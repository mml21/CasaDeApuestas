# Macros

CC      = gcc
PROC    = proc
PROG    = principal parser
INCS    = -I/usr/local/oracle/app/oracle/product/8.1.6/precomp/public 
LDFLAGS = -L/usr/local/oracle/app/oracle/product/8.1.6/precomp/public \
                /usr/local/oracle/app/oracle/product/8.1.6/lib/libclntsh.so 
SRCS_C = parser.c interfaz.c gestion_eventos.c gestion_usuarios.c realizar_apuestas.c principal.c gestion_interna.c asesor.c juegos.c promociones.c informes.c

# Reglas

todo: parser principal

parser: parser.c parser.o interfaz.o escape.o dinam.o gestion_eventos.o gestion_usuarios.o gestion_interna.o realizar_apuestas.o macros.h
	$(CC) $(INCS) $(LDFLAGS) dinam.o interfaz.o escape.o gestion_eventos.o gestion_usuarios.o realizar_apuestas.o gestion_interna.o parser.c -o parser

principal: principal.c escape.o gestion_eventos.o realizar_apuestas.o interfaz.o gestion_usuarios.o dinam.o tipos.h gestion_interna.o juegos.o asesor.o macros.h promociones.o informes.o
	$(CC) $(INCS) $(LDFLAGS) dinam.o escape.o interfaz.o gestion_usuarios.o gestion_eventos.o realizar_apuestas.o gestion_interna.o juegos.o asesor.o promociones.o informes.o principal.c -o principal

principal.c: principal.pc
	$(PROC) principal.pc

informes.c: informes.pc
	$(PROC) informes.pc

informes.o: informes.c informes.h promociones.o promociones.h
	$(CC) $(INCS) -c informes.c
	
promociones.c: promociones.pc
	 $(PROC) promociones.pc	
	 	
promociones.o: promociones.c promociones.h juegos.h juegos.o
	$(CC) $(INCS) -c promociones.c	
	
juegos.o: juegos.c juegos.h asesor.h asesor.o
	$(CC) $(INCS) -c juegos.c

juegos.c: juegos.pc
	$(PROC) juegos.pc
	
asesor.o: asesor.c asesor.h gestion_eventos.h gestion_eventos.o
	$(CC) $(INCS) -c asesor.c
	
asesor.c: asesor.pc
	$(PROC) asesor.pc

gestion_eventos.o: gestion_eventos.c gestion_eventos.h gestion_interna.h gestion_interna.o
	$(CC) $(INCS) -c gestion_eventos.c

gestion_eventos.c: gestion_eventos.pc
	$(PROC) gestion_eventos.pc	
		
gestion_interna.o: gestion_interna.c gestion_interna.h realizar_apuestas.h realizar_apuestas.o
	$(CC) $(INCS) -c gestion_interna.c
	
gestion_interna.c: gestion_interna.pc
	$(PROC) gestion_interna.pc

realizar_apuestas.o: realizar_apuestas.c realizar_apuestas.h interfaz.h interfaz.o
	$(CC) $(INCS) -c realizar_apuestas.c

realizar_apuestas.c: realizar_apuestas.pc
	$(PROC) realizar_apuestas.pc

interfaz.o: interfaz.c interfaz.h gestion_usuarios.h gestion_usuarios.o
	$(CC) $(INCS) -c interfaz.c

interfaz.c: interfaz.pc
	$(PROC) interfaz.pc
	
gestion_usuarios.o: gestion_usuarios.c tipos.h
	$(CC) $(INCS) -c gestion_usuarios.c

gestion_usuarios.c: gestion_usuarios.pc
	$(PROC) gestion_usuarios.pc
	
escape.o: escape.c
	$(CC) $(INCS) -c escape.c
	
dinam.o: dinam.c
	$(CC) $(INCS) -c dinam.c

parser.o: parser.c
	$(CC) $(INCS) -c parser.c
	
parser.c: parser.pc
	$(PROC) parser.pc
	
clean:
	@echo "Borrando archivos objeto, los .c adecuados y ejecutables"
	rm -f core $(PROG) $(SRCS_C) *.o 
	@echo "Borrado finalizado"
	
