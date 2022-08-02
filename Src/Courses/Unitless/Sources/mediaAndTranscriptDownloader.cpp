#include "mediaAndTranscriptDownloader.hpp"

#include <regex>

#include "utils.hpp"
#include "currentCourse.hpp"
#include "downloader.hpp"


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        MediaAndTranscriptDownloader::MediaAndTranscriptDownloader(
            std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr
            , std::shared_ptr<std::string> media_and_transcript_date_ptr
        ): media_and_transcript_url_addresses_ptr_(media_and_transcript_url_addresses_ptr)
        , media_and_transcript_date_ptr_(media_and_transcript_date_ptr)
        {
        }

        void MediaAndTranscriptDownloader::DownloadMediaAndTranscript()
        {
            if (!media_and_transcript_url_addresses_ptr_)
            {
                return;
            }
            
            for (const auto& media_or_transcript_url_address : *media_and_transcript_url_addresses_ptr_)
            {
                std::shared_ptr<std::filesystem::path> current_file_folder_full_path_ptr{
                    CreateCurrentFileFolderIfNecessaryAndGetItFullPath(media_or_transcript_url_address)
                };
                
                std::shared_ptr<std::filesystem::path> current_file_filesystem_filename_ptr{
                    GetCurrentFileFilesystemFilename(media_or_transcript_url_address)
                };
                
                if (!utils::filesystem::IsFilesystemObjectExists(*current_file_folder_full_path_ptr / *current_file_filesystem_filename_ptr))
                {
                    DownloadCurrentFile(
                        *current_file_folder_full_path_ptr / *current_file_filesystem_filename_ptr
                        , media_or_transcript_url_address
                    );
                }
            }
            
        }

        std::shared_ptr<std::string> MediaAndTranscriptDownloader::ExtractDateFromFileName()
        {
            return media_and_transcript_date_ptr_;
        }

        std::shared_ptr<std::filesystem::path> MediaAndTranscriptDownloader
            ::GetCurrentSubPath(const std::string& media_or_transcript_url_address)
        {
            std::string sub_path(*ExtractDateFromFileName());

            if (sub_path.empty())
            {
                return nullptr;
            }

            const unsigned int two_digit_year_designation{2};

            // trims from the argument-valued position to the end of the string
            sub_path.erase(two_digit_year_designation);

            const unsigned int string_begin_position{0};

            const std::string year_first_two_digits("20");

            return std::make_shared<std::filesystem::path>(
                       sub_path.insert(string_begin_position, year_first_two_digits)
                   );
        }

        std::shared_ptr<std::filesystem::path> MediaAndTranscriptDownloader
            ::CreateCurrentFileFolderIfNecessaryAndGetItFullPath(const std::string& media_or_transcript_url_address)
        {
            std::shared_ptr<std::filesystem::path> current_folder_full_path_ptr{
                std::make_shared<std::filesystem::path>(
                    *(CurrentCourse().GetCurrentCoursePath()) / *GetCurrentSubPath(media_or_transcript_url_address)
                )
            };

            if (!utils::filesystem::IsFilesystemObjectExists(
                *current_folder_full_path_ptr)
            )
            {
                utils::filesystem::CreateMissingSubdirectories(
                    *current_folder_full_path_ptr
                );
            }

            return current_folder_full_path_ptr;
        }

        std::shared_ptr<std::filesystem::path> MediaAndTranscriptDownloader
            ::GetCurrentFileFilesystemFilename(const std::string& media_or_transcript_url_address)
        {
            std::string media_or_transcript_filename(
                *utils::filesystem::UrlAddressToDownloadFileName(media_or_transcript_url_address)
            );

            DeleteRedundantSymbols(media_or_transcript_filename);

            CurrentCourse().AddCurrentCoursePrefix(media_or_transcript_filename);

            return std::make_shared<std::filesystem::path>(media_or_transcript_filename);
        }

        void MediaAndTranscriptDownloader::DeleteRedundantSymbols(std::string& filesystem_file_name)
        {
            filesystem_file_name = std::regex_replace(filesystem_file_name, std::regex("_download.*\\."), ".");
        }

        void MediaAndTranscriptDownloader::DownloadCurrentFile(
            const std::filesystem::path& current_file_full_path
            , const std::string& media_or_transcript_url_address
        )
        {
            utils::Downloader(
                media_or_transcript_url_address
                , current_file_full_path.string()
            ).Download();
        }
    }
}