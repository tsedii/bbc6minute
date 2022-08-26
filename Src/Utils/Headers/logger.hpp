#pragma once


#define FOR_LOG_LINE_FUNC_FILE(MESSAGE) \
    [=](std::string message) -> std::string { return ( \
        message \
        + std::string ( "\n code line : " ) + std::to_string ( __LINE__ ) \
        + std::string ( "\n function name : " ) + std::string ( __func__ ) \
        + std::string ( "\n source file : " ) + std::string ( __FILE__ ) \
    ); \
    }(MESSAGE)

