#include "currentUnitDownloadCentrePageDownloader.hpp"
#include "downloadCentrePageMediasAndTranscriptsUrlAddressesExtracter.hpp"
#include "currentUnitMediasAndTranscriptsDownloader.hpp"


int main()
{
    bbc_6_minute::CurrentUnitDownloadCentrePageDownloader().DownloadCurrentUnitDownloadCentrePage();

    bbc_6_minute::DownloadCentrePageMediasAndTranscriptsUrlAddressesExtracter().ExtractDownloadCentrePageMediasAndTranscriptsUrlAddresses();

    bbc_6_minute::CurrentUnitMediasAndTranscriptsDownloader().DownloadCurrentUnitMediasAndTranscripts();
}