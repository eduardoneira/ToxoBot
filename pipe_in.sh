#!/bin/bash

trap "{ echo Termino pipe_in ; exit 1; }" SIGINT SIGTERM
echo "Comenzando pipe_in"

while true; do
    read stdin
    echo "$stdin"
done