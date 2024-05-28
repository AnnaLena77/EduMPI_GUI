#!/bin/bash

# SSH-Zugangsdaten
REMOTE_USER=$1
REMOTE_HOST=$2
REMOTE_DIR=$3
JOB_SCRIPT=$4
CHECK_INTERVAL=1
SSH_PORT=22 # Standard ist 22, ändern Sie dies, falls notwendig

# Pfad für die Kontrollsockel-Datei
CONTROL_PATH="/tmp/ssh-%r@%h:%p"

# SSH-Optionen für eine persistente Verbindung
SSH_OPTIONS="-o ControlMaster=auto -o ControlPath=${CONTROL_PATH} -o ControlPersist=600"

# Funktion zur Ausführung eines Kommandos auf dem Remote-Host
function remote_command() {
    local COMMAND=$1
    ssh ${SSH_OPTIONS} -p ${SSH_PORT} ${REMOTE_USER}@${REMOTE_HOST} "${COMMAND}"
}

# Verbindung öffnen (erster Befehl startet die Verbindung)
REMOTE_COMMANDS=$(cat <<EOF
cd $REMOTE_DIR && \
chmod +x $JOB_SCRIPT && \
sbatch --parsable ./$JOB_SCRIPT
EOF
)

JOB_ID=$(remote_command "$REMOTE_COMMANDS")

if [[ $? -ne 0 ]]; then
    echo "Fehler beim Einreichen des Jobs."
    exit 1
fi

echo "Job erfolgreich eingereicht mit ID: $JOB_ID"

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



# Hier können Sie beliebige weitere Kommandos ausführen
remote_command "echo Hallo"
remote_command "sleep 10"
#remote_command "df -h"
#remote_command "ls -l /home/${REMOTE_USER}"

# Optional: Verbindung schließen (wenn Sie sicherstellen möchten, dass die Verbindung sofort beendet wird)
ssh ${SSH_OPTIONS} -O exit -p ${SSH_PORT} ${REMOTE_USER}@${REMOTE_HOST}

echo "SSH-Verbindung geschlossen"
