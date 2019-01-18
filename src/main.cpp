/*
	v0 : strutturazione programma basic
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdio>

#include <iostream>
#include <string>

#include "utilities.h"

#include "gioco.h"

using namespace std;

/* 100 - 140
   ##  AVVENTURA: L'ASTRONAVE CONDANNATA   ##
   ## di Enrico Colombini e Chiara Tovena  ##
   ## (C) 1985 DINOSOFT E JACKSON EDITRICE ##
 - versione in linguaggio C di Stefano Ferilli -
*/




int main()
{
	gioco mGioco = gioco();
	mGioco.exec();
		
	return 0;
}


