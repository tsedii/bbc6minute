#include "currentCourse.hpp"
#include "currentUnit.hpp"
#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.hpp"
#include "currentUnitMediasAndTranscriptsDownloader.hpp"
#include "currentUnitVocabularyAndGrammarReferenceDownloader.hpp"


namespace bbc_6_minute
{
    void DownloadCourseWithUnits()
    {
        while (CurrentUnit().Go())
        {
            CurrentUnitDownloadCentrePageDownloader()
                .DownloadCurrentUnitDownloadCentrePage();

            DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter()
                .ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses();

            CurrentUnitMediasAndTranscriptsDownloader()
                .DownloadCurrentUnitMediasAndTranscripts();

            CurrentUnitVocabularyAndGrammarReferenceDownloader()
                .DownloadCurrentUnitVocabularyAndGrammarReference();
        }
    }

    void DownloadCourseWithoutUnits()
    {}
}


int main()
{
    while (bbc_6_minute::CurrentCourse().Go())
    {
        bbc_6_minute::DownloadCourseWithUnits();
        bbc_6_minute::DownloadCourseWithoutUnits();
    }
}