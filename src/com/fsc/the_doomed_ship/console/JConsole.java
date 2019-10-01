package com.fsc.the_doomed_ship.console;

import javax.swing.*;
import javax.swing.text.*;
import java.awt.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

public class JConsole extends JTextPane {
    private PrintStream printStream;
    private PrintStream errorStream;

    public JConsole() {
        printStream = new PrintStream(new ConsolePrintStream());
        errorStream = new PrintStream(new ConsolePrintStream(Color.RED));
    }

    public PrintStream getPrintStream() {
        return printStream;
    }

    public PrintStream getErrorStream() {
        return errorStream;
    }

    private void append(String msg, Color c) {
        StyleContext sc = StyleContext.getDefaultStyleContext();
        AttributeSet aset = sc.addAttribute(SimpleAttributeSet.EMPTY, StyleConstants.FontFamily, "Lucida Console");
        aset = sc.addAttribute(aset, StyleConstants.Alignment, StyleConstants.ALIGN_JUSTIFIED);

        if (c != null) aset = sc.addAttribute(aset, StyleConstants.Foreground, c);


        int len = getDocument().getLength();
        try {
            getStyledDocument().insertString(len, msg, aset);
        } catch (BadLocationException e) {
            e.printStackTrace();
        }
    }

    public void printColored(String s, Color c) {
        append(s, c);
    }

    public void printlnColored(String s, Color c) {
        append(s + "\n", c);
    }

    public void clear() {
        try {
            getStyledDocument().remove(0, getDocument().getLength());
        } catch (BadLocationException e) {
            e.printStackTrace();
        }
    }

    private class ConsolePrintStream extends ByteArrayOutputStream {
        Color color;

        ConsolePrintStream() {
            color = null;
        }

        ConsolePrintStream(Color c) {
            color = c;
        }

        public synchronized void write(byte[] b, int off, int len) {
            setCaretPosition(getDocument().getLength());
            String str = new String(b);
            append(str.substring(off, len), color);
        }
    }
}
