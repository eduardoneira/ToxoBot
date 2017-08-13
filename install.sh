#!/usr/bin/env bash

# Install curl
sudo apt-get install libcurl4-openssl-dev

#Install postgresql and libpqxx
sudo apt-get install postgresql
sudo apt-get install libpq-dev

git clone https://github.com/jtv/libpqxx.git
cd libpqxx
./configure
make
sudo make install