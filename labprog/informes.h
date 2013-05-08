/* MODULO DE INFORMES DE LA CASA DE APUESTAS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion del modulo de informes
                economicos de la Casa de Apuestas orientados a los 
                administradores. 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include "macros.h"

EXEC SQL INCLUDE promociones;


/* Orientadas al administrador */


tpInforme acceder_informe_mensual(int mes, int anyo);
/* Pre: mes y anyo deben corresponder a un mes y año
        correctos y con 2 digitos ambos.
   Post: Muestra el informe del mes y año especificados. 
*/


tpInforme acceder_informe_global(void);
/* Pre: --
   Post: Devuelve un informe global calculado a partir
         de los informes mensuales almacenados en la B.D.
*/


int accederDatosJuegos(struct usuario *user, datosJuegos *datos);
/* Pre: user->nick debe ser el nick de un jugador del sistema.
   Post: datos contiene los datos economicos de los juegos del
         usuario con nick user->nick.
	 Devuelve 1 si se realiza correctamente lo anterior y
	 un valor distinto en caso contrario.
 
*/

int actualizarDatosJuegos(struct usuario *user, datosJuegos datos);
/* Pre: user->nick debe ser el nick de un jugador del sistema y
        en datos se almacenan los datos economicos de los juegos
	del usuario.
   Post: Actualiza los datos economicos de los juegos del usuario
         en la B.D asi como actualiza o crea (si aun no existia)
	 el informe economico del mes actual.
	 Devuelve 1 si se realiza correctamente lo anterior y un
	 valor distinto en caso contrario.
*/


int enviar_informe(tpInforme informe, int tipo);
/* Pre: informe debe corresponder a un informe economico de la Casa 
        de Apuestas de tipo global o mensual.
   Post: Envia por email al administrador de la casa de apuestas 
         el informe. */


int listadoUsuarios(lista_dinamica *l);
/* Pre: --
   Post: Crea una lista l con los nicks, fecha de creacion y fecha
         de ultimo login de los jugadores del sistema.
	 Devuelve 1 si la lista se crea correctamente y un valor
	 distinto si ocurre algun error al crearla.
*/
