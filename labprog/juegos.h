/* MODULO DE JUEGOS EN TIEMPO REAL
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion del modulo de juegos */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include "macros.h"
#include "escape.h"

EXEC SQL INCLUDE asesor;


/* Definicion de tipos de datos para los juegos de cartas */

#define TAMBARAJA 48
#define PUNTUACION_MAX 21

typedef struct tpBaraja
{
  int naipe[TAMBARAJA];
  /* Numero de naipes empleados */
  int repartidos;
}tpBaraja;

typedef struct tpJugador
{
  int naipe[TAMBARAJA];  /* Almacena las cartas del jugador */
  int puntuacion; /* Numero de puntos totales del jugador */
  int numCartas; /* Numero de cartas en mano del jugador */
}tpJugador;



/* Operaciones basicas del modulo: */

void jugarCartaMasAlta (struct usuario *user, perfilUsuario *perfil, int opcion, datosJuegos *datos);
/* Pre: user debe corresponder a un usuario registrado en la Casa de Apuestas.
   Post: Interacciona con el usuario para permitirle jugar a la carta mas alta.
         Ademas actualiza los datos economicos del usuario referentes a los juegos. 
*/


int jugarDados (struct usuario *user, perfilUsuario *perfil, int opcion, datosJuegos *datos);
/* Pre: user debe corresponder a un usuario registrado en la Casa de Apuestas.
   Post: Interacciona con el usuario para permitirle jugar a los dados.
         Ademas actualiza los datos economicos del usuario referentes a los juegos.  
*/


void jugarRuleta (struct usuario *user, perfilUsuario *perfil, int opcion, datosJuegos *datos);
/* Pre: user debe corresponder a un usuario registrado en la Casa de Apuestas.
   Post: Interacciona con el usuario para permitirle jugar a la ruleta.
         Ademas actualiza los datos economicos del usuario referentes a los juegos. 
*/


void tirarDados (int *dado1, int *dado2, int *resultado);
/* Pre: --
   Post: Simula los resultados de ambos dados y los devuelve en dado1,
         dado2. Resultado contiene la suma de los resultados de ambos
         dados. Devuelve -1 si ha ocurrido algún tipo de error 
*/

   
void moverRuleta (struct tpResulRuleta *resultado );
/* Pre: --
   Post: Simula un lanzamiento de la bola de la ruleta y devuelve
         en resultado el numero que ha salido y su color correspondiente. 
*/
   
   
void sacarCarta (tpCarta *carta);
/* Pre: --
   Post: Saca una carta de la baraja entre 1 y 12 sin importar el palo,
   para el juego de la carta mas alta 
*/
   

/* Funciones y procedimientos del juego BlackJack */ 


void barajar(tpBaraja *baraja);
/* Pre: --
   Post: Baraja las cartas para empezar a jugar al BlackJack 
*/


int valor_carta(int cartas, int total, int mostrar);
/* Pre: --
   Post: Devuelve el total de puntos de un jugador en el juego
         del BlackJack a partir del numero de carta (cartas) y 
         del antiguo valor total de puntos del jugador (total).
         Ademas si mostrar = 1, muestra por pantalla la carta en
         modo texto. 
*/


int coger_carta(tpBaraja *baraja, tpJugador *jugador, int mostrar);
/* Pre: --
   Post: Toma una carta de la baraja, se la asigna al jugador y calcula
         su nueva puntuacion. Si mostrar = 1, mostrara por pantalla
	 la carta en modo texto. 
*/


void jugarBlackJack (struct usuario *user, perfilUsuario *perfil, int opcion, datosJuegos *datos);
/* Pre: --
   Post: Interacciona con el usuario para permitirle jugar al BlackJack.
         Ademas actualiza los datos economicos del usuario referentes a los juegos.  
*/


/* Estos 4 procedimientos muestran por pantalla en modo texto
   la carta correspondiente a partir de su numero. Se usan en funcion
   del palo de la carta. */

void diamantes(int numero);
void picas(int numero);
void treboles(int numero);
void corazones(int numero);


