#include "PVec.h"
#include "Window.h"

int main(void) {
	Console console(L"Finch Framework", 200, 100, 8, 8, Console::COLOR::FG_DARK_GRAY);
	console.InitializeConsole();
	while (console.IsRunning())
	{
		console.UpdateConsole();
	}

	return 0;
}