//leandro_say

#include <Windows.h>
#include <iostream>


#include <conio.h>

#include "WinConsole.h"
#include "Param.h"
#include "Wtf.h"



int main(int argc, char** argv) {


    Param param{ argc, argv };


    if (param.mode)
    {
        Wtf* pApp = new Wtf(param.path());

        if ('f' == param.mode)
            pApp->find(param.pattern(), true);
        else
            pApp->read();

        delete pApp;
    }
    else
        Wtf::help();

    return 0;
}

