/* MODULO DE GESTION INTERNA
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Declaracion del modulo de Gestion Interna */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include <time.h>
#include "macros.h"
#include "escape.h"

EXEC SQL INCLUDE realizar_apuestas;


typedef struct
{
  VARCHAR           nickUser[NICK_LEN];
  VARCHAR           email[MAIL_LEN];
  int               divisa;
} tupla_inf_usuario;


typedef struct 
{
   VARCHAR     nickUser[NICK_LEN];
   int        idApuesta;
   int        idPosResul;
   int        idEvento;
} tuplaPreverResul;   


typedef struct 
{
  int         haOcurrido;
  float       cotizacion;
} tupla_exito_cotiz;  


/************************* Declaracion de funciones ***************************/


/* Operaciones para obtener informacion de datos almacenados en la BD */


int tipo_apuesta (int id_apuesta);
/* 
 * PRE: 'id_apuesta' es un identificador correspondiente a una apuesta 
 *      registrada en la BD.
 *
 * POST: El tipo de la apuesta identificada por 'id_apuesta' es devuelto
 *       por la funcion. Si la funcion no termina correctamente, se devuelve
 *       un valor negativo.
 */


int status_miembro (char id_miembro[NICK_LEN]);
/* 
 * PRE: 'id_miembro' es un identificador correspondiente a un usuario 
 *      registrado en la BD.
 *
 * POST: El status del miembro identificado por 'id_miembro' es devuelto
 *       por la funcion. Si la funcion no termina correctamente, se devuelve
 *       un valor negativo.
 */
 
void efectuar_promociones ();
/*
 * PRE:
 *
 * POST: Detecta a aquellos usuarios que podrian ser promocionados y los eleva
 *      en el ranking interno de la clasificacion si procede.
 */ 
 
 
int detectar_promocion_miembro (char id_miembro[NICK_LEN]);
/* 
 * PRE: 'id_miembro' es un identificador correspondiente a un usuario 
 *      registrado en la BD.
 *
 * POST: Si el miembro con identificador 'id_miembro' ha superado una cierta
 *       cantidad de dinero sumando todas sus cantidades apostadas, incrementa
 *       su ranking al nivel correspondiente.
 *       Devuelve el actual valor del ranking del usuario senyalado por 
 *       'id_miembro' o un valor negativo en caso de error.
 */
 

int se_puede_resolver ( tupla_contabilidad *apuesta );
/*
 * PRE: -.
 *
 * POST: Devuelve un valor distinto de cero si el campo idApuesta apuntado por
 *      'apuesta' no esta referido a ningun evento que todavia no haya termina-
 *      do. En caso contrario, devuelve cero.
 */ 
 
 
/* Operaciones para el envio de mensajes */

void eventos_a_resolver();
/*
 * PRE: -.
 *
 * POST: Envia al administrador un mensaje notificandole si hay eventos que 
 *       resolver.
 */
 

int usuarios_a_dar_de_alta ();
/*
 * PRE: -.
 *
 * POST: Envia al administrador un mensaje notificandole si existen usuarios que
 *       deban ser dados de alta.
 */
 

void enviar_mensaje (char dest[MAIL_LEN], char mens[MAX_LEN]);
/*
 * PRE: - 
 *
 * POST: Envia a la direccion de correo 'dest' un mensaje que contiene la
 *       cadena 'mens'.
 */


/* Operaciones para tramitar los movimientos de credito */


void resolver_evento (int id_evento);
/* 
 * PRE: 'id_evento' es un identificador correspondiente a un evento 
 *       registrado en la BD.
 *
 * POST: Chequea las apuestas que tengan un posible resultado con 
 *       idEvento igual a 'id_evento' y, para aquellas en las que el posible
 *       resultado coincide con el realmente acontecido, calcula las ganancias
 *       de los usuarios que las llevaron a cabo e ingresa estas en sus cuentas.
 *       Por ultimo envia a todos los usuarios que formalizaron la apuesta
 *       un correo electronico con los resultados de dichas apuestas.
 *       Devuelve un valor distinto de cero si la funcion termina con normalidad
 *       o devuelve cero en caso contrario.
 */


float calcular_ganancias_usuario (char nick[NICK_LEN], int id_evento);
/*
 * PRE: -.
 *
 * POST: Calcula las ganancias obtenidas por el usuario con nick 'nick' gracias
 *       a la apuesta identificada por 'id_apuesta' en la BD.
 *       Devuelve el valor de dichas ganancias si termina con normalidad. Si el
 *       usuario no ha obtenido ganancias o ha habido un error devuelve 0.0.
 */


float resolver_apuesta_simple (tupla_contabilidad *info_contab);
/*
 * PRE: -.
 *
 * POST: Si el campo 'haOcurrido' de la estructura info_contab es cierto,
 *       devuelve el resultado correspondiente a haber apostado 'cantidad'
 *       euros a un posible resultado con cotizacion 'cotizacion', donde 
 *       'cantidad' y 'cotizacion' son campos de la estructura info_contab.
 *       En cambio, si el campo 'haOcurrido' es falso, devuelve 0.0.
 */
	
 
float resolver_apuesta_sistema(tupla_contabilidad *apuesta);
/*
 * PRE: 'lista' es una lista de estructuras de tipo 'tupla_contabilidad'.
 *
 * POST: Si existe alguna combinacion de posibles resultados en la lista que
 *       verifique el sistema escogido, devuelve el resultado correspondiente.
 *       Este sistema viene determinado por el valor del campo 'combinadas' de
 *       los nodos de la lista y por el valor de 'num_apuestas'.
 *       En caso de no verificarse ninguna combinacion de posibles resultados,
 *       devuelve 0.0.
 */	 
 
 
float resolver_apuesta_combinada(tupla_contabilidad *apuesta);
/*
 * PRE: -.
 *
 * POST: Si todos los pronosticos de la apuesta con identificador el campo 
 *       idApuesta de la estructura apuntada por apuesta son correctos, devuel-
 *       ve el resultado correspondiente a una apuesta combinada en la que se 
 *       han apostado 'cantidad' euros a diferentes posibles resultados.
 *      'cantidad' es un campo de las estructura apuntada por apuesta.
 *       La cotizacion total asociada a la apuesta es el producto de las co-
 *       tizaciones de los posibles resultados individuales.
 */


int ingresar_credito (char id_usuario[NICK_LEN], float ganancias );
/*
 * PRE: 'id_usuario' es un identificador correspondiente a un usuario registrado
 *      en la BD.
 *
 * POST: Ingresa en la cuenta correspondiente al usuario con identificador 
 *       'id_usuario' un cantidad equivalente (en la correspondiente divisa del
 *       usuario) a 'ganancias' euros. Devuelve cero en caso de error y cual-
 *       quier otro valor en los demas casos.
 */


/* Otras operaciones */

struct tm* desplazar_fecha(int desfase);
/*
 * PRE: -.
 *
 * POST: Devuelve un puntero a estructura de tipo tm que almacena la hora del
 *       sistema desfasada en 'desfase' segundos.
 */


int actualizarPerfilUsuario(perfilUsuario *perfil);
/* Pre: perfil debe corresponder al perfil de un usuario registrado
        en la Casa de Apuestas.
   Post: Actualiza todos los campos del perfil del usuario concreto
         en la B.D. con la informacion contenida en perfil.
         Devuelve 1 si la actualizacion se realiza de forma correcta, 0
         si el usuario al que se refiere el perfil no existe y -1 si
         ocurre algun error en la actualizacion.
*/

int actualizarPerfilUsuarioTrasApostar(perfilUsuario *perfil, struct apuesta apuestaUser);
/* Pre: perfil debe corresponder al perfil de un usuario registrado
        en la Casa de Apuestas.
  Post: Actualizara los campos del perfil en funcion de una apuesta realizada.
        Esto se hara en interaccion con la realizacion de apuestas.
        Hay que actualizar el perfil del usuario tras cada apuesta realizada.
*/


int actualizarPerfilUsuarioTrasJugar(perfilUsuario *perfil, int juego);
/* Pre: perfil debe corresponder al perfil de un usuario registrado
        en la Casa de Apuestas.
  Post: Actualiza el perfil del usuario tras jugar a algun juego. 
*/


int actualizarDatosAlResolverApuesta(int cantidad);
/* Pre: cantidad > 0 
   Post: Actualiza o crea (si aun no existia) el informe economico 
         del mes actual añadiendo los datos de la apuesta resuelta
	 en la que se ha ganado cantidad de euros. 
	 Devuelve 1 si se realiza correctamente y -1 en caso contrario.
*/
