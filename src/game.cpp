#include "game.h"

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <iomanip>

#include "utilities.h"

using namespace std;

game::game()
{
	mCurrentLang = languages::AvailableLanguages::ITALIAN;
	mEndGame = false;

	get_strings();
}

game::~game()
{
}

void game::begin()
{
	do
	{
		unsigned menu_choice = show_menu();

		switch (menu_choice)
		{
		case 1u:
			clear_screen();
			exec();
			break;
		case 2u:
			change_language();
			break;
		case 3u:
			end_game();
			break;
		default:
			break;
		}
	} while (!mEndGame);
}

void game::show_intro()
{
	cout << colored_string("#" + center_string(mStrings[GAME_TITLE]) + "#", colored_string::PrintColors::GREEN) << endl
		 << colored_string("#" + center_string(mStrings[ORIGINAL_AUTHOR]) + "#", colored_string::PrintColors::GREEN) << endl
		 << colored_string("#" + center_string(mStrings[AUTHOR]) + "#", colored_string::PrintColors::GREEN) << endl
		 << endl
		 << center_string(mStrings[COPYRIGHT], 40) << endl
		 << center_string(mStrings[VERSION], 40) << endl
		 << endl
		 << wrap_string(mStrings[INTRODUCTION]) << endl
		 << endl;
	press_any_key();
}

unsigned game::show_menu()
{
	clear_screen();
	cout << "==========================================" << endl
		 << "                   MENU" << endl
		 << "==========================================" << endl;

	for (int i = MENU_FIRST_OPTION; i <= MENU_EXIT; i++)
		cout << i - MENU_FIRST_OPTION + 1 << ". " << mStrings[i] << endl;

	int option = get_value_in_range(1u, static_cast<unsigned>(MENU_EXIT - MENU_FIRST_OPTION + 1u), mStrings[MENU_INPUT_PROMPT], mStrings[ERROR_STRING]);

	return option;
}

void game::change_language()
{
	cout << mStrings[LANGUAGE_SUBMENU_TITLE] << endl;
	for (unsigned i = 0; i < sizeof(mLanguages) / sizeof(mLanguages[static_cast<languages::AvailableLanguages>(0)]); i++)
		cout << i + 1 << ". " << mLanguages[static_cast<languages::AvailableLanguages>(i)].name << endl;

	int option = get_value_in_range(1u, static_cast<unsigned>(languages::NUMBER_OF_AVAILABLE_LANGUAGES), mStrings[MENU_INPUT_PROMPT], mStrings[ERROR_STRING]);

	mCurrentLang = static_cast<languages::AvailableLanguages>(option - 1);
	get_strings();
}

void game::end_game()
{
	mEndGame = true;
}

void game::exec()
{
	// TODO: Complete
	show_intro();
}

void game::get_strings()
{
	ifstream mInputFile("./res/" + mLanguages[mCurrentLang].ISO639_1 + "/preliminary");
	int i = 0;

	while (!mInputFile.eof())
	{
		getline(mInputFile, mStrings[i]);
		cryptography::decrypt(mStrings[i]);
		mStrings[i] = regex_replace(mStrings[i], regex("\\\\n"), "\n\n");
		i++;
	}

	mInputFile.close();
	mInputFile.open("./res/" + mLanguages[mCurrentLang].ISO639_1 + "/menu");

	while (!mInputFile.eof())
	{
		getline(mInputFile, mStrings[i]);
		cryptography::decrypt(mStrings[i]);
		i++;
	}

	mInputFile.close();
}

game::languages::languages(const language (&pLang)[NUMBER_OF_AVAILABLE_LANGUAGES]) noexcept
{
	for (int i = 0; i < NUMBER_OF_AVAILABLE_LANGUAGES; i++)
		mLanguages[i] = pLang[i];
}

game::languages::language &game::languages::operator[](AvailableLanguages lang) noexcept
{
	return mLanguages[static_cast<unsigned>(lang)];
}