

!!==============================================================================
!!
!!	MENSAJES DE LA LIBRER�A EN ESPA�OL
!!	Narrador en segunda persona, tiempo presente
!!
!!==============================================================================
!!
!!	Archivo:		sp2present.inf
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		0.0
!!	Fecha:			2018/06/08
!!
!!------------------------------------------------------------------------------
!!
!!	HISTORIAL DE VERSIONES
!!
!!	0.0: 2018/06/08	Versi�n en desarrollo.
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

[ SecondPersonPresent_ES n x1;

	Answer, Ask, AskFor:
		"No hay respuesta.";

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "os autolesionar�ais";
			else print "te autolesionar�as";
			" a prop�sito.";
		}
		print "No servir�a de nada tratar de ";
		LanguageVerb(verb_word);
		" ", (the) x1, ".";

	Blow:
		if (IsPluralNoun(player)) print "Vuestro";
		else print "Tu";
		" soplido no produce ning�n efecto.";

	Burn:
		print "Esa es una idea peligrosa con la que no ";
		if (IsPluralNoun(player)) print "lograr�ais";
		else print "lograr�as";
		" nada en cualquier caso.";

	Buy:
		if (x1 == 0) "No hay nada en venta.";
		else {
			print "No ";
			if (IsPluralNoun(player)) print "pod�is";
			else print "puedes";
			" comprar ", (the) x1, ".";
		}

	Climb:
		print "No es algo a lo que ";
		if (IsPluralNoun(player)) print "pod�is";
		else print "puedas";
		print " ";
		LanguageVerb(verb_word);
		".";

	Close:
		switch (n) {
			1:
				"No es algo que se pueda cerrar.";
			2:
				"Ya est�", (n) x1, " cerrad", (o) x1, ".";
			3:
				if (IsPluralNoun(player)) print "Cerr�is";
				else print "Cierras";
				" ", (the) x1, ".";
		}

	Consult:
		print "No ";
		if (IsPluralNoun(player)) print "descubr�s";
		else print "descubres";
		" nada interesante en ", (the) x1, " sobre ese tema.";

	Cut:
		print "Cort�ndo", (lo) x1, " no ";
		if (IsPluralNoun(player)) print "lograr�ais";
		else print "lograr�as";
		" gran cosa.";

	Dig:
		print "No servir�a de nada que ";
		if (IsPluralNoun(player)) print "os pong�is";
		else print "te pongas";
		print " a ";
		LanguageVerb(verb_word);
		" all�.";

	Disrobe:
		switch (n) {
			1:
				print "No ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "llev�is";
				else print "llevas";
				" puest", (o) x1, ".";
			2:
				if (IsPluralNoun(player)) print "Os quit�is";
				else print "Te quitas";
				" ", (the) x1, ".";
		}

	Drink:
		"Eso no parece potable.";

	Drop:
		switch (n) {
			1:
				print "Para poder dejar ", (the) x1, " ";
				if (IsPluralNoun(player)) print "deber�ais";
				else print "deber�as";
				" tener", (lo) x1, ".";
			2:
				print "No ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				"", (contigo) player, ".";
			3:
				print "(Primero ";
				if (IsPluralNoun(player)) print "os quit�is";
				else print "te quitas";
				" ", (the) x1, ".)";
			4:
				"Dejad", (o) x1, ".";
		}

	Eat:
		switch (n) {
			1:
				"Eso no parece comestible.";
			2:
				if (IsPluralNoun(player)) print "Os com�is";
				else print "Te comes";
				" ", (the) x1, ".";
		}

	EmptyT:
		switch (n) {
			1:
 				"", (The) x1, " no puede", (n) x1, " tener cosas dentro.";
			2:
				print "No ";
 				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" hacerlo porque ", (the) x1, " est�", (n) x1,
				" cerrad", (o) x1, ".";
			3:
				"", (The) x1, " ya est�", (n) x1, " vac�", (o) x1, ".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" vaciar un objeto sobre s� mismo.";
		}

	Enter:
		switch (n) {
			1:
				print "Ya ";
				if (IsPluralNoun(player)) print "est�is";
				else print "est�s";
				print " ";
				if (x1 has supporter) print "sobre";
				else print "en";
				" ", (the) x1, ".";
			2:
				print "No ";
				if (IsPluralNoun(x1)) print "son";
				else print "es";
				print " algo donde ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedas";
				print " ";
				LanguageVerb(verb_word);
				".";
			3:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				print " ";
				LanguageVerb(verb_word);
				print " en ", (the) x1, " porque est�", (n) x1,
				" cerrad", (o) x1, ".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "v�is a poder";
				else print "vas a poder";
				print " ";
				LanguageVerb(verb_word);
				print " ah� mientras no ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "solt�is";
				else print "sueltes";
				" primero.";
			5:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "Sub�s";
					else print "Subes";
					print " ", (al) x1;
				} else {
					if (IsPluralNoun(player)) print "Entr�is";
					else print "Entras";
					print " en ", (the) x1;
				}
				".";
			6:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "(Os baj�is";
					else print "(Te bajas";
				} else {
					if (IsPluralNoun(player)) print "(Sal�s";
					else print "(Sales";
				}
				" ", (del) x1, ").";
			7:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "(Os sub�s";
					else print "(Te subes";
					" ", (al) x1, ").^";
				} else if (x1 has container) {
					if (IsPluralNoun(player)) print "(Os met�is";
					else print "(Te metes";
					" en ", (the) x1, ").^";
				} else {
					if (IsPluralNoun(player)) print "(Entr�is";
					else print "(Entras";
					" en ", (the) x1, ").^";
				}
		}

	Examine:
		switch (n) {
			1:
				print "Est� demasiado oscuro. No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" ver nada.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "observ�is";
				else print "observas";
				"  nada especial en ", (the) x1, ".";
			3:
				print (The) x1, " est�", (n) x1;
				if (x1 has on) print " encendid", (o) x1;
				else print " apagad", (o) x1;
				".";
		}

	Exit:
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "est�is";
				else print "est�s";
 				print " en ning�n sitio del que ";
				if (IsPluralNoun(player)) print "deb�is";
				else print "debas";
				print " ";
				LanguageVerb(verb_word);
				".";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" salir ", (del) x1, " porque est�", (n) x1,
				" cerrad", (o) x1, ".";
			3:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "Baj�is";
					else print "Bajas";
				} else {
					if (IsPluralNoun(player)) print "Sal�s";
					else print "Sales";
				}
				" ", (del) x1, ".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				print ". No ";
				if (IsPluralNoun(player)) print "est�is";
				else print "est�s";
				print " ";
				if (x1 has supporter) print "encima";
				else print "dentro";
				" ", (del) x1, ".";
		}

	Fill:
		print "No ";
		if (IsPluralNoun(player)) print "pod�is";
		else print "puedes";
		" llenar", (lo) x1, ".";

	GetOff:
		print "No ";
		if (IsPluralNoun(player)) print "pod�is";
		else print "puedes";
		print ". No ";
		if (IsPluralNoun(player)) print "est�is";
		else print "est�s";
		" en ", (the) x1, ".";

	Give:
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				" ", (the) x1, ".";
			2:
				if (IsPluralNoun(player)) print "Manose�is";
				else print "Manoseas";
				" ", (the) x1, " durante unos momentos, sin conseguir nada.";
			3:
				"", (The) x1, " no parece", (n) x1, " interesad", (o) x1, ".";
		}

	Go:
		switch (n) {
			1:
				PronounNotice(x1);
				if (IsPluralNoun(player)) print "Ten�is";
				else print "Tienes";
				print " que ";
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "bajaros";
					else print "bajarte";
				}
				else print "salir";
				" ", (del) x1, " antes.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" ir por ah�.";
			3:
				PronounNotice(x1);
				if (IsPluralNoun(player)) print "Sois incapaces";
				else print "Eres incapaz";
				" de trepar por ", (the) x1, ".";
			4:
				PronounNotice(x1);
				if (IsPluralNoun(player)) print "Sois incapaces";
				else print "Eres incapaz";
				" de bajar por ", (the) x1, ".";
			5:
				PronounNotice(x1);
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" pasar a trav�s ", (del) x1, ".";
			6:
				PronounNotice(x1);
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" ir porque ", (the) x1, " no lleva", (n) x1,
				" a ning�n sitio.";
		}

	Insert:
		switch (n) {
			1:
				if (x1 has animate) {
					if (IsPluralNoun(player))
						"Antes ten�is que ", (coge)"r", (lo) x1,
						" y no sab�is si se dejar�a", (n) x1, ".";
					else
						"Antes tienes que ", (coge)"r", (lo) x1,
						" y no sabes si se dejar�a", (n) x1, ".";
				} else {
					if (IsPluralNoun(player)) print "Necesit�is";
					else print "Necesitas";
					" tener ", (the) x1, " para poder meter", (lo) x1,
					" donde sea.";
				}
			2:
				"No se pueden meter cosas dentro ", (del) x1, ".";
			3:
				"", (The) x1, " est�", (n) x1, " cerrad", (o) x1, ".";
			4:
				if (IsPluralNoun(player)) print "Ten�is que quit�ros";
				else print "Tienes que quit�rte";
				"", (lo) x1, " antes.";
			5:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" poner un objeto dentro de s� mismo.";
			6:
				print "(Primero ";
				if (IsPluralNoun(player)) print "os ", (lo) x1, " quit�is";
				else print "te ", (lo) x1, "quitas";
				").^";
			7:
				"No queda sitio en ", (the) x1, ".";
			8:
				"Hecho.";
			9:
				if (IsPluralNoun(player)) print "Met�is";
				else print "Metes";
				" ", (the) x1, " dentro ", (del) second, ".";
		}

	Inv:
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "llev�is";
				else print "llevas";
				" nada.";
			2:
				if (IsPluralNoun(player)) print "Llev�is";
				else print "Llevas";
			3:
				print ":^";
			4:
				print ".^";
		}

	Jump:
		if (IsPluralNoun(player)) print "Salt�is";
		else print "Saltas";
		" en el sitio, sin ning�n resultado.";

	JumpOver, Tie:
		print "No ";
		if (IsPluralNoun(player)) print "conseguir�ais";
		else print "conseguir�as";
		" nada as�.";

	Kiss:
		print "No ";
		if (IsPluralNoun(player)) print "se os ocurrir�a";
		else print "se te ocurrir�a";
		" hacer algo as� en este momento.";

	Listen:
		print "No ";
		if (IsPluralNoun(player)) print "escuch�is";
		else print "escuchas";
		" nada fuera de lo com�n.";

	ListMiscellany:
		switch (n) {
			2:
				print " (que est�", (n) x1, " cerrad", (o) x1, ")";
			4:
				print " (que est�", (n) x1, " vac�", (o) x1, ")";
			6:
				print " (que est�", (n) x1, " cerrad", (o) x1,
				" y vac�", (o) x1, ")";
			8:
				print " (alumbrando y que ";
				if (IsPluralNoun(player)) print "llev�is";
				else print "llevas";
				print " puest", (o) x1;
			10:
				print " (que ";
				if (IsPluralNoun(player)) print "llev�is";
				else print "llevas";
				print " puest", (o) x1;
			11:
				print " (que est�", (n) x1, " ";
			17:
				print " (que est�", (n) x1, " vac�", (o) x1, ")";
			18:
				print " que contiene", (n) x1, " ";
			default:
				ThirdPersonPast_ES(n, x1);
		}

	Lock:
		switch (n) {
			1:
				"No parece", (n) x1, " tener ning�n tipo de cerrojo.";
			2:
				if (x1 provides with_key) {
					"", (The) x1, " ya est�", (n) x1, " cerrad", (o) x1,
					" con llave.";
				}
				else {
					"", (The) x1, " ya tiene", (n) x1, " echado el cerrojo.";
				}
			3:
				print "Primero ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
 				" que cerrar ", (the) x1, ".";
			4:
				if (second) {
					"No parece", (n) x1, " encajar en la cerradura.";
				} else {
					if (IsPluralNoun(player)) print "Necesit�is";
					else print "Necesitas";
					" alg�n tipo de llave.";
				}
			5:
				if (second) {
					if (IsPluralNoun(player)) print "Cerr�is";
					else print "Cierras";
					" ", (the) x1, " con ", (the) second, ".";
				} else {
					if (IsPluralNoun(player)) print "Ech�is";
					else print "Echas";
					" el cerrojo ", (al) x1, ".";
				}
		}

	Look:
		switch (n) {
			5, 6:
				if (real_location provides inhibit_object_list)
					if (real_location.inhibit_object_list)
						return true;
				new_line;
				if (x1 ~= location) {
					if (x1 has supporter) print "Sobre ";
					else print "En ";
					print (the) x1, " ";
					if (IsPluralNoun(player)) print "pod�is";
					else print "puedes";
					print " ver ";
				} else {
					if (IsPluralNoun(player)) print "Pod�is";
					else print "Puedes";
					print " ver ";
				}
				if (n==5) print "tambi�n ";
				WriteListFrom(child(x1),
					ENGLISH_BIT + WORKFLAG_BIT + RECURSE_BIT
					+ PARTINV_BIT + TERSE_BIT + CONCEAL_BIT);
				".";
			7:
				print "No ";
				if (IsPluralNoun(player)) print "observ�is";
				else print "observas";
				" nada digno de menci�n al mirar hacia ", (the) x1, ".";
			default:
				ThirdPersonPast_ES(n, x1);
		}

	LookUnder:
		switch (n) {
			1:
				"Est� demasiado oscuro como para poder ver algo.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "v�is";
				else print "ves";
				" nada destacable.";
		}

	Miscellany:
		switch (n) {
			3:
				if (IsPluralNoun(player)) print " Hab�is muerto ";
				else print " Has muerto ";
			4:
				if (IsPluralNoun(player)) print " Hab�is ganado ";
				else print " Has ganado ";
			9:
				print "^�";
				if (IsPluralNoun(player)) print "Os hab�is";
				else print "Te has";
				" quedado a oscuras!";
			17:
				"Est� demasiado oscuro como para poder ver algo.";
			18:
				if (IsPluralNoun(player)) print "vosotr", (o) player;
				else print "t�";
				print " mism", (o) player;
			19:
				"Tan buen aspecto como siempre.";
			26:
				print "(Primero ";
				if (IsPluralNoun(player)) print "trat�is";
				else print "tratas";
				" de ", (coge) "r ", (the) x1, ".)";
			32:
				print "No ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				" eso.";
			44:
				if (action_to_be == ##Drop) {
					print "[No ";
					if (IsPluralNoun(player)) print "ten�is";
					else print "tienes";
					print " nada que ";
					LanguageVerb(verb_word);
					"].";
				} else {
					print "[No hay nada que ";
					LanguageVerb(verb_word);
					"].";
				}
			default:
				ThirdPersonPast_ES(n, x1);
		}

	Objects:
		switch (n) {
			1:
				print "Objectos que ";
				if (IsPluralNoun(player)) print "hab�is";
				else print "has";
				" manejado:^";
			2:
				"Ninguno.";
			3:
				print "   (puest", (o) x1, ")";
			4:
				print "   (", (contigo) player, ")";
			5:
				print "   (dejad", (o) x1, " con alguien)";
			6:
				print "   (ahora en ", (name) x1, ")";
			7:
				print "   (ahora en ", (the) x1, ")";
			8:
				print "   (ahora dentro ", (del) x1, ")";
			9:
				print "   (ahora en ", (the) x1, ")";
			10:
				print "   (perdid", (o) x1, ")";
		}

	Open:
		switch (n) {
			1:
				"No es algo que se pueda abrir.";
			2:
				"Est�", (n) x1, " cerrad", (o) x1, " con llave.";
			3:
				"Ya est�", (n) x1, " abiert", (o) x1, ".";
			4:
				if (IsPluralNoun(player)) print "Abr�s";
				else print "Abres";
				print " ", (the) x1, ", descubriendo ";
				if (WriteListFrom(child(x1),
					ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT) == 0) {
					print "que est�", (n) x1, " vac�", (o) x1;
				}
				".";
			5:
				if (IsPluralNoun(player)) print "Abr�s";
				else print "Abres";
				" ", (the) x1, ".";
		}

	Order:
		"", (The) x1, " tiene", (n) x1, " mejores cosas que hacer.";

	Pray:
		"La fe tal vez pueda resultar �til en una ocasi�n diferente.";

	Pull, Push, Turn:
		switch (n) {
			1:
				"Est�", (n) x1, " firmemente sujet", (o) x1, ".";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "sois capaces";
				else print "eres capaz";
				".";
			3:
				"No ocurre nada, aparentemente.";
			4:
				"Eso ser�a, como poco, maleducado.";
		}

	PushDir:
		switch (n) {
			1:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�is";
				else print "crees";
				" que empujar", (lo) x1, " sirva de nada.";
			2:
				"Eso no es una direcci�n.";
			3:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" empujar", (lo) x1, " en esa direcci�n.";
		}

	PutOn:
		switch (n) {
			1:
				if (x1 has animate) {
					if (IsPluralNoun(player))
						"Antes ten�is que ", (coge)"r", (lo) x1,
						" y no sab�is si se dejar�a", (n) x1, ".";
					else
						"Antes tienes que ", (coge)"r", (lo) x1,
						" y no sabes si se dejar�a", (n) x1, ".";
				} else {
					if (IsPluralNoun(player)) print "Necesit�is";
					else print "Necesitas";
					" tener ", (the) x1, " para poder poner", (lo) x1,
					" donde fuese.";
				}
			2:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" poner un objeto sobre s� mismo.";
			3:
				"Poner cosas sobre ", (the) x1, " no servir�a de nada.";
			4:
				if (IsPluralNoun(player)) print "Os falta";
				else print "Te falta";
				" destreza.";
			5:
				print "(Primero ";
				if (IsPluralNoun(player)) print "os ", (lo) x1, "quit�is";
				else print "te ", (lo) x1, "quitas";
				").^";
			6:
				"No queda sitio en ", (the) x1, " para poner nada m�s.";
			7:
				"Hecho.";
			8:
				if (IsPluralNoun(player)) print "Coloc�is";
				else print "Colocas";
				" ", (the) x1, " sobre ", (the) second, ".";
		}

	Remove:
		switch (n) {
			1:
				"Por desgracia ", (the) parent(x1), " est�", (n) parent(x1),
				" cerrad", (o) parent(x1), ".";
			2:
				if (second has animate)
					"�Pero si no ", (lo) x1, " tiene", (n) second,"!";
				else
					"�Pero si no est�", (n) x1, " ah� en este momento!";
			3:
				if (verb_word == 'quita') "Quitad", (o) x1, ".";
				"Sacad", (o) x1, ".";
		}

	Rub:
		"Ya est�", (n) x1, " bastante limpi", (o) x1, ".";

	Search:
		switch (n) {
			1:
				"Est� demasiado oscuro como para poder ver algo.";
			2:
				"No hay nada sobre ", (the) x1, ".";
			3:
				print "Sobre ", (the) x1;
				WriteListFrom(child(x1),
					ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT + ISARE_BIT);
				".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "encontr�is";
				else print "encuentras";
				" nada interesante.";
			5:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is";
				else print "puedes";
				" ver lo que hay dentro ", (del) x1, " porque
				est�", (n) x1, " cerrad", (o) x1, ".";
			6:
				"", (The) x1, " est�", (n) x1, " vac�", (o) x1, ".";
			7:
				print "En ", (the) x1;
				WriteListFrom(child(x1),
					TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
				".";
		}

	Set:
		print "No, no ";
		if (IsPluralNoun(player)) print "pod�is";
		else print "puedes";
 		".";

	SetTo:
		"Eso no puede regularse a ning�n valor.";

	Show:
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				" ", (the) x1, ".";
			2:
				"", (The) x1, " no muestra", (n) x1, " ning�n inter�s.";
		}

	Sing:
		if (IsPluralNoun(player)) print "Cant�is";
		else print "Cantas";
		" fatal.";

	Sleep:
		print "No ";
		if (IsPluralNoun(player)) print "est�is";
		else print "est�s";
		" especialmente somnolient", (o) player, ".";

	Smell:
		print "No ";
		if (IsPluralNoun(player)) print "ol�is";
		else print "hueles";
		" nada extra�o.";

	Squeeze:
		switch (n) {
			1:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "se os ocurrir�a";
				else print "se te ocurrir�a";
				" hacer algo as�.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "consegu�s";
				else print "consigues";
				" nada haciendo eso.";
		}

	Swim:
		"No es el momento ni el lugar para ponerse a nadar.";

	Swing:
		print "No parece", (n) x1, " el lugar m�s adecuado en el que ";
		if (IsPluralNoun(player)) print "columpiaros";
		else print "columpiarte";
		".";

	SwitchOff:
		switch (n) {
			1:
				"No es algo que se pueda apagar.";
			2:
				"Ya est�", (n) x1, "apagad", (o) x1, ".";
			3:
				if (IsPluralNoun(player)) print "Apag�is";
				else print "Apagas";
				" ", (the) x1, ".";
		}

	SwitchOn:
		switch (n) {
			1:
				"No es algo que se pueda encender.";
			2:
				"Ya est�", (n) x1, " encendid", (o) x1, ".";
			3:
				if (IsPluralNoun(player)) print "Encend�is";
				else print "Enciendes";
				" ", (the) x1, ".";
		}

	Take:
		switch (n) {
			1:
				if (dialecto_sudamericano) print "Tomad";
				else print "Cogid";
				"", (o) noun, ".";
			2:
				print "Siempre ";
				if (IsPluralNoun(player)) print "os ten�is";
				else print "te tienes";
 				" a ", (string) YOURSELF__TX, ".";
			3:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�is";
				else print "crees";
				" que ", (al) x1, " le", (s) x1, " fuese a gustar.";
			4:
				if (IsPluralNoun(player)) print "Ten�is";
				else print "Tienes";
				print " que ";
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "bajaros";
					else print "bajarte";
				}
				else print "salir";
				"", (del) x1, " antes.";
			5:
				print "Ya ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				" ", (the) x1, ".";
			6:
				"Parece", (n) noun, " pertenecer ", (al) x1, ".";
			7:
				"Parece", (n) noun, " formar parte ", (del) x1, ".";
			8:
				"No est�", (n) x1, " disponible", (s) x1, ".";
			9:
				"", (The) x1, " no est�", (n) x1, " abiert", (o) x1, ".";
			10:
				print "Dif�cilmente ";
				if (IsPluralNoun(player)) print "podr�ais";
				else print "podr�as";
				" llevarse aquello.";
			11:
				"", (The) x1, "est�", (n) x1, " fij", (o) x1,
				" en el sitio.";
			12:
				print "Ya ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				" las manos ocupadas con demasiadas cosas.";
			13:
				print "(Primero ";
				if (IsPluralNoun(player)) print "coloc�is";
				else print "colocas";
				" ", (the) x1, " en ", (the) SACK_OBJECT,
				" para hacer sitio).";
		}

	Taste:
		print "No ";
		if (IsPluralNoun(player)) print "sabore�is";
		else print "saboreas";
		" nada inesperado.";

	Tell:
		switch (n) {
			1:
				if (IsPluralNoun(player)) print "Habl�is";
				else print "Hablas";
				" sol", (o) player, " durante un rato.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "provoc�is";
				else print "provocas";
				" ninguna reacci�n.";
		}

	Think:
		print "Si, eso ";
		if (IsPluralNoun(player)) print "intent�is";
		else print "intentas";
		".";

	ThrowAt:
		switch (n) {
			1:
				"No servir�a de nada.";
			2:
				print "En el �ltimo momento ";
				if (IsPluralNoun(player)) print "os ech�is";
				else print "te echas";
				" atr�s.";
		}

	Touch:
		switch (n) {
			1:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�is";
				else print "crees";
				" que ", (al) x1, " le", (s) x1, " pueda gustar.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "not�is";
				else print "notas";
				" nada extra�o al tacto.";
			3:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�is";
				else print "crees";
				" que algo as� pueda servir de nada.";
    	}

	Unlock:
		switch (n) {
			1:
				"No parece", (n) x1, " tener ning�n tipo de cerrojo.";
			2:
				"", (The) x1, " ya tiene", (n) x1, " abierto el cerrojo.";
			3:
				if (second) {
					"No parece", (n) x1, " encajar en la cerradura.";
				} else {
					if (IsPluralNoun(player)) print "Necesit�is";
					else print "Necesitas";
					" alg�n tipo de llave.";
				}
			4:
				if (IsPluralNoun(player)) print "Quit�is";
				else print "Quitas";
				print " el cerrojo ", (al) x1;
				if (second) print " con ", (the) second;
				".";
		}

	Wait:
		"Pasa el tiempo...";

	Wake:
		"La cruda realidad es que eso no es un sue�o.";

	WakeOther:
		"No parece necesario hacer eso.";

	Wave:
		switch (n) {
			1:
				print "No l", (o) x1, " ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
				"", (contigo) player, ".";
			2:
				if (IsPluralNoun(player)) print "Os sent�s";
				else print "Te sientes";
				" rid�cul", (o) player, " agitando ", (the) x1, ".";
		}

	WaveHands:
		if (IsPluralNoun(player)) print "Os encontr�is";
		else print "Te encuentras";
		" rid�cul", (o) player, " gesticulando as�.";

	Wear:
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "pod�is poneros";
				else print "puedes ponerte";
				" aquello.";
			2:
				print "No ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "ten�is";
				else print "tienes";
 				".";
			3:
				print "Ya ", (lo) x1;
				if (IsPluralNoun(player)) print "llev�is";
				else print "llevas";
				" puest", (o) x1, ".";
			4:
				if (IsPluralNoun(player)) print "Os pon�is";
				else print "Te pones";
				" ", (the) x1, ".";
		}

	default:
		ThirdPersonPast_ES(n, x1);

];
