
[ FirstPersonPresent_ES n x1;

	Answer, Ask, AskFor:
		"No hay respuesta.";

	!! Ask: @see Answer

	!! AskFor: @see Answer

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "nos autolesionar�amos";
			else print "me autolesionar�a";
			" a prop�sito.";
		}
		print "No servir�a de nada ";
		LanguageVerb(verb_word);
		" ", (al) x1, ".";

	Blow:
		if (IsPluralNoun(player)) print "Nuestro";
		else print "Mi";
		" soplido no produce ning�n efecto.";

	default:
		ThirdPersonPast_ES(n, x1);
];
