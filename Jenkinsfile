pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                echo 'Building...'
                       sh '''pio account logout || true 
                       PLATFORMIO_AUTH_TOKEN=${MX_PLATFORMIO_AUTH_TOKEN} pio remote run -r ''' 
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Tagging stable') {
            when {
                branch 'stable' 
            }
            steps {
                echo 'Tagging branch' 
                    script {
                        def date = new Date().format('yyyy-MM-dd HH:mm:ss') // Format the date as yyyy-MM-dd HH:mm:ss
                        echo "${date}"
                        def TAG_VERSION = "jenkins-v-${date}" // Combine date and build number
                        echo "Generated version: ${TAG_VERSION}"
                    }
                    //sh '''git tag ${TAG_VERSION}'''
                    script {
                        withCredentials([usernamePassword(credentialsId: 'github_usr_pwd', usernameVariable: 'GIT_USERNAME', passwordVariable: 'GIT_PASSWORD')]) {
                            // Configure Git to use the credentials helper
                            sh 'git config --global credential.helper store'
                            sh 'git config user.email "leruizv@gmail.com"'
                            sh 'git config user.name "lruizv"'
                            sh 'echo "https://${GIT_USERNAME}:${GIT_PASSWORD}@github.com" > ~/.git-credentials' // Or your Git host                           
                            // Push tags
                            sh 'git push origin --tags'
                        } 
                    } 
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