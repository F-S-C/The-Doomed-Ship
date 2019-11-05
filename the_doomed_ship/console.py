import curses


class Console:
    def __init__(self):
        self.__screen = curses.initscr()
        curses.noecho()
        curses.cbreak()
        curses.start_color()
        self.__screen.keypad(True)
        # curses.wrapper(self.__set_screen)

    def __del__(self):
        curses.nocbreak()
        self.__screen.keypad(False)
        curses.echo()
        curses.endwin()

    def __set_screen(self, screen):
        self.__screen = screen

    # def get_screen(self):
    #     return self.__screen

    def print(self, to_print):
        self.__screen.addstr(f"{to_print}")

    def println(self, to_print):
        self.__screen.addstr(f"{to_print}\n")

    def pause(self):
        self.__screen.getch()

    def clear(self):
        self.__screen.erase()

    def show_menu(self, options: list, title: str = None) -> int:
        curses.init_pair(1, curses.COLOR_WHITE, curses.COLOR_BLACK)
        curses.init_pair(2, curses.COLOR_BLACK, curses.COLOR_WHITE)

        c = 0  # last character read
        option = 0  # the current option that is marked
        while c != 10:  # Enter in ascii
            self.__screen.erase()
            if title is not None:
                self.println(title)
            self.__screen.addstr("What is your class?\n", curses.A_UNDERLINE)
            for i in range(len(options)):
                if i == option:
                    attr = curses.color_pair(2)
                else:
                    attr = curses.color_pair(1)
                self.__screen.addstr(f"{i + 1}. {options[i]}\n", attr)

            c = self.__screen.getch()

            if c == 3: raise KeyboardInterrupt
            if c == curses.KEY_UP and option > 0:
                option -= 1
            elif c == curses.KEY_DOWN and option < len(options) - 1:
                option += 1

        return option
