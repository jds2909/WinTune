#pragma once

#include "RegistryProvider.h"
#include "Tweak.h"
#include <vector>

class WinTuneApp
{
public:
	void run();
	void invalidInput();

private:
	std::vector<Tweak> regTweaks;
	int choice;

	bool showMainMenu();
	void showRegistryMenu();
	void showTweakDetails(const int& choice);
	void printAscii();

	RegistryProvider registry;
};

