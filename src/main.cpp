/*!
 * \mainpage The Doomed Ship: an Adventure
 * \image html Logo/Logo.png width=250px
 *
 * \section intro_sec Introduction
 *
 * This project was started by a group of five students of Computer Science
 * (the group **FSC**) as part of an exam and it developed into something
 * bigger than it originally was.
 *
 * \section the_website This Website
 *
 * This website contains the documentation of both the code and the project
 * itself. It has been generated using Doxygen and stylized using the M.CSS's
 * Doxygen template.
 *
 * \section important_pages Important Pages
 * \ref resources &mdash; A description of all the resources used in this project.
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
    game mGame;

    mGame.begin();

    return 0;
}