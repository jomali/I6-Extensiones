
[ SecondPersonFuture_ES n x1;

	Answer, Ask, AskFor:
		"No habr� respuesta.";

	!! Ask: @see Answer

	!! AskFor: @see Answer

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "os ir�is a autolesionar";
			else print "te ir�s a autolesionar";
			" a prop�sito.";
		}
		print "No servir� de nada ";
		LanguageVerb(verb_word);
		" ", (al) x1, ".";

	Blow:
		if (IsPluralNoun(player)) print "Nuestro";
		else print "Mi";
		" soplido no producir� ning�n efecto.";

	default:
		ThirdPersonPast_ES(n, x1);
];
