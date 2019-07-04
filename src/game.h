/**
 * \file game.h
 * \brief The main header of the project.
 *
 * This header contains the declaration of all the core functions of the game.
 *
 * \copyright GNU General Public License version 3.
 */

#ifndef THE_DOOMED_SHIP_GAME_H
#define THE_DOOMED_SHIP_GAME_H


#include <string>
#include <array>

/**
 * \brief The game.
 *
 * This class contains all the core functions of the game.
 * It's in this class that the main loop of the game can be found.
 */
class game
{
public:
    game();

    ~game();

    void begin();

protected:
    /**
     * \brief An array of languages.
     *
     * This class is a wrapper for an array of languages. It is used
     * to check data types and avoid errors.
     */
    class languages
    {
    protected:
        /**
         * \brief a language
         */
        struct language
        {
            std::string ISO639_1; ///< The ISO 639-1 code of the language (two letters code).
            std::string name;     ///< The name of the language. This is a name that can be printed and selected by the user.
        };

    public:
        /**
         * \brief All the available languages.
         *
         * This enumerator is used to get a particular language by
         * a costant and is useful to make the code more readable.
         *
         * \warning Do *not* modify the first and last values: this
         * enumerator is used to index an array.
         */
        enum AvailableLanguages : unsigned
        {
            ITALIAN = 0,                  ///< The constant for the *Italian* language.
            ENGLISH,                      ///< The constant for the *English* language.
            NUMBER_OF_AVAILABLE_LANGUAGES ///< A useful constant that indicates how many languages are available.
        };

        /**
         * \brief Languages' array's constructor.
         *
         * This construct a new languages' array.
         *
         * \param[in] pLang An array of languages.
         */
        explicit languages(const language (&pLang)[NUMBER_OF_AVAILABLE_LANGUAGES]) noexcept;

        /**
         * \brief Get a language.
         *
         * This gets a language using its code.
         *
         * \param[in] lang The language's code. It
         * must be one defined in the AvailableLanguages
         * enumerator.
         */
        language &operator[](AvailableLanguages lang) noexcept;

    private:
        language mLanguages[NUMBER_OF_AVAILABLE_LANGUAGES]; ///< The underlaying array of languages.
    };

    /**
     * \brief The main loop.
     *
     * This is the main loop of the game. In this loop,
     * all the user's input (regarding actions in the game)
     * and game events take place.
     */
    void exec();

    /**
     * \brief All the game's strings' codes.

     * This enumerator is used to get the code associated
     * with a string. This allows to write a more readable
     * code.
     *
     * \warning Do *not* modify the first and last values: this
     * enumerator is used to index an array.
     */
    enum String_Resources : unsigned
    {
        GAME_TITLE = 0,            ///< The game's title.
        ORIGINAL_AUTHOR,        ///< The original game's authors.
        AUTHOR,                    ///< The modified game's authors.
        COPYRIGHT,                ///< A copyright notice.
        VERSION,                ///< The game's version.
        INTRODUCTION,            ///< The game's introduction.
        ERROR_STRING,            ///< The error message that will be printed if an input fails.
        MENU_FIRST_OPTION,        ///< The first option of the menu
        MENU_SECOND_OPTION,        ///< The second option of the menu
        MENU_EXIT,                ///< The "Exit" option of the menu
        MENU_INPUT_PROMPT,        ///< The message that will be printed to wait a user input in the menu.
        LANGUAGE_SUBMENU_TITLE, ///< The title of the language selection sub-menu.
        RES_STRING_NUMBER        ///< A useful constant that indicates how many strings are being saved.
    };

    std::string mStrings[RES_STRING_NUMBER]; ///< The array containing all the game strings.

    /// The object containing the array of languages.
    languages mLanguages = languages({{"it", "Italiano"},
                                      {"en", "English"}});

    languages::AvailableLanguages mCurrentLang; ///< The current selected language's code.
    bool mEndGame;                                ///< Does the game have to end?

private:
    void end_game();

    void change_language();

    unsigned show_menu();

    void show_intro();

    void get_strings();
};

#endif //THE_DOOMED_SHIP_GAME_H
