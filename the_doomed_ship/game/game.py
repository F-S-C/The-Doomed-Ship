# Copyright (C) 2019 FSC
#
# This file is part of The Doomed Ship.
#
# The Doomed Ship is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# The Doomed Ship is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# The Doomed Ship. If not, see <http://www.gnu.org/licenses/>.

import curses
import textwrap

from the_doomed_ship import __version__
from the_doomed_ship.console import Console

class Game():
    def __init__(self):
        self.ended = False

    def main_loop(self, ui):
        self.ui = Console(ui)
        self.__show_intro()

    def __show_intro(self):
        self.ui.println('The Doomed Ship: an Adventure', curses.color_pair(41), centered=True, pre='#', post='#')
        self.ui.println('by Enrico Colombini and Chiara Tovena', curses.color_pair(41), centered=True, pre='#', post='#')
        self.ui.println('Modified by the F.S.C. group', curses.color_pair(41), centered=True, pre='#', post='#')
        self.ui.print('\n')
        self.ui.println('(c) Dinosoft e Jackson Publishing 1985', centered=True)
        self.ui.println(f'version {__version__}', centered=True)
        self.ui.print('\n')
        self.ui.print_wrap(('''Laying on the sand, you're enjoying the sweet heat of the tropical sun...\nNow the sun is burning harder, you're in the desert and there's not a trace of an oasis...\nYou suddenly wake up in your cabin, the one of the 'Neutronia' commander. It's really hot. Too much. There must be something that doesn't work.'''))
        self.ui.print('\n')

        self.ui.refresh()
        self.ui.pause()
