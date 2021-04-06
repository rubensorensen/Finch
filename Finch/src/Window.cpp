#include "Window.h"

Console::Console(const wchar_t* title, const uint8_t width, uint8_t height, uint8_t fWidth, uint8_t fHeight, short backGroundColor)
{
	//	Set title of window
	SetConsoleTitle(title);
	m_ScreenWidth = width;
	m_ScreenHeight = height;
	m_FSizeW = fWidth;
	m_FSizeH = fHeight;
	m_BackGround = backGroundColor;
}

bool Console::IsRunning()
{
	return m_AppIsRunning;
}

uint8_t Console::ScreenWidth()
{
	return m_ScreenWidth;
}

uint8_t Console::ScreenHeight()
{
	return m_ScreenHeight;
}

uint8_t Console::FontWidth()
{
	return m_FSizeW;
}

uint8_t Console::FontHeight()
{
	return m_FSizeH;
}

void Console::ClearConsole(short col)
{
	for (int i{ 0 }; i < m_ScreenWidth * m_ScreenHeight; ++i)
	{
		m_ConsoleBuffer[i].Char.UnicodeChar = PIXEL::SOLID;
		m_ConsoleBuffer[i].Attributes = col;
	}
}

void Console::InitializeConsole()
{
	//	Set handles for reading from and writing to the console
	m_wHnd = { GetStdHandle(STD_OUTPUT_HANDLE) };
	m_rHnd = { GetStdHandle(STD_INPUT_HANDLE) };

	//	Set window size
	m_WindowSize = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(m_wHnd, TRUE, &m_WindowSize);

	// Create COORD to hold buffer size
	m_BufferSize = { m_ScreenWidth, m_ScreenHeight };

	//	Change internal buffer size
	SetConsoleScreenBufferSize(m_wHnd, m_BufferSize);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = m_FSizeW;
	cfi.dwFontSize.Y = m_FSizeH;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(m_wHnd, false, &cfi);

	//	Set physical window size
	m_WindowSize = { 0, 0, m_ScreenWidth - 1, m_ScreenHeight - 1 };
	SetConsoleWindowInfo(m_wHnd, TRUE, &m_WindowSize);

	m_ConsoleBuffer = new CHAR_INFO[m_ScreenWidth * m_ScreenHeight];
	memset(m_ConsoleBuffer, 0, sizeof(CHAR_INFO) * m_ScreenWidth * m_ScreenHeight);

	ClearConsole(m_BackGround);
}

void Console::UpdateConsole()
{
	//	Set up positions
	COORD charBufSize { m_ScreenWidth, m_ScreenHeight };
	COORD characterPos = { 0, 0 };
	SMALL_RECT writeArea{ 0, 0, m_ScreenWidth - 1, m_ScreenHeight - 1 };

	//	Copy buffer to display
	WriteConsoleOutputW(m_wHnd, m_ConsoleBuffer, charBufSize, characterPos, &writeArea);
	GetConsoleEvents();
}

void Console::GetConsoleEvents()
{
	//	How many events have happened?
	DWORD numEvents{ 0 };

	//	How many events have we read from the console?
	DWORD numEventsRead{ 0 };

	//	How many events have happened?
	GetNumberOfConsoleInputEvents(m_rHnd, &numEvents);

	if (numEvents != 0)
	{
		//	Creeate a buffer to store events
		INPUT_RECORD* m_EventBuffer{ new INPUT_RECORD[numEvents] };

		//	Read console events into the buffer, save how many events have been read into numEventsRead
		ReadConsoleInput(m_rHnd, m_EventBuffer, numEvents, &numEventsRead);

		//	Cycle through all events that have happened
		for (DWORD i{ 0 }; i < numEventsRead; ++i)
		{
			//	Check event type
			if (m_EventBuffer[i].EventType == KEY_EVENT)
			{
				//	Was is the escape key?
				if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
				{
					system("CLS");
					delete m_ConsoleBuffer;
					delete[] m_EventBuffer;
					m_AppIsRunning = false;
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
				{
					ClearConsole(m_BackGround);
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F1)
				{
					Draw(rand() % m_ScreenWidth, rand() % m_ScreenHeight, PIXEL::SOLID, rand() % 256);
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F2)
				{
					Fill(rand() % m_ScreenWidth, rand() % m_ScreenHeight, rand() % m_ScreenWidth, rand() % m_ScreenHeight, PIXEL::SOLID, rand() % 256);
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F3)
				{
					DrawString(rand() % m_ScreenWidth, rand() % m_ScreenHeight, L"Hello World!");
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F4)
				{
					DrawLine(rand() % m_ScreenWidth, rand() % m_ScreenHeight, rand() % m_ScreenWidth, rand() % m_ScreenHeight, PIXEL::SOLID, rand() % 256);
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F5)
				{
					DrawTriangle(rand() % m_ScreenWidth, rand() % m_ScreenHeight, rand() % m_ScreenWidth, rand() % m_ScreenHeight, rand() % m_ScreenWidth, rand() % m_ScreenHeight, PIXEL::SOLID, rand() % 256);
				}
				else if (m_EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F6)
				{
					DrawCircle(rand() % m_ScreenWidth, rand() % m_ScreenHeight, rand() % (m_ScreenHeight < m_ScreenWidth ? m_ScreenHeight / 2 : m_ScreenWidth / 2), PIXEL::SOLID, rand() % 256);
				}
			}
		}
		delete[] m_EventBuffer;
	}
}

void Console::Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Console::Clip(int& x, int& y)
{
	if (x < 0) x = 0;
	else if (x > m_ScreenWidth) x = m_ScreenWidth;
	if (y < 0) y = 0;
	else if (y > m_ScreenHeight) y = m_ScreenHeight;
}

void Console::Draw(int x, int y, PIXEL ch, short col)
{
	if (x >= 0 && x < m_ScreenWidth && y >= 0 && y < m_ScreenHeight)
	{
		m_ConsoleBuffer[x + y * m_ScreenWidth].Char.UnicodeChar = ch;
		m_ConsoleBuffer[x + y * m_ScreenWidth].Attributes = col;
	}
}

void Console::Fill(int x1, int y1, int x2, int y2, PIXEL ch, short col)
{
	Clip(x1, y1);
	Clip(x2, y2);
	if (x1 > x2)
		Swap(x1, x2);
	if (y1 > y2)
		Swap(y1, y2);
	for (int x{ x1 }; x < x2; x++)
	{
		for (int y{ y1 }; y < y2; y++)
		{
			Draw(x, y, ch, col);
		}
	}
}

void Console::DrawString(int x, int y, std::wstring text, short col)
{
	if (x + text.size() + y * m_ScreenWidth <= m_ScreenWidth * m_ScreenHeight)
	{
		for (size_t i{ 0 }; i < text.size(); i++)
		{
			m_ConsoleBuffer[x + i + y * m_ScreenWidth].Char.UnicodeChar = text[i];
			m_ConsoleBuffer[x + i + y * m_ScreenWidth].Attributes = col;
		}
	}
}

void Console::DrawLine(int x1, int y1, int x2, int y2, PIXEL c, short col)
{
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1; dy = y2 - y1;
	dx1 = abs(dx); dy1 = abs(dy);
	px = 2 * dy1 - dx1;	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1; y = y1; xe = x2;
		}
		else
		{
			x = x2; y = y2; xe = x1;
		}

		Draw(x, y, c, col);

		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
				px = px + 2 * dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}
			Draw(x, y, c, col);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1; y = y1; ye = y2;
		}
		else
		{
			x = x2; y = y2; ye = y1;
		}

		Draw(x, y, c, col);

		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
				py = py + 2 * dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1; else x = x - 1;
				py = py + 2 * (dx1 - dy1);
			}
			Draw(x, y, c, col);
		}
	}
}

void Console::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, PIXEL ch, short col)
{
	DrawLine(x1, y1, x2, y2, ch, col);
	DrawLine(x1, y1, x3, y3, ch, col);
	DrawLine(x2, y2, x3, y3, ch, col);
}

void Console::DrawCircle(int xc, int yc, int r, PIXEL c, short col)
{
	int x = 0;
	int y = r;
	int p = 3 - 2 * r;
	if (!r) return;

	while (y >= x) // only formulate 1/8 of circle
	{
		Draw(xc - x, yc - y, c, col);//upper left left
		Draw(xc - y, yc - x, c, col);//upper upper left
		Draw(xc + y, yc - x, c, col);//upper upper right
		Draw(xc + x, yc - y, c, col);//upper right right
		Draw(xc - x, yc + y, c, col);//lower left left
		Draw(xc - y, yc + x, c, col);//lower lower left
		Draw(xc + y, yc + x, c, col);//lower lower right
		Draw(xc + x, yc + y, c, col);//lower right right
		if (p < 0) p += 4 * x++ + 6;
		else p += 4 * (x++ - y--) + 10;
	}
}