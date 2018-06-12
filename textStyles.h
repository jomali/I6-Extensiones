

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
!!	Versi�n:		2.2
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
!!	2.1: 2018/06/11	A�adidas recomendaciones de aspecto en la funci�n
!!					'InitialiseStyleHints()' para todos los estilos de texto en
!!					Glulx, a fin de intentar dar mayor uniformidad al aspecto
!!					en diferentes int�rpretes.
!!	2.0: 2018/03/07	Modificaci�n del enfoque basado en el uso de un objeto
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
!!	Opcionalmente en Glulx, adem�s, es posible inicializar sugerencias sobre el
!!	aspecto por defecto de los distintos estilos de texto de la extensi�n.
!!	Desde el propio sistema Inform no puede determinarse la apariencia final de
!!	los estilos de texto puesto que esta responsabilidad recae exclusivamente
!!	en el programa int�rprete, pero s� es posible definir un conjunto de
!!	sugerencias que pueden ser tenidas en cuenta por �l. Es necesario realizar
!!	estas sugerencias antes de la creaci�n de la ventana principal de la obra;
!!	habitualmente se recomienda utilizar el punto de entrada Glk
!!	'InitGlkWindow(winrock)', invocado cada vez que la librer�a se encarga de
!!	establecer una de las ventanas est�ndar de la aplicaci�n [PLO02]:
!!
!!		#Ifdef TARGET_GLULX;
!!		[ InitGlkWindow winrock;
!!		    !! Sugerencias de aspecto de 'textStyles':
!!		    InitialiseStyleHints(winrock);
!!		    !! Espacio para otras sugerencias de aspecto definidas por el
!!			!! autor y para el resto de contenidos de InitGlkWindow:
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
!! ejemplo en el punto de entrada 'InitGlkWindow(winrock)'. Estas propuestas se
!! establecen con la funci�n:
!!
!!	void glk_stylehint_set(
!!		glui32 wintype, glui32 styl, glui32 hint, glsi32 val);
!!
!! A continuaci�n se listan todas las propuestas de aspecto posibles, ordenadas
!! por su c�digo de operaci�n (descripciones extra�das de la especificaci�n de
!! la API Glk <https://www.eblong.com/zarf/glk/glk-spec-075_5.html>):
!!
!!	0)	stylehint_Indentation: How much to indent lines of text in the given
!!		style. May be a negative number, to shift the text out (left) instead
!!		of in (right). The exact metric isn't precisely specified; you can
!!		assume that +1 is the smallest indentation possible which is clearly
!!		visible to the player.
!!	1)	stylehint_ParaIndentation: How much to indent the first line of each
!!		paragraph. This is in addition to the indentation specified by
!!		stylehint_Indentation. This too may be negative, and is measured in the
!!		same units as stylehint_Indentation.
!!	2)	stylehint_Justification: The value of this hint must be one of the
!!		constants 0:stylehint_just_LeftFlush, 1:stylehint_just_LeftRight (full
!!		justification), 2:stylehint_just_Centered, or
!!		3:stylehint_just_RightFlush.
!!	3)	stylehint_Size: How much to increase or decrease the font size. This is
!!		relative; 0 means the interpreter's default font size will be used,
!!		positive numbers increase it, and negative numbers decrease it. Again,
!!		+1 is the smallest size increase which is easily visible. [The amount
!!		of this increase may not be constant. +1 might increase an 8-point font
!!		to 9-point, but a 16-point font to 18-point.]
!!	4)	stylehint_Weight: The value of this hint must be 1 for heavy-weight
!!		fonts (boldface), 0 for normal weight, and -1 for light-weight fonts.
!!	5)	stylehint_Oblique: The value of this hint must be 1 for oblique fonts
!!		(italic), or 0 for normal angle.
!!	6)	stylehint_Proportional: The value of this hint must be 1 for
!!		proportional-width fonts, or 0 for fixed-width.
!!	7)	stylehint_TextColor: The foreground color of the text. This is encoded
!!		in the 32-bit hint value: the top 8 bits must be zero, the next 8 bits
!!		are the red value, the next 8 bits are the green value, and the bottom
!!		8 bits are the blue value. Color values range from 0 to 255. [So
!!		0x00000000 is black, 0x00FFFFFF is white, and 0x00FF0000 is bright
!!		red.]
!!	8)	stylehint_BackColor: The background color behind the text. This is
!!		encoded the same way as stylehint_TextColor.
!!	9)	stylehint_ReverseColor: The value of this hint must be 0 for normal
!!		printing (TextColor on BackColor), or 1 for reverse printing (BackColor
!!		on TextColor). [Some libraries may support this hint but not the
!!		TextColor and BackColor hints. Other libraries may take the opposite
!!		tack; others may support both, or neither.]
!!
!!	@param {integer} winrock - C�digo con que se indica en qu� fase se ha
!!		invocado al punto de entrada 'InitGlkWindow()'. Si la rutina se utiliza
!!		desde un sitio diferente a este punto de entrada es necesario hacer que
!!		el par�metro tome el valor GG_MAINWIN_ROCK para que la operai�n se siga
!!		llevando a cabo efectivamente
!!	@param {integer} [wintype=0] - C�digo num�rico con el tipo de ventana sobre
!!		el que se apican las propuestas de aspecto (0: wintype_AllTypes,
!!		1: wintype_Pair, 2: wintype_Blank, 3: wintype_TextBuffer,
!!		4: wintype_TextGrid, 5: wintype_Graphics)
!!	@returns {boolean} Verdadero si 'winrock == GG_MAINWIN_ROCK' y las
!!		sugerencias se establecen correctamente. Falso en caso
!!		contrario
!!------------------------------------------------------------------------------
[ InitialiseStyleHints winrock wintype;
	#Ifdef TARGET_GLULX;
	if (winrock ~= GG_MAINWIN_ROCK) return false;

	!! Indicaciones de aspecto: estilo HEADER (style_Header)
	glk($00B0, wintype, 3, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 3, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 3, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 3, 3, 1); ! stylehint_Size
	glk($00B0, wintype, 3, 4, 1); ! stylehint_Weight
	glk($00B0, wintype, 3, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 3, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 3, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo IMPORTANT (style_Subheader)
	glk($00B0, wintype, 4, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 4, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 4, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 4, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 4, 4, 1); ! stylehint_Weight
	glk($00B0, wintype, 4, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 4, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 4, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo INPUT (style_Input)
	glk($00B0, wintype, 8, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 8, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 8, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 8, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 8, 4, 1); ! stylehint_Weight
	glk($00B0, wintype, 8, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 8, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 8, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo MONOSPACED (style_Preformatted)
	glk($00B0, wintype, 2, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 2, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 2, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 2, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 2, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 2, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 2, 6, 0); ! stylehint_Proportional
	glk($00B0, wintype, 2, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo NOTE (style_Note)
	glk($00B0, wintype, 6, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 6, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 6, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 6, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 6, 4, 1); ! stylehint_Weight
	glk($00B0, wintype, 6, 5, 1); ! stylehint_Oblique
	glk($00B0, wintype, 6, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 6, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo QUOTE (style_BlockQuote)
	glk($00B0, wintype, 7, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 7, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 7, 2, 3); ! stylehint_Justification
	glk($00B0, wintype, 7, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 7, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 7, 5, 1); ! stylehint_Oblique
	glk($00B0, wintype, 7, 6, 0); ! stylehint_Proportional
	glk($00B0, wintype, 7, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo REVERSED (style_Alert)
	glk($00B0, wintype, 5, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 5, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 5, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 5, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 5, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 5, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 5, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 5, 9, 1); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo STRESSED (style_Emphasized)
	glk($00B0, wintype, 1, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 1, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 1, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 1, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 1, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 1, 5, 1); ! stylehint_Oblique
	glk($00B0, wintype, 1, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 1, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo UPRIGHT (style_Normal)
	glk($00B0, wintype, 0, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 0, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 0, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 0, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 0, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 0, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 0, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 0, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo USER1 (style_User1)
	glk($00B0, wintype, 9, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 9, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 9, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 9, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 9, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 9, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 9, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 9, 8, $FFFF00); ! stylehint_BackColor #FFFF00
	glk($00B0, wintype, 9, 9, 0); ! stylehint_ReverseColor

	!! Indicaciones de aspecto: estilo USER2 (style_User2)
	glk($00B0, wintype, 10, 0, 0); ! stylehint_Indentation
	glk($00B0, wintype, 10, 1, 0); ! stylehint_ParaIndentation
	glk($00B0, wintype, 10, 2, 0); ! stylehint_Justification
	glk($00B0, wintype, 10, 3, 0); ! stylehint_Size
	glk($00B0, wintype, 10, 4, 0); ! stylehint_Weight
	glk($00B0, wintype, 10, 5, 0); ! stylehint_Oblique
	glk($00B0, wintype, 10, 6, 1); ! stylehint_Proportional
	glk($00B0, wintype, 10, 7, $808080); ! stylehint_TextColor #808080
	glk($00B0, wintype, 10, 9, 0); ! stylehint_ReverseColor
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
