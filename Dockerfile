FROM jenkins/jenkins:lts-jdk17 
RUN yum install python3
RUN yum install python3-pip
RUN pip install platformio
RUN pip install certifi