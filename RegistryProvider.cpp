#include "RegistryProvider.h"

bool RegistryProvider::readDword(
    HKEY rootKey,
    const std::wstring& subKey,
    const std::wstring& valueName,
    DWORD& outputValue
)
{
    DWORD valueType;
    DWORD dataSize = sizeof(outputValue);

    HKEY openedKey = nullptr;

    LSTATUS openResult = RegOpenKeyExW(
        rootKey,
        subKey.c_str(),
        0,
        KEY_QUERY_VALUE,
        &openedKey
    );

    if (openResult != ERROR_SUCCESS)
    {
        return false;
    }

    LSTATUS queryResult = RegQueryValueExW(
        openedKey,
        valueName.c_str(),
        nullptr,
        &valueType,
        reinterpret_cast<LPBYTE>(&outputValue),
        &dataSize
    );

    RegCloseKey(openedKey);

    if (queryResult != ERROR_SUCCESS || valueType != REG_DWORD)
    {
        return false;
    }

    return true;
}

bool RegistryProvider::writeDword(
    HKEY rootKey,
    const std::wstring& subKey,
    const std::wstring& valueName,
    DWORD newValue
    )
{
    DWORD dataSize = sizeof(newValue);

    HKEY openedKey = nullptr;

    LSTATUS openResult = RegOpenKeyExW(
        rootKey,
        subKey.c_str(),
        0,
        KEY_SET_VALUE,
        &openedKey
    );

    if (openResult != ERROR_SUCCESS)
    {
        return false;
    }

    LSTATUS setResult = RegSetValueExW(
        openedKey,
        valueName.c_str(),
        0,
        REG_DWORD,
        reinterpret_cast<const BYTE*>(&newValue),
        dataSize
    );

    RegCloseKey(openedKey);

    if (setResult != ERROR_SUCCESS)
    {
        return false;
    }

    return true;
}