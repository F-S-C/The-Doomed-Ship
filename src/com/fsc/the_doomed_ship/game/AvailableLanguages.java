package com.fsc.the_doomed_ship.game;

import com.fsc.the_doomed_ship.Language;

public enum AvailableLanguages {
    ENGLISH(new Language("en", "English")),
    ITALIAN(new Language("it", "Italiano"));

    private final Language language;

    AvailableLanguages(Language language){
        this.language = language;
    }

    public Language getLanguage() {
        return language;
    }
}
