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
         stage('Generate Version') {
            steps {
                script {
                    def date = new Date().format('yyyy-MM-dd HH:mm:ss') // Format the date as yyyy-MM-dd HH:mm:ss
                    echo "${date}"
                    TAG_VERSION = "${CODE_VERSION}v-${date}" // Combine date and build number
                    echo "Generated version: ${TAG_VERSION}"
                }
            }
        }
        stage('Tagging stable') {
            when {
                branch 'stable' 
            }
            steps {
                echo 'Tagging branch' 
                echo "Generated version: ${CODE_VERSION}"                
                    sh '''git tag ${CODE_VERSION}'''
                    sshagent(credentials: ['github_ssh']) {
                        sh '''git push origin --tags'''
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
    CODE_VERSION = "jenkins_${TAG_VERSION}"
  }
}