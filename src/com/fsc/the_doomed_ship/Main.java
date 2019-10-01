package com.fsc.the_doomed_ship;

import com.fsc.the_doomed_ship.console.Console;
import com.fsc.the_doomed_ship.console.JConsole;
import com.fsc.the_doomed_ship.game.Game;

import javax.swing.*;
import java.awt.*;

/**
 * The main class.
 */
public class Main {

    /**
     * The application entry point.
     * @param args The application arguments.
     */
    public static void main(String[] args) {
        Game game = new Game();
        game.begin();
    }
}
