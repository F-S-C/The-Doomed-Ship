package com.fsc.the_doomed_ship.game;

import com.fsc.the_doomed_ship.console.Console;
import com.fsc.the_doomed_ship.game.strings.MenuStrings;
import com.fsc.the_doomed_ship.game.strings.StringDictionary;
import com.fsc.the_doomed_ship.game.strings.StringNames;
import com.fsc.the_doomed_ship.game.strings.StringUtils;

import java.awt.*;

/**
 * The game. This class contains all the core functions of the game.
 * It's in this class that the main loop of the game can be found.
 */
public class Game {
    private StringDictionary stringDictionary;
    private boolean isEndGame;
    private AvailableLanguages language;
    private Console console;

    public Game() {
        console = new Console();
        language = AvailableLanguages.ENGLISH;
        isEndGame = false;
        getStrings();
    }

    private void getStrings() {
        String languageSelector = language != AvailableLanguages.ENGLISH ? "-" + language.getLanguage().getIso639() : "";
        stringDictionary = new StringDictionary("./res/strings" + languageSelector + ".xml");
    }

    public void begin() {
        do {
            int menuChoice = showMenu();

            switch (menuChoice) {
                case 1:
                    console.clear();
                    execute();
                    break;
                case 2:
                    changeLanguage();
                    break;
                case 3:
                    end();
                    break;
                default:
                    break;
            }
        } while (!isEndGame);
        console.close();
    }

    /**
     * The main loop. This is the main loop of the game. In this loop,
     * all the user's input (regarding actions in the game)
     * and game events take place.
     */
    private void execute() {
        showIntro();
    }

    private void end() {
        isEndGame = true;
    }

    private void changeLanguage() {
        console.println(stringDictionary.get(MenuStrings.MENU_LANGUAGE_SUBMENU_TITLE));
        for (int i = 0; i < AvailableLanguages.values().length; i++) {
            console.println(i + 1 + ". " + AvailableLanguages.values()[i].getLanguage().getName());
        }

        int option = console.getIntegerInRange(1, AvailableLanguages.values().length, stringDictionary.get(MenuStrings.MENU_INPUT_PROMPT), stringDictionary.get(MenuStrings.ERROR_STRING));
        language = AvailableLanguages.values()[option - 1];
        getStrings();
    }

    private int showMenu() {
        console.clear();
        console.println("=".repeat(StringUtils.DEFAULT_WIDTH));
        console.println(StringUtils.center("MENU"));
        console.println("=".repeat(StringUtils.DEFAULT_WIDTH));

        console.println("1. " + stringDictionary.get(MenuStrings.MENU_FIRST_OPTION));
        console.println("2. " + stringDictionary.get(MenuStrings.MENU_SECOND_OPTION));
        console.println("3. " + stringDictionary.get(MenuStrings.MENU_EXIT));

        return console.getIntegerInRange(1, 3, stringDictionary.get(MenuStrings.MENU_INPUT_PROMPT), stringDictionary.get(MenuStrings.ERROR_STRING));
    }

    private void showIntro() {
        console.printlnColored("#" + StringUtils.center(stringDictionary.get(StringNames.GAME_TITLE)) + "#", Color.GREEN);
        console.printlnColored("#" + StringUtils.center(stringDictionary.get(StringNames.ORIGINAL_AUTHOR)) + "#", Color.GREEN);
        console.printlnColored("#" + StringUtils.center(stringDictionary.get(StringNames.AUTHOR)) + "#", Color.GREEN);
        console.println();
        console.println(StringUtils.center(stringDictionary.get(StringNames.COPYRIGHT)));
        console.println(StringUtils.center(stringDictionary.get(StringNames.VERSION)));
        console.println();
        console.println(StringUtils.wrap(stringDictionary.get(StringNames.INTRODUCTION)));
        console.println();
        console.pressAnyKey();
    }

}
