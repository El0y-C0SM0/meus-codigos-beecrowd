#!/bin/zsh

for file in "$@"
do
    file_name=$(basename "$file")
    git add "$file" && echo "$file_name adicionado" && git commit -m "$file_name accepted"
done