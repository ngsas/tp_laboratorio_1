/** \brief =Suma de dos numeros
 *
 * \param primerNumero float=primer numero a ser sumado
 * \param segundoNumero float=segundo numero a ser sumado
 * \param float*resultado=resultado pasado por referencia
 * \return float=0 esta todo bien -1 overflow
 *
 */
float suma( float primerNumero, float segundoNumero,float*resultado)
{
    int retorno=-1;
    double suma=0;
    suma=primerNumero+segundoNumero;
    if(suma>-3.4E38 && suma<3.4E38)
    {
        retorno=0;
        *resultado=suma;
    }
    return retorno;
}
/** \brief =Resta de dos numeros
 *
 * \param primerNumero float=primer numero a ser restado
 * \param segundoNumero float=segundo numero a ser restado
 * \param float*resultado=resultado pasado por referencia
 * \return float=0 esta todo bien -1 overflow
 *
 */
float resta( float primerNumero, float segundoNumero,float*resultado)
{
    int retorno=-1;
    double resta=0;
    resta=primerNumero-segundoNumero;
    if(resta>-3.4E38 && resta<3.4E38)
    {
        retorno=0;
        *resultado=resta;
    }
    return retorno;
}
/** \brief =Division de dos numeros
 *
 * \param primerNumero float=primer numero a ser dividendo
 * \param segundoNumero float=el segundo numero es el divisor
 * \param float*resultado=resultado pasado por referencia
 * \return float=0 esta todo bien, -1 overflow, -2 si el segundo numero es 0
 *
 */
float division(float primerNumero, float segundoNumero, float*resultado)
{
    int retorno=-1;
    double division=0;
    division=primerNumero/segundoNumero;
    if(segundoNumero==0)
    {
        retorno=-2;
    }
    else if(division>-3.4E38 && division<3.4E38)
    {
        retorno=0;
        *resultado=division;
    }
    return retorno;
}
/** \brief =multiplicacion de dos numeros
 *
 * \param primerNumero float=primer numero a ser multiplicado
 * \param segundoNumero float=segundo numero a ser multiplicado
 * \param float*resultado=resultado pasado por referencia
 * \return float=0 esta todo bien -1 overflow
 *
 */
float multiplicacion(float primerNumero, float segundoNumero, float*resultado)
{
    int retorno=-1;
    double multiplicacion=0;
    multiplicacion=primerNumero*segundoNumero;
    if(multiplicacion>-3.4E38 && multiplicacion<3.4E38)
    {
        retorno=0;
        *resultado=multiplicacion;
    }
    return retorno;
}
/** \brief =factorial del primer numero
 *
 * \param primerNumero float=primer numero a ser sumado
 * \param float*resultado=resultado pasado por referencia
 * \return float=0 esta todo bien ,-1 overflow,-2 el numero es negativo,-3 el numero es decimal
 *
 */
float factorial(float primerNumero,float*resultado)
{
    int retorno=-1;
    int factorial=1;
    int parteEntera=(int) primerNumero;
    int contador;
    if(primerNumero>=0 && primerNumero<3.4E38 && (primerNumero-parteEntera)==0)
    {
        retorno=0;
        for(contador=1;contador<=parteEntera;contador++)
        {
            factorial=factorial*contador;
            *resultado=factorial;
        }
    }
    else if(parteEntera<0)
    {
        retorno=-2;
    }
    else if((primerNumero-parteEntera)>0)
    {
        retorno=-3;
    }
    else if(*resultado>=3.4E38)
    {
        retorno=-1;
    }
    return retorno;
}


