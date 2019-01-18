#include "azione.h"



azione::azione()
{
	numeroAzione = 0;
	codiceAzione = 0;
}

azione::azione(int pCodiceAzione, int pAzione)
{
	numeroAzione = pAzione;
	codiceAzione = pCodiceAzione;
}

void azione::set_codice(int pCodiceAzione)
{
	codiceAzione = pCodiceAzione;
}

int azione::get_codice() const
{
	return codiceAzione;
}

void azione::set_azione(int pAzione)
{
	numeroAzione = pAzione;
}

int azione::get_azione() const
{
	return numeroAzione;
}
