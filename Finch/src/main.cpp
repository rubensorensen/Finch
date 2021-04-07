#include "Vec2D.h"
#include "Window.h"
#include <iostream>

int main() {
	
	Console console;
	console.InitializeConsole();

	while (console.IsRunning())
	{
		console.UpdateConsole();
	}

	return 0;
}