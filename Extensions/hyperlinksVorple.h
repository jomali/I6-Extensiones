

!!==============================================================================
!!
!!	HYPERLINKS
!!	Rutinas para facilitar la interacci�n por hiperv�nculos
!!
!!==============================================================================
!!
!!	Archivo:		hyperlinksVorple.h
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		1.0
!!	Fecha:			2018/06/06
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
System_file;

#Ifndef HYPERLINKS;
Constant HYPERLINKS;

Include "vorple-hyperlinks.h";

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
[ HandleHyperlinkEvent ev context abortres;
	ev = context + abortres;
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
	auxiliary;
	if (metaclass(item) ~= String or Object) return false;
	!! Selecciona el estilo de texto del hiperv�nculo:
	auxiliary = HyperlinkSetStyle(style, item);
	!! Hiperv�nculo:
	VorpleLinkCommand("MIRA"); ! TODO
	!! Reestablece el estilo de texto de la obra:
	HyperlinkSetStyle(auxiliary);
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
[ HyperlinkSetStyle style item;
	item++; ! (por evitar alertas del compilador)
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
	!! Garantiza que tras el hiperv�nculo se utilice el estilo Normal:
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
	return false;
];

#Endif; ! HYPERLINKS;
