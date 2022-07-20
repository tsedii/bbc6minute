cmake_minimum_required( VERSION 3.0.0 )

project( bbc6minute VERSION 0.1.0 )

set( CMAKE_CXX_STANDARD 20 )

set( SOURCE_FILES 
    Src/main.cpp
    Src/Courses/Sources/currentCourse.cpp
    Src/Courses/Sources/missingFiles.cpp
    Src/Courses/Sources/downloader.cpp
    Src/Courses/Sources/pause.cpp
    Src/Courses/WithUnits/Sources/currentUnitDownloadCentrePageDownloader.cpp 
    Src/Courses/WithUnits/Sources/currentUnitMediasAndTranscriptsDownloader.cpp 
    Src/Courses/WithUnits/Sources/downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.cpp
    Src/Courses/WithUnits/Sources/currentUnit.cpp
    Src/Courses/WithUnits/Sources/currentUnitVocabularyAndGrammarReferenceDownloader.cpp
    Src/Courses/Unitless/Sources/unitless.cpp
)

include_directories( 
    Src/Courses/Headers/
    Src/Courses/WithUnits/Headers/
    Src/Courses/Unitless/Headers/
)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )