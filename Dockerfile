FROM jenkins/jenkins:lts-jdk17
RUN apt-get update 
RUN apt-get install python3
RUN apt-get install python3-pip
RUN pip install platformio
RUN pip install certifi