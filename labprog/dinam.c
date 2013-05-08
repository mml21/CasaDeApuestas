/* MODULO DE LISTAS DINAMICAS GENERICAS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de definicion de listas dinamicas y sus
                operaciones mas comunes. */

#include <stdio.h>
#include <stdlib.h>
#include "dinam.h"


void nueva_lista_dinam (lista_dinamica *l, int tamano)
/* Tamano es el tamano de los elementos de la lista */
{
    l -> tamano_dato = tamano;
    l -> num_datos = 0;
    l -> primero = NULL;
}


int agregar (lista_dinamica *l, char *dato)
/* Se agrega a la lista l lo apuntado por el puntero dato */
{
  struct nodo *nuevo_nodo;

  if(buscar(l,dato)) return 0;
  nuevo_nodo = (struct nodo *)malloc(sizeof(struct nodo *));
  nuevo_nodo -> nodo = (char *)malloc(l->tamano_dato);
  /* Espacio para el nuevo nodo */
  nuevo_nodo -> siguiente = l -> primero;
  memcpy(nuevo_nodo->nodo,dato,l -> tamano_dato);
  l -> primero = nuevo_nodo;
  l -> num_datos++;
}


int agregar_al_final (lista_dinamica *l, char *dato)
/* Se agrega al final de la lista l lo apuntado por el puntero dato */
{
  struct nodo *nuevo_nodo;
  int i;
  
  if ( buscar(l,dato) ) return 0;
  if ( !numdatos(*l) ) 
  {
    agregar(l, dato);
    return 1;
  }
  nuevo_nodo = l->primero;
  while ( nuevo_nodo->siguiente != NULL )
    nuevo_nodo = nuevo_nodo->siguiente;
  nuevo_nodo->siguiente = (struct nodo *)malloc(sizeof(struct nodo *));
  nuevo_nodo = nuevo_nodo->siguiente;
  nuevo_nodo->nodo = (char *)malloc(l->tamano_dato);
  /* Espacio para el nuevo nodo */
  nuevo_nodo->siguiente = NULL;
  memcpy(nuevo_nodo->nodo,dato,l -> tamano_dato);
  l->num_datos++;
}

int buscar (lista_dinamica *l, char * dato)
{
  struct nodo *aux;
  int exito = 0;
  
  aux = l -> primero;
  while (aux != NULL)
  {
    if (!memcmp(aux->nodo,dato,l->tamano_dato))
    { exito = 1;
      break;
    }
    aux = aux -> siguiente;
  }
  return exito;
}


int eliminar (lista_dinamica *l, char *dato)
{

  struct nodo *aux1, *aux2;
  int parar = 0;
  
  aux1 = l -> primero;
  
  while ((aux1 != NULL) && !parar)
  {
     if (!memcmp(aux1->nodo,dato,l->tamano_dato))
     {
       if (aux1 == l->primero)
       {
         l->primero = (l -> primero) -> siguiente;
	 free(aux1->nodo);
         free(aux1);
         parar = 1;
	 l->num_datos--;
       }
       else
       {
         aux2 -> siguiente = aux1 -> siguiente;
	 free(aux1->nodo);
         free(aux1);
         parar = 1;
	 l->num_datos--;
       }
    }
    else
    {
      aux2 = aux1;
      aux1 = aux1 -> siguiente;
    }
  }
  if (parar) return 1;
  else return 0;
}


int numdatos (lista_dinamica l)
{
  return l.num_datos;
}



int dato_posicion (lista_dinamica *l, int posicion, char * dato)
{
    struct nodo *aux;
    int i;

    if (posicion > l->num_datos) return 0;

    aux = l->primero;
    for (i=2;i<=posicion;i++)
      aux = aux->siguiente;
    memcpy(dato,aux->nodo,l->tamano_dato);
}



int primero (lista_dinamica *l, char * dato)
{

  if (l->primero == NULL) return 0;
  memcpy(dato,l->primero->nodo,l->tamano_dato);	

}



void destruir_lista (lista_dinamica *l)
{
   struct nodo *aux, *aux2;
   
   aux = l->primero;
   aux2 = l->primero;
   while (aux != NULL)
   {
     aux = aux -> siguiente;
     free(aux2->nodo);
     free(aux2);
     aux2 = aux;
   }
}
