#include "gioco.h"

#include <iostream>
#include <fstream>

#include "utilities.h"

using namespace std;

gioco::gioco()
{
	init();
}

void gioco::init()
{
	fine_partita = false;
	numeroComandi = 0;
	numeroLuoghi = 0;
	numeroAzioni = 0;
	numeroOggetti = 0;
	printf("\nUn attimo di pazienza...\n");

	comandi[++numeroComandi] = comando("a", 5);
	comandi[++numeroComandi] = comando("aggiusta", 27);
	comandi[++numeroComandi] = comando("alto", 5);
	comandi[++numeroComandi] = comando("antenna", 69);
	comandi[++numeroComandi] = comando("apri", 22);
	comandi[++numeroComandi] = comando("armadietto", 67);
	comandi[++numeroComandi] = comando("b", 6);
	comandi[++numeroComandi] = comando("basso", 6);
	comandi[++numeroComandi] = comando("basta", 90); // nuovo comando (ESCI)
	comandi[++numeroComandi] = comando("bottone", 61);
	comandi[++numeroComandi] = comando("camice", 52);
	comandi[++numeroComandi] = comando("cartello", 60);
	comandi[++numeroComandi] = comando("casco", 50);
	comandi[++numeroComandi] = comando("chiave", 54);
	comandi[++numeroComandi] = comando("cosa", 13);
	comandi[++numeroComandi] = comando("e", 3);
	comandi[++numeroComandi] = comando("esci", 90); // Nuovo comando (ESCI)
	comandi[++numeroComandi] = comando("est", 3);
	comandi[++numeroComandi] = comando("etichetta", 70);
	comandi[++numeroComandi] = comando("giallo", 63);
	comandi[++numeroComandi] = comando("guarda", 10);
	comandi[++numeroComandi] = comando("il", 7);
	comandi[++numeroComandi] = comando("indicatore", 66);
	comandi[++numeroComandi] = comando("indossa", 20);
	comandi[++numeroComandi] = comando("inventario", 13);
	comandi[++numeroComandi] = comando("l", 7);
	comandi[++numeroComandi] = comando("la", 7);
	comandi[++numeroComandi] = comando("lascia", 9);
	comandi[++numeroComandi] = comando("leggi", 25);
	comandi[++numeroComandi] = comando("letto", 68);
	comandi[++numeroComandi] = comando("leva", 65);
	comandi[++numeroComandi] = comando("lo", 7);
	comandi[++numeroComandi] = comando("load", 12);
	comandi[++numeroComandi] = comando("manuale", 55);
	comandi[++numeroComandi] = comando("metti", 20);
	comandi[++numeroComandi] = comando("n", 1);
	comandi[++numeroComandi] = comando("nord", 1);
	comandi[++numeroComandi] = comando("o", 4);
	comandi[++numeroComandi] = comando("ovest", 4);
	comandi[++numeroComandi] = comando("premi", 26);
	comandi[++numeroComandi] = comando("prendi", 8);
	comandi[++numeroComandi] = comando("pulsante", 61);
	comandi[++numeroComandi] = comando("ripara", 27);
	comandi[++numeroComandi] = comando("rosso", 64);
	comandi[++numeroComandi] = comando("s", 2);
	comandi[++numeroComandi] = comando("sali", 5);
	comandi[++numeroComandi] = comando("save", 11);
	comandi[++numeroComandi] = comando("scendi", 6);
	comandi[++numeroComandi] = comando("schiaccia", 26);
	comandi[++numeroComandi] = comando("secondo", 53);
	comandi[++numeroComandi] = comando("spingi", 24);
	comandi[++numeroComandi] = comando("sud", 2);
	comandi[++numeroComandi] = comando("tira", 23);
	comandi[++numeroComandi] = comando("togli", 21);
	comandi[++numeroComandi] = comando("tuta", 51);
	comandi[++numeroComandi] = comando("verde", 62);
	comandi[++numeroComandi] = comando("w", 4);


	luoghi[++numeroLuoghi] = luogo("nella cabina di pilotaggio", "000000000002");
	luoghi[++numeroLuoghi] = luogo("ad un'estremita' del corridoio", "000300050100");
	luoghi[++numeroLuoghi] = luogo("nel corridoio", "020400060000");
	luoghi[++numeroLuoghi] = luogo("ad un'estremita' del corridoio", "030000070008");
	luoghi[++numeroLuoghi] = luogo("nella cabina del secondo pilota", "000002000000");
	luoghi[++numeroLuoghi] = luogo("nella tua cabina", "000003000000");
	luoghi[++numeroLuoghi] = luogo("nel compartimento stagno", "000000000000");
	luoghi[++numeroLuoghi] = luogo("nella sala controllo del reattore", "000000000400");
	luoghi[++numeroLuoghi] = luogo("all'esterno, a prua dell'astronave", "001000000000");
	luoghi[++numeroLuoghi] = luogo("all'esterno dell'astronave", "091100000000");
	luoghi[++numeroLuoghi] = luogo("all'esterno, a poppa dell'astronave", "100007000000");


	azioni[++numeroAzioni] = azione(100, 1);
	azioni[++numeroAzioni] = azione(200, 1);
	azioni[++numeroAzioni] = azione(300, 1);
	azioni[++numeroAzioni] = azione(400, 1);
	azioni[++numeroAzioni] = azione(500, 1);
	azioni[++numeroAzioni] = azione(600, 1);
	azioni[++numeroAzioni] = azione(899, -2);
	azioni[++numeroAzioni] = azione(950, -10);
	azioni[++numeroAzioni] = azione(951, -10);
	azioni[++numeroAzioni] = azione(999, 3);
	azioni[++numeroAzioni] = azione(1051, -11);
	azioni[++numeroAzioni] = azione(1052, -14);
	azioni[++numeroAzioni] = azione(1053, -12);
	azioni[++numeroAzioni] = azione(1055, -13);
	azioni[++numeroAzioni] = azione(1060, -13);
	azioni[++numeroAzioni] = azione(1099, -4);
	azioni[++numeroAzioni] = azione(1100, 5);
	azioni[++numeroAzioni] = azione(1200, 6);
	azioni[++numeroAzioni] = azione(1300, 7);
	azioni[++numeroAzioni] = azione(2050, -2);
	azioni[++numeroAzioni] = azione(2051, -2);
	azioni[++numeroAzioni] = azione(2052, -2);
	azioni[++numeroAzioni] = azione(2150, -10);
	azioni[++numeroAzioni] = azione(2151, -10);
	azioni[++numeroAzioni] = azione(2152, -3);
	azioni[++numeroAzioni] = azione(2255, -15);
	azioni[++numeroAzioni] = azione(2555, -15);
	azioni[++numeroAzioni] = azione(2769, -29);
	azioni[++numeroAzioni] = azione(6550, -10);
	azioni[++numeroAzioni] = azione(6551, -10);
	azioni[++numeroAzioni] = azione(6552, -3);
	azioni[++numeroAzioni] = azione(9000, 90); // Nuova azione (ESCI)
	azioni[++numeroAzioni] = azione(11066, 16);
	azioni[++numeroAzioni] = azione(12570, 17);
	azioni[++numeroAzioni] = azione(12661, 18);
	azioni[++numeroAzioni] = azione(20300, 21);
	azioni[++numeroAzioni] = azione(20500, 20);
	azioni[++numeroAzioni] = azione(22560, 19);
	azioni[++numeroAzioni] = azione(30300, 21);
	azioni[++numeroAzioni] = azione(40300, 21);
	azioni[++numeroAzioni] = azione(42560, 22);
	azioni[++numeroAzioni] = azione(52267, 23);
	azioni[++numeroAzioni] = azione(62267, 24);
	azioni[++numeroAzioni] = azione(70300, 37);
	azioni[++numeroAzioni] = azione(70400, 38);
	azioni[++numeroAzioni] = azione(72661, 25);
	azioni[++numeroAzioni] = azione(72662, 27);
	azioni[++numeroAzioni] = azione(72664, 26);
	azioni[++numeroAzioni] = azione(81066, 16);
	azioni[++numeroAzioni] = azione(82365, 35);
	azioni[++numeroAzioni] = azione(82465, 34);
	azioni[++numeroAzioni] = azione(82560, 28);
	azioni[++numeroAzioni] = azione(82661, 30);
	azioni[++numeroAzioni] = azione(82662, 33);
	azioni[++numeroAzioni] = azione(82663, 32);
	azioni[++numeroAzioni] = azione(82664, 31);
	azioni[++numeroAzioni] = azione(91069, 36);


	oggetti[++numeroOggetti] = oggetto(66, -1, "un indicatore");
	oggetti[++numeroOggetti] = oggetto(61, -1, "un pulsante");
	oggetti[++numeroOggetti] = oggetto(70, -1, "un'etichetta");
	oggetti[++numeroOggetti] = oggetto(51, 1, "una tuta");
	oggetti[++numeroOggetti] = oggetto(60, -2, "un cartello bianco");
	oggetti[++numeroOggetti] = oggetto(60, -4, "un cartello giallo");
	oggetti[++numeroOggetti] = oggetto(68, -5, "un letto");
	oggetti[++numeroOggetti] = oggetto(67, -5, "un armadietto");
	oggetti[++numeroOggetti] = oggetto(68, -6, "un letto");
	oggetti[++numeroOggetti] = oggetto(67, -6, "un armadietto");
	oggetti[++numeroOggetti] = oggetto(50, 6, "un casco");
	oggetti[++numeroOggetti] = oggetto(61, -7, "un pulsante rosso");
	oggetti[++numeroOggetti] = oggetto(61, -7, "un pulsante verde");
	oggetti[++numeroOggetti] = oggetto(66, -8, "un indicatore");
	oggetti[++numeroOggetti] = oggetto(65, -8, "una leva");
	oggetti[++numeroOggetti] = oggetto(61, -8, "un pulsante rosso");
	oggetti[++numeroOggetti] = oggetto(61, -8, "un pulsante verde");
	oggetti[++numeroOggetti] = oggetto(60, -8, "un cartello rosso");
	oggetti[++numeroOggetti] = oggetto(61, -8, "un pulsante giallo");
	oggetti[++numeroOggetti] = oggetto(53, 9, "il secondo pilota");
	oggetti[++numeroOggetti] = oggetto(69, -9, "un'antenna parabolica");
	oggetti[++numeroOggetti] = oggetto(52, -99, "un camice");
	oggetti[++numeroOggetti] = oggetto(54, -99, "una chiave");
	oggetti[++numeroOggetti] = oggetto(55, -99, "un manuale");
	// "FO"
}

void gioco::exec()
{
	do
	{
		introduzione();
		pausa();
		clear_screen();
		do
		{
			string inStringa;
			cout << "\nSei " << luoghi[luogoAttuale].get_descrizione().c_str() << ".\n\n";
			elenca("Vedo ", luogoAttuale);
			tempo();
			printf("\n\n");
			do
			{
				inStringa = "";
				printf("Cosa devo fare ? ");
				getline(cin, inStringa);
			} while (inStringa == "");
			printf("\n");
			in = 0;
			string pStringa = estrai(inStringa);
			string p1Stringa = pStringa;
			c1 = static_cast<direzioni>(c);
			if (p1Stringa == "")
				printf("- Beh?\n");
			else if (in > 1 && p1Stringa.substr(in - 2, 2) == "re")
				printf("- Dammi del tu, per favore.\n");
			else if (static_cast<int>(c1) == 0 && p1Stringa[0] != '\0')
				cout << "- Non conosco il verbo '" << p1Stringa << "'.\n";
			else
			{
				pStringa = estrai(inStringa);
				string p2Stringa = pStringa;
				c2 = c;
				if (c2 == 0 && p2Stringa[0] != '\0')
					cout << "- Non conosco la parola '" << p2Stringa << "'.\n";
				else
				{
					if (c2 != 0)
						luogo_oggetto();
					int n1 = luogoAttuale * 10000;
					int n2 = static_cast<int>(c1) * 100;
					azioneCorrente = n1 + n2 + c2;
					azioneCorrente = esegui_azione();
					if (azioneCorrente == 0 && c2 != 0)
					{
						azioneCorrente = n1 + n2 + 99;
						azioneCorrente = esegui_azione();
					}
					if (azioneCorrente == 0)
					{
						azioneCorrente = n2 + c2;
						azioneCorrente = esegui_azione();
					}
					if (azioneCorrente == 0 && c2 != 0)
					{
						azioneCorrente = n2 + 99;
						azioneCorrente = esegui_azione();
					}
					if (azioneCorrente == 0)
						printf("- Non capisco.\n");
				}
			}
		} while (!fine_partita);
	} while (riparti);
}

int gioco::cerca_parola(const string &pStringa)
{
	int i = 1;
	int f = numeroComandi;
	int to_return = 0;

	do
	{
		int a = (i + f) / 2;
		string aStringa = comandi[a].get_parola();

		if (pStringa == aStringa)
			to_return = comandi[a].get_codice();
		else if (pStringa > aStringa)
			i = a + 1;
		else
			f = a - 1;

	} while (i <= f && to_return == 0);

	return to_return;
}

string gioco::estrai(const string& inStringa)
{
	string pStringa = "";
	do
	{
		c = 0;
		while (inStringa[in] == ' ' || inStringa[in] == '\'')
			in++;
		if (in >= inStringa.length())
			pStringa = "";
		else
		{
			azioneCorrente = in;
			while (inStringa[in] != ' ' && inStringa[in] != '\'' && in < inStringa.length())
				in++;

			pStringa = inStringa.substr(azioneCorrente, in - azioneCorrente);
			c = cerca_parola(pStringa);
		}
	} while (c == 7);
	return pStringa;
}

int gioco::cerca_azione(int pAzioneCorrente)
{
	int i = 1;
	int f = numeroAzioni;
	int to_return = 0;
	int n = pAzioneCorrente;

	do 
	{
		pAzioneCorrente = (i + f) / 2;
		int m = azioni[pAzioneCorrente].get_codice();
		if (n == m)
			to_return = azioni[pAzioneCorrente].get_azione();
		else if (n > m)
			i = pAzioneCorrente + 1;
		else
			f = pAzioneCorrente - 1;
	} while (i <= f && to_return == 0);
	pAzioneCorrente = 0;

	return to_return;
}

void gioco::elenca(const string &pInizio, int pLuogo)
{
	for (int i = 1; i <= numeroOggetti; i++) {
		if (abs(oggetti[i].get_luogo()) == pLuogo)
			cout << pInizio << oggetti[i].get_nome() << endl;
	}
	return;
}

void gioco::luogo_oggetto()
{
	og = 0;
	for (int i = 1; i <= numeroOggetti; i++) {
		if (oggetti[i].get_codice() == c2)
			if (abs(oggetti[i].get_luogo()) == luogoAttuale || oggetti[i].get_luogo() == 0) {
				og = i;
				break;
			}
	}
	return;
}

void gioco::pausa()
{
	press_any_key();
}

void gioco::morto()
{
	pausa();
	printf("### IL GAZZETTINO DELLA GALASSIA ###\n");
	printf("\n");
	printf("- Tragedia al largo di Vega -\n");
	printf("\n");
	printf("L'astronave 'Neutronia', in servizio\n");
	printf("passeggeri con 250 persone a bordo,\n");
	printf("e' stata distrutta da una violenta\n");
	printf("esplosione, causata probabilmente\n");
	printf("da imperizia del comandante (un\n");
	printf("novellino, stando a indiscrezioni\n");
	printf("raccolte dal nostro corrispondente)\n");
	printf("Il responsabile del peggior disastro\n");
	printf("della storia galattica sara' di certo\n");
	printf("degradato alla memoria.\n");
	printf("\n");
	fine_partita = true;

	riparti = get_yn_response("Vuoi giocare ancora?");

	if (!riparti)
		cout << "\n\nCiao!\n\n";
}

void gioco::tempo()
{
	mTempoRimanente--;
	if (mTempoRimanente <= 10)
		printf("Sento un segnale di allarme.\n");
	if (mTempoRimanente <= 5)
		printf("La temperatura e' insopportabile.\n");
	if (mTempoRimanente <= 2)
		printf("La nave e' scossa da vibrazioni.\n");
	if (mTempoRimanente == 0) {
		print_colored("\n*** Troppo tardi! ***\n\n", 0x0C);
		cout << "Il reattore e' fuori controllo.\n"
			"L'astronave e' disintegrata in minuscoli frammenti\n"
			"E' incredibile il silenzio delle esplosioni nel vuoto.\n";
		morto();
	}
}

void gioco::introduzione()
{
	clear_screen();
	print_colored("\n"
		"# L'astronave condannata: un'avventura #\n"
		"#  di Enrico Colombini e Chiara Tovena #\n"
		"#     Modificato dal gruppo F.S.C.     #\n",
		0x0a);
	cout << "\n(c) Dinosoft e Jackson Editrice 1985\n"
		"\n"
		"Sdraiato nella sabbia, ti godi il\n"
		"dolce calore del sole tropicale...\n"
		"\n"
		"Ora il sole picchia piu' forte,\n"
		"sei in pieno deserto e non c'e'\n"
		"traccia di oasi...\n"
		"\n"
		"Ti svegli di soprassalto nella tua\n"
		"cabina di comandante del 'Neutronia'.\n"
		"Fa molto caldo. Troppo caldo. Ci\n"
		"dev'essere qualcosa che non funziona.\n\n";
	mTempoRimanente = 100;
	luogoAttuale = 6;
	v1 = 0;
	v2 = 0;
	printf("\n");
	return;
}

void gioco::comune()
{
	v1 = 0;
	mTempoRimanente = mTempoRimanente / 2;
	return;
}

void gioco::spostamento()
{
	azioneCorrente = stoi(luoghi[luogoAttuale].get_direzioni().substr(2 * static_cast<int>(c1) - 2, 2));
	if (azioneCorrente == 0)
		printf("- Di li' non puoi andare\n");
	else
		luogoAttuale = azioneCorrente;
}

void gioco::prendi()
{
	if (oggetti[og].get_luogo() == 0)
		printf("- Gia' fatto.\n");
	else if (oggetti[og].get_luogo() < 0)
		printf("- Non e' possibile.\n");

	else if (og == 4 && oggetti[22].get_luogo() == 0)
		printf("Togli prima il camice.\n");
	else if (og == 22 && oggetti[4].get_luogo() == 0)
		printf("Togli prima la tuta.\n");

	else
	{
		oggetti[og].set_luogo(0);
		if (og == 4 || og == 9 || og == 11)
			printf("Ora l'hai addosso.\n");
		printf("Fatto.\n");
	}
	return;
}

void gioco::lascia()
{
	if (og == 0 || oggetti[og].get_luogo() != 0)
		printf("- Non ce l'hai.\n");
	else if (luogoAttuale < 9) {
		oggetti[og].set_luogo(luogoAttuale);
		printf("Fatto.\n");
	}
	else {
		oggetti[og].set_luogo(-99);
		printf("Si e' perso nello spazio.\n");
	}
	return;
}

void gioco::guarda()
{
	printf("- Non noto nulla di particolare.\n");
	return;
}

void gioco::save()
{
	std::ofstream file(mNomeFile, std::ios::trunc);
	for (int i = 1; i <= numeroOggetti; i++)
		file << oggetti[i].get_luogo() << std::endl;
	file << luogoAttuale << std::endl
		<< mTempoRimanente << std::endl
		<< v1 << std::endl
		<< v2 << std::endl;
	file.close();
}

void gioco::load()
{
	std::ifstream file(mNomeFile);
	for (int i = 1; i <= numeroOggetti; i++)
	{
		int l;
		file >> l;
		oggetti[i].set_luogo(l);
	}
	file >> luogoAttuale >> mTempoRimanente >> v1 >> v2;
	file.close();
}

void gioco::cosa()
{
	printf("Possiedi:\n");
	elenca("- ", 0);
	return;
}

void gioco::vuota()
{
	return;
}

void gioco::azione_10()
{
	if (oggetti[og].get_luogo() != 0)
		printf("Non ce l'hai.\n");
	else if (!(luogoAttuale == 9) || (luogoAttuale == 7 && v2 == 1))
		lascia();
	else {
		printf("L'aria! L'aria! Aaaagh!!!\n");
		morto();
	}
	return;
}

void gioco::guarda_tuta()
{
	printf("E' la tuta per la tua attivita'\n");
	printf("extraveicolare.\n");
	return;
}

void gioco::guarda_secondo_pilota()
{
	printf("E' privo di conoscenza ed ha\n");
	printf("un'ammaccatura nel casco.\n");
	printf("Probabilmente e' stato colpito\n");
	printf("da un piccolo meteorite mentre\n");
	printf("riparava l'antenna. Per\n");
	printf("fortuna, e' ancora vivo.\n");
	return;
}

void gioco::guarda_cartello()
{
	printf("Non e' meglio leggerlo?\n");
	return;
}

void gioco::azione_14()
{
	printf("E' piuttosto pesante.\n");
	printf("Probabilmente, e'\n");
	printf("trattato al piombo.\n");
	return;
}

void gioco::leggi_manuale()
{
	if (oggetti[og].get_luogo() == luogoAttuale)
		printf("Prendilo in mano, prima.\n");
	else {
		printf("- MANUALE DI ISTRUZIONI DEL -\n");
		printf("-   REATTORE POSITRONICO    -\n");
		printf("-     Mod. YTREWQ 8421      -\n\n");
		printf("- Per attivare il reattore,\n");
		printf("tirare la leva e poi premere\n");
		printf("in sequenza i pulsanti verde,\n");
		printf("giallo e rosso.\n");
		printf("- Per disattivare il reattore...\n");
		printf("\nDannazione! La pagina e' strappata.\n");
	}
	return;
}

void gioco::azione_16()
{
	printf("- TEMPERATURA REATTORE -\n\n");
	printf("Segna %d gradi e sta\n", 840 - mTempoRimanente * 4);
	printf("salendo velocemente. C'e'\n");
	printf("un segno rosso a 800 gradi.\n");
	return;
}

void gioco::azione_17()
{
	printf("- S.O.S. GALATTICO -\n\n");
	printf("Premere il pulsante solo\n");
	printf("in caso di emergenza.\n");
	printf("Ogni abuso verra' punito.\n");
	return;
}

void gioco::azione_18()
{
	printf("Una scritta lampeggia brevemente:\n\n");
	printf("- ANTENNA ESTERNA DIFETTOSA -\n");
	return;
}

void gioco::azione_19()
{
	printf("E' alla base di una scaletta\n");
	printf("e dice:\n\n");
	printf("INGRESSO RISERVATO AL\n");
	printf("PERSONALE DI BORDO.\n");
	return;
}

void gioco::azione_20()
{
	luogoAttuale = 1;
	if (oggetti[20].get_luogo() == 9) {
		printf("Se solo ci fosse qui il secondo\n");
		printf("pilota, il solo che se ne intende\n");
		printf("di problemi tecnici!\n");
	}
	return;
}

void gioco::azione_21()
{
	printf("Meglio non svegliare i\n");
	printf("passeggeri, potrebbero\n");
	printf("farsi prendere dal panico.\n");
	return;
}

void gioco::azione_22()
{
	printf("E' posto ad ovest e dice:\n\n");
	printf("- ATTENZIONE: -\n\n");
	printf("STANZA DEPRESSURIZZATA\n");
	return;
}

void gioco::azione_23()
{
	if (oggetti[24].get_luogo() != -99)
		printf("Gia' fatto.\n");
	else if (oggetti[23].get_luogo() != 0)
		printf("E' chiuso a chiave.\n");
	else {
		printf("Fatto.\n");
		oggetti[24].set_luogo(luogoAttuale);
		oggetti[22].set_luogo(luogoAttuale);
	}
	return;
}

void gioco::apri_armadietto_personaggio()
{
	printf("E' vuoto.\n");
	return;
}

void gioco::azione_25()
{
	printf("Dimmi: 'Premi il rosso'\n");
	printf("o 'Premi il verde'.\n");
	return;
}

void gioco::azione_26()
{
	if (v2 == 1)
		printf("Click.\n");
	else {
		printf("La parete ad est si chiude.\n");
		printf("La parete ad ovest si apre\n");
		printf("verso lo spazio esterno.\n");
		printf("L'aria esce sibilando.\n");
		if (oggetti[4].get_luogo() != 0 || oggetti[11].get_luogo() != 0) {
			printf("\nAaaagh!\n");
			morto();
		}
		else {
			for (int i = 1; i <= numeroOggetti; i++) {
				if (oggetti[i].get_luogo() == luogoAttuale) {
					cout << oggetti[i].get_nome() << " si perde nello spazio\n";
					oggetti[i].set_luogo(-99);
				}
			}
			v2 = 1;
		}
	}
	return;
}

void gioco::azione_27()
{
	if (v2 == 0)
		printf("Click.\n");
	else {
		printf("La parete ad ovest si chiude.\n");
		printf("La parete ad est si apre\n");
		printf("verso il corridoio.\n");
		printf("L'aria rientra sibilando.\n");
		v2 = 0;
		if (!(oggetti[20].get_luogo() != 0 || oggetti[23].get_luogo() != -99)) {
			printf("\nIl secondo pilota rinviene, si rende\n");
			printf("subito conto della situazione e dice:\n\n");
			printf("- Presto, ferma il reattore!\n");
			printf("Ecco la chiave del mio...\n");
			printf("Poi perde nuovamente i sensi\n");
			oggetti[23].set_luogo(luogoAttuale);
		}
	}
	return;
}

void gioco::azione_28()
{
	printf("- L'EMERGENZA E' IN AGGUATO! -\n");
	printf("-    Porta sempre con te     -\n");
	printf("-  il manuale del reattore.  -\n");
	return;
}

void gioco::azione_29()
{
	printf("Il tecnico e' il secondo pilota.\n");
	return;
}

void gioco::azione_30()
{
	printf("Dimmi: 'Premi il rosso', 'Premi\n");
	printf("il verde' o 'Premi il giallo'.\n");
	return;
}

void gioco::azione_31()
{
	printf("Click.\n");
	if (v1 != 0)
		comune();
	else {
		printf("Una tubatura perde leggermente\n");
		printf("da un raccordo (probabilmente per\n");
		printf("sovrapressione). Le gocce cadono sul\n");
		printf("quadro di controllo, vicino a te.\n");
		v1 = 1;
	}
	return;
}

void gioco::azione_32()
{
	printf("Click.\n");
	if (v1 != 1)
		comune();
	else {
		v1 = 2;
		if (oggetti[22].get_luogo() != 0)
			printf("Non ti senti troppo bene.\n");
	}
	return;
}

void gioco::azione_33()
{
	printf("Click.\n");
	if (v1 != 2)
		comune();
	else {
		v1 = 3;
		if (oggetti[22].get_luogo() != 0) {
			printf("Temo che tu abbia assorbito troppe\n");
			printf("radiazioni. Ora stai decisamente\n");
			printf("male. Perdi conoscenza...\n");
			morto();
		}
	}
	return;
}

void gioco::vittoria()
{
	printf("Clanck.\n");
	if (v1 != 3)
		comune();
	else {
		pausa();
		printf("### IL GAZZETTINO DELLA GALASSIA ###\n\n");
		printf("- Comandante salva astronave -\n\n");
		printf("L'astronave 'Neutronia', in servizio\n");
		printf("passeggeri con 250 persone a bordo,\n");
		printf("e' stata salvata da sicura distruzione\n");
		printf("grazie al coraggio e al sangue freddo\n");
		printf("del comandante, che e' riuscito a\n");
		printf("disattivare il reattore impazzito.\n");
		printf("Il suo nome verra' ricordato per\n");
		printf("sempre tra gli eroi della nostra\n");
		printf("flotta galattica\n\n");
		printf("\n- Congratulazioni! -\n\n");
		fine_partita = true;
		riparti = false;
	}
	return;
}

void gioco::azione_35()
{
	cout << "Clunck.\n";
}

void gioco::azione_36()
{
	printf("Sembra danneggiata, forse\n");
	printf("da un grosso meteorite.\n");
	return;
}

void gioco::azione_37()
{
	if (v2 == 0)
		luogoAttuale = 4;
	else
		spostamento();
	return;
}

void gioco::azione_38()
{
	if (v2 == 1)
		luogoAttuale = 11;
	else
		spostamento();
	return;
}

void gioco::esci()
{	
	if (get_yn_response("Vuoi salvare la partita?"))
		save();

	cout << "Arrivederci!\n";
	press_any_key();
	fine_partita = true;
	riparti = false;
}

void gioco::esegui(int pAzioneCorrente)
{
	switch (pAzioneCorrente)
	{
	case 1:
		spostamento();
		break;
	case 2:
		prendi();
		break;
	case 3:
		lascia();
		break;
	case 4:
		guarda();
		break;
	case 5:
		save();
		break;
	case 6:
		load();
		break;
	case 7:
		cosa();
		break;
	case 8: case 9:
		vuota();
		break;
	case 10:
		azione_10();
		break;
	case 11:
		guarda_tuta();
		break;
	case 12:
		guarda_secondo_pilota();
		break;
	case 13:
		guarda_cartello();
		break;
	case 14:
		azione_14();
		break;
	case 15:
		leggi_manuale();
		break;
	case 16:
		azione_16();
		break;
	case 17:
		azione_17();
		break;
	case 18:
		azione_18();
		break;
	case 19:
		azione_19();
		break;
	case 20:
		azione_20();
		break;
	case 21:
		azione_21();
		break;
	case 22:
		azione_22();
		break;
	case 23:
		azione_23();
		break;
	case 24:
		apri_armadietto_personaggio();
		break;
	case 25:
		azione_25();
		break;
	case 26:
		azione_26();
		break;
	case 27:
		azione_27();
		break;
	case 28:
		azione_28();
		break;
	case 29:
		azione_29();
		break;
	case 30:
		azione_30();
		break;
	case 31:
		azione_31();
		break;
	case 32:
		azione_32();
		break;
	case 33:
		azione_33();
		break;
	case 34:
		vittoria();
		break;
	case 35:
		azione_35();
		break;
	case 36:
		azione_36();
		break;
	case 37:
		azione_37();
		break;
	case 38:
		azione_38();
		break;
	case 90:
		esci();
		break;
	default:
		printf("AZIONE %d", pAzioneCorrente);
	}
}

int gioco::esegui_azione()
{
	int mAzione = cerca_azione(azioneCorrente);
	if (mAzione != 0)
	{
		if (c2 == 0 || mAzione > 0)
			esegui(mAzione);
		else
		{
			mAzione = -mAzione;
			if (og == 0)
				printf("- Qui non c'e'.\n");
			else
				esegui(mAzione);
		}
		mAzione = 1;
	}
	return mAzione;
}
