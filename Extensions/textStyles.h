

!!==============================================================================
!!
!!	TEXT STYLES
!!	Interfaz biplataforma para la selecci�n de estilos de texto
!!
!!==============================================================================
!!
!!	Archivo:		textStyles.h
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		2.0
!!	Fecha:			2018/03/07
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
!!	2.0: 2018/03/XX	Modificaci�n del enfoque basado en el uso de un objeto
!!					gestor TextFormatter con estado interno, por un enfoque
!!					basado en rutinas independientes y variables globales. Por
!!					reducir la carga de la pila al encadenar llamadas a
!!					rutinas (especialmente cuando se utilizan directivas de
!!					depuraci�n: 'acciones', 'mensajes'..., que pueden
!!					desencadenar errores de tipo "Stack overflow in callstub").
!!					La regla de impresi�n 'emphasis' se reemplaza por su
!!					sin�nimo 'emph', para evitar incompatibilidades con la
!!					extensi�n 'utility.h' de L. Ross Raszewski
!!	1.1: 2018/03/05	Correcci�n en las instrucciones de instalaci�n.
!!	1.0: 2018/02/28	Versi�n inicial.
!!
!!------------------------------------------------------------------------------
!!
!!	TABLA DE CONTENIDOS
!!
!!	1)	Definici�n de constantes y variables
!!	2)	Rutinas de selecci�n del estilo de texto
!!	3)	Reglas de impresi�n normales
!!	4)	Reglas de impresi�n contextuales
!!
!!------------------------------------------------------------------------------
!!
!!	INSTALACI�N
!!
!!	Para utilizar la extensi�n basta con a�adir la siguiente l�nea en el
!!	fichero principal de la aplicaci�n, inmediatamente despu�s de la l�nea
!!	'Include "Parser";
!!
!!		Include "textStyles";
!!
!!	Opcionalmente en Glulx, adem�s, es posible inicializar algunas sugerencias
!!	sobre el aspecto de los distintos estilos de texto de la extensi�n. Desde
!!	el propio sistema Inform no puede determinarse la apariencia final de los
!!	estilos de texto puesto que esta responsabilidad recae exclusivamente en el
!!	programa int�rprete, pero s� es posible definir un conjunto de sugerencias
!!	que pueden ser tenidas en cuenta por �l. Es necesario realizar estas
!!	sugerencias antes de la creaci�n de la ventana principal de la obra;
!!	habitualmente se recomienda utilizar el punto de entrada Glk
!!	'InitGlkWindow(winrock)', invocado cada vez que la librer�a se encarga de
!!	establecer una de las ventanas est�ndar de la aplicaci�n [PLO02]:
!!
!!		#Ifdef TARGET_GLULX;
!!		[ InitGlkWindow winrock;
!!		    !! Sugerencias de aspecto de 'textStyles':
!!		    InitialiseStyleHints(winrock);
!!		    !! Espacio para sugerencias de aspecto del autor y
!!		    !! para el resto de contenidos de InitGlkWindow:
!!		    [...]
!!		    !! Se contin�a con el proceso normal de la librer�a:
!!		    return false;
!!		];
!!		#Endif; ! TARGET_GLULX;
!!
!!	[PLO02] Plotkin, Andrew (2002) 'The Game Author's Guide to Glulx Inform'.
!!	<https://www.eblong.com/zarf/glulx/inform-guide.txt>
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef TEXT_STYLES;
Constant TEXT_STYLES;


!!==============================================================================
!!
!!	1)	Definici�n de constantes y variables
!!
!!------------------------------------------------------------------------------

Constant TEXT_STYLE_UPRIGHT		= 0;	! Estilo: Recto (Upright)
Constant TEXT_STYLE_STRESSED	= 1;	! Estilo: Enf�tico (Stressed)
Constant TEXT_STYLE_IMPORTANT	= 2;	! Estilo: Importante (Important)
Constant TEXT_STYLE_MONOSPACED	= 3;	! Estilo: Monoespaciada (Monospaced)
Constant TEXT_STYLE_REVERSED	= 4;	! Estilo: Invertido (Reversed)
Constant TEXT_STYLE_HEADER		= 5;	! Estilo: Encabezado (Header)
Constant TEXT_STYLE_NOTE		= 6;	! Estilo: Nota (Note)
Constant TEXT_STYLE_QUOTE		= 7;	! Estilo: Cita (Quote)
Constant TEXT_STYLE_INPUT		= 8;	! Estilo: Entrada (Input)
Constant TEXT_STYLE_USER1		= 9;	! Estilo: Usuario 1 (User 1)
Constant TEXT_STYLE_USER2		= 10;	! Estilo: Usuario 2 (User 2)

!! C�digo del estilo de texto utilizado por los mensajes del sistema:
Default TEXT_STYLE_PARSER = TEXT_STYLE_UPRIGHT;

!! Prefijo de los mensajes del sistema:
Default TEXT_STYLE_PARSER_PREFIX = "";

!! Sufijo de los mensajes del sistema:
Default TEXT_STYLE_PARSER_SUFIX = "";

!! C�digo num�rico entero que representa el �ltimo estilo de texto establecido
!! por la extensi�n. Es importante tener en cuenta que si la �ltima vez que se
!! ha modificado el estilo de texto ha sido por medios distintos a los
!! ofrecidos por 'textStyles' ---utilizando directamente los c�digos de
!! operaci�n de las m�quinas virtuales, por ejemplo---, este valor puede NO
!! CORRESPONDERSE en realidad con el estilo de texto utilizado actualmente en
!! la obra:
Global _current_text_style = TEXT_STYLE_UPRIGHT;


!!==============================================================================
!!
!!	2)	Rutinas de selecci�n del estilo de texto
!!
!!------------------------------------------------------------------------------

!!------------------------------------------------------------------------------
!! (S�LO PARA GLULX. NO TIENE NING�N EFECTO EN M�QUINA-Z). Establece las
!! propuestas de aspecto por defecto para los estilos definidos por la
!! extensi�n. No garantiza el aspecto real con que se visualizar� cada estilo
!! puesto que al final es siempre decisi�n del int�rprete ignorar o reescribir
!! esta informaci�n. Debe invocarse antes de crear las ventanas gr�ficas, por
!! ejemplo en el punto de entrada 'InitGlkWindow(winrock)'.
!!
!!	@param {integer} winrock - C�digo con que se indica en qu� fase se ha
!!		invocado al punto de entrada 'InitGlkWindow()'. Si la rutina se utiliza
!!		desde un sitio diferente a este punto de entrada es necesario hacer que
!!		el par�metro tome el valor GG_MAINWIN_ROCK para que la operai�n se siga
!!		llevando a cabo efectivamente
!!	@returns {boolean} Verdadero si 'winrock == GG_MAINWIN_ROCK' y las
!!		sugerencias se establecen correctamente. Falso en caso
!!		contrario
!!------------------------------------------------------------------------------
[ InitialiseStyleHints winrock;
	#Ifdef TARGET_GLULX;
	if (winrock ~= GG_MAINWIN_ROCK) return false;
	!! Indicaciones de aspecto: estilo Header:
	glk($00B0, 3, 3, 4, 1); ! Header, weight, 1 (heavy)
	glk($00B0, 3, 3, 5, 0); ! Header, oblique, 0 (false)
	!! Indicaciones de aspecto: estilo Important:
	glk($00B0, 3, 4, 4, 1); ! Subheader, weight, 1 (heavy)
	glk($00B0, 3, 4, 5, 0); ! Subheader, oblique, 0 (false)
	!! Indicaciones de aspecto: estilo Reversed
	glk($00B0, 3, 5, 5, 0); ! Alert, oblique, 0 (false)
	glk($00B0, 3, 5, 9, 1); ! Alert, ReverseColor, 1 (reverse)
	!! Indicaciones de aspecto: estilo Note:
	glk($00B0, 3, 6, 4, 1); ! Note, weight, 1 (heavy)
	glk($00B0, 3, 6, 5, 1); ! Note, oblique, 1 (true)
	!! Indicaciones de aspecto: estilo Quote:
	glk($00B0, 3, 7, 6, 0); ! BlockQuote, Proportional, 0 (false)
	!! Indicaciones de aspecto: estilo	 User1:
	glk($00B0, 3, 9, 8, $FFFF00); ! User1, background, #FFFF00
	!! Indicaciones de aspecto: estilo User2:
	glk($00B0, 3, 10, 7, $808080); ! User2, foreground, #808080
	#Endif; ! TARGET_GLULX;
	winrock++; ! (por evitar alertas del compilador en M�quina-Z)
	return true;
];

!!------------------------------------------------------------------------------
!! Establece el estilo que se corresponde con el c�digo num�rico pasado como
!! par�metro.
!!
!!	@param {integer} st - C�digo num�rico del estilo que se desea utilizar
!!		en la obra. Si el c�digo no se corresponde con un valor v�lido, no se
!!		produce ning�n efecto
!!	@returns {integer} C�digo del estilo de texto registrado anteriormente por
!!		la extensi�n
!!------------------------------------------------------------------------------
[ UseTextStyle st
	is_proportional is_bold is_underline is_reverse glulx_code result;
	result = _current_text_style;
	switch (st) {
		TEXT_STYLE_HEADER:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= true;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 3; ! style_Header
		TEXT_STYLE_IMPORTANT:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= true;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 4; ! style_Subheader
		TEXT_STYLE_INPUT:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= true;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 8; ! style_Input
		TEXT_STYLE_MONOSPACED:
			_current_text_style	= st;
			is_proportional	= true;
			is_bold			= false;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 2; ! style_Preformatted
		TEXT_STYLE_NOTE:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= true;
			is_underline	= true;
			is_reverse		= false;
			glulx_code		= 6; ! style_Note
		TEXT_STYLE_QUOTE:
			_current_text_style	= st;
			is_proportional	= true;
			is_bold			= false;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 7; ! style_BlockQuote
		TEXT_STYLE_REVERSED:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= false;
			is_underline	= false;
			is_reverse		= true;
			glulx_code		= 5; ! style_Alert
		TEXT_STYLE_STRESSED:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= false;
			is_underline	= true;
			is_reverse		= false;
			glulx_code		= 1; ! style_Emphasized
		TEXT_STYLE_UPRIGHT:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= false;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 0; ! style_Normal
		TEXT_STYLE_USER1:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= false;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 9; ! style_User1
		TEXT_STYLE_USER2:
			_current_text_style	= st;
			is_proportional	= false;
			is_bold			= false;
			is_underline	= false;
			is_reverse		= false;
			glulx_code		= 10; ! style_User2
	}
	if (result ~= _current_text_style) {
		#Ifdef TARGET_ZCODE;
		!! Se reinicia el estilo para evitar combinaciones indeseadas:
		font on; style roman;
		!! Se aplican los estilos seg�n corresponda:
		if (is_proportional) font off;
		if (is_bold) style bold;
		if (is_underline) style underline;
		if (is_reverse) style reverse;
		#Ifnot; ! TARGET_GLULX;
		glk($0086, glulx_code);
		#Endif; ! TARGET_
	}
	return result;
];


!!==============================================================================
!!
!!	3)	Reglas de impresi�n
!!
!!------------------------------------------------------------------------------

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Header'; para introducir secciones
!! principales de la obra como su propio t�tulo o t�tulos de posibles
!! cap�tulos, por ejemplo.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ header text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_HEADER);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Important'; para indicar una
!! importancia destacada, un asunto serio, o urgencia en un texto. Es an�logo a
!! las etiquetas <strong> en HTML5. Los int�rpretes suelen imprimir este estilo
!! en negrita.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ important text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_IMPORTANT);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Input'; para la entrada de
!! usuario. No se recomienda su utilizaci�n salvo en casos excepcionales.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ input text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_INPUT);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Monospaced'. En un int�rprete bien
!! configurado este estilo usa siempre una fuente de letra de ancho fijo.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ monospaced text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_MONOSPACED);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo Note'; para notificaciones
!! especiales, como cambios en la puntuaci�n del usuario. Est� ideado como
!! alternativa de aspecto para el estilo 'Important'.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ note text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_NOTE);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Parser'; para mensajes del
!! sistema. En realidad funciona a modo envoltorio de otro estilo diferente
!! determinado por la constante TEXT_STYLE_PARSER. La regla imprime adem�s el
!! prefijo y el sufijo definidos en las constantes TEXT_STYLE_PARSER_PREFIX y
!! TEXT_STYLE_PARSER_SUFIX, respectivamente.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ parser text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_PARSER);
	print (string) TEXT_STYLE_PARSER_PREFIX;
	print (string) text;
	print (string) TEXT_STYLE_PARSER_SUFIX;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Quote'; para citas u otros textos
!! especiales.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ quote text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_QUOTE);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Reversed'; intercambia los colores
!! frontal y de fondo de la configuraci�n por defecto. Para utilizarlo
!! adecuadamente en Glulx es necesario invocar a la funci�n
!! 'InitialiseStyleHints()' antes de crear las ventanas de la interfaz gr�fica.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ reversed text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_REVERSED);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Stressed'; para indicar una
!! acentuaci�n enfatizada de un texto. Es an�logo a las etiquetas <em> en
!! HTML5. Los int�rpretes suelen imprimir este estilo en it�lica.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ stressed text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_STRESSED);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'Upright'; usado por el cuerpo de
!! texto normal. Es siempre el estilo de inicio de la aplicaci�n.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ upright text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_UPRIGHT);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'User1'; ideado junto con 'User2'
!! para ser redefinido libremente por el autor.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ user1 text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_USER1);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n que utiliza el estilo 'User2'; ideado junto con 'User1'
!! para ser redefinido libremente por el autor.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con �xito. Falso si el
!!		par�metro 'text' no es una cadena de caracteres
!!------------------------------------------------------------------------------
[ user2 text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = _current_text_style;
	UseTextStyle(TEXT_STYLE_USER2);
	print (string) text;
	UseTextStyle(previous_style);
	return true;
];

!! Reglas de impresi�n contextuales:

!!------------------------------------------------------------------------------
!! Regla de impresi�n contextual. Imprime el texto con un estilo enfatizado
!! con respecto al estilo utilizado actualmente.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con estilo enfatizado.
!!		Falso si el par�metro 'text' no es una cadena de caracteres y no puede
!!		imprimirse, o si el texto se imprime sin modificar el estilo
!!------------------------------------------------------------------------------
[ emph text;
	switch (_current_text_style) {
		TEXT_STYLE_HEADER:
			return note(text);
		TEXT_STYLE_IMPORTANT:
			return note(text);
		TEXT_STYLE_NOTE:
			return important(text);
		TEXT_STYLE_QUOTE:
			return stressed(text);
		TEXT_STYLE_STRESSED:
			return upright(text);
		TEXT_STYLE_UPRIGHT:
			return stressed(text);
		default:
			if (metaclass(text) == String) print (string) text;
			return false;
	}
];

!!------------------------------------------------------------------------------
!! Regla de impresi�n contextual. Imprime el texto con un estilo destacado
!! con respecto al estilo utilizado actualmente.
!!------------------------------------------------------------------------------
[ strong text;
	switch (_current_text_style) {
		TEXT_STYLE_HEADER:
			return upright(text);
		TEXT_STYLE_IMPORTANT:
			return upright(text);
		TEXT_STYLE_NOTE:
			return stressed(text);
		TEXT_STYLE_QUOTE:
			return important(text);
		TEXT_STYLE_STRESSED:
			return note(text);
		TEXT_STYLE_UPRIGHT:
			return important(text);
		default:
			if (metaclass(text) == String) print (string) text;
			return false;
	}
];

!! Alias:

!!------------------------------------------------------------------------------
!! Sin�nimo para la regla de impresi�n 'emph'.
!!
!!	@param {String} text - Texto a imprimir
!!	@returns {boolean} Verdadero si el texto se imprime con estilo enfatizado.
!!		Falso si el par�metro 'text' no es una cadena de caracteres y no puede
!!		imprimirse, o si el texto se imprime sin modificar el estilo
!!------------------------------------------------------------------------------
[ em text; return emph(text); ];

#Endif; ! TEXT_STYLES;
