#!/bin/bash
now="$(date +'%B %e, %Y')"

git pull
git add . 
git commit -m "Updates $now"
git push