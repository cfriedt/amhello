FROM ubuntu:latest
MAINTAINER Christopher Friedt "chrisfriedt@gmail.com"

RUN apt-get update
RUN apt-get install -y build-essential autotools-dev autoconf

WORKDIR /home
