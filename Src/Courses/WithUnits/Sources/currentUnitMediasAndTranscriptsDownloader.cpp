#include "currentUnitMediasAndTranscriptsDownloader.hpp"
#include "missingFiles.hpp"
#include "downloader.hpp"
#include "pause.hpp"


namespace bbc_6_minute
{
    namespace with_units_courses
    {
        void CurrentUnitMediasAndTranscriptsDownloader::DownloadCurrentUnitMediasAndTranscripts()
        {
            if (!utils::MissingFiles().GetMissingFiles())
            {
                return;
            }

            for (const auto& [url_addresses_file_name, filesystem_file_name] : (*(utils::MissingFiles().GetMissingFiles())))
            {
                utils::Downloader(url_addresses_file_name, filesystem_file_name.string()).Download();
                utils::Pause().On();
            }
        }
    }
}