#pragma once

#include "common.h"


namespace bbc_6_minute
{
    std::string GetWgetCommandLine();

    void GetFilesUrlAddressesForDownload();

    void CheckFileExistenceOnFilesystem();
}