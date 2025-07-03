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
                withCredentials([gitUsernamePassword(credentialsId: 'git_hub_credentials', gitToolName: 'git-tool')]) {
                    sh '''git fetch --all'''
                    sh '''git checkout Stable'''
                    sh '''git merge origin/Development'''
                    sh '''git push origin/Stable'''
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