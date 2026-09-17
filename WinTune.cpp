// WinTune.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tweak.h"
#include "RegistryProvider.h"

int main()
{

    std::cout << R"( __      __.__     ___________                           ____ 
/  \    /  \__| ___\__    ___/_ __  ____   ____   ___  _/_   |
\   \/\/   /  |/    \|    | |  |  \/    \_/ __ \  \  \/ /|   |
 \        /|  |   |  \    | |  |  /   |  \  ___/   \   / |   |
  \__/\  / |__|___|  /____| |____/|___|  /\___  >   \_/  |___|
       \/          \/                  \/     \/              )" << "\n\n";



    RegistryProvider registry;

    DWORD currentValue = 0;

    bool success = registry.readDword(
        HKEY_LOCAL_MACHINE,
        L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
        L"Win32PrioritySeparation",
        currentValue
    );

    Tweak win32PrioritySeparation(
        "win32_priority_separation",
        "Win32 Priority Separation",
        "Controls foreground and background process scheduling.",
        "CPU / Scheduling",
        "Advanced",
        std::to_string(currentValue),
        "42"
    );

    /*if (success)
    {
        std::cout << "Current Win32PrioritySeparation value: " << currentValue << '\n';
    }
    else
    {
        std::cout << "Failed to read registry value.\n";
    }*/

    bool menuRunning = true;

    while (menuRunning)
    {
        std::cout << "1. Registry tweaks\n";
        std::cout << "2. Exit\n";\
        
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            return true;
        }

        else if (choice == 2)
        {
            return false;
        }
    }

    

    /*DWORD newValue = 0x2A;

    bool success2 = registry.writeDword(
        HKEY_LOCAL_MACHINE,
        L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
        L"Win32PrioritySeparation",
        newValue
    );

    if (success2)
    {
        std::cout << "Win32PrioritySeparation has been set to 2a" << '\n';

    }

    else
    {
        std::cout << "Failed to change Win32PrioritySeparation value.\n";
    }*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
