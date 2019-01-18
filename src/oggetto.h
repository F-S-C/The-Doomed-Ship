#pragma once

#include <string>

class oggetto
{
public:
    oggetto();
    oggetto(unsigned, int, const std::string&);

    void set_codice(unsigned);
    unsigned get_codice() const;

    void set_luogo(int);
    int get_luogo() const;

    void set_nome(const std::string&);
    std::string get_nome() const;
private:
    unsigned codice;
    int luogo;
    std::string nome;
};