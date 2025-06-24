FROM jenkins/jenkins:lts-jdk17
RUN sudo apt-get update 
RUN sudo apt-get install python3
RUN sudo apt-get install python3-pip
RUN pip install platformio
RUN pip install certifi