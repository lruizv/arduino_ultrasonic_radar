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
                branch 'Development' 
            }
            steps {
                echo 'Merging...'
                sh '''git fetch --all '''
                sh '''git checkout Stable '''
                sh '''git merge Development'''
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying..'
                sh '''pio account logout || true 
                PLATFORMIO_AUTH_TOKEN=${MX_PLATFORMIO_AUTH_TOKEN} pio remote run --environment uno --target upload'''
            }
        }
    }
    environment {
    MX_PLATFORMIO_AUTH_TOKEN = credentials('MX_PLATFORMIO_AUTH_TOKEN')
  }
}