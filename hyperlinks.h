

!!==============================================================================
!!
!!	HYPERLINKS
!!	Rutinas para facilitar la interacci�n por hiperv�nculos
!!
!!==============================================================================
!!
!!	Archivo:		hyperlinks.h
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		1.3
!!	Fecha:			2018/07/23
!!
!!------------------------------------------------------------------------------
!!
!!	Copyright (c) 2018, J. Francisco Mart�n
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
!!	HISTORIAL DE VERSIONES
!!
!!	1.3: 2018/07/23 A�adido nuevo modo de funcionamiento de los hiperv�nculos
!!					generados con una cadena de texto alternativa. Consultar el
!!					apartado COMPORTAMIENTO AL UTILIZAR CADENAS DE TEXTO
!!					ALTERNATIVAS de la documentaci�n para m�s informaci�n.
!!	1.2: 2018/06/12	A�adida opci�n de desactivar los hiperv�nculos,
!!					configurable por el usuario a trav�s de la redefinici�n de
!!					la nueva rutina 'HyperlinkStatus()'.
!!	1.1: 2018/06/06	Nueva funci�n 'ListenHyperlinkEvents()' para activar la
!!					escucha de eventos de tipo pulsaci�n de hiperv�nculo.
!!					A�adidas comprobaciones de las capacidades del int�rprete
!!					antes de definir un hiperv�nculo en 'Hyperlink()'. A�adido
!!					'eco' a la entrada de usuario al utilizar hiperv�nculos.
!!	1.0: 2018/03/05	Versi�n inicial de la extensi�n.
!!
!!------------------------------------------------------------------------------
!!
!!	INSTALACI�N
!!
!!	Es importante tener en cuenta que la utilizaci�n de hiperv�nculos s�lo est�
!!	soportada por la m�quina virtual Glulx, y que no todos los int�rpretes de
!!	Glulx implementan esta funcionalidad. A�n as�, la extensi�n puede
!!	utilizarse tanto en Glulx como en M�quina-Z (en esta segunda ---o en
!!	aquellos int�rpretes Glulx que no soporten hiperv�nculos--- simplemente
!!	no es posible utilizar la funcionalidad). Para hacerlo hay que a�adir la
!!	siguiente l�nea en el fichero principal de la obra, inmediatamente despu�s
!!	de la l�nea 'Include "Parser";':
!!
!!		Include "hyperlinks";
!!
!!	Son necesarias, adem�s, otras dos consideraciones: Por una parte, 1) debe
!!	activarse la escucha de eventos glk de selecci�n de hiperv�nculos en las
!!	ventanas principales de la aplicaci�n. Para ello, basta con invocar a la
!!	funci�n 'ListenHyperlinkEvents()' en el punto de entrada 'Initialise()':
!!
!! 		[ Initialise;
!!			ListenHyperlinkEvents();
!!
!! 			!! Resto de contenidos del punto de entrada:
!! 			[...]
!! 		];
!!
!!	Por �ltimo, 2) hay que introducir la l�gica encargada de capturar y
!!	responder a esos eventos Glk de tipo hiperv�nculo. Esta l�gica debe
!!	encontrarse dentro del punto de entrada Glulx 'HandleGlkEvent()' ---crearlo
!!	si no existe---:
!!
!! 		#Ifdef TARGET_GLULX;
!! 		[ HandleGlkEvent ev context abortres;
!! 			if (HandleHyperlinkEvent(ev, context, abortres)) return 2;
!! 		];
!! 		#Endif; ! TARGET_GLULX;
!!
!!	NOTA: Destacar la utilizaci�n de directivas de compilaci�n condicionales
!!	en el �ltimo ejemplo para permitir la compilaci�n biplataforma.
!!
!!
!!	COMPORTAMIENTO AL UTILIZAR CADENAS DE TEXTO ALTERNATIVAS
!!
!!	Al generar un hiperv�nculo con la rutina 'Hyperlink()' se puede incluir una
!!	cadena de texto alternativa adem�s del elemento (objeto o cadena de texto)
!!	sobre el que se genera el hiperv�nculo. Esta cadena de texto alternativa se
!!	imprimir� en el lugar del elemento a la hora de crear el hiperv�nculo. Hay,
!!	adem�s, dos modos de funcionamiento posibles al seleccionar un hiperv�nculo
!!	creado utilizando una cadena de texto alternativa:
!!
!!	1)	Por defecto, al seleccionar el hiperv�nculo se lanza el comando
!!		guardado en la variable '_hyperlinks_command', sobre la cadena de texto
!!		alternativa. Se entiende que esta cadena de texto debe ser un sin�nimo
!!		del nombre del elemento. As�, si se crea un hiperv�nculo sobre un
!!		hipot�tico objeto de nombre 'piedra' de la siguiente manera:
!!
!!			Hyperlink(piedra, "roca");
!!
!!		En pantalla se imprimir� la cadena alternativa "roca", y al seleccionar
!!		dicho hiperv�nculo se lanzar� el comando "<_hyperlinks_command> ROCA".
!!		Debe asegurarse que el objeto 'piedra' est� definido con el sin�nimo
!!		'roca'. De lo contrario el comando no reconocer� ning�n objeto.
!!
!!	2)	Para evitar este �ltimo comportamiento, es posible utilizar un segundo
!!		modo de funcionamiento definiendo la constante 'HYPERLINKS_ALT_MODE'
!!		como verdadera. As�, el hiperv�nculo del ejemplo anterior se imprimir�
!!		en pantalla igualmente con la cadena alternativa "roca" pero, al
!!		seleccionarlo, se lanzar�a en cambio el comando:
!!		"<_hyperlinks_command> PIEDRA". Este modo de funcionamiento garantiza
!!		que no se generen comandos que no sean reconocidos por la falta de
!!		definici�n de alg�n sin�nimo (tambi�n rompe ligeramente cierta
!!		coherencia de la interfaz).
!!
!!------------------------------------------------------------------------------
!!
!!	TABLA DE CONTENIDOS
!!
!!	<>	HandleHyperlinkEvent()
!!	<>	Hyperlink()
!!	<>	HyperlinkSetStyle()
!!	<>	HyperlinkStatus()
!!	<>	ListenHyperlinkEvents()
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef HYPERLINKS;
Constant HYPERLINKS;

!! Comportamiento de los hiperv�nculos generados con un texto alternativo:
Default HYPERLINKS_ALT_MODE = false;

!! Comando por defecto al seleccionar un hiperv�nculo:
Default _hyperlinks_command = "examina";

!! Array de apoyo para la gesti�n de los eventos de selecci�n de hiperv�nculos:
Array _hyperlinks_temp_array -> INPUT_BUFFER_LEN/WORDSIZE*2;

#Ifdef TARGET_GLULX;
!!------------------------------------------------------------------------------
!! Gestiona la respuesta a los eventos Glk de tipo hiperv�nculo. Ideada para
!! ser invocada desde el punto de entrada 'HandleGlkEvent()'.
!!
!!	@param {array} ev - Array de 4 palabras que describe el evento. ev-->0
!!		registra un c�digo num�rico con que se determina el tipo de evento. La
!!		rutina s�lo act�a si se trata de un evento de tipo hiperv�nculo
!!		(ev-->0 == 8); ev-->1 indica la ventana sobre la que se ha producido el
!!		evento; ev-->2 el objeto o cadena de caracteres sobre el que se ha
!!		creado el hiperv�nculo; ev-->3, reservado para informaci�n adicional,
!!		no se utiliza
!!	@param {integer} context - 0 si el evento se ha producido durante una
!!		entrada de l�nea (comandos normales u otros usos de la funci�n de la
!!		librer�a 'KeyboardPrimitive()'); la aplicaci�n debe esperar a que el
!!		usuario pulse INTRO antes de dar respuesta para la entrada. 1 si el
!!		evento se ha producido durante una entrada de caracter (funci�n de la
!!		librer�a 'KeyCharPrimitive()'); la aplicaci�n responde ante cada
!!		pulsaci�n de tecla, como en los men�s, por ejemplo
!!	@param {array} abortres - Utilizado para cancelar la entrada de texto y
!!		forzar una entrada particular. La longitud de la nueva entrada se
!!		registra en 'abortres-->0'. Si es diferente de 0, los caracteres del
!!		comando deben escribirse en el array secuencialmente desde la posici�n
!!		'abortres->WORDSIZE' hasta 'abortres->(WORDSIZE+length)' (no
!!		inclusive). No pueden superarse los 256 caracteres
!!	@returns {boolean} Verdadero para indicar que la entrada de usuario debe
!!		ser ignorada y finalizar el turno con la nueva entrada indicada en el
!!		par�metro 'abortres'
!!------------------------------------------------------------------------------
[ HandleHyperlinkEvent ev context abortres
	length i;
	if (ev-->0 == 8) { ! evtype_Hyperlink
		!! Tras capturar con �xito el evento de selecci�n de un hiperv�nculo la
		!! aplicaci�n deja de esperar nuevos eventos de este tipo, de modo que
		!! es necesario activar de nuevo su escucha. Para poder capturar uno de
 		!! estos eventos por primera vez es necesario activar su escucha
		!! tambi�n al inicio de la obra (en el punto de entrada 'Initialise()',
		!! por ejemplo):
		ListenHyperlinkEvents();
		!! Se cancelan los inputs de teclado:
		glk($00D3, gg_mainwin);		! glk_cancel_char_event
		glk($00D1, gg_mainwin, 0);	! glk_cancel_line_event
		!! 1) Si el hiperv�nculo se ha creado sobre un objeto, la entrada de
		!! usuario se genera como la combinaci�n de la orden registrada en el
		!! string _hyperlinks_command, el s�mbolo espacio ' ', y el nombre del
		!! objeto:
		if (metaclass(ev-->2) == Object) {
			if (metaclass(_hyperlinks_command) == String) {
				PrintToBuffer(abortres, INPUT_BUFFER_LEN, _hyperlinks_command);
				#Ifdef DEBUG_HYPERLINKS;
				print "** Acci�n del hiperv�nculo: ";
				print "(tam = ", (abortres-->0), ") ";
				for (i = WORDSIZE : i < (abortres-->0) + WORDSIZE : i++) {
					print (char) abortres->i;
				}
				print " **^";
				#Endif; ! DEBUG_HYPERLINKS;
				length = abortres->(WORDSIZE-1);
				if (length >= 1) {
					abortres->(WORDSIZE+length) = ' ';
					(abortres->(WORDSIZE-1))++;
					length = abortres->(WORDSIZE-1);
				}
			}
			PrintToBuffer(_hyperlinks_temp_array,
				INPUT_BUFFER_LEN/WORDSIZE * 2, ev-->2);
			for (i=WORDSIZE : i<(_hyperlinks_temp_array-->0)+WORDSIZE : i++) {
				abortres->(length+i) = _hyperlinks_temp_array->i;
				(abortres->(WORDSIZE-1))++;
			}
			#Ifdef DEBUG_HYPERLINKS;
			print "** Comando completo del hiperv�nculo: ";
			print "(tam = ", (abortres-->0), ") ";
			for (i = WORDSIZE : i < (abortres-->0) + WORDSIZE : i++) {
				print (char) abortres->i;
			}
			print " **^";
			#Endif; ! DEBUG_HYPERLINKS;
			!! Imprime el eco de la entrada de texto:
			glk($0086, 8); ! style_Input
			glk($0084, buffer+WORDSIZE, buffer-->0);
			glk($0086, 0); ! style_Normal
			new_line;
			return true;
		}
		!! 2) Si el hiperv�nculo se ha creado sobre un string, la entrada de
		!! usuario es �l mismo:
		if (metaclass(ev-->2) == String) {
			PrintToBuffer(abortres, INPUT_BUFFER_LEN, ev-->2);
			#Ifdef DEBUG_HYPERLINKS;
			print "** Comando completo del hiperv�nculo: ";
			print "(tam = ", (abortres-->0), ") ";
			for (i = WORDSIZE : i < (abortres-->0) + WORDSIZE : i++) {
				print (char) abortres->i;
			}
			print " **^";
			#Endif; ! DEBUG_HYPERLINKS;
			!! Imprime el eco de la entrada de texto:
			glk($0086, 8); ! style_Input
			glk($0084, buffer+WORDSIZE, buffer-->0);
			glk($0086, 0); ! style_Normal
			new_line;
			return true;
		}
	}
	if (ev-->0 == 3) { ! evtype_LineInput
		!! Imprime el eco de la entrada de texto:
		glk($0086, 8); ! style_Input
		glk($0084, buffer+WORDSIZE, buffer-->0);
		glk($0086, 0); ! style_Normal
		new_line;
		return true;
	}
	context++; ! (por evitar alertas del compilador)
	return false;
];
#Endif; ! TARGET_GLULX;

!!------------------------------------------------------------------------------
!! Crea un hiperv�nculo a partir del objeto o la cadena de caracteres pasado
!! como par�metro, de forma que el texto impreso del hiperv�nculo es el nombre
!! corto del objeto o la propia cadena de caracteres. Admite dos par�metros
!! opcionales; 1) una cadena de caracteres con un texto alternativo que se
!! imprime en lugar del nombre corto del objeto o de la cadena, 2) un par�metro
!! extra que puede ser utilizado libremente en las rutinas: 'HyperlinkStatus()'
!! e 'HyperlinkSetStyle()'.
!!
!!	@param {Object|String} item - Objeto o cadena de caracteres sobre la que se
!!		genera el hiperv�nculo. Si es un objeto, la entrada que se ejecuta al
!!		seleccionar el hiperv�nculo es un comando con el verbo definido en
!!		'_hyperlinks_command' y el objeto. Si es una cadena de caracteres, la
!!		entrada que se ejecuta es ella misma
!!	@param {String} [alternative] - Texto alternativo con que se imprime el
!!		hiperv�nculo. Si no se indica ninguno, como texto del hiperv�nculo se
!!		utiliza el nombre del objeto o la cadena de caracteres del par�metro
!!		'item'
!!	@param extra1 - Par�metro libre para controlar la l�gica de la rutina
!!		'HyperlinkSetStyle()'
!!	@param extra2 - Par�metro libre para controlar la l�gica de la rutina
!!		'HyperlinkStatus()'
!!	@returns {boolean} Verdadero
!!------------------------------------------------------------------------------
[ Hyperlink item alternative extra1 extra2
	previous_style hyperlink_active;
	if (metaclass(item) ~= string or Object) return false;
	!! Establece el estilo del hiperv�nculo:
	previous_style = HyperlinkSetStyle(item, extra1);
	!! Determina si el hiperv�nculo se debe desactivar o no:
	hyperlink_active = HyperlinkStatus(item, extra2);
	#Ifdef TARGET_GLULX;
	!! Establece el inicio del hiperv�nculo:
	if (hyperlink_active && glk($0004, 11, 0)) {
		if (HYPERLINKS_ALT_MODE == false && metaclass(alternative) == string) {
			glk($0100, alternative); ! glk_set_hyperlink();
		} else {
			glk($0100, item); ! glk_set_hyperlink();
		}
	}
	#Endif; ! TARGET_GLULX;
	!! Imprime el texto del hiperv�nculo:
	if (metaclass(alternative) == string) item = alternative;
	switch (metaclass(item)) {
		string:
			print (string) item;
		Object:
			if (indef_mode && item.&short_name_indef ~= 0
				&& PrintOrRun(item, short_name_indef, 1) ~= 0)
				jump hyperlinkTextPrinted;
			if (item.&short_name ~= 0 && PrintOrRun(item, short_name, 1) ~= 0)
				jump hyperlinkTextPrinted;
			print (object) item;
	}
	.hyperlinkTextPrinted;
	#Ifdef TARGET_GLULX;
	!! Establece el final del hiperv�nculo:
	if (hyperlink_active && glk($0004, 11, 0)) {
		glk($0100, 0); ! glk_set_hyperlink();
	}
	#Endif; ! TARGET_GLULX;
	!! Reestablece el estilo de texto normal:
	HyperlinkSetStyle(0, previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Selecciona el estilo de texto utilizado por los hiperv�nculos. Por defecto
!! utiliza los mismos estilos de texto presentes en M�quina-Z, pero puede ser
!! reescrita para definir un comportamiento m�s complejo o aumentar el n�mero
!! de estilos disponibles utilizando una sentencia 'Replace HyperlinkSetStyle;'
!! antes de incluir la extensi�n.'Hyperlink()' invoca a esta rutina 2 veces:
!!
!!	1)	Antes de crear el hiperv�nculo, para establecer el estilo con el que
!!		se imprime. En esta etapa el valor del par�metro 'item' es distinto de
!!		0 (item ~= 0).
!!	2)	Tras la creaci�n del hiperv�nculo, para reestablecer el estilo normal
!!		de la obra. En esta estapa el valor de 'item' es siempre 0 (item == 0).
!!
!!	@param {Object|String} item - En la etapa (1) contiene al objeto o la
!!		cadena de caracteres sobre la que se va a generar el hiperv�nculo. En
!!		la etapa (2) siempre es 0
!!	@param {integer} style - C�digo num�rico para identificar el estilo de
!!		texto a utilizar, en base a los estilos de texto de M�quina-Z:
!!		0) normal, 1) subrayado, 2) negrita y 3) ancho-fijo
!!	@returns {integer} C�digo num�rico que identifica el estilo de texto
!!		utilizado antes de invocar a la rutina. El resultado retornado durante
!!		la etapa (1) se pasa como par�metro en la etapa (2) para reestablecer
!!		el estilo de texto que hab�a en la obra antes de imprimir el
!!		hiperv�nculo
!!------------------------------------------------------------------------------
[ HyperlinkSetStyle item style;
	item = style; ! (por evitar alertas del compilador)
	switch (style) {
		1:	! Subrayado
			#Ifdef TARGET_ZCODE;
			font on; style roman;
			style underline;
			#Ifnot; ! TARGET_GLULX;
			glk($0086, 1); ! style_Emphasized
			#Endif; ! TARGET_
		2:	! Negrita
			#Ifdef TARGET_ZCODE;
			font on; style roman;
			style bold;
			#Ifnot; ! TARGET_GLULX;
			glk($0086, 4); ! style_Subheader
			#Endif; ! TARGET_
		3:	! Ancho-fijo
			#Ifdef TARGET_ZCODE;
			font on; style roman;
			font off;
			#Ifnot; ! TARGET_GLULX;
			glk($0086, 2); ! style_Preformatted
			#Endif; ! TARGET_
		default: ! Normal
			#Ifdef TARGET_ZCODE;
			font on; style roman;
			#Ifnot; ! TARGET_GLULX;
			glk($0086, 0); ! style_Normal
			#Endif; ! TARGET_
	}
	!! Retorna 0 para reestablecer el estilo de texto normal en la etapa (2):
	return 0;
];

!!------------------------------------------------------------------------------
!! Determina si el pr�ximo hiperv�nculo est� o no activado. Por defecto siempre
!! retorna verdadero ---los hiperv�nculos est�n siempre activados---, pero
!! puede ser reescrita utilizando una sentencia 'Replace HyperlinkStatus;'
!! antes de incluir la extensi�n.
!!
!!	@param {Object|String} item - Contiene al objeto o la cadena de caracteres
!!		sobre la que se va a generar el hiperv�nculo
!!	@param extra - Par�metro libre para controlar la l�gica de la rutina
!!	@returns {boolean} Verdadero para indicar que el hiperv�nculo est�
!!		activado. Falso en caso contrario
!!------------------------------------------------------------------------------
[ HyperlinkStatus item extra;
	item = extra; ! (por evitar alertas del compilador)
	return true;
];

!!------------------------------------------------------------------------------
!! Si el int�rprete utilizado los soporta, activa la escucha de eventos glk
!! para la selecci�n de hiperv�nculos en las ventanas principal de la
!! aplicaci�n.
!!
!!	@returns {boolean} Verdadero
!!------------------------------------------------------------------------------
[ ListenHyperlinkEvents;
	#Ifdef TARGET_GLULX;
	if (glk($0004, 11, 0)) { ! glk_gestalt(gestalt_Hyperlinks, 0)
		!! Activa escucha de hiperv�nculos en la ventana principal:
		glk($0102, gg_mainwin); ! glk_request_hyperlink_event
		!! Activa escucha de hiperv�nculos en la ventana de estado:
		glk($0102, gg_statuswin); ! glk_request_hyperlink_event
		!! Desactiva el eco autom�tico de la entrada en la ventana principal:
		glk($0150, gg_mainwin, 0); ! glk_set_echo_line_event
	}
	#Endif; ! TARGET_GLULX;
];

#Endif; ! HYPERLINKS;
