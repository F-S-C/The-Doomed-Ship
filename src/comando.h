#pragma once

#include <string>

class comando
{
public:
	comando();
	comando(const std::string&, unsigned);

	void set_parola(const std::string&);
	std::string get_parola() const;

	void set_codice(unsigned);
	unsigned get_codice() const;
private:
	std::string parola;
	unsigned codice;
};

