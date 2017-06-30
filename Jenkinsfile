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
      if ( fileExists( "${WORKSPACE}/**/*.xml" ) ) {
        junit "${WORKSPACE}/**/*.xml"
      }
      sh """
        GIT_COMMIT="`git log --pretty=format:'%H' | head -n 1`"
        INSTALLDIR="amhello-\${GIT_COMMIT}"
        ${RUN} make DESTDIR=${WD}/\${INSTALLDIR} install
        ${RUN} tar cpvJf \${INSTALLDIR}.tar.xz \${INSTALLDIR}
      """
      archive '*.tar.xz'
   }
}
