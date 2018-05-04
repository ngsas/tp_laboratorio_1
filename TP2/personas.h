#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
typedef struct
{
    char nombre[50];
    char dni[20];
    int edad;
    int idPersona;
    int isEmpty;
}Persona;
#endif // PERSONAS_H_INCLUDED

int persona_init(Persona *array,int limite);
int persona_buscarPorId(Persona *array,int limite, int id);
int persona_baja(Persona *array,int limite, int id);
int persona_mostrar(Persona *array,int limite);
int persona_alta(Persona *array,int limite);
int persona_ordenar(Persona *array,int limite, int orden);
int mostrar_grafico(Persona *array, int limite);



