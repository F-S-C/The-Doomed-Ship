#pragma once

#include <string>

class azione
{
public:
	azione();
	azione(int pCodiceAzione, int pAzione);

	void set_codice(int pCodiceAzione);
	int get_codice() const;

	void set_azione(int pAzione);
	int get_azione() const;
private:
	int codiceAzione;
	int numeroAzione;
};

