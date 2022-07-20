#include "currentCourse.hpp"
#include "currentUnit.hpp"
#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.hpp"
#include "currentUnitMediasAndTranscriptsDownloader.hpp"
#include "currentUnitVocabularyAndGrammarReferenceDownloader.hpp"


namespace bbc_6_minute
{
    void DownloadCoursesWithUnits()
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
}


int main()
{
    while (bbc_6_minute::CurrentCourse().Go())
    {
        bbc_6_minute::DownloadCoursesWithUnits();
    }
}