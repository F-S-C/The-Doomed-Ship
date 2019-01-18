#pragma once

#include <string>

class luogo
{
public:
    luogo();
    luogo(const std::string&, const std::string&);

    void set_descrizione(const std::string&);
    std::string get_descrizione() const;

    void set_direzioni(const std::string&);
    std::string get_direzioni() const;
private:
    std::string descrizione;
    std::string direzioni;
};