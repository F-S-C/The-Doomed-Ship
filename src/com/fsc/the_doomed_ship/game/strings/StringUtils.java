package com.fsc.the_doomed_ship.game.strings;

public abstract class StringUtils {
    public static final int DEFAULT_WIDTH = 45;
    
    public static String center(String string) {
        return center(string, DEFAULT_WIDTH);
    }

    public static String center(String string, int width) {
        if (string == null || width <= string.length())
            return string;

        StringBuilder sb = new StringBuilder(width);
        sb.append(" ".repeat((width - string.length()) / 2));
        sb.append(string);
        while (sb.length() < width) {
            sb.append(' ');
        }
        return sb.toString();
    }

    public static String wrap(String string) {
        return wrap(string, DEFAULT_WIDTH);
    }

    public static String wrap(String string, int width) {
        if (string == null) {
            return null;
        }
        if (width < 1) {
            width = 1;
        }

        String[] strings = string.split("\n");
        StringBuilder wrappedLine = new StringBuilder();

        for (String currentString : strings) {
            int inputLineLength = currentString.length();
            int offset = 0;

            while (inputLineLength - offset > width) {
                if (currentString.charAt(offset) == ' ') {
                    offset++;
                    continue;
                }
                int spaceToWrapAt = currentString.lastIndexOf(' ', width + offset);

                if (spaceToWrapAt >= offset) {
                    wrappedLine.append(currentString, offset, spaceToWrapAt);
                    wrappedLine.append("\n");
                    offset = spaceToWrapAt + 1;

                } else {
                    // do not wrap really long word, just extend beyond limit
                    spaceToWrapAt = currentString.indexOf(' ', width + offset);
                    if (spaceToWrapAt >= 0) {
                        wrappedLine.append(currentString, offset, spaceToWrapAt);
                        wrappedLine.append("\n");
                        offset = spaceToWrapAt + 1;
                    } else {
                        wrappedLine.append(currentString.substring(offset));
                        offset = inputLineLength;
                    }
                }
            }

            // Whatever is left in line is short enough to just pass through
            wrappedLine.append(currentString.substring(offset));
            wrappedLine.append("\n");
        }

        wrappedLine.deleteCharAt(wrappedLine.length() - 1);

        return wrappedLine.toString();
    }
}
