#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Libreria.h"

int menu(){ // bien!
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    system("cls");
    printf("-------------------------------------------------------------------------------------------");
    printf("\n\t\t>>> Registro de Personas <<<\n\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("*** Menu de opciones ***\n\n");
    printf("  1- Alta\n");
    printf("  2- Modificar\n");
    printf("  3- Baja\n");
    printf("  4- Listado\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("  5- Salir\n\n");
    *control = getInt(&opcion, "Ingrese opcion: ", "Error, ingrese una opcion de la lista: ", 1, 5, 3);
    if(*control == -1){
        opcion = 0;
    }
    free(control);
    return opcion;
}

int getInt(int *x, char* ing, char* err, int inf, int sup, int chances){
    int* control = (int*) malloc(sizeof(int));
    int bandera = 0;
    int* aux = (int*) malloc(sizeof(int));

    printf("%s", ing);
    *control = scanf("%d", aux);
    chances--;
    while((*control != 1 || *aux < inf || *aux > sup) && chances>=1){
        printf("%s", err);
        fflush(stdin);
        *control = scanf("%d", aux);
        chances--;
    }
    if(*control == 1){
        bandera = 1;
        *x = *aux;
    }
    free(control);
    free(aux);
    return bandera; // si (bandera == 0) no obtuvo el entero.
}

int getCharResp(char *letra, char* ing, char* err, int chances){
    int* control = (int*) malloc(sizeof(int));
    int bandera = 0;
    char* auxChar = (char*) malloc(sizeof(char));

    printf("%s", ing);
    fflush(stdin);
    scanf("%c", auxChar);
    *control = isValidAnswer(auxChar);
    chances--;
    while(!(*control == 1) && chances >= 1){
        printf("%s", err);
        fflush(stdin);
        scanf("%c", auxChar);
        *control = isValidAnswer(auxChar);
        chances--;
    }
    if(*control == 1){
        bandera = 1;
        *letra = *auxChar;
    }
    free(control);
    free(auxChar);
    return bandera; // si (bandera == 0) no obtuvo el caracter.
}

int isValidAnswer(char* answer){
    int validar = 1;
    if (!(*answer == 's' || *answer == 'n' || *answer == 'S' || *answer == 'N')){
        validar = 0;
    }
    return validar;
}

int isValidName(char* pBuffer, int limit){
    int retorno = 0;
    int* i = (int*) malloc(sizeof(int));;
    if(pBuffer != NULL && limit > 0){
        retorno = 1;
        for(*i = 0; *i < limit && pBuffer[*i] != '\0'; (*i)++){
            if(tolower(pBuffer[*i]) < 'a' || tolower(pBuffer[*i] > 'z')){
                retorno = 0;
                break;
            }
        }
    }
    free(i);
    return retorno;
}

int getString(char* pbuffer, int limite){
    int retorno = 0;
    char bufferStr[30];
    int* len = (int*) malloc(sizeof(int));
    if(pbuffer != NULL && limite > 0){
        fflush(stdin);
        fgets(bufferStr, limite, stdin);
        *len = strlen(bufferStr);
        if(*len != limite-1 || bufferStr[limite-2] == '\n'){
            bufferStr[(*len)-1] = '\0';
        }
        retorno = 1;
        strncpy(pbuffer, bufferStr, limite);
    }
    free(len);
    return retorno;
}

int getName(char* pName, char* msg, char* msgError, int limit, int chanches){
    int retorno = 0;
    char bufferName[30];
    if(pName != NULL && limit > 0 && msg != NULL && msgError != NULL && chanches >= 0){
        do{
            chanches--;
            printf("%s", msg);
            if(getString(bufferName, limit) == 1 && isValidName(bufferName, limit)){
                strncpy(pName, bufferName, limit);
                retorno = 1;
                break;
            }else{
                printf("%s", msgError);
            }
        }while(chanches >= 0);
    }
    return retorno;
}

FILE* readBinaryFile(char* nombre, char* modo)
{
    FILE* pArch = NULL;
    if((pArch = fopen(nombre, modo)) == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
    fclose(pArch);
    return pArch;
}

FILE* readTextFile(char* nombre, char* modo)
{
    FILE* pArch = NULL;
    if((pArch = fopen(nombre, modo)) == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
    fclose(pArch);
    return pArch;
}

FILE* binFileImpl(char* nombre, char* modo)
{
    FILE* pArch = NULL;
    //Se abre en modo lectura
    if((pArch = fopen(nombre, "rb")) == NULL)
    {
        //Si el modo anterior dio error el archivo
        if((pArch = fopen(nombre, modo)) == NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        //no existe, por lo tanto se crea
        fclose(pArch);
    }
    return pArch;
}

FILE* textFileImpl(char* nombre, char* modo)
{
    FILE* pArch = NULL;
    //Se abre en modo lectura
    if((pArch = fopen(nombre, "r")) == NULL)
    {
        //Si el modo anterior dio error el archivo
        if((pArch = fopen(nombre, modo)) == NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        //no existe, por lo tanto se crea
        fclose(pArch);
    }
    return pArch;
}
