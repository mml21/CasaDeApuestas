/* MODULO DE GESTION DE EVENTOS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Declaracion del modulo de gestion de eventos */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include "macros.h"
#include "escape.h"

EXEC SQL INCLUDE gestion_interna;


void listar_eventos(int criterio, int tipo, struct usuario *user, lista_dinamica *l);
/*
 * PRE: 'criterio' es un valor entero que indica uno de los criterios de 
 *      ordenacion definidos en la aplicacion.
 *      'tipo' es un valor entero que indica el tipo de los eventos que 
 *      se desean ver listados.
 *
 * POST: Se muestra en pantalla un listado de los eventos de tipo 'tipo'
 *       ordenados segun el criterio de ordenacion 'criterio' mostrado.
 */
 
int introducir_evento(tuplaEvento *evento);
/*
 * PRE: El evento apuntado por 'evento' esta integrado por campos que respetan
 *      el formato definido para la BD de la aplicacion.
 * 
 * POST: Si la introduccion del evento apuntado por 'evento' en la BD se 
 *       lleva a cabo con exito, la funcion devuelve el identificador del 
 *       evento en la BD. En caso contrario, devuelve un valor negativo.
 */ 

int introducir_evento_manualmente();
/*
 * PRE: -
 *
 * POST: Tras introducir interactivamente una serie de datos con los que 
 *       rellenar los campos del evento, este se introduce en la BD.
 *       Ademas, esta funcion forzara la introduccion de posibles resultados
 *       asociados al evento.
 *       Si todos los datos se introducen satisfactoriamente en la BD, la 
 *       funcion devuelve el identificador del evento en la BD. En caso
 *       contrario, devuelve un valor negativo.
 */
 
int introducir_pos_resultado(tuplaResul *resul);
/* 
 * PRE: 'resul' apunta a un posible resultado asociado a un evento ya intro-
 *       -ducido en la BD.
 * 
 * POST: El resultado apuntado por 'resul' se introduce en la BD. Si dicha 
 *       introduccion se lleva a cabo satisfactoriamente, la funcion devuelve
 *       el identificador del posible resultado dentro de la BD. En caso 
 *       contrario, devuelve un valor negativo.
 */

int introducir_pos_resultado_manualmente(int id_evento);
/*
 * PRE: 'id_evento' es un identificador correspondiente a un evento ya intro
 *       ducido en la BD.
 *
 * POST: Tras introducir interactivamente una serie de datos con los que 
 *       rellenar los campos del posible resultado, este se introduce en la BD.
 *       Si esta introduccion se lleva a cabo satisfactoriamente, la funcion
 *       devuelve un valor distinto de cero. En caso contrario, devuelve cero.
 */

int definir_resultados_evento (int id_evento, struct usuario *user);
/* 
 * PRE: 'id_evento' es un identificador de evento ya insertado en la BD.
 * 
 * POST: Tras permitir seleccionar interactivamente un resultado asociado
 *       al evento con identificador 'id_evento', trata de marcar este 
 *       posible resultado como el correcto. Si dicha modificacion se lleva a
 *       cabo satisfactoriamente, la funcion devuelve un valor distinto de 
 *       cero. En caso contrario, devuelve cero.
 */


int generar_id_evento();
/*
 * PRE: -
 *
 * POST: Devuelve el identificador de evento que habra de tener el proximo 
 *       evento a ser insertado en la BD. Este identificador sera una unidad
 *       mayor que el identificador del ultimo evento introducido.
 */
 
int generar_id_resultado();
/*
 * PRE: -
 *
 * POST: Devuelve el identificador de resultado que habra de tener el proximo 
 *       resultado a ser insertado en la BD. Este identificador sera una unidad
 *       mayor que el identificador del ultimo resultado introducido.
 */


int referencia (lista_dinamica *l_favoritos, char cadena[MAX_DESC_LEN]);
/*
 * Pre: l_favoritos es una lista inicializada de cadenas de caracteres.
 *
 * Post: Devuelve un numero positivo si existe alguna ocurrencia de cadena
 *       en l_favoritos. En caso contrario, devuelve cero y en caso de error
 *       un numero negativo.
 */
 
 
int detectar_favoritos (lista_dinamica *l_eventos, lista_dinamica *l_favor);
/*
 * Pre: l_eventos y l_favor son listas inicializadas. l_eventos es una lista
 *      de elementos de tipo tuplaEvento y l_favor es una lista de elementos
 *      de tipo cadena de caracteres.
 *        
 * Post: Devuelve un valor positivo si alguno de los eventos de la lista 
 *       l_eventos hace referencia a alguno de los favoritos de la lista
 *       l_favor. Si no existe ningun evento que haga tal referencia, devuel-
 *       ve cero. En caso de error, devuelve un numero negativo.
 */
 
 
void reordenar_lista (lista_dinamica *l_eventos, lista_dinamica *l_favoritos);
/*
 * Pre: l_eventos y l_favoritos son listas inicializadas, la primera de elemen-
 *      tos de tipo tuplaEvento y la segunda de elementos de tipo cadena de 
 *      caracteres. 
 *
 * Post: l_eventos contiene los mismos elementos que antes, pero aunque siguen 
 *       ordenados en funcion de su tipo (futbol, f1 o social) si alguno de di-
 *       chos elementos hace referencia a alguno de los favoritos de la lista 
 *       l_favor, estos elementos se colocan en la lista por delante de los ele-
 *       mentos de su mismo tipo que no hacen referencia a los favoritos de la 
 *       lista l_favor.
 */
 

void reordenar_sublista (lista_dinamica *l_eventos, lista_dinamica *l_favoritos);
/* Pre: l_eventos y l_favoritos son listas inicializadas, la primera de elemen-
 *      tos de tipo tuplaEvento y la segunda de elementos de tipo cadena de
 *      caracteres.
 *
 * Post: l_eventos contiene los mismos elementos que antes, pero si existia 
 *       algun elemento que hiciera referencia a alguno de los favoritos de la 
 *       lista l_favoritos, estos elementos se colocan en la lista por delante 
 *       de los elementos que no hicieran referencia a los favoritos de la lis-
 *       lista l_favoritos.
 */
  
