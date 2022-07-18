#include "currentCourse.hpp"
#include "currentUnit.hpp"
#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.hpp"
#include "currentUnitMediasAndTranscriptsDownloader.hpp"
#include "currentUnitVocabularyAndGrammarReferenceDownloader.hpp"


int main()
{
    while (bbc_6_minute::CurrentCourse().Go())
    {
        while (bbc_6_minute::CurrentUnit().Go())
        {
            bbc_6_minute::CurrentUnitDownloadCentrePageDownloader()
                .DownloadCurrentUnitDownloadCentrePage();

            bbc_6_minute::DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter()
                .ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses();

            bbc_6_minute::CurrentUnitMediasAndTranscriptsDownloader()
                .DownloadCurrentUnitMediasAndTranscripts();

            bbc_6_minute::CurrentUnitVocabularyAndGrammarReferenceDownloader()
                .DownloadCurrentUnitVocabularyAndGrammarReference();
        }
    }
}