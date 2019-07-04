#include "cryptography.h"

#include <algorithm>

std::string &cryptography::decrypt(std::string &str, int key)
{
    std::transform(str.begin(), str.end(), str.begin(), [key](unsigned char c) { return c -= key; });
    return str;
}

std::string &cryptography::encrypt(std::string &str, int key)
{
    std::transform(str.begin(), str.end(), str.begin(), [key](unsigned char c) { return c += key; });
    return str;
}