#!/bin/zsh

while [ $# -gt 0 ]
do
    number=$1
    file=$2

    if [ $file = "cpp" ]; then
        cp ".template" "bee$number.$file"
    elif [ $file = "py" ]; then
        cp ".template" "bee$number.$file"
    fi
    
    echo "create bee$number.$file"
    
    shift 2
done