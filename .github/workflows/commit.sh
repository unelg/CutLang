#!/bin/bash

git config user.email "jinens8@gmail.com"
git config user.name "bot"

git add ../previous/artifacts.zip
git commit -m "automated update" 
git push origin master
