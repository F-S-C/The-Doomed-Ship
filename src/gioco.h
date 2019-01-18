#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>

#include "oggetto.h"
#include "luogo.h"
#include "comando.h"
#include "azione.h"

class gioco
{
public:
	gioco();

	void exec();

	int cerca_parola();
	void estrai();
	int cerca_azione(int pAzioneCorrente);
	void elenca();
	void luogo_oggetto();
	void pausa();
	void morto();
	void tempo();
	void introduzione();
	void comune();
	void direzioni();

	void prendi();
	void lascia();
	void guarda();
	void save();
	void load();
	void cosa();
	void vuota();
	void azione_10();
	void azione_11();
	void azione_12();
	void azione_13();
	void azione_14();
	void azione_15();
	void azione_16();
	void azione_17();
	void azione_18();
	void azione_19();
	void azione_20();
	void azione_21();
	void azione_22();
	void azione_23();
	void azione_24();
	void azione_25();
	void azione_26();
	void azione_27();
	void azione_28();
	void azione_29();
	void azione_30();
	void azione_31();
	void azione_32();
	void azione_33();
	void azione_34();
	void azione_35();
	void azione_36();
	void azione_37();
	void azione_38();
	void esci();

	void esegui(int pAzioneCorrente);
	int esegui_azione();

private:
	void init();

	bool fine_partita;
	bool riparti;

	int numeroComandi;
	int numeroLuoghi;
	int numeroAzioni;
	int numeroOggetti;

	oggetto oggetti[50];
	luogo luoghi[30];
	comando comandi[100];
	azione azioni[150];

	//TODO: check

	int mTempoRimanente;
	int lu;
	int og;
	int v1;
	int v2;
	int c;
	int azioneCorrente;
	int m;
	int n;
	int i;
	int f;
	std::string inStringa;
	std::string pStringa;
	std::string p1Stringa;
	std::string p2Stringa;
	int c1;
	int c2;
	int n1, n2;
	int li;
	int in;
	int mLuogoAttuale;
	std::string aStringa;

	std::string fStringa = "astro";
	FILE *file;
};