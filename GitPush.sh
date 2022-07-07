#! /usr/bin/sh

echo "init PUSH"

git add .
git commit -m $1
git push github master
git push tencent master




