/* MODULO DE REALIZACION DE APUESTAS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Declaracion del modulo de Realizar Apuestas */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>

EXEC SQL INCLUDE interfaz;



	
int apostable (int ev);
/* Pre: --
   Post: devuelve 1 si todavia se pueden realizar apuestas al evento
   indicado, es decir, que el plazo para apostar aun no ha finalizado.
   Devuelve 0 en caso contrario */


int evento_resultado (int res);
/* Pre: res tiene que ser un identificador valido de resultado */
/* Post: devuelve el identificador de evento asociado a un resultado */


int resultado_apostable (int res);
/*  Pre: res tiene que ser un identificador valido de resultado */
/*  Post: devuelve 1 si el identificador de resultado esta asociado a un evento 
  	 apostable */
	 

float cotizacion_resultado (int id_res);
/* Pre: --
   Post: devuelve la cotizacion asociada al identificador de posible
   resultado indicado. En caso de que no exista o haya algun error
   devuelve -1 */


int resultados_evento (int ev, lista_dinamica *l);
/*  Pre: --
    Post: Agrega a la lista dinamica los resultados asociados
          al identificador de evento que se pasa como parametro.
	  Devuelve el numero de resultados asociados al evento */


int info_eventos(int deporte,lista_dinamica *listaEventos);
/* Pre: --
     Post: agrega a la lista dinamica el conjunto de eventos asociados al
     deporte indicado como parametro*/
     

float consultar_saldo (char nick[NICK_LEN]);
/* Pre: --
   Post: Devuelve el saldo del usuario que se pasa como parametro.
   En caso de que el usuario no este registrado o que ocurra algun
   error devuelve -1 */
    
 
int comprobar_saldo_usuario(char id[NICK_LEN], float cant);
/* Pre: --
* Post: Devuelve un valor distinto de '0' si el usuario 'id' dispone de 
* suficiente credito como para pagar la cantidad 'cant' 
* que pretende apostar.
*/

int efectuar_apuesta_simple(int id_res, char id_us[NICK_LEN], float cantidad);
/* Pre: --
* Post: Permite al usuario 'id_us' efectuar una apuesta a un determinado
* resultado 'id_res' de un evento.
*/


int efectuar_apuesta_multiple (lista_dinamica *l_res, char id_us[NICK_LEN],
                               float apostado, int tipo, int combinadas);
/* Pre: tipo = por sistema o combinada 
        l: lista dinamica con mas de un elemento 
	   de id's de posible resultado 
   Post: registra la apuesta. Su la efectua con exito
         devuelve 1, en caso contrario devuelve 0 */
 
 
int apuestas_pendientes(char id[NICK_LEN], lista_dinamica *l);
/* Pre: El ususario id debe estar registrado */
/* Post: Vuelca sobre la lista dinamica el conjunto de apuestas pendientes 
            referentes al usuario */
	
	
int se_corresponden (int id_ev, int id_res);
/* Pre: -- 
/* Post: devuelve 1 si el identificador de resultado
         esta asociado al identificador de evento */
	
	    
float maximo_apostable(int id_ev);
/*  Pre: -- 
/*  Post: devuelve la cantidad maxima apostable al evento
    cuyo identificador de evento se pasa como parametro. En
    caso de que el evento no exista devuelve -1 */
 

int descripcion_resultado (char *nombre, int id);
/* Pre: Debe haber un resultado identificado con el identificador id
   Post: Escribe en la zona de memoria apuntada por nombre la descripcion
         del resultado que tiene asociado el identificador id */
	
	 
int descripcion_evento (char *nombre, int id);
/* Pre: Debe haber un resultado identificado con el identificador id
   Post: Escribe en la zona de memoria apuntada por nombre la descripcion
         del evento que tiene asociado el identificador id como alguno de
	 sus posibles resultados. */


int desc_evento (char *nombre, int id);
/* Pre: Debe haber un resultado identificado con el identificador id
   Post: Escribe en la zona de memoria apuntada por nombre la descripcion
         del evento que tiene asociado el identificador id como alguno de
	 sus posibles resultados. */


int retirar_credito (char *nick, float *cantidad, int divisa);
/* Pre: el usuario debe existir
   Post: actualiza el credito del usuario restandole la cantidad indicada.
         Devuelve 1 si la operacion se puede realizar y 0 en caso contrario */


int insertar_credito (char *nick, float *cantidad, int divisa);
/* Pre: el usuario debe existir
   Post: actualiza el credito del usuario sumandole la cantidad indicada.
         Devuelve 1 si la operacion se puede realizar y 0 en caso contrario */


int ha_pasado (int id_resul);
/* Pre: id_resul es un identificador valido de resultado */
/* Post: indica si el evento del resultado ya se ha celebrado */


int se_ha_celebrado (int id_ev);
/* Pre: id_ev es un identificador valido de evento */
/* Post: dado un identificador de evento indica si ya se ha celebrado */


int ha_sucedido (int id_resul);
/* Pre: id_resul es un identificador valido de resultado */
/* Post: indica si el identificador de resultado ha sido el sucedido */


int historico_usuario (struct usuario *user);
/* Pre: el nick debe correponder a un usuario registrado 
   Post: muestra por pantalla el historico de un usuario mostrando
         sus apuestas resueltas y su balance global */


int actualizarDatosAlApostar(int cantidad);
/* Pre: cantidad > 0 
   Post: Actualiza o crea (si aun no existia) el informe economico 
         del mes actual añadiendo los datos de la apuesta realizada
	 a la que se ha apostado cantidad de euros. 
	 Devuelve 1 si se realiza correctamente y -1 en caso contrario.
*/


void mostrar_eventos_antiguos (struct usuario *user);
/* Pre: --
   Post: muestra por pantalla los eventos ya celebrados que el usuario
   seleccione */
