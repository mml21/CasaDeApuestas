/* @creaBD.sql */
/* Crea la base de datos de la Casa de Apuestas */


/* Crear las tablas y añadir algunas restricciones, de varias maneras */


CREATE TABLE Administrador (
  nickAdmin         VARCHAR2(10)   CONSTRAINT  nickAdmin_PK            PRIMARY KEY,
  DNI               VARCHAR2(9)    CONSTRAINT  DNIA_UN                 UNIQUE
                                   CONSTRAINT  DNIA_NN                 NOT NULL,
  nombreApell       VARCHAR2(50)   CONSTRAINT  nombreApellA_NN         NOT NULL,
  sexo              number(1)      CONSTRAINT  sexoA_NN                NOT NULL,
  direccion         VARCHAR2(100)  CONSTRAINT  direccionA_NN           NOT NULL,       
  CP                VARCHAR2(5)    CONSTRAINT  CPA_NN                  NOT NULL, 
  localidad         VARCHAR2(30)   CONSTRAINT  localidadA_NN           NOT NULL,
  pais              VARCHAR2(30)   CONSTRAINT  paisA_NN                NOT NULL,
  fechaNac          date           CONSTRAINT  fechaNacA_NN            NOT NULL,
  email             VARCHAR2(35)   CONSTRAINT  emailA_NN               NOT NULL,
  preguntaPrivada   VARCHAR2(100)  CONSTRAINT  preguntaPrivadaA_NN     NOT NULL,
  respuestaPrivada  VARCHAR2(100)  CONSTRAINT  respuestaPrivadaA_NN    NOT NULL,
  pass              VARCHAR2(20)   CONSTRAINT  passA_NN                NOT NULL,
  idioma            number(1)      CONSTRAINT  idiomaA_NN              NOT NULL,
  nacionalidad      VARCHAR2(20)   CONSTRAINT  nacionalidadA_NN        NOT NULL,
  fechaCreacion     date           CONSTRAINT  fechaCreacionA_NN       NOT NULL,
  fechaUltLogin     date           CONSTRAINT  fechaUltLoginA_NN       NOT NULL);



CREATE TABLE Usuario (
  nickUser          VARCHAR2(10)   CONSTRAINT  nickUser_PK         PRIMARY KEY,
  DNI               VARCHAR2(9)    CONSTRAINT  DNI_UN                 UNIQUE
                                   CONSTRAINT  DNI_NN                 NOT NULL,
  nombreApell       VARCHAR2(50)   CONSTRAINT  nombreApell_NN         NOT NULL,
  sexo              number(1)      CONSTRAINT  sexo_NN                NOT NULL,
  direccion         VARCHAR2(100)  CONSTRAINT  direccion_NN           NOT NULL,       
  CP                VARCHAR2(5)    CONSTRAINT  CP_NN                  NOT NULL, 
  localidad         VARCHAR2(30)   CONSTRAINT  localidad_NN           NOT NULL,
  pais              VARCHAR2(30)   CONSTRAINT  pais_NN                NOT NULL,
  fechaNac          date           CONSTRAINT  fechaNac_NN            NOT NULL,
  email             VARCHAR2(35)   CONSTRAINT  email_NN               NOT NULL,
  preguntaPrivada   VARCHAR2(100)  CONSTRAINT  preguntaPrivada_NN     NOT NULL,
  respuestaPrivada  VARCHAR2(100)  CONSTRAINT  respuestaPrivada_NN    NOT NULL,
  pass              VARCHAR2(20)   CONSTRAINT  pass_NN                NOT NULL,
  divisa            number(1)      CONSTRAINT  divisa_NN              NOT NULL,
  idioma            number(1)      CONSTRAINT  idioma_NN              NOT NULL,
  nacionalidad      VARCHAR2(20)   CONSTRAINT  nacionalidad_NN        NOT NULL,
  fechaCreacion     date           CONSTRAINT  fechaCreacion_NN       NOT NULL,
  fechaUltLogin     date           CONSTRAINT  fechaUltLogin_NN       NOT NULL,
  gananciasJuegos   number(9,2)    CONSTRAINT  gananciasJuego_NN      NOT NULL,
  gananciasOfertas  number(9,2)    CONSTRAINT  gananaciasOfertas_NN   NOT NULL,
  gananciasTotales  number(9,2)    CONSTRAINT  gananciasTotales_NN    NOT NULL,
  totalJuegos       number(9,2)    CONSTRAINT  totalJuegos_NN         NOT NULL,
  dadoAlta          number(1)      CONSTRAINT  dadoAlta_NN            NOT NULL,
  credito           number(7,2)    CONSTRAINT  credito_NN             NOT NULL,
  ranking           number(2)      CONSTRAINT  ranking_NN             NOT NULL);
  

CREATE TABLE Evento (
  idEvento          number(7)       CONSTRAINT idEvento_PK            PRIMARY KEY,
  nickAdmin         VARCHAR2(10),
  descripcion       VARCHAR2(100)   CONSTRAINT descripcion_NN         NOT NULL, 
  fechaIntroduccion date            CONSTRAINT fechaIntroduccion_NN   NOT NULL,
  tipoEvento        number(1)       CONSTRAINT tipoEvento_NN          NOT NULL,
  popularidad       number(2)       CONSTRAINT popularidad_NN         NOT NULL,
  haSucedido        number(1)       CONSTRAINT haSucedido_NN          NOT NULL,
  maxApostable      number(7,2)     CONSTRAINT maxApostable_NN        NOT NULL,
  fechaInicio       date            CONSTRAINT fechaInicio_NN            NOT NULL,
  CONSTRAINT        nickAdmin_FK  FOREIGN KEY (nickAdmin) REFERENCES 
    Administrador(nickAdmin) ON DELETE SET NULL);


CREATE TABLE Resultado (
  idPosResul        number(3),
  idEvento          number(7)    CONSTRAINT idEvento_NN            NOT NULL,
  infoResul         VARCHAR2(100) CONSTRAINT infoResul_NN           NOT NULL,
  cotizacion        number(7,2)  CONSTRAINT cotizacion_NN          NOT NULL,
  haOcurrido        number(1)    CONSTRAINT haOcurrido_NN          NOT NULL,
  CONSTRAINT        Resultado_PK PRIMARY KEY (idPosResul, idEvento),
  CONSTRAINT        idEvento_FK  FOREIGN KEY (idEvento) REFERENCES Evento(idEvento) ON DELETE CASCADE,
  CONSTRAINT        cotizacionPositiva CHECK (cotizacion > 0) );


CREATE TABLE Apuesta (
  idApuesta         number(7),
  nickUser          VARCHAR2(10),
  fecha             date            CONSTRAINT  fecha_NN               NOT NULL,
  cantidad          number(7,2)     CONSTRAINT  cantidad_NN            NOT NULL,
  tipo              number(1)       CONSTRAINT  tipo_NN                NOT NULL,
  combinadas        number(1)       CONSTRAINT combinadas_NN           NOT NULL,	
  CONSTRAINT        Apuesta_PK      PRIMARY KEY (idApuesta, nickUser),
  CONSTRAINT        nickUser_FK  FOREIGN KEY (nickUser) REFERENCES 
    Usuario(nickUser) ON DELETE CASCADE, 
  CONSTRAINT        apuestaPositiva  CHECK (cantidad > 0) );


CREATE TABLE PreverResul (
  nickUser   VARCHAR2(10),
  idApuesta     number(7),
  idPosResul    number(3),
  idEvento      number(7),
  CONSTRAINT    PreverResul_PK       PRIMARY KEY  (nickUser, idApuesta, idPosResul, idEvento),
  CONSTRAINT    idApuestaNickJug_FK  FOREIGN KEY (idApuesta, nickUser)  
    REFERENCES Apuesta(idApuesta,nickUser) ON DELETE CASCADE,
  CONSTRAINT    idPosResulEvento_FK  FOREIGN KEY (idPosResul, idEvento) 
    REFERENCES Resultado(idPosResul, idEvento) ON DELETE CASCADE);


CREATE TABLE Informe (
  fecha             date               CONSTRAINT fecha_PK               PRIMARY KEY,
  ingresosApuestas  number(9,2)        CONSTRAINT ingrAp_NN              NOT NULL,
  perdidasApuestas  number(9,2)        CONSTRAINT perdAp_NN              NOT NULL,
  ingresosJuegos    number(9,2)        CONSTRAINT ingrJueg_NN            NOT NULL,
  perdidasJuegos    number(9,2)        CONSTRAINT perdJueg_NN            NOT NULL,
  perdidasOfertas   number(9,2)        CONSTRAINT perdOf_NN              NOT NULL);


CREATE TABLE Promocion (
  idPromocion    number(7)             CONSTRAINT idPromocion_PK         PRIMARY KEY,
  nickAdmin      VARCHAR2(10),  
  infoPromo      VARCHAR2(100)       CONSTRAINT infoPromo_NN           NOT NULL,
  rankingPromo   number(2)             CONSTRAINT rankingPromo_NN        NOT NULL,
  CONSTRAINT     nickAdminPromo_FK  FOREIGN KEY (nickAdmin) REFERENCES 
    Administrador(nickAdmin) ON DELETE SET NULL);


CREATE TABLE DirigirPromo (
  idPromocion   number(7),
  nickUser      VARCHAR2(10),
  fechaPromo    date                   CONSTRAINT    fechaPromo_NN NOT NULL,
  CONSTRAINT    DirigirPromo_PK        PRIMARY KEY   (idPromocion, nickUser),
  CONSTRAINT    idPromocion_FK         FOREIGN KEY   (idPromocion)  REFERENCES 
    Promocion(idPromocion) ON DELETE CASCADE,
  CONSTRAINT    nickUserPromo_FK    FOREIGN KEY   (nickUser)  REFERENCES     
     Usuario(nickUser)  ON DELETE CASCADE);
     
  
CREATE TABLE PreferenciasUsuario (
  nickUser  VARCHAR2(10),
  riesgo    number(2)                CONSTRAINT riesgo_NN NOT NULL,
  gustaFutbol number(1)              CONSTRAINT gustaFutbol_NN NOT NULL,
  gustaF1     number(1)              CONSTRAINT gustaF1_NN NOT NULL,
  gustaSocial number(1)              CONSTRAINT gustaSocial_NN NOT NULL,
  numApuestasFutbol   number(4)      CONSTRAINT numApuestasFutbol_NN NOT NULL,
  numApuestasF1       number(4)      CONSTRAINT numApuestasF1_NN NOT NULL,
  numApuestasSocial   number(4)      CONSTRAINT numApuestasSocial_NN NOT NULL,
  numVecesRuleta      number(4)      CONSTRAINT numVecesRuleta_NN NOT NULL,
  numVecesDados       number(4)      CONSTRAINT numVecesDados_NN NOT NULL,
  numVecesCarta       number(4)      CONSTRAINT numVecesCarta_NN NOT NULL,
  numVecesBlackJack   number(4)      CONSTRAINT numVecesBlackJack_NN NOT NULL,
  numApuestasArriesgadas number(4)   CONSTRAINT numApuestasArriesgadas_NN NOT NULL,
  numApuestasConservadoras number(4) CONSTRAINT numApuestasConservadoras_NN NOT NULL,
  numApuestasSimples       number(4) CONSTRAINT numApuestasSimples_NN NOT NULL,
  numApuestasCombinadas    number(4) CONSTRAINT numApuestasCombinadas_NN NOT NULL,
  numApuestasSistema	   number(4) CONSTRAINT numApuestasSistema_NN NOT NULL,
  equipoFutbol1  VARCHAR2(30),
  equipoFutbol2  VARCHAR2(30),
  equipoFutbol3  VARCHAR2(30),
  piloto1F1      VARCHAR2(30),
  piloto2F1      VARCHAR2(30),
  piloto3F1      VARCHAR2(30),
  escuderia1F1   VARCHAR2(30),
  escuderia2F1   VARCHAR2(30),
  escuderia3F1   VARCHAR2(30),
  CONSTRAINT PreferenciasUsuario_PK PRIMARY KEY(nickUser),
  CONSTRAINT PreferenciasUsuario_FK FOREIGN KEY(nickUser) REFERENCES
    Usuario(nickUser) ON DELETE CASCADE);

  
