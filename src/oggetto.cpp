#include "oggetto.h"

using namespace std;

oggetto::oggetto()
{
    codice = 0;
    luogo = -99;
    nome = "";
}

oggetto::oggetto(unsigned pCodice, int pLuogo, const string& pNome)
{
    codice = pCodice;
    luogo = pLuogo;
    nome = pNome;
}

void oggetto::set_codice(unsigned pCodice)
{
    codice = pCodice;
}

unsigned oggetto::get_codice() const
{
    return codice;
}

void oggetto::set_luogo(int pLuogo)
{
    luogo = pLuogo;
}

int oggetto::get_luogo() const
{
    return luogo;
}

void oggetto::set_nome(const std::string& pNome)
{
    nome = pNome;
}

std::string oggetto::get_nome() const
{
    return nome;
}