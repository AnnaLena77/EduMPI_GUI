#!/usr/bin/env bash

#Run: nix-shell -p papi libz --run ./scorep_scalasca_script.sh

#Paths
SCALASCA_PATH="/opt/scalasca/bin"
SCOREP_PATH="/opt/scorep/bin"
HOSTFILE_PATH="/etc/mpi/hosts"

#File
FILE_PATH="$(pwd)/matrix_mult_.c"

#Number of Processes
NUM=400

export PATH=$PATH:$SCALASCA_PATH
export PATH=$PATH:$SCOREP_PATH

echo -e "\n--> Scorep_Scalasca_Test Start\n"

scorep mpicc $FILE_PATH -o scorep_scalasca_script_out -lm
scalasca -analyze mpiexec -n 400 "--mca pml ob1" "-hostfile /etc/mpi/hosts" ./scorep_scalasca_scrip>

newest_directory=$(ls -td -- */ | head -n 1)
echo -e "\n--> New Scorep-Directory: $(pwd)/$newest_directory\n"

current_datetime=$(date +%Y%m%d_%H%M)
previous_minute_datetime=$(date -d '1 minute ago' +%Y%m%d_%H%M)

if [[ "$newest_directory" == *"$current_datetime"* ]] || [[ "$newest_directory" == *"$previous_minu>
    echo -e "\n--> Everything worked for Instrumentation and Measurement... Continue with Postproce>
    square -s $newest_directory
    cd $newest_directory
    if [ -f summary.cubex ]; then
        echo -e "\n--> SUCCESS!\n"
    else
        echo "\n--> Error in the last step: Postprocessing with command “/scalasca/bin/square -s ..>
    fi
else
    echo "\n--> An error has occurred during the instrumentation or measurement process\n"
fi

