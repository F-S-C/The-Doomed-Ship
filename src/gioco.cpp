#include "gioco.h"

#include <iostream>

#include "utilities.h"

using namespace std;

gioco::gioco()
{
	init();
}

void gioco::init()
{
	fine_partita = false;
	fd = 0;
	fm = 0;
	fa = 0;
	fo = 0;
	printf("\nUn attimo di pazienza...\n");

	dzStringa[++fd] = "a"; dz[fd] = 5;
	dzStringa[++fd] = "aggiusta"; dz[fd] = 27;
	dzStringa[++fd] = "alto"; dz[fd] = 5;
	dzStringa[++fd] = "antenna"; dz[fd] = 69;
	dzStringa[++fd] = "apri"; dz[fd] = 22;
	dzStringa[++fd] = "armadietto"; dz[fd] = 67;
	dzStringa[++fd] = "b"; dz[fd] = 6;
	dzStringa[++fd] = "basso"; dz[fd] = 6;
	dzStringa[++fd] = "bottone"; dz[fd] = 61;
	dzStringa[++fd] = "camice"; dz[fd] = 52;
	dzStringa[++fd] = "cartello"; dz[fd] = 60;
	dzStringa[++fd] = "casco"; dz[fd] = 50;
	dzStringa[++fd] = "chiave"; dz[fd] = 54;
	dzStringa[++fd] = "cosa"; dz[fd] = 13;
	dzStringa[++fd] = "e"; dz[fd] = 3;
	dzStringa[++fd] = "est"; dz[fd] = 3;
	dzStringa[++fd] = "etichetta"; dz[fd] = 70;
	dzStringa[++fd] = "giallo"; dz[fd] = 63;
	dzStringa[++fd] = "guarda"; dz[fd] = 10;
	dzStringa[++fd] = "il"; dz[fd] = 7;
	dzStringa[++fd] = "indicatore"; dz[fd] = 66;
	dzStringa[++fd] = "indossa"; dz[fd] = 20;
	dzStringa[++fd] = "inventario"; dz[fd] = 13;
	dzStringa[++fd] = "l"; dz[fd] = 7;
	dzStringa[++fd] = "la"; dz[fd] = 7;
	dzStringa[++fd] = "lascia"; dz[fd] = 9;
	dzStringa[++fd] = "leggi"; dz[fd] = 25;
	dzStringa[++fd] = "letto"; dz[fd] = 68;
	dzStringa[++fd] = "leva"; dz[fd] = 65;
	dzStringa[++fd] = "lo"; dz[fd] = 7;
	dzStringa[++fd] = "load"; dz[fd] = 12;
	dzStringa[++fd] = "manuale"; dz[fd] = 55;
	dzStringa[++fd] = "metti"; dz[fd] = 20;
	dzStringa[++fd] = "n"; dz[fd] = 1;
	dzStringa[++fd] = "nord"; dz[fd] = 1;
	dzStringa[++fd] = "o"; dz[fd] = 4;
	dzStringa[++fd] = "ovest"; dz[fd] = 4;
	dzStringa[++fd] = "premi"; dz[fd] = 26;
	dzStringa[++fd] = "prendi"; dz[fd] = 8;
	dzStringa[++fd] = "pulsante"; dz[fd] = 61;
	dzStringa[++fd] = "ripara"; dz[fd] = 27;
	dzStringa[++fd] = "rosso"; dz[fd] = 64;
	dzStringa[++fd] = "s"; dz[fd] = 2;
	dzStringa[++fd] = "sali"; dz[fd] = 5;
	dzStringa[++fd] = "save"; dz[fd] = 11;
	dzStringa[++fd] = "scendi"; dz[fd] = 6;
	dzStringa[++fd] = "schiaccia"; dz[fd] = 26;
	dzStringa[++fd] = "secondo"; dz[fd] = 53;
	dzStringa[++fd] = "spingi"; dz[fd] = 24;
	dzStringa[++fd] = "sud"; dz[fd] = 2;
	dzStringa[++fd] = "tira"; dz[fd] = 23;
	dzStringa[++fd] = "togli"; dz[fd] = 21;
	dzStringa[++fd] = "tuta"; dz[fd] = 51;
	dzStringa[++fd] = "verde"; dz[fd] = 62;
	dzStringa[++fd] = "w"; dz[fd] = 4;


	luoghi[++fm] = luogo("nella cabina di pilotaggio", "000000000002");
	luoghi[++fm] = luogo("ad un'estremita' del corridoio", "000300050100");
	luoghi[++fm] = luogo("nel corridoio", "020400060000");
	luoghi[++fm] = luogo("ad un'estremita' del corridoio", "030000070008");
	luoghi[++fm] = luogo("nella cabina del secondo pilota", "000002000000");
	luoghi[++fm] = luogo("nella tua cabina", "000003000000");
	luoghi[++fm] = luogo("nel compartimento stagno", "000000000000");
	luoghi[++fm] = luogo("nella sala controllo del reattore", "000000000400");
	luoghi[++fm] = luogo("all'esterno, a prua dell'astronave", "001000000000");
	luoghi[++fm] = luogo("all'esterno dell'astronave", "091100000000");
	luoghi[++fm] = luogo("all'esterno, a poppa dell'astronave", "100007000000");


	ca[++fa] = 100; az[fa] = 1;
	ca[++fa] = 200; az[fa] = 1;
	ca[++fa] = 300; az[fa] = 1;
	ca[++fa] = 400; az[fa] = 1;
	ca[++fa] = 500; az[fa] = 1;
	ca[++fa] = 600; az[fa] = 1;
	ca[++fa] = 899; az[fa] = -2;
	ca[++fa] = 950; az[fa] = -10;
	ca[++fa] = 951; az[fa] = -10;
	ca[++fa] = 999; az[fa] = 3;
	ca[++fa] = 1051; az[fa] = -11;
	ca[++fa] = 1052; az[fa] = -14;
	ca[++fa] = 1053; az[fa] = -12;
	ca[++fa] = 1055; az[fa] = -13;
	ca[++fa] = 1060; az[fa] = -13;
	ca[++fa] = 1099; az[fa] = -4;
	ca[++fa] = 1100; az[fa] = 5;
	ca[++fa] = 1200; az[fa] = 6;
	ca[++fa] = 1300; az[fa] = 7;
	ca[++fa] = 2050; az[fa] = -2;
	ca[++fa] = 2051; az[fa] = -2;
	ca[++fa] = 2052; az[fa] = -2;
	ca[++fa] = 2150; az[fa] = -10;
	ca[++fa] = 2151; az[fa] = -10;
	ca[++fa] = 2152; az[fa] = -3;
	ca[++fa] = 2255; az[fa] = -15;
	ca[++fa] = 2555; az[fa] = -15;
	ca[++fa] = 2769; az[fa] = -29;
	ca[++fa] = 6550; az[fa] = -10;
	ca[++fa] = 6551; az[fa] = -10;
	ca[++fa] = 6552; az[fa] = -3;
	ca[++fa] = 11066; az[fa] = 16;
	ca[++fa] = 12570; az[fa] = 17;
	ca[++fa] = 12661; az[fa] = 18;
	ca[++fa] = 20300; az[fa] = 21;
	ca[++fa] = 20500; az[fa] = 20;
	ca[++fa] = 22560; az[fa] = 19;
	ca[++fa] = 30300; az[fa] = 21;
	ca[++fa] = 40300; az[fa] = 21;
	ca[++fa] = 42560; az[fa] = 22;
	ca[++fa] = 52267; az[fa] = 23;
	ca[++fa] = 62267; az[fa] = 24;
	ca[++fa] = 70300; az[fa] = 37;
	ca[++fa] = 70400; az[fa] = 38;
	ca[++fa] = 72661; az[fa] = 25;
	ca[++fa] = 72662; az[fa] = 27;
	ca[++fa] = 72664; az[fa] = 26;
	ca[++fa] = 81066; az[fa] = 16;
	ca[++fa] = 82365; az[fa] = 35;
	ca[++fa] = 82465; az[fa] = 34;
	ca[++fa] = 82560; az[fa] = 28;
	ca[++fa] = 82661; az[fa] = 30;
	ca[++fa] = 82662; az[fa] = 33;
	ca[++fa] = 82663; az[fa] = 32;
	ca[++fa] = 82664; az[fa] = 31;
	ca[++fa] = 91069; az[fa] = 36;


	oggetti[++fo] = oggetto(66, -1, "un indicatore");
	oggetti[++fo] = oggetto(61, -1, "un pulsante");
	oggetti[++fo] = oggetto(70, -1, "un'etichetta");
	oggetti[++fo] = oggetto(51, 1, "una tuta");
	oggetti[++fo] = oggetto(60, -2, "un cartello bianco");
	oggetti[++fo] = oggetto(60, -4, "un cartello giallo");
	oggetti[++fo] = oggetto(68, -5, "un letto");
	oggetti[++fo] = oggetto(67, -5, "un armadietto");
	oggetti[++fo] = oggetto(68, -6, "un letto");
	oggetti[++fo] = oggetto(67, -6, "un armadietto");
	oggetti[++fo] = oggetto(50, 6, "un casco");
	oggetti[++fo] = oggetto(61, -7, "un pulsante rosso");
	oggetti[++fo] = oggetto(61, -7, "un pulsante verde");
	oggetti[++fo] = oggetto(66, -8, "un indicatore");
	oggetti[++fo] = oggetto(65, -8, "una leva");
	oggetti[++fo] = oggetto(61, -8, "un pulsante rosso");
	oggetti[++fo] = oggetto(61, -8, "un pulsante verde");
	oggetti[++fo] = oggetto(60, -8, "un cartello rosso");
	oggetti[++fo] = oggetto(61, -8, "un pulsante giallo");
	oggetti[++fo] = oggetto(53, 9, "il secondo pilota");
	oggetti[++fo] = oggetto(69, -9, "un'antenna parabolica");
	oggetti[++fo] = oggetto(52, -99, "un camice");
	oggetti[++fo] = oggetto(54, -99, "una chiave");
	oggetti[++fo] = oggetto(55, -99, "un manuale");
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
			cout << "\nSei " << luoghi[lu].get_descrizione().c_str() << ".\n\n";
			l = lu;
			pStringa = "Vedo ";
			elenca();
			tempo();
			printf("\n\n");
			do
			{
				inStringa[0] = '\0';
				printf("Cosa devo fare ? ");
				getline(cin, inStringa);
			} while (inStringa[0] == '\0');
			printf("\n");
			li = inStringa.size();
			in = 0;
			estrai();
			p1Stringa = pStringa;
			c1 = c;
			if (p1Stringa == "")
				printf("- Beh?\n");
			else if (in > 1 && p1Stringa.substr(in - 2, 2) == "re")
				printf("- Dammi del tu, per favore.\n");
			else if (c1 == 0 && p1Stringa[0] != '\0')
				cout << "- Non conosco il verbo '" << p1Stringa << "'.\n";
			else
			{
				estrai();
				p2Stringa = pStringa;
				c2 = c;
				if (c2 == 0 && p2Stringa[0] != '\0')
					cout << "- Non conosco la parola '" << p2Stringa << "'.\n";
				else
				{
					if (c2 != 0)
						luogo_oggetto();
					n1 = lu * 10000;
					n2 = c1 * 100;
					a = n1 + n2 + c2;
					esegui_azione();
					if (a == 0 && c2 != 0)
					{
						a = n1 + n2 + 99;
						esegui_azione();
					}
					if (a == 0)
					{
						a = n2 + c2;
						esegui_azione();
					}
					if (a == 0 && c2 != 0)
					{
						a = n2 + 99;
						esegui_azione();
					}
					if (a == 0)
						printf("- Non capisco.\n");
				}
			}
		} while (!fine_partita);
	} while (riparti);
}

int gioco::cerca_parola()
{
	int i = 1;
	int f = fd;
	int to_return = 0;

	do 
	{
		int a = (i + f) / 2;
		aStringa = dzStringa[a];

		if (pStringa == aStringa)
			to_return = dz[a];
		else if (pStringa > aStringa)
			i = a + 1;
		else
			f = a - 1;

	} while (i <= f && to_return == 0);

	return to_return;
}

void gioco::estrai()
{
	do
	{
		c = 0;
		while (inStringa[in] == ' ' || inStringa[in] == '\'')
			in++;
		if (in >= li)
			pStringa = "";
		else
		{
			a = in;
			while (inStringa[in] != ' ' && inStringa[in] != '\'' && in < li)
				in++;

			pStringa = inStringa.substr(a, in - a);
			c = cerca_parola();
		}
	} while (c == 7);
	return;
}

void gioco::cerca_azione()
{
	i = 1;
	f = fa;
	n = a;

	do {
		a = (i + f) / 2;
		m = ca[a];
		if (n == m) {
			a = az[a];
			return;
		}
		else if (n > m)
			i = a + 1;
		else
			f = a - 1;
	} while (i <= f);
	a = 0;
}

void gioco::elenca()
{
	for (i = 1; i <= fo; i++) {
		if (abs(oggetti[i].get_luogo()) == l)
			cout << pStringa << oggetti[i].get_nome() << endl;
	}
	return;
}

void gioco::luogo_oggetto()
{
	og = 0;
	for (i = 1; i <= fo; i++) {
		if (oggetti[i].get_codice() == c2)
			if (abs(oggetti[i].get_luogo()) == lu || oggetti[i].get_luogo() == 0) {
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
	do
	{
		printf("Vuoi giocare ancora ? ");
		cin >> aStringa;
	} while (aStringa[0] != 's' && aStringa[0] != 'n');

	if (aStringa[0] == 's')
		riparti = true;
	else
	{
		printf("\n\nCiao!\n\n");
		riparti = false;
	}
}

void gioco::tempo()
{
	t1--;
	if (t1 <= 10)
		printf("Sento un segnale di allarme.\n");
	if (t1 <= 5)
		printf("La temperatura e' insopportabile.\n");
	if (t1 <= 2)
		printf("La nave e' scossa da vibrazioni.\n");
	if (t1 == 0) {
		printf("\n*** Troppo tardi! ***\n\n");
		printf("Il reattore e' fuori controllo.\n");
		printf("L'astronave e' disintegrata in minuscoli frammenti\n");
		printf("E' incredibile il silenzio delle esplosioni nel vuoto.\n");
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
	t1 = 100;
	lu = 6;
	v1 = 0;
	v2 = 0;
	printf("\n");
	return;
}

void gioco::comune()
{
	v1 = 0;
	t1 = t1 / 2;
	return;
}

void gioco::direzioni()
{
	a = stoi(luoghi[lu].get_direzioni().substr(2 * c1 - 2, 2));
	if (a == 0)
		printf("- Di li' non puoi andare\n");
	else
		lu = a;
	return;
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
	else if (lu < 9) {
		oggetti[og].set_luogo(lu);
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
	file = fopen(fStringa.c_str(), "w");
	for (i = 1; i <= fo; i++)
		fprintf(file, "%d\n", oggetti[i].get_luogo());
	fprintf(file, "%d\n", lu);
	fprintf(file, "%d\n", t1);
	fprintf(file, "%d\n", v1);
	fprintf(file, "%d\n", v2);
	fclose(file);
	return;
}

void gioco::load()
{
	file = fopen(fStringa.c_str(), "r");
	int l;
	for (i = 1; i <= fo; i++)
		fscanf(file, "%d", &l), oggetti[i].set_luogo(l);
	fscanf(file, "%d", &lu);
	fscanf(file, "%d", &t1);
	fscanf(file, "%d", &v1);
	fscanf(file, "%d", &v2);
	fclose(file);
	return;
}

void gioco::cosa()
{
	printf("Possiedi:\n");
	l = 0;
	pStringa = "- ";
	elenca();
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
	else if (!(lu == 9) || (lu == 7 && v2 == 1))
		lascia();
	else {
		printf("L'aria! L'aria! Aaaagh!!!\n");
		morto();
	}
	return;
}

void gioco::azione_11()
{
	printf("E' la tuta per la tua attivita'\n");
	printf("extraveicolare.\n");
	return;
}

void gioco::azione_12()
{
	printf("E' privo di conoscenza ed ha\n");
	printf("un'ammaccatura nel casco.\n");
	printf("Probabilmente e' stato colpito\n");
	printf("da un piccolo meteorite mentre\n");
	printf("riparava l'antenna. Per\n");
	printf("fortuna, e' ancora vivo.\n");
	return;
}

void gioco::azione_13()
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

void gioco::azione_15()
{
	if (oggetti[og].get_luogo() == lu)
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
	printf("Segna %d gradi e sta\n", 840 - t1 * 4);
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
	lu = 1;
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
		oggetti[24].set_luogo(lu);
		oggetti[22].set_luogo(lu);
	}
	return;
}

void gioco::azione_24()
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
			for (i = 1; i <= fo; i++) {
				if (oggetti[i].get_luogo() == lu) {
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
			oggetti[23].set_luogo(lu);
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

void gioco::azione_34()
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
		lu = 4;
	else
		direzioni();
	return;
}

void gioco::azione_38()
{
	if (v2 == 1)
		lu = 11;
	else
		direzioni();
	return;
}

void gioco::esci()
{
	fine_partita = true;
	riparti = false;
}

void gioco::esegui()
{
	switch (a) 
	{
	case 0:
		esci();
		break;
	case 1:
		direzioni();
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
		azione_11();
		break;
	case 12:
		azione_12();
		break;
	case 13:
		azione_13();
		break;
	case 14:
		azione_14();
		break;
	case 15:
		azione_15();
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
		azione_24();
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
		azione_34();
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
	default:
		printf("AZIONE %d", a);
	}
}

void gioco::esegui_azione()
{
	cerca_azione();
	if (a != 0) 
	{
		if (c2 == 0 || a > 0)
			esegui();
		else 
		{
			a = -a;
			if (og == 0)
				printf("- Qui non c'e'.\n");
			else
				esegui();
		}
		a = 1;
	}
	return;
}
