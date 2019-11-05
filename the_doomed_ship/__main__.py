#!/usr/bin/env python
# -*- coding: utf-8 -*-

from sys import exit
from the_doomed_ship import __version__
from console import Console


def main():
    try:
        console = Console()
        console.print(f"Hello world. This is version {__version__}")
        val = console.show_menu(["Option1", "Option2", "Option3", "Option4"], title="Main Menu")
        console.print(str(val) + "\n")
        console.pause()
    except KeyboardInterrupt:
        exit()


if __name__ == '__main__':
    main()
