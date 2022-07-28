#include "mediaAndTranscriptDownloader.hpp"

#include <regex>

#include "utils.hpp"
#include "currentCourse.hpp"


namespace bbc_6_minute
{
    namespace unit_less_courses
    {
        MediaAndTranscriptDownloader::MediaAndTranscriptDownloader(
            std::shared_ptr<MediaAndTranscriptUrlAddresses> media_and_transcript_url_addresses_ptr
        ): media_and_transcript_url_addresses_ptr_(media_and_transcript_url_addresses_ptr)
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
                CheckCurrentSubPathExistence(media_or_transcript_url_address);
            }
            
        }

        std::string MediaAndTranscriptDownloader::ExtractDateFromFileName(const std::string& media_or_transcript_url_address)
        {
            std::regex regex_extract_date_template("/(\\d{6})_");

            std::smatch match;

            std::regex_search(
                media_or_transcript_url_address.cbegin()
                , media_or_transcript_url_address.cend()
                , match
                , regex_extract_date_template
            );

            return match[1].str();
        }

        std::shared_ptr<std::filesystem::path> MediaAndTranscriptDownloader::GetCurrentSubPath(const std::string& media_or_transcript_url_address)
        {
            std::string sub_path(ExtractDateFromFileName(media_or_transcript_url_address));

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

        void MediaAndTranscriptDownloader::CheckCurrentSubPathExistence(const std::string& media_or_transcript_url_address)
        {
            if (!utils::filesystem::IsFilesystemObjectExists(
                *(CurrentCourse().GetCurrentCoursePath()) / *GetCurrentSubPath(media_or_transcript_url_address)
            ))
            {
                utils::filesystem::CreateMissingSubdirectories(
                    *(CurrentCourse().GetCurrentCoursePath()) / *GetCurrentSubPath(media_or_transcript_url_address)
                );
            }
        }
    }
}