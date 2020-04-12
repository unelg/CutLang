#!/bin/bash

git config user.email "jinens8@gmail.com"
git config user.name "bot"

git add ../previous/
git commit -m "automated update" 
git push origin $1
