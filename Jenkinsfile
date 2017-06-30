node {
   def TAG="amhello:dockerfile"
   def WD="/home"
   def RUN="docker run -v ${WORKSPACE}:${WD} ${TAG}"
   stage('Preparation') {
      git 'https://github.com/cfriedt/amhello.git'
      // uses Dockerfile from forked amhello project
      sh "docker build -t ${TAG} ${WORKSPACE}"
   }
   stage('Build') {
      sh "${RUN} autoreconf --install"
      sh "${RUN} ./configure"
      sh "${RUN} make"
   }
   stage('Results') {
      sh "${RUN} make check"
      junit '**/*.xml'
      // no idea why all of the predefined variables fail in a multiline command below
      sh '''
        GIT_COMMIT="`git log --pretty=format:'%H' | head -n 1`"
        INSTALLDIR="amhello-${GIT_COMMIT}"
        docker run -v ${WORKSPACE}:/home amhello:dockerfile \
            make DESTDIR=/home/${INSTALLDIR} install
        docker run -v ${WORKSPACE}:/home amhello:dockerfile \
            tar cpvJf ${INSTALLDIR}.tar.xz ${INSTALLDIR}
        '''
      archive '*.tar.xz'
   }
}
