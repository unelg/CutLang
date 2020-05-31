#!/bin/bash

target_date=`date "+%Y-%m-%d" -d "6 day ago"`
cur_date=`git log -1 --pretty="format:%cs" ../previous/raw_output.txt`
tar_date_int=$(date -d $target_date +%s)
cur_date_int=$(date -d $cur_date +%s)

if [ $tar_date_int -le $cur_date_int ]; then
	exit 0
fi

git config user.email "jinens8@gmail.com"
git config user.name "bot"

git add ../previous/
git commit -m "automated update" 
git push origin $1
