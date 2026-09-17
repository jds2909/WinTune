#pragma once

#include <Windows.h>
#include <string>

class RegistryProvider
{
public:
    bool readDword(
        HKEY rootKey,
        const std::wstring& subKey,
        const std::wstring& valueName,
        DWORD& outputValue
    );

    bool writeDword(
        HKEY rootKey,
        const std::wstring& subKey,
        const std::wstring& valueName,
        DWORD newValue
    );
};