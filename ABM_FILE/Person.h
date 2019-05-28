#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

typedef struct{
    char name[21];
    int age;
    int isEmpty;
}sPerson;

#endif // PERSON_H_INCLUDED

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
FILE* readFile(char* nombre, char* modo, int tam);

/** \brief
 * \param
 * \param
 * \return
 */
int* addBinPerson(char* nombre, char* modo);

/** \brief
 * \param
 * \param
 * \return
 */
int* addTxtPerson(char* nombre, char* modo);
