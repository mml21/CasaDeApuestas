/* @elimDatBD.sql */
/* Elimina los datos de la BD de la Casa de Apuestas */

SET ECHO ON


/* Elimina los datos almacenados en las tablas */


DELETE FROM Administrador;
DELETE FROM Usuario;
DELETE FROM Evento;
DELETE FROM Resultado;
DELETE FROM Apuesta;
DELETE FROM Informe;
DELETE FROM Promocion;
DELETE FROM PreverResul;
DELETE FROM DirigirPromo;
DELETE FROM PreferenciasUsuario;
