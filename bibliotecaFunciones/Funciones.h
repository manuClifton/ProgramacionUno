

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \param attempts Limite de errores
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */
int getIntRange(int* number, char* message,char* messageError,int lowLimit, int hiLimit, int attempts);

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \param attempts Limite de errores
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */
int getFloat(float* number, char* message,char* messageError,float lowLimit, float hiLimit, int attempts);

/**
 * \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \param attempts Limite de errores
 * \return Si obtuvo el caracter [0] si no [-1]
 *
 */
int getChar(char* input,char* message,char* messageError, char lowLimit, char hiLimit, int attempts);







