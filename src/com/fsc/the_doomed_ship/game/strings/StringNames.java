package com.fsc.the_doomed_ship.game.strings;

public enum StringNames {
    GAME_TITLE("title"),
    ORIGINAL_AUTHOR("original_author"),       ///< The original game's authors.
    AUTHOR("author"),                  ///< The modified game's authors.
    COPYRIGHT("copyright"),               ///< A copyright notice.
    VERSION("version"),                ///< The game's version.
    INTRODUCTION("introduction");           ///< The game's introduction.

    private final String name;

    StringNames(String s) {
        name = s;
    }

    @Override
    public String toString() {
        return name;
    }
}
