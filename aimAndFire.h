

!!==============================================================================
!!
!!	AIM AND FIRE
!!	Sistema de apuntado y disparo
!!
!!==============================================================================
!!
!!	File:			aimAndFire.h
!!	Author(s):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Language:		ES (Castellano)
!!	System:			Inform-INFSP 6
!!	Platform:		M�quina-Z / GLULX
!!	Version:		5.0
!!	Released:		2018/01/17
!!
!!------------------------------------------------------------------------------
!!
!!	Copyright (c) 2012, 2018, J. Francisco Mart�n
!!
!!	Este programa es software libre: usted puede redistribuirlo y/o
!!	modificarlo bajo los t�rminos de la Licencia P�blica General GNU
!!	publicada por la Fundaci�n para el Software Libre, ya sea la versi�n
!!	3 de la Licencia, o (a su elecci�n) cualquier versi�n posterior.
!!
!!	Este programa se distribuye con la esperanza de que sea �til, pero
!!	SIN GARANT�A ALGUNA; ni siquiera la garant�a impl�cita MERCANTIL o
!!	de APTITUD PARA UN PROP�SITO DETERMINADO. Consulte los detalles de
!!	la Licencia P�blica General GNU para m�s informaci�n.
!!
!!	Deber�a haber recibido una copia de la Licencia P�blica General GNU
!!	junto a este programa. En caso contrario, consulte
!!	<http://www.gnu.org/licenses/>.
!!
!!------------------------------------------------------------------------------
!!
!!	# HISTORIAL DE VERSIONES
!!
!!	5.0: 2018/01/17	Redefinici�n de la interfaz del objeto gestor. Adici�n de
!!					nivel de dificultad, modo de operaci�n probabilista (usado
!!					en M�quina-Z), formato del resultado basado en una divisi�n
!!					en zonas de la ventana de estado.
!!	4.4: 2017/08/04	Revisi�n de comentarios de la extensi�n.
!!	4.3: 2016/10/04	Parametrizaci�n del posicionamiento de las gu�as centrales
!!					en la animaci�n de apuntado. Extensi�n de la interfaz:
!!					'get_is_distance():integer', 'set_is_distance(integer)'.
!!	4.2: 2014/08/12 Extensi�n de la interfaz del gestor: m�todo
!!					'get_status_window_width()'.
!!	4.1: 2014/07/28	Refactorizaci�n de la l�gica de apuntado y disparo en el
!!					objeto gestor para evitar interferencias con otros sistemas
!!					que puedan hacer uso del temporizador Glk.
!!	4.0: 2014/03/19	Desactivada la l�gica del Movimiento Arm�nico Simple.
!!					Ventana de estado parametrizada.
!!	3.0: 2012/07/05	Pruebas con las ecuaciones del Movimiento Arm�nico Simple.
!!					Modo de depuraci�n.
!!	2.0: 2012/		Refactorizaci�n general, correcciones de l�gica y adici�n
!!					comentarios.
!!	1.0: 2012/		Sistema de apuntado y disparo basado en una animaci�n
!!					interactiva usando el temporizador Glk.
!!
!!------------------------------------------------------------------------------
!!
!!	# INTRODUCCI�N
!!
!!	'AimAndFire' es una extensi�n para la librer�a Inform que implementa un
!!	sistema de apuntado y disparo basado en una animaci�n interactiva en la
!!	m�quina virtual GLULX. Para facilitar la portabilidad de las obras a
!!	M�quina-Z, implementa adem�s un m�todo alternativo basado en
!!	probabilidades que no requiere del temporizador Glk exclusivo de GLULX.
!!
!!
!!	# 'AIM AND FIRE' EN GLULX
!!
!!	Aprovechando las funciones de tiempo real de GLULX, el mecanismo principal
!!	de 'AimAndFire' utiliza una animaci�n para representar la acci�n de
!!	apuntar, y determina el �xito del disparo en funci�n de la entrada del
!!	usuario y el estado de la animaci�n. Al iniciar el mecanismo, los
!!	contenidos de la ventana de estado de la obra se reemplazan por una
!!	ret�cula de apuntado animada con un movimiento de desplazamiento de extremo
!!	a extremo de la ventana hasta que el usuario pulsa una tecla. El resultado
!!	de la acci�n se determina en funci�n de lo lejos del centro de la ventana
!!	de estado que se haya conseguido detener la ret�cula.
!!
!!	Para utilizar el sistema, el desarrollador de la obra debe incluir la
!!	siguiente llamada dentro del punto de entrada 'HandleGlkEvent':
!!
!!		[ HandleGlkEvent ev;
!!			if (ev-->0 == 1) ! evtype_Timer
!!				AimingManager.tick();
!!		];
!!
!!
!!	# 'AIM AND FIRE' EN M�QUINA-Z
!!
!!	Como se ha indicado anteriormente, el uso del temporizador Glk es exclusivo
!!	de GLULX as� que las obras compiladas para M�quina-Z no pueden hacer uso de
!!	�l. Para facilitar la creaci�n de obras biplataforma, 'AimAndFire'
!!	implementa una aproximaci�n simplificada de la funcionalidad basada en
!!	probabilidades dependientes de la dificultad del sistema. Adem�s esta
!!	dificultad, modificable en tiempo de ejecuci�n, permite al desarrollador la
!!	posibilidad de establecer probabilidades de 0 o 1 ---indicando porcentajes
!!	de dificultad del 100% y del 0%, respectivamente--- que fuerzan el fallo o
!!	el acierto del sistema, de modo que puede eliminarse el factor probabilista
!!	y hacer que el resultado dependa exclusivamente de alg�n par�metro
!!	arbitrario como la resoluci�n de un 'puzzle' o un desaf�o l�gico por parte
!!	del usuario, por ejemplo.
!!
!!	En GLULX se puede utilizar tambi�n este modo de funcionamiento.
!!
!!
!!	# OBJETO GESTOR
!!
!!	La extensi�n define un objeto gestor 'AimingManager' en el que se
!!	implementan todas las funcionalidades del sistema. En la propia definici�n
!!	del objeto se incluye documentaci�n exhaustiva sobre la interfaz que ofrece
!!	al desarrollador de relatos interactivos.
!!
!!------------------------------------------------------------------------------
System_file;

!! Descomentar para obtener informaci�n de depuraci�n:
! Constant DEBUG_AIMANDFIRE;

!! Objeto gestor del sistema
Object	AimingManager "(Aiming Manager)"
 with	!!----------------------------------------------------------------------
		!! M�TODOS P�BLICOS:
		!!----------------------------------------------------------------------
		!! M�todo principal que implementa el sistema de apuntado y disparo.
		!! Tiene 2 modos de operaci�n, seleccionables a trav�s del par�metro
		!! opcional 'probabilistic':
		!!	0)	Utilizando una animaci�n de apuntado interactiva (s�lo en
		!!		GLULX). Al invocar al m�todo se inicia la animaci�n ---una
		!!		ret�cula movi�ndose de extremo a extremo de la ventana de
		!!		estado--- con una velocidad que se determina en funci�n del
		!!		nivel de dificultad del sistema, y que se detiene cuando el
		!!		usuario pulsa una tecla. El resultado indica bien la distancia
		!!		en n�mero de columnas entre la posici�n final de la ret�cula y
		!!		el centro de la ventana de estado o la zona de la ventana de
		!!		estado en la que se ha detenido, en funci�n del formato
		!!		establecido en el sistema.
		!!	1)	M�todo probabilista (�nico modo posible en M�quina-Z).
		!!		Determina fallo con una probabilidad P(Q) que depende del nivel
		!!		de dificultad 'difficulty' del sistema:
		!!		P(Q) = 1 - P(difficulty/100). El valor retornado se selecciona
		!!		aleatoriamente en funci�n de si se ha producido un acierto o un
		!!		fallo de entre conjuntos de valores que var�an a su vez en
		!!		funci�n del formato establecido en el sistema.
		!! Para establecer el formato de los resultados hay que invocar al
		!! m�todo 'set_format()' del gestor.
		!!
		!!	@param {boolean} [probabilistic=false] - Por defecto en GLULX el
		!!		sistema utiliza el modo de operaci�n 0, pero si se invoca al
		!!		m�todo con este par�metro verdadero se utiliza el modo 1. En
		!!		M�quina-Z el par�metro se ignora totalmente y se utiliza en
		!!		cualquier caso el modo de operaci�n 1 probabilista
		!!	@param {boolean} [reset_position_flag=false] - S�lo cuando se
		!!		utiliza el modo de operaci�n 0, al invocar el m�todo con este
		!!		par�metro verdadero evita que la ret�cula de apuntado inicie
		!!		la animaci�n desde el extremo izquierdo de la ventana y
		!!		desplaz�ndose hacia la derecha y, en su lugar, iniciar�a la
		!!		animaci�n desde la posici�n y con el sentido con el que se
		!!		detuvo la �ltima vez que la rutina fue invocada
		!!	@result {integer} Valores positivos cuando se considera que el
		!!		resultado ha sido un acierto; negativos si se considera un
		!!		fallo. El valor concreto del resultado depende del tipo de
		!!		formato del sistema
		!!----------------------------------------------------------------------
		aim_and_fire [ probabilistic reset_position_flag
			status_window_width result;
			#Ifdef TARGET_ZCODE;
			probabilistic = true;
			#Endif; ! TARGET_ZCODE;
			!! MODO DE OPERACI�N 1 ---------------------------------------------
			if (probabilistic) {
				!! FIXME - Modo de operaci�n probabilista
			}
			!! MODO DE OPERACI�N 0 ---------------------------------------------
			else {
				!! Asegura la correcta inicializaci�n de atributos del gestor:
				if (self.grid_vx == 0)
					self.set_difficulty(self.initial_difficulty);
				if (self.status_window == 0)
					self.status_window = gg_statuswin;
				self.delay_counter = 0;
				self.end_flag = false;
				!! Establece el punto de inicio y el sentido del movimiento de
				!! la ret�cula:
				if (~~reset_position_flag) {
					if (self.grid_vx < 0) self.grid_vx = self.grid_vx * -1;
					self.grid_x = 0;
				}
				!! Inicia el temporizador glk y activa la animaci�n:
				glk(214, self.timer_frequency); ! glk_request_timer_events(f);
				give self on;
				#Ifdef DEBUG_AIMANDFIRE;
				print "** AIM&FIRE: Velocidad ", self.grid_vx, " **^";
				#Endif; ! DEBUG_AIMANDFIRE;
				!! La animaci�n se detiene cuando el usuario pulsa una tecla:
				KeyCharPrimitive();
				self.end_flag = true;
				!! Calcula la distancia absoluta en n�mero de columnas entre la
				!! posici�n final de la ret�cula y el centro de la ventana de
				!! estado:
				glk($0025, self.status_window, gg_arguments, gg_arguments + 4);
				status_window_width = gg_arguments-->0;
				result = (self.grid_x/1000) + 1 - (status_window_width / 2);
				if (result < 0) result = -result;
				!! Retorna el resultado de la operaci�n con el formato adecuado:
				#Ifdef DEBUG_AIMANDFIRE;
				print "** AIM&FIRE: Resultados... **^";
				print "** Posici�n final de la ret�cula: ", result, " **^";
				print "** Ancho de la ventana/Medio: ", status_window_width,
				" / ", (status_window_width/2), " **^";
				print "** Resultado: ", self.format_result(result), " **^";
				#Endif; ! DEBUG_AIMANDFIRE;
				return self.format_result(result);
			}
		],
		!!----------------------------------------------------------------------
		!!	@returns {integer} Milisegundos que se sigue mostrando la posici�n
		!!		final de la ret�cula una vez detenida la animaci�n de apuntado
		!!----------------------------------------------------------------------
		get_delay_value [; return self.delay_value; ],
		!!----------------------------------------------------------------------
		!!	@returns {integer} Dificultad establecida en el sistema
		!!----------------------------------------------------------------------
		get_difficulty [; return self.difficulty; ],
		!!----------------------------------------------------------------------
		!!	@returns {integer} Tipo de formato de los resultados establecido en
		!!		el sistema [0-1]
		!!----------------------------------------------------------------------
		get_format_type [; return format_type; ],
		!!----------------------------------------------------------------------
		!!	@returns {String|integer} Ret�cula de apuntado
		!!----------------------------------------------------------------------
		get_grid [; return self.grid; ],
		!!----------------------------------------------------------------------
		!!	@returns {integer} Distancia al centro de la ventana de estado, en
		!!		n�mero de columnas, a la que se imprimen las gu�as centrales
		!!----------------------------------------------------------------------
		get_iron_sight_distance [; return self.iron_sight_distance; ],
		!!----------------------------------------------------------------------
		!!	@returns {character|integer} Caracter con el que se representan las
		!!		gu�as centrales
		!!----------------------------------------------------------------------
		get_iron_sight_symbol [; return self.iron_sight_symbol; ],
		!!----------------------------------------------------------------------
		!!	@returns {Object} Ventana de estado establecida en el sistema
		!!----------------------------------------------------------------------
		get_status_window [; return self.status_window; ],
		!!----------------------------------------------------------------------
		!! Reestablece los par�metros iniciales del sistema.
		!!----------------------------------------------------------------------
		reset [;
			self.delay_value = self.initial_delay_value;
			self.difficulty = self.initial_difficulty;
			self.format_type = self.initial_format_type;
			self.grid = self.initial_grid;
			self.grid_length = self.initial_grid_length;
			self.grid_vx = self.initial_grid_vx;
			self.grid_x = self.initial_grid_x;
			self.iron_sight_distance = self.initial_iron_sight_distance;
			self.iron_sight_symbol = self.initial_iron_sight_symbol;
			self.status_window = self.initial_status_window;
		],
		!!----------------------------------------------------------------------
		!! Establece el n�mero de milisegundos que se sigue mostrando la
		!! posici�n final de la ret�cula una vez detenida la animaci�n de
		!! apuntado. En M�quina-Z no realiza ning�n cambio.
		!!
		!!	@param {integer} a - Nuevo tiempo de espera (en ms)
		!!	@returns {integer} El tiempo de espera previo (en ms)
		!!----------------------------------------------------------------------
		set_delay_value [ a
			result;
			result = self.delay_value;
			#Ifdef TARGET_GLULX;
			self.delay_value = a;
			#Endif; ! TARGET_GLULX;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece la dificultad del sistema. En GLULX se modifica adem�s la
		!! velocidad de la ret�cula de apuntado atendiendo a que antes de
		!! modificar el valor de la velocidad es necesario registrar el sentido
		!! del movimiento previo de modo que el nuevo valor tenga el mismo
		!! sentido (mismo signo).
		!!
		!!	@param {integer} difficulty - Valor comprendido en el rango [0-100]
		!!		que se establece como nueva dificultad del sistema
		!!	@returns {integer} El valor de dificultad previo. -1 si el
		!!		par�metro 'a' se sale del rango v�lido y no se produce el
 		!!		cambio de dificultad
		!!----------------------------------------------------------------------
		set_difficulty [ a
			negative_v result;
			if (a < 0 || a > 100) return -1;
			result = self.difficulty;
			self.difficulty = a;
			#Ifdef TARGET_GLULX;
			if (self.grid_vx < 0) negative_v = true;
			self.grid_vx = ((self.difficulty * (self.grid_min_vx
				* self.grid_max_vx_factor)) / 100) + self.grid_min_vx;
			if (negative_v) self.grid_vx = self.grid_vx * -1;
			#Endif; ! TARGET_GLULX;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece el tipo de formato de los resultados.
		!!
		!!	@param {integer} a - Nuevo tipo de formato [0-1]
		!!	@returns {integer} El tipo de formato previo. -1 si el par�metro
		!!		'a' se sale del rango v�lido y no se produce el cambio de
		!!		formato
		!!----------------------------------------------------------------------
		set_format_type [ a
			result;
			if (a < 0 || a > 1) return -1;
			result = self.format_type;
			self.format_type = a;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece la ret�cula de apuntado (calcula adem�s el ancho de la
		!! nueva ret�cula). En M�quina-Z no realiza ning�n cambio.
		!!
		!!	@param {String} a - Nueva ret�cula de apuntado
		!!	@returns {String|integer} La ret�cula de apuntado previa
		!!----------------------------------------------------------------------
		set_grid [ a
			result;
			result = self.grid;
			#Ifdef TARGET_GLULX;
			!! FIXME - Debe calcularse el ancho de la nueva ret�cula
			self.grid = a;
			#Endif; ! TARGET_GLULX;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece la distancia al centro de la ventana de estado, en n�mero
		!! de columnas, a la que se imprimen las gu�as centrales. En M�quina-Z
		!! no realiza ning�n cambio.
		!!
		!!	@param {integer} a - Nueva distancia al centro de la ventana de
		!!		estado de las gu�as centrales (en n�mero de columnas)
		!!	@returns {integer} La distancia previa
		!!----------------------------------------------------------------------
		set_iron_sight_distance [ a
			result;
			result = self.iron_sight_distance;
			#Ifdef TARGET_GLULX;
			self.iron_sight_distance = a;
			#Endif; ! TARGET_GLULX;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece el caracter con el que se representan las gu�as centrales.
		!! En M�quina-Z no realiza ning�n cambio.
		!!
		!!	@param {character} a - Nuevo caracter para representar las gu�as
		!!		centrales
		!!	@returns {character|integer} El caracter con el que se
		!!		representaban las gu�as centrales previamente
		!!----------------------------------------------------------------------
		set_iron_sight_symbol [ a
			result;
			result = self.iron_sight_symbol;
			#Ifdef TARGET_GLULX;
			self.iron_sight_symbol = a;
			#Endif; ! TARGET_GLULX;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece la ventana de estado del sistema.
		!!
		!!	@param {Object} a - Nueva ventana de estado
		!!	@returns {Object} La ventana de estado previa
		!!----------------------------------------------------------------------
		set_status_window [ a
			result;
			result = self.status_window;
			self.status_window = a;
			return result;
		],
		!!----------------------------------------------------------------------
		!! Operaci�n encargada de realizar la animaci�n en la ventana de
		!! estado. Debe invocarse desde el punto de entrada 'HandleGlkEvent()'
		!! para que se ejecute en cada ciclo del temporizador glk:
		!!
		!!		[ HandleGlkEvent ev;
		!!			if (ev-->0 == 1) ! evtype_Timer
		!!				AimingManager.tick();
		!!		];
		!!
		!!	@returns {boolean} Falso si el gestor no est� preparado para
		!!		mostrar la animaci�n. Verdadero en otro caso
		!!----------------------------------------------------------------------
		tick [
			status_window_width;
			print "* ", self.grid_x, " / ", (self.grid_x/1000), " *^";
			#Ifdef TARGET_ZCODE;
			return false;
			#Ifnot; ! TARGET_GLULX;
			!! Si el sistema no est� activado o no tiene definida una ventana
			!! de estado en la mostrar la animaci�n de apuntado, retorna
			if (self hasnt on || self.status_window == 0) {
				glk(214, 0); ! glk_request_timer_events(0)
				return false;
			}
			!! Se calcula el ancho de la ventana de estado (debe calcularse en
			!! cada evento del temporizador por si la ventana ha sido
			!! redimensionada por el usuario)
			glk($0025, self.status_window, gg_arguments, gg_arguments + 4);
			status_window_width = gg_arguments-->0;
			!! Mientras el usuario no detenga la animaci�n, se muestra
			if (~~self.end_flag) {
				switch (self.motion_type) {
					0:	self.update_grid_position_LM(status_window_width);
					1:	self.update_grid_position_SHM(status_window_width);
				}
				self.draw_aiming_line(status_window_width);
			}
			!! Tras ser detenida, la posici�n final de la ret�cula a�n se
			!! muestra en la ventana de estado durante unos milisegundos
			else {
				self.draw_aiming_line(status_window_width);
				self.delay_counter++;
				if (self.delay_counter > self.delay_value) {
					glk(214, 0); ! glk_request_timer_events(0)
					self.delay_counter = 0;
					give self ~on;
					DrawStatusLine();
				}
			}
			#Endif; ! TARGET_
		],
 private
		!!----------------------------------------------------------------------
		!! M�TODOS PRIVADOS:
		!!----------------------------------------------------------------------
		!! FIXME - Documentaci�n
		!!----------------------------------------------------------------------
		draw_aiming_line [ status_window_width;
			!! Si no hay ventana de estado definida, retorna
			if (self.status_window == 0) {
				#Ifdef DEBUG_AIMANDFIRE;
				print "** AIM&FIRE: No hay definida ventana de estado para
				pintar la animaci�n de apuntado. **^";
				#Endif; ! DEBUG_AIMANDFIRE;
				return false;
			}
			!! Inicializa la ventana de estado
			glk($002F, self.status_window); ! set_window
			!! TODO - �Establecer alto de la ventana con StatusLineHeight()?
			glk($002A, self.status_window); ! window_clear
			!! Imprime las gu�as
			glk($002B, self.status_window, ((status_window_width / 2)
				- self.iron_sight_distance), 0); ! window_move_cursor
			print (char) self.iron_sight_symbol;
			glk($002B, self.status_window, ((status_window_width / 2)
				+ self.iron_sight_distance), 0); ! window_move_cursor
			print (char) self.iron_sight_symbol;
			!! Imprime la ret�cula
			glk($002B, self.status_window, (self.grid_x/1000), 0);
			print (string) self.grid;
			!! Reestablece la ventana principal
			glk($002F, gg_mainwin);
			return true;
		],
		!!----------------------------------------------------------------------
		!! FIXME - Documentaci�n
		!!----------------------------------------------------------------------
		format_result [ raw
			result;
			switch (self.format_type) {
				0:	! Divisi�n de la ventana de estado en zonas
					if (raw == 0) result = 0;
					else if (raw <= self.iron_sight_distance) result = 1;
					else if (raw <= (self.iron_sight_distance * 4)) result = -2;
					else result = -3;
				1:	! Divisi�n de la ventana de estado en columnas
					if (raw <= self.iron_sight_distance) result = raw;
					else result = -raw;
			}
			return result;
		],
		!!----------------------------------------------------------------------
		!! Actualiza la posici�n de la ret�cula (Movimiento Rectil�neo
		!! Uniforme).
		!!----------------------------------------------------------------------
		update_grid_position_LM [ status_window_width; ! Linear Motion
			if ((self.grid_x/1000) < 0 || (self.grid_x/1000)
				> status_window_width - self.grid_length) {
				self.grid_vx = self.grid_vx * -1;
			}
			self.grid_x = self.grid_x + self.grid_vx;
		],
		!!----------------------------------------------------------------------
		!! XXX - C�digo GLULX para mover la posici�n de la ret�cula utilizando
		!! Movimiento Arm�nico Simple. Para hacerlo funcional, habr�a que
		!! modificar el algoritmo para ajustar el tiempo a la frecuencia del
		!! temporizador glk, de modo que no se produjesen saltos entre
		!! posiciones consecutivas y simplemente se modificase el n�mero de
		!! ticks de reloj en cada posici�n.
		!!----------------------------------------------------------------------
		update_grid_position_SHM [ ! Simple Harmonic Motion
			i ini sini aux gp;
			i = ini + sini + aux + gp;
			!! aux = WIN_WIDTH/2;
			!! @numtof aux ini; ! ini: centro de la ventana
			!! @numtof GRID_COUNTER i; ! i: contador
			!! @sin i sini; ! sini: seno de GRID_COUNTER
			!! @fmul ini sini aux; ! aux: (WIN_WIDTH/2)*sin(GRID_COUNTER)
			!!
			!! if (GRID_MOVEMENT == 0) @fadd ini aux gp;
			!! else @fsub ini aux gp;
			!! @ftonumn gp GRID_POS;
			!!
			!! GRID_COUNTER++;
			!! if (GRID_COUNTER == 180)
			!! {	GRID_COUNTER = 0;
			!! 	if (GRID_MOVEMENT == 0) GRID_MOVEMENT = 1;
			!! 	else GRID_MOVEMENT = 0;
			!! }
		],
		!!----------------------------------------------------------------------
		!! ATRIBUTOS:
		!!----------------------------------------------------------------------
		!! N�mero de milisegundos que se sigue mostrando la posici�n final de
		!! la ret�cula tras haber detenido la animaci�n:
		delay_value 100, initial_delay_value 100,
		!! Valor num�rico comprendido en el rango [0-100] que expresa la
		!! dificultad para conseguir un acierto;
		!!	-	En GLULX afecta a la velocidad de movimiento de la ret�cula;
		!!		con 0 indicando velocidad m�nima, y 100 velocidad m�xima.
		!!	-	En M�quina-Z afecta a la probabilidad P(Q) de NO conseguir un
		!!		resultado positivo: P(Q) = 1 - difficulty/100
		difficulty 50, initial_difficulty 50,
		!! Indicador del formato utilizado para los resultados de la operaci�n
		!! de apuntado y disparo:
		!!	0)	Divisi�n de la ventana de estado en las siguientes zonas:
		!!		0)	Centro exacto de la ventana.
		!!		1)	Zona comprendida dentro de las dos gu�as centrales.
		!!		-2)	Fuera de las gu�as centrales, a una distancia igual o
		!!			inferior a la que hay entre el centro de la ventana y
		!!			cualquiera de las dos gu�as.
		!!		-3)	Fuera de las gu�as centrales, a una distancia superior a
		!!			la delimitada por la zona 2.
		!!		Cuando se usa el modo de operaci�n 0, usando una animaci�n
		!!		interactiva, el resultado indica el n�mero de zona en el que el
		!!		usuario ha conseguido detener la ret�cula de apuntado. En el
		!!		modo de operaci�n 1, probabilista, se retorna aleatoriamente
		!!		{0,1} o {-2,-3} en funci�n de si se logra un acierto o un
		!!		fallo, respectivamente.
		!!	1)	Divisi�n de la ventana de estado en columnas. En el modo de
		!!		operaci�n 0, usando una animaci�n interactiva, el resultado es
		!!		la distancia absoluta en n�mero de columnas de la posici�n
		!!		final en la que se ha detenido la ret�cula y el centro de la
		!!		ventana de estado. Con valores positivos si se ha detenido a
		!!		una distancia igual o inferior a la delimitada por las gu�as
		!!		centrales, y valores negativos en caso contrario. En el modo de
		!!		operaci�n 1, probabilista, el resultado se selecciona
		!!		aleatoriamente de entre el conjunto [0, iron_sight_distance],
		!!		si es un acierto, y entre (iron_sight_distance, <ancho de la
		!!		ventana de estado>], con valor negativo, si es un fallo.
		format_type 0, initial_format_type 0,
		!! Cadena que forma la ret�cula de apuntado:
		grid "[+]", initial_grid "[+]",
		!! Factor de multiplicaci�n de la velocidad m�nima con el que se
		!! calcula la velocidad m�xima de la ret�cula:
		grid_max_vx_factor 25, initial_grid_max_vx_factor 25,
		!! Velocidad actual de la ret�cula (valor/1000):
		grid_vx 0, initial_grid_vx 0,
		!! Posici�n de la ret�cula (valor/1000):
		grid_x 0, initial_grid_x 0,
		!! Longitud de la ret�cula en n�mero de caracteres:
		grid_length 3, initial_grid_length 3,
		!! Distancia al centro de la ventana de estado en n�mero de columnas a
		!! la que se imprimen las gu�as centrales (valor absoluto utilizado por
		!! las dos gu�as; en positivo y negativo):
		iron_sight_distance 3, initial_iron_sight_distance 3,
		!! Caracter con el que se representan las gu�as centrales:
		iron_sight_symbol '�', initial_iron_sight_symbol '�',
		!! Ventana de estado sobre la que se muestra la animaci�n de apuntado:
		status_window 0, initial_status_window 0,
		!!----------------------------------------------------------------------
		!! Velocidad m�nima de la ret�cula (valor/1000):
		grid_min_vx 120,
		!! Contador interno:
		delay_counter 0,
		!! Indica si el usuario ha detenido la animaci�n de la ret�cula:
		end_flag false,
		!! Frecuencia con que se activa el temporizador glk (ms):
		!! C�digo num�rico del tipo de movimiento de la animaci�n de apuntado:
		!!	0)	Movimiento Rectil�neo Uniforme
		!!	1)	Movimiento Arm�nico Simple
		motion_type 0,
		!! Frecuencia con que se activa el temporizador Glk (en ms):
		timer_frequency 16,
;
