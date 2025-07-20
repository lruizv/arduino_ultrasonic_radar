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
                echo 'Merging...'
                withCredentials([gitUsernamePassword(credentialsId: 'git_hub_credentials', gitToolName: 'git-tool')]) {
                    sh '''git fetch origin'''
                    sh '''git checkout -b stable origin/stable'''
                    sh '''git merge origin/development -m "Merge from Jenkins pipeline into stable"'''
                    sh '''git push origin stable'''
                }
                
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