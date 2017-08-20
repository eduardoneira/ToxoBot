#!/bin/bash

echo "Installing python 3"
sudo apt-get install python3
alias python=python3

echo "Installing pip"
sudo python3 get-pip.py

echo "Installing psycopg"
pip3 install --user psycopg2
