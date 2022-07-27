#pragma once

#include <map>
#include <string>
#include <filesystem>
#include <memory>


namespace bbc_6_minute
{
    namespace with_units_courses
    {
        typedef std::map<std::string, std::filesystem::path> VocabularyAndGrammaReferencesAttributes;

        class CurrentUnitVocabularyAndGrammarReferenceDownloader
        {
        public:
            void DownloadCurrentUnitVocabularyAndGrammarReference();
    
        private:
            std::shared_ptr<std::string> GetVocabularyReferenceUrlAddress();
            std::shared_ptr<std::string> GetGrammarReferenceUrlAddress();
    
            std::shared_ptr<std::filesystem::path> GetReferenceFilesystemFilename(
                const std::string& reference_filesystem_filename_base
            );
    
            void InitializeVocabularyAndGrammaReferencesAttributes();
    
        private:
            const std::string downloader_{
                "google-chrome --headless --disable-gpu --print-to-pdf="
            };
            std::unique_ptr<VocabularyAndGrammaReferencesAttributes> vocabulary_and_gramma_references_attributes_ptr_{nullptr};
        };
    }
}