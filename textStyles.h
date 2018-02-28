

!!==============================================================================
!!
!!	TEXT STYLES
!!	Interfaz biplataforma para la selecci�n de estilos de texto
!!
!!==============================================================================
!!
!!	Archivo:		textStyles.inf
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		1.0
!!	Fecha:			2018/02/28
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
!!	1.0: 2018/02/28	Versi�n inicial.
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
!!		    TextFormatter.set_style_hints(winrock);
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

!! Constantes de la extensi�n:

Constant TEXT_STYLE_UPRIGHT		= 0;
Constant TEXT_STYLE_STRESSED	= 1;
Constant TEXT_STYLE_IMPORTANT	= 2;
Constant TEXT_STYLE_MONOSPACED	= 3;
Constant TEXT_STYLE_REVERSED	= 4;
Constant TEXT_STYLE_HEADER		= 5;
Constant TEXT_STYLE_NOTE		= 6;
Constant TEXT_STYLE_QUOTE		= 7;
Constant TEXT_STYLE_INPUT		= 8;
Constant TEXT_STYLE_USER1		= 9;
Constant TEXT_STYLE_USER2		= 10;

Default TEXT_STYLE_PARSER_PREFIX	= "";
Default TEXT_STYLE_PARSER_STYLE		= TEXT_STYLE_UPRIGHT;
Default TEXT_STYLE_PARSER_SUFIX		= "";

!! Objeto que implementa la interfaz principal de la extensi�n:

Object	TextFormatter "(Text Formatter)"
 with	!!----------------------------------------------------------------------
		!! Retorna el c�digo num�rico entero que representa el �ltimo estilo de
		!! texto establecido por el formateador. Es importante tener en cuenta
		!! que si la �ltima vez que se ha modificado el estilo de texto ha sido
		!! por medios distintos a los ofrecidos por el objeto formateador
		!! ---utilizando directamente los c�digos de operaci�n de las m�quinas
		!! virtuales, por ejemplo---, este valor puede NO CORRESPONDERSE en
		!! realidad con el estilo de texto utilizado actualmente en la obra.
		!!
		!!	@returns {integer} C�digo num�rico del �ltimo estilo establecido
		!!		por el objeto formateador
		!!----------------------------------------------------------------------
		get_current_style [;
			return self.current_style;
		],
		!!----------------------------------------------------------------------
		!! (S�LO PARA GLULX. NO TIENE NING�N EFECTO EN M�QUINA-Z). Establece
		!! las propuestas de aspecto por defecto para los estilos definidos por
		!! la extensi�n. No garantiza el aspecto real con que se visualizar�
		!! cada estilo puesto que al final es siempre decisi�n del int�rprete
		!! ignorar o reescribir esta informaci�n. Debe invocarse antes de crear
		!! las ventanas gr�ficas, por ejemplo en el punto de entrada
 		!! 'InitGlkWindow(winrock)'.
		!!
		!!	@param {integer} winrock - C�digo con que se indica en qu� fase se
		!!		ha invocado al punto de entrada 'InitGlkWindow()'. Si se
		!!		utiliza el m�todo desde un sitio diferente a este punto de
		!!		entrada es necesario hacer que el par�metro tome el valor
		!!		GG_MAINWIN_ROCK para que el m�todo lleve a cabo efectivamente
		!!		la operaci�n
		!!	@returns {boolean} Verdadero si 'winrock == GG_MAINWIN_ROCK' y las
		!!		sugerencias se establecen correctamente. Falso en caso
		!!		contrario
		!!----------------------------------------------------------------------
		initialise_style_hints [ winrock;
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
			winrock++; ! (para evitar advertencias del compilador)
			return true;
		],
		!!----------------------------------------------------------------------
		!! Imprime el prefijo de los mensajes del sistema, tal y como est�
		!! definido en la constante TEXT_STYLE_PARSER_PREFIX. (Por defecto es
		!! la cadena vac�a: '').
		!!
		!!	@returns {boolean} Falso si el valor definido por la constante
		!!		TEXT_STYLE_PARSER_PREFIX no es v�lido (si no es una cadena de
		!!		caracteres) y, por tanto, no se puede imprimir. Verdadero si la
		!!		cadena se imprime con �xito
		!!----------------------------------------------------------------------
		print_parser_prefix [;
			if (metaclass(TEXT_STYLE_PARSER_PREFIX) ~= String) {
				return false;
			}
			print (string) TEXT_STYLE_PARSER_PREFIX;
			return true;
		],
		!!----------------------------------------------------------------------
		!! Imprime el sufijo de los mensajes del sistema, tal y como est�
		!! definido en la constante TEXT_STYLE_PARSER_SUFIX. (Por defecto es
		!! la cadena vac�a: '').
		!!
		!!	@returns {boolean} Falso si el valor definido por la constante
		!!		TEXT_STYLE_PARSER_SUFIX no es v�lido (si no es una cadena de
		!!		caracteres) y, por tanto, no se puede imprimir. Verdadero si la
		!!		cadena se imprime con �xito
		!!----------------------------------------------------------------------
		print_parser_sufix [;
			if (metaclass(TEXT_STYLE_PARSER_SUFIX) ~= String) {
				return false;
			}
			print (string) TEXT_STYLE_PARSER_SUFIX;
			return true;
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo que se corresponde con el c�digo num�rico
		!! pasado como par�metro.
		!!
		!!	@param {integer} style - C�digo num�rico del estilo que se desea
		!!		utilizar en la obra. Si el c�digo no se corresponde con un
		!!		valor v�lido, no se produce ning�n efecto
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use [ style
			is_proportional is_bold is_underline is_reverse glulx_code result;
			result = self.current_style;
			switch (style) {
				TEXT_STYLE_HEADER:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= true;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 3; ! style_Header
				TEXT_STYLE_IMPORTANT:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= true;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 4; ! style_Subheader
				TEXT_STYLE_INPUT:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= true;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 8; ! style_Input
				TEXT_STYLE_MONOSPACED:
					self.current_style	= style;
					is_proportional		= true;
					is_bold				= false;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 2; ! style_Preformatted
				TEXT_STYLE_NOTE:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= true;
					is_underline		= true;
					is_reverse			= false;
					glulx_code			= 6; ! style_Note
				TEXT_STYLE_QUOTE:
					self.current_style	= style;
					is_proportional		= true;
					is_bold				= false;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 7; ! style_BlockQuote
				TEXT_STYLE_REVERSED:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= false;
					is_underline		= false;
					is_reverse			= true;
					glulx_code			= 5; ! style_Alert
				TEXT_STYLE_STRESSED:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= false;
					is_underline		= true;
					is_reverse			= false;
					glulx_code			= 1; ! style_Emphasized
				TEXT_STYLE_UPRIGHT:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= false;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 0; ! style_Normal
				TEXT_STYLE_USER1:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= false;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 9; ! style_User1
				TEXT_STYLE_USER2:
					self.current_style	= style;
					is_proportional		= false;
					is_bold				= false;
					is_underline		= false;
					is_reverse			= false;
					glulx_code			= 10; ! style_User2
			}
			if (result ~= self.current_style) {
				self.apply_text_style(is_proportional, is_bold, is_underline,
					is_reverse, glulx_code);
			}
			return result;
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Header'; para introducir secciones principales
		!! de la obra. Su propio t�tulo o t�tulos de posibles cap�tulos, por
		!! ejemplo.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_header [;
			return self.use(TEXT_STYLE_HEADER);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Important'; para indicar una importancia
		!! destacada, un asunto serio, o urgencia en un texto. Es an�logo a las
		!! etiquetas <strong> en HTML. Los int�rpretes suelen imprimir este
		!! estilo en negrita.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_important [;
			return self.use(TEXT_STYLE_IMPORTANT);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Input'; para la entrada de usuario. No se
		!! recomienda su utilizaci�n salvo en casos excepcionales.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_input [;
			return self.use(TEXT_STYLE_INPUT);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Monospaced'. En un int�rprete bien configurado
		!! este estilo usa siempre una fuente de letra de ancho fijo.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_monospaced [;
			return self.use(TEXT_STYLE_MONOSPACED);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo Note'; para notificaciones especiales, como
		!! cambios en la puntuaci�n del usuario. Est� ideado como alternativa
		!! de aspecto para el estilo 'Important'.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_note [;
			return self.use(TEXT_STYLE_NOTE);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Parser'; para mensajes del sistema. En realidad
		!! funciona a modo envoltorio de otro estilo diferente determinado por
		!! la constante TEXT_STYLE_PARSER_STYLE.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_parser [;
			return self.use(TEXT_STYLE_PARSER_STYLE);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Quote'; para citas u otros textos especiales.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_quote [;
			return self.use(TEXT_STYLE_QUOTE);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Reversed', que intercambia los colores frontal
		!! y de fondo de la configuraci�n por defecto. Para utilizarlo
		!! adecuadamente en Glulx es necesario invocar a la funci�n
		!! 'TextFormatter.initialise_style_hints()'' antes de crear las
		!! ventanas de la interfaz gr�fica.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_reversed [;
			return self.use(TEXT_STYLE_REVERSED);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Stressed'; para indicar una acentuaci�n
		!! enfatizada de un texto. Es an�logo a las etiquetas <em> en HTML.
		!! Los int�rpretes suelen imprimir este estilo en it�lica.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_stressed [;
			return self.use(TEXT_STYLE_STRESSED);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'Upright'; usado por el cuerpo de texto normal.
		!! Es siempre el estilo de inicio de la aplicaci�n.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_upright [;
			return self.use(TEXT_STYLE_UPRIGHT);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'User1'; ideado junto con 'User2' para ser
		!! redefinido libremente por el autor.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_user1 [;
			return self.use(TEXT_STYLE_USER1);
		],
		!!----------------------------------------------------------------------
		!! Establece el estilo 'User2'; ideado junto con 'User1' para ser
		!! redefinido libremente por el autor.
		!!
		!!	@returns {integer} C�digo del estilo de texto registrado
		!!		anteriormente en el formateador
		!!----------------------------------------------------------------------
		use_user2 [;
			return self.use(TEXT_STYLE_USER2);
		],
 private
		!! C�digo num�rico del �ltimo estilo establecido por el formateador:
		current_style TEXT_STYLE_UPRIGHT,
		!! M�todo privado encargado de aplicar efectivamente el estilo:
		apply_text_style [
			is_proportional is_bold is_underline is_reverse glulx_code;
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
			is_proportional = is_bold + is_underline + is_reverse + glulx_code;
		],
;

!! Reglas de impresi�n:

[ emphasis text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = TextFormatter.get_current_style();
	switch (previous_style) {
		TEXT_STYLE_HEADER:
			TextFormatter.use_note();
		TEXT_STYLE_IMPORTANT:
			TextFormatter.use_note();
		TEXT_STYLE_NOTE:
			TextFormatter.use_important();
		TEXT_STYLE_QUOTE:
			TextFormatter.use_stressed();
		TEXT_STYLE_STRESSED:
			TextFormatter.use_upright();
		TEXT_STYLE_UPRIGHT:
			TextFormatter.use_stressed();
	}
	print (string) text;
	TextFormatter.use(previous_style);
	return true;
];

[ strong text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = TextFormatter.get_current_style();
	switch (previous_style) {
		TEXT_STYLE_HEADER:
			TextFormatter.use_upright();
		TEXT_STYLE_IMPORTANT:
			TextFormatter.use_upright();
		TEXT_STYLE_NOTE:
			TextFormatter.use_stressed();
		TEXT_STYLE_QUOTE:
			TextFormatter.use_important();
		TEXT_STYLE_STRESSED:
			TextFormatter.use_note();
		TEXT_STYLE_UPRIGHT:
			TextFormatter.use_important();
	}
	print (string) text;
	TextFormatter.use(previous_style);
	return true;
];

[ parser text
	previous_style;
	if (metaclass(text) ~= String) return false;
	previous_style = TextFormatter.use_parser();
	TextFormatter.print_parser_prefix();
	print (string) text;
	TextFormatter.print_parser_sufix();
	TextFormatter.use(previous_style);
	return true;
];

!! Alias para las reglas de impresi�n:

[ emph text; emphasis(text); ];

[ em text; emphasis(text); ];

#Endif; ! TEXT_STYLES;
