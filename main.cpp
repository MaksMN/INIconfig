#include <iostream>
#include "INIconfig.h"

using namespace std;
int main()
{
    auto var = getConfigValue("conf.ini", "Section2", "var1");
    return 0;
}