

!!==============================================================================
!!
!!	MENSAJES DE LA LIBRER�A EN ESPA�OL
!!
!!==============================================================================
!!
!!	File:			SpanishLM.inf
!!	Author(s):		INFSP Task Team
!!					J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Language:		ES (Castellano)
!!	System:			Inform-INFSP 6
!!	Platform:		M�quina-Z / GLULX
!!	Version:		0.0
!!	Released:		2017/08/03
!!
!!------------------------------------------------------------------------------
!!
!!	# HISTORIAL DE VERSIONES
!!
!!	0.0: 2017/08/03	Versi�n en desarrollo de la extensi�n.
!!
!!------------------------------------------------------------------------------
!!
!!	Copyright (c) 2017, J. Francisco Mart�n
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
!!	# NOTAS
!!
!!	Implementa el conjunto de mensajes por defecto de la librer�a Inform-INFSP,
!!	incluyendo la posibilidad de modificar en tiempo de ejecuci�n tanto el
!!	tiempo verbal (presente, pasado, futuro) y la persona (primera, segunda,
!!	tercera), como el g�nero (masculino, femenino) el n�mero (singular,
!!	plural). Los mensajes est�n basados en gran medida en los de 'Spanish.h'.
!!
!!
!!	# UTILIZACI�N
!!
!!	A continuaci�n se detallan los pasos que deben seguirse para usar la
!!	librer�a.
!!
!!	1)	Declarar la constante SIN_MENSAJES para omitir los mensajes por defecto
!!		de la librer�a Inform (antes de incluir librer�as y extensiones):
!!
!!			Constant SIN_MENSAJES;
!!
!!	2)	Declarar el reemplazo de la rutina 'ChangePlayer' definida en
!!		'parserm.h' (antes de incluir librer�as y extensiones):
!!
!!			Replace ChangePlayer;
!!
!!		Como se ha apuntado anteriormente, 'SpanishLM.h' utiliza un mecanismo
!!		que permite modificar la flexi�n gramatical de los mensajes de la
!!		librer�a en tiempo de ejecuci�n ---permitiendo mensajes en primera,
!!		segunda y tercera persona; presente, pasado y futuro; singular y
!!		plurar; masculino y femenino--- en funci�n, en parte, de los atributos
!!		del personaje controlado por el usuario. As�, al cambiar de personaje,
!!		se hace necesario actualizar el estado de la librer�a Inform.
!!
!!------------------------------------------------------------------------------


!!------------------------------------------------------------------------------
!! Definici�n de constantes y variables
!!------------------------------------------------------------------------------

Constant FIRST_PERSON_PRESENT	= 1;
Constant SECOND_PERSON_PRESENT	= 2;
Constant THIRD_PERSON_PRESENT	= 3;
Constant FIRST_PERSON_PAST		= 4;
Constant SECOND_PERSON_PAST		= 5;
Constant THIRD_PERSON_PAST		= 6;
Constant FIRST_PERSON_FUTURE	= 7;
Constant SECOND_PERSON_FUTURE	= 8;
Constant THIRD_PERSON_FUTURE	= 9;

Global _grammatical_inflection = SECOND_PERSON_PRESENT;


!!------------------------------------------------------------------------------
!! Funciones
!!------------------------------------------------------------------------------

[ _puedes_ x;
	switch (_grammatical_inflection) {
		FIRST_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "podemos";
			else print "puedo";
		SECOND_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "pod�is";
			else print "puedes";
		THIRD_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "pueden";
			else print "puede";
		FIRST_PERSON_PAST:
			if (IsPluralNoun(player)) print "pod�amos";
			else print "pod�a";
		SECOND_PERSON_PAST:
			if (IsPluralNoun(player)) print "pod�ais";
			else print "pod�as";
		THIRD_PERSON_PAST:
			if (IsPluralNoun(player)) print "pod�an";
			else print "pod�a";
		FIRST_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "podremos";
			else print "podr�";
		SECOND_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "podr�is";
			else print "podr�s";
		THIRD_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "podr�n";
			else print "podr�";
	}
	print (string) x;
];

[ oy_ x;
	switch (_grammatical_inflection) {
		FIRST_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "amos";
			else print "oy";
		SECOND_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "�is";
			else print "�s";
		THIRD_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "�n";
			else print "�";
		FIRST_PERSON_PAST:
			if (IsPluralNoun(player)) print "�bamos";
			else print "aba";
		SECOND_PERSON_PAST:
			if (IsPluralNoun(player)) print "abais";
			else print "abas";
		THIRD_PERSON_PAST:
			if (IsPluralNoun(player)) print "aban";
			else print "aba";
		FIRST_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "aremos";
			else print "ar�";
		SECOND_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "ar�is";
			else print "ar�s";
		THIRD_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "ar�n";
			else print "ar�";
	}
	print (string) x;
];

[ as_ x;
	switch (_grammatical_inflection) {
		FIRST_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "amos";
			else print "o";
		SECOND_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "�is";
			else print "as";
		THIRD_PERSON_PRESENT:
			if (IsPluralNoun(player)) print "an";
			else print "a";
		FIRST_PERSON_PAST:
			if (IsPluralNoun(player)) print "�bamos";
			else print "aba";
		SECOND_PERSON_PAST:
			if (IsPluralNoun(player)) print "abais";
			else print "abas";
		THIRD_PERSON_PAST:
			if (IsPluralNoun(player)) print "aban";
			else print "aba";
		FIRST_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "aremos";
			else print "ar�";
		SECOND_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "ar�is";
			else print "ar�s";
		THIRD_PERSON_FUTURE:
			if (IsPluralNoun(player)) print "ar�n";
			else print "ar�";
	}
	print (string) x;
];

!!==============================================================================
!! Intercambia el objeto controlado por el usuario por otro objeto dado.
!!
!!	@param {Object} obj
!!	@param {boolean} [flag]
!!	@overrides parserm.h
!!------------------------------------------------------------------------------
[ ChangePlayer obj flag
	i;
	if (actor == player) actor=obj;
    give player ~transparent ~concealed;
    i = obj; while (parent(i) ~= 0) {
        if (i has animate) give i transparent;
        i = parent(i);
    }

	!! XXX - Modificaci�n sobre la rutina original
	SetGrammaticalInflection(_grammatical_inflection, obj);
	!! XXX - Fin de la modificaci�n

    if (player == selfobj) player.short_name = FORMER__TX;

    player = obj;

    if (player == selfobj) player.short_name = NULL;
    give player transparent concealed animate proper;
    i = player; while (parent(i) ~= 0) i = parent(i);
    location = i; real_location = location;
    if (parent(player) == 0) return RunTimeError(10);
    MoveFloatingObjects();
    lightflag = OffersLight(parent(player));
    if (lightflag == 0) location = thedark;
    print_player_flag = flag;
];


!!==============================================================================
!! Determina si un objeto est� definido como nombre femenino o no.
!!
!!	@param {Object} obj
!!	@returns {boolean} Verdadero si el objeto est� definido como nombre
!!		femenino. Falso en caso contrario
!!------------------------------------------------------------------------------
[ IsFemaleNoun obj;
	return (GetGNAOfObject(obj, true) == 1 or 4 or 7 or 10);
];


!!==============================================================================
!! Determina si un objeto est� definido como nombre plural o no.
!!
!!	@param {Object} obj
!!	@returns {boolean} Verdadero si el objeto est� definido como nombre
!!		plural. Falso en caso contrario
!!------------------------------------------------------------------------------
[ IsPluralNoun obj;
	return (GetGNAOfObject(obj, true) == 3 or 4 or 5 or 9 or 10 or 11);
];


!!==============================================================================
!! Establece la flexi�n gramatical de los mensajes de la librer�a, actualizando
!! su estado. Para ello, utiliza la definici�n ---para determinar su g�nero y
!! n�mero--- de un objeto dado (si no se especifica uno, por defecto el objeto
!! 'player' controlado por el usuario).
!!
!!	@param {int} [gi=SECOND_PERSON_PRESENT] - Nueva flexi�n gramatical a
!!		utilizar en los mensajes de la librer�a. Si no se especifica un valor o
!!		el valor especificado es err�neo, se establece por defecto la segunda
!!		persona del presente: SECOND_PERSON_PRESENT.
!!	@param {Object} [obj=player] - Objeto del que se cosultan los atributos
!!		referidos a g�nero y n�mero utilizados para actualizar el estado de la
!!		librer�a.
!!------------------------------------------------------------------------------
[ SetGrammaticalInflection gi obj;
	if ((obj == 0) || (metaclass(obj) == nothing)) obj = player;
	switch (gi) {
		FIRST_PERSON_PRESENT:
			_grammatical_inflection = FIRST_PERSON_PRESENT;
			if (IsPluralNoun(player)) {
				ARE__TX			= " vemos";
				ARE2__TX		= "vemos ";
				CANTGO__TX		= "No podemos ir por ah�.";
				IS__TX			= " vemos";
				IS2__TX			= "vemos ";
				PARTICULA_TE	= "nos";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "nuestra antigua ~yo~";
					YOU__TX			= "Nosotras";
					YOURSELF__TX	= "nosotras mismas";
				} else {
					FORMER__TX		= "nuestro antiguo ~yo~";
					YOU__TX			= "Nosotros";
					YOURSELF__TX	= "nosotros mismos";
				}
			} else {
				ARE__TX			= " veo";
				ARE2__TX		= "veo ";
				CANTGO__TX		= "No puedo ir por ah�.";
				IS__TX			= " veo";
				IS2__TX			= "veo ";
				PARTICULA_TE	= "me";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "mi antigua ~yo~";
					YOU__TX			= "Yo";
					YOURSELF__TX	= "m� misma";
				} else {
					FORMER__TX		= "mi antiguo ~yo~";
					YOU__TX			= "Yo";
					YOURSELF__TX	= "m� mismo";
				}
			}
		SECOND_PERSON_PRESENT:
			.defaultInflection;
			_grammatical_inflection = SECOND_PERSON_PRESENT;
			if (IsPluralNoun(player)) {
				ARE__TX			= " veis";
				ARE2__TX		= "veis ";
				CANTGO__TX		= "No pod�is ir por ah�.";
				IS__TX			= " veis";
				IS2__TX			= "veis ";
				PARTICULA_TE	= "os";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "vuestra antigua ~yo~";
					YOU__TX			= "Vosotras";
					YOURSELF__TX	= "vosotras mismas";
				} else {
					FORMER__TX		= "vuestro antiguo ~yo~";
					YOU__TX			= "Vosotros";
					YOURSELF__TX	= "vosotros mismos";
				}
			} else {
				ARE__TX			= " ves";
				ARE2__TX		= "ves ";
				CANTGO__TX		= "No puedes ir por ah�.";
				IS__TX			= " ves";
				IS2__TX			= "ves ";
				PARTICULA_TE	= "te";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "tu antigua ~yo~";
					YOU__TX			= "T�";
					YOURSELF__TX	= "t� misma";
				} else {
					FORMER__TX		= "tu antiguo ~yo~";
					YOU__TX			= "T�";
					YOURSELF__TX	= "t� mismo";
				}
			}
		THIRD_PERSON_PRESENT:
			_grammatical_inflection = THIRD_PERSON_PRESENT;
			if (IsPluralNoun(player)) {
				ARE__TX			= " ven";
				ARE2__TX		= "ven ";
				CANTGO__TX		= "No pueden ir por ah�.";
				IS__TX			= " ven";
				IS2__TX			= "ven ";
				PARTICULA_TE	= "se";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "su antigua ~yo~";
					YOU__TX			= "Ellas";
					YOURSELF__TX	= "ellas mismas";
				} else {
					FORMER__TX		= "su antiguo ~yo~";
					YOU__TX			= "Ellos";
					YOURSELF__TX	= "ellos mismos";
				}
			} else {
				ARE__TX			= " ve";
				ARE2__TX		= "ve ";
				CANTGO__TX		= "No puede ir por ah�.";
				IS__TX			= " ve";
				IS2__TX			= "ve ";
				PARTICULA_TE	= "se";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "su antigua ~yo~";
					YOU__TX			= "Ella";
					YOURSELF__TX	= "s� misma";
				} else {
					FORMER__TX		= "su antiguo ~yo~";
					YOU__TX			= "�l";
					YOURSELF__TX	= "s� mismo";
				}
			}
		FIRST_PERSON_PAST:
			_grammatical_inflection = FIRST_PERSON_PAST;
			if (IsPluralNoun(player)) {
				ARE__TX			= " ve�amos";
				ARE2__TX		= "ve�amos ";
				CANTGO__TX		= "No pod�amos ir por ah�.";
				IS__TX			= " ve�amos";
				IS2__TX			= "ve�amos ";
				PARTICULA_TE	= "nos";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "nuestra antigua ~yo~";
					YOU__TX			= "Nosotras";
					YOURSELF__TX	= "nosotras mismas";
				} else {
					FORMER__TX		= "nuestro antiguo ~yo~";
					YOU__TX			= "Nosotros";
					YOURSELF__TX	= "nosotros mismos";
				}
			} else {
				ARE__TX			= " ve�a";
				ARE2__TX		= "ve�a ";
				CANTGO__TX		= "No pod�a ir por ah�.";
				IS__TX			= " ve�a";
				IS2__TX			= "ve�a ";
				PARTICULA_TE	= "me";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "mi antigua ~yo~";
					YOU__TX			= "Yo";
					YOURSELF__TX	= "m� misma";
				} else {
					FORMER__TX		= "mi antiguo ~yo~";
					YOU__TX			= "Yo";
					YOURSELF__TX	= "m� mismo";
				}
			}
		SECOND_PERSON_PAST:
			_grammatical_inflection = SECOND_PERSON_PAST;
			if (IsPluralNoun(player)) {
				ARE__TX			= " ve�ais";
				ARE2__TX		= "ve�ais ";
				CANTGO__TX		= "No pod�ais ir por ah�.";
				IS__TX			= " ve�ais";
				IS2__TX			= "ve�ais ";
				PARTICULA_TE	= "os";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "vuestra antigua ~yo~";
					YOU__TX			= "Vosotras";
					YOURSELF__TX	= "vosotras mismas";
				} else {
					FORMER__TX		= "vuestro antiguo ~yo~";
					YOU__TX			= "Vosotros";
					YOURSELF__TX	= "vosotros mismos";
				}
			} else {
				ARE__TX			= " ve�as";
				ARE2__TX		= "ve�as ";
				CANTGO__TX		= "No pod�as ir por ah�.";
				IS__TX			= " ve�as";
				IS2__TX			= "ve�as ";
				PARTICULA_TE	= "te";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "tu antigua ~yo~";
					YOU__TX			= "T�";
					YOURSELF__TX	= "t� misma";
				} else {
					FORMER__TX		= "tu antiguo ~yo~";
					YOU__TX			= "T�";
					YOURSELF__TX	= "t� mismo";
				}
			}
		THIRD_PERSON_PAST:
			_grammatical_inflection = THIRD_PERSON_PAST;
			if (IsPluralNoun(player)) {
				ARE__TX			= " ve�an";
				ARE2__TX		= "ve�an ";
				CANTGO__TX		= "No pod�an ir por ah�.";
				IS__TX			= " ve�an";
				IS2__TX			= "ve�an ";
				PARTICULA_TE	= "se";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "su antigua ~yo~";
					YOU__TX			= "Ellas";
					YOURSELF__TX	= "ellas mismas";
				} else {
					FORMER__TX		= "su antiguo ~yo~";
					YOU__TX			= "Ellos";
					YOURSELF__TX	= "ellos mismos";
				}
			} else {
				ARE__TX			= " ve�a";
				ARE2__TX		= "ve�a ";
				CANTGO__TX		= "No pod�a ir por ah�.";
				IS__TX			= " ve�a";
				IS2__TX			= "ve�a ";
				PARTICULA_TE	= "se";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "su antigua ~yo~";
					YOU__TX			= "Ella";
					YOURSELF__TX	= "s� misma";
				} else {
					FORMER__TX		= "su antiguo ~yo~";
					YOU__TX			= "�l";
					YOURSELF__TX	= "s� mismo";
				}
			}
		FIRST_PERSON_FUTURE:
			_grammatical_inflection = FIRST_PERSON_FUTURE;
			if (IsPluralNoun(player)) {
				ARE__TX			= " veremos";
				ARE2__TX		= "veremos ";
				CANTGO__TX		= "No podremos ir por ah�.";
				IS__TX			= " veremos";
				IS2__TX			= "veremos ";
				PARTICULA_TE	= "nos";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "nuestra antigua ~yo~";
					YOU__TX			= "Nosotras";
					YOURSELF__TX	= "nosotras mismas";
				} else {
					FORMER__TX		= "nuestro antiguo ~yo~";
					YOU__TX			= "Nosotros";
					YOURSELF__TX	= "nosotros mismos";
				}
			} else {
				ARE__TX			= " ver�";
				ARE2__TX		= "ver� ";
				CANTGO__TX		= "No podr� ir por ah�.";
				IS__TX			= " ver�";
				IS2__TX			= "ver� ";
				PARTICULA_TE	= "me";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "mi antigua ~yo~";
					YOU__TX			= "Yo";
					YOURSELF__TX	= "m� misma";
				} else {
					FORMER__TX		= "mi antiguo ~yo~";
					YOU__TX			= "Yo";
					YOURSELF__TX	= "m� mismo";
				}
			}
		SECOND_PERSON_FUTURE:
			_grammatical_inflection = SECOND_PERSON_FUTURE;
			if (IsPluralNoun(player)) {
				ARE__TX			= " ver�is";
				ARE2__TX		= "ver�is ";
				CANTGO__TX		= "No podr�is ir por ah�.";
				IS__TX			= " ver�is";
				IS2__TX			= "ver�is ";
				PARTICULA_TE	= "os";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "vuestra antigua ~yo~";
					YOU__TX			= "Vosotras";
					YOURSELF__TX	= "vosotras mismas";
				} else {
					FORMER__TX		= "vuestro antiguo ~yo~";
					YOU__TX			= "Vosotros";
					YOURSELF__TX	= "vosotros mismos";
				}
			} else {
				ARE__TX				= " ver�s";
				ARE2__TX			= "ver�s ";
				CANTGO__TX			= "No podr�s ir por ah�.";
				IS__TX				= " ver�s";
				IS2__TX				= "ver�s ";
				PARTICULA_TE		= "te";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "tu antigua ~yo~";
					YOU__TX			= "T�";
					YOURSELF__TX	= "t� misma";
				} else {
					FORMER__TX		= "tu antiguo ~yo~";
					YOU__TX			= "T�";
					YOURSELF__TX	= "t� mismo";
				}
			}
		THIRD_PERSON_FUTURE:
			_grammatical_inflection = THIRD_PERSON_FUTURE;
			if (IsPluralNoun(player)) {
				ARE__TX			= " ver�n";
				ARE2__TX		= "ver�n ";
				CANTGO__TX		= "No podr�n ir por ah�.";
				IS__TX			= " ver�n";
				IS2__TX			= "ver�n ";
				PARTICULA_TE	= "se";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "su antigua ~yo~";
					YOU__TX			= "Ellas";
					YOURSELF__TX	= "ellas mismas";
				} else {
					FORMER__TX		= "su antiguo ~yo~";
					YOU__TX			= "Ellos";
					YOURSELF__TX	= "ellos mismos";
				}
			} else {
				ARE__TX			= " ver�";
				ARE2__TX		= "ver� ";
				CANTGO__TX		= "No podr� ir por ah�.";
				IS__TX			= " ver�";
				IS2__TX			= "ver� ";
				PARTICULA_TE	= "se";
				if (IsFemaleNoun(player)) {
					FORMER__TX		= "su antigua ~yo~";
					YOU__TX			= "Ella";
					YOURSELF__TX	= "s� misma";
				} else {
					FORMER__TX		= "su antiguo ~yo~";
					YOU__TX			= "�l";
					YOURSELF__TX	= "s� mismo";
				}
			}
		default:
			jump defaultInflection;
	}
	ChangeDefault(cant_go, CANTGO__TX);
];

#Ifdef	DEBUG;
Verb	meta 'gramatica' 'grammar'
	*								-> Grammar
	* number						-> Grammar;
[ GrammarSub;
	switch (noun) {
		1:	SetGrammaticalInflection(FIRST_PERSON_PRESENT);
		2:	SetGrammaticalInflection(SECOND_PERSON_PRESENT);
		3:	SetGrammaticalInflection(THIRD_PERSON_PRESENT);
		4:	SetGrammaticalInflection(FIRST_PERSON_PAST);
		5:	SetGrammaticalInflection(SECOND_PERSON_PAST);
		6:	SetGrammaticalInflection(THIRD_PERSON_PAST);
		7:	SetGrammaticalInflection(FIRST_PERSON_FUTURE);
		8:	SetGrammaticalInflection(SECOND_PERSON_FUTURE);
		9:	SetGrammaticalInflection(THIRD_PERSON_FUTURE);
		default:
			"Flexi�n gramatical actual: ", _grammatical_inflection,
			"^ARE__TX: ", ARE__TX,
			"^ARE2__TX: ", ARE2__TX,
			"^CANTGO__TX: ", CANTGO__TX,
			"^IS__TX: ", IS__TX,
			"^IS2__TX: ", IS2__TX,
			"^PARTICULA_TE: ", PARTICULA_TE,
			"^FORMER__TX: ", FORMER__TX,
			"^YOU__TX: ", YOU__TX,
			"^YOURSELF__TX: ", YOURSELF__TX;
	}
	print "Cambio de flexi�n gramatical: ";
	switch (_grammatical_inflection) {
		FIRST_PERSON_PRESENT:	print "(1) presente 1a persona";
		SECOND_PERSON_PRESENT:	print "(2) presente 2a persona";
		THIRD_PERSON_PRESENT:	print "(3) presente 3a persona";
		FIRST_PERSON_PAST:		print "(4) pasado 1a persona";
		SECOND_PERSON_PAST:		print "(5) pasado 2a persona";
		THIRD_PERSON_PAST:		print "(6) pasado 3a persona";
		FIRST_PERSON_FUTURE:	print "(7) futuro 1a persona";
		SECOND_PERSON_FUTURE:	print "(8) futuro 2a persona";
		THIRD_PERSON_FUTURE:	print "(9) futuro 3a persona";
	}
	".";
];
#Endif; ! DEBUG;


!!==============================================================================
[ LanguageLM n x1;

	Answer, Ask, AskFor:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				"No hay respuesta.";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				"No hab�a respuesta.";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				"No habr� respuesta.";
		}

!!	Ask:	see Answer
!!	AskFor:	see Answer

	Attack:
		print "No ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				print "es";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "era";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "ser�";
		}
		" necesario emprenderla a golpes con ", (the) x1, ".";

	Blow:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "Nuestro";
				else print "Mi";
				print " soplido no produce";
			SECOND_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "Vuestro";
				else print "Tu";
				print " soplido no produce";
			THIRD_PERSON_PRESENT:
				print "Su soplido no produce";
			FIRST_PERSON_PAST:
				if (IsPluralNoun(player)) print "Nuestro";
				else print "Mi";
				print " soplido no produjo";
			SECOND_PERSON_PAST:
				if (IsPluralNoun(player)) print "Vuestro";
				else print "Tu";
				print " soplido no produjo";
			THIRD_PERSON_PAST:
				print "Su soplido no produjo";
			FIRST_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "Nuestro";
				else print "Mi";
				print " soplido no producir�";
			SECOND_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "Vuestro";
				else print "Tu";
				print " soplido no producir�";
			THIRD_PERSON_FUTURE:
				print "Su soplido no producir�";
		}
		" ning�n efecto.";

	Burn:
		print "Con esa peligrosa acci�n no ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			FIRST_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "�bamos";
				else print "iba";
				" a lograr nada.";
			SECOND_PERSON_PRESENT,
			SECOND_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "ibais";
				else print "ibas";
				" a lograr nada.";
			THIRD_PERSON_PRESENT,
			THIRD_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "iban";
				else print "iba";
				" a lograr nada.";
			FIRST_PERSON_PAST:
				if (IsPluralNoun(player)) print "hubi�semos";
				else print "hubiese";
				" logrado nada.";
			SECOND_PERSON_PAST:
				if (IsPluralNoun(player)) print "hubieseis";
				else print "hubieses";
				" logrado nada.";
			THIRD_PERSON_PAST:
				if (IsPluralNoun(player)) print "hubiesen";
				else print "hubiese";
				" logrado nada.";
		}

	Buy:
		print "No ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				print "hay";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "hab�a";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "habr�";
		}
		" nada en venta.";

	Climb:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "No creemos que vayamos";
				else print "No creo que vaya";
				" a lograr nada haciendo eso.";
			SECOND_PERSON_PRESENT:
				print "En realidad no";
				if (IsPluralNoun(player)) print "cre�is que vay�is";
				else print "crees que vayas";
				" a lograr nada haciendo eso.";
			THIRD_PERSON_PRESENT:
				print "En realidad no";
				if (IsPluralNoun(player)) print "creen que vayan";
				else print "cree que vaya";
				" a lograr nada haciendo eso.";
			FIRST_PERSON_PAST:
				if (IsPluralNoun(player)) print "No creemos que hubi�semos";
				else print "No creo que hubiese";
				" logrado nada haciendo aquello.";
			SECOND_PERSON_PAST:
				print "En realidad no";
				if (IsPluralNoun(player)) print "cre�is que hubieseis";
				else print "crees que hubieses";
				" logrado nada haciendo aquello.";
			THIRD_PERSON_PAST:
				print "En realidad no";
				if (IsPluralNoun(player)) print "creen que hubiesen";
				else print "cree que hubiese";
				" logrado nada haciendo aquello.";
			FIRST_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "No lograremos";
				else print "No lograr�";
				" nada haciendo eso.";
			SECOND_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "No lograr�is";
				else print "No lograr�s";
				" nada haciendo eso.";
			THIRD_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "No lograr�n";
				else print "No lograr�";
				" nada haciendo eso.";
		}

	Close:
		!!	1:	Error. El objeto no es *openable*.
		!!	2:	Error. El objeto est� cerrado.
		!!	3:	Mensaje cuando se cierra el objeto.
		switch (n) {
			1:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						"No es algo que pueda cerrarse.";
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						"No era algo que se pudiese cerrar.";
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						"No ser� algo que pueda cerrarse.";
				}
			2:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						"Ya estaba", (n) x1, " cerrad", (o) x1, ".";
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						"Ya estaba", (n) x1, " cerrad", (o) x1, ".";
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						"Ya estar�", (n) x1, " cerrad", (o) x1, ".";
				}
			3:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Cerramos";
						else print "Cierro";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Cerr�is";
						else print "Cierras";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Cierran";
						else print "Cierra";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "Cerramos";
						else print "Cerr�";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "Cerrasteis";
						else print "Cerraste";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "Cerraron";
						else print "Cerr�";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Cerraremos";
						else print "Cerrar�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Cerrar�is";
						else print "Cerrar�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Cerrar�n";
						else print "Cerrar�";
				}
				" ", (the) x1, ".";
		}

	CommandsOff:
		switch (n) { ![6/11]
			1:	"[Grabaci�n de �rdenes finalizada.]";
			#Ifdef TARGET_GLULX;
			2:	"[Grabaci�n de �rdenes ya finalizada.]";
			#Endif; ! TARGET_
		}

	CommandsOn:
		switch (n) { ![6/11]
			1:	"[Grabaci�n de �rdenes activada.]";
			#Ifdef TARGET_GLULX;
			2:	"[�rdenes relanzadas.]";
			3:	"[Grabaci�n de �rdenes ya activada.]";
			4:	"[Fallo en la grabaci�n de �rdenes.]";
			#Endif; ! TARGET_
		}

	CommandsRead:
		switch (n) { ![6/11]
			1:	"[Relanzando acciones.]";
			#Ifdef TARGET_GLULX;
			2:	"[Las �rdenes ya est�n siendo relanzadas.]";
			3:	"[Fallo en la reejecuci�n de �rdenes: grabaci�n en curso.]";
			4:	"[Fallo en la reejecuci�n de �rdenes.]";
			5:	"[Acciones ejecutadas: fin del proceso.]";
			#Endif; ! TARGET_
		}

	Consult:
		print "No ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "descubrimos";
				else print "descubro";
			SECOND_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "descubr�s";
				else print "descubres";
			THIRD_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "descubren";
				else print "descubre";
			FIRST_PERSON_PAST:
				if (IsPluralNoun(player)) print "descubrimos";
				else print "descubr�";
				" nada interesante en ", (the) x1, " sobre aquel tema.";
			SECOND_PERSON_PAST:
				if (IsPluralNoun(player)) print "descubristeis";
				else print "descubriste";
				" nada interesante en ", (the) x1, " sobre aquel tema.";
			THIRD_PERSON_PAST:
				if (IsPluralNoun(player)) print "descubrieron";
				else print "descubri�";
				" nada interesante en ", (the) x1, " sobre aquel tema.";
			FIRST_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "descubriremos";
				else print "descubrir�";
			SECOND_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "descubrir�is";
				else print "descubrir�s";
			THIRD_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "descubrir�n";
				else print "descubrir�";
		}
		" nada interesante en ", (the) x1, " sobre ese tema.";

	Cut:
		print "Cort�ndo", (lo) x1, " no ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			FIRST_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "lograremos";
				else print "lograr�";
			SECOND_PERSON_PRESENT,
			SECOND_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "lograr�is";
				else print "lograr�s";
			THIRD_PERSON_PRESENT,
			THIRD_PERSON_FUTURE:
				if (IsPluralNoun(player)) print "lograr�n";
				else print "lograr�";
			FIRST_PERSON_PAST:
				if (IsPluralNoun(player)) print "hubi�semos logrado";
				else print "hubiese logrado";
			SECOND_PERSON_PAST:
				if (IsPluralNoun(player)) print "hubieseis logrado";
				else print "hubiese logrado";
			THIRD_PERSON_PAST:
				if (IsPluralNoun(player)) print "hubiesen logrado";
				else print "hubiese logrado";
		}
		" gran cosa.";

	Dig:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT:
			THIRD_PERSON_PRESENT:
				"Excavar no servir� de nada aqu�.";
			FIRST_PERSON_PAST:
			SECOND_PERSON_PAST:
			THIRD_PERSON_PAST:
				"Excavar no hubiese servido de nada all�.";
			FIRST_PERSON_FUTURE:
			SECOND_PERSON_FUTURE:
			THIRD_PERSON_FUTURE:
				"Excavar no servir� de nada all�.";
		}

	Disrobe:
		!!	1:	Error. El protagonista no lleva el objeto puesto.
		!!	2:	Mensaje cuando el protagonista se quita el objeto.
		switch (n) {
			1:	print "No ", (lo) x1, " ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "llevamos";
						else print "llevo";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "llev�is";
						else print "llevas";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "llevan";
						else print "lleva";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "llev�bamos";
						else print "llevaba";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "llevabais";
						else print "llevabas";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "llevaban";
						else print "llevaba";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "llevaremos";
						else print "llevar�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "llevar�is";
						else print "llevar�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "llevar�n";
						else print "llevar�";
				}
				" puest", (o) x1, ".";
			2:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Nos quitamos";
						else print "Me quito";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Os quit�is";
						else print "Te quitas";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Se quitan";
						else print "Se quita";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "Nos quitamos";
						else print "Me quit�";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "Os quitasteis";
						else print "Te quitaste";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "Se quitaron";
						else print "Se quit�";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Nos quitaremos";
						else print "Me quitar�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Os quitar�is";
						else print "Te quitar�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Se quitar�n";
						else print "Se quitar�";
				}
				" ", (the) x1, ".";
		}

	Drink:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT:
			THIRD_PERSON_PRESENT:
				"Eso no parece potable.";
			FIRST_PERSON_PAST:
			SECOND_PERSON_PAST:
			THIRD_PERSON_PAST:
				"Aquello no parec�a potable.";
			FIRST_PERSON_FUTURE:
			SECOND_PERSON_FUTURE:
			THIRD_PERSON_FUTURE:
				"Eso no parecer� potable.";
		}

	Drop:
		!!	1:	Error, el objeto dejado no est� en poder del protagonista,
		!!		pero est� en la localidad.
		!!	2:	Error, el objeto dejado no est� en poder del protagonista ni en
		!!		la localidad,
		!!	3:	Aviso, el objeto era una prenda que el protagonista llevaba
		!!		puesta y la librer�a va a quit�rsela autom�ticamente para poder
		!!		dejarla.
		!!	4:	�xito.
		switch (n) {
			1:	print "Para dejar ", (the) x1, " ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "deber�amos";
						else print "deber�a";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "deber�ais";
						else print "deber�as";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "deber�an";
						else print "deber�a";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "hubi�semos debido";
						else print "hubiese debido";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "hubieseis debido";
						else print "hubieses debido";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "hubiesen debido";
						else print "hubiese debido";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "deberemos";
						else print "deber�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "deber�is";
						else print "deber�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "deber�n";
						else print "deber�";
				}
				" tener", (lo) x1, ".";
			2:	print "No ", (lo) x1, " ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (~~IsPluralNoun(player)) "tengo conmigo.";
						if (IsFemaleNoun(player)) "tenemos con nosotras.";
						"tenemos con nosotros.";
					SECOND_PERSON_PRESENT:
						if (~~IsPluralNoun(player)) "tienes contigo.";
						if (IsFemaleNoun(player)) "ten�is con vosotras.";
						"ten�is con vosotros.";
					THIRD_PERSON_PRESENT:
						if (~~IsPluralNoun(player)) "tiene consigo";
						if (IsFemaleNoun(noun)) "tienen con ellas.";
						"tienen con ellos.";
					FIRST_PERSON_PAST:
						if (~~IsPluralNoun(player)) "ten�a conmigo";
						if (IsFemaleNoun(noun)) "ten�amos con nosotras.";
						"ten�amos con nosotros.";
					SECOND_PERSON_PAST:
						if (~~IsPluralNoun(player)) "ten�as contigo";
						if (IsFemaleNoun(noun)) "ten�ais con vosotras.";
						"ten�ais con vosotros.";
					THIRD_PERSON_PAST:
						if (~~IsPluralNoun(player)) "ten�a consigo";
						if (IsFemaleNoun(noun)) "ten�an con ellas.";
						"ten�an con ellos.";
					FIRST_PERSON_FUTURE:
						if (~~IsPluralNoun(player)) "tendr� conmigo";
						if (IsFemaleNoun(noun)) "tendremos con nosotras.";
						"tendremos con nosotros.";
					SECOND_PERSON_FUTURE:
						if (~~IsPluralNoun(player)) "tendr�s contigo";
						if (IsFemaleNoun(noun)) "tendr�is con vosotras.";
						"tendr�is con vosotros.";
					THIRD_PERSON_FUTURE:
						if (~~IsPluralNoun(player)) "tendr� consigo";
						if (IsFemaleNoun(noun)) "tendr�n con ellas.";
						"tendr�n con ellos.";
				}
			3:	print "(Primero ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "nos quitamos";
						else print "me quito";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "os quit�is";
						else print "te quitas";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "se quitan";
						else print "se quita";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "nos quitamos";
						else print "me quit�";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "os quitasteis";
						else print "te quitaste";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "se quitaron";
						else print "se quit�";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "nos quitaremos";
						else print "me quitar�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "os quitar�is";
						else print "te quitar�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "se quitar�n";
						else print "se quitar�";
				}
				" ", (the) x1, ".)";
			4:	"Dejad", (o) x1, ".";
		}

	Eat:
		!!	1:	Error, el objeto no tiene el atributo "comestible".
		!!	2:	�xito. [NOTA: la librer�a permite por defecto comerse
		!!		cualquier cosa que tenga el atributo "comestible", pero la
		!!		�nica acci�n que provoca esto es que el objeto en cuesti�n
		!!		desaparece del juego al ser comido.]
		switch (n) {
			1:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT:
					THIRD_PERSON_PRESENT:
						"Eso no parece comestible.";
					FIRST_PERSON_PAST:
					SECOND_PERSON_PAST:
					THIRD_PERSON_PAST:
						"Aquello no parec�a comestible.";
					FIRST_PERSON_FUTURE:
					SECOND_PERSON_FUTURE:
					THIRD_PERSON_FUTURE:
						"Eso no parecer� comestible.";
				}
			2:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Nos comemos";
						else print "Me como";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Os com�is";
						else print "Te comes";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "Se comen";
						else print "Se come";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "Nos comimos";
						else print "Me com�";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "Os comisteis";
						else print "Te comiste";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "Se comieron";
						else print "Se comi�";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Nos comeremos";
						else print "Me comer�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Os comer�is";
						else print "Te comer�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "Se comer�n";
						else print "Se comer�";
				}
				" ", (the) x1, ".";
		}

	EmptyT:
		!!	1:	Error, el usuario intenta vaciar un objeto en otro que no es un
		!!		recipiente.
		!!	2:	Error, el usuario intenta vaciar un objeto sobre un recipiente
		!!		cerrado.
		!!	3:	Error, el usuario intenta vaciar un objeto que no tiene nada
		!!		dentro.
		!!	4:	Error, el usuario intenta vaciar un objeto sobre s� mismo.
		!!
		!! [NOTA: No hay mensajes de �xito para esta acci�n, ya que en caso
		!! de haber superado los test anteriores, la librer�a genera
		!! finalmente la acci�n ##Transfer, la cu�l, a su vez, generar� la
		!! acci�n ##PutOn o ##Insert, seg�n el segundo objeto sea soporte o
		!! recipiente. Por tanto los mensajes de �xito ser�n los de las
		!! acciones ##PutOn o ##Insert.]
		switch (n) {
			1:	print (The) x1, " no ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "puede", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "pod�a", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "podr�", (n) x1;
				}
				" tener cosas dentro.";
			2:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print (The) x1, " est�", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print (The) x1, " estaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print (The) x1, " estar�", (n) x1;
				}
				" cerrad", (o) x1, ".";
			3:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print (The) x1, " ya est�", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print (The) x1, " ya estaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print (The) x1, " ya estar�", (n) x1;
				}
				" vac�", (o) x1, ".";
			4:	print "No ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "podemos";
						else print "puedo";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "pod�is";
						else print "puedes";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "pueden";
						else print "puede";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "pod�amos";
						else print "pod�a";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "pod�ais";
						else print "pod�as";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "pod�an";
						else print "pod�a";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "podremos";
						else print "podr�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "podr�is";
						else print "podr�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "podr�n";
						else print "podr�";
				}
				" vaciar un objeto sobre s� mismo.";
		}

	Enter:
		! [infsp] GoIn (Meterse) se cambi� por Enter.
		!! CUIDADO. La acci�n Meterse se genera en muy diversas
		!! circunstancias: VETE HACIA EL PUENTE, VETE AL PUENTE, VETE POR
		!! EL PUENTE, PASA POR EL PUENTE, ENTRA EN EL PUENTE, ENTRA AL
		!! PUENTE, CRUZA EL PUENTE, CRUZA POR EL PUENTE, METETE EN EL
		!! PUENTE, METETE POR EL PUENTE, ATRAVIESA EL PUENTE, BAJA POR EL
		!! PUENTE.  Todas ellas generar�an la acci�n <Meterse Puente>
		!!
		!! Adem�s, los intentos de entrar en un "entrable", tambi�n, como
		!! por ejemplo: SIENTATE EN EL BANCO, ECHATE EN EL BANCO, SUBETE AL
		!! BANCO, SUBETE EN EL BANCO, SUBE AL BANCO, SUBE POR EL BANCO,
		!! SALTA AL BANCO. Todas ellas generar�an <Meterse Banco>
		!!
		!! Puesto que hay muchos verbos diferentes que dan lugar a la misma
		!! acci�n, es necesaria alguna forma de imprimir qu� verbo concreto
		!! ha sido el que la ha desencadenado, para poder generar mensajes
		!! como "No puedes entrar ahi", "No puedes sentarte ahi", "No
		!! puedes subirte ahi", etc.. seg�n el verbo usado. Para esto puede
		!! usarse una llamada a IdiomaVerbo(palabra_verbo). palabra_verbo
		!! contiene el verbo usado por el jugador (convertido en forma
		!! imperativa), y IdiomaVerbo lo que hace es imprimir la forma
		!! infinitiva.
		!!
		!! Mensajes que puede generar esta acci�n:
		!!	1:	Error, el protagonista ya est� en/sobre el objeto.
		!!	2:	Error, el objeto al que intenta entrar/subirse el usuario
		!!		no tiene el atributo "enterable".
		!!	3:	Error, el objeto al que intenta entrar/subirse el usuario tiene
		!!		los atributos "container" y "enterable", pero est� cerrado.
		!!	4:	Error, el objeto al que intenta entrar/subirse el usuario est�
		!!		en poder del propio usuario.
		!!	5:	�xito, el usuario entra/sube al objeto.
		!!	6:	Aviso, el usuario estaba en otro objeto, la lib. intentar� la
		!!		acci�n SALIR autom�ticamente antes de reintentar entrar el
		!!		nuevo objeto.
		!!	7:	Aviso, el objeto al que intenta entrar/subirse el usuario est�
		!!		dentro de otros objeto. La lib. intentar� autom�ticamente meter
		!!		al jugador en el objeto desde el cual pueda acceder al que el
		!!		jugador le ha indicado.
		switch (n) {
			1:	print "Ya est", (oy_) " ";
				if (x1 has supporter) print "sobre ";
				else print "en ";
				"", (the) x1, ".";
			2:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player))
							print "No es algo donde podamos";
						else print "No es algo donde pueda";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player))
							print "No es algo donde pod�is";
						else print "No es algo donde puedas";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player))
							print "No es algo donde puedan";
						else print "No es algo donde pueda";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player))
							print "No era algo donde pudi�semos";
						else print "No era algo donde pudiese";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player))
							print "No era algo donde pudieseis";
						else print "No era algo donde pudieses";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player))
							print "No era algo donde pudiesen";
						else print "No era algo donde pudiese";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player))
							print "No ser� algo donde podremos";
						else print "No ser� algo donde podr�";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player))
							print "No ser� algo donde podr�is";
						else print "No ser� algo donde podr�s";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player))
							print "No ser� algo donde podr�n";
						else print "No ser� algo donde podr�";
				}
				LanguageVerb(verb_word); ".";
			3:	print "No ", (_puedes_) " ";
				LanguageVerb(verb_word);
				print " en ", (the) x1, " porque ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "est�", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "estaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "estar�", (n) x1;
				}
				" cerrad", (o) x1, ".";
			4:	print "No ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "vamos a poder";
						else print "voy a poder";
					SECOND_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "vais a poder";
						else print "vas a poder";
					THIRD_PERSON_PRESENT:
						if (IsPluralNoun(player)) print "van a poder";
						else print "va a poder";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "�bamos a poder";
						else print "iba a poder";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "ibais a poder";
						else print "ibas a poder";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "iban a poder";
						else print "iba a poder";
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "podremos";
						else print "podr�";
						" hacerlo sin soltarlo antes.";
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "podr�is";
						else print "podr�s";
						" hacerlo sin soltarlo antes.";
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "podr�n";
						else print "podr�";
						" hacerlo sin soltarlo antes.";
				}
				LanguageVerb(verb_word);
				print " ah� mientras no ", (lo) x1, " ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					FIRST_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "soltemos";
						else print "suelte";
					SECOND_PERSON_PRESENT,
					SECOND_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "solt�is";
						else print "sueltes";
					THIRD_PERSON_PRESENT,
					THIRD_PERSON_FUTURE:
						if (IsPluralNoun(player)) print "suelten";
						else print "suelte";
					FIRST_PERSON_PAST:
						if (IsPluralNoun(player)) print "solt�semos";
						else print "soltase";
					SECOND_PERSON_PAST:
						if (IsPluralNoun(player)) print "soltaseis";
						else print "soltases";
					THIRD_PERSON_PAST:
						if (IsPluralNoun(player)) print "soltasen";
						else print "soltase";
				}
				".";
			5:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subimos";
							else print "Subo";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entramos";
							else print "Entro";
							print " en ", (the) x1;
						}
						".";
					SECOND_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Sub�s";
							else print "Subes";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entr�is";
							else print "Entras";
							print " en ", (the) x1;
						}
						".";
					THIRD_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Suben";
							else print "Sube";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entran";
							else print "Entra";
							print " en ", (the) x1;
						}
						".";
					FIRST_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subimos";
							else print "Sub�";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entramos";
							else print "Entr�";
							print " en ", (the) x1;
						}
						".";
					SECOND_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subisteis";
							else print "Subiste";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entrasteis";
							else print "Entraste";
							print " en ", (the) x1;
						}
						".";
					THIRD_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subieron";
							else print "Subi�";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entraron";
							else print "Entr�";
							print " en ", (the) x1;
						}
						".";
					FIRST_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subiremos";
							else print "Subir�";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entraremos";
							else print "Entrar�";
							print " en ", (the) x1;
						}
						".";
					SECOND_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subir�is";
							else print "Subir�s";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entrar�is";
							else print "Entrar�s";
							print " en ", (the) x1;
						}
						".";
					THIRD_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "Subir�n";
							else print "Subir�";
							print " ", (al_) x1;
						} else {
							if (IsPluralNoun(player)) print "Entrar�n";
							else print "Entrar�";
							print " en ", (the) x1;
						}
						".";
				}
			6:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Nos bajamos";
							else print "(Me bajo";
						} else {
							if (IsPluralNoun(player)) print "(Salimos";
							else print "(Salgo";
						}
					SECOND_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Os baj�is";
							else print "(Te bajas";
						} else {
							if (IsPluralNoun(player)) print "(Sal�s";
							else print "(Sales";
						}
					THIRD_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Se bajan";
							else print "(Se baja";
						} else {
							if (IsPluralNoun(player)) print "(Salen";
							else print "(Sale";
						}
					FIRST_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Nos bajamos";
							else print "(Me baj�";
						} else {
							if (IsPluralNoun(player)) print "(Salimos";
							else print "(Sal�";
						}
					SECOND_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Os baj�steis";
							else print "(Te bajaste";
						} else {
							if (IsPluralNoun(player)) print "(Salisteis";
							else print "(Saliste";
						}
					THIRD_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Se bajaron";
							else print "(Se baj�";
						} else {
							if (IsPluralNoun(player)) print "(Salieron";
							else print "(Sali�";
						}
					FIRST_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Nos bajaremos";
							else print "(Me bajar�";
						} else {
							if (IsPluralNoun(player)) print "(Saldremos";
							else print "(Saldr�";
						}
					SECOND_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Os bajar�is";
							else print "(Te bajar�s";
						} else {
							if (IsPluralNoun(player)) print "(Saldr�is";
							else print "(Saldr�s";
						}
					THIRD_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Se bajar�n";
							else print "(Se bajar�";
						} else {
							if (IsPluralNoun(player)) print "(Saldr�n";
							else print "(Saldr�";
						}
				}
				" ", (del_) x1, ").";
			7:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Nos subimos";
							else print "(Me subo";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Nos metemos";
							else print "(Me meto";
						} else {
							if (IsPluralNoun(player)) print "(Entramos";
							else print "(Entro";
						}
					SECOND_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Os sub�s";
							else print "(Te subes";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Os met�is";
							else print "(Te metes";
						} else {
							if (IsPluralNoun(player)) print "(Entr�is";
							else print "(Entras";
						}
					THIRD_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Se suben";
							else print "(Se sube";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Se meten";
							else print "(Se mete";
						} else {
							if (IsPluralNoun(player)) print "(Entran";
							else print "(Entra";
						}
					FIRST_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Nos subimos";
							else print "(Me sub�";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Nos metimos";
							else print "(Me met�";
						} else {
							if (IsPluralNoun(player)) print "(Entramos";
							else print "(Entr�";
						}
					SECOND_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Os subisteis";
							else print "(Te subiste";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Os metisteis";
							else print "(Te metiste";
						} else {
							if (IsPluralNoun(player)) print "(Entrasteis";
							else print "(Entraste";
						}
					THIRD_PERSON_PAST:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Se subieron";
							else print "(Se subi�";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Se metieron";
							else print "(Se meti�";
						} else {
							if (IsPluralNoun(player)) print "(Entraron";
							else print "(Entr�";
						}
					FIRST_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Nos subiremos";
							else print "(Me subir�";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Nos meteremos";
							else print "(Me meter�";
						} else {
							if (IsPluralNoun(player)) print "(Entraremos";
							else print "(Entrar�";
						}
					SECOND_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Os subir�is";
							else print "(Te subir�s";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Os meter�is";
							else print "(Te meter�s";
						} else {
							if (IsPluralNoun(player)) print "(Entrar�is";
							else print "(Entrar�s";
						}
					THIRD_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsPluralNoun(player)) print "(Se subir�n";
							else print "(Se subir�";
							" ", (al_) x1, ".)^";
						} else if (x1 has container) {
							if (IsPluralNoun(player)) print "(Se meter�n";
							else print "(Se meter�";
						} else {
							if (IsPluralNoun(player)) print "(Entrar�n";
							else print "(Entrar�";
						}
				}
				" en ", (the) x1, ".)^";
		}

!! TODO
	Examine:
		!!	1:	Error, el usuario intenta examinar un objeto, pero est� a
		!!		oscuras.
		!!	2:	�xito, pero el objeto examinado no tiene descripcion
		!!	3:	�xito, pero el objeto examinado no tiene descripcion, aunque
		!!		tiene el atributo conmutable, por lo que la librer�a genera
		!!		este mensaje para indicar si est� apagado o encendido.
		switch (n) {
			1:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "Est�";
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "Estaba";
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "Estar�";
				}
				" demasiado oscuro. No ", (_puedes_) " ver nada.";
			2:	print "No ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "observo";
						else print "observamos";
					SECOND_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "observas";
						else print "observ�is";
					THIRD_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "observa";
						else print "observan";
					FIRST_PERSON_PAST:
						if (IsSingularNoun(player)) print "observ�";
						else print "observamos";
					SECOND_PERSON_PAST:
						if (IsSingularNoun(player)) print "observaste";
						else print "observasteis";
					THIRD_PERSON_PAST:
						if (IsSingularNoun(player)) print "observ�";
						else print "observaron";
					FIRST_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "observar�";
						else print "observaremos";
					SECOND_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "observar�s";
						else print "observar�is";
					THIRD_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "observar�";
						else print "observar�n";
				}
				" nada especial en ", (the) x1, ".";
			3:	switch (_grammatical_inflection) {
					1,2,3:	print (The) x1, " est�", (n) x1;
					4,5,6:	print (The) x1, " estaba", (n) x1;
					7,8,9:	print (The) x1, " estar�", (n) x1;
				}
				if (x1 has on) " encendid", (o) x1, ".";
				else " apagad", (o) x1,".";
		}

!! TODO
	Exit:
		!!	1:	Error, el usuario no est� subido/sentado/metido en ning�n
		!!		objeto. [Nota, si la localidad tiene la propiedad "afuera",
		!!		entonces la acci�n Salir lo sacar� de la localidad. En caso
		!!		contrario es cuando se genera este error.]
		!!	2:	Error, el usuario est� dentro de un recipiente cerrado.
		!!	3:	�xito, el usuario sale/baja del objeto
		!!	4:	Error, m�s espec�fico. [6/11]
		switch (n) {
			1:	print "No est", (oy_) " en ning�n sitio del que ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "deba";
						else print "debamos";
					SECOND_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "debas";
						else print "deb�is";
					THIRD_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "deba";
						else print "deban";
					FIRST_PERSON_PAST:
						if (IsSingularNoun(player)) print "debiese";
						else print "debi�semos";
					SECOND_PERSON_PAST:
						if (IsSingularNoun(player)) print "debieses";
						else print "debieseis";
					THIRD_PERSON_PAST:
						if (IsSingularNoun(player)) print "debiese";
						else print "debiesen";
					FIRST_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "deber�a";
						else print "deber�amos";
					SECOND_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "deber�as";
						else print "deber�ais";
					THIRD_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "deber�a";
						else print "deber�an";
				}
				LanguageVerb(verb_word); ".";
			2:	print "No ", (_puedes_) " salir ", (del_) x1, " porque ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "est�", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "estaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "estar�", (n) x1;
				}
				" cerrad", (o) x1, ".";
			3:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Bajo";
							else print "Bajamos";
						} else {
							if (IsSingularNoun(player)) print "Salgo";
							else print "Salimos";
						}
					SECOND_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Bajas";
							else print "Baj�is";
						} else {
							if (IsSingularNoun(player)) print "Sales";
							else print "Sal�s";
						}
					THIRD_PERSON_PRESENT:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Baja";
							else print "Bajan";
						} else {
							if (IsSingularNoun(player)) print "Sale";
							else print "Salen";
						}
					FIRST_PERSON_PAST:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Baj�";
							else print "Bajamos";
						} else {
							if (IsSingularNoun(player)) print "Sal�";
							else print "Salimos";
						}
					SECOND_PERSON_PAST:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Bajaste";
							else print "Bajasteis";
						} else {
							if (IsSingularNoun(player)) print "Saliste";
							else print "Salisteis";
						}
					THIRD_PERSON_PAST:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Baj�";
							else print "Bajaron";
						} else {
							if (IsSingularNoun(player)) print "Sali�";
							else print "Salieron";
						}
					FIRST_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Bajar�";
							else print "Bajaremos";
						} else {
							if (IsSingularNoun(player)) print "Saldr�";
							else print "Saldremos";
						}
					SECOND_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Bajar�s";
							else print "Bajar�is";
						} else {
							if (IsSingularNoun(player)) print "Saldr�s";
							else print "Saldr�is";
						}
					THIRD_PERSON_FUTURE:
						if (x1 has supporter) {
							if (IsSingularNoun(player)) print "Bajar�";
							else print "Bajar�n";
						} else {
							if (IsSingularNoun(player)) print "Saldr�";
							else print "Saldr�n";
						}
				}
				" ", (del_) x1, ".";
			4:	print "No ", (_puedes_) ". No est", (oy_) " ";
				if (x1 has supporter) print "encima";
				else print "dentro";
				" ", (del_) x1, ".";
		}

	Fill:
		print "No ", (_puedes_) " llenar", (lo) x1, ".";

	FullScore:
		!! Puntuaci�n en modo "explicativo". Puede activarse porque el
		!! usuario lo pida con el verbo "PUNTUACION LARGA" o porque el
		!! relato haya terminado (y la constante HAY_TAREAS est� definida).
		!!
		!!	1:	Texto introductorio al desglose de puntos
		!!	2:	Texto de objetos importantes (los que tienen el atributo
		!!		"valepuntos")
		!!	3:	Texto de lugares importantes (los que tienen el atributo
		!!		"valepuntos")
		!!	4:	Texto final, tras la suma total impresa por la librer�a
		switch (n) {
			1:	if (deadflag) print "La puntuaci�n se desglos� ";
				else          print "La puntuaci�n se desglosa ";
				"de la siguiente manera:^";
			2: "por encontrar objetos importantes";
			3: "por visitar lugares importantes";
			4: print "total (de ", MAX_SCORE ; ")";
		}

	GetOff:
		!! Esta acci�n se genera ante la frase SAL DEL ARMARIO o similares.
		!! Ante SAL a secas la acci�n es Salir. Si el jugador no est� en el
		!! objeto indicado, se genera el siguiente mensaje de error. Si est�,
		!! la librer�a generar� una acci�n Salir, por lo que el mensaje de
		!! �xito ser� el de Salir.
		print "No ", (_puedes_) ". No est", (oy_) " en ", (the) x1, ".";

!! TODO
	Give:
		!!	1:	Error, el jugador intenta dar un objeto que no tiene.
		!!	2:	Error, el jugador se da el objeto a s� mismo.
		!!	3:	Aviso, se ha enviado la acci�n Dar al PNJ, pero este no ha
		!!		respondido. En este caso x1 apunta al PNJ y no al objeto
		!!		que le hemos dado.
		!!
		!! [Observar que por defecto el objeto sigue en poder del
		!! jugador. Si queremos que el PNJ lo acepte, hay que programarlo
		!! como parte de su rutina Vida.]
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1:	"No tengo ", (the) x1, ".";
				2:	"No tienes ", (the) x1, ".";
				3:	"No tiene ", (the) x1, ".";
				4:	"No ten�a ", (the) x1, ".";
				5:	"No ten�as ", (the) x1, ".";
				6:	"No ten�a ", (the) x1, ".";
				7:	"No tendr� ", (the) x1, ".";
				8:	"No tendr�s ", (the) x1, ".";
				9:	"No tendr� ", (the) x1, ".";
				}
			2:	switch (_grammatical_inflection) {
				1:	print "Manoseo ", (the) x1;
				2:	print "Manoseas ", (the) x1;
				3:	print "Manosea ", (the) x1;
				4:	print "Manose� ", (the) x1;
				5:	print "Manoseaste ", (the) x1;
				6:	print "Manose� ", (the) x1;
				7:	print "Manosear� ", (the) x1;
				8:	print "Manosear�s ", (the) x1;
				9:	print "Manosear� ", (the) x1;
				} " durante unos momentos, sin conseguir nada.";
			3:	switch (_grammatical_inflection) {
				1,2,3:	print_ret (The) x1, " no parece", (n) x1,
						" interesad", (o) x1, ".";
				4,5,6:	print_ret (The) x1, " no parec�a", (n) x1,
						" interesad", (o) x1, ".";
				7,8,9:	print_ret (The) x1, " no parecer�", (n) x1,
						" interesad", (o) x1, ".";
				}
		}

!! TODO
	Go:
		!!	1:	Error, el jugador est� dentro/subido en un objeto del que
		!!		tiene que salir antes.
		!!	2:	Error, la localidad no tiene salida en esa direcci�n (y tampoco
		!!		tiene la propiedad "cant_go", ya que en este caso se habr�a
		!!		impreso el valor de esa propiedad.
		!!	3:	Error, el jugador ha intentado ir hacia arriba, pero all� hay
		!!		una puerta cerrada.
		!!	4:	Error, el jugador ha intentado ir hacia abajo, pero all� hay
		!!		una puerta cerrada.
		!!	5:	Error, en la direcci�n que ha dicho el jugador hay una
		!!		puerta cerrada.
		!!	6:	Error, en la direcci�n que ha dicho el jugador hay una puerta,
		!!		pero �sta no tiene una propiedad "door_to" (probablemente un
		!!		error de programaci�n del juego).
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1:	print "Tengo que ";
					if (x1 has supporter) print "bajarme ";
					else print "salir ";
				2:	print "Tienes que ";
					if (x1 has supporter) print "bajarte ";
					else print "salir ";
				3:	print "Tiene que ";
					if (x1 has supporter) print "bajarse ";
					else print "salir ";
				4:	print "Ten�a que ";
					if (x1 has supporter) print "bajarme ";
					else print "salir ";
				5:	print "Ten�as que ";
					if (x1 has supporter) print "bajarte ";
					else print "salir ";
				6:	print "Ten�a que ";
					if (x1 has supporter) print "bajarse ";
					else print "salir ";
				7:	print "Tendr� que ";
					if (x1 has supporter) print "bajarme ";
					else print "salir ";
				8:	print "Tendr�s que ";
					if (x1 has supporter) print "bajarte ";
					else print "salir ";
				9:	print "Tendr� que ";
					if (x1 has supporter) print "bajarse ";
					else print "salir ";
				}
				print_ret (del_) x1, " antes.";
			2:	"No ", (_puedes_) " ir por ah�.";
			3:	switch (_grammatical_inflection) {
				1:	"Soy incapaz de trepar por ", (the) x1, ".";
				2:	"Eres incapaz de trepar por ", (the) x1, ".";
				3:	"Es incapaz de trepar por ", (the) x1, ".";
				4:	"Era incapaz de trepar por ", (the) x1, ".";
				5:	"Eras incapaz de trepar por ", (the) x1, ".";
				6:	"Era incapaz de trepar por ", (the) x1, ".";
				7:	"Ser� incapaz de trepar por ", (the) x1, ".";
				8:	"Ser�s incapaz de trepar por ", (the) x1, ".";
				9:	"Ser� incapaz de trepar por ", (the) x1, ".";
				}
			4:	switch (_grammatical_inflection) {
				1:	"Soy incapaz de bajar por ", (the) x1, ".";
				2:	"Eres incapaz de bajar por ", (the) x1, ".";
				3:	"Es incapaz de bajar por ", (the) x1, ".";
				4:	"Era incapaz de bajar por ", (the) x1, ".";
				5:	"Eras incapaz de bajar por ", (the) x1, ".";
				6:	"Era incapaz de bajar por ", (the) x1, ".";
				7:	"Ser� incapaz de bajar por ", (the) x1, ".";
				8:	"Ser�s incapaz de bajar por ", (the) x1, ".";
				9:	"Ser� incpaz de bajar por ", (the) x1, ".";
				}
			5:	"No ", (_puedes_) " pasar a trav�s ", (del_) x1, ".";
			6:	print "No ", (_puedes_) " ir porque ", (the) x1, " no ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "lleva", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "llevaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "llevar�", (n) x1;
				}
				" a ning�n sitio.";
		}

!! TODO
	Insert:
		!!	1:	Error, el objeto no est� en poder del jugador. [Nota, conviene
		!!		mirar en este caso si el objeto es animado o no, para generar
		!!		un mensaje m�s adecuado].
		!!	2:	Error, el jugador intenta meter el objeto en otro que no tiene
		!!		el atributo "container".
		!!	3:	Error, el jugador intenta meter el objeto en un recipiente
		!!		cerrado.
		!!	4:	Error, el objeto es una prenda que el jugador lleva puesta.
		!!		[ESTE MENSAJE NO SE GENERA NUNCA, PARECE UN BUG DE LA LIBRER�A.
		!!		V�ase en su lugar el mensaje 6].
		!!	5:	Error, se intenta poner un objeto dentro de s� mismo.
		!!	6:	Aviso, el objeto es una prenda puesta, la librer�a va a
		!!		quit�rsela de forma autom�tica antes de reintentar Insert.
		!!	7:	Error, no queda sitio en el recipiente (el n�mero de objetos
		!!		que un recipiente puede contener se indica en su propiedad
		!!		"capacity").
		!!	8:	�xito. Mensaje a mostrar para cada objeto metido cuando se
		!!		meten muchos (ej: METE TODO EN LA BOLSA).
		!!	9:	�xito. Mensaje a mostrar cuando se mete un solo objeto dentro
		!!		de otro.
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1:	if (x1 has animate)
						"Antes tendr�a que ", (coge)"rl", (o) x1, " y no s�
						si se dejar�", (n) x1, ".";
					else
						"Necesito tener ", (the) x1, " para poder meter",
						(lo) x1, " donde sea.";
				2:	if (x1 has animate)
						"Antes tendr�as que ", (coge)"rl", (o) x1, " y no sabes
						si se dejar�", (n) x1, ".";
					else
						"Necesitas tener ", (the) x1, " para poder meter",
						(lo) x1, " donde sea.";
				3:	if (x1 has animate)
						"Antes tendr�a que ", (coge)"rl", (o) x1, " y no sabe
						si se dejar�", (n) x1, ".";
					else
						"Necesita tener ", (the) x1, " para poder meter",
						(lo) x1, " donde sea.";
				4:	if (x1 has animate)
						"Antes tendr�a que haber", (lo) x1, " cogido, y no
						s� si ", (the) x1, " se hubiese", (n) x1,
						" dejado.";
					else
						"Hubiese necesitado tener ", (the) x1, " para poder
						meter", (lo) x1, " donde fuese.";
				5:	if (x1 has animate)
						"Antes tendr�as que haber", (lo) x1, " cogido, y no
						sabes si ", (the) x1, " se hubiese", (n) x1,
						" dejado.";
					else
						"Hubieses necesitado tener ", (the) x1, " para poder
						meter", (lo) x1, " donde fuese.";
				6:	if (x1 has animate)
						"Antes tendr�a que haber", (lo) x1, " cogido, y no
						sabe si ", (the) x1, " se hubiese", (n) x1,
						" dejado.";
					else
						"Hubiese necesitado tener ", (the) x1, " para poder
						meter", (lo) x1, " donde fuese.";
				7:	if (x1 has animate)
						"Antes tendr� que haber", (lo) x1, " cogido, y no
						sabr� si ", (the) x1, " se habr�a", (n) x1,
						" dejado.";
					else
					 	"Necesitar� tener ", (the) x1, " para poder
						meter", (lo) x1, " donde sea.";
				8:	if (x1 has animate)
						"Antes tendr�s que haber", (lo) x1, " cogido, y no
						sabr�s si ", (the) x1, " se habr�a", (n) x1,
						" dejado.";
					else
						"Necesitar�s tener ", (the) x1, " para poder
						meter", (lo) x1, " donde sea.";
				9:	if (x1 has animate)
						"Antes tendr� que haber", (lo) x1, " cogido, y no
						sabr� si ", (the) x1, " se habr�a", (n) x1,
						" dejado.";
					else
						"Necesitar� tener ", (the) x1, " para poder
						meter", (lo) x1, " donde sea.";
				}
			2:	switch (_grammatical_inflection) {
				1,2,3:	"No se pueden meter cosas dentro ", (del_) x1, ".";
				4,5,6:	"No se pod�an meter cosas dentro ", (del_) x1, ".";
				7,8,9:	"No se podr�n meter cosas dentro ", (del_) x1, ".";
				}
			3:	switch (_grammatical_inflection) {
					1,2,3:	print (The) x1, " est�", (n) x1;
					4,5,6:	print (The) x1, " estaba", (n) x1;
					7,8,9:	print (The) x1, " estar�", (n) x1;
				}
				" cerrad", (o) x1, ".";
			4:	switch (_grammatical_inflection) {
				1:	"Tengo que quit�rme", (lo) x1, " antes.";
				2:	"Tienes que quit�rte", (lo) x1, " antes.";
				3:	"Tiene que quit�rse", (lo) x1, " antes.";
				4:	"Ten�a que quit�rme", (lo) x1, " antes.";
				5:	"Ten�as que quit�rte", (lo) x1, " antes.";
				6:	"Ten�a que quit�rse", (lo) x1, " antes.";
				7:	"Tendr� que quit�rme", (lo) x1, " antes.";
				8:	"Tendr�s que quit�rte", (lo) x1, " antes.";
				9:	"Tendr� que quit�rse", (lo) x1, " antes.";
				}
			5:	"No ", (_puedes_) " poner un objeto dentro de s� mismo.";
			6:	switch (_grammatical_inflection) {
				1:	"(Primero me ", (lo) x1, " quito.)^";
				2:	"(Primero te ", (lo) x1, " quitas.)^";
				3:	"(Primero se ", (lo) x1, " quita.)^";
				4:	"(Primero me ", (lo) x1, " quit�.)^";
				5:	"(Primero te ", (lo) x1, " quitaste.)^";
				6:	"(Primero se ", (lo) x1, " quit�.)^";
				7:	"(Primero me ", (lo) x1, " quitar�.)^";
				8:	"(Primero te ", (lo) x1, " quitar�s.)^";
				9:	"(Primero se ", (lo) x1, " quitar�.)^";
				}
			7:	switch (_grammatical_inflection) {
				1,2,3:	"No queda sitio en ", (the) x1, ".";
				4,5,6:	"No quedaba sitio en ", (the) x1, ".";
				7,8,9:	"No quedar� sitio en ", (the) x1, ".";
				}
			8:	"Hecho.";
			9:	switch (_grammatical_inflection) {
				1:	print "Meto ";
				2:	print "Metes ";
				3:	print "Mete ";
				4:	print "Met� ";
				5:	print "Metiste ";
				6:	print "Meti� ";
				7:	print "Meter� ";
				8:	print "Meter�s ";
				9:	print "Meter� ";
				}
				print_ret (the) x1, " dentro ", (del_) second, ".";
		}

	Inv:
		!!	1:	Mensaje si el inventario est� vac�o
		!!	2:	Encabezado del inventario, antes de la lista de objetos
		!!		generada por la librer�a
		!!	3 y 4: [6/11]
		switch (n) {
			1:	print "No llev", (as_) " nada.";
			2:	print "LLev", (as_) "";
			3:	print ":^";
			4:	print ".^";
		}

	Jump:
		"Salt", (as_) " en el sitio, sin ning�n resultado.";

!! TODO
	JumpOver, Tie:
		print "No ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			FIRST_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "lograr�";
				else print "lograremos";
			SECOND_PERSON_PRESENT,
			SECOND_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "lograr�s";
				else print "lograr�is";
			THIRD_PERSON_PRESENT,
			THIRD_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "lograr�";
				else print "lograr�n";
			FIRST_PERSON_PAST:
				if (IsSingularNoun(player)) print "hubiese logrado";
				else print "hubi�semos logrado";
			SECOND_PERSON_PAST:
				if (IsSingularNoun(player)) print "hubieses logrado";
				else print "hubieseis logrado";
			THIRD_PERSON_PAST:
				if (IsSingularNoun(player)) print "hubiese logrado";
				else print "hubiesen logrado";
		}
		" nada as�.";

!! TODO
	Kiss:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT:
				if (IsSingularNoun(player))
					"No creo que deba.";
				else "En realidad no deber�amos.";
			SECOND_PERSON_PRESENT:
				if (IsSingularNoun(player))
				 	"En realidad no crees que debas.";
				else "En realidad no deber�ais.";
			THIRD_PERSON_PRESENT:
				if (IsSingularNoun(player))
					"No cree que deba.";
				else "En realidad no deber�an.";
			FIRST_PERSON_PAST:
				if (IsSingularNoun(player)) print "No se me ocurri�";
				else print "No se nos ocurri�";
				" hacer algo as� en aquel momento.";
			SECOND_PERSON_PAST:
				if (IsSingularNoun(player)) print "No se te ocurri�";
				else print "No se os ocurri�";
				" hacer algo as� en aquel momento.";
			THIRD_PERSON_PAST:
				if (IsSingularNoun(player)) print "No se le ocurri�";
				else print "No se les ocurri�";
				" hacer algo as� en aquel momento.";
			FIRST_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "No se me ocurrir�";
				else print "No se nos ocurrir�";
				" hacer algo as� en ese momento.";
			SECOND_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "No se te ocurrir�";
				else print "No se os ocurrir�";
				" hacer algo as� en ese momento.";
			THIRD_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "No se le ocurrir�";
				else print "No se les ocurrir�";
				" hacer algo as� en ese momento.";
		}

	Listen:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "No escuchamos";
				else print "No escucho";
			SECOND_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "No escuch�is";
				else print "No escuchas";
			THIRD_PERSON_PRESENT:
				if (IsPluralNoun(player)) print "No escuchas";
				else print "No escucha";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "No se escuchaba";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "No se escuchar�";
		}
		" nada fuera de lo com�n.";

!! TODO
	ListMiscellany:
		!! Los siguientes mensajes se muestran como aclaraciones cuando se est�
		!! listando el inventario del jugador, o los objetos que hay en una
		!! localidad. Junto a cada mensaje se comenta qu� condiciones deben
		!! darse en ese objeto para que se muestre ese mensaje aclaratorio.
		switch (n) {
			1:	print " (alumbrando)";
			!! El objeto tiene "luz" y la localidad no
			2:	switch (_grammatical_inflection) {
				1,2,3:	print " (que ", (esta) x1, " cerrad", (o) x1, ")";
				4,5,6:	print " (que estaba", (n) x1, " cerrad", (o) x1, ")";
				7,8,9:	print " (que estar�", (n) x1, " cerrad", (o) x1, ")";
				}
			!! El objeto tiene "recipiente" pero no "abierto"
			3:	print " (cerrad", (o) x1, " y alumbrando)";
			!! Casos 2 y 1 juntos
			4:	switch (_grammatical_inflection) {
				1,2,3:	print " (que ", (esta) x1, " vac�", (o) x1, ")";
				4,5,6:	print " (que estaba", (n) x1, " vac�", (o) x1, ")";
				7,8,9:	print " (que estar�", (n) x1, " vac�", (o) x1, ")";
				}
			!! El objeto es un recipiente abierto (o transparente) y no
			!!! tiene nada en su interior
			5:	print " (vac�", (o) x1, " y alumbrando)";
			!! Casos 1 y 4 juntos
			6:	switch (_grammatical_inflection) {
				1,2,3:	print " (que ", (esta) x1, " cerrad", (o) x1,
						" y vac�", (o) x1, ")";
				4,5,6:	print " (que estaba", (n) x1, " cerrad", (o) x1,
						" y vac�", (o) x1, ")";
				7,8,9:	print " (que estar�", (n) x1, " cerrad", (o) x1,
						" y vac�", (o) x1, ")";
				}
			!! El objeto tiene "recipiente", no "abierto", pero s�
			!! "transparente"
			7:	print " (cerrad", (o) x1, ", vac�", (o) x1, " y
				alumbrando)";
			!! Casos 1 y 6 juntos

			!! Los casos siguientes son similares, pero se muestran cuando se
			!! solicita a la rutina EscribirListaDesde la opci�n INFOTOTAL. La
			!! librer�a puede combinar varios de estos mensajes, por eso no
			!! deben llevar el cerrado de par�ntesis al final, que lo a�ade la
			!! propia librer�a. *** NO SE ACONSEJA CAMBIAR ESTOS ***

			8:	print " (alumbrando y que llev", (as_) " puest", (o) x1;
			!! El objeto tiene "luz" y "puesto"
			9:	print " (alumbrando";
			!! El objeto tiene "luz" pero no "puesto"
			10:	print " (que llev", (as_) " puest", (o) x1;
			!! El objeto tiene "puesto" pero no "luz"
			11:	switch (_grammatical_inflection) {
				1,2,3:	print " (que est�", (n) x1, " ";
				4,5,6:	print " (que estaba", (n) x1;
				7,8,9:	print " (que estar�", (n) x1;
				}
			!! Mensaje introductorio para decir "que est�
			!! abierto/cerrado/vacio"...
			12:	print "abiert", (o) x1;
			!! Objeto tiene "recipiente", "abrible" y "abierto" (y cosas dentro)
			13:	print "abiert", (o) x1, ", pero vac�", (o) x1;
			!! Objeto tiene "recipiente", "abrible" y "abierto (pero vacio)
			14:	print "cerrad", (o) x1;
			!! Objeto tiene "recipiente", "abrible" y no "abierto"
			15: print "cerrad", (o) x1, " con llave";
			!! Objeto tiene "recipiente", "abrible" y "cerrojoechado" o
			!! "cerrojo"
			16:	print " vac�", (o) x1;
			!! Objeto tiene "recipiente", no "abrible" y "transparente"
			17:	switch (_grammatical_inflection) {
				1,2,3:	print " (que est�", (n) x1, " vac�", (o) x1, ")";
				4,5,6:	print " (que estaba", (n) x1, " vac�", (o) x1, ")";
				7,8,9:	print " (que estar�", (n) x1, " vac�", (o) x1, ")";
				}
			!! Como el caso anterior, pero mensaje m�s "largo" (que se activa
			!! si EscribirListaDesde es llamada sin el modo BREVE_BIT)
			18:	switch (_grammatical_inflection) {
				1,2,3:	print " que contiene", (n) x1, " ";
				4,5,6:	print " que conten�a", (n) x1, " ";
				7,8,9:	print " que contendr�", (n) x1, " ";
			}
			!! encabezado a la lista de lo que hay dentro del objeto
			19: print " (sobre ", (el_) x1;
			!! Si el objeto tiene "soporte", la librer�a va a listar sus
			!! contenidos. Este es el encabezado de la lista
			20: print ", encima ", (del_) x1;
			!! Como e l9, pero en otra modalidad (que se activa si
			!! EscribirListaDesde es llamada sin el modo BREVE_BIT)
			21: print " (en ", (el_) x1;
			!! Si el contenido tiene "recipiente" y puede verse su interior
			!! y hay cosas, la librer�a va a mostrar sus contenidos. Este
			!! es el encabezado de la lista
			22: print ", dentro ", (del_) x1;
			!! Como el 21, pero en otra modalidad (que se activa si
			!! EscribirListaDesde es llamada sin el modo BREVE_BIT)
		}

 	LMode1:
	    !! La acci�n LMode1 se genera ante el comando BREVE (o NORMAL). La
	    !! librer�a imprime la constante Historia y a continuaci�n este
	    !! mensaje.
	    " est� ahora en su modo normal ~breve~, que da s�lo descripciones
	    largas de los lugares la primera vez que son visitadas, y
	    descripciones cortas en otro caso.";

	LMode2:
    	!! La acci�n LMode2 se genera ante el comando LARGO. La librer�a
		!! imprime la constante Historia y a continuaci�n este mensaje.
		" est� ahora en su modo ~largo~, que siempre da descripciones
    	largas de los lugares (incluso si ya hab�as estado antes).";

	LMode3:
    	!! La acci�n LMode3 se genera ante el comando SUPERBREVE. La librer�a
		!! imprime la constante Historia y a continuaci�n este mensaje.
		" est� ahora en su modo ~superbreve~, que siempre da descripciones
    	cortas de los lugares (incluso si nunca hab�as estado antes).";

!! TODO
	Lock:
		!! Lock se genera con CIERRA <objeto> CON <objeto2>, o
		!! tambi�n ante ECHA CERROJO A <objeto> (sin especificar un
		!! segundo objeto en este caso).
		!!
		!!	1:	Error, el objeto al que se intenta echar el cerrojo no tiene la
		!!		propiedad "lockable".
		!!	2:	Error, el objeto al que se intenta echar el cerrojo tiene la
		!!		propiedad "lockable", pero ya tiene tambi�n "locked".
		!!	3:	Error, el objeto tiene las propiedades "lockable" y "open". No
		!!		se le puede echar el cerrojo hasta que no se cierre.
		!!	4:	Error, el <objeto2> especificado no coincide con el que el
		!!		objeto indica en su propiedad "with_key".
		!!	5:	�xito, se echa el cerrojo al objeto (con el <objeto2> si �ste
		!!		es especificado y se puede encontrar en la variable "second").
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1,2,3:	"No parece", (n) x1, " tener ning�n tipo de cerrojo.";
				4,5,6:	"No parec�a", (n) x1," tener ning�n tipo de cerrojo.";
				7,8,9:	"No parecer�", (n) x1, " tener ning�n tipo de cerrojo.";
				}
			2:	if (x1 provides with_key) {
					switch (_grammatical_inflection) {
						1,2,3:	print (The) x1, " ya estaba", (n) x1;
						4,5,6:	print (The) x1, " ya estaba", (n) x1;
						7,8,9:	print (The) x1, " ya estar�", (n) x1;
					}
					" cerrad", (o) x1, " con llave.";
				}
				else {
					switch (_grammatical_inflection) {
					1,2,3:	print (The) x1, " ya tiene", (n) x1;
					4,5,6:	print (The) x1, " ya ten�a", (n) x1;
					7,8,9:	print (The) x1, " ya tendr�", (n) x1;
					}
					" echado el cerrojo.";
				}
			3:	switch (_grammatical_inflection) {
				1:	"Primero tengo que cerrar ", (the) x1, ".";
				2:	"Primero tienes que cerrar ", (the) x1, ".";
				3:	"Primero tiene que cerrar ", (the) x1, ".";
				4:	"Primero ten�a que cerrar ", (the) x1, ".";
				5:	"Primero ten�as que cerrar ", (the) x1, ".";
				6:	"Primero ten�a que cerrar ", (the) x1, ".";
				7:	"Primero tendr� que cerrar ", (the) x1, ".";
				8:	"Primero tendr�s que cerrar ", (the) x1, ".";
				9:	"Primero tendr� que cerrar ", (the) x1, ".";
				}
			4:	if (second) switch (_grammatical_inflection) {
				1,2,3:	"No parece", (n) x1, " encajar en la cerradura.";
				4,5,6:	"No parec�a", (n) x1, " encajar en la cerradura.";
				7,8,9:	"No parecer�", (n) x1, " encajar en la cerradura.";
				}
				switch (_grammatical_inflection) {
				1:	print "Necesito";
				2:	print "Necesitas";
				3:	print "Necesita";
				4:	print "Necesitaba";
				5:	print "Necesitabas";
				6:	print "Necesitaba";
				7:	print "Necesitar�";
				8:	print "Necesitar�s";
				9:	print "Necesitar�";
				}
				" alg�n tipo de llave.";
			5:	switch (_grammatical_inflection) {
				1:	if (second) "Cierro ", (the) x1, " con ", (the) second, ".";
					else "Echo el cerrojo ", (al_) x1, ".";
				2:	if (second) "Cierras ", (the) x1, " con ", (the) second,".";
					else "Echas el cerrojo ", (al_) x1, ".";
				3:	if (second) "Cierra ", (the) x1, " con ", (the) second, ".";
					else "Echa el cerrojo ", (al_) x1, ".";
				4:	if (second) "Cerr� ", (the) x1, " con ", (the) second, ".";
					else "Ech� el cerrojo ", (al_) x1, ".";
				5:	if (second) "Cerraste ", (the) x1," con ", (the) second,".";
					else "Echaste el cerrojo ", (al_) x1, ".";
				6:	if (second) "Cerr� ", (the) x1, " con ", (the) second, ".";
					else "Ech� el cerrojo ", (al_) x1, ".";
				7:	if (second) "Cerrar� ", (the) x1, " con ", (the) second,".";
					else "Echar� el cerrojo ", (al_) x1, ".";
				8:	if (second) "Cerrar�s ", (the) x1," con ", (the) second,".";
					else "Echar�s el cerrojo ", (al_) x1, ".";
				9:	if (second) "Cerrar� ", (the) x1, " con ", (the) second,".";
					else "Echar� el cerrojo ", (al_) x1, ".";
				}
		}

!! TODO
	Look:
		!! La acci�n Look se genera cuando el jugador pone MIRAR, pero tambi�n
		!! de forma autom�tica al entrar en una localidad nueva, o cuando el
		!! jugador sale/se baja de un objeto en el que estaba.
		!!
		!! Algunos de los mensajes que se definen aqu� aparecen en el "t�tulo"
		!! de la localidad (lo que aparece en negrita antes de la descripci�n
		!! de la localidad).
		!!
		!!	1:	Aclaraci�n a a�adir tras el t�tulo si el jugador est� subido
		!!		en un objeto.
		!!	2:	Aclaraci�n a a�adir tras el t�tulo si el jugador est� dentro
		!!		de un objeto.
		!!	3:	Aclaraci�n a a�adir tras el t�tulo si el jugador ha sido
		!!		transformado en otro personaje mediante una llamada a
		!!		ChangePlayer(nuevo, 1); (sin el 1, la librer�a no intentar�
		!!		mostrar este mensaje).
		!!	4:	Una vez que la librer�a ha mostrado la descripci�n de la
		!!		localidad, si el jugador estaba encima de un supporter, la
		!!		librer�a generar� este mensaje 4 para mostrar qu� m�s cosas
		!!		hay sobre el supporter.
		!!	Restante: 5,6 [6/11] antes 'default'
		!!		Son usados por la librer�a para listar los objetos "simples"
		!!		que hay en la localidad. Son objetos "simples" los que no
		!!		dan su propia auto-descrcipcion a trav�s de la propiedad
		!!		"describe" o "initial".
		!!	7:	Respuesta estandar para MirarHacia [6/11]
		switch (n) {
			1:	print ", ";
				!! XXX: Se puede usar un mensaje de aclaraci�n completamente
				!! personalizado definiendo la propiedad "clarification" en un
				!! objeto ("clarification" tiene que devolver un string o una
				!! rutina encargada de imprimir un string). Ej: SALA DE ESTAR,
				!! sentado en el sof�
				if ( x1 provides clarification ) {
					if (x1.clarification ofclass string)
						print (string) x1.clarification;
					else if (x1.clarification ofclass routine)
						indirect(x1.clarification);
				}
				else print "sobre ", (the) x1;
			2:	print ", ";
				!! XXX: Ver comportamiento de Look con n == 1
				if ( x1 provides clarification ) {
					if (x1.clarification ofclass string)
						print (string) x1.clarification;
					else if (x1.clarification ofclass routine)
						indirect( x1.clarification);
				}
				else print ", en ", (the) x1;
			3:	print " (como ", (object) x1 , ")";
			4:	print "^Sobre ", (the) x1;
				WriteListFrom(child(x1),
						ENGLISH_BIT + RECURSE_BIT + PARTINV_BIT
						+ TERSE_BIT + ISARE_BIT + CONCEAL_BIT);
				".";
			5,	!! XXX: Si la localidad actual tiene definida la propiedad
			6:	!! "inhibit_object_list" y est� establecida como verdadero, se
				!! evita que se imprima el listado autom�tico de objetos
				!! simples junto con la descripci�n de la localidad
				if (real_location provides inhibit_object_list)
					if (real_location.inhibit_object_list)
						return true;

				new_line;
				if (x1~=location) {
					if (x1 has supporter) print "Sobre "; else print "En ";
					print (the) x1, " ", (_puedes_) " ver ";
				}
				else switch (_grammatical_inflection) {
				1:	print "Puedo ver ";
				2:	print "Puedes ver ";
				3:	print "Puede ver ";
				4:	print "Pod�a ver ";
				5:	print "Pod�as ver ";
				6:	print "Pod�a ver ";
				7:	print "Podr� ver ";
				8:	print "Podr�s ver ";
				9:	print "Podr� ver ";
				}
				if (n==5) print "tambi�n ";
				WriteListFrom(child(x1),
					ENGLISH_BIT + WORKFLAG_BIT + RECURSE_BIT
					+ PARTINV_BIT + TERSE_BIT + CONCEAL_BIT);
				".";
			7:	switch (_grammatical_inflection) {
				1:	print "No observo";
				2:	print "No observas";
				3:	print "No observa";
				4:	print "No observ�";
				5:	print "No observaste";
				6:	print "No observ�";
				7:	print "No observar�";
				8:	print "No observar�s";
				9:	print "No observar�";
				}
				" nada digno de menci�n al mirar hacia ", (the) x1, ".";
			8:	if (x1 has supporter) print " (sobre "; else print " (en ";
				print (the) x1, ")";
		}

!! TODO
	LookUnder:
		!!	1:	Error, estamos a oscuras.
		!!	2:	�xito, mensaje por defecto.
		switch (n) {
			1:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "Est�";
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "Estaba";
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "Estar�";
				}
				" demasiado oscuro como para ver algo.";
			2:	print "No ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "veo";
						else print "vemos";
					SECOND_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "ves";
						else print "veis";
					THIRD_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "ve";
						else print "ven";
					FIRST_PERSON_PAST:
						if (IsSingularNoun(player)) print "vi";
						else print "vimos";
					SECOND_PERSON_PAST:
						if (IsSingularNoun(player)) print "viste";
						else print "visteis";
					THIRD_PERSON_PAST:
						if (IsSingularNoun(player)) print "vio";
						else print "vieron";
					FIRST_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "ver�";
						else print "veremos";
					SECOND_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "ver�s";
						else print "ver�is";
					THIRD_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "ver�";
						else print "ver�n";
				}
				" nada inusual.";
		}

	Mild:
		!! Respuesta si se usa como primera palabra alg�n insulto suave.
		"Bastante.";

!! TODO
	Miscellany:
		!! Esta es una falsa acci�n, que se usa simplemente para agrupar aqu�
		!! todos los mensajes de error del parser, los mensajes ante algunos
		!! metacommandos, o algnouns mensajes de librer�a no relacionados con
		!! acci�n alguna. La asignaci�n de n�meros a mensajes es bastante
		!! caprichosa.
		switch (n) {
			1:
				!! El jugador ha especificado objetos multiples, pero el parser
				!! tiene una lista que no admite m�s de 16, de modo que los
				!! restantes objetos no ser�n procesados.
				"(S�lo se consideran los diecis�is primeros objetos).";
			2:
				!! El jugador ha usado objetos m�ltiples, pero por alguna raz�n
				!! la lista del parser est� vac�a.
				"No se pudo determinar a qu� objetos te has referido.";
			3:
				!! Mensaje de fin del relato. Has muerto.
				! TextoLlamativo(" Has muerto ");
				switch (_grammatical_inflection) {
					1:	print " He muerto ";
					2:	print " Has muerto ";
					3:	print " Ha muerto ";
					4:	print " Hab�a muerto ";
					5:	print " Hab�as muerto ";
					6:	print " Hab�a muerto ";
					7:	print " Habr� muerto ";
					8:	print " Habr�s muerto ";
					9:	print " Habr� muerto ";
				}
!! TODO - probar
			4:
				!! Mensaje de fin del relato. Victoria.
				! TextoLlamativo(" Has ganado ");
				switch (_grammatical_inflection) {
					1:	print " He ganado ";
					2:	print " Has ganado ";
					3:	print " Ha ganado ";
					4:	print " Hab�a ganado ";
					5:	print " Hab�as ganado ";
					6:	print " Hab�a ganado ";
					7:	print " Habr� ganado ";
					8:	print " Habr�s ganado ";
					9:	print " Habr� ganado ";
				}
!! TODO - mensaje del parser
			5:
				!! Mensaje a mostrar tras el fin del juego, para pedir al
				!! jugador si quiere reniciar, recuperar, anular, puntuaci�n,
				!! curiosidades o terminar.
				print "^�Quieres REINICIAR, RECUPERAR un juego guardado";
				#IFDEF DEATH_MENTION_UNDO;
					print ", ANULAR tu �ltimo movimiento";
				#ENDIF;
				! #IFNDEF NO_PUNTUACION;
					if (TASKS_PROVIDED==0)
						print ", ver la PUNTUACI�N de este juego";
				! #ENDIF; ! NO_PUNTUACION
				if (deadflag==2 && AMUSING_PROVIDED==0)
					print ", ver algunas CURIOSIDADES";
				" o TERMINAR?";
			6:
				!! Error si el int�rprete no tiene "undo"
				!! -- "[Tu int�rprete no puede ~deshacer~ acciones,
				!! �lo siento!]";
				"Tu int�rprete no puede ~DESHACER~ acciones.";
			#Ifdef TARGET_ZCODE; ![6/11]
			!! Otro error si el int�rprete no tiene "undo", pero no hab�a
			!! sido detectado correctamente.
			7:
				"~DESHACER~ fall�. (No todos los int�rpretes lo implementan.)";
			#Ifnot; ! TARGET_GLULX
			7:
				"No puedes ~DESHACER~ m�s.";
			#Endif; ! TARGET_
			8:
				!! Si el jugador no responde correctamente a la pregunta del
				!! mensaje [Miscellany,5]
				"Por favor, introduce una de las respuestas anteriores.";
!! TODO - cambiar mensaje
			9:
				!! Mensaje cuando se detecta, al final del turno, que ya no hay
				!! una fuente de luz en la localidad actual.
				switch (_grammatical_inflection) {
					1:	"^�Me he quedado a oscuras!";
					2:	"^�Te has quedado a oscuras!";
					3:	"^�Se ha quedado a oscuras!";
					4:	"^�Me hab�a quedado a oscuras!";
					5:	"^�Te hab�as quedado a oscuras!";
					6:	"^�Se hab�a quedado a oscuras!";
					7:	"^�Me habr� quedado a oscuras!";
					8:	"^�Te habr�s quedado a oscuras!";
					9:	"^�Se habr� quedado a oscuras!";
				}
			10:
				!! Mensaje cuando el jugador introduce una linea en blanco.
				"No has introducido ninguna instrucci�n.";
			11:
				!! Si el jugador intenta "undo" al principio del juego
				!! -- "[No puedes ~deshacer~ lo que no has hecho.]";
				"No se puede ~DESHACER~ algo que no has hecho.";
			12:
				!! Si el jugador pone "undo" dos veces.
				!! -- "[No puedes ~deshacer~ dos veces seguidas. �Lo siento!]";
				"No se puede ~DESHACER~ dos veces seguidas.";
			13:
				!! �xito en el "undo".
				"Retrocediendo al turno anterior.";
			14:
				!! Si el jugador pone EEPA (verbo para corregir), pero el
				!! parser no recordaba ninguna palabra mal. Ejmplo de uso del
				!! comando EEPA:
				!!		> SACA MAZANA VERDE DE LA CESTA
				!!		No vqeo eso por aqu�.
				!!		> EEPA MANZANA
				!!		Sacas la manzana verde de la cesta de mimbre.
				!! -- "Lo siento, eso no puede corregirse.";
				"Eso no puede corregirse.";
			15:
				!! Se usa EEPA sin especificar la palabra corregida.
				"Has utilizado ~EEPA~ sin especificar qu� palabra deseabas
				corregir.";
			16:
				!! Si el jugador pone EEPA seguido de dos o m�s palabras.
				"~EEPA~ s�lo puede corregir una palabra.";
			17:
				!! Descripci�n del objeto Oscuridad.
				switch (_grammatical_inflection) {
				1,2,3:	"Est� muy oscuro como para poder ver algo.";
				4,5,6:	"Estaba muy oscuro como para poder ver algo.";
				7,8,9:	"Estar� muy oscuro como para poder ver algo.";
				}
			18:
				!! Nombre corto del objeto jugador.
				switch (_grammatical_inflection) {
					1,4,7:	print " mi mism", (o) player;
					2,5,8:	print " ti mism", (o) player;
					3,6,9:	print " si mism", (o) player;
				}
			19:
				!! Descripci�n del objeto jugador.
				!! -- "Tan buen aspecto como siempre.";
				<<Inv>>;
			20:
				!! Cuando el jugador pone PNJ, REPITE para que el PNJ haga otra
				!! vez la �ltima acci�n.
				"Para repetir un comando como ~PERSONAJE, SALTA~, escribe
				~REPITE~, en lugar de ~PERSONAJE, REPITE~.";
			21:
				!! Cuando el jugador pone REPITE como primer commando del juego.
				"No hay comando que repetir.";
			22:
				!! El jugador ha comenzado la frase con una coma.
				"No se puede empezar una frase con una coma.";
			23:
				!! Cuando el jugador pone, por ejemplo; PEPE, COGE HACHA, pero
				!! no hay un objeto que responda al name PEPE.
				"Parece que has tratado de hablar con alguien, pero no se pudo
				identificar con qui�n.";
			24:
				!! Si el jugador intenta hablar con un objeto que no es
				!! "animate" ni "talkable" ("talkable" debe ponerse a objetos
				!! inanimates con los que se podr�a hablar, como un micr�fono).
				"No puedes hablar con ", (the) x1, ".";
			25:	!! Hay palabras no comprendidas entre el nombre de un PNJ y la
				!! coma, ej: PEPE ZAFDSRGG, SALTA.
				!! -- "Para hablar con alguien intenta ~alguien, hola~ o algo
				!! -- as�.";
				"Para iniciar una conversaci�n, intenta �rdenes del tipo:
				PERSONAJE, HOLA.";
			26:
				!! La gram�tica especifica que una acci�n debe efectuarse sobre
				!! un objeto en poder del jugador (token 'held'), pero el
				!! jugador lo ha intentado sobre un objeto que no tiene, aunque
				!! est� a su alcance. El parser intentar� autom�ticamente coger
				!! ese objeto antes de efectuar la acci�n. En este mensaje se
				!! avisa al jugador de esta intenci�n.
				switch (_grammatical_inflection) {
				1:	"(Primero trato de ", (coge)"r ", (the) x1, ".)";
				2:	"(Primero tratas de ", (coge)"r ", (the) x1, ".)";
				3:	"(Primero trata de ", (coge)"r ", (the) x1, ".)";
				4:	"(Primero trat� de ", (coge)"r ", (the) x1, ".)";
				5:	"(Primero trataste de ", (coge)"r ", (the) x1, ".)";
				6:	"(Primero trat� de ", (coge)"r ", (the) x1, ".)";
				7:	"(Primero tratar� de ", (coge)"r ", (the) x1, ".)";
				8:	"(Primero tratar�s de ", (coge)"r ", (the) x1, ".)";
				9:	"(Primero tratar� de ", (coge)"r ", (the) x1, ".)";
				}

			!! ERRORES DE PARSING: Estos errores son generados por la librer�a,
			!! a menos que el programador proporcione su propia funci�n
			!! ParserError para manejo de errores.

			! 27:	!! manejado por ParserError.
			! 28:	!! manejado por ParserError.
			! 29:	!! manejado por ParserError.
			! 30:	!! manejado por ParserError.
			! 31:	!! manejado por ParserError.
			! 32:	!! manejado por ParserError.
			! 33:	!! manejado por ParserError.
			! 34:	!! manejado por ParserError.
			! 35:	!! manejado por ParserError.
			! 36:	!! manejado por ParserError.
			! 37:	!! manejado por ParserError.
			! 38:	!! manejado por ParserError.
			! 39:	!! manejado por ParserError.
			! 40:	!! manejado por ParserError.
			! 41:	!! manejado por ParserError.
			! 42:	!! manejado por ParserError.
			! 43:	!! manejado por ParserError.

!! TODO - cambiar mensaje
			44:
				!! El jugador ha intentado objetos m�ltiples usando TODO
				!! pero el parser no ha encontrado ninguno. Por ejemplo, COGE
				!! TODO o DEJA TODO si no hay nada cerca o en el inventario.
				!! Modificado en [020621] para dar un mensaje m�s coherente
				!! si el jugador tiene alg�n objeto en su inventario.
				if (action_to_be == ##Drop) {
					print "�Pero si no llevas nada";
					if (children (player)) " de eso!";
					else "!";
				}
				switch (_grammatical_inflection) {
				1,2,3:	print "No hay nada para ";
				4,5,6:	print "No hab�a nada para ";
				7,8,9:	print "No habr� nada para ";
				}
				LanguageVerb(verb_word);
				".";
!! TODO - mensaje del parser
			45:
				!! El jugador ha nombrado un PNJ ambiguo (hay m�s de noun con
				!! el mismo name cerca). El parser le pide aclaraci�n. Este
				!! mensaje es la primera parte de la pregunta, el resto lo pone
				!! el parser (que es la lista de PNJs entre los que duda).
				!! Debemos poner a 1 la variable PreguntaCualExactamente cuando
				!! se generan este tipo de preguntas aclaratorias.
				print "�Qui�n concretamente, ";
				PreguntaCualExactamente=1;
				ImprimirListaDudosos("o");
				!print "?^";
!! TODO - mensaje del parser
			46:
				!! El jugador ha nombrado un objeto ambiguo (hay m�s de objeto
				!! con el mismo nombre cerca). El parser le pide aclaraci�n.
				!! Este mensaje es la primera parte de la pregunta, el resto lo
				!! pone el parser (que es la lista de objetos entre los que
				!! duda). Debemos poner a 1 la variable PreguntaCualExactamente
				!! cuando se generan este tipo de preguntas aclaratorias.
				print "�Cu�l concretamente, ";
				PreguntaCualExactamente=1;
				ImprimirListaDudosos("o");
				!print "?^";
!! TODO - mensaje del parser
			47:
				!! El jugador ha respondido "TODOS" o "AMBOS" a una pregunta
				!! aclaratoria como la anterior, pero el verbo no admite
				!! objetos m�ltiples.
				print "Desafortunadamente s�lo puedes referirte a un objeto
				en este caso. �Cu�l exactamente?^";
				PreguntaCualExactamente=1;
!! TODO - Tienes que indicar a quien tiene que/quieres <comando>...
			48:
				!! El jugador ha escrito una frase u orden a PSI incompleta,
				!! como BESA (verbo aplicado sobre PSIs normalmente). El parser
				!! le pregunta para que complete la frase.
				PreguntaCualExactamente = 1;
				if (IniciarPregunta() ==0 ) print "A qui�n";
				if (actor ~= player) print " tiene que ";
				else print " quieres ";
				IdiomaImprimirComando();
				if (actor~=player) print " ", (the) actor;
				print "?";
				new_line;
!! TODO - Tienes que indicar qu� tiene que/quieres <comando>...
			49:
				!! El jugador ha escrito una frase u orden incompleta, como
				!! COGE (verbo aplicado sobre objetos normalmente). El parser
				!! le pregunta para que complete la frase.
				PreguntaCualExactamente = 1;
				if (IniciarPregunta() ==0 ) print "Qu�";
				if (actor ~= player) print " tiene que ";
				else print " quieres ";
				IdiomaImprimirComando();
				if (actor~=player) print " ", (the) actor;
				print "?";
				new_line;
			!#IFNDEF NO_PUNTUACION;
!! TODO - mensaje del parser
			50:
				!! El jugador acaba de realizar una acci�n que punt�a (la
				!! librer�a ha detectado que la variable score ha cambiado de
				!! valor). Se informa de ello al player. El par�metro x1
				!! contiene el incremento (o decremento) en la puntuaci�n.
				print "Tu puntuaci�n ha ";
				if (x1 > 0) print "aumentado";
				else {
					x1 = -x1;
					print "disminuido";
				}
				print " en ", (number) x1, " punto";
				if (x1 > 1) print "s";
			!#ENDIF; ! NO_PUNTUACION
			51:
				!! El jugador ha intentado una acci�n con objeto m�ltiple
				!! (como COGE TODO). Esta acci�n es convertida por el parser en
				!! una serie de actiones COGE OBJETO1, COGE OBJETO2, etc... Si
				!! en la ejecuci�n de alguna de estas actiones encuentra que la
				!! localidad del player ha cambiado, debe abortar el proceso.
				!! Este mensaje informa de ello al jugador.
				!!	-- (Ya que ha ocurrido algo dram�tico, se ha recortado la
				!!		lista de objetos sobre los que actuabas)
				"(Se ha producido un evento inesperado que ha obligado a
				recortar la lista de objetos sobre los que actuabas).";
			52:
				!! En los men�s, se espera a que el player escriba un n�mero
				!! para mostrar una entrada del men�. Si pulsa un numero
				!! incorrecto, se saca este mensaje. El par�metro x1 contiene
				!! el n�mero m�s alto v�lido.
				new_line;
				print "Escribe un n�mero del 1 al ", x1, ", 0 para volver a
				mostrarlo, o pulsa Intro.";
				new_line;
				return true;
			53:
				!! Mensaje que muestra el sistema de men�s cuando espera una
				!! tecla.
				new_line;
				"Por favor, pulsa ESPACIO.";
			54:
				return true; ! FIXME
!				print_ret (parser) "Comentario guardado.";
			55:
				"Comentario NO guardado.";
			56:
				print ".^";
			57:
				print "?^";
		}

!! TODO
	No:
		!! Cuando el jugador pone NO, a secas, se genera esta acci�n. Est�
		!! pensada por si el relato suelta una frase del estilo de "�Pero t�
		!! eres tonto?" y el jugador responde NO. De todas formas, hay un
		!! problema, y es que NO es normalmente la acci�n Ir al noroeste. Si
		!! queremos que NO sea provisionalmente la acci�n No, entonces se debe
		!! poner a 1 la variable PreguntaSiNo antes de escribir el texto
		!! "�Pero t� eres tonto?". En ese caso, el parser interpretar� "NO"
		!! como la acci�n No, pero �nicamente durante el siguiente turno.
		"S�lo era una pregunta ret�rica.";

!! TODO
	NotifyOff:
		"Notificaci�n de puntuaci�n desactivada.";

!! TODO
!!TODO - Mensaje del parser (parser_style)
	Objects:
		!! Ante el verbo "OBJETOS" se genera esta acci�n, que muestra una
		!! lista de todos los objetos que el jugador ha manipulado a lo largo
		!! del juego, junto con una indicaci�n de qu� hizo con ellos.
		!!
		!!	1:	Texto introductorio a la lista.
		!!	2:	Si no ha manejado a�n ninguno.
		!!	3:	Indicaci�n de que lo lleva puesto.
		!!	4:	Indicaci�n de que lo lleva en su inventario.
		!!	5:	Indicaci�n de qui�n lo tiene ahora (si lo tiene un PNJ).
		!!	6:	Indicaci�n de d�nde est� el objeto (si est� en una localidad).
		!!	7:	Indicaci�n de d�nde est� el objeto (si est� en un "entrable").
		!!	8:	Indicaci�n de d�nde est� el objeto (si est� en un recipiente).
		!!	9:	Indicaci�n de d�nde est� el objeto (si est� en un soporte).
		!!	10:	Indicaci�n de que se ha perdido (no est� en ninguno de los
		!!		casos anteriores).
		switch (n) {
			1:	"Objetos que has manejado:^";
			2:	"Ninguno.";
!! TODO - usar x1
			3:	print "   (puesto)";
			4:	print "   (contigo)";
!! TODO - usar x1
			5:	print "   (dejado con alguien)";
			6:	print "   (ahora en ", (name) x1, ")";
			7:	print "   (ahora en ", (the) x1, ")";
			8:	print "   (ahora dentro ", (del_) x1, ")";
			9:	print "   (ahora en ", (the) x1, ")";
!! TODO - usar x1
			10:	print "   (perdido)";
		}

!! TODO
	Open:
		!!	1:	Error, el objeto no tiene el atributo "openable".
		!!	2:	Error, el objeto es abrible, pero tiene "locked".
		!!	3:	Error, el objeto es abrible, pero ya tiene el atributo "open".
		!!	4:	�xito, el objeto se abre, y adem�s era recipiente. Se muestra
		!!		entoces la lista de objetos que hab�a en su interior (si habia
		!!		algo).
		!!	5:	�xito, el objeto se abre (pero no tiene nada en su
		!!		interior, o no era recipiente).
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1,2,3:	"No es algo que pueda abrirse.";
				4,5,6:	"No era algo que se pudiese abrir.";
				7,8,9:	"No ser� algo que pueda abrirse.";
				}
			2:	switch (_grammatical_inflection) {
				1,2,3:	"Est�", (n) x1, " cerrad", (o) x1, " con llave.";
				4,5,6:	"Estaba", (n) x1, " cerrad", (o) x1, " con llave.";
				7,8,9:	"Estar�", (n) x1, " cerrad", (o) x1, " con llave.";
				}
			3:	switch (_grammatical_inflection) {
				1,2,3:	"Ya estaba", (n) x1, " abiert", (o) x1, ".";
				4,5,6:	"Ya estaba", (n) x1, " abiert", (o) x1, ".";
				7,8,9:	"Ya estar�", (n) x1, " abiert", (o) x1, ".";
				}
			4:	switch (_grammatical_inflection) {
					1: print "Abro "; 	2: print "Abres ";	3: print "Abre ";
					4: print "Abr� ";	5: print "Abriste "; 6: print "Abri� ";
					7: print "Abrir� ";	8: print "Abrir�s "; 9: print "Abrir� ";
				}
				print (the) x1, ", descubriendo ";
				if (WriteListFrom(child(x1),
					ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT) == 0) {
					switch (_grammatical_inflection) {
					1,2,3:	"que est�", (n) x1, " vac�", (o) x1, ".";
					4,5,6:	"que estaba", (n) x1, " vac�", (o) x1, ".";
					7,8,9:	"que estar�", (n) x1, " vac�", (o) x1, ".";
					}
				}
				".";
			5:	switch (_grammatical_inflection) {
					1: print "Abro "; 	2: print "Abres ";	3: print "Abre ";
					4: print "Abr� ";	5: print "Abriste "; 6: print "Abri� ";
					7: print "Abrir� ";	8: print "Abrir�s "; 9: print "Abrir� ";
				}
				print_ret (the) x1, ".";
		}

!!	Order:	see Answer.
!!		switch (GRAMMATICAL_INFLEXION) {
!!		1,2,3:	print_ret (The) x1," tiene", (n) x1," mejores cosas que hacer.";
!!		4,5,6:	print_ret (The) x1," ten�a", (n) x1," mejores cosas que hacer.";
!!		}

	Places:
		!! El verbo "LUGARES" muestra un listado de los lugares que el jugador
		!! ha visitado. Aqu� debemos escribir el texto introductorio a esa
		!! lista.
		switch (n) {
			1:  print "Has visitado: ";
			2:  print ".^";
		}

	Pray:
		print "La fe tal vez ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				print "pueda";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "pudiese";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "podr�";
		}
		" resultar �til en una ocasi�n diferente.";

	Prompt:
		!! El prompt aparece justo antes de pedir una nueva l�nea al jugador.
		!! Puede definirse para que sea una frase, o se genere una frase
		!! aleatoria en cada turno, por ejemplo.
		new_line;
		print "> ";

!! TODO
	Pronouns:
		!! Esta acci�n (generada por el verbo PRONOMBRES) muestra una lista
		!! de qu� significa en ese momento para el parser cada pronombre:
		!! -lo, -la, -los, -las...
		!!
		!!	1:	Texto introductorio.
		!!	2:	La palabra "es".
		!!	3:	Texto a mostrar si el pronombre no est� definido.
		!!	4:	Si el juego no define pronombres.
		!!	5:	[6/11].
		switch (n) {
			1:	print "En este momento, ";
			2:	print "es ";
			3:	print "no est� definido";
			4:	print "el juego no conoce ning�n pronombre.";
				new_line;
				return true;
			5:	print ".";
				new_line;
				return true;
		}

!! TODO
	Pull, Push, Turn:
		!! Las acciones Pull, Push y Turn generan todas ellas los
		!! mismos mensajes, pero pueden darse 4 casos:
		!!	1:	El objeto tiene el atributo 'static'.
		!!	2:	El objeto tiene el atributo 'scenery'.
		!!	3:	El objeto no es 'static' ni 'scenery'.
		!!	4:	El objeto es un ser animado.
		!! [Nota, si el objeto tiene ambos 'estatico' y 'escenario' se
		!! est� tambi�n en el caso 1.]
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1,2,3:	print "Est�", (n) x1;
				4,5,6:	print "Estaba", (n) x1;
				7,8,9:	print "Estar�", (n) x1;
				}
				" firmemente sujet", (o) x1, ".";
			2:	switch (_grammatical_inflection) {
				1:	"No soy capaz.";
				2:	"No eres capaz.";
				3:	"No es capaz.";
				4:	"No fui capaz.";
				5:	"No fuiste capaz.";
				6:	"No fue capaz.";
				7:	"No ser� capaz.";
				8:	"No ser�s capaz.";
				9:	"No ser� capaz.";
				}
			3:	switch (_grammatical_inflection) {
				1,2,3:	"No ocurre nada, aparentemente.";
				4,5,6:	"No ocurri� nada, aparentemente.";
				7,8,9:	"No ocurrir� nada, aparentemente.";
				}
			4:	switch (_grammatical_inflection) {
				1,2,3:	"Eso ser�a, como poco, maleducado.";
				4,5,6:	"Eso hubiese sido, como poco, maleducado.";
				7,8,9:	"Eso ser�a, como poco, maleducado.";
				}
		}

!!	Push:	see Pull.

!! TODO
	PushDir:
		!! La acci�n PushDir se genera ante frases como EMPUJA EL COCHE HACIA
		!! EL NORTE. Hay 3 casos posibles:
		!!	1:	Si el juego no ha previsto la posibilidad de empujar ese
		!!		objeto hacia una direcci�n (o sea, no llama a la rutina
		!!		PermitirEmujarDir). Esta es la respuesta por defecto m�s
		!!		habitual.
		!!	2:	Si el jugador pone tras HACIA algo que no es una direcci�n.
		!!		(respuesta por defecto en este caso).
		!!	3:	Si intenta empujar hacia arriba o hacia abajo.
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1:	"No creo que empujar ", (the) x1, " sirva de nada.";
				2:	"No crees que empujar ", (the) x1, " sirva de nada.";
				3:	"No cree que empujar ", (the) x1, " sirva de nada.";
				4:	"No cre�a que empujar ", (the) x1, " hubiese servido
					de nada.";
				5:	"No cre�as que empujar ", (the) x1, " hubiese servido
					de nada.";
				6:	"No cre�a que empujar ", (the) x1, " hubiese servido
					de nada.";
				7,8,9:	"Empujar ", (the) x1, " no servir� de nada.";
				}
			2:	switch (_grammatical_inflection) {
					1,2,3:	"Eso no es una direcci�n.";
					4,5,6:	"Eso no era una direcci�n.";
					7,8,9:	"Eso no ser� una direcci�n.";
				}
			3:	"No ", (_puedes_) " empujar", (lo) x1, " en esa direcci�n.";
		}

!! TODO
	PutOn:
		!!	1:	Error, el objeto no est� en poder del jugador. [Nota, conviene
		!!		mirar en este caso si el objeto es animado o no, para generar
		!!		un mensaje m�s adecuado].
		!!	2:	Error, el jugador intenta poner un objeto sobre s� mismo.
		!!	3:	Error, el jugador intenta poner el objeto sobre otro que no
		!!		tiene el atributo "supporter".
		!!	4:	Error, el jugador intenta poner un objeto sobre el propio
		!!		jugador.
		!!	5:	Aviso, el objeto es una prenda puesta. La librer�a va a
		!!		quit�rselo autom�ticamente antes de reintentar la acci�n PutOn.
		!!	6:	Error, se intenta poner el objeto sobre otro en el que ya no
		!!		queda sitio (el n�mero de objetos que caben en el soporte se
		!!		indica en su propiedad "capacity").
		!!	7:	Exito. Mensaje a mostrar para cada objeto puesto cuando se
		!!		ponen muchos (ej: PON TODO SOBRE LA MESA).
		!!	8:	Exito. Mensaje a mostrar cuando se pone un objeto sobre otro.
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1:	if (x1 has animate)
						"Antes tendr�a que ", (coge)"rl", (o) x1, " y no s�
						si se dejar�", (n) x1, ".";
					else
						"Necesito tener ", (the) x1, " para poder poner",
						(lo) x1, " donde sea.";
				2:	if (x1 has animate)
						"Antes tendr�as que ", (coge)"rl", (o) x1, " y no sabes
						si se dejar�", (n) x1, ".";
					else
						"Necesitas tener ", (the) x1, " para poder poner",
						(lo) x1, " donde sea.";
				3:	if (x1 has animate)
						"Antes tendr�a que ", (coge)"rl", (o) x1, " y no sabe
						si se dejar�", (n) x1, ".";
					else
						"Necesita tener ", (the) x1, " para poder poner",
						(lo) x1, " donde sea.";
				4:	if (x1 has animate)
						"Antes tendr�a que haber", (lo) x1, " cogido, y no
						sab�a si ", (the) x1, " se hubiese", (n) x1,
						" dejado.";
					else
						"Hubiese necesitado tener ", (the) x1, " para poder
						poner", (lo) x1, " donde fuese.";
				5:	if (x1 has animate)
						"Antes tendr�as que haber", (lo) x1, " cogido, y no
						sab�as si ", (the) x1, " se hubiese", (n) x1,
						" dejado.";
					else
						"Hubieses necesitado tener ", (the) x1, " para poder
						poner", (lo) x1, " donde fuese.";
				6:	if (x1 has animate)
						"Antes tendr�a que haber", (lo) x1, " cogido, y no
						sab�a si ", (the) x1, " se hubiese", (n) x1,
						" dejado.";
					else
						"Hubiese necesitado tener ", (the) x1, " para poder
						poner", (lo) x1, " donde fuese.";
				7:	if (x1 has animate)
						"Antes tendr� que haber", (lo) x1, " cogido, y no
						sabr� si ", (the) x1, " se habr�a", (n) x1,
						" dejado.";
					else
						"Necesitar� tener ", (the) x1, " para poder
						poner", (lo) x1, " donde sea.";
				8:	if (x1 has animate)
						"Antes tendr�s que haber", (lo) x1, " cogido, y no
						sabr�s si ", (the) x1, " se habr�a", (n) x1,
						" dejado.";
					else
						"Necesitar�s tener ", (the) x1, " para poder
						poner", (lo) x1, " donde sea.";
				9:	if (x1 has animate)
						"Antes tendr� que haber", (lo) x1, " cogido, y no
						sabr� si ", (the) x1, " se habr�a", (n) x1,
						" dejado.";
					else
						"Necesitar� tener ", (the) x1, " para poder
						poner", (lo) x1, " donde sea.";
				}
			2:	"No ", (_puedo_) " poner un objeto sobre s� mismo.";
			3:	switch (_grammatical_inflection) {
				1,2,3:	"Poner cosas sobre ", (the) x1," no servir� de nada.";
				4,5,6:	"Poner cosas sobre ", (the) x1, " no hubiese servido
						de nada.";
				7,8,9:	"Poner cosas sobre ", (the) x1," no servir� de nada.";
				}
!! TODO - cambiar mensaje
			4:	switch (_grammatical_inflection) {
					1:	"Me falta destreza.";
					2:	"Te falta destreza.";
					3:	"Le falta destreza.";
					4:	"Me faltaba destreza.";
					5:	"Te faltaba destreza.";
					6:	"Le faltaba destreza.";
					7:	"Me faltar� destreza.";
					8:	"Te faltar� destreza.";
					9:	"Le faltar� destreza.";
				}
			5:	switch (_grammatical_inflection) {
				1:	"(Primero me ", (lo) x1, " quito.)^";
				2:	"(Primero te ", (lo) x1, " quitas.)^";
				3:	"(Primero se ", (lo) x1, " quita.)^";
				4:	"(Primero me ", (lo) x1, " quit�.)^";
				5:	"(Primero te ", (lo) x1, " quitaste.)^";
				6:	"(Primero se ", (lo) x1, " quit�.)^";
				7:	"(Primero me ", (lo) x1, " quitar�.)^";
				8:	"(Primero te ", (lo) x1, " quitar�s.)^";
				9:	"(Primero se ", (lo) x1, " quitar�.)^";
				}
			6:	switch (_grammatical_inflection) {
					1,2,3:	print "No queda";
					4,5,6:	print "No quedaba";
					7,8,9:	print "No quedar�";
				}
				" sitio en ", (the) x1, " para poner nada m�s.";
			7:	"Hecho.";
			8:	switch (_grammatical_inflection) {
					1:	print "Coloco ";
					2:	print "Colocas ";
					3:	print "Coloca ";
					4:	print "Coloqu� ";
					5:	print "Colocaste ";
					6:	print "Coloc� ";
					7:	print "Colocar� ";
					8:	print "Colocar�s ";
					9:	print "Colocar� ";
				}
				print_ret (the) x1, " sobre ", (the) second, ".";
		}

!! TODO
	Quit:
		!!	1:	Respuesta al comando FIN.
		!!	2:	Respuesta si el jugador escribe algo distinto de "si" o "no".
		switch (n) {
			1:
				print "Por favor, responde SI o NO: ";
			2:
				print "�Realmente quieres abandonar el relato? ";
		}
		return true;

!! TODO
	Remove:
		!!	1:	El recipiente que contiene el objeto que el jugador quiere
		!!		sacar, est� cerrado. (x1 apunta al objeto, no al recipiente,
		!!		el cu�l puede obtenerse con parent(x1)).
		!!	2:	El objeto no est� dentro del recipiente que el jugador ha dicho.
		!!	3:	�xito.
		switch (n) {
			1:	print "Por desgracia ", (the) parent(x1);
				switch (_grammatical_inflection) {
					1,2,3:	print " est�", (n) parent(x1);
					4,5,6:	print " estaba", (n) parent(x1);
					7,8,9:	print " estar�", (n) parent(x1);
				}
				" cerrad", (o) parent(x1), ".";
			2:	switch (_grammatical_inflection) {
				1,2,3:	if (second has animate)
							"�Pero si no ", (lo) x1, " tiene", (n) second,"!";
						"�Pero si no est�", (n) x1, " ah� ahora!";
				4,5,6:	if (second has animate)
							"�Pero si no ", (lo) x1, " ten�a", (n) second,"!";
						"�Pero si no estaba", (n) x1, " ah�!";
				7,8,9:	if (second has animate)
							"�Pero si no ", (lo) x1, " tendr�", (n) second, "!";
						"�Pero si no estar�", (n) x1, " ah�!";
				}
			3:	if (verb_word == 'quita') "Quitad", (o) x1, ".";
				"Sacad", (o) x1, ".";
		}

!! TODO
	Restart:
		!!	1:	Respuesta al comando REINICIAR.
		!!	2:	Si no se puede reiniciar.
		switch (n) {
			1:	print "�Realmente quieres reiniciar el relato?";
			2:	"Error al reiniciar la partida.";
		}

!! TODO
	Restore:
		!!	1:	Si no se pudo cargar la partida con LOAD.
		!!	2:	�xito (no llega a mostrarse, porque en caso de �xito el estado
		!!		del juego cambia al momento en que se salv�. El "Ok" que se ve
		!!		entonces es el del comando Salvar.
		switch (n) {
			1:	"Error. No se pudo recuperar la
				partida.";
			2:	print "Partida cargada.";
				new_line; <<Look>>;
		}

	Rub:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				print "Ya est�", (n) x1;
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "Ya estaba", (n) x1;
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "Ya estar�", (n) x1;
		}
		" bastante limpi", (o) x1, ".";

!! TODO
	Save:
		!!	1:	Si no se pudo guardar el juego.
		!!	2:	�xito.
		switch (n) {
			1:	"Error. No se pudo guardar la partida.";
			2:	"Partida guardada.";
		}

!! TODO
	Score:
		!! Puntuaci�n del juego. Puede activarse porque el jugador lo pide
		!! (con el verbo "PUNTUACION") o porque el juego ha terminado. En
		!! este ultimo caso, la variable "deadflag" valdr� true.
		switch (n) {
			1:
				if (deadflag) print "En este juego, tu puntuaci�n ha sido ";
				else print "Hasta el momento tu puntuaci�n es ";
				print score, " de un total de ", MAX_SCORE,
				", en ", turns, " turno";
				if (turns>1) print "s";
				print ".";
				new_line;
				return;
			2:	"Este juego no tiene conteo de puntuaci�n.";
		}

!! TODO
	ScriptOff:
		!!	1:	Error ya estaba desactivada la transcrcipci�n.
		!!	2:	�xito.
		switch (n) {
			1:	"La transcripci�n ya estaba
				desactivada.";
			2:	new_line; "Fin de la transcripci�n.";
			3:	"Intento fallido de finalizaci�n de
				transcripci�n.";
		}

!! TODO
	ScriptOn:
		!!	1:	Error, ya estaba activada la transcrcipci�n.
		!!	2:	�xito (parte inicial del mensaje, la librer�a a�ade el t�tulo
		!!		del juego obtenido de la constante Historia).
		switch (n) {
			1:	"La transcripci�n ya estaba activada.";
			2:	"Iniciando la transcripci�n de:";
			3:	"Intento fallido de comienzo de la
				transcripci�n.";
		}

!! TODO
	Search:
		!! La acci�n Search se genera ante la frase MIRA EN RECIPIENTE, MIRA EN
		!! SOPORTE, REGISTRA OBJETO.
		!!
		!!	1:	Error, estamos a oscuras.
		!!	2:	�xito examinando soporte, pero no hay nada sobre �l.
		!!	3:	�xito examinando soporte, listar lo que hay.
		!!	4:	El objeto examinado no es soporte ni recipiente, mensaje
		!!		est�ndar indicando que no se encuentra nada.
		!!	5:	Error, El objeto examinado es recipiente, pero est� cerrado.
		!!	6:	�xito, el objeto examinado es recipiente abierto, pero no
		!!		tiene nada dentro.
		!!	7:	�xito, el objeto examinado es recipiente abierto y tiene
		!!		cosas dentro. Se las lista.
		switch (n) {
			1:	switch (_grammatical_inflection) {
					1,2,3:	print "Est�";
					4,5,6:	print "Estaba";
					7,8,9:	print "Estar�";
				}
				" demasiado oscuro como para ver algo.";
			2:	switch (_grammatical_inflection) {
					1,2,3:	"No hay nada sobre ", (the) x1, ".";
					4,5,6:	"No hab�a nada sobre ", (the) x1, ".";
					7,8,9:	"No habr� nada sobre ", (the) x1, ".";
				}
!! TODO - comprobar funcionamiento
			3:	print "Sobre ", (the) x1;
				WriteListFrom(child(x1),
					TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
				".";
			4:	switch (_grammatical_inflection) {
					1:	print "No encuentro";
					2:	print "No encuentras";
					3:	print "No encuentra";
					4:	print "No encontr�";
					5:	print "No encontraste";
					6:	print "No encontr�";
					7:	print "No encontrar�";
					8:	print "No encontrar�s";
					9:	print "No encontrar�";
				}
				" nada interesante.";
			5:	switch (_grammatical_inflection) {
				1:	"No puedo ver lo que hay dentro ", (del_) x1, " porque ",
					(esta) x1, " cerrad", (o) x1, ".";
				2:	"No puedes ver lo que hay dentro ", (del_) x1, " porque ",
					(esta) x1, " cerrad", (o) x1, ".";
				3:	"No puede ver lo que hay dentro ", (del_) x1, " porque ",
					(esta) x1, " cerrad", (o) x1, ".";
				4:	"No pod�a ver lo que hay dentro ", (del_) x1, " porque
					estaba", (n) x1, " cerrad", (o) x1, ".";
				5:	"No pod�as ver lo que hay dentro ", (del_) x1, " porque
					estaba", (n) x1, " cerrad", (o) x1, ".";
				6:	"No pod�a ver lo que hay dentro ", (del_) x1, " porque
					estaba", (n) x1, " cerrad", (o) x1, ".";
				7:	"No podr� ver lo que hay dentro ", (del_) x1, " porque
					estar�", (n) x1, " cerrad", (o) x1, ".";
				8:	"No podr�s ver lo que hay dentro ", (del_) x1, " porque
					estar�", (n) x1, " cerrad", (o) x1, ".";
				9:	"No podr� ver lo que hay dentro ", (del_) x1, " porque
					estar�", (n) x1, " cerrad", (o) x1, ".";
				}
			6:	switch (_grammatical_inflection) {
					1,2,3:	print (The) x1, " ", (esta) x1;
					4,5,6:	print (The) x1, " estaba", (n) x1;
					7,8,9:	print (The) x1, " estar�", (n) x1;
				}
				" vac�", (o) x1, ".";
			7:	print "En ", (the) x1;
				WriteListFrom(child(x1),
					TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
				".";
		}

	Set:
		!! Set sale ante la frase FIJA OBJETO o AJUSTA OBJETO
		"No, no ", (_puedes_) ".";

	SetTo:
		!! SetTo sale ante la frase AJUSTA DIAL A 23 o FIJA CONTROL EN
		!! ACTIVADO, o PON REGULADOR A 30
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT, SECOND_PERSON_PRESENT, THIRD_PERSON_PRESENT:
				print "Eso no puede";
			FIRST_PERSON_PAST, SECOND_PERSON_PAST, THIRD_PERSON_PAST:
				print "Aquello no pod�a";
			FIRST_PERSON_FUTURE, SECOND_PERSON_FUTURE, THIRD_PERSON_FUTURE:
				print "Aquello no podr�";
		}
		" regularse a ning�n valor.";

!! TODO
	Show:
		!!	1:	Error, el jugador intenta mostrar un objeto que no tiene.
		!!	2:	Aviso, se ha enviado la acci�n Show al PNJ, pero este no ha
		!!		respondido. En este caso x1 apunta al PNJ y no al objeto que
		!!		le hemos mostrado.
		switch (n) {
			1:	switch (_grammatical_inflection) {
					1:	"No tengo ", (the) x1, ".";
					2:	"No tienes ", (the) x1, ".";
					3:	"No tiene ", (the) x1, ".";
					4:	"No ten�a ", (the) x1, ".";
					5:	"No ten�as ", (the) x1, ".";
					6:	"No ten�a ", (the) x1, ".";
					7:	"No tendr� ", (the) x1, ".";
					8:	"No tendr�s ", (the) x1, ".";
					9:	"No tendr� ", (the) x1, ".";
				}
			2:	switch (_grammatical_inflection) {
				1,2,3:	print_ret (The) x1, " no muestra", (n) x1,
						" ning�n inter�s.";
				4,5,6:	print_ret (The) x1, " no mostraba", (n) x1,
						" ning�n inter�s.";
				7,8,9:	print_ret (The) x1, " no mostrar�", (n) x1,
						" ning�n inter�s.";
				}
		}

!! TODO
	Sing:
		switch (_grammatical_inflection) {
			1:	"Canto fatal.";
			2:	"Cantas fatal.";
			3:	"Canta fatal.";
			4:	"Cantaba fatal.";
			5:	"Cantabas fatal.";
			6:	"Cantaba fatal.";
			7:	"Cantar� fatal.";
			8:	"Cantar�s fatal.";
			9:	"Cantar� fatal.";
		}

!! TODO
	Sleep:
		print "No estoy especialmente somnolient", (o) player, "."; ! FIXME

!! TODO
	Smell:
		print "No ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT:
				if (IsSingularNoun(player)) print "huelo";
				else print "olemos";
			SECOND_PERSON_PRESENT:
				if (IsSingularNoun(player)) print "hueles";
				else print "ol�is";
			THIRD_PERSON_PRESENT:
				if (IsSingularNoun(player)) print "huele";
				else print "huelen";
			FIRST_PERSON_PAST:
				if (IsSingularNoun(player)) print "ol�a";
				else print "ol�amos";
			SECOND_PERSON_PAST:
				if (IsSingularNoun(player)) print "ol�as";
				else print "ol�ais";
			THIRD_PERSON_PAST:
				if (IsSingularNoun(player)) print "ol�a";
				else print "ol�an";
			FIRST_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "oler�";
				else print "oleremos";
			SECOND_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "oler�s";
				else print "oler�is";
			THIRD_PERSON_FUTURE:
				if (IsSingularNoun(player)) print "oler�";
				else print "oler�n";
			}
			" nada extra�o.";

	Sorry:
		!! Esta acci�n se genera si el usuario introduce "LO SIENTO",
		!! "PERDONA" o cosas similares.
		!! TODO - Cambiar por un mensaje m�s apropiado.
		"Oh, no es necesario que te disculpes.";

!! TODO
	Squeeze:
		!!	1:	Tratar de retorcer un ser animado.
		!!	2:	Cualquier otro objeto.
		switch (n) {
			!! -- "�Las manos quietas!";
			1:	switch (_grammatical_inflection) {
					1:	"No creo que deba.";
					2:	"En realidad no crees que debas.";
					3:	"No cree que deba.";
					4:	"No se me hubiese ocurrido hacer algo as�.";
					5:	"No se te hubiese ocurrido hacer algo as�.";
					6:	"No se le hubiese ocurrido hacer algo as�.";
					7:	"No se me ocurrir� hacer algo as�.";
					8:	"No se te ocurrir� hacer algo as�.";
					9:	"No se le ocurrir� hacer algo as�.";
				}
			2:	switch (_grammatical_inflection) {
					1:	"No consigo nada haciendo eso.";
					2:	"No consigues nada haciendo eso.";
					3:	"No consigue nada haciendo eso.";
					4:	"No consegu� nada haciendo eso.";
					5:	"No conseguiste nada haciendo eso.";
					6:	"No consigui� nada haciendo eso.";
					7:	"No conseguir� nada haciendo eso.";
					8:	"No conseguir�s nada haciendo eso.";
					9:	"No conseguir� nada haciendo eso.";
				}
		}

!! TODO - Recomendar AYUDA
	Strong:
		!! Respuesta si se usa como primera palabra alg�n taco.
		!! TODO - Cambiar por un mensaje m�s apropiado.
		print "Los verdaderos aventureros no ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT, SECOND_PERSON_PRESENT, THIRD_PERSON_PRESENT:
				print "usan";
			FIRST_PERSON_PAST, SECOND_PERSON_PAST, THIRD_PERSON_PAST:
				print "usaban";
			FIRST_PERSON_FUTURE, SECOND_PERSON_FUTURE, THIRD_PERSON_FUTURE:
				print "usar�n";
		}
		" ese vocabulario.";

	Swim:
		print "No ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT, SECOND_PERSON_PRESENT, THIRD_PERSON_PRESENT:
				print "es";
			FIRST_PERSON_PAST, SECOND_PERSON_PAST, THIRD_PERSON_PAST:
				print "era";
			FIRST_PERSON_FUTURE, SECOND_PERSON_FUTURE, THIRD_PERSON_FUTURE:
				print "ser�";
		}
		" un sitio apropiado para ponerse a nadar.";

!! TODO
	Swing:
		switch (_grammatical_inflection) {
			1:	"No parece", (n) x1, " el lugar m�s adecuado en el que
				columpiarme.";
			2:	"No parece", (n) x1, " el lugar m�s adecuado en el que
				columpiarte.";
			3:	"No parece", (n) x1, " el lugar m�s adecuado en el que
				columparse.";
			4:	"No parec�a", (n) x1, " el lugar m�s adecuado en el que
				columpiarme.";
			5:	"No parec�a", (n) x1, " el lugar m�s adecuado en el que
				columpiarte.";
			6:	"No parec�a", (n) x1, " el lugar m�s adecuado en el que
				columpiarse.";
			7:	"No parecer�", (n) x1, " el lugar m�s adecuado en el que
				columpiarme.";
			8:	"No parecer�", (n) x1, " el lugar m�s adecuado en el que
				columpiarte.";
			9:	"No parecer�", (n) x1, " el lugar m�s adecuado en el que
				columpiarse.";
		}

!! TODO
	SwitchOff:
		!!	1:	Error, el objeto no tiene el atributo "switchable".
		!!	2:	Error, el objeto ya tenia desactivado el atributo "on".
		!!	3:	�xito, el objeto tiene ahora desactivado "on".
		switch (n) {
			1:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						"No es algo que pueda apagarse.";
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						"No era algo que se pudiese apagar.";
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						"No ser� algo que pueda apagarse.";
				}
			2:	print "Ya ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "estaba", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "estaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "estar�", (n) x1;
				}
				" apagad", (o) x1, ".";
			3:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "Apago";
						else print "Apagamos";
					SECOND_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "Apagas";
						else print "Apag�is";
					THIRD_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "Apaga";
						else print "Apagan";
					FIRST_PERSON_PAST:
						if (IsSingularNoun(player)) print "Apagu�";
						else print "Apagamos";
					SECOND_PERSON_PAST:
						if (IsSingularNoun(player)) print "Apagaste";
						else print "Apagasteis";
					THIRD_PERSON_PAST:
						if (IsSingularNoun(player)) print "Apag�";
						else print "Apagaron";
					FIRST_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "Apagar�";
						else print "Apagaremos";
					SECOND_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "Apagar�s";
						else print "Apagar�is";
					THIRD_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "Apagar�";
						else print "Apagar�n";
				}
				" ", (the) x1, ".";
		}

!! TODO
	SwitchOn:
		!! Generada al intentar ENCIENDE OBJETO si el objeto tiene el
		!! atributo "conmutable". Observar que si no lo tiene, la acci�n
		!! que se genera ser� sin embargo Quemar.
		!!	1:	Error, el objeto no es conmutable (este error no aparecer�
		!!		si el jugador pone ENCIENDE OBJETO, ya que en este caso la
		!!		acci�n generada ser� Quemar objeto, pero puede aparecer si
		!!		pone CONECTA OBJETO).
		!!	2:	Error, el objeto ya ten�a el atributo "on".
		!!	3:	�xito, el objeto tiene ahora activado "on".
		switch (n) {
			1:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						"No es algo que pueda encenderse.";
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						"No era algo que se pudiese encender.";
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						"No ser� algo que pueda encenderse.";
				}
			2:	print "Ya ";
				switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT,
					SECOND_PERSON_PRESENT,
					THIRD_PERSON_PRESENT:
						print "estaba", (n) x1;
					FIRST_PERSON_PAST,
					SECOND_PERSON_PAST,
					THIRD_PERSON_PAST:
						print "estaba", (n) x1;
					FIRST_PERSON_FUTURE,
					SECOND_PERSON_FUTURE,
					THIRD_PERSON_FUTURE:
						print "estar�", (n) x1;
				}
				" encendid", (o) x1, ".";
			3:	switch (_grammatical_inflection) {
					FIRST_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "Enciendo";
						else print "Encendemos";
					SECOND_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "Enciendes";
						else print "Encend�is";
					THIRD_PERSON_PRESENT:
						if (IsSingularNoun(player)) print "Enciende";
						else print "Encienden";
					FIRST_PERSON_PAST:
						if (IsSingularNoun(player)) print "Encend�";
						else print "Encendimos";
					SECOND_PERSON_PAST:
						if (IsSingularNoun(player)) print "Encendiste";
						else print "Encendisteis";
					THIRD_PERSON_PAST:
						if (IsSingularNoun(player)) print "Encendi�";
						else print "Encendieron";
					FIRST_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "Encender�";
						else print "Encenderemos";
					SECOND_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "Encender�s";
						else print "Encender�is";
					THIRD_PERSON_FUTURE:
						if (IsSingularNoun(player)) print "Encender�";
						else print "Encender�n";
				}
				" ", (the) x1, ".";
		}

!! TODO
	Take:
		!! Hay 13 casos diferentes. Se trata de 1 mensaje de �xito y 11
		!! mensajes de error y un aviso:
		!!	1:	�xito.
		!!	2:	Error, el objeto cogido es el propio jugador.
		!!	3:	Error, el objeto cogido es un objeto animado.
		!!	4:	Error, el jugador est� subido o metido en el objeto que intenta
		!!		coger.
		!!	5:	Error, el jugador ya ten�a ese objeto en su inventario.
		!!	6:	Error, el objeto est� en poder de un ser animado [x1 apunta
		!!		al ser, no al objeto, el cual puede obtenerse en la variable
		!!		"noun"].
		!!	7:	Error, el objeto es un sub-objeto de otro (est� dentro de un
		!!		objeto que tiene el atributo "transparent", pero no tiene el
		!!		atributo "container" ni "supporter").
		!!	8:	Error, el objeto est� dentro de otro, pero este otro no tiene
		!!		el atributo "container" ni "supporter" ni "transparent"
		!!		(probablemente un error de programaci�n).
		!!	9:	Error, el objeto est� dentro de un recipiente cerrado.
		!!	10:	Error, el objeto tiene el atributo "scenery".
		!!	11:	Error, el objeto tiene el atributo "static".
		!!	12:	Error, el jugador lleva demasiados objetos.
		!!	13: Mensaje de aviso, la librer�a ha decidido mover objetos del
		!!		inventario al "objeto saco" para hacer sitio y que el jugador
		!!		pueda coger el objeto. [El objeto saco es uno que puede
		!!		declarar el programador. Si el jugador lo coge y lo lleva
		!!		consigo, la librer�a lo usar� autom�ticamente como mochila
		!!		para descargar al jugador cuando sea necesario].
		switch (n) {
			1:	if (dialecto_sudamericano) print "Tomad"; else print "Cogid";
				print_ret (o) noun, ".";
			2:	switch (_grammatical_inflection) {
					1:	"Siempre me tengo a m� mism", (o) player, ".";
					2:	"Siempre te tienes a t� mism", (o) player, ".";
					3:	"Siempre se tiene a s� mism", (o) player, ".";
					4:	"Siempre me he tenido a m� mism", (o) player, ".";
					5:	"Siempre te has tenido a t� mism", (o) player, ".";
					6:	"Siempre se ha tenido a s� mism", (o) player, ".";
					7:	"Siempre me tendr� a m� mism", (o) player, ".";
					8:	"Siempre te tendr�s a t� mism", (o) player, ".";
					9:	"Siempre se tendr� a s� mism", (o) player, ".";
				}
			3:	switch (_grammatical_inflection) {
				1:	"No creo que ", (al_) x1, " le", (s) x1, " gustara.";
				2:	"No crees que ", (al_) x1, " le", (s) x1, " gustara.";
				3:	"No cree que ", (al_) x1, " le", (s) x1, " gustara.";
				4:	"No cre�a que ", (al_) x1, " le", (s) x1, " hubiese
					gustado.";
				5:	"No cre�as que ", (al_) x1, " le", (s) x1, " hubiese
					gustado.";
				6:	"No cre�a que ", (al_) x1, " le", (s) x1, " hubiese
					gustado.";
				7:	"No lo creer� buena idea.";
				8:	"No lo creer�s buena idea.";
				9:	"No lo creer� buena idea.";

				}
			4:	switch (_grammatical_inflection) {
					1:	print "Tengo que ";
						if (x1 has supporter) print "bajarme ";
						else print "salir ";
					2:	print "Tienes que ";
						if (x1 has supporter) print "bajarte ";
						else print "salir ";
					3:	print "Tiene que ";
						if (x1 has supporter) print "bajarse ";
						else print "salir ";
					4:	print "Ten�a que ";
						if (x1 has supporter) print "bajarme ";
						else print "salir ";
					5:	print "Ten�as que ";
						if (x1 has supporter) print "bajarte ";
						else print "salir ";
					6:	print "Ten�a que ";
						if (x1 has supporter) print "bajarse ";
						else print "salir ";
					7:	print "Tendr� que ";
						if (x1 has supporter) print "bajarme ";
						else print "salir ";
					8:	print "Tendr�s que ";
						if (x1 has supporter) print "bajarte ";
						else print "salir ";
					9:	print "Tendr� que ";
						if (x1 has supporter) print "bajarse ";
						else print "salir ";
				}
				print_ret (del_) x1, " antes.";
			5:	switch (_grammatical_inflection) {
					1:	"Ya tengo ", (the) x1, ".";
					2:	"Ya tienes ", (the) x1, ".";
					3:	"Ya tiene ", (the) x1, ".";
					4:	"Ya ten�a ", (the) x1, ".";
					5:	"Ya ten�as ", (the) x1, ".";
					6:	"Ya ten�a ", (the) x1, ".";
					7:	"Ya tendr� ", (the) x1, ".";
					8:	"Ya tendr�s ", (the) x1, ".";
					9:	"Ya tendr� ", (the) x1, ".";
				}
			6:	switch (_grammatical_inflection) {
					1,2,3:	print "Parece", (n) noun;
					4,5,6:	print "Parec�a", (n) noun;
					7,8,9:	print "Parecer�", (n) noun;
				}
				" pertenecer ", (al_) x1, ".";
			7:	switch (_grammatical_inflection) {
					1,2,3:	print "Parece", (n) noun;
					4,5,6:	print "Parec�a", (n) noun;
					7,8,9:	print "Parecer�", (n) noun;
				}
				" formar parte ", (del_) x1, ".";
			8:	switch (_grammatical_inflection) {
					1,2,3:	"No ", (esta) x1, " disponible", (s) x1, ".";
					4,5,6:	"No estaba", (n) x1, " disponible", (s) x1, ".";
					7,8,9:	"No estar�", (n) x1, " disponible", (s) x1, ".";
				}
			9:	switch (_grammatical_inflection) {
					1,2,3:	print_ret (The) x1, " no ", (esta) x1,
							" abiert", (o) x1, ".";
					4,5,6:	print_ret (The) x1, " no estaba", (n) x1,
							" abiert", (o) x1, ".";
					7,8,9:	print_ret (The) x1, " no estar�", (n) x1,
							" abiert", (o) x1, ".";
				}
			10:	switch (_grammatical_inflection) {
					1:	"Dif�cilmente podr�a llevarme eso.";
					2:	"Dif�cilmente podr�as llevarte eso.";
					3:	"Dif�cilmente podr�a llevarse eso.";
					4:	"Dif�cilmente hubiese podido llevarme eso.";
					5:	"Dif�cilmente hubieses podido llevarte eso.";
					6:	"Dif�cilmente hubiese podido llevarse eso.";
					7:	"Dif�cilmente podr� llevarme eso.";
					8:	"Dif�cilmente podr�s llevarte eso.";
					9:	"Dif�cilmente podr� llevarse eso.";
				}
			11:	switch (_grammatical_inflection) {
					1,2,3:	print_ret (The) x1, " ", (esta) x1,
							" fij", (o) x1, " en el sitio.";
					4,5,6:	print_ret (The) x1, " estaba", (n) x1,
							" fij", (o) x1, " en el sitio.";
					7,8,9:	print_ret (The) x1, " estar�", (n) x1,
							" fij", (o) x1, " en el sitio.";
				}
			12:	switch (_grammatical_inflection) {
					1:	print "Ya tengo";
					2:	print "Ya tienes";
					3:	print "Ya tiene";
					4:	print "Ya ten�a";
					5:	print "Ya ten�as";
					6:	print "Ya ten�a";
					7:	print "Ya tendr�";
					8:	print "Ya tendr�s";
					9:	print "Ya tendr�";
				}
				" las manos ocupadas con demasiadas cosas.";
			!! -- "(colocas ", (the) x1, " en ", (the) SACK_OBJECT,
			!! -- " para hacer sitio)"
			13:	switch (_grammatical_inflection) {
					1:	print "(Primero meto ";
					2:	print "(Primero metes ";
					3:	print "(Primero mete ";
					4:	print "(Primero met� ";
					5:	print "(Primero metiste ";
					6:	print "(Primero meti� ";
					7:	print "(Primero meter� ";
					8:	print "(Primero meter�s ";
					9:	print "(Primero meter� ";
				}
				print_ret (the) x1, " en ", (the) SACK_OBJECT, " para hacer
				sitio).";
		}

!! TODO
	Taste:
		switch (_grammatical_inflection) {
			1:	"No saboreo nada inesperado.";
			2:	"No saboreas nada inesperado.";
			3:	"No saborea nada inesperado.";
			4:	"No sabore� nada inesperado.";
			5:	"No saboreaste nada inesperado.";
			6:	"No sobore� nada inesperado.";
			7:	"No saborear� nada inesperado.";
			8:	"No saborear�s nada inesperado.";
			9:	"No saborear� nada inesperado.";
		}

!! TODO
!!	Tell:	see Answer.
!!		!!	1:	El jugador habla consigo mismo.
!!		!!	2:	Hablar con cualquier otro ser animado.
!!		!! [Nota: Hablar con un objeto inanimado no est� permitido por el
!!		!! parser, que da un error y no llega a generar la acci�n.]
!!		!! [Los errores de parser se tratan en la secci�n "Miscelanea" de
!!		!! esta rutina, al final.]
!!		switch (n) {
!!			1:	switch (_grammatical_inflection) {
!!				1:	"Hablo sol", (o) player, " durante un rato.";
!!				2:	"Hablas sol", (o) player, " durante un rato.";
!!				3:	"Habla sol", (o) player, " durante un rato.";
!!				4:	"Habl� sol", (o) player, " durante un rato.";
!!				5:	"Hablaste sol", (o) player, " durante un rato.";
!!				6:	"Habl� sol", (o) player, " durante un rato.";
!!				}
!!			2:	switch (_grammatical_inflection) {
!!				1:	"No he provocado ninguna reacci�n.";
!!				2:	"No has provocado ninguna reacci�n.";
!!				3:	"No ha provocado ninguna reacci�n.";
!!				4:	"No provoqu� ninguna reacci�n.";
!!				5:	"No provocaste ninguna reacci�n.";
!!				6:	"No provoc� ninguna reacci�n.";
!!				}
!!		}

	Think:
		"Si, eso intent", (as_) ".";

!! TODO
	ThrowAt:
		!!  1:	Lanzar cosas a objetos inanimados.
		!!	2:	Lanzar cosas a objetos animados.
		switch (n) {
			1:	switch (_grammatical_inflection) {
					1,2,3:	"No servir�a de nada.";
					4,5,6:	"No hubiese servido de nada.";
					7,8,9:	"No servir� de nada.";
				}
			2:	switch (_grammatical_inflection) {
					1:	"En el �ltimo momento me echo atr�s.";
					2:	"En el �ltimo momento te echas atr�s.";
					3:	"En el �ltimo momento se echa atr�s.";
					4:	"En el �ltimo momento me ech� atr�s.";
					5:	"En el �ltimo momento te echaste atr�s.";
					6:	"En el �ltimo momento se ech� atr�s.";
					7:	"En el �ltimo momento me echar� atr�s.";
					8:	"En el �ltimo momento te echar�s atr�s.";
					9:	"En el �ltimo momento se echar� atr�s.";
				}
		}

!!	Tie: see JumpOver

!! TODO
	Touch:
		!!	1:	Si se intenta tocar a un ser animado.
		!!	2:	Tocar un objeto normal del juego.
		!!	3: Tocarse a si mismo.
		switch (n) {
			!! "�Las manos quietas!";
			1:	switch (_grammatical_inflection) {
					1:	"No creo que deba.";
					2:	"En realidad no crees que debas.";
					3:	"No cree que deba.";
					4:	"No cre�a que debiese hacer algo as�.";
					5:	"En realidad no cre�as que debieses hacer algo as�.";
					6:	"No cre�a que debiese hacer algo as�.";
					7:	"No creer� que deba hacerlo.";
					8:	"No creer�s que debas hacerlo.";
					9:	"No creer� que deba hacerlo.";
				}
			2:	switch (_grammatical_inflection) {
					1:	"No noto nada extra�o al tacto.";
					2:	"No notas nada extra�o al tacto.";
					3:	"No nota nada extra�o al tacto.";
					4:	"No not� nada extra�o al tacto.";
					5:	"No notaste nada extra�o al tacto.";
					6:	"No not� nada extra�o al tacto.";
					7:	"No notar� nada extra�o al tacto.";
					8:	"No notar�s nada extra�o al tacto.";
					9:	"No notar� nada extra�o al tacto.";
				}
			!! "Si crees que eso servir� de algo...";
			3:	switch (_grammatical_inflection) {
				1:	"No creo que eso sirva de nada.";
				2:	"En realidad no crees que eso sirva de nada.";
				3:	"No cree que eso sirva de nada.";
				4:	"No cre�a que algo as� hubiese servido de nada.";
				5:	"En realidad no cre�as que algo as� hubiese servido de
					nada.";
				6:	"No cre�a que algo as� hubiese servido de nada.";
				7:	"No creer� que eso sirva de nada.";
				8:	"No creer�s que eso sirva de nada.";
				9:	"No creer� que eso sirva de nada.";
				}
    }

!!	Turn:	see Pull

!! TODO
	Unlock:
		!! Unlock se genera ante ABRE <objeto> CON <objeto2>, o tambi�n
		!! ante QUITA CERROJO A <objeto> (en este segundo caso no se
		!! especifica la "llave" que abre la puerta).
		!!
		!!	1:	Error, el objeto que se intenta abrir, no tiene el atributo
		!!		cerrojo.
		!!	2:	Error, el objeto que se intenta abrir tiene atributo "cerrojo",
		!!		pero no tiene atributo "cerrojoechado".
		!!	3:	Error, el <objeto2> que se intenta usar como llave, no coincide
		!!		con la propiedad "con_llave" del <objeto> que intenta ser
		!!		abierto.
		!!	4:	�xito. El <objeto> se abre (con <objeto2> si �ste ha sido
		!!		especificado, el cual podemos encontrarlo en la variable "otro".
		switch (n) {
			1:	switch (_grammatical_inflection) {
					1,2,3:	print "No parece", (n) x1;
					4,5,6:	print "No parec�a", (n) x1;
					7,8,9:	print "No parecer�", (n) x1;
				}
				" tener ning�n tipo de cerrojo.";
			2:	switch (_grammatical_inflection) {
					1,2,3:	print (The) x1, " ya ten�a", (n) x1;
					4,5,6:	print (The) x1, " ya ten�a", (n) x1;
					7,8,9:	print (The) x1, " ya tendr�", (n) x1;
				}
				" abierto el cerrojo.";
			3:	if (second) switch (_grammatical_inflection) {
					1,2,3:	"No parece", (n) x1, " encajar en la cerradura.";
					4,5,6:	"No parec�a", (n) x1, " encajar en la cerradura.";
					7,8,9:	"No parecer�", (n) x1, " encajar en la cerradura.";
				}
				else switch (_grammatical_inflection) {
					1:	"Necesito alg�n tipo de llave.";
					2:	"Necesitas alg�n tipo de llave.";
					3:	"Necesita alg�n tipo de llave.";
					4:	"Necesitaba alg�n tipo de llave.";
					5:	"Necesitabas alg�n tipo de llave.";
					6:	"Necesitaba alg�n tipo de llave.";
					7:	"Necesitar� alg�n tipo de llave.";
					8:	"Necesitar�s alg�n tipo de llave.";
					9:	"Necesitar� alg�n tipo de llave.";
				}
			4:	switch (_grammatical_inflection) {
				1:	if (~~second) "Quito el cerrojo ", (al_) x1, ".";
					"Quito el cerrojo ", (al_) x1, " con ", (the) second, ".";
				2:	if (~~second) "Quitas el cerrojo ", (al_) x1, ".";
					"Quitas el cerrojo ", (al_) x1, " con ", (the) second, ".";
				3:	if (~~second) "Quita el cerrojo ", (al_) second, ".";
					"Quita el cerrojo ", (al_) x1, " con ", (the) second, ".";
				4:	if (~~second) "Quit� el cerrojo ", (al_) x1, ".";
					"Quit� el cerrojo ", (al_) x1, " con ", (the) second, ".";
				5:	if (~~second) "Quitaste el cerrojo ", (al_) x1, ".";
					"Quitaste el cerrojo ",(al_) x1," con ", (the) second, ".";
				6:	if (~~second) "Quit� el cerrojo ", (al_) x1, ".";
					"Quit� el cerrojo ", (al_) x1, " con ", (the) second, ".";
				7:	if (~~second) "Quitar� el cerrojo ", (al_) x1, ".";
					"Quitar� el cerrojo ", (al_) x1, " con ", (the) second, ".";
				8:	if (~~second) "Quitar�s el cerrojo ", (al_) x1, ".";
					"Quitar�s el cerrojo ", (al_) x1, " con ", (the) second,".";
				9:	if (~~second) "Quitar� el cerrojo ", (al_) x1, ".";
					"Quitar� el cerrojo ", (al_) x1, " con ", (the) second, ".";
				}
		}

!! TODO - mostrar salidas
	VagueGo:
		!! El jugador ha dicho IR sin especificar a d�nde
		"Tienes que especificar en qu� direcci�n ir.";

!! TODO
	Verify:
		!!	1:	�xito.
		!!	2:	Error en la verificaci�n.
		switch (n) {
			1:	"Fichero de juego verificado e
				intacto.";
			2:	"El fichero de juego no parece intacto,
				puede estar corrompido (a menos que est�s jugando con un
				int�rprete muy primitivo que no sea capaz de realizar la
				comprobaci�n).";
		}

	Wait:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				print "Pasa";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "Pasaba";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "Pasar�";
		}
		" el tiempo...";

!! TODO dar respuesta adecuada
	Wake:
		print "La cruda realidad es que ";
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				print "esto no es";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				print "aquello no era";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				print "aquello no ser�";
		}
		" un sue�o.";

	WakeOther:
		switch (_grammatical_inflection) {
			FIRST_PERSON_PRESENT,
			SECOND_PERSON_PRESENT,
			THIRD_PERSON_PRESENT:
				"No parece necesario hacer eso.";
			FIRST_PERSON_PAST,
			SECOND_PERSON_PAST,
			THIRD_PERSON_PAST:
				"No parec�a necesario hacer aquello.";
			FIRST_PERSON_FUTURE,
			SECOND_PERSON_FUTURE,
			THIRD_PERSON_FUTURE:
				"No parecer� necesario hacer eso.";
		}

!! TODO
	Wave:
		!!	1:	Si se intenta agitar un objeto que no est� en el inventario.
		!!	2:	Si se agita un objeto que s� est� en el inventario.
		switch (n) {
			1:	switch (_grammatical_inflection) {
				1: "No l", (o) x1, " tengo.";
				2: "No l", (o) x1, " tienes.";
				3: "No l", (o) x1, " tiene.";
				4: "No l", (o) x1, " ten�a.";
				5: "No l", (o) x1, " ten�as.";
				6: "No l", (o) x1, " ten�a.";
				7:	"No l", (o) x1, " tendr�.";
				8:	"No l", (o) x1, " tendr�s.";
				9:	"No l", (o) x1, " tendr�.";
				}
			2:	switch (_grammatical_inflection) {
					1:	print "Me siento";
					2:	print "Te sientes";
					3:	print "Se siente";
					4:	print "Me sent�a";
					5:	print "Te sent�as";
					6:	print "Se sent�a";
					7:	print "Me sentir�";
					8:	print "Te sentir�s";
					9:	print "Se sentir�";
				}
				" rid�cul", (o) player, " agitando ", (the) x1, ".";
		}

!! TODO
	WaveHands:
		!! La acci�n WaveHands se genera ante las frases "gesticula", "agita la
		!! mano", "sacude la mano", "saluda con la mano", etc.
		switch (_grammatical_inflection) {
			1:	print "Me encuentro";
			2:	print "Te encuentras";
			3:	print "Se encuentra";
			4:	print "Me encontraba";
			5:	print "Te encontrabas";
			6:	print "Se encontraba";
		}
		" rid�cul", (o) player, " gesticulando as�.";

!! TODO
	Wear:
		!! 1: Error, el objeto no tiene el atributo "clothing".
		!! 2: Error, el jugador no tiene el objeto.
		!! 3: Error, el objeto ya tiene el atributo "worn".
		!! 4: �xito.
		switch (n) {
			!! "�No puedes ponerte eso!";
			1:	switch (_grammatical_inflection) {
					1:	"No puedo ponerme eso.";
					2:	"No puedes ponerte eso.";
					3:	"No puede ponerse eso.";
					4:	"No pod�a ponerme aquello.";
					5:	"No pod�as ponerte aquello.";
					6:	"No pod�a ponerse aquello.";
					7:	"No podr� ponerme aquello.";
					8:	"No podr�s ponerte aquello.";
					9:	"No podr� ponerse aquello.";
				}
			2:	switch (_grammatical_inflection) {
					1:	"No ", (lo) x1, " tengo.";
					2:	"No ", (lo) x1, " tienes.";
					3:	"No ", (lo) x1, " tiene.";
					4:	"No ", (lo) x1, " ten�a.";
					5:	"No ", (lo) x1, " ten�as.";
					6:	"No ", (lo) x1, " ten�a.";
					7:	"No ", (lo) x1, " tendr�.";
					8:	"No ", (lo) x1, " tendr�s.";
					9:	"No ", (lo) x1, " tendr�.";
				}
			3:	switch (_grammatical_inflection) {
				1:	"Ya ", (lo) x1, " llevo puest", (o) x1, ".";
				2:	"Ya ", (lo) x1, " llevas puest", (o) x1, ".";
				3:	"Ya ", (lo) x1, " lleva puest", (o) x1, ".";
				4:	"Ya ", (lo) x1, " llevaba puest", (o) x1, ".";
				5:	"Ya ", (lo) x1, " llevabas puest", (o) x1, ".";
				6:	"Ya ", (lo) x1, " llevaba puest", (o) x1, ".";
				7:	"Ya ", (lo) x1, " llevar� puest", (o) x1, ".";
				8:	"Ya ", (lo) x1, " llevar�s puest", (o) x1, ".";
				9:	"Ya ", (lo) x1, " llevar� puest", (o) x1, ".";
				}
			4:	switch (_grammatical_inflection) {
					1:	"Me pongo ", (the) x1, ".";
					2:	"Te pones ", (the) x1, ".";
					3:	"Se pone ", (the) x1, ".";
					4:	"Me puse ", (the) x1, ".";
					5:	"Te pusiste ", (the) x1, ".";
					6:	"Se puso ", (the) x1, ".";
					7:	"Me pondr� ", (the) x1, ".";
					8:	"Te pondr�s ", (the) x1, ".";
					9:	"Se pondr� ", (the) x1, ".";
				}
		}

!! TODO
	Yes:
		"La orden 'si' no tiene sentido en esta situaci�n.";

];
