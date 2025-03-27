#!/bin/sh

curl -o main.zip -L https://github.com/mastermach50/OS-Lab-Programs/archive/refs/heads/main.zip
unzip main.zip -d .
rm main.zip .gitignore .envrc README.md shell.nix
