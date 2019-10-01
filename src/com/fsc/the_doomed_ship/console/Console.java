package com.fsc.the_doomed_ship.console;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;

public class Console {
    private JFrame jFrame;
    private JTextField jTextField;

    private JConsole console;

    public Console() {
        jFrame = new JFrame("The Doomed Ship");
        jFrame.setLayout(new BorderLayout());
        jFrame.getRootPane().setBorder(new EmptyBorder(0, 0, 0, 0));
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.setSize(500, 600);

        console = new JConsole();
        console.setBackground(Color.BLACK);
        console.setForeground(Color.WHITE);
        console.setBorder(new EmptyBorder(10, 10, 10, 10));
        console.setEditable(false);

        System.setOut(console.getPrintStream());
        System.setErr(console.getErrorStream());

        jFrame.getContentPane().add(new JScrollPane(console));

        jTextField = new JTextField();
        jTextField.setBackground(Color.BLACK);
        jTextField.setForeground(Color.WHITE);
        jTextField.setCaretColor(Color.LIGHT_GRAY);
        jTextField.setBorder(new EmptyBorder(10, 10, 10, 10));
        jTextField.setFont(Font.getFont("Lucide Console"));
        jTextField.requestFocusInWindow();


        jFrame.add(jTextField, BorderLayout.PAGE_END);

        jFrame.setVisible(true);
    }

    public void close() {
        jFrame.dispose();
    }

    public void getInput(Consumer<String> consumer) {
        AtomicBoolean done = new AtomicBoolean(false);
        while (!done.get()) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            jTextField.addActionListener(e -> {
                String s = jTextField.getText().trim();
                if (!s.isEmpty()) {
                    println(s);
                    consumer.accept(s);
                }
                jTextField.setText("");
                done.set(true);
            });
        }
    }

    public int getIntegerInRange(int min, int max, String prompt, String error) {
        AtomicInteger option = new AtomicInteger(max + 1);
        AtomicBoolean first = new AtomicBoolean(true);
        do {
            if (!first.get())
                System.out.print(error + " ");
            System.out.print(prompt + ": ");
            while (option.get() > max || option.get() < min) {
                try {
                    Thread.sleep(200);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                jTextField.addActionListener(e -> {
                    String s = jTextField.getText().trim();
                    if (!s.isEmpty()) {
                        println(s);
                        option.set(Integer.parseInt(s));
                    }
                    jTextField.setText("");
                    first.set(false);
                });
            }
            first.set(false);
        } while (option.get() < min || option.get() > max);
        return option.get();
    }

    public void pressAnyKey() {
        System.out.println("Press enter to continue...");
        AtomicBoolean done = new AtomicBoolean(false);
        while (!done.get()) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            jTextField.addActionListener(e -> {
                jTextField.setText("");
                done.set(true);
            });
        }
    }

    public void clear() {
        console.clear();
    }

    public void print(String s) {
        System.out.print(s);
    }

    public void println(String s) {
        System.out.println(s);
    }

    public void println() {
        System.out.println();
    }

    public void printColored(String s, Color c) {
        console.printColored(s, c);
    }

    public void printlnColored(String s, Color c) {
        console.printlnColored(s, c);
    }
}
