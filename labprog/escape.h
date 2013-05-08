/* FUNCIONES CON SECUENCIAS DE ESCAPE
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de declaracion de funciones que trabajan
                con secuencias de escape */


#include <stdio.h>

/* Estas funciones trabajan con secuencias de escape
   y a partir de su uso el texto se muestra por
   pantalla de la manera especificada */

void limpiar_pantalla();
void modo_normal();
void negrita();
void cursiva();
void subrayado();
void parpadeante();
void inverso();
void no_negrita();
void no_cursiva();
void no_subrayado();
void no_parpadeante();
void no_inverso();
void color_texto(char * texto, char * fondo);
void posicionar_cursor(int x, int y);
void poner_cuadro(int sup_izqx, int sup_izqy, char *texto);
