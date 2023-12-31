#include "INIconfig.h"

std::string getConfigValue(std::string path, std::string section, std::string value)
{
    std::ifstream stream(path);

    std::string line;
    const int section_len = section.length();
    const int value_len = value.length();

    char section_buff[section_len];
    char value_buff[value_len];

    while (1)
    {
        if (std::getline(stream, line, '['))
        {
            stream.read(section_buff, section_len);
            if (memcmp(section_buff, section.data(), section_len) == 0)
            {
                if (!std::getline(stream, line, ']'))
                    break;

                std::getline(stream, line, '[');

                // очистка пробелов и табуляторов перед параметрами
                while (1)
                {
                    auto value_bpos = line.find("\n ");
                    auto value_tpos = line.find("\n\t");
                    if (value_bpos == std::string::npos && value_tpos == std::string::npos)
                        break;

                    if (value_bpos != std::string::npos)
                        line.erase(value_bpos + 1, 1);
                    if (value_tpos != std::string::npos)
                        line.erase(value_tpos + 1, 1);
                }
                auto value_pos = line.find("\n" + value) + 1;
                if (value_pos == std::string::npos)
                    break;
                line.erase(0, value_len + value_pos);

                for (int i{0}; i < line.length(); i++)
                {
                    if (line[i] == '=' || line[i] == ' ')
                    {
                        line.erase(0, 1);
                    }
                    else
                    {
                        break;
                    }
                }

                char deleted[5]{';', '#', '\n', '\r', '\t'};
                for (int i{0}; i < 5; i++)
                {
                    value_pos = line.find(deleted[i]);
                    if (value_pos != std::string::npos)
                        line.erase(value_pos, line.length() - value_pos);
                }
                stream.close();
                return line;
            }
            else
            {
                continue;
            }
        }
        else
        {
            break;
        }
    }
    stream.close();
    return std::string();
}
