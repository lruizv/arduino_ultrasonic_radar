FROM jenkins/jenkins:lts-jdk17
USER root
RUN apt-get update 
RUN apt-get -y install python3
RUN apt-get -y install python3.11-venv
RUN apt-get -y install python3-pip 
RUN pip install platformio --break-system-packages
RUN pip install certifi --break-system-packages