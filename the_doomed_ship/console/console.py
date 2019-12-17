import curses
import textwrap


class Console():
    __console_width = 64

    def __init__(self, stdscr):
        self.stdscr = stdscr
        curses.resize_term(70, 100)
        curses.start_color()
        curses.use_default_colors()
        for i in range(0, curses.COLORS):
            curses.init_pair(i + 1, i, -1)

    def print(self, text, *attr, color=None, centered=False, pre='', post=''):
        if centered:
            text = text.center(Console.__console_width - len(pre.replace('\n', '')) - len(post.replace('\n', '')))
            if color:
                attr = (curses.color_pair(color),) + attr
        self.stdscr.addstr(pre + text + post, *attr)

    def println(self, text, *attr, color=None, centered=False, pre='', post=''):
        self.print(text, *attr, centered=centered, pre=pre, post=post+'\n', color=color)

    def print_wrap(self, text, *attr, color=None, centered=False, pre='', post=''):
        lines = text.split('\n')
        for line in lines:
            wrapped = textwrap.wrap(line, width=Console.__console_width- len(pre.replace('\n', '')) - len(post.replace('\n', '')))
            # for sub_line in wrapped:
            self.println('\n'.join(wrapped), *attr, centered=centered, pre=pre, post=post, color=color)



    def refresh(self):
        self.stdscr.refresh()

    def pause(self):
        self.stdscr.getkey()
