
[ SecondPersonPresent_ES n x1;

	Answer, Ask, AskFor:
		"No hay respuesta.";

	!! Ask: @see Answer

	!! AskFor: @see Answer

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "os autolesionar�ais";
			else print "te autolesionar�as";
			" a prop�sito.";
		}
		print "No servir�a de nada ";
		LanguageVerb(verb_word);
		" ", (al) x1, ".";

	Blow:
		if (IsPluralNoun(player)) print "Vuestro";
		else print "Tu";
		" soplido no produce ning�n efecto.";

	default:
		ThirdPersonPast_ES(n, x1);
];
