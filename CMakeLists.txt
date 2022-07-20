cmake_minimum_required( VERSION 3.0.0 )

project( bbc6minute VERSION 0.1.0 )

set( CMAKE_CXX_STANDARD 20 )

set( SOURCE_FILES 
    Src/main.cpp
    Src/Courses/source/currentCourse.cpp
    Src/Courses/source/missingFiles.cpp
    Src/Courses/source/downloader.cpp
    Src/Courses/source/pause.cpp
    Src/Courses/WithUnits/source/currentUnitDownloadCentrePageDownloader.cpp 
    Src/Courses/WithUnits/source/currentUnitMediasAndTranscriptsDownloader.cpp 
    Src/Courses/WithUnits/source/downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.cpp
    Src/Courses/WithUnits/source/currentUnit.cpp
    Src/Courses/WithUnits/source/currentUnitVocabularyAndGrammarReferenceDownloader.cpp
)

include_directories( 
    Src/Courses/header/
    Src/Courses/WithUnits/header/
)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )