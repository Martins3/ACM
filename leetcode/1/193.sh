#!/bin/bash
# regex doesn't work as expected!
while IFS='' read -r line || [[ -n "$line" ]]; do
    echo "Text read from file: $line"
    if [[ "$line" =~ '[0-9]{3}' ]]; then
        echo $line
# ["$line" =~ "[0-9]{3}-[0-9]{3}-[0-9]{3}"]
    fi
done < "$1"

