

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
!!	Versi�n:		1.2
!!	Fecha:			2018/06/12
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
!!	1.2: 2018/06/12	A�adida opci�n de desactivar los hiperv�nculos.
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
!!	NOTA: Se�alar c�mo el �ltimo ejemplo utiliza directivas de compilaci�n
!!	condicionales para permitir la compilaci�n biplataforma.
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef HYPERLINKS;
Constant HYPERLINKS;

Default _hyperlinks_command = "examina";
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
!! Genera un hiperv�nculo de tipo texto a partir del objeto o la cadena de
!! caracteres pasado como par�metro, de forma que el texto impreso del
!! hiperv�nculo es el nombre del objeto o la propia cadena de caracteres.
!! Admite dos par�metros opcionales; en primer lugar una cadena de caracteres
!! con un texto alternativo que se imprime en lugar del nombre del objeto o de
!! la cadena, y un valor num�rico que se identifica con el estilo de texto
!! utilizado para imprimir el hiperv�nculo.
!!
!!	@param {Object|String} item - Objeto o cadena de caracteres sobre la que se
!!		genera el hiperv�nculo. Si es un objeto, la entrada que se genera al
!!		seleccionarlo es un comando con el verbo definido en
!!		'_hyperlinks_command' y el objeto. Si es una cadena de caracteres, la
!!		entrada que se genera es ella misma
!!	@param {String} [alternative] - Texto alternativo con que se imprime el
!!		hiperv�nculo. Si no se indica ninguno, como texto del hiperv�nculo se
!!		utiliza el nombre del objeto o la cadena de caracteres del par�metro
!!		'item'
!!	@param {integer} [style = 0] - C�digo num�rico indicando el estilo de
!!		texto con que se imprime el hiperv�nculo
!!	@returns {boolean} Verdadero
!!------------------------------------------------------------------------------
[ Hyperlink item alternative style
	code;
	if (metaclass(item) ~= String or Object) return false;
	!! Selecciona el estilo de texto del hiperv�nculo:
	code = HyperlinkSetStyle(style, item);
	#Ifdef TARGET_GLULX;
	!! Establece el inicio del hiperv�nculo:
	if (code >= 0 && glk($0004, 11, 0)) {
		glk($0100, item); ! glk_set_hyperlink();
	}
	#Endif; ! TARGET_GLULX;
	!! Imprime el texto del hiperv�nculo:
	if (metaclass(alternative) == String) item = alternative;
	switch (metaclass(item)) {
		String:
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
	if (code >= 0 && glk($0004, 11, 0)) {
		glk($0100, 0); ! glk_set_hyperlink();
	}
	#Endif; ! TARGET_GLULX;
	!! Reestablece el estilo de texto de la obra:
	if (code >= 0) HyperlinkSetStyle(code);
	return true;
];

!!------------------------------------------------------------------------------
!! Selecciona el estilo de texto utilizado por la rutina para crear
!! hiperv�nculos. Puede ser sobreescrita por el autor desde el fichero original
!! (por medio de una sentencia 'Replace HyperlinkSetStyle'), para definir un
!! comportamiento m�s complejo ---como utilizar el objeto que se pasa como
!! par�metro para, en base a �l, determinar el estilo de texto a utilizar, por
!! ejemplo---.
!!
!! Es invocada 2 veces dentro de la funci�n Hyperlink(). En la primera ocasi�n
!! ---etapa 1)--- selecciona el estilo de texto utilizado para imprimir el
!! hiperv�nculo. Si aqu� la rutina retorna un n�mero negativo, se cancela la
!! creaci�n del hiperv�nculo. En la etapa 2) debe reestablecer el estilo de
!! texto normal de la obra y el valor de retorno resulta indiferente.
!!
!!	@param {integer} style - C�digo num�rico para identificar el estilo de
!!		texto a utilizar, utilizando como referencia los estilos de texto de
!!		M�quina-Z: 0) normal, 1) subrayado, 2) negrita y 3) ancho-fijo
!!	@param {Object|String} [item = 0] - En la etapa 1) es el objeto o cadena de
!!		caracteres sobre el que se genera el hiperv�nculo. En la etapa 2) el
!!		par�metro est� vac�o
!!	@returns {integer} C�digo num�rico que identifica los estilos de texto.
!!		Puede retornar -1 durante la etapa 1) para cancelar la creaci�n del
!!		hiperv�nculo. En cualquier otro caso, la etapa 1) debe retornar el
!!		c�digo del estilo de texto que se pasa como par�metro en la etapa 2),
!!		para reestablecer el estilo de texto de la obra tras la impresi�n del
!!		del hiperv�nculo
!!------------------------------------------------------------------------------
[ HyperlinkSetStyle style item;
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
	return 0;
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
