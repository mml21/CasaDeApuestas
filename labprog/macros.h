/* FICHERO DE MACROS
   AUTORES: Marcos Mainar, Ismael Saad y Jose Javier Colomer
   PROYECTO: Casa de Apuestas Laboratorio de Programacion.
   DESCRIPCION: Fichero en el que estan definidas constantes,
                variables globales, etc, que se utilizan desde
		varios modulos de la aplicacion */

 
 /* Acotaciones de longitud */
 
#define NAME_LEN 100
#define MAX_LEN 300
#define MAX_DESC_LEN 100
#define NICK_LEN 10
#define PASS_LEN 20
#define DIR_LEN 100
#define PREG_PRIVADA_LEN 100
#define RESP_PRIVADA_LEN 100
#define MAX_INFO_EVENTO 300
#define MAX_INFO_APUESTA 300
#define INFO_PROMO_LEN 100
#define NUM_DIGITOS_CC 20
#define DNI_LEN 9
#define CP_LEN 5
#define LOC_LEN 30
#define PAIS_LEN 30
#define MAIL_LEN 35
#define NAC_LEN 20
#define HOST_LEN 50
#define FECHA_LEN 11
#define FECHA_HORA_LEN 26
#define EQUIPO_LEN 30
#define PILOTO_LEN 30
#define CONTADOR_LEN 4
#define RIESGO_LEN 2
#define MAX_DURACION_EVENTOS 3

/* Divisas */

#define EURO 1
#define DOLAR 2


/* Idiomas */

#define ESP 0 
#define ING 1
#define ALE 2

/* Meses */

#define enero 1
#define febrero 2
#define marzo 3
#define abril 4
#define mayo 5
#define junio 6
#define julio 7
#define agosto 8
#define septiembre 9
#define octubre 10
#define noviembre 11
#define diciembre 12

/* Criterios de clasificacion de eventos  */

#define ev_pref_usuario 0                /* Segun preferencias usuario. */
#define ev_mas_recientes 1               /* De mas a menos recientes. */
#define ev_menos_recientes 2             /* De menos a mas recientes. */
#define ev_menos_populares 3             /* De menor a mayor popularidad. */
#define ev_mas_populares 4               /* De mayor a menor popularidad. */ 
#define ev_caducan_antes 5               /* Terminan antes */
#define ev_caducan_despues 6             /* Terminan despues */
#define ev_max_tope_apostable 7          /* Orden decreciente de tope de apuesta admitido */				                           

   
/* Criterios de clasificacion de apuestas */

#define ap_estandar 0                    /* Ordenacion estandar. */
#define ap_tipos 1                       /* Segun el tipo. */  
#define ap_mas_probable  2               /* Orden probabilistico (decreciente). */
#define ap_menos_probable 3              /* Orden probabilistico (creciente). */

/* Tipos de eventos */

#define FUTBOL 0
#define F1 1
#define SOCIAL 2
#define FUTBOL_F1 3
#define FUTBOL_SOCIAL 4
#define F1_SOCIAL 5 
#define TODOS 6

/* Otros */

#define NO 0
#define SI 1
#define INDIFERENTE 2
#define TRUE 1
#define FALSE 0
#define ERROR -1

/* Sexo */

#define MUJER 0
#define HOMBRE 1

/* Tipos de cabecera (se mantendra este convenio para tipos de usuario) */

#define principal 0
#define cliente 1
#define admin 2

/* Tipos de apuestas */

#define tp_apuesta_simple 0
#define tp_apuesta_combinada 1
#define tp_apuesta_sistema 2

/* Opciones de botones para el interfaz */
 
#define ARRIBA 65
#define ABAJO 66
#define DERECHA 67
#define IZQUIERDA 68
#define ENTER 10
#define FONDO_BOTON "rojo"
#define TEXTO_BOTON "azul"
#define FONDO_ILUMINADO "verde"
#define TEXTO_ILUMINADO "azul"
#define FONDO_NORMAL "negro"
#define TEXTO_NORMAL "blanco"
#define ANCHO_PANTALLA 125

/* Valores divisas */

#define EUROS_DOLAR 1.4663
#define DOLARES_EURO 0.682
#define EUROS_STRING "Euro"
#define DOLAR_STRING "Dolar"
#define EURO_SIMBOLO ""
#define DOLAR_SIMBOLO "$"

/* Tipos de juegos */

#define DADOS 0
#define RULETA 1
#define BLACKJACK 2
#define CARTA 3


/* Macros para semaforos */

#define csem()  sema_wait(&mutex)
#define lsem()  sema_post(&mutex)

/* Asesor */

#define MAX_RESULTADOS_EVENTO 50 /* Maximo numero de posibles resultados 
                                    asociados a un evento determinado */
#define MAX_RIESGO 20
#define MIN_RIESGO 0

/* Relaciones gastos-ranking */

#define cant_rank1  25
#define cant_rank2  50
#define cant_rank3  75
#define cant_rank4  100
#define cant_rank5  200
#define cant_rank6  350
#define cant_rank7  500
#define cant_rank8  750
#define cant_rank9  1000
#define cant_rank10 1500

/* Tipos de oferta */

#define NUM_OFERTAS 4
#define OF_REGALO_INICIAL 0
#define OF_REGALO_EFECTIVO 1
#define OF_PREMIADO_PERMANENCIA 2
#define OF_CUMPLEANYOS 3

/* Peticiones de preferencias */

#define EQUIPO 0
#define PILOTO 1
#define ESCUDERIA 2

/* Descripciones de ofertas */

#define DESC_OFERTA_REGALO_INICIAL  "\n\n\tOferta que ingresara un credito base a los usuarios como bienvenida."
#define DESC_OFERTA_REGALO_EFECTIVO "\n\n\tOferta que dara potestad al admin. de ingresar credito a los usuarios."
#define DESC_OFERTA_PREMIADO_PERMANENCIA "\n\n\tPremio para todos aquellos usuarios que cumplan su aniversario como clientes de Apostopolis."
#define DESC_OFERTA_CUMPLEANYOS "\n\n\tOferta de Apostopolis que permitira al usuario cumplir sus deseos el dia de su cumpleanyos"

/* Tipos de informes economicos */
#define MENSUAL 0
#define GLOBAL 1
