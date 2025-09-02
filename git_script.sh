#!/bin/bash
for dir in $(git status --porcelain | awk '{print $2}' | xargs -n1 dirname | sort -u); do
    echo "Committing changes in $dir"
    git add "$dir"
    git commit -m "$dir"
    git push
done

