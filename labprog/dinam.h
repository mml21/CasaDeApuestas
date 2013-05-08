/* MODULO DE LISTAS DINAMICAS GENERICAS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion de listas dinamicas y sus
                operaciones mas comunes. */

#include <stdio.h>


/* Estructuras de datos para las listas */

struct nodo
{
    char *nodo; /* Dato efectivo */
    struct nodo *siguiente; /* Puntero a siguiente nodo */
};


typedef struct
{
  struct nodo *primero; /* Puntero a primer nodo */
  int num_datos;        /* Numero de datos de la lista */
  int tamano_dato;      /* Cuanto ocupa cada dato */
} lista_dinamica;


/* Operaciones con listas */


void nueva_lista_dinam (lista_dinamica *l, int tamano);
/* Pre: tamano > 0
   Post: crea una nueva lista cuyos elementos seran del tamaño que se 
   especifica al crearla */
   
   
int agregar (lista_dinamica *l, char *dato);
/* Pre: tamaño de dato = l -> tamano_dato
   Post: agrega el elemento al que apunta dato a la lista */
   

int agregar_al_final (lista_dinamica *l, char *dato);
/* Pre: tamaño de dato = l -> tamano_dato
   Post: agrega el elemento al que apunta dato al final de la lista */


int buscar (lista_dinamica *l, char *dato);
/* Post: si el dato al que apunta el parametro dato esta contenido
         en la lista devuelve 1. Devuelve 0 en caso contrario */
	 

int eliminar (lista_dinamica *l, char *dato) ;
/* Post: elimina el dato al que apunta el parametro dato, en caso de
         que lo borre devolvera 1. Devuelve 0 en caso contrario */
   

int numdatos (lista_dinamica l);
/* Pre: l es una lista inicializada
   Post: devuelve el numero de datos de la lista */	


int dato_posicion (lista_dinamica *l, int posicion, char * dato);
/* Post: almacena en la posicion de memoria apuntada por el parametro
         dato el dato que ocupa la posicion que se indica en el parametro
	 posicion de la lista. Si se ha podido realizar devuelve 1.
	 Devuelve 0 en caso contrario.
	 Cuidado con esta funcion, tras las inserciones y borrados
	 los datos cambian su posicion */


int primero (lista_dinamica *l, char * dato);
/* Post: guarda en la zona de memoria apuntada por el parametro dato el 
         primer dato de la lista */
	 
	 
void destruir_lista (lista_dinamica *l);
/* Post: librera la memoria dinamica que ocupa la lista */
