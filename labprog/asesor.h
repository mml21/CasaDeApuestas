/* MODULO ASESOR DE APUESTAS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion del modulo asesor */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include "macros.h"
#include "escape.h"

EXEC SQL INCLUDE gestion_eventos;


void listar_eventos_por_perfil (perfilUsuario perfil, lista_dinamica *l);
/* Pre: perfil es un perfil valido de algun usuario de la Casa de Apuestas. 
   Post: Selecciona los resultados de los eventos a los que se recomienda
         apostar en funcion del perfil del usuario y los almacena en la lista l.  
*/
