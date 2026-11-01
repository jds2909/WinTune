#pragma once

#include "RegistryProvider.h"
#include "Tweak.h"
#include <vector>

class WinTuneApp
{
public:
	void run();

private:
	std::vector<Tweak> regTweaks;
	int choice;

	void invalidInput();
	void alreadySelected();
	bool showMainMenu();
	void showRegistryMenu();
	void showTweakDetails();
	void selectedValueMenu();
	void printAscii();
	bool confirmSelection(const std::string& input);

	RegistryProvider registry;
};

