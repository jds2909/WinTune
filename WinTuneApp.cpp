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
        "regedit",
        {
            {
                38,
                "Short, variable - 3x foreground quantum",
                "Desktop-style baseline (0x26). Foreground threads receive "
                "three times the background quantum length. Favours the active "
                "application under CPU contention; does not guarantee higher FPS."
            },
            {
                37,
                "Short, variable - 2x foreground quantum",
                "Experimental (0x25). Foreground threads receive twice the "
                "background quantum length. Reduces foreground preference "
                "compared with 38; may help competing background work at the "
                "expense of the active application."
            },
            {
                36,
                "Short, variable - no foreground extension",
                "Experimental (0x24). Foreground and background threads use "
                "the same short quantum length. Removes foreground quantum "
                "preference; may disadvantage the active application under "
                "contention. Other scheduling priorities still apply."
            },
            {
                40,
                "Short, fixed - no foreground extension",
                "Experimental (0x28). Uses the fixed short-quantum table, "
                "without a foreground quantum extension. Its quantum lengths "
                "differ from 36 despite both being labelled short. May change "
                "throughput and responsiveness; benchmark before retaining."
            }
        }
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
        printAscii();
        std::cout << "1. Registry tweaks\n";
        std::cout << "2. Exit\n"; \

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
    bool registryMenuRunning = true;

    while (registryMenuRunning)
    {
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
            printAscii();
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
        // vector of option structs
        auto optionStructs = regTweaks[choice - 1].getOptions();

        std::cout << regTweaks[choice - 1].getName() << "\n";
        std::cout << regTweaks[choice - 1].getDesc() << "\n";
        std::cout << "Current value: " << regTweaks[choice - 1].getCurrVal() << "\n";
        std::cout << "\n";
        for (int i = 0; i < (regTweaks[choice - 1].getOptions()).size(); ++i)
        {
            if (optionStructs[i].value == stoi(regTweaks[choice - 1].getCurrVal()))
            {
                std::cout << i + 1 << ". " << optionStructs[i].value << " " << optionStructs[i].label << " (X)" << "\n";
            }

            else
            {
                std::cout << i + 1 << ". " << optionStructs[i].value << " " << optionStructs[i].label << "\n";
            }
        }

        std::cout << (regTweaks[choice - 1].getOptions().size()) + 1 << ". Exit" << "\n";

        DWORD newValue = 0x2A;

        /*bool success2 = registry.writeDword(
            HKEY_LOCAL_MACHINE,
            L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
            L"Win32PrioritySeparation",
            newValue
        );*/

        /*if (success2)
        {
            std::cout << "Win32PrioritySeparation has been set to 2a" << '\n';

        }

        else
        {
            std::cout << "Failed to change Win32PrioritySeparation value.\n";
        }*/

        std::cin >> newChoice;

        bool valueMenuRunning = true;


        while (valueMenuRunning)
        {
            // if newChoice = options total + 1 (exit)
            if (newChoice == (regTweaks[choice - 1].getOptions().size()) + 1)
            {
                return;
            }

            else if (newChoice >= 1 && newChoice <= regTweaks[choice - 1].getOptions().size())
            {
                // newChoice - 1 = index of struct for selected option.
                printAscii();
                std::cout << regTweaks[choice - 1].getName() << "\n";
                std::cout << "Current value: " << regTweaks[choice - 1].getCurrVal() << "\n";
                std::cout << "Selected value: " << optionStructs[newChoice - 1].value << "\n";
                std::cout << optionStructs[newChoice - 1].description << "\n";
                std::cin >> newChoice;
            }

            else
            {
                invalidInput();
                printAscii();
                showTweakDetails(choice);
            }
        }
    }
}

void WinTuneApp::printAscii()
{
    system("cls");
    std::cout << R"( __      __.__     ___________                           ____ 
/  \    /  \__| ___\__    ___/_ __  ____   ____   ___  _/_   |
\   \/\/   /  |/    \|    | |  |  \/    \_/ __ \  \  \/ /|   |
 \        /|  |   |  \    | |  |  /   |  \  ___/   \   / |   |
  \__/\  / |__|___|  /____| |____/|___|  /\___  >   \_/  |___|
       \/          \/                  \/     \/              )" << "\n\n";
}