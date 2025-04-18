#!/bin/bash

# SSH-Zugangsdaten
REMOTE_USER=$1
REMOTE_HOST=$2
REMOTE_DIR=$3
JOB_SCRIPT=$4
CHECK_INTERVAL=1
SSH_PORT=22 # Standard ist 22, ändern Sie dies, falls notwendig

# Pfad für die Kontrollsockel-Datei
#CONTROL_PATH="/tmp/ssh-%r@%h:%p"

# SSH-Optionen für eine persistente Verbindung
#SSH_OPTIONS="-o ControlMaster=auto -o ControlPath=${CONTROL_PATH} -o ControlPersist=600"
SSH_OPTIONS=""

echo "SCRIPT_PID=$$"

# Funktion zur Ausführung eines Kommandos auf dem Remote-Host
function remote_command() {
    local COMMAND=$1
    ssh ${SSH_OPTIONS} -p ${SSH_PORT} ${REMOTE_USER}@${REMOTE_HOST} "${COMMAND}"
}

function handle_cancel_signal() {
    echo "Signal empfangen, breche Job $JOB_ID ab..."
    remote_command "scancel $JOB_ID"
    echo "Job $JOB_ID CANCELLED."
    ssh ${SSH_OPTIONS} -O exit -p ${SSH_PORT} ${REMOTE_USER}@${REMOTE_HOST}
    echo "SSH-Verbindung geschlossen"
    exit 0
}

# Signal-Handler für SIGINT und SIGTERM registrieren
trap 'handle_cancel_signal' SIGTERM

# Verbindung öffnen (erster Befehl startet die Verbindung)
REMOTE_COMMANDS=$(cat <<EOF
cd $REMOTE_DIR && \
chmod +x $JOB_SCRIPT && \
nix-shell -p papi libz --run "sbatch --parsable ./$JOB_SCRIPT"
EOF
)

JOB_ID=$(remote_command "$REMOTE_COMMANDS")

if [[ $? -ne 0 ]]; then
    echo "Fehler beim Einreichen des Jobs."
    exit 1
fi

echo "JOB_ID=$JOB_ID"

#SWITCH_PATH=$(remote_command "cd $REMOTE_DIR")
#SET_RIGHTs=$(remote_command "chmod +x $JOB_SCRIPT")
#JOB_ID=$(remote_command "sbatch --parsable ./$JOB_SCRIPT")
if [[ $? -ne 0 ]]; then
    echo "Fehler beim Einreichen des Jobs."
    exit 1
fi

while true; do
    JOB_STATUS=$(remote_command "squeue -j $JOB_ID -h -o %T")

    if [[ $? -ne 0 ]]; then
        echo "Fehler beim Abrufen des Job-Status."
        exit 1
    fi

    # Status des Jobs ausgeben
    echo "Job $JOB_ID Status: $JOB_STATUS"
    
     # Überprüfen, ob der Job abgeschlossen ist
    if [[ "$JOB_STATUS" == "COMPLETED" || "$JOB_STATUS" == "FAILED" || "$JOB_STATUS" == "CANCELLED" || -z "$JOB_STATUS" ]]; then
        break
    fi

    # Eine Sekunde warten, bevor der Status erneut überprüft wird
    sleep $CHECK_INTERVAL
done


DIR_COMMAND=$(cat <<EOF
cd $REMOTE_DIR && \
ls -td -- */ | head -n 1
EOF
)

SCOREP_DIR=$(remote_command "$DIR_COMMAND")
SCOREP_DIR=$(echo "$SCOREP_DIR" | tr -d '\r')

SQUARE_COMMAND=$(cat <<EOF
cd $REMOTE_DIR && \
export PATH="\$PATH:/opt/scorep/bin:/opt/scalasca/bin" && \
square -s $SCOREP_DIR
EOF
)

if [[ $(basename "$SCOREP_DIR") == scorep* ]]; then
    echo "generate summary.cubex"
    remote_command "$SQUARE_COMMAND"
else
    echo "Fehler: Das Verzeichnis beginnt nicht mit 'scorep'."
    exit 1
fi

while true; do
    CHECK_FILE_COMMAND="if [ -f $REMOTE_DIR/$SCOREP_DIR/summary.cubex ]; then echo 'exists'; else echo 'not exists'; fi"
    FILE_STATUS=$(remote_command "$CHECK_FILE_COMMAND")

    if [[ "$FILE_STATUS" == "exists" ]]; then
        echo "summary.cubex gefunden, kopiere Verzeichnis..."
        scp -r -P ${SSH_PORT} ${REMOTE_USER}@${REMOTE_HOST}:${REMOTE_DIR}/${SCOREP_DIR} ~/
        break
    else
        echo "summary.cubex noch nicht vorhanden, warte..."
        sleep $CHECK_INTERVAL
    fi
done

#remote_command "sleep 10"
#remote_command "df -h"
#remote_command "ls -l /home/${REMOTE_USER}"

# Optional: Verbindung schließen (wenn Sie sicherstellen möchten, dass die Verbindung sofort beendet wird)
ssh ${SSH_OPTIONS} exit -p ${SSH_PORT} ${REMOTE_USER}@${REMOTE_HOST}

echo "SSH-Verbindung geschlossen"
