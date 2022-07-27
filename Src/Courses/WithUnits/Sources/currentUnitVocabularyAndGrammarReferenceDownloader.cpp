#include "currentUnitVocabularyAndGrammarReferenceDownloader.hpp"
#include "pause.hpp"
#include "currentCourse.hpp"
#include "currentUnit.hpp"
#include "utils.hpp"


namespace bbc_6_minute
{
    void CurrentUnitVocabularyAndGrammarReferenceDownloader::DownloadCurrentUnitVocabularyAndGrammarReference()
    {
        InitializeVocabularyAndGrammaReferencesAttributes();

        for (const auto& [url_address, filesystem_file_name] : *vocabulary_and_gramma_references_attributes_ptr_)
        {
            std::system(std::string(
                downloader_ 
                + filesystem_file_name.string() 
                + " "
                + url_address
            ).c_str());
        }
        
        Pause().On();
    }

    std::shared_ptr<std::string> CurrentUnitVocabularyAndGrammarReferenceDownloader::GetVocabularyReferenceUrlAddress()
    {
        return std::make_shared<std::string>(CurrentCourse().GetCurrentCourseVocabularyReferenceUrlAddress(CurrentUnit().GetCurrentUnitNumber()));
    }

    std::shared_ptr<std::string> CurrentUnitVocabularyAndGrammarReferenceDownloader::GetGrammarReferenceUrlAddress()
    {
        return std::make_shared<std::string>(CurrentCourse().GetCurrentCourseGrammarReferenceUrlAddress(CurrentUnit().GetCurrentUnitNumber()));
    }

    std::shared_ptr<std::filesystem::path> CurrentUnitVocabularyAndGrammarReferenceDownloader::GetReferenceFilesystemFilename(
        const std::string& reference_filesystem_filename_base
    )
    {
        std::string reference_filesystem_filename_base_tmp(reference_filesystem_filename_base);

        CurrentUnit().AddCurrentUnitPrefix(reference_filesystem_filename_base_tmp);
        CurrentCourse().AddCurrentCoursePrefix(reference_filesystem_filename_base_tmp);

        return CurrentUnit().GetFullFilesystemFileName(reference_filesystem_filename_base_tmp);
    }

    void CurrentUnitVocabularyAndGrammarReferenceDownloader::InitializeVocabularyAndGrammaReferencesAttributes()
    {
        if (!vocabulary_and_gramma_references_attributes_ptr_)
        {
            vocabulary_and_gramma_references_attributes_ptr_ = std::make_unique<VocabularyAndGrammaReferencesAttributes>();
        }
        
        if (!utils::IsFilesystemObjectExists(*(GetReferenceFilesystemFilename("VocabularyReference.pdf")))
            and !((*(GetVocabularyReferenceUrlAddress())).empty())
        )
        {
            (*vocabulary_and_gramma_references_attributes_ptr_)[*(GetVocabularyReferenceUrlAddress())] 
                = *(GetReferenceFilesystemFilename("VocabularyReference.pdf"));
        }
        
        if (!utils::IsFilesystemObjectExists(*(GetReferenceFilesystemFilename("GrammarReference.pdf")))
            and !((*(GetGrammarReferenceUrlAddress())).empty())
        )
        {
            (*vocabulary_and_gramma_references_attributes_ptr_)[*(GetGrammarReferenceUrlAddress())] 
                = *(GetReferenceFilesystemFilename("GrammarReference.pdf"));
        }
    }
}