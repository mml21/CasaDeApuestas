/* MODULO DE GESTION DE USUARIOS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Declaracion del modulo de Gestion de Usuarios */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include "macros.h"


EXEC SQL INCLUDE tipos;

/* --------------------- Funciones del modulo ----------------------- */


int existeNick (char *nickJugador);
/* Pre: --
   Post: Devuelve 1 si nickJugador esta registrado como jugador en la 
         Casa de Apuestas y 0 en caso contrario. 
         Devuelve -1 si ocurre algun tipo de error en la consulta SQL. 
*/
   

int obtener_datos_globales(char *nickJugador, int *tipo, 
                           int *divisa, float *credito);  
/* Pre: --			   
   Post: Devuelve 1 si nickJugador esta registrado como jugador o como
         administrador de la Casa de Apuestas y en este caso tipo es el 
         tipo de usuario de que se trata. Si es un jugador, ademas, 
         divisa y credito toman el valor de la divisa empleada por el
         jugador y del credito que posee el jugador en el momento actual,
         respectivamente. En cualquier otro caso, divisa y credito quedan
         indefinidos.
         Devuelve un 0 si nickJugador no corresponde a ningun jugador o
         administrador de la Casa de Apuestas.
         Devuelve -1 si ocurre algun tipo de error en las sentencias SQL 
*/


int esMayorEdad (char *nickJugador);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas.
   Post: Devuelve 1 si el jugador con nickJugador es mayor de edad (en EspaÃ±a)
         y 0 si no lo es. Devuelve -1 si ocurre algun tipo de error en la 
         sentencia SQL. 
*/


int validarLogin (char *nick, char *password);
/* Pre: --
   Post: Devuelve 1 si nick y password corresponden al nick y la 
         contraseña de algun jugador registrado en la Casa de Apuestas.
	 Devuelve 0 si nick y password corresponden al nick y la
	 contraseña de algun administrador de la Casa de Apuestas.
         Devuelve -1 si ocurre algun tipo de error en la sentencia SQL o
	 el nick y la contraseña no corresponden a ningun jugadodor o 
	 administrador de la Casa de Apuestas. 
*/


int validarRecordatorioPass (char *nickJugador, char *respSecreta, VARCHAR *pass);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas.
   Post: Devuelve 1 si respSecreta coincide con la respuesta privada del 
         usuario con nick nickJugador y 0 en caso contrario.
	 En el caso de que la respuesta secreta proporcionada sea correcta, pass
	 contiene la password del jugador.
         Devuelve -1 si ocurre algun tipo de error en la sentencia SQL. 
*/


int accederPregRecordatorioPass(char *nickJugador, VARCHAR *pregSecreta);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas.
   Post: Devuelve 1 y pregPrivada contiene la pregunta
         privada del usuario con nick nickJugador. 
         Si ocurre algun tipo de error devuelve -1 y respuesta secreta queda
         indefinido. 
*/



/* --------------- Para el jugador de la casa de apuestas -------------------- */


/* Una vez validado el usuario con nick y contrasena correctos...*/


int accederDatosPersonales (char *nickJugador, tuplaUsuario *user);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas. Ademas, el usuario
        debe haber validado su login anteriormente en la Casa de Apuestas.
   Post: Devuelve 1 y user contiene los datos personales del usuario.
         Devuelve -1 si ocurre algun tipo de error. 
*/


int modificarDatosPersonales (char *nickJugador, tuplaUsuario user);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas. Ademas, el usuario
        debe haber validado su login anteriormente en la Casa de Apuestas.
   Post: Actualiza algunos datos personales del usuario en la B.D. con los
         datos almacenados en la estructura user. Los datos que se pueden actualizar
         desde esta funciÃ³n son: CP, localidad, pais, email, preguntaPrivada,
         respuestaPrivada, divisa e idioma. Para modificar la password se hace desde
         modificarPassUsuario. 
         Devuelve 1 si la modificacion de los datos del usuario se realiza de forma
         correcta y 0 en caso contrario.
         Devuelve -1 si ocurre algun tipo de error. 
*/


int darseBaja (char *nickJugador);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas. Ademas, el usuario
        debe haber validado su login anteriormente en la Casa de Apuestas.
   Post: Devuelve 1 si elimina los datos del usuario de la tabla Usuario de la
         B.D. de la Casa de Apuestas de forma correcta y 0 en caso contrario.
         Devuelve -1 en caso de que ocurra algun tipo de error. 
*/


int solicitarAlta (tuplaUsuario user);
/* Pre: (user.dadoAlta = FALSE) AND (user.gananciasJuego = 0.0) AND
        (user.gananciasTotales = 0.0) AND (user.credito = 0.0) AND
	(user.fechaCreacion = sysdate (fecha actual) ) AND
	(user.fechaUltLogin = sysdate (fecha y hora actuales) ).
   Post: Almacena los datos del usuario en la B.D. y lo marca como usuario 
         pendiente de recibir el alta definitiva en la Casa de Apuestas.
         Devuelve 1 en caso de que lo anterior se realice de forma
         correcta y -1 en caso de que ocurra algun tipo de error
         al almacenar los datos del usuario en la B.D. 
*/


int modificarPassUsuario(char *nickJugador, char *passVieja, char *passNueva);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas. Ademas, el usuario
        debe haber validado su login anteriormente en la Casa de Apuestas.
   Post: Devuelve 1 si la passVieja del usuario con nick nickJugador corresponde
         a la password del usuario y la cambia por la contenida en passNueva.
         Devuelve 0 si la password antigua proporcionada no coincide.
         Devuelve -1 si ocurre algun tipo de error. 
*/


int modificarDatosRecordatorioPass(char *nickJugador, char *pregNueva, char *respNueva);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas. Ademas, el usuario
        debe haber validado su login anteriormente en la Casa de Apuestas.
   Post: Devuelve 1 si modifica la pregunta y respuesta secretas del usuario con nick
         nickJugador con los valores de pregNueva y respNueva.
         Devuelve -1 si ocurre algun tipo de error. 
*/


/* --------------- Para el administrador de la casa de apuestas -------------------- */


int darAltaUsuario (char *nickJugador);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas pero que aun no
        ha sido dado de alta, es decir, su atributo dadoAlta = 0.
   Post: Registra definitivamente al usuario como jugador de la Casa
         de Apuestas poniendo su atributo dadoAlta a 1 y devuelve 1 en ese caso.
         Devuelve -1 si ocurre algun tipo de error. 
*/


int darBajaUsuario (char *nickJugador);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas ya registrado
        definitivamente.
   Post: Devuelve 1 si el usuario es dado de baja de la Casa de Apuestas de
         forma correcta.
         Devuelve -1 si ocurre algun tipo de error. 
*/


int accederDatosUsuario (char *nickJugador, tuplaUsuario *user);
/* Pre: nickJugador debe corresponder al nickUser de algun usuario almacenado
        en la tabla Usuario de la B.D. de la Casa de Apuestas.
   Post: Devuelve 1 si los datos del usuario quedan almacenados
         en el parametro user.
         Devuelve -1 si ocurre algun error.
*/


int listaNicksUsuariosRegistrados(lista_dinamica *listaUsuariosRegistrados);
/* Pre: --
   Post: Almacena en la lista dinamica los nicks de todos los usuarios registrados 
         en la Casa de Apuestas. Devuelve 1 si esto se realiza de 
         forma correcta. Devuelve -1 si ocurre algun tipo de error. 
*/


int listaNicksUsuariosPendientes(lista_dinamica *listaUsuariosPendientes);
/* Pre: --
   Post: Almacena en la lista dinamica los nicks de todos los usuarios pendientes de ser 
         registrados en la Casa de Apuestas. Devuelve 1 si esto se realiza de 
         forma correcta. Devuelve -1 si ocurre algun tipo de error. 
*/


int accederPerfilUsuario(struct usuario *user, perfilUsuario *perfil);
/* Pre: --
   Post: Devuelve 1 si se ha podido acceder al perfil del usuario user
         en cuyo caso se guarda el mismo en perfil.
         Si el usuario no existia devuelve 0 y si ocurre algun tipo de
         error devuelve -1 
*/


int accederPerfilUsuarioNick(char *user, perfilUsuario *perfil);
/* Pre: --
   Post: Devuelve 1 si se ha podido acceder al perfil del usuario user
         en cuyo caso se guarda el mismo en perfil.
         Si el usuario no existia devuelve 0 y si ocurre algun tipo de
         error devuelve -1 
*/


void copiarDatosPerfilUsuario(perfilUsuario origen, perfilUsuario *destino);
/* Pre: origen debe contener los datos del perfil de un usuario.
   Post: El perfil destino contiene los datos del perfil origen.
*/


void obtener_favoritos(struct usuario *user, lista_dinamica *l_favoritos);
/*
   Pre: l_favoritos es una lista dinamica de elementos de tipo cadena
        ya inicializada.
   Post: l_favoritos contiene un listado de los favoritos del usuario
        identificado por el campo nick de la estructura apuntada por user.
*/
 
 
int obtener_direccion_email (char mail[MAIL_LEN], char nick[NICK_LEN]);
/*
   Pre: --
   Post: mail contiene la direccion de correo del usuario identificado por
        'nick' en la BD. Devuelve un valor distinto de cero si termina 
        correctamente y cero en caso contrario.
*/


int actualizarFechaUltLogin(char *nick);
/* Pre: nick debe corresponder a algun jugador o administrador de la
        Casa de Apuestas.
   Post: Actualiza la fecha de ultimo login del usuario.
*/


int obtener_idioma(char *nick);
/* Pre: nick debe corresponder a algun jugador o administrador de la
        Casa de Apuestas.
   Post: Devuelve el idioma del usuario.
*/



/* ----------------- Otras funciones --------------------------------- */

/* Declaracion del procedimiento definido para el tratamiento de errores
   en las sentencias SQL. */

int sql_error(char *msg);
/* Pre: --
   Post: Imprime por pantalla el mensaje msg 
*/
