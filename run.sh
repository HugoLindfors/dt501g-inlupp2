#!/bin/bash

if [[ "$1" == "-d" || "$1" == "--delete" ]]; then
        DELETE_ON_FINISH=true
        shift
else
        DELETE_ON_FINISH=false
fi

OUTPUT_NAME="${1%.c}"

cc "$1" -o "$OUTPUT_NAME" && ./"$OUTPUT_NAME" "${@:2}"

if [ "$DELETE_ON_FINISH" = true ]; then
        rm "$OUTPUT_NAME"
fi