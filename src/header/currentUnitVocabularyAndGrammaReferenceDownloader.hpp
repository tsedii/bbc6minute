#pragma once

#include <string>


namespace bbc_6_minute
{
    class CurrentUnitVocabularyAndGrammaReferenceDownloader
    {
    public:
        void DownloadCurrentUnitVocabularyAndGrammaReference();

    private:
        const std::string downloader_{
            "google-chrome --headless --disable-gpu --print-to-pdf="
        };
        //"\"c0_u1_vocab_ref.pdf\" https://www.bbc.co.uk/learningenglish/english/course/lower-intermediate/unit-1/tab/vocabulary"};
        std::string url_addresses_;
        std::string filesystem_file_name_;
    };
}