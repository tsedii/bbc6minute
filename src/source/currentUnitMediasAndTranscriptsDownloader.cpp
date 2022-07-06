#include "currentUnitMediasAndTranscriptsDownloader.hpp"
#include "missingFiles.hpp"
#include <iostream>


namespace bbc_6_minute
{
    void CurrentUnitMediasAndTranscriptsDownloader::DownloadCurrentUnitMediasAndTranscripts()
    {
        for (const auto& [key, value] : (*(MissingFiles().GetMissingFiles())))
        {
            std::cout << key << std::endl << value.string() << std::endl << std::endl;
        }
        
    }
    
}