#!/usr/bin/env bash
git checkout master
git fetch upstream
git pull upstream master
git push origin master

git checkout claudio
# git pull --rebase origin master
git rebase master
git push origin claudio --force-with-lease
