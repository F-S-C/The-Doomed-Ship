/**
 * \dir utilities
 * \brief Various utilities functions.
 * 
 * This directory contains various files that implements
 * various utilities functions.
 * Each file is included in the utilities.h file, so you
 * must _not_ directly include the content of this directory.
 */
/** 
 * \file string_utilities.h
 * \brief Some utilities functions to be used with strings.
 * 
 * This file contains the declaration of various useful functions
 * that work on `std::string`.
 * 
 * \copyright GNU General Public License version 3.
 * \date January 28, 2019.
 */

#ifndef _STRING_UTILITIES_H
#define _STRING_UTILITIES_H

#include <list>
#include <string>
#include <iostream>

/**
 * \brief Center a string.
 * 
 * Given a string, this functions centers it with spaces.
 * 
 * \param[in] str The string to be centered.
 * \param[in] width The total width of the final string.
 * This is the total width on which the string has to be centered.
 * \return The centered string with trailing spaces (both at the
 * beginning and the ending).
 */
std::string center_string(const std::string &str, unsigned width = 44u);

/**
 * \brief Split a string based on another string.
 * 
 * This function, given a string, splits it in a list of strings
 * based on a `delimiter` string.
 * 
 * \param[in] str The string to be splitted.
 * \param[in] delimiter The delimiter based on which the string has to be 
 * splitted (_optional_).
 * \return A list of string. If the `delimiter` is _not_ found in the `str` string,
 * the list will contain only a string that is equal to `str`. If the `delimiter`
 * is found, instead, the list will contain multiple strings, to which the `delimiter`
 * _has been removed_.
 */
std::list<std::string> split_string(const std::string &str, const std::string &delimiter = "\n");

/**
 * \brief Wrap a string based on a maximum length.
 * 
 * This function, given a string and a maximum linewidth, wraps it to
 * get a better output format. The wrapping is based on a list of characters
 * that will be considered whitespaces.
 * 
 * \param[in] str The string to be wrapped.
 * \param[in] line_width The maximum line width on which the string has to be wrapped (_optional_).
 * \param[in] whitespace The list of character that will be considered as whitespaces (_optional_).
 * \return The wrapped string.
 */
std::string wrap_string(const std::string &str, unsigned line_width = 44u, const std::string &whitespace = " \t\r");

/**
 * \brief A colored string
 * 
 * This class allows to print a colored string to the stdout.
 * This is a cross platform solution.
 */
class colored_string
{
  public:
	/**
     * \brief Printable colors.
  
     * This enumerator contains all the possible colors
     * that can be printed. Each color is identified
     * by an integer.
	 * 
     * \warning The colors have various code based on the platform.
     * This is because some operative systems (like Windows) don't
     * support ASCII Escaped sequences.
     */
	enum class PrintColors : short
	{
#ifdef _WIN32
		BLACK = 0x0,   ///< The black color.
		RED = 0xc,	 ///< The red color.
		GREEN = 0x2,   ///< The green color.
		YELLOW = 0xe,  ///< The yellow color.
		BLUE = 0x9,	///< The blue color.
		MAGENTA = 0xd, ///< The magenta color.
		CYAN = 0xb,	///< The cyan color.
		WHITE = 0xf	///< The white color.
#else
		BLACK = 0,   ///< The black color.
		RED = 1,	 ///< The red color.
		GREEN = 2,   ///< The green color.
		YELLOW = 3,  ///< The yellow color.
		BLUE = 4,	///< The blue color.
		MAGENTA = 5, ///< The magenta color.
		CYAN = 6,	///< The cyan color.
		WHITE = 7	///< The white color.
#endif
	};

	/**
     * \brief Colored string's constructor.
  
     * This creates a new colored string ready to be printed.
	 * 
     * \param[in] str The normal string.
     * \param[in] foreground The foreground color (_optional_).
     * \param[in] background The background color (_optional_).
     */
	colored_string(const std::string &str, const PrintColors foreground = PrintColors::RED, const PrintColors background = PrintColors::BLACK);

	operator std::string() const;

	/**
     * \brief Output the colored string.
  
     * This outputs the colored string to a std::ostream (like `cout`).
	 * 
     * \note This function does _not_ add a new line at the end of the output.
	 * 
     * \param[in] os The output stream.
     * \param[in] str The colored string.
     * \return The modified output stream.
     *
     * # Example
     *
     * The following line of code will print `"Hello World!"` (with an ending
     * new line character) to the stdout. The string will be printed
     * in _red_, using the color _blue_ as background.
     *
     * \code{.cpp}
     * std::cout << colored_string("Hello world!",
     *                  colored_string::PrintColors::RED,
     *                  colored_string::PrintColors::BLUE)
     *           << std::endl;
     * \endcode
     */
	friend std::ostream &operator<<(std::ostream &os, const colored_string &str);

  private:
	std::string m_str;
	std::string m_color;
};

#endif //_STRING_UTILITIES_H