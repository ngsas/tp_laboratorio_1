#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"
#include "utn.h"
#define QTY 20
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Persona* array,int limite);
static int proximoId();


/** \brief Inicializa la estructura Persona
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite La cantidad de elementos a incluir en la estructura
 * \return int 0 Si esta todo OK, -1 Error
 *
 */
int persona_init(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}

/** \brief Busca una persona por ID
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \param id int El ID de la persona enviado como parametro
 * \return int -2 Si esta todo OK, -1 Error, i el ID si encontro un espacio libre
 *
 */
int persona_buscarPorId(Persona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPersona == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Da de baja una persona por ID
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \param id int El ID de la persona enviado como parametro
 * \return int 0 si encontro el ID de la persona a eliminar, -1 Error
 *
 */
int persona_baja(Persona* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = persona_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


/** \brief
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \return int 0 si esta todo OK, -1 Error
 *
 */
int persona_mostrar(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n %s - %d - %d - %s",array[i].nombre,array[i].idPersona,array[i].edad,array[i].dni);
            }
        }
    }
    return retorno;
}

/** \brief Da de alta una persona
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \return int 0 Si esta todo OK, -1 Error, -2 Si el limite no es negativo y el array contiene elementos, -3 si encontro un espacio libre
 *
 */
int persona_alta(Persona* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    char dni[20];
    int edad;
    int id;
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("\nNombre:","Error","Overflow", nombre,50,2))
            {
                if(!getValidInt("\nEdad: ","Error",&edad,1, 150,2))
                {
                    if((getStringNumeros("\nDNI: ", dni)==1))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].dni,dni);
                        array[indice].idPersona = id;
                        array[indice].edad = edad;
                        array[indice].isEmpty = OCUPADO;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \return int i si encontro un lugar libre devuelve el indice, -1 Error, -2 Si el limite no es negativo y el array contiene elementos
 *
 */
static int buscarLugarLibre(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Incrementa el ID por una unica vezs
 *
 * \return int ultimoID el ID incrementado una vez
 *
 */
static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}


/** \brief Ordena las personas de la estructura por nombre
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \param orden int 0 para ordenar los nombres de la A - Z, 1 para ordenar los nombres de la Z - A
 * \return int 0 Si el limite no es negativo y el array contiene elementos, -1 Error
 *
 */
int persona_ordenar(Persona* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Persona auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO)
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden))
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

/** \brief Muestra un grafico con la cantidad de personas u sus diferentes edades
 *
 * \param array Persona* La estructura enviada como parametro
 * \param limite int La cantidad de elementos a incluir en la estructura
 * \return int 0 si esta todo OK, -1 Error, -2 Si el limite no es negativo y el array contiene elementos
 *
 */
int mostrar_grafico(Persona *array, int limite)
{
    int i;
    int retorno=-1;

    if(limite > 0 && array != NULL)
    {
        retorno=-2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                retorno=0;
                if(array[i].edad<=18)
                {
                    printf("\n      *      ");
                }
                if(array[i].edad>18 && array[i].edad<=35)
                {
                    printf("\n                     *                 ");
                }
                if(array[i].edad>35)
                {
                    printf("\n                                     *      ");
                }
            }
        }
        printf("\n     <18    ///    19-35    ///    >35");
    }
    return retorno;
}








































