
[ FirstPersonFuture_ES n x1;

	Answer, Ask, AskFor:
		"No habr� respuesta.";

	!! Ask: @see Answer

	!! AskFor: @see Answer

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "nos iremos a autolesionar";
			else print "me ir� a autolesionar";
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
