

!!==============================================================================
!!
!!	HYPERLINKS
!!	Rutinas para facilitar la interacci�n por hiperv�nculos
!!
!!==============================================================================
!!
!!	Archivo:		hyperlinks.inf
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		Glulx
!!	Versi�n:		1.0
!!	Fecha:			2018/03/05
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
!!	1.0: 2018/03/05	Versi�n inicial de la extensi�n.
!!
!!------------------------------------------------------------------------------
!!
!!	INSTALACI�N
!!
!!	Para utilizar la extensi�n hay que a�adir la siguiente l�nea en el fichero
!!	principal de la obra, inmediatamente despu�s de la l�nea
!!	'Include "Parser";':
!!
!!		Include "hyperlinks";
!!
!!	Son necesarias, adem�s, otras dos consideraciones: por una parte, debe
!!	activarse la escucha de eventos glk de selecci�n de hiperv�nculos en las
!!	ventanas principales de la aplicaci�n. Para hacer esto se deben incluir las
!!	siguientes declaraciones dentro del punto de entrada 'Initialise()' ---el
!!	ejemplo utiliza directivas de compilaci�n condicionales para permitir la
!!	compilaci�n biplataforma---:
!!
!! 		[ Initialise;
!! 			#Ifdef TARGET_GLULX;
!! 			!! Escucha de hiperv�nculos en la ventana princiapl:
!! 			glk($0102, gg_mainwin); ! glk_request_hyperlink_event();
!!			!! Escucha de hiperv�nculos en la ventana de estado:
!!			glk($0102, gg_statuswin); ! glk_request_hyperlink_event();
!! 			#Endif; ! TARGET_GLULX;
!!
!! 			!! Resto de contenidos del punto de entrada:
!! 			[...]
!! 		];
!!
!!	Por �ltimo, hay que introducir la l�gica encargada de capturar y responder
!!	a esos eventos Glk de tipo hiperv�nculo. Esta l�gica debe encontrarse
!!	dentro del punto de entrada Glulx 'HandleGlkEvent()' ---crearlo si no
!!	existe---:
!!
!! 		#Ifdef TARGET_GLULX;
!! 		[ HandleGlkEvent ev context abortres;
!! 			if (HandleHyperlinkEvent(ev, context, abortres)) return 2;
!! 		];
!! 		#Endif; ! TARGET_GLULX;
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef HYPERLINKS;
Constant HYPERLINKS;

Default HYPERLINKS_COMMAND = "examina";
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
!!		librer�a 'KeyboardPrimitive()'). 1 si el evento se ha producido durante
!!		una entrada de caracter (funci�n de la librer�a 'KeyCharPrimitive()')
!!	@param {array} abortres - Utilizado para cancelar la entrada de texto y
!!		forzar una entrada particular. La longitud de la nueva entrada se
!!		registra en 'abortres-->0'. Si es diferente de 0, los caracteres del
!!		comando deben escribirse en el array secuencialmente desde la posici�n
!!		'abortres->WORDSIZE' hasta 'abortres->(WORDSIZE+length)' (no
!!		inclusive). No pueden superarse los 256 caracteres
!!	@returns {boolean} Verdadero para indicar que la entrada de usuario debe
!!		ser ignorada y finalizar el turno con la nueva entrada indicada en el
!!		par�metro 'abortres'.
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
		glk($0102, gg_mainwin);		! glk_request_hyperlink_event
		glk($0102, gg_statuswin);	! glk_request_hyperlink_event
		!! Se cancelan los inputs de teclado:
		glk($00D3, gg_mainwin);		! glk_cancel_char_event
		glk($00D1, gg_mainwin, 0);	! glk_cancel_line_event
		!! 1) Si el hiperv�nculo se ha creado sobre un objeto, la entrada de
		!! usuario se genera como la combinaci�n de la orden registrada en el
		!! string HYPERLINKS_COMMAND, el s�mbolo espacio ' ', y el nombre del
		!! objeto:
		if (metaclass(ev-->2) == Object) {
			if (metaclass(HYPERLINK_COMMAND) == String) {
				PrintToBuffer(abortres, INPUT_BUFFER_LEN, HYPERLINKS_COMMAND);
				#Ifdef DEBUG_HYPERLINKS;
				print "** Acci�n del hiperv�nculo: ";
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
			for (i = WORDSIZE : i < (abortres-->0) + WORDSIZE : i++) {
				print (char) abortres-->i;
			}
			print " **^";
			#Endif; ! DEBUG_HYPERLINKS;
			return true;
		}
		!! 2) Si el hiperv�nculo se ha creado sobre un string, la entrada de
		!! usuario es �l mismo:
		if (metaclass(ev-->2) == String) {
			PrintToBuffer(abortres, INPUT_BUFFER_LEN, ev-->2);
			#Ifdef DEBUG_HYPERLINKS;
			print "** Comando completo del hiperv�nculo: ";
			for (i = WORDSIZE : i < (abortres-->0) + WORDSIZE : i++) {
				print (char) abortres-->i;
			}
			print " **^";
			#Endif; ! DEBUG_HYPERLINKS;
			return true;
		}
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
!!		seleccionarlo es un comando con el verbo definido en HYPERLINKS_COMMAND
!!		y el objeto. Si es una cadena de caracteres, la entrada que se genera
!!		es ella misma
!!	@param {String} [alternative] - Texto alternativo con que se imprime el
!!		hiperv�nculo. Si no se indica ninguno, como texto del hiperv�nculo se
!!		utiliza el nombre del objeto o la cadena de caracteres del par�metro
!!		'item'
!!	@param {integer} [highlight = 0] - C�digo num�rico indicando el estilo de
!!		texto con que se imprime el hiperv�nculo
!!	@returns {boolean} Verdadero
!!------------------------------------------------------------------------------
[ Hyperlink item alternative highlight
	auxiliary;
	if (metaclass(item) ~= String or Object) return false;
	!! Establece el inicio del hiperv�nculo:
	#Ifdef TARGET_GLULX;
	glk($0100, item); ! glk_set_hyperlink();
	#Endif; ! TARGET_GLULX;
	!! Selecciona el estilo de texto del hiperv�nculo:
	auxiliary = HyperlinkSetStyle(highlight, item);
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
	!! Reestablece el estilo de texto de la obra:
	HyperlinkSetStyle(auxiliary, item);
	!! Establece el final del hiperv�nculo:
	#Ifdef TARGET_GLULX;
	glk($0100, 0); ! glk_set_hyperlink
	#Endif; ! TARGET_GLULX;
];

!!------------------------------------------------------------------------------
!! Selecciona el estilo de texto utilizado por la rutina para crear
!! hiperv�nculos. Puede ser sobreescrita por el autor desde el fichero original
!! (por medio de una sentencia 'Replace HyperlinkSetStyle'), para definir un
!! comportamiento m�s complejo ---utilizar el tipo de objeto pasado como
!! par�metro para determinar el estilo de texto aplicado en el hiperv�nculo,
!! por ejemplo---.
!!
!!	@param {integer} highlight - C�digo num�rico para identificar el estilo de
!!		texto a utilizar, utilizando como referencia los estilos de texto de
!!		M�quina-Z: 0) normal, 1) subrayado, 2) negrita y 3) ancho-fijo
!!	@param {Object|String} item - Objeto o cadena de caracteres sobre el que se
!!		genera el hiperv�nculo. Originalmente no se utiliza, pero puede ser
!!		interesante si el autor decide sobreescribir la rutina y tener en
!!		cuenta este 'item' para seleccionar el estilo de texto utilizado
!!	@returns {integer} C�digo num�rico que identifica los estilos de texto. La
!!		rutina se invoca 2 veces, antes y despu�s de imprimir el texto del
!!		hiperv�nculo, de tal forma que el resultado de la primera llamada se
!!		pasa como par�metro en la segunda. As� es posible inicar, desde la
!!		llamada 1, el estilo final del texto una vez impreso el hiperv�nculo
!!------------------------------------------------------------------------------
[ HyperlinkSetStyle highlight item;
	item++; ! (por evitar alertas del compilador)
	switch (highlight) {
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
	!! Garantiza que tras el hiperv�nculo se utilice el estilo Normal:
	return 0;
];

#Endif; ! HYPERLINKS;
