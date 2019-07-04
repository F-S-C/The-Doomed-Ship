#include "string_utilities.h"

#include <math.h>

#ifdef _WIN32

#include <windows.h>

#endif // _WIN32

std::list<std::string> split_string(const std::string &str, const std::string &delimiter)
{
    std::list<std::string> strings;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    strings.push_back(str.substr(prev));

    return strings;
}

std::string center_string(const std::string &str, unsigned width)
{
    std::string out;

    for (unsigned i = 0; i < floor(double(width - str.size()) / 2); i++)
        out += " ";

    out += str;

    for (unsigned i = 0; i < ceil(double(width - str.size()) / 2); i++)
        out += " ";

    return out;
}

colored_string::colored_string(const std::string &str, const PrintColors foreground, const PrintColors background)
{
    m_str = str;
#ifdef _WIN32
    m_color = std::to_string((static_cast<int>(background) << 4) | static_cast<int>(foreground));
#else
    color = "\033[4" + std::to_string(static_cast<int>(pBackground)) + ";3" + std::to_string(static_cast<int>(pForeground)) + "m";
#endif // _WIN32
}

colored_string::operator std::string() const
{
    return m_str;
}

std::ostream &operator<<(std::ostream &os, const colored_string &str)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    auto *mConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsole, mConsoleInfo);
    SetConsoleTextAttribute(hConsole, std::stoi(str.m_color));

    os << str.m_str;
    SetConsoleTextAttribute(hConsole, mConsoleInfo->wAttributes);
#else
    os << str.m_color << str.m_str << "\033[0m";
#endif // _WIN32

    return os;
}

std::string wrap_string(const std::string &str, unsigned width, const std::string &whitespace)
{
    std::string to_return;
    std::list<std::string> splitted = split_string(str, "\n");
    for (auto &source : splitted)
    {
        if (!source.empty())
        {
            std::size_t currIndex = width - 1;
            std::size_t sizeToElim;
            bool stop = false;
            while (currIndex < source.length() && !stop)
            {
                currIndex = source.find_last_of(whitespace, currIndex + 1);
                if (currIndex != std::string::npos)
                {
                    currIndex = source.find_last_not_of(whitespace, currIndex);
                    if (currIndex != std::string::npos)
                    {
                        sizeToElim = source.find_first_not_of(whitespace, currIndex + 1) - currIndex - 1;
                        source.replace(currIndex + 1, sizeToElim, "\n");
                        currIndex += (width + 1);
                    }
                    else
                        stop = true;
                }
                else
                    stop = true;
            }
            to_return += (source + "\n");
        }
        else
            to_return += "\n";
    }
    return to_return;
}