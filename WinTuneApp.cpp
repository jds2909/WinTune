#include "WinTuneApp.h"
#include "RegistryProvider.h"
#include "Tweak.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void WinTuneApp::invalidInput()
{
    system("cls");
    std::cout << "Invalid input, try again.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void WinTuneApp::run()
{
    // var to store win32prio value
    DWORD currentWin32Value = 0;

    // reads current value of win32priosep from reg - > currentValue
    bool success = registry.readDword(
        HKEY_LOCAL_MACHINE,
        L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
        L"Win32PrioritySeparation",
        currentWin32Value
    );

    // create win32prio tweak obj
    Tweak win32PrioritySeparation(
        "win32_priority_separation",
        "Win32 Priority Separation",
        "Controls foreground and background process scheduling.",
        "CPU / Scheduling",
        "Advanced",
        std::to_string(currentWin32Value),
        "42",
        "regedit"
    );

    // push to vector containing all tweak objs
    regTweaks.push_back(win32PrioritySeparation);

    // launch main menu, passing allTweaks vec
	showMainMenu();
}

bool WinTuneApp::showMainMenu()
{
    bool menuRunning = true;

    while (menuRunning)
    {
        system("cls");
        printAscii();
        std::cout << "1. Registry tweaks\n";
        std::cout << "2. Exit\n"; \

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            showRegistryMenu();
        }

        else if (choice == 2)
        {
            std::cout << "tank yu com again\n";
            return false;
        }

        else
        {
            invalidInput();
        }
    }

    return 0;
}

void WinTuneApp::showRegistryMenu()
{
    int choice;

    bool registryMenuRunning = true;

    while (registryMenuRunning)
    {
        system("cls");

        printAscii();

        for (int i = 0; i < regTweaks.size(); ++i)
        {
            std::cout << i + 1 << ". " << regTweaks[i].getName() << '\n';
        }

        std::cout << regTweaks.size() + 1 << ". " << "Return\n";

        std::cin >> choice;

        if (choice == regTweaks.size() + 1)
        {
            return;
        }

        else if (choice <= regTweaks.size() && choice > 0)
        {
            showTweakDetails(choice);
            // if tweaks[choice - 1] (list num - 1 = index) --- > update win32priovalue
        }

        else
        {
            invalidInput();
        }
    }
}

void WinTuneApp::showTweakDetails(const int& choice)
{
    int newChoice;

    if (regTweaks[choice - 1].getId() == "win32_priority_separation")
    {
        std::cout << regTweaks[choice - 1].getName() << "\n";
        std::cout << "Current value: " << regTweaks[choice - 1].getCurrVal() << "\n";
        std::cout << "Recommended value: " << regTweaks[choice - 1].getRecVal() << "\n";

        DWORD newValue = 0x2A;

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
        }

        std::cin >> newChoice;
    }
}

void WinTuneApp::printAscii()
{
    std::cout << R"( __      __.__     ___________                           ____ 
/  \    /  \__| ___\__    ___/_ __  ____   ____   ___  _/_   |
\   \/\/   /  |/    \|    | |  |  \/    \_/ __ \  \  \/ /|   |
 \        /|  |   |  \    | |  |  /   |  \  ___/   \   / |   |
  \__/\  / |__|___|  /____| |____/|___|  /\___  >   \_/  |___|
       \/          \/                  \/     \/              )" << "\n\n";
}