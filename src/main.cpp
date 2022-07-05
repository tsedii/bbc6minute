#include "supportingTools.hpp"


int main()
{
    if (!std::filesystem::exists(bbc_6_minute::downloads_file_name))
    {
        std::system(bbc_6_minute::GetWgetCommandLine().c_str());
    }

    bbc_6_minute::GetFilesUrlAddressesForDownload();

    bbc_6_minute::CheckFileExistenceOnFilesystem();
}