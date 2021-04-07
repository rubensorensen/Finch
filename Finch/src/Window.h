#pragma once

#include <Windows.h>
#include <stdint.h>
#include <string>

#ifndef UNICODE
#error Please enable UNICODE for your compiler
#endif

class Console
{

public:

	enum  COLOR {
		FG_BLACK		=	0x0000,
		FG_DARK_BLUE	=	0x0001,
		FG_DARK_GREEN	=	0x0002,
		FG_DARK_CYAN	=	0x0003,
		FG_DARK_RED		=	0x0004,
		FG_DARK_MAGENTA	=	0x0005,
		FG_DARK_YELLOW	=	0x0006,
		FG_GRAY			=	0x0007,
		FG_DARK_GRAY	=	0x0008,
		FG_BLUE			=	0x0009,
		FG_GREEN		=	0x000A,
		FG_CYAN			=	0x000B,
		FG_RED			=	0x000C,
		FG_MAGENTA		=	0x000D,
		FG_YELLOW		=	0x000E,
		FG_WHITE		=	0x000F,

		BG_BLACK		=	0x0000,
		BG_DARK_BLUE	=	0x0010,
		BG_DARK_GREEN	=	0x0020,
		BG_DARK_CYAN	=	0x0030,
		BG_DARK_RED		=	0x0040,
		BG_DARK_MAGENTA =	0x0050,
		BG_DARK_YELLOW	=	0x0060,
		BG_GRAY			=	0x0070,
		BG_DARK_GRAY	=	0x0080,
		BG_BLUE			=	0x0090,
		BG_GREEN		=	0x00A0,
		BG_CYAN			=	0x00B0,
		BG_RED			=	0x00C0,
		BG_MAGENTA		=	0x00D0,
		BG_YELLOW		=	0x00E0,
		BG_WHITE		=	0x00F0
	};

	enum  PIXEL {
		SOLID			=	0x2588,
		THREEQUARTERS	=	0x2593,
		HALF			=	0x2592,
		QUARTER			=	0x2591
	};

	Console(const wchar_t* title = L"Finch Framework", const uint16_t width = 160u, uint16_t height = 100u, uint8_t fWidth = 8u, uint8_t fHeight = 8u, short backgroundColor = COLOR::FG_WHITE);
	~Console();

	void ClearConsole(short col);
	void InitializeConsole();
	void GetConsoleEvents();
	void UpdateConsole();

	bool IsRunning();
	uint8_t ScreenWidth();
	uint8_t ScreenHeight();
	uint8_t FontWidth();
	uint8_t FontHeight();

	void Swap(int& a, int& b);
	void Clip(int& x, int& y);

	void Draw(int x, int y, PIXEL ch = PIXEL::SOLID, short col = COLOR::FG_BLACK);
	void Fill(int x1, int y1, int x2, int y2, PIXEL ch = PIXEL::SOLID, short col = COLOR::FG_BLACK);
	void DrawString(int x, int y, std::wstring text, short col = COLOR::FG_BLACK | COLOR::BG_WHITE);
	void DrawLine(int x1, int y1, int x2, int y2, PIXEL c = PIXEL::SOLID, short col = COLOR::FG_BLACK);
	void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, PIXEL ch = PIXEL::SOLID, short col = COLOR::FG_BLACK);
	void DrawCircle(int xc, int yc, int r, PIXEL c = PIXEL::SOLID, short col = COLOR::FG_BLACK);


private:

	//wchar_t* m_Title;
	uint16_t m_ScreenWidth{ 160u };
	uint16_t m_ScreenHeight{ 100u };
	uint8_t m_FSizeW{ 8u };
	uint8_t m_FSizeH{ 8u };

	short m_BackGround;

	//	Set up character buffer
	CHAR_INFO* m_ConsoleBuffer;

	//	Create handles for reading and writing to the console
	HANDLE m_wHnd;
	HANDLE m_rHnd;

	SMALL_RECT m_WindowSize;
	COORD m_BufferSize;

	INPUT_RECORD* m_EventBuffer = nullptr;
	CONSOLE_FONT_INFOEX m_cfi;

	bool m_AppIsRunning{ true };
};