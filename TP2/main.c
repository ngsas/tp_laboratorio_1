#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"
#include "utn.h"
#define QTY 20

int main()
{
    Persona array[QTY];
    int menu;
    int orden;
    int auxiliarId;

    persona_init(array,QTY);
    do
    {
        getValidInt("\n1.Dar de alta\n2.Dar de baja\n3.Ordenar\n4.Mostrar grafico de edades\n5.Salir\nIngrese una opcion: ","\nOpcion no valida\n",&menu,1,5,4);
        switch(menu)
        {
            case 1:
                persona_alta(array,QTY);
                break;
            case 2:
                persona_mostrar(array,QTY);
                getValidInt("\nIngrese el ID: ","\nID no valido\n",&auxiliarId,0,200,2);
                persona_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("\nIngrese 0 para ordenar de A - Z / 1 para ordenar de Z - A: ","\nOpcion no valida\n",&orden,0,1,4);
                if(orden==0)
                {
                    persona_ordenar(array,QTY,orden);
                    persona_mostrar(array,QTY);
                }
                else if(orden==1)
                {
                    persona_ordenar(array,QTY,orden);
                    persona_mostrar(array,QTY);
                }
                break;
            case 4:
                mostrar_grafico(array,QTY);
                break;
        }
    }while(menu != 5);

    return 0;
}
