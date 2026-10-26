// WinTune.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//void printAscii()
//{
//    std::cout << R"( __      __.__     ___________                           ____ 
///  \    /  \__| ___\__    ___/_ __  ____   ____   ___  _/_   |
//\   \/\/   /  |/    \|    | |  |  \/    \_/ __ \  \  \/ /|   |
// \        /|  |   |  \    | |  |  /   |  \  ___/   \   / |   |
//  \__/\  / |__|___|  /____| |____/|___|  /\___  >   \_/  |___|
//       \/          \/                  \/     \/              )" << "\n\n";
//}

//printAscii();

    //// create registryprovider object
    //// used to read and write reg values
    //RegistryProvider registry;

    //DWORD currentWin32Value = 0;

    //// reads current value of win32priosep from reg - > currentValue

    //// success = true if read successful, false if not
    //// later used as validation for conditions
    //bool success = registry.readDword(
    //    HKEY_LOCAL_MACHINE,
    //    L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
    //    L"Win32PrioritySeparation",
    //    currentWin32Value
    //);

    //std::vector<Tweak> regTweaks;

    //Tweak win32PrioritySeparation(
    //    "win32_priority_separation",
    //    "Win32 Priority Separation",
    //    "Controls foreground and background process scheduling.",
    //    "CPU / Scheduling",
    //    "Advanced",
    //    std::to_string(currentWin32Value),
    //    "42",
    //    "regedit"
    //);

    //regTweaks.push_back(win32PrioritySeparation);

    ////for 
    ////{

    ////}

    //// if win32prio read success -> print curr value, else print error msg
    ///*if (success)
    //{
    //    std::cout << "Current Win32PrioritySeparation value: " << currentValue << '\n';
    //}
    //else
    //{
    //    std::cout << "Failed to read registry value.\n";
    //}*/

    //bool menuRunning = true;

    //while (menuRunning)
    //{
    //    std::cout << "1. Registry tweaks\n";
    //    std::cout << "2. Exit\n"; \

    //        int choice;
    //    std::cin >> choice;

    //    if (choice == 1)
    //    {
    //        bool registryMenuRunning = true;

    //        while (registryMenuRunning)
    //        {
    //            system("cls");

    //            printAscii();

    //            for (int i = 0; i < regTweaks.size(); ++i)
    //            {
    //                std::cout << i + 1 << ". " << regTweaks[i].getName() << '\n';
    //            }

    //            std::cout << regTweaks.size() + 1 << ". " << "Return\n";

    //            std::cin >> choice;

    //            if (choice == regTweaks.size() + 1)
    //            {
    //                registryMenuRunning = false;

    //                system("cls");

    //                printAscii();
    //            }

    //            if (choice <= regTweaks.size() && choice > 0)
    //            {
    //                // if tweaks[choice - 1] (list num - 1 = index) --- > update win32priovalue
    //                if (regTweaks[choice - 1].getId() == "win32_priority_separation")
    //                {
    //                    std::cout << regTweaks[choice - 1].getName() << "\n";
    //                    std::cout << "Current value: " << regTweaks[choice - 1].getCurrVal() << "\n";
    //                    std::cout << "Recommended value: " << regTweaks[choice - 1].getRecVal() << "\n";

    //                    DWORD newValue = 0x2A;

    //                    bool success2 = registry.writeDword(
    //                        HKEY_LOCAL_MACHINE,
    //                        L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
    //                        L"Win32PrioritySeparation",
    //                        newValue
    //                    );

    //                    if (success2)
    //                    {
    //                        std::cout << "Win32PrioritySeparation has been set to 2a" << '\n';

    //                    }

    //                    else
    //                    {
    //                        std::cout << "Failed to change Win32PrioritySeparation value.\n";
    //                    }

    //                    std::cin >> choice;
    //                }
    //            }
    //        }
    //    }

    //    else if (choice == 2)
    //    {
    //        std::cout << "tank yu com again\n";
    //        return false;
    //    }
    //}

    //return 0;

#include "WinTuneApp.h"

int main()
{
    WinTuneApp menu;

    menu.run();
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
