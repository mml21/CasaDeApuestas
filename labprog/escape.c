/* FUNCIONES CON SECUENCIAS DE ESCAPE
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer.
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero de definicion de funciones que trabajan
                con secuencias de escape */

# include <stdio.h>
# include "escape.h"
# include <string.h>


void limpiar_pantalla()

{
  printf("\x1b[2J");
}

void modo_normal() 

{

  printf("\x1b[0m");

}



void negrita() 

{

  printf("\x1b[1m");

}



void cursiva()

{

  printf("\x1b[3m");

}



void subrayado()

{
  
  printf("\x1b[4m");

}



void parpadeante()

{

  printf("\x1b[5m");

}



void inverso() 

{

  printf("\x1b[7m");

}



void no_negrita() 

{

  printf("\x1b[22m");

}



void no_cursiva()

{

  printf("\x1b[23m");

}



void no_subrayado()

{

  printf("\x1b[24m");

}



void no_parpadeante()

{

  printf("\x1b[25m");

}



void no_inverso()

{

  printf("\x1b[27m");

}



void color_texto(char * texto, char * fondo) 

{

  int colorTexto, colorFondo;
  


  if (!strcmp(texto,"blanco"))           colorTexto = 37;
  else if (!strcmp(texto,"negro"))       colorTexto = 30;
  else if (!strcmp(texto,"rojo"))        colorTexto = 31;
  else if (!strcmp(texto,"verde"))       colorTexto = 32; 
  else if (!strcmp(texto,"amarillo"))    colorTexto = 33;
  else if (!strcmp(texto,"azul"))        colorTexto = 34;
  else if (!strcmp(texto,"morado"))      colorTexto = 35;
  else if (!strcmp(texto,"cyan"))        colorTexto = 36;
  else colorTexto = 30;
  

  if (!strcmp(fondo,"gris"))        colorFondo = 47;
  else if (!strcmp(fondo,"negro"))  colorFondo = 40;
  else if (!strcmp(fondo,"rojo"))   colorFondo = 41;
  else if (!strcmp(fondo,"verde"))  colorFondo = 42;
  else if (!strcmp(fondo,"cafe"))   colorFondo = 43;
  else if (!strcmp(fondo,"azul"))   colorFondo = 44;
  else if (!strcmp(fondo,"morado")) colorFondo = 45;
  else if (!strcmp(fondo,"cyan"))   colorFondo = 46;
  else colorFondo = 40;
  
  
  printf("\x1b[%c%c;%c%cm",colorTexto/10+'0',colorTexto%10+'0',
                           colorFondo/10+'0',colorFondo%10+'0');
}


void posicionar_cursor (int x, int y)

{

printf("\x1b[%d;%dH",y,x);

}


void poner_cuadro(int sup_izqx, int sup_izqy, char *texto)

{

  int longitud, i;

  posicionar_cursor(sup_izqx,sup_izqy);
  longitud = strlen(texto);
  for(i=1;i<=longitud+6;i++) putchar(' ');
  posicionar_cursor(sup_izqx,sup_izqy+1);
  printf("   %s   ",texto);
  posicionar_cursor(sup_izqx,sup_izqy+2);
  for(i=1;i<=longitud+6;i++) putchar(' ');
  fflush(stdout);
}
