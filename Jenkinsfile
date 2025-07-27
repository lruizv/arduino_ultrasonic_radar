pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building...'
                       sh '''pio account logout || true 
                       PLATFORMIO_AUTH_TOKEN=${MX_PLATFORMIO_AUTH_TOKEN} pio remote run -r
''' 
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Merging into stable') {
            when {
                branch 'development' 
            }
            steps {
                echo 'Merging branches from development'
                    
                  git branch: 'stable',
                    credentialsId: 'git_hub_credentials',
                    changelog: false,
                    url: 'https://github.com/lruizv/arduino_ultrasonic_radar.git'
                    sh '''git pull origin stable'''
                    sh '''git rm Jenkinsfile'''
                    sh '''git rm Dockerfile'''
                    sh '''git commit -m "removing jenkinsfile and docker file" '''
                    sh '''git merge -s recursive -X theirs origin/development'''
                    sh '''git push origin stable'''
                
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying..'
                //sh '''pio account logout || true 
                //PLATFORMIO_AUTH_TOKEN=${MX_PLATFORMIO_AUTH_TOKEN} pio remote run --environment uno --target upload'''
            }
        }
    }
    environment {
    MX_PLATFORMIO_AUTH_TOKEN = credentials('MX_PLATFORMIO_AUTH_TOKEN')
  }
}