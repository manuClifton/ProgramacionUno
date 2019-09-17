

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param messageError Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \param attempts Limite de errores
 * \return Si obtuvo el numero [0] si no [-1]
 */
int getIntRange(int* number, char* message,char* messageError,int lowLimit, int hiLimit, int attempts);

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param messageError Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \param attempts Limite de errores
 * \return Si obtuvo el numero [0] si no [-1]
 */
int getFloat(float* number, char* message,char* messageError,float lowLimit, float hiLimit, int attempts);

/**
 * \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param messageError Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \param attempts Limite de errores
 * \return Si obtuvo el caracter [0] si no [-1]
 */
int getChar(char* input,char* message,char* messageError, char lowLimit, char hiLimit, int attempts);



/**
 * \brief Solicita una cadena de caracteres al usuario y la valida
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a ser mostrado
 * \param messageError Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mínima de la cadena
 * \param hiLimit Longitud máxima de la cadena
 * \param attempts Limite de errores
 * \return Si obtuvo la cadena [0] si no [-1]
 */
int getString(char* strig,char message[],char messageError[], int lowLimit, int hiLimit, int attempts);



typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
/**
 * \brief  Compara 2 fechas resividas como parametros
 * \param  tipo de dato estructura de eFecha
 * \param  tipo de dato estructura de eFecha
 * \return [-1] si fecha1 < fecha2, [0] si fecha1 = fecha2, [1] si fecha1 > fecha2
 */
int comparaFecha(eFecha f1, eFecha f2);





