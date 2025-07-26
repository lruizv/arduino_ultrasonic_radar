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
                //withCredentials([gitUsernamePassword(credentialsId: 'git_hub_credentials', gitToolName: 'git-tool')]) {
                    //sh '''git fetch --all'''
                    //sh '''git checkout -b stable origin/stable'''
                    //sh '''git merge origin/development -m "Merge from Jenkins pipeline into stable"'''
                    //sh '''git push origin stable'''
                  
                //}
                  git branch: 'stable',
                    credentialsId: 'git_hub_credentials',
                    changelog: false,
                    url: 'https://github.com/lruizv/arduino_ultrasonic_radar.git'
                    
                    sh '''git branch'''
                    sh '''git merge origin/development -m "Merge from Jenkins pipeline into stable branch"'''
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