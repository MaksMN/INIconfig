#pragma once

#include <string>
#include <cstring>
#include <fstream>

std::string getConfigValue(std::string path, std::string section, std::string value);

/*

формат конфиг файла

|    ; некоторый комментарий
|    # комментарий в стиле Unix
|
|    [Section1]
|    ; комментарий о разделе
|    var1=значение_1 ; иногда допускается комментарий к отдельному параметру
|    var2=значение_2
|
|    [Section2]
|    var1=значение_1
|    var2=значение_2

другие форматы ini файла не поддерживаются.

*/