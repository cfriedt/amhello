FROM ubuntu:latest
MAINTAINER Christopher Friedt "chrisfriedt@gmail.com"

RUN apt-get update
RUN apt-get install -y build-essentials

WORKDIR /home
