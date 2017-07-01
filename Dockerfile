FROM ubuntu:latest
MAINTAINER Christopher Friedt "chrisfriedt@gmail.com"

RUN apt-get update
RUN apt-get install -y build-essential autotools-dev autoconf libtool
RUN apt-get install -y cmake
RUN apt-get install -y libgtest-dev
RUN "cd /usr/src/gtest && cmake -DBUILD_SHARED_LIBS=ON && make install"

WORKDIR /home
