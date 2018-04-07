#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float primerNumero=0;
    float segundoNumero=0;
    float resultado;
    while(seguir=='s')
    {
        printf("\nMenu de opciones\n");
        printf("1- Ingresar 1er operando (A=%f)\n",primerNumero);
        printf("2- Ingresar 2do operando (B=%f)\n",segundoNumero);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nIngresar primer numero: ");
                scanf("%f",&primerNumero);
                break;
            case 2:
                printf("\nIngrese segundo numero: ");
                scanf("%f",&segundoNumero);
                break;
            case 3:
                if(suma(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la suma es:%f",resultado);
                }
                else
                {
                    printf("Fuera de rango");
                }
                break;
            case 4:
                if(resta(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la resta es:%f",resultado);
                }
                else
                {
                    printf("Fuera de rango");
                }
                break;
            case 5:
                if(division(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la division es:%f",resultado);
                }
                else if(division(primerNumero,segundoNumero,&resultado)==-2)
                {
                    printf("No se puede dividir en 0\n");
                }
                else
                {
                    printf("Fuera de rango");
                }
                break;
            case 6:
                if(multiplicacion(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\n El resultado de la multiplicacion es:%f",resultado);
                }
                else
                {
                    printf("Fuera de rango");
                }
                break;
            case 7:
                if(factorial(primerNumero,&resultado)==0)
                {
                    printf("\nEl factorial de %.4f es:%f",primerNumero,resultado);
                }
                else if(factorial(primerNumero,&resultado)==-2)
                {
                    printf("\nEl numero ingresado es negativo\n");
                }
                else if(factorial(primerNumero,&resultado)==-3)
                {
                    printf("\nEl numero ingresado es decimal\n");
                }
                else if(factorial(primerNumero,&resultado)==-1)
                {
                    printf("\nFuera de rango");
                }
                break;
            case 8:
                if(suma(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la suma es:%f",resultado);
                }
                else
                {
                    printf("\nFuera de rango");
                }

                if(resta(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la resta es:%f",resultado);;
                }
                else
                {
                    printf("\nFuera de rango");
                }

                if(division(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la division es:%f",resultado);
                }
                else if(division(primerNumero,segundoNumero,&resultado)==-2)
                {
                    printf("\nNo se puede dividir en 0\n");
                }
                else
                {
                    printf("\nFuera de rango");
                }

                if(multiplicacion(primerNumero,segundoNumero,&resultado)==0)
                {
                    printf("\nEl resultado de la multiplicacion es:%f",resultado);
                }
                else
                {
                    printf("\nFuera de rango");
                }

                if(factorial(primerNumero,&resultado)==0)
                {
                    printf("\nEl factorial de %.4f es:%f",primerNumero,resultado);
                }
                else if(factorial(primerNumero,&resultado)==-2)
                {
                    printf("\nEl numero ingresado es negativo\n");
                }
                else if(factorial(primerNumero,&resultado)==-3)
                {
                    printf("\nEl numero ingresado es decimal\n");
                }
                else if(factorial(primerNumero,&resultado)==-1)
                {
                    printf("\nFuera de rango");
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
