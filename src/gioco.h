#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>

#include "oggetto.h"
#include "luogo.h"
#include "comando.h"
#include "azione.h"

class gioco
{
private:
	enum class direzioni : unsigned int
	{
		INVALID = 0,
		NORD = 1,
		SUD = 2,
		EST = 3,
		OVEST = 4,
		SU = 5,
		GIU = 6
	};
public:
	gioco();

	void exec();

	int cerca_parola(const std::string &pStringa);
	std::string estrai(const std::string &inStringa);
	int cerca_azione(int pAzioneCorrente);
	void elenca(const std::string &pInizio, int pLuogo);
	void luogo_oggetto();
	void pausa();
	void morto();
	void tempo();
	void introduzione();
	void comune();
	void spostamento();

	void prendi();
	void lascia();
	void guarda();
	void save();
	void load();
	void cosa();
	void vuota();
	void azione_10();
	void guarda_tuta();					/// azione 11
	void guarda_secondo_pilota();		/// azione 12
	void guarda_cartello();				/// azione 13
	void azione_14();
	void leggi_manuale();				/// azione 15
	void azione_16();
	void azione_17();
	void azione_18();
	void azione_19();
	void azione_20();
	void azione_21();
	void azione_22();
	void azione_23();
	void apri_armadietto_personaggio();	/// azione 24
	void azione_25();
	void azione_26();
	void azione_27();
	void azione_28();
	void azione_29();
	void azione_30();
	void azione_31();
	void azione_32();
	void azione_33();
	void vittoria();					/// azione 34
	void azione_35();
	void azione_36();
	void azione_37();
	void azione_38();
	void esci();						/// azione 90

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
	int mTempoRimanente;

	oggetto oggetti[50];
	luogo luoghi[30];
	comando comandi[100];
	azione azioni[150];

	//TODO: check
	
	int luogoAttuale;
	int og;
	int v1;
	int v2;
	int c;
	int azioneCorrente;
	direzioni c1;
	int c2;
	int in;

	static constexpr char const *mNomeFile = "astro";
};