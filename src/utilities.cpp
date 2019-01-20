#include "utilities.h"

#include <algorithm>

using namespace std;

bool get_yn_response(const std::string & message)
{
	string input = "";
	enum class ResponseType { YES, NO, INVALID } response;
	do
	{
		if (input != "")
			cout << "Risposta non valida. ";
		cout << message << " (s/n) ";
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input == "s" || input == "si" || input == "si'" || input == "y" || input == "yes")
			response = ResponseType::YES;
		else if (input == "n" || input == "no")
			response = ResponseType::NO;
		else
			response = ResponseType::INVALID;

	} while (response == ResponseType::INVALID);

	return response == ResponseType::YES;
}

#ifdef _WIN32
/* ---------------------------------------------------------------------------
 * PressAnyKey()
 * ---------------------------------------------------------------------------
 * Copyright 2008 Michael Thomas Greer
 * http://www.boost.org/LICENSE_1_0.txt
 *
 * function
 *   Optionally print a message and and wait for the user to press (and
 *   release) a single key.
 *
 * arguments
 *   The message to print. If NULL, uses a default message. Specify the empty
 *   string "" to not print anything.
 *
 * returns
 *   The virtual keycode for the key that was pressed.
 *
 *   Windows #defines virtual keycode values like
 *     VK_UP
 *     VK_DOWN
 *     VK_RIGHT
 *     VK_LEFT
 *   which you can use to identify special keys.
 *
 *   Letter keys are simply the upper-case ASCII value for that letter.
 */
#include <windows.h>

int press_any_key(const wchar_t *prompt)
{
    DWORD        mode;
    HANDLE       hstdin;
    INPUT_RECORD inrec;
    DWORD        count;
    wchar_t         default_prompt[] = L"Premi un tasto per continuare...\n";

    /* Set the console mode to no-echo, raw input, */
    /* and no window or mouse events.              */
    hstdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hstdin == INVALID_HANDLE_VALUE || !GetConsoleMode( hstdin, &mode ) || !SetConsoleMode( hstdin, 0 ))
		return 0;

    if (!prompt) prompt = default_prompt;

    /* Instruct the user */
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE),
		prompt,
		lstrlen(prompt),
		&count,
		NULL);

    FlushConsoleInputBuffer(hstdin);

    /* Get a single key RELEASE */
    do ReadConsoleInput( hstdin, &inrec, 1, &count );
    while ((inrec.EventType != KEY_EVENT) || inrec.Event.KeyEvent.bKeyDown);

    /* Restore the original console mode */
    SetConsoleMode( hstdin, mode );

    return inrec.Event.KeyEvent.wVirtualKeyCode;
}

void clear_screen()
{
	system("cls");
}
#else
/* ---------------------------------------------------------------------------
 * PressAnyKey()
 * ---------------------------------------------------------------------------
 * Copyright 2008 Michael Thomas Greer
 * http://www.boost.org/LICENSE_1_0.txt
 *
 * function
 *   Optionally print a message and and wait for the user to press (and
 *   release) a single key.
 *
 * arguments
 *   The message to print. If NULL, uses a default message. Specify the empty
 *   string "" to not print anything.
 *
 * returns
 *   The keycode for the key that was pressed.
 *
 *   Extended key codes (like arrow keys) are properly handled, but their
 *   keycode is not understood; they are simply returned as the last code in
 *   the sequence, negated. For example, it is likely that the arrow keys are:
 *
 *     UP_ARROW    = -'A' = -65
 *     DOWN_ARROW  = -'B' = -66
 *     RIGHT_ARROW = -'C' = -67
 *     LEFT_ARROW  = -'D' = -68
 *
 *   Exactly identifying the values for these keys requires a foray into the
 *   terminfo database, which is a subject for later. For now we'll leave it
 *   at this.
 */
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int press_any_key( const wchar_t* prompt )
{
    #define MAGIC_MAX_CHARS 18
    struct termios initial_settings;
    struct termios settings;
    unsigned char  keycodes[ MAGIC_MAX_CHARS ];
    int            count;

    tcgetattr( STDIN_FILENO, &initial_settings );
    settings = initial_settings;

    /* Set the console mode to no-echo, raw input. */
    /* The exact meaning of all this jazz will be discussed later. */
    settings.c_cc[ VTIME ] = 1;
    settings.c_cc[ VMIN  ] = MAGIC_MAX_CHARS;
    settings.c_iflag &= ~(IXOFF);
    settings.c_lflag &= ~(ECHO | ICANON);
    tcsetattr( STDIN_FILENO, TCSANOW, &settings );

    wprintf( "%s", prompt ? prompt : "Premi un tasto per continuare...\n" );
    count = read( stdin, (void*)keycodes, MAGIC_MAX_CHARS );

    tcsetattr( STDIN_FILENO, TCSANOW, &initial_settings );

    return (count == 1) ? keycodes[ 0 ] : -(int)(keycodes[ count -1 ]);
}

void clear_screen()
{
	system("clear");
}
#endif