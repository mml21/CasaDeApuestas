/* MODULO DE DEFINICION DE TIPOS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero con definiciones de tipos de datos
                que se utilizan en varios modulos de la
                aplicacion. 
*/
   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>
#include <sqlca.h>
#include <oraca.h>
#include "macros.h"
#include "dinam.h"


/* Estructura para el interfaz y el principal */

struct usuario
{
  char nick[NICK_LEN];
  int tipo_user;
  /* Los siguiente campos solo tendran valor definido en caso de que
     tipo_user tenga el valor de usuario, para administrador
     tendran valor indefinido */
  float saldo; /* El saldo siempre sera en euros, si la divisa es dolares,
                para las operaciones de interaccion con el usuario
                se le mostrara con la conversion adecuada. */
  int divisa;
};


/* Estructura o registro que contiene todos los atributos o columnas 
   de la tabla Usuario */

typedef struct {
   VARCHAR   nickUser[NICK_LEN];
   VARCHAR   DNI[DNI_LEN];
   VARCHAR   nombreApell[NAME_LEN];
   int       sexo;
   VARCHAR   direccion[DIR_LEN];
   VARCHAR   CP[CP_LEN];
   VARCHAR   localidad[LOC_LEN];
   VARCHAR   pais[PAIS_LEN];
   VARCHAR   fechaNac[FECHA_LEN];
   VARCHAR   email[MAIL_LEN];
   VARCHAR   preguntaPrivada[PREG_PRIVADA_LEN];
   VARCHAR   respuestaPrivada[RESP_PRIVADA_LEN];
   VARCHAR   pass[PASS_LEN];
   int       divisa;
   int       idioma;
   VARCHAR   nacionalidad[NAC_LEN];
   VARCHAR   fechaCreacion[FECHA_LEN];
   VARCHAR   fechaUltLogin[FECHA_HORA_LEN];
   float     gananciasJuegos;
   float     gananciasOfertas;
   float     gananciasTotales;
   float     totalJuegos;
   int       dadoAlta ;
   float     credito;
   int       ranking;
} tuplaUsuario;


/* Estructura o registro que contiene todos los atributos o columnas 
   de la tabla Evento */
 
typedef struct
{
  int        idEvento;                           /* Identificador */
  VARCHAR    nickAdmin[NICK_LEN];                /* Introductor */
  VARCHAR    descripcion[MAX_DESC_LEN];          /* Nombre */
  char       fechaIntroduccion[FECHA_HORA_LEN];  /* Fecha de introduccion */ 
  int        tipoEvento;                         /* Tipo */
  int        popularidad;                        /* Popularidad */
  int        haSucedido;                         /* Indicador de vigencia */ 
  float      maxApostable;                       /* Maxima apuesta admitida */
  char       fechaInicio[FECHA_HORA_LEN];        /* Fecha de fin de admision 
                                                                de apuestas */
} tuplaEvento;


/* Estructura o registro que contiene todos los atributos o columnas 
   de la tabla Resultado */

typedef struct 
{ 
  int            idPosResul;                /* Identificador posible resultado */
  int            idEvento;                  /* Identificador evento */
  VARCHAR       infoResul[NAME_LEN];       /* Informacion relevante */
  float          cotizacion;               /* Cotizacion asociada */
  int            haOcurrido;               /* Indicador de acierto */
} tuplaResul;


struct apuesta
{
      int id;                        /* Identificador de apuesta */
      int id_ev;                     /* Identificador evento */
      int id_res;                    /* Identificador posible resultado */
      int tipo;                      /* Tipo de apuesta */
      int combinadas;                /* Para apuestas combinadas */
};

/* Estructura para almacenar información de las apuestas */

struct info_apuesta
{
   int id;                          /* Identificador de apuesta */
   VARCHAR desc_ev[200];            /* Descripcion del evento */
   VARCHAR fecha_fin[FECHA_LEN];    /* Fecha de fin del evento */
   VARCHAR fecha_ap[FECHA_LEN];     /* Fecha de la apuesta */
   float cantidad;                  /* Cantidad apostada */
   int tipo;                        /* Tipo de apuesta */
   int combinadas;                  /* Para apuestas combinadas */
   int id_resultado;                /* Identificador posible resultado */
};


/* Estructura que almacena el perfil del usuario */


typedef struct 
{
  VARCHAR  nickUser[NICK_LEN];
  int riesgo; /* Todos los usuarios comienzan con riesgo = 10 y va de 0 a 20 */
  int gustaFutbol;
  int gustaF1;
  int gustaSocial;
  int numApuestasFutbol;
  int numApuestasF1;
  int numApuestasSocial;
  int numVecesRuleta;
  int numVecesDados;
  int numVecesCarta;
  int numVecesBlackJack;
  int numApuestasArriesgadas;
  int numApuestasConservadoras;
  int numApuestasSimples;
  int numApuestasCombinadas;
  int numApuestasSistema;  
  VARCHAR equipoFutbol1[EQUIPO_LEN];  /* A partir de este, atributos opcionales */
  VARCHAR equipoFutbol2[EQUIPO_LEN];
  VARCHAR equipoFutbol3[EQUIPO_LEN];
  VARCHAR piloto1F1[PILOTO_LEN];    
  VARCHAR piloto2F1[PILOTO_LEN];    
  VARCHAR piloto3F1[PILOTO_LEN];       
  VARCHAR escuderia1F1[EQUIPO_LEN];
  VARCHAR escuderia2F1[EQUIPO_LEN];
  VARCHAR escuderia3F1[EQUIPO_LEN];
} perfilUsuario;


/* Registro indicador de nulos para las consultas con el registro anterior */

typedef struct 
{
  short nickUser[NICK_LEN];
  short riesgo; /* Todos los usuarios comienzan con riesgo = 10 y va de 0 a 20 */
  short gustaFutbol;
  short gustaF1;
  short gustaSocial;
  short numApuestasFutbol;
  short numApuestasF1;
  short numApuestasSocial;
  short numVecesRuleta;
  short numVecesDados;
  short numVecesCarta;
  short numVecesBlackJack;
  short numApuestasArriesgadas;
  short numApuestasConservadoras;
  short numApuestasSimples;
  short numApuestasCombinadas;
  short numApuestasSistema;  
  short equipoFutbol1;  /* A partir de este, atributos opcionales */
  short equipoFutbol2;
  short equipoFutbol3;
  short piloto1F1;    
  short piloto2F1;    
  short piloto3F1;       
  short escuderia1F1;
  short escuderia2F1;
  short escuderia3F1;
} perfilUsuarioInd;


/* Tipos de datos de Promociones */

typedef struct
{
  int idPromocion;  /* Identificador de la promocion */
  VARCHAR nickAdmin[NICK_LEN]; /* Nick del administrador que efectua la promocion */
  VARCHAR infoPromo[INFO_PROMO_LEN]; /* Informacion acerca de la promocion */
  int rankingPromo; /* Ranking al que corresponde la promocion */
} oferta;  


typedef struct
{
   int      idPromocion;  /* Identificador de la promocion */
   VARCHAR  nickUser[NICK_LEN]; /* Nick del usuario que recibe la promocion */
   char     fechaPromo[FECHA_LEN];  /* Fecha de la promocion */
} tuplaDirigirPromo;


/* Tipos de datos de los juegos */


struct tpResulRuleta {
   int   numero; /* Del 0 al 36 */
   char  color; 
   /* R para rojo, N para negro, NULL para ninguno (caso del 0) */
};


typedef int tpCarta;
/* 0-11 = diamantes
  12-23 = corazones
  24-35 = treboles
  36-47 = picas */


/* Tipos para los datos economicos de los juegos */

typedef struct
{
  float gananciasJuegos, totalJuegos;  
} datosJuegos;


/* Estructura de datos para el Asesor */

typedef struct 
{
  VARCHAR infoResul[NAME_LEN];   /* Informacion relevante del resultado */
  int idResul, idEvento;  /* Identificadores del resultado y del evento */
  float invcuota, p; /* p es la probabilidad del resultado, 
                        invcuota el inverso de la cotizacion o cuota
                        del resultado */
} resulProb; 


/* Tupla de contabilidad */

typedef struct
{
  int          idApuesta;         /* Identificador de la apuesta */
  float        cantidad;          /* Cantidad apostada */
  float        cotizacion;        /* Cotizacion asociada al posible resultado */
  int          haOcurrido;        /* Indicador de acontecimiento del evento */
  int          combinadas;        /* Indicador del sistema de apuesta escogido */
} tupla_contabilidad;


/* Los informes economicos se generan mensualmente y
   sus datos corresponden unicamente al mes y año de
   la fecha especificada. */

typedef struct 
{
  VARCHAR fecha[FECHA_LEN]; 
  float ingresosApuestas;
  float perdidasApuestas;
  float ingresosJuegos;
  float perdidasJuegos;
  float perdidasOfertas;
} tpInforme;


/* Datos para el listado de los usuarios */

typedef struct
{
  VARCHAR nick[NICK_LEN];
  VARCHAR fechaCreacion[FECHA_LEN];
  VARCHAR fechaUltLogin[FECHA_HORA_LEN];
} datos_listado;
