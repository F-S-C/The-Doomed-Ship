/**
 * \file utilities.h
 * \brief Some utilities functions.
 * 
 * This file contains the declaration and definition of
 * various miscellaneous functions that are useful in
 * various parts of the project.
 * 
 * \copyright GNU General Public License version 3.
 * \date January 28, 2019
 */

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <iostream>
#include <string>
#include <limits>

#include "utilities/string_utilities.h"
#include "utilities/cryptography.h"

/**
 * \brief Get a value in a range.
 * 
 * Given a range, this functions prompt the user for an input.
 * In case of error (if the inserted value isn't in the range or other
 * kind of errors that can set to true the `std::cin.fail()` flag), the
 * user is asked to insert a new value.
 * 
 * \tparam InputType The type of object that must be inserted.
 * \param[in] min The minimum value that can be accepted _(inclusive)_.
 * \param[in] max The maximum value that can be accepted _(inclusive)_.
 * \param[in] prompt The message that will be displayed to ask the user
 * for an input.
 * \param[in] error The message that will be displayed in case of errors.
 * \note \parblock The `error` message is prepended to the prompt value with the only 
 * addition of a space between the two values. So the resulting message will 
 * be like
 * 
 * \code{.cpp} error + " " + prompt\endcode
 * \endparblock
 * \return The inputed value that is in the range [`min`, `max`].
 * \pre In order to use this function on all kinds of object, there must be
 * an ovveride of the `operator <`, `operator >` and 
 * `operator >> (std::istream&, InputType&)`.
 */
template <typename InputType>
InputType get_value_in_range(const InputType &min, const InputType &max, const std::string &prompt, const std::string &error);

/**
 * \brief Clear the screen.
 */
void clear_screen();

/**
 * \brief Press any key.
 * 
 * Prompts the user to press any key to continue and waits
 * for a key press. The execution does _not_ continue while
 * this function is waiting for an input.
 */
void press_any_key();

// Implementation

template <typename InputType>
InputType get_value_in_range(const InputType &min, const InputType &max, const std::string &prompt, const std::string &error)
{
	InputType option;
	bool first = true;
	do
	{
		if (!first)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << error << " ";
		}
		std::cout << prompt << ": ";
		std::cin >> option;
		first = false;
	} while (std::cin.fail() || option < min || option > max);

	return option;
}

void clear_screen()
{
	// TODO: Make cross platform
	system("cls");
}

void press_any_key()
{
	// TODO: Make cross platform
	system("pause");
}

#endif // _UTILITIES_H
