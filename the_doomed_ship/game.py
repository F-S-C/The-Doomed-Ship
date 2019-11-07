from pyfiglet import Figlet
from console import Console

class Game:
    def __init__(self):
        self.__console = Console()
        self.__is_game_finished = False
        # TODO: Add dictionaries' initialization

    def exec(self):
        while not self.__is_game_finished:
            self.__begin()
            # TODO: Add main loop body
            self.__end()

    def __end(self):
        self.__is_game_finished = True
        self.__console.pause()

    def __begin(self):
        self.__console.println(Figlet().renderText("The Doomed Ship"))
