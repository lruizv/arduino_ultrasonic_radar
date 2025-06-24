FROM jenkins/jenkins:lts-jdk17
USER root
RUN apt-get update 
RUN apt-get -y install python3
RUN apt-get -y install python3-pip
RUN pip install platformio
RUN pip install certifi