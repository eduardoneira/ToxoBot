#!/bin/bash

trap "{ echo Termino pipe_out ; exit 1; }" SIGINT SIGTERM
echo "Comenzando pipe_out"

sleep_time=1    # Duerme un seg
i=1

while true; do
    echo "$i"
    i=$((i + 1))
    sleep $sleep_time
done

