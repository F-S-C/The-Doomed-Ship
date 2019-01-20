#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class progress_bar
{
public:
	progress_bar(int max);
	progress_bar(int max, const std::string& msg, const char symb);

	void operator++();
	void operator++(int);
	progress_bar & operator+=(const int right);
private:
	int progress;
	int max;
	std::string message;
	char symbol;
	void show_progress_bar();
};

void clear_screen();

int press_any_key(const wchar_t* prompt);

inline int press_any_key(const std::string& prompt = "Premi un tasto per continuare...\n")
{
	std::wstring widestr = std::wstring(prompt.begin(), prompt.end());
	const wchar_t* wide = widestr.c_str();
    return press_any_key(wide);
}

template <typename _ObjectToPrint>
void print_colored(const _ObjectToPrint& msg, unsigned color);

bool get_yn_response(const std::string& message);

#ifdef _WIN32
#include <windows.h>
#include <iostream>
template <typename _ObjectToPrint>
void print_colored(const _ObjectToPrint& msg, unsigned color)
{
	HANDLE  hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	SetConsoleTextAttribute(hConsole, color);
	std::cout << msg << std::endl;
	SetConsoleTextAttribute(hConsole, 0x0f);
}
#endif