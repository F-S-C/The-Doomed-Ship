#include "luogo.h"

using namespace std;

luogo::luogo()
{
    descrizione = "";
    direzioni = "000000000000";
}

luogo::luogo(const string &pDesc, const string &pDir)
{
    descrizione = pDesc;
    direzioni = pDir;
}

void luogo::set_descrizione(const string &pDesc)
{
    descrizione = pDesc;
}

string luogo::get_descrizione() const
{
    return descrizione;
}

void luogo::set_direzioni(const string &pDir)
{
    direzioni = pDir;
}

string luogo::get_direzioni() const
{
    return direzioni;
}