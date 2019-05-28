#include <stdio.h>
#include <stdlib.h>
#include "Libreria.h"
#include "Person.h"

#define BIN	".\\Data.bin"
#define TXT	".\\Data.txt"

int main()
{
    FILE* pBinArch;
    char* answer = (char*) malloc(sizeof(char));

    do
    {
        pBinArch = readFile(BIN, "rb", 1);
        switch(menu())
        {
            case 1: addBinPerson(BIN, "wb");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }

    }while(*answer != 'n');

    free(answer);
    fclose(pBinArch);
    return 0;
}
