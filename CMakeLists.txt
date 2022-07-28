cmake_minimum_required( VERSION 3.0.0 )

project( bbc6minute VERSION 0.1.0 )

set( CMAKE_CXX_STANDARD 20 )

set( SOURCE_FILES 
    Src/main.cpp

    Src/Courses/Sources/currentCourse.cpp

    Src/Courses/WithUnits/Sources/currentUnitDownloadCentrePageDownloader.cpp 
    Src/Courses/WithUnits/Sources/currentUnitMediasAndTranscriptsDownloader.cpp 
    Src/Courses/WithUnits/Sources/downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.cpp
    Src/Courses/WithUnits/Sources/currentUnit.cpp
    Src/Courses/WithUnits/Sources/currentUnitVocabularyAndGrammarReferenceDownloader.cpp

    Src/Courses/Unitless/Sources/unitless.cpp
    Src/Courses/Unitless/Sources/mediasAndTranscriptsPagesUrlAddressesPageDownloader.cpp
    Src/Courses/Unitless/Sources/mediasAndTranscriptsPagesUrlAddressesExtracter.cpp
    Src/Courses/Unitless/Sources/mediasAndTranscriptsUrlAddressesPagesDownloader.cpp
    Src/Courses/Unitless/Sources/mediaAndTranscriptDownloader.cpp

    Src/Utils/Sources/utils.cpp
    Src/Utils/Sources/missingFiles.cpp
    Src/Utils/Sources/downloader.cpp
    Src/Utils/Sources/pause.cpp
)

include_directories( 
    Src/Courses/Headers/
    Src/Courses/WithUnits/Headers/
    Src/Courses/Unitless/Headers/
    Src/Utils/Headers/
)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )