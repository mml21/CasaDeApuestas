/* @elimBD.sql */
/* Elimina la base de datos de la Casa de Apuestas */

SET ECHO ON


/* Elimina todos los datos almacenados en las tablas */


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


/* Elimina todas las restricciones ligadas a las tablas, del tal
   forma que solo se borre una tabla cuando sus atributos no son
   referenciados */

ALTER TABLE Usuario DROP CONSTRAINT DNI_UN;
ALTER TABLE Apuesta    DROP CONSTRAINT nickUser_FK;
ALTER TABLE Evento     DROP CONSTRAINT nickAdmin_FK;
ALTER TABLE Resultado DROP CONSTRAINT idEvento_FK;
ALTER TABLE PreverResul DROP CONSTRAINT idApuestaNickJug_FK;
ALTER TABLE PreverResul  DROP CONSTRAINT idPosResulEvento_FK;
ALTER TABLE Promocion  DROP CONSTRAINT nickAdminPromo_FK;
ALTER TABLE DirigirPromo DROP CONSTRAINT idPromocion_FK;
ALTER TABLE Apuesta DROP CONSTRAINT apuestaPositiva;
ALTER TABLE Resultado DROP CONSTRAINT cotizacionPositiva;
ALTER TABLE PreferenciasUsuario DROP CONSTRAINT PreferenciasUsuario_FK;

/* Elimina todas las tablas */


DROP TABLE Administrador CASCADE CONSTRAINTS;
DROP TABLE Usuario CASCADE CONSTRAINTS;
DROP TABLE Evento CASCADE CONSTRAINTS;
DROP TABLE Resultado CASCADE CONSTRAINTS;
DROP TABLE Apuesta CASCADE CONSTRAINTS;
DROP TABLE Informe CASCADE CONSTRAINTS;
DROP TABLE Promocion CASCADE CONSTRAINTS;
DROP TABLE PreverResul CASCADE CONSTRAINTS;
DROP TABLE DirigirPromo CASCADE CONSTRAINTS;
DROP TABLE PreferenciasUsuario CASCADE CONSTRAINTS;

SELECT * FROM cat;


