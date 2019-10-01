package com.fsc.the_doomed_ship.game.strings;

public enum MenuStrings {
    MENU_FIRST_OPTION("menu_first_option"),        ///< The first option of the menu
    MENU_SECOND_OPTION("menu_second_option"),        ///< The second option of the menu
    MENU_EXIT("menu_exit"),                ///< The "Exit" option of the menu
    MENU_INPUT_PROMPT("menu_input_prompt"),        ///< The message that will be printed to wait a user input in the menu.
    MENU_LANGUAGE_SUBMENU_TITLE("menu_language_submenu_title"),        ///< The message that will be printed to wait a user input in the menu.
    ERROR_STRING("menu_error");            ///< The error message that will be printed if an input fails.

    private final String name;

    MenuStrings(String s) {
        name = s;
    }

    @Override
    public String toString() {
        return name;
    }
}
