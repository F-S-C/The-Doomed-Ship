package com.fsc.the_doomed_ship;

public class Language {
    private String iso639;
    private String name;

    public Language(String iso639, String name) {
        this.iso639 = iso639;
        this.name = name;
    }

    public String getIso639() {
        return iso639;
    }

    public void setIso639(String iso639) {
        this.iso639 = iso639;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
