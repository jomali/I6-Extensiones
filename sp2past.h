
[ SecondPersonPast_ES n x1;

	Answer, Ask, AskFor:
		"No hab�a respuesta.";

	!! Ask: @see Answer

	!! AskFor: @see Answer

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "os hubi�seis autolesionado";
			else print "te hubieses autolesionado";
			" a prop�sito.";
		}
		print "No hubiese servido de nada ";
		LanguageVerb(verb_word);
		" ", (al) x1, ".";

	Blow:
		if (IsPluralNoun(player)) print "Nuestro";
		else print "Mi";
		" soplido no produjo ning�n efecto.";

	default:
		ThirdPersonPast_ES(n, x1);
];
