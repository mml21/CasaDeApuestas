/* MODULO DE PROMOCIONES, OFERTAS Y BONOS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion del modulo de gestion
                de bonos, ofertas y promociones */


/* Numeracion de las ofertas:
     
      - oferta regalo inicial:       num 0.
      - oferta efectivo usuario:     num 1.
      - oferta premiado permanencia  num 2.
      - oferta cumpleanyos:          num 3.
               
*/
      
#include <stdio.h>
#include <string.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include "macros.h"

EXEC SQL INCLUDE juegos;


void extender_cheque_usuario(struct usuario *user);
/*
   Pre: 'user' es la direccion de memoria de una estructura que almacena toda
        la informacion relativa al usuario que ejecuta actualmente la aplica-
        cion.
  
   Post:Solicita el nick del usuario a bonificar, la cantidad a extenderle y 
        efectua el pago.
 */


int introducir_oferta (int id_oferta, char *nick_admin, char *info_promo,
                         int min_rank);
/* 
  Pre: 'id_oferta' es un identificador correspondiente a una de las ofertas 
        cuyos algoritmos ya estan definidos. 'nick_admin' es el nick que iden-
        tifica a uno de los administradores de la BD. 'min_rank' sera el ranking
        minimo que un usuario debera tener para poderse beneficiar de esta ofer-
        ta. 	
 
   Post: Introduce la oferta de identificador 'id_oferta' en la BD. Se marca
         como introducida por 'nick_admin' y se la describe con 'info_promo'.
         Valor a devolver:
            - Nulo cuando falla la introduccion.
            - No nulo cuando la introduccion se lleva a cabo sin problemas.
 */
 

int introducir_oferta_manualmente ();
/*
   Pre: --
  
   Post: Solicita interactivamente datos al administrador para efectuar la in-
         troduccion de una determinada apuesta en la BD. Cuando la funcion con-
         cluye satisfactoriamente, devuelve un valor no nulo. En caso contrario
         devuelve un valor nulo.
 */
 
 
void listar_ofertas ();
/*
   Pre: --
 
   Post: Lista todas las ofertas que hay en vigor en la BD.
 */


int borrar_oferta (int id_oferta);
/*
   Pre: 'id_oferta' es un identificador correspondiente a alguna oferta ya exis-
        tente en la BD.
  
   Post: Elimina de la BD la oferta con identificador 'id_oferta'. Devuelve un
         valor negativo si el borrado se lleva a cabo satisfactoriamente y un va-
         lor positivo en caso contrario.  
 */
 

int borrar_oferta_manualmente();
/*
   Pre: 
 
   Post: Ofrece al administrador un listado de ofertas activas en la BD y le 
         permite borrar una de estas. Si concluye satisfactoriamente devuelve un
         valor positivo. Si el borrado falla devuelve un valor negativo y si se 
         intenta borrar una promocion que no esta en la BD devuelve un valor 
         nulo.
 */
  

void oferta_regalo_inicial (char n_user[NICK_LEN]);
/*
   Pre: 'n_user' es el identificador de un cliente de la BD.
 
   Post: Inserta una cantidad inicial de 5 euros en la cuenta del usuario. Esta 
         cantidad sera posteriormente convertida a la divisa correspondiente.
 */
 
 
void oferta_efectivo_usuario(char n_user[NICK_LEN], float cantidad);
/*
   Pre: 'n_user' es el identificador de un cliente de la BD.
 
   Post: Anyade al credito del usuario de la BD identificado por 'n_user'
         la cantidad indicada por 'cantidad'.
 */


void oferta_premiado_anyo_permanencia();
/*
   Pre: --
 
   Post: Premia a todos aquellos usuarios que cumplen su aniversario como clien-
         tes de Apostopolis ingresandoles la cantidad simbolica de 15 euros.
 */
 
 
void oferta_cumpleanyos ();
/*
   Pre: --
 
   Post: Premia a todos aquellos usuarios que entran en Apostopolis el dia de su
         cumpleanyos.
 */


void administrar_ofertas();
/*
   Pre: --
  
   Post: Otorga a cada usuario las promociones que le son aplicables.
 */


int actualizarDatosOfertas(float cantidad);
/*
   Pre: cantidad > 0 
 
   Post: Actualiza o crea (si aun no existia) el informe economico 
         del mes actual añadiendo los datos de la ofera realizada
  	 a la que se ha regalado al usuario cantidad de euros. 
  	 Devuelve 1 si se realiza correctamente y -1 en caso contrario.
 */
