#include "comando.h"



comando::comando()
{
	parola = "";
	codice = 0;
}

comando::comando(const std::string &pParola, unsigned pCodice)
{
	parola = pParola;
	codice = pCodice;
}

void comando::set_parola(const std::string &pParola)
{
	parola = pParola;
}

std::string comando::get_parola() const
{
	return parola;
}

void comando::set_codice(unsigned pCodice)
{
	codice = pCodice;
}

unsigned comando::get_codice() const
{
	return codice;
}
