#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Libreria.h"

int* addBinPerson(char* nombre, char* modo)
{
    int* flag = (int*) malloc(sizeof(int));
    sPerson* auxPerson = (sPerson*) malloc(sizeof(sPerson));
    FILE* pArch = binFileImpl(nombre, modo);
    *flag = 0;
    if(auxPerson != NULL && pArch != NULL)
    {
        if(getName(auxPerson->name, "\nIngrese nombre: ", "Error, ingrese solo letras respetando el limite(20): ", 20, 3))
        {
            if(getInt(&auxPerson->age, "\nIngrese edad: ", "Error, ingrese solo numeros respetando el limite(110): ", 0, 110, 3))
            {
                auxPerson->isEmpty = 0;
                if(fwrite(auxPerson, sizeof(auxPerson), 1, pArch))
                {
                    *flag = 1;
                    printf("\nRegistro exitoso.");
                }
                else
                {
                    printf("\nError al cargar registro.");
                }
            }
        }
    }
    fclose(pArch);
    free(auxPerson);
    return flag;
}

int* addTxtPerson(char* nombre, char* modo)
{
    int* flag = (int*) malloc(sizeof(int));
    sPerson* auxPerson = (sPerson*) malloc(sizeof(sPerson));
    FILE* pArch = textFileImpl(nombre, modo);
    *flag = 0;
    if(auxPerson != NULL && pArch != NULL)
    {
        if(getName(auxPerson->name, "\nIngrese nombre: ", "Error, ingrese solo letras respetando el limite(20): ", 20, 3))
        {
            if(getInt(&auxPerson->age, "\nIngrese edad: ", "Error, ingrese solo numeros respetando el limite(110): ", 0, 110, 3))
            {
                auxPerson->isEmpty = 0;
                if(fwrite(auxPerson, sizeof(auxPerson), 1, pArch))
                {
                    *flag = 1;
                    printf("\nRegistro exitoso.");
                }
                else
                {
                    printf("\nError al cargar registro.");
                }
            }
        }
    }
    fclose(pArch);
    free(auxPerson);
    return flag;
}
