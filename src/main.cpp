#include "supportingTools.hpp"


int main()
{
    bbc_6_minute::DownloadCurrentUnitMediasAndTranscriptsUrlAddresses();

    bbc_6_minute::CheckFilesExistenceOnFilesystem(bbc_6_minute::GetMediasAndTranscriptsUrlAddresses());
}