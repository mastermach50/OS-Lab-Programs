#!/bin/sh

curl -o OS-Lab-Programs-main.zip -L https://github.com/mastermach50/OS-Lab-Programs/archive/refs/heads/main.zip
unzip OS-Lab-Programs-main.zip -d .
mv ./OS-Lab-Programs-main ./OS-Lab-Programs
rm ./OS-Lab-Programs-main.zip ./OS-Lab-Programs/.gitignore ./OS-Lab-Programs/.envrc ./OS-Lab-Programs/README.md ./OS-Lab-Programs/shell.nix
