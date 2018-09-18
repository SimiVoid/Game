#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "Menu.h"

#include <iostream>

int main()
{
	Menu * menu = new Menu();

	while (menu->getWindow()->isOpen())
	{
		menu->events();
		menu->update();
		menu->render();
	}

	return 0;
}