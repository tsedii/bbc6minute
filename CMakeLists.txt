cmake_minimum_required( VERSION 3.0.0 )

project( bbc6minute VERSION 0.1.0 )

set( CMAKE_CXX_STANDARD 20 )

set( SOURCE_FILES 
    src/main.cpp 
    src/source/currentUnitDownloadCentrePageDownloader.cpp 
    src/source/currentUnitMediasAndTranscriptsDownloader.cpp 
    src/source/downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.cpp
    src/source/currentUnit.cpp
    src/source/currentCourse.cpp
    src/source/missingFiles.cpp
    src/source/downloader.cpp
    src/source/pause.cpp
    src/source/currentUnitVocabularyAndGrammaReferenceDownloader.cpp
)

include_directories( src/header/ )

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )