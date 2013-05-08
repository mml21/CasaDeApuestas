/* @ponDatBD.sql */


/* Introduce algunos datos de prueba en la BD de la Casa de Apuestas */


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


INSERT INTO Administrador VALUES ('admin','12345678B','Apostopolis admin',
                            1,'Avda. Hola','50004','Zaragoza','España',
			    to_date('18-3-1974', 'DD-MM-YYYY'),
			    'jj.colomer@gmail.com', 'nombre de mi perro?', 
			    'jsr', '1234567', 1,'Española',
			    to_date(sysdate, 'DD-MM-YY'), 
			    to_date(sysdate, 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Usuario VALUES ('BloOdHooD','11111111B','Marcos Mainar',
                            1,'Avda. Hola','50004','Zaragoza','España',
			    to_date('17-6-1987', 'DD-MM-YYYY'),
			    'marcosmainar@gmail.com', 'nombre de mi perro?', 
			    'jsr', '1234567', 1, 0,'Española',
			    to_date(sysdate, 'DD-MM-YY'), 
			    to_date(sysdate, 'DD-MM-YY HH24:MI:SS'),
			    0,0,0,0,1,5000,0);
			    
INSERT INTO PreferenciasUsuario VALUES ('BloOdHooD',10,1,1,1,0,0,0,
			    0,0,0,0,0,0,0,0,0, 'Zaragoza',NULL,
			    NULL, 'Alonso', NULL, NULL,'Renault',NULL,
			    NULL);		
			  				    
			    			    				    				    	  
INSERT INTO Usuario VALUES ('Orlgaun','12345678A','Jose Javier Colomer',
                            1,'Avda. Hola','50004','Zaragoza','España',
			    to_date('27-8-1987', 'DD-MM-YYYY'),
			    'jj.colomer@gmail.com', 'nombre de mi perro?', 
			    'jsr', '1234567', 1, 0,'Española',
			    to_date(sysdate, 'DD-MM-YY'), 
			    to_date(sysdate, 'DD-MM-YY HH24:MI:SS'),
			    0,0,0,0,1,1000,0);
			    
INSERT INTO PreferenciasUsuario VALUES ('Orlgaun',10,1,1,1,0,0,0,
			    0,0,0,0,0,0,0,0,0, 'Zaragoza','Barcelona',
			    'Madrid', 'Alonso', 'Hamilton', 'Raikkonen','McLaren','Renault',			 
			    'Ferrari');				    


INSERT INTO Usuario VALUES ('Blazer','12345678C','Ismael Saad',
                            1,'Avda. Hola','50004','Zaragoza','España',
			    to_date('17-8-1987', 'DD-MM-YYYY'),
			    'isma.saad@gmail.com', 'nombre de mi perro?', 
			    'jsr', '1234567', 1, 0,'Española',
			    to_date(sysdate, 'DD-MM-YY'), 
			    to_date(sysdate, 'DD-MM-YY HH24:MI:SS'),
			    0,0,0,0,1,1000,0);
			    
INSERT INTO PreferenciasUsuario VALUES ('Blazer',10,1,1,1,0,0,0,
			    0,0,0,0, 0, 0,0,0,0, 'Barcelona',NULL,
			    NULL, NULL, NULL, NULL,NULL,NULL,
			    NULL);			    

INSERT INTO Evento  VALUES (1, 'admin', 'Real Madrid vs Barcelona',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('7-5-08 20:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (2, 'admin', 'Que piloto ganara el mundial 2008?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('20-2-08 16:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (3, 'admin', 'Que escuderia ganara el mundial de F1 2008?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('20-2-08 16:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (4, 'admin', 'Que partido ganara las elecciones espanyolas de Marzo de 2008?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 2, 10, 0, 1000,
  to_date('9-3-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (5, 'admin', 'Que partido ganara las elecciones en EEUU de Noviembre de 2008?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 2, 10, 0, 1000,
  to_date('4-11-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (6, 'admin', 'Que partido ganara las elecciones de Mayo de 2008 en el Reino Unido?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 2, 10, 0, 1000,
  to_date('5-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (7, 'admin', 'Que piloto abandonara primero en la primera carrera de F1 de 2008?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('5-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (8, 'admin', 'Quien ganara la Eurocopa 2008? (se disputara en Austria y Suiza)',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (9, 'admin', 'Quien ganara la Champions League 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
 
INSERT INTO Evento  VALUES (10, 'admin', 'Quien ganara la Liga 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (11, 'admin', 'Quien ganara la Premier (Liga Inglesa) 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (12, 'admin', 'Quien ganara la Serie A (Liga Italiana) 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (13, 'admin', 'Quien ganara la Bundesliga Alemana 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (14, 'admin', 'Quien ganara la Liga Francesa 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));
  
INSERT INTO Evento  VALUES (15, 'admin', 'Quien ganara la Copa de Africa 2008?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (16, 'admin', 'Quien ganara la FA Cup (Copa Inglesa) 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (17, 'admin', 'Proximo Lider Liberal-Democrata',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 2, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (18, 'admin', 'Iceman manda',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (19, 'admin', 'La Historia de Lewis Hamilton',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('31-12-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (20, 'admin', 'Los de abajo lo intentaran con fuerza',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('31-12-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (21, 'admin', 'Magic Alonso',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('31-12-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (22, 'admin', 'Mas victorias en F1 en 2008',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('31-12-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (23, 'admin', 'Especial Motor',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 1, 10, 0, 1000,
  to_date('31-12-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (24, 'admin', 'Fichajes del Real Zaragoza en el mercado de invierno 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('31-12-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (25, 'admin', 'Campeon de la SuperLiga Griega 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (26, 'admin', 'Campeon de la SuperLiga de Portugal 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (27, 'admin', 'Campeon de la SuperLiga de Suiza 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (28, 'admin', 'Quien ganara la Bundesliga austriaca 2007-08?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('29-5-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (29, 'admin', 'Campeon de la Eredivise (Liga de Holanda) 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (30, 'admin', 'Campeon de la Liga de Suecia (Swedish Allsvenskan) 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (31, 'admin', 'Que equipos descenderan en la Premier League (Liga Inglesa) 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (32, 'admin', 'Campeon de la Liga de Noruega (Norwegian Tippeligaen) 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (33, 'admin', 'Campeon de la Copa de la UEFA 2007-08',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('1-6-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (34, 'admin', 'Champions League 2007-08, Celtic v Barcelona - Quien se clasificara?',   
  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000,
  to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (35, 'admin', 'Champions League 2007-08, Liverpool v Internazionale - Quien se clasificara?', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (36, 'admin', 'Champions League 2007-08, Lyon v Manchester United - Quien se clasificara?',  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (37, 'admin', 'Champions League 2007-08, Schalke 04 v Oporto - Quien se clasificara?', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (38, 'admin', 'Champions League 2007-08, Arsenal v AC Milan - Quien se clasificara?', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (39, 'admin', 'Champions League 2007-08, Fenerbahce v Sevilla - Quien se clasificara?',  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (40, 'admin', 'Champions League 2007-08, Olympiakos v Chelsea - Quien se clasificara?', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (41, 'admin', 'Champions League 2007-08, Roma v Real Madrid - Quien se clasificara?', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('21-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (42, 'admin', 'Owen rompe el record', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (43, 'admin', 'Capitan Rooney', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (44, 'admin', 'Portero de Inglaterra v Suiza al comienzo del partido', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('6-2-08 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (45, 'admin', 'Juega Beckham', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (46, 'admin', 'Yendo a Inglaterra - Kaká', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (47, 'admin', 'Yendo a Inglaterra - Ronaldinho', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (48, 'admin', 'Yendo a Inglaterra - Lionel Messi', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (49, 'admin', 'Yendo a Inglaterra - David Beckham', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (50, 'admin', 'Yendo a Inglaterra - Klass-Jan Huntelaar', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (51, 'admin', 'Yendo a Inglaterra - Ruud Van Nistelrooy', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (52, 'admin', 'Yendo a Inglaterra - Frank Rijkaard', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (53, 'admin', 'Diciendo Adios - Cristiano Ronaldo', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (54, 'admin', 'Diciendo Adios - Michael Ballack', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (55, 'admin', 'Diciendo Adios - Andriy Shevchenko', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (56, 'admin', 'Diciendo Adios - Rafa Benitez', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (57, 'admin', 'Diciendo Adios - Michael Owen', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (58, 'admin', 'Premier Inglesa - Imbatido', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (59, 'admin', 'Premier Inglesa - Goles en Abundancia', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (60, 'admin', 'Premier Inglesa - Locura de dinero', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (61, 'admin', 'Premier Inglesa - Maquina de goles', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (62, 'admin', 'Premier Inglesa - Tecnologia finalmente', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (63, 'admin', 'Premier Inglesa - McClaren vuelve al banquillo', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (64, 'admin', 'Eurocopa 2008 - Campeon de Grupo A', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (65, 'admin', 'Eurocopa 2008 - Campeon de Grupo B', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (66, 'admin', 'Eurocopa 2008 - Campeon de Grupo C', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (67, 'admin', 'Eurocopa 2008 - Campeon de Grupo D', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));

INSERT INTO Evento  VALUES (68, 'admin', 'Champions League 2007/08 - Pais del campeon?', to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 0, 10, 0, 1000, to_date('1-1-09 22:00:00', 'DD-MM-YY HH24:MI:SS'));


INSERT INTO Resultado  VALUES (1, 1, 'Local', 5.50, 0);
INSERT INTO Resultado  VALUES (2, 1, 'Empate', 4.50, 0);
INSERT INTO Resultado  VALUES (3, 1, 'Visitante', 3.50, 0);

INSERT INTO Resultado  VALUES (4, 2, 'L. Hamilton', 2.80, 0);
INSERT INTO Resultado  VALUES (5, 2, 'F. Alonso', 5.00, 0);
INSERT INTO Resultado  VALUES (6, 2, 'F. Massa', 5.60, 0);
INSERT INTO Resultado  VALUES (7, 2, 'K. Raikkonen', 2.75, 0);
INSERT INTO Resultado  VALUES (8, 2, 'H. Kovalainen', 19.00, 0);
INSERT INTO Resultado  VALUES (9, 2, 'N. Heidfeld', 34.00, 0);
INSERT INTO Resultado  VALUES (10, 2, 'N. Rosberg', 34.00, 0);
INSERT INTO Resultado  VALUES (11, 2, 'R. Kubica', 41.00, 0);
INSERT INTO Resultado  VALUES (12, 2, 'J. Button', 51.00, 0);
INSERT INTO Resultado  VALUES (13, 2, 'M. Webber', 101.00, 0);
INSERT INTO Resultado  VALUES (14, 2, 'D. Coulthard', 151.00, 0);

INSERT INTO Resultado  VALUES (15, 3, 'Ferrari', 1.75, 0);
INSERT INTO Resultado  VALUES (16, 3, 'McLaren-Mercedes', 3.00, 0);
INSERT INTO Resultado  VALUES (17, 3, 'Renault', 6.00, 0);
INSERT INTO Resultado  VALUES (18, 3, 'Red Bull', 20.00, 0);
INSERT INTO Resultado  VALUES (19, 3, 'BMW Sauber', 20.00, 0);
INSERT INTO Resultado  VALUES (20, 3, 'Honda', 30.00, 0);
INSERT INTO Resultado  VALUES (21, 3, 'WilliamsF1', 40.00, 0);
INSERT INTO Resultado  VALUES (22, 3, 'Toyota', 50.00, 0);
INSERT INTO Resultado  VALUES (23, 3, 'Toro Rosso', 101.00, 0);
INSERT INTO Resultado  VALUES (24, 3, 'Super Aguri', 201.00, 0);

INSERT INTO Resultado VALUES (25, 4, 'PP', 4.50, 0);
INSERT INTO Resultado VALUES (26, 4, 'PSOE', 4.00, 0);
INSERT INTO Resultado VALUES (27, 5, 'Democratas', 1.45, 0);
INSERT INTO Resultado VALUES (28, 5, 'Republicanos', 2.60, 0);
INSERT INTO Resultado VALUES (29, 6, 'Partido Laborista', 2.10, 0);
INSERT INTO Resultado VALUES (30, 6, 'Partido Conservador', 1.66, 0);
INSERT INTO Resultado VALUES (31, 6, 'Partido Liberal-Democrata', 67.00, 0);

INSERT INTO Resultado  VALUES (32, 7, 'L. Hamilton', 100.80, 0);
INSERT INTO Resultado  VALUES (33, 7, 'F. Alonso', 50.00, 0);
INSERT INTO Resultado  VALUES (34, 7, 'F. Massa', 110.60, 0);
INSERT INTO Resultado  VALUES (35, 7, 'K. Raikkonen', 105.75, 0);
INSERT INTO Resultado  VALUES (36, 7, 'H. Kovalainen', 19.00, 0);
INSERT INTO Resultado  VALUES (37, 7, 'N. Heidfeld', 34.00, 0);
INSERT INTO Resultado  VALUES (38, 7, 'N. Rosberg', 34.00, 0);
INSERT INTO Resultado  VALUES (39, 7, 'R. Kubica', 11.00, 0);
INSERT INTO Resultado  VALUES (40, 7, 'J. Button', 11.00, 0);
INSERT INTO Resultado  VALUES (41, 7, 'M. Webber', 11.00, 0);
INSERT INTO Resultado  VALUES (42, 7, 'D. Coulthard', 10.00, 0);

INSERT INTO Resultado  VALUES (43, 8, 'Alemania', 5.00, 0);
INSERT INTO Resultado  VALUES (44, 8, 'Espanya', 6.50, 0);
INSERT INTO Resultado  VALUES (45, 8, 'Italia', 7.00, 0);
INSERT INTO Resultado  VALUES (46, 8, 'Francia', 9.00, 0);
INSERT INTO Resultado  VALUES (47, 8, 'Portugal', 9.00, 0);
INSERT INTO Resultado  VALUES (48, 8, 'Croacia', 11.00, 0);
INSERT INTO Resultado  VALUES (49, 8, 'Holada', 13.00, 0);
INSERT INTO Resultado  VALUES (50, 8, 'Republica Checa', 13.00, 0);
INSERT INTO Resultado  VALUES (51, 8, 'Suiza', 21.00, 0);
INSERT INTO Resultado  VALUES (52, 8, 'Suecia', 26.00, 0);
INSERT INTO Resultado  VALUES (53, 8, 'Grecia', 34.00, 0);
INSERT INTO Resultado  VALUES (54, 8, 'Rumania', 34.00, 0);
INSERT INTO Resultado  VALUES (55, 8, 'Rusia', 34.00, 0);
INSERT INTO Resultado  VALUES (56, 8, 'Turquia', 34.00, 0);
INSERT INTO Resultado  VALUES (57, 8, 'Polonia', 41.00, 0);
INSERT INTO Resultado  VALUES (58, 8, 'Austria', 101.00, 0);

INSERT INTO Resultado  VALUES (59, 9, 'Barcelona', 5.00, 0);
INSERT INTO Resultado  VALUES (60, 9, 'Manchester United', 6.50, 0);
INSERT INTO Resultado  VALUES (61, 9, 'Arsenal', 7.50, 0);
INSERT INTO Resultado  VALUES (62, 9, 'Chelsea', 8.00, 0);
INSERT INTO Resultado  VALUES (63, 9, 'Inter de Milan', 9.00, 0);
INSERT INTO Resultado  VALUES (64, 9, 'Milan', 10.00, 0);
INSERT INTO Resultado  VALUES (65, 9, 'Real Madrid', 11.00, 0);
INSERT INTO Resultado  VALUES (66, 9, 'Liverpool', 15.00, 0);
INSERT INTO Resultado  VALUES (67, 9, 'Sevilla', 17.00, 0);
INSERT INTO Resultado  VALUES (68, 9, 'Roma', 21.00, 0);
INSERT INTO Resultado  VALUES (69, 9, 'Lyon', 34.00, 0);
INSERT INTO Resultado  VALUES (70, 9, 'Oporto', 51.00, 0);
INSERT INTO Resultado  VALUES (71, 9, 'Celtic', 67.00, 0);
INSERT INTO Resultado  VALUES (72, 9, 'Schalke 04', 67.00, 0);
INSERT INTO Resultado  VALUES (73, 9, 'Werder Bremen', 67.00, 0);
INSERT INTO Resultado  VALUES (74, 9, 'Fenerbahce', 81.00, 0);
INSERT INTO Resultado  VALUES (75, 9, 'Marsella', 101.00, 0);
INSERT INTO Resultado  VALUES (76, 9, 'Olympiakos', 101.00, 0);
INSERT INTO Resultado  VALUES (77, 9, 'Rangers', 101.00, 0);
INSERT INTO Resultado  VALUES (78, 9, 'PSV Eindhoven', 201.00, 0);
INSERT INTO Resultado  VALUES (79, 9, 'Rosenborg', 251.00, 0);

INSERT INTO Resultado  VALUES (80, 10, 'Barcelona', 2.00, 0);
INSERT INTO Resultado  VALUES (81, 10, 'Real Madrid', 2.00, 0);
INSERT INTO Resultado  VALUES (82, 10, 'Atletico de Madrid', 13.00, 0);
INSERT INTO Resultado  VALUES (83, 10, 'Villareal', 26.00, 0);
INSERT INTO Resultado  VALUES (84, 10, 'Valencia', 34.00, 0);
INSERT INTO Resultado  VALUES (85, 10, 'Sevilla', 67.00, 0);
INSERT INTO Resultado  VALUES (86, 10, 'Espanyol', 81.00, 0);

INSERT INTO Resultado  VALUES (87, 11, 'Manchester United', 2.20, 0);
INSERT INTO Resultado  VALUES (88, 11, 'Arsenal', 23.00, 0);
INSERT INTO Resultado  VALUES (89, 11, 'Chelsea', 4.00, 0);
INSERT INTO Resultado  VALUES (90, 11, 'Liverpool', 7.50, 0);
INSERT INTO Resultado  VALUES (91, 11, 'Manchester City', 251.00, 0);
INSERT INTO Resultado  VALUES (92, 11, 'Aston Villa', 501.00, 0);
INSERT INTO Resultado  VALUES (93, 11, 'Blackburn', 501.00, 0);
INSERT INTO Resultado  VALUES (94, 11, 'Portsmouth', 501.00, 0);

INSERT INTO Resultado  VALUES (95, 12, 'Inter de Milan', 1.25, 0);
INSERT INTO Resultado  VALUES (96, 12, 'Roma', 6.00, 0);
INSERT INTO Resultado  VALUES (97, 12, 'Juventus', 11.00, 0);
INSERT INTO Resultado  VALUES (98, 12, 'Milan', 34.00, 0);
INSERT INTO Resultado  VALUES (99, 12, 'Fiorentina', 51.00, 0);
INSERT INTO Resultado  VALUES (100, 12, 'Udinese', 101.00, 0);

INSERT INTO Resultado  VALUES (101, 13, 'Bayern Munich', 1.20, 0);
INSERT INTO Resultado  VALUES (102, 13, 'Werder Bremen', 6.50, 0);
INSERT INTO Resultado  VALUES (103, 13, 'Hamburgo', 13.00, 0);
INSERT INTO Resultado  VALUES (104, 13, 'Bayer Leverkusen', 26.00, 0);
INSERT INTO Resultado  VALUES (105, 13, 'Schalke 04', 34.00, 0);
INSERT INTO Resultado  VALUES (106, 13, 'VFB Stuttgart', 34.00, 0);

INSERT INTO Resultado  VALUES (107, 14, 'Lyon', 1.05, 0);
INSERT INTO Resultado  VALUES (108, 14, 'Nancy', 13.00, 0);
INSERT INTO Resultado  VALUES (109, 14, 'Girondins', 17.00, 0);
INSERT INTO Resultado  VALUES (110, 14, 'Marsella', 29.00, 0);
INSERT INTO Resultado  VALUES (111, 14, 'Rennes', 51.00, 0);
INSERT INTO Resultado  VALUES (112, 14, 'Monaco', 81.00, 0);
INSERT INTO Resultado  VALUES (113, 14, 'Paris St. Germain', 101.00, 0);
INSERT INTO Resultado  VALUES (114, 14, 'St Etienne', 101.00, 0);

INSERT INTO Resultado  VALUES (115, 15, 'Ghana', 4.50, 0);
INSERT INTO Resultado  VALUES (116, 15, 'Costa de Marfil', 4.50, 0);
INSERT INTO Resultado  VALUES (117, 15, 'Camerun', 6.00, 0);
INSERT INTO Resultado  VALUES (118, 15, 'Nigeria', 6.00, 0);
INSERT INTO Resultado  VALUES (119, 15, 'Senegal', 13.00, 0);
INSERT INTO Resultado  VALUES (120, 15, 'Marruecos', 15.00, 0);
INSERT INTO Resultado  VALUES (121, 15, 'Egipto', 17.00, 0);
INSERT INTO Resultado  VALUES (122, 15, 'Guinea', 21.00, 0);
INSERT INTO Resultado  VALUES (123, 15, 'Sudafrica', 21.00, 0);
INSERT INTO Resultado  VALUES (124, 15, 'Tunez', 21.00, 0);
INSERT INTO Resultado  VALUES (125, 15, 'Mali', 26.00, 0);
INSERT INTO Resultado  VALUES (126, 15, 'Zambia', 51.00, 0);
INSERT INTO Resultado  VALUES (127, 15, 'Angola', 67.00, 0);
INSERT INTO Resultado  VALUES (128, 15, 'Benin', 101.00, 0);
INSERT INTO Resultado  VALUES (129, 15, 'Namibia', 101.00, 0);
INSERT INTO Resultado  VALUES (130, 15, 'Sudan', 101.00, 0);

INSERT INTO Resultado  VALUES (131, 16, 'Chelsea', 5.00, 0);
INSERT INTO Resultado  VALUES (132, 16, 'Manchester United', 5.00, 0);
INSERT INTO Resultado  VALUES (133, 16, 'Liverpool', 5.50, 0);
INSERT INTO Resultado  VALUES (134, 16, 'Arsenal', 6.00, 0);
INSERT INTO Resultado  VALUES (135, 16, 'Tottenham Hotspur', 13.00, 0);
INSERT INTO Resultado  VALUES (137, 16, 'Blackburn', 21.00, 0);
INSERT INTO Resultado  VALUES (138, 16, 'Everton', 21.00, 0);
INSERT INTO Resultado  VALUES (139, 16, 'Manchester City', 26.00, 0);
INSERT INTO Resultado  VALUES (140, 16, 'Newcastle United', 26.00, 0);
INSERT INTO Resultado  VALUES (141, 16, 'Portsmouth', 26.00, 0);
INSERT INTO Resultado  VALUES (142, 16, 'Aston Villa', 34.00, 0);
INSERT INTO Resultado  VALUES (143, 16, 'West Ham Utd', 34.20, 0);
INSERT INTO Resultado  VALUES (144, 16, 'Birmingham', 67.00, 0);
INSERT INTO Resultado  VALUES (145, 16, 'Bolton', 67.00, 0);

INSERT INTO Resultado  VALUES (146, 17, 'Nick Clegg', 1.25, 0);
INSERT INTO Resultado  VALUES (147, 17, 'Chris Huhne', 3.75, 0);

INSERT INTO Resultado  VALUES (148, 18, 'Raikkonen será Campeón del Mundo de F1 en 2008', 2.75, 0);
INSERT INTO Resultado  VALUES (149, 18, 'Raikkonen ganará todas las carreras de F1 en 2008', 101.00, 0);
INSERT INTO Resultado  VALUES (150, 18, 'Raikkonen hará la Pole en todas las carreras de F1 en 2008', 101.00, 0);
INSERT INTO Resultado  VALUES (151, 18, 'Raikkonen acabará todas las carreras de F1 en el Podium en 2008', 8.00, 0);

INSERT INTO Resultado  VALUES (152, 19, 'Lewis Hamilton se casará en 2008', 11.00, 0);
INSERT INTO Resultado  VALUES (153, 19, 'Lewis Hamilton será padre en 2008', 21.00, 0);
INSERT INTO Resultado  VALUES (154, 19, 'Lewis Hamilton ganará todas las carreras de F1 en 2008', 101.00, 0);
INSERT INTO Resultado  VALUES (155, 19, 'Lewis Hamilton hará la Pole en todas la carreras de F1 en 2008', 101.00, 0);
INSERT INTO Resultado  VALUES (156, 19, 'Lewis Hamilton será Campeón del Mundo de F1 en 2008', 3.25, 0);
INSERT INTO Resultado  VALUES (157, 19, 'Lewis Hamilton será Campeón del Mundo y Button segundo en 2008', 11.00, 0);
INSERT INTO Resultado  VALUES (158, 19, 'Lewis Hamilton acabará todas las carreras de F1 en el Podium en 2008', 8.00, 0);

INSERT INTO Resultado  VALUES (159, 20, 'Jenson Button ganará alguna carrera de Fórmula 1 en 2008', 1.62, 0);
INSERT INTO Resultado  VALUES (160, 20, 'Nick Heidfeld ganará alguna carrera de Fórmula 1 en 2008', 1.25, 0);
INSERT INTO Resultado  VALUES (161, 20, 'Robert Kubica ganará alguna carrera de Fórmula 1 en 2008', 1.40, 0);
INSERT INTO Resultado  VALUES (162, 20, 'Mark Webber ganará alguna carrera de Fórmula 1 en 2008', 1.50, 0);
INSERT INTO Resultado  VALUES (163, 20, 'David Coulthard ganará alguna carrera de Fórmula 1 en 2008', 1.73, 0);

INSERT INTO Resultado  VALUES (164, 21, 'Alonso ganará todas las carreras de F1 en 2008', 101.00, 0);
INSERT INTO Resultado  VALUES (165, 21, 'Alonso hará la Pole en todas las carreras en 2008', 101.00, 0);
INSERT INTO Resultado  VALUES (166, 21, 'Alonso acabará todas la carreras de F1 en el Podium en 2008', 8.00, 0);
INSERT INTO Resultado  VALUES (167, 21, 'Alonso será Campeón del Mundo de en 2008', 5.00, 0);

INSERT INTO Resultado  VALUES (168, 22, 'Raikkonen será quien logre más victorias en 2008', 2.75, 0);
INSERT INTO Resultado  VALUES (169, 22, 'Hamilton será quien logre más victorias en 2008', 3.50, 0);
INSERT INTO Resultado  VALUES (170, 22, 'Alonso será quien logre más victorias en 2008', 4.00, 0);
INSERT INTO Resultado  VALUES (171, 22, 'Massa será quien logre más victorias en 2008', 5.00, 0);
INSERT INTO Resultado  VALUES (172, 22, 'Heidfeld será quien logre más victorias en 2008', 17.00, 0);
INSERT INTO Resultado  VALUES (173, 22, 'Kubica será quien logre más victorias en 2008', 21.00, 0);
INSERT INTO Resultado  VALUES (174, 22, 'Button será quien logre más victorias en 2008', 51.00, 0);

INSERT INTO Resultado  VALUES (175, 23, 'Rossi pilotara en alguna carrera del Mundial de F1 en 2008', 21.00, 0);
INSERT INTO Resultado  VALUES (176, 23, 'Michael Schumacher Pilotará en alguna carrera del Mundial de F1 en 2008', 8.00, 0);

INSERT INTO Resultado  VALUES (178, 24, 'El Real Zaragoza no hara ningun fichaje en el mercado de invierno 2007-08', 3.00, 0);
INSERT INTO Resultado  VALUES (179, 24, 'El Real Zaragoza fichara o conseguira la cesion de Saviola (Real Madrid)', 2.00, 0);
INSERT INTO Resultado  VALUES (180, 24, 'El Real Zaragoza fichara o conseguira la cesion de Gerard Pique (Manchester United)', 4.00, 0);

INSERT INTO Resultado  VALUES (181, 25, 'Olympiakos', 2.10, 0);
INSERT INTO Resultado  VALUES (182, 25, 'AEK Atenas', 3.00, 0);
INSERT INTO Resultado  VALUES (183, 25, 'Pananthinaikos', 3.60, 0);
INSERT INTO Resultado  VALUES (184, 25, 'Aris de Salonica', 26.00, 0);

INSERT INTO Resultado  VALUES (185, 26, 'Oporto', 1.08, 0);
INSERT INTO Resultado  VALUES (186, 26, 'Sporting de Lisboa', 17.00, 0);
INSERT INTO Resultado  VALUES (187, 26, 'Benfica', 8.00, 0);

INSERT INTO Resultado  VALUES (188, 27, 'FC Basilea', 1.30, 0);
INSERT INTO Resultado  VALUES (189, 27, 'FC Zurich', 3.30, 0);
INSERT INTO Resultado  VALUES (190, 27, 'Young Boys', 10.00, 0);
INSERT INTO Resultado  VALUES (191, 27, 'Grasshoppers', 51.00, 0);
INSERT INTO Resultado  VALUES (192, 27, 'Sion', 51.00, 0);
INSERT INTO Resultado  VALUES (193, 27, 'Aarau', 101.00, 0);
INSERT INTO Resultado  VALUES (194, 27, 'Xamax', 101.00, 0);
INSERT INTO Resultado  VALUES (195, 27, 'Lucerna', 251.00, 0);
INSERT INTO Resultado  VALUES (196, 27, 'FC Thun', 501.00, 0);
INSERT INTO Resultado  VALUES (197, 27, 'St. Gallen', 501.00, 0);

INSERT INTO Resultado  VALUES (198, 28, 'Salzburgo', 1.70, 0);
INSERT INTO Resultado  VALUES (199, 28, 'Austria Viena', 2.60, 0);
INSERT INTO Resultado  VALUES (200, 28, 'Rapid Viena', 9.00, 0);
INSERT INTO Resultado  VALUES (201, 28, 'Sturm Graz', 12.00, 0);
INSERT INTO Resultado  VALUES (202, 28, 'SV Mattersburgo', 19.00, 0);
INSERT INTO Resultado  VALUES (203, 28, 'LASK Linz', 41.00, 0);
INSERT INTO Resultado  VALUES (204, 28, 'SV Ried', 501.00, 0);
INSERT INTO Resultado  VALUES (205, 28, 'SK Austria Karnten', 751.00, 0);
INSERT INTO Resultado  VALUES (206, 28, 'Altach', 1001.00, 0);
INSERT INTO Resultado  VALUES (207, 28, 'Wacker Tirol', 1001.00, 0);

INSERT INTO Resultado  VALUES (208, 29, 'Ajax', 2.40, 0);
INSERT INTO Resultado  VALUES (209, 29, 'PSV Eindhoven', 2.50, 0);
INSERT INTO Resultado  VALUES (210, 29, 'Feyenoord', 4.50, 0);
INSERT INTO Resultado  VALUES (211, 29, 'AZ Alkmaar', 13.00, 0);
INSERT INTO Resultado  VALUES (212, 29, 'Heerenveen', 51.00, 0);
INSERT INTO Resultado  VALUES (213, 29, 'FC Twente', 101.00, 0);

INSERT INTO Resultado  VALUES (214, 30, 'IFK Goteborg', 4.30, 0);
INSERT INTO Resultado  VALUES (215, 30, 'Elfsborg', 5.50, 0);
INSERT INTO Resultado  VALUES (216, 30, 'Malmoe FF', 5.50, 0);
INSERT INTO Resultado  VALUES (217, 30, 'Djurgaarden', 7.00, 0);
INSERT INTO Resultado  VALUES (218, 30, 'AIK', 8.00, 0);
INSERT INTO Resultado  VALUES (219, 30, 'Helsingborg', 10.00, 0);
INSERT INTO Resultado  VALUES (220, 30, 'Kalmar FF', 10.00, 0);
INSERT INTO Resultado  VALUES (221, 30, 'Hammarby', 12.00, 0);
INSERT INTO Resultado  VALUES (222, 30, 'Halmstad', 26.00, 0);
INSERT INTO Resultado  VALUES (223, 30, 'IFK Norrkoping', 34.00, 0);
INSERT INTO Resultado  VALUES (224, 30, 'GAIS', 81.00, 0);
INSERT INTO Resultado  VALUES (225, 30, 'Gefle', 81.00, 0);
INSERT INTO Resultado  VALUES (226, 30, 'Orebro SK', 81.00, 0);
INSERT INTO Resultado  VALUES (227, 30, 'GIF Sundsvall', 101.00, 0);
INSERT INTO Resultado  VALUES (228, 30, 'Trelleborgs FF', 101.00, 0);
INSERT INTO Resultado  VALUES (229, 30, 'Ljungskile', 201.00, 0);

INSERT INTO Resultado  VALUES (230, 31, 'Derby County', 1.01, 0);
INSERT INTO Resultado  VALUES (231, 31, 'Wigan', 1.60, 0);
INSERT INTO Resultado  VALUES (232, 31, 'Birmingham', 3.50, 0);
INSERT INTO Resultado  VALUES (233, 31, 'Fulham', 3.00, 0);
INSERT INTO Resultado  VALUES (234, 31, 'Sunderland', 3.25, 0);
INSERT INTO Resultado  VALUES (235, 31, 'Middlesbrough', 4.00, 0);
INSERT INTO Resultado  VALUES (236, 31, 'Reading', 6.50, 0);
INSERT INTO Resultado  VALUES (237, 31, 'Bolton', 4.00, 0);
INSERT INTO Resultado  VALUES (238, 31, 'West Ham Utd', 34.00, 0);
INSERT INTO Resultado  VALUES (239, 31, 'Newcastle United', 34.00, 0);
INSERT INTO Resultado  VALUES (240, 31, 'Tottenham Hotspur', 26.00, 0);

INSERT INTO Resultado  VALUES (241, 32, 'Brann', 3.50, 0);
INSERT INTO Resultado  VALUES (242, 32, 'Rosenborg', 3.50, 0);
INSERT INTO Resultado  VALUES (243, 32, 'Lillestrom', 5.50, 0);
INSERT INTO Resultado  VALUES (244, 32, 'Valerenga', 7.00, 0);
INSERT INTO Resultado  VALUES (245, 32, 'Viking', 7.00, 0);
INSERT INTO Resultado  VALUES (246, 32, 'Stabaek', 9.00, 0);
INSERT INTO Resultado  VALUES (247, 32, 'Fredrikstad', 41.00, 0);
INSERT INTO Resultado  VALUES (248, 32, 'Lyn', 51.00, 0);
INSERT INTO Resultado  VALUES (249, 32, 'Tromso', 51.00, 0);
INSERT INTO Resultado  VALUES (250, 32, 'Stromsgodset', 67.00, 0);
INSERT INTO Resultado  VALUES (251, 32, 'Aalesund', 101.00, 0);
INSERT INTO Resultado  VALUES (252, 32, 'Molde', 101.00, 0);
INSERT INTO Resultado  VALUES (253, 32, 'Bodo-Glimt', 201.00, 0);
INSERT INTO Resultado  VALUES (254, 32, 'Ham-Kam', 201.00, 0);

INSERT INTO Resultado  VALUES (255, 33, 'Bayern Munich', 3.75, 0);
INSERT INTO Resultado  VALUES (256, 33, 'Atl Madrid', 9.00, 0);
INSERT INTO Resultado  VALUES (257, 33, 'Tottenham Hotspur', 10.00, 0);
INSERT INTO Resultado  VALUES (258, 33, 'Everton', 11.00, 0);
INSERT INTO Resultado  VALUES (259, 33, 'Villareal', 13.00, 0);
INSERT INTO Resultado  VALUES (260, 33, 'Werder Bremen', 15.00, 0);
INSERT INTO Resultado  VALUES (261, 33, 'Fiorentina', 17.00, 0);
INSERT INTO Resultado  VALUES (262, 33, 'Hamburgo', 17.00, 0);
INSERT INTO Resultado  VALUES (263, 33, 'Bayer Leverkusen', 21.00, 0);
INSERT INTO Resultado  VALUES (264, 33, 'Benfica', 21.00, 0);
INSERT INTO Resultado  VALUES (265, 33, 'Getafe', 21.00, 0);
INSERT INTO Resultado  VALUES (266, 33, 'PSV Eindhoven', 26.00, 0);
INSERT INTO Resultado  VALUES (267, 33, 'Spartak de Moscu', 26.00, 0);
INSERT INTO Resultado  VALUES (268, 33, 'Sporting de Lisboa', 26.00, 0);
INSERT INTO Resultado  VALUES (269, 33, 'Girondins', 41.00, 0);
INSERT INTO Resultado  VALUES (270, 33, 'Marsella', 41.00, 0);
INSERT INTO Resultado  VALUES (271, 33, 'Panathinaikos', 41.00, 0);
INSERT INTO Resultado  VALUES (272, 33, 'Rangers', 41.00, 0);
INSERT INTO Resultado  VALUES (273, 33, 'AEK Atenas', 51.00, 0);
INSERT INTO Resultado  VALUES (274, 33, 'Zenit St Petesburgo', 51.00, 0);
INSERT INTO Resultado  VALUES (275, 33, 'Nurenberg', 67.00, 0);
INSERT INTO Resultado  VALUES (276, 33, 'Rosenborg', 67.00, 0);
INSERT INTO Resultado  VALUES (277, 33, 'Galatasaray', 81.00, 0);
INSERT INTO Resultado  VALUES (278, 33, 'Anderlecht', 101.00, 0);
INSERT INTO Resultado  VALUES (279, 33, 'Basilea', 101.00, 0);
INSERT INTO Resultado  VALUES (280, 33, 'Bolton', 101.00, 0);
INSERT INTO Resultado  VALUES (281, 33, 'Slavia de Proga', 101.00, 0);
INSERT INTO Resultado  VALUES (282, 33, 'Sporting de Braga', 101.00, 0);
INSERT INTO Resultado  VALUES (283, 33, 'FC Zurich', 151.00, 0);
INSERT INTO Resultado  VALUES (284, 33, 'Helsingborg', 151.00, 0);
INSERT INTO Resultado  VALUES (285, 33, 'Aberdeen', 501.00, 0);
INSERT INTO Resultado  VALUES (286, 33, 'Brann', 501.00, 0);

INSERT INTO Resultado  VALUES (287, 34, 'Local', 5.00, 0);
INSERT INTO Resultado  VALUES (288, 34, 'Visitante', 1.14, 0);

INSERT INTO Resultado  VALUES (289, 35, 'Local', 1.95, 0);
INSERT INTO Resultado  VALUES (290, 35, 'Visitante', 1.75, 0);

INSERT INTO Resultado  VALUES (291, 36, 'Local', 2.60, 0);
INSERT INTO Resultado  VALUES (292, 36, 'Visitante', 1.45, 0);

INSERT INTO Resultado  VALUES (293, 37, 'Local', 2.05, 0);
INSERT INTO Resultado  VALUES (294, 37, 'Visitante', 1.70, 0);

INSERT INTO Resultado  VALUES (295, 38, 'Local', 1.80, 0);
INSERT INTO Resultado  VALUES (296, 38, 'Visitante', 1.90, 0);

INSERT INTO Resultado  VALUES (297, 39, 'Local', 3.20, 0);
INSERT INTO Resultado  VALUES (298, 39, 'Visitante', 1.30, 0);

INSERT INTO Resultado  VALUES (299, 40, 'Local', 4.50, 0);
INSERT INTO Resultado  VALUES (300, 40, 'Visitante', 1.17, 0);

INSERT INTO Resultado  VALUES (301, 41, 'Local', 2.40, 0);
INSERT INTO Resultado  VALUES (302, 41, 'Visitante', 1.50, 0);

INSERT INTO Resultado  VALUES (303, 42, 'Michael Owen romperá el record de Bobby Charlton con Inglaterra en 2008', 13.00, 0);

INSERT INTO Resultado  VALUES (304, 43, 'Rooney comenzará un partido con Inglaterra como Capitán en 2008', 13.00, 0);

INSERT INTO Resultado  VALUES (305, 44, 'Paul Robinson', 2.20, 0);
INSERT INTO Resultado  VALUES (306, 44, 'David James', 3.25, 0);
INSERT INTO Resultado  VALUES (307, 44, 'Scott Carson', 5.50, 0);
INSERT INTO Resultado  VALUES (308, 44, 'Robert Green', 5.50, 0);
INSERT INTO Resultado  VALUES (309, 44, 'Chris Kirkland', 34.00, 0);
INSERT INTO Resultado  VALUES (310, 44, 'Ben Foster', 34.00, 0);

INSERT INTO Resultado  VALUES (311, 45, 'David Beckham jugará algún clasificatorio para el Mundial en 2008', 2.25, 0);

INSERT INTO Resultado  VALUES (312, 46, 'Kaka jugara en la Premiership en 2008', 7.00, 0);

INSERT INTO Resultado  VALUES (313, 47, 'Ronaldinho jugara en la Premiership en 2008', 2.30, 0);

INSERT INTO Resultado  VALUES (314, 48, 'Messi jugara en la Premiership en 2008', 15.00, 0);

INSERT INTO Resultado  VALUES (315, 49, 'Beckham jugara en algun Club ingles en 2008', 7.00, 0);

INSERT INTO Resultado  VALUES (316, 50, 'Huntelaar jugara en la Premiership en 2008', 1.60, 0);

INSERT INTO Resultado  VALUES (317, 51, 'Van Nistelrooy jugara en la Premiership en 2008', 5.00, 0);

INSERT INTO Resultado  VALUES (318, 52, 'Rijkaard entrenara en la Premiership en 2008', 5.00, 0);

INSERT INTO Resultado  VALUES (319, 53, 'Ronaldo abandonara el Manchester Utd en 2008', 6.00, 0);

INSERT INTO Resultado  VALUES (320, 54, 'Ballack abandonara el Chelsea en 2008', 1.55, 0);

INSERT INTO Resultado  VALUES (321, 55, 'Shevchenko abandonara el Chelsea en 2008', 2.10, 0);

INSERT INTO Resultado  VALUES (322, 56, 'Benitez abandonara el Liverpool en 2008', 2.40, 0);

INSERT INTO Resultado  VALUES (323, 57, 'Owen abandonara el Newcastle en 2008', 3.00, 0);

INSERT INTO Resultado  VALUES (324, 58, 'Un Club de la Premiership permanecerá imbatido en 2008', 17.00, 0);

INSERT INTO Resultado  VALUES (325, 59, 'Un partido de la Premier tendra mas de 10 goles en 2008', 6.00, 0);

INSERT INTO Resultado  VALUES (326, 60, 'Un Club de la Premiership comprará a un jugador por más de 30 millones de libras en 2008', 3.00, 0);

INSERT INTO Resultado  VALUES (327, 61, 'Algún jugador marca 5 o más goles en un partido de la Premiership en 2008', 11.00, 0);

INSERT INTO Resultado  VALUES (328, 62, 'La tecnología en la Línea de Gol será usada en la Premiership en 2008', 5.00, 0);

INSERT INTO Resultado  VALUES (329, 63, 'Steve McClaren entrenará a un Club de la Premiership en 2008', 1.60, 0);

INSERT INTO Resultado  VALUES (330, 64, 'Portugal', 2.625, 0);
INSERT INTO Resultado  VALUES (331, 64, 'Republica Checa', 3.25, 0);
INSERT INTO Resultado  VALUES (332, 64, 'Suiza', 4.00, 0);
INSERT INTO Resultado  VALUES (333, 64, 'Turquia', 5.50, 0);
INSERT INTO Resultado  VALUES (334, 65, 'Alemania', 1.65, 0);
INSERT INTO Resultado  VALUES (335, 65, 'Croacia', 3.40, 0);
INSERT INTO Resultado  VALUES (336, 65, 'Polonia', 7.00, 0);
INSERT INTO Resultado  VALUES (337, 65, 'Austria', 13.0, 0);
INSERT INTO Resultado  VALUES (338, 66, 'Italia', 2.50, 0);
INSERT INTO Resultado  VALUES (339, 66, 'Francia', 2.75, 0);
INSERT INTO Resultado  VALUES (340, 66, 'Holanda', 4.00, 0);
INSERT INTO Resultado  VALUES (341, 66, 'Rumania', 9.00, 0);
INSERT INTO Resultado  VALUES (342, 67, 'España', 1.70, 0);
INSERT INTO Resultado  VALUES (343, 67, 'Grecia', 5.00, 0);
INSERT INTO Resultado  VALUES (344, 67, 'Suecia', 5.50, 0);
INSERT INTO Resultado  VALUES (345, 67, 'Rusia', 6.50, 0);

INSERT INTO Resultado  VALUES (346, 68, 'España', 2.40, 0);
INSERT INTO Resultado  VALUES (347, 68, 'Inglaterra', 2.25, 0);
INSERT INTO Resultado  VALUES (348, 68, 'Italia', 4.50, 0);
INSERT INTO Resultado  VALUES (349, 68, 'Francia', 26.00, 0);
INSERT INTO Resultado  VALUES (350, 68, 'Alemania', 51.00, 0);
INSERT INTO Resultado  VALUES (351, 68, 'Portugal', 41.00, 0);
INSERT INTO Resultado  VALUES (352, 68, 'Escocia', 101.00, 0);
INSERT INTO Resultado  VALUES (353, 68, 'Turquia', 101.00, 0);
INSERT INTO Resultado  VALUES (354, 68, 'Grecia', 67.00, 0);


INSERT INTO Apuesta VALUES (1, 'BloOdHooD',  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 10.50, 0, 0);

INSERT INTO Apuesta VALUES (2, 'Orlgaun',  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 15, 0, 0);

INSERT INTO Apuesta VALUES (3, 'Blazer',  to_date(sysdate, 'DD-MM-YY HH24:MI:SS'), 12.5, 0, 0);
  
  
INSERT INTO PreverResul VALUES ('BloOdHooD', 1, 3, 1);
INSERT INTO PreverResul VALUES ('Orlgaun', 2, 1, 1);
INSERT INTO PreverResul VALUES ('Blazer', 3, 2, 1);

