#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

#endif // LIBRERIA_H_INCLUDED

/** \brief
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return
 */
int getInt(int *x, char* ing, char* err, int inf, int sup, int chances);

/** \brief
 * \return
 */
int menu();

/** \brief
 * \param
 * \param
 * \param
 * \param
 * \return
 */
int getCharResp(char *letra, char* ing, char* err, int chances);

/** \brief
 * \param
 * \return
 */
int isValidAnswer(char* answer);

/** \brief
 * \param
 * \param
 * \return
 */
int isValidName(char* pBuffer, int limit);

/** \brief
 * \param
 * \param
 * \return
 */
int getString(char* pbuffer, int limite);

/** \brief
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return
 */
int getName(char* pName, char* msg, char* msgError, int limite, int chanches);

/** \brief
 * \param
 */
void menuService(int* option);

/** \brief
 * \param
 * \param
 * \return
 */
FILE* readBinaryFile(char* nombre, char* modo);

/** \brief
 * \param
 * \param
 * \return
 */
FILE* readTextFile(char* nombre, char* modo);

/** \brief
 * \param
 * \param
 * \return
 */
FILE* binFileImpl(char* nombre, char* modo);

/** \brief
 * \param
 * \param
 * \return
 */
FILE* textFileImpl(char* nombre, char* modo);
