/* MODULO DE INTERFAZ
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion del modulo de interfaz */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>


EXEC SQL INCLUDE gestion_usuarios;



/*---------------------------------------------------------------*/
/*--------------------- Definiciones de datos -------------------*/
/*---------------------------------------------------------------*/
typedef struct
{
  char *vectop[30];  /*Vector de punteros a caracter */
  int numop;  /* Siguiente elemento a insertar */
} lista_opciones;

typedef void *Combinations;

typedef struct {
  int	nelem;		/* for i in [0..nelem-1] */
  int	ncombo;		/* for j in [0..ncombo-1] */
  int	**combos;	/* combos[i][j] is ith element of jth combo */
} combinations_t;




/*.-------------------------------------------------------------------------------- */
/* ---------------------- Funciones de combinatoria ------------------------------- */
/* -------------------------------------------------------------------------------- */

void free_combinations(Combinations vp);
/* Pre: --
   Post: Libera la memoria dinamica que ocupa la escructura permutaciones pasada
         como parametro */


Combinations init_combinations(int nuniv, int nelem);
/* Pre: nuniv <= nelem
   Post: Devuelve una estructura que contiene todos los posibles subconjuntos de
         cardinalidad nelem de un conjunto de cardinalidad nuniv  */


int num_combinations(Combinations vp);
/* Pre: vp tiene que contener un conjunto de permutaciones 
   Post: devuelve el numero de subconjuntos que contiene la estructura vp,
         es decir, el numero combinatorio de la cardinalidad del conjunto
	 sobre la cardinalidad de los subconjuntos */


void get_combination(Combinations vp, int cnum, int *elems);
/* Pre: vp tiene que contener un conjunto de permutaciones
        cnum < num_combinations (vp) 
   Post: Escribe en el espacio apuntado por el puntero elems el conjunto
         indicado por cnum. Cada elemento del conjunto se escribe
	 como un entero. */




/*---------------------------------------------------------------*/
/*---------------------Funciones de internacionalizacion---------*/
/*---------------------------------------------------------------*/
void configurar_idioma (int opcion);
/* Pre: opcion tiene que ser uno de los idiomas predeinidos
   Post: establece como idioma de la aplicacion el idioma
   seleccionado */


char *frase(char *cad);
/* Pre: El idioma debe estar configurado y cad debe ser una 
        etiqueta valida del idioma
   Post: devuelve un puntero a la palabra clave de la etiqueta */





/*---------------------------------------------------------------*/
/*-------Funciones para el manejo de botones mediante listas-----*/
/*---------------------------------------------------------------*/

void nueva_lista (lista_opciones *l);
/* Pre: --
   Post: Crea una nueva lista de botones */
   
   
void agregar_opcion (lista_opciones *l, char *opcion);
/* Pre: la lista l debe contener menos del maximo de opciones
   Post: Agrega la opcion indicada como segundo parametro a la lista */
   
   
int es_vacia (lista_opciones l);
/* Pre: --
   Post: Devuelve 1 si la lista esta vacia y 0 en caso contrario */


void destruir_lista_op (lista_opciones *l);
/* Pre --
   Post: libera la memoria dinamica que ocupa la lista */


int elegir_opcion (lista_opciones l);
/* Pre: es_vacia(l) = false
   Post: muestra por pantalla la lista y gestion la eleccion de
         una opcion por parte del usuario devolviendo la opcion
	 elegida como su posicion (en orden de introduccion) 
	 en la lista */





/*--------------------------------------------------------------*/
/*---------------Funciones de lecturas por teclado--------------*/
/*--------------------------------------------------------------*/
void leer_pass(char *,int x, int y);
/* Pre:x, y son las coordenadas desde donde se debe leer el pass,
   tienen que ser coordenadas utiles de la pantalla.
   Post: Almacena en las posiciones consecutivas de memoria donde
         apunta cadena el password leido. Lee el password de forma
	 no visible por pantalla */



char leer_caracter_oculto();
/* Pre: --
   Post: Lee un caracter de la entrada estandar sin mostrarlo por
         pantalla y sin necesidad de pulsar enter */


void preguntarVARCHAR (char *msg, VARCHAR *dest, short max); 
/* Pre: --
   Post: Lee de teclado una cadena y la transforma a formato VARCHAR */
   
   
char leer_caracter (void);
/* Pre: --
   Post: Lee un caracter de la entrada estandar */
   
   
int leer_cadena_cota (char *cadena, int cota);
/* Pre: --
   Post: Lee una cadena de longitud <= cota */   
   
   
int leer_cadena (char *cadena);
/* Pre: --
   Post: lee una cadena de teclado */   
   
   
 void leer_entero (int *num);
/* Pre: --
   Post: lee un entero de teclado */
   
   
void leer_float (float *num);
/* Pre: --
   Post: lee un real de teclado */   
   
   
   
   
   
     
/*--------------------------------------------------------------------------*/
/*----------------------- Funciones de manejo de divisas -------------------*/
/*--------------------------------------------------------------------------*/

float a_dolar (float euros);
/* Pre: --
   Post: devuelve la cantidad en dolares del numero de euros pasado*/


float a_euros (float dolares);
/* Pre: --
   Post: devuelve la cantidad en euros del numero de euros pasado*/


void mostrar_saldo (float cantidad, int divisa);
/* Post: muestra por pantalla una cantidad de dinero con su 
         correspondiente divisa */





/*------------------------------------------------------------------------*/
/*---------------Funciones de peticion de informacion---------------------*/
/*------------------------------------------------------------------------*/

int seguir(char *fallo);
/* Pre: --
   Post: Informa al usuario de que se ha producido un error debido a la 
         causa que se pasa como parametro (una cadena). Pregunta al 
	 usuario si quiere volver a intentarlo, en cuya afirmacion
	 devuelve un 1. Devuelve 0 en caso contrario */


int preguntar_datos_personales(tuplaUsuario *datos);
/* Pre: --
   Post: Interactua con el usuario preguntandole sus datos
         personales para una posterior alta. Si esto se 
	 realiza con exito devuelve 1. Devuelve 0 en caso
	 contrario */


void obtener_nick_pass(char *nick, char *pass);
/* Pre: --
   Post: pregunta por pantalla el nick y el password de un usuario
         y los guarda en las direcciones de memoria apuntadas por 
	 los correspondientes punteros pasados como parametro */


int pedir_datos_ingresos (struct usuario *user, float *cantidad);
/* Pre: --
   Post: pide al usuario los datos necesarios para hacer un ingreso
         (numero de cuenta y cantidad). Si la interaccion se hace 
	 con exito devuelve 1. Devuelve 0 en caso contrario */


int pedir_datos_cobros (struct usuario *user, float *cantidad);
/* Pre: --
   Post: pide al usuario los datos necesarios para hacer una retirada de
         dinero (numero de cuenta y cantidad). Si la interaccion se hace 
	 con exito devuelve 1. Devuelve 0 en caso contrario */





/*----------------------------------------------------------------------------------------*/
/*-------------------------------Funciones para mostrar datos-----------------------------*/
/*----------------------------------------------------------------------------------------*/

void escribir_hora(int idioma);
/* Pre: --
   Post: Escribe por pantalla la fecha y la hora actuales del sistema
   en el formato:
   Dia de la semana - Dia del mes - Mes - Anyo - Hora - Minutos 
   y en el correspondiente idioma */


void mostrar_cabecera_sin_login();
/* Pre: --
   Post: muestra la cabecera de la aplicacion en los momentos en que el usuario
         no ha iniciado sesion. Tanto para usuarios como para administradores */


void mostrar_cabecera (int tipo, struct usuario *user);
/* Pre: --
   Post: muestra la cabecera de la aplicacion en los momentos en los que la 
         sesion se ha iniciado, tanto para usuarios como para administradores */


void mostrar_datos_personales (tuplaUsuario *user);
/* Pre: --
   Post: muestra por pantalla los datos personales del usuario 
   los cuales se pasan como parametro */


void mostrar_resultados (lista_dinamica *l);
/* Pre: --
   Post: muestra todos los resultados de la lista */


void mostrar_info_apuestas (lista_dinamica *l,struct usuario *user);
/* Pre: --
   Post: muestra la informacion de las apuestas pendientes de un usuario junto
         con la informacion de sus eventos. Agrupa las apuestas por tipos */


int mostrar_eventos (lista_dinamica *l, struct usuario *user);
/*  Pre: l es una lista dinamica de tuplaEvento
    Post: Devuelve 1 si se ha mostrado algun evento */


int seleccionar_res (struct usuario * user,int id_ev);
/* Pre: El identificador de evento tiene que tener asociados unos resultados.
        El numero de resultados asociados al evento debe ser menor de 14.
   Post: pregunta al usuario a que resultado del evento quiere apostar. En caso de 
         que elija no apostar devuelve 0. Devuelve el identificador del resultado
	 en caso contrario */


int mostrar_resultado_prob (resulProb *dato, struct usuario *user);
/* Pre: --
   Post: pregunta al usuario si quiere apostar al resultado dada la probabilidad
   de este */


void mostrar_ganancias_sistema (lista_dinamica *lista,int combinadas, float cantidad);
/* Pre: numdatos(lista) > 2 AND cantidad > 0.0 AND 7 >= combinadas >=2
   Post: muestra la ganancia potencial de una apuesta por sistema */





/*---------------------------------------------------------------------------------*/
/*------------------------------ Menus de interfaz --------------------------------*/
/*---------------------------------------------------------------------------------*/

int menu_principal(void);
/* Pre: --
/* Post: Muestra el menu principal de la aplicacion y devuelve la opcion elegida 
         por el usuario.*/


int opcion_menu_cliente(struct usuario *user);
/* Pre: --
   Post: Muestra el menu de opciones para los usuarios y devuelve
         la opcion escogida */


int opcion_menu_admin(struct usuario *user);
/* Pre: --
   Post: Muestra el menu de opciones para el administrador y devuelve
         la opcion escogida */


int pantalla_inicial(void);
/* Pre: --
   Post: Muestra la pantalla inicial y pide el idioma en el que se desea
         que se ejecute la aplicacion. Devuelve el idioma elegido */


void menu_evento_criterio (struct usuario *user,int *opcion, int *criterio, int se_puede);
/* Pre: --
   Post: Pide al usuario Tipo y Criterio para un listado de eventos */


int mostrarPantJuegos(struct usuario *user);
/* Pre: --
   Post: muestra la pantalla de eleccion de juego  para que el
         usuario elija y devuelve a que juego se quiere jugar  */


int mostrarPantDados (struct usuario *user);
/* Pre: --
   Post: muestra la pantalla de apuesta a dados  para que el usuario
         elija y devuele a que se quiere apostar */


int mostrarPantRuleta (struct usuario *user);
/* Pre: --
   Post: muestra la pantalla de apuesta a ruleta  para que el usuario
         elija y devuele a que se quiere apostar */


int pedir_datos_dados (struct usuario *user, int opcion, float *cantidad, int *numero);
/* Pre: --
   Post: pide al usuario los datos para realizar una apuesta de dados
         (cantidad y/o numero) y los guarda en la zona de memoria
	 apuntada por los correspondientes punteros pasados como 
	 parametro */


int mostrar_resultado_dados(float *cantidad, int dado1, int dado2, int opcion, struct usuario *user, int resultado);
/* Pre: --
   Post: muestra el resultado de una partida de dados indicando ademas al usuario el resultado de
         su apuesta */


int pedir_datos_ruleta (struct usuario *user, int opcion, float *cantidad, int *numero);
/* Pre: --
   Post: pide al usuario los datos para realizar una apuesta de dados
         (cantidad y/o numero) y los guarda en la zona de memoria
	 apuntada por los correspondientes punteros pasados como 
	 parametro. Devuelve 1 si los datos se han pedido de forma correcta y 0 en 
	 caso contrario. */


int mostrar_resultados_ruleta (int opcion, struct tpResulRuleta resultado, float *cantidad, int numero, struct usuario *user);
/* Pre: --
   Post: muestra el resultado de una partida de ruleta indicando ademas al usuario el resultado de
         su apuesta */
	

int mostrar_resultados_carta (int opcion, tpCarta cartaUsuario, tpCarta
                              cartaMaquina, float *cantidad, struct usuario *user);
/* Pre: --
   Post: muestra el resultado de una partida de carta mas alta indicando ademas al usuario el resultado de
         su apuesta */
	 

int pedir_datos_carta (struct usuario *user, float *cantidad);
/* Pre: --
   Post: pide al usuario los datos para realizar una apuesta de carta mas alta
         (cantidad) y los guarda en la zona de memoria
	 apuntada por los correspondientes punteros pasados como 
	 parametro. Devuelve 1 si los datos se han pedido de forma correcta
	 y 0 en caso contrario */
	 
	 
int pedir_datos_blackjack (struct usuario *user, float *cantidad);
/* Pre: --
   Post: pide al usuario los datos para realizar una apuesta de BlackJack
         (cantidad) y los guarda en la zona de memoria
	 apuntada por los correspondientes punteros pasados como 
	 parametro */	  
	 

int elegir_resultado (lista_dinamica *lista, struct usuario *user);
/* Pre: Lista es lista dinamica de tuplaResul */
/* Post: devuelve el identificador de resultado seleccionado por el usuario */	 
	 
	 
void mostrar_perfil (perfilUsuario *pref);
/* Pre: --
   Post: muestra por pantalla el perfil de usuario pasado como parametro */	 
	 

int pedir_preferencias_globales (int *futbol, int *f1, int *social);
/* Pre: --
   Post: pregunta al usuario acerca de las preferencias en todas las tematicas */


void mostrar_resultado_apuesta_simple(int id_res,float *mi_cantidad,
                                     float *ganancia, struct usuario *user);
/* Pre: id_res es un identificador valido de resultado
        mi_cantidad >= 0.0   ganancia >=0.0
	user es un usuario registrado
   Post: muestra por pantalla el resultado de una apuesta simple ya resuelta */


void mostrar_resultado_apuesta_multiple(int mi_tipo,lista_dinamica *lista_resultados,float *mi_cantidad,
                                        float *ganancia, struct usuario *user);
/* Pre: mi_tipo es un tipo de resultado valido
        lista_resultados es una lista dinamica de identificadores de resultado
        id_res es un identificador valido de resultado
        mi_cantidad >= 0.0   ganancia >=0.0
	user es un usuario registrado
   Post: muestra por pantalla el resultado de una apuesta simple ya resuelta */


void mostrar_historico_global (struct usuario *user, float *balance, 
                               float *totalJuegos, float *gananciasJuegos,
			       float *gananciasOfertas);
/* Pre: --
   Post: muestra por pantalla el balance global de un usuario */


void mostrar_informe(tpInforme informe, int tipo, struct usuario *user);
/* Pre: informe debe corresponder a un informe economico correcto.
        Si tipo == MENSUAL, es un informe mensual y si tipo == GLOBAL
	es un informe global.
  Post: Muestra por pantalla el informe del tipo espeficado */	 


void pedir_datos_nuevos (tuplaUsuario *datos);
/* Pre: datos son datos validos de un usuario registrado
   Post: actualiza los datos que el usuario indica pidiendo unos nuevos */


void mostrar_listado_usuarios(lista_dinamica *lista, struct usuario *user);
/* Pre: --
   Post: muestra por pantalla un listado de todos los usuarios registrados junto con su
   fecha de ultimo login y la fecha de creacion de su cuenta */
