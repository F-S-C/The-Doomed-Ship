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

import the_doomed_ship.game


def main():
    game = the_doomed_ship.game.Game()
    curses.wrapper(game.main_loop)
