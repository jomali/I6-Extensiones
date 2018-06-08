

!!==============================================================================
!!
!!	MENSAJES DE LA LIBRER�A EN ESPA�OL
!!	Narrador en tercera persona, tiempo pasado
!!
!!==============================================================================
!!
!!	Archivo:		sp3past.inf
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
!!
!!	La librer�a de mensajes se basa en la librer�a espa�ola para Inform
!!	'Spanish.h', de Sarganar. Adem�s de las modificaciones en las inflexiones
!!	de persona y tiempo, se han modificado los contenidos de los mensajes para
!!	las siguientes acciones:
!!
!!	-	Attack
!!	-	Burn
!!	-	Buy
!!	-	Climb
!!	-	Cut
!!	-	Dig
!!	-	Disrobe
!!	-	Drop
!!	-	Eat
!!	-	EmptyT
!!	-	Enter
!!	-	GetOff
!!	-	Give
!!	-	Go
!!	-	Kiss
!!	-	LookUnder
!!
!!------------------------------------------------------------------------------

[ ThirdPersonPast_ES n x1
	i;

	Answer, Ask, AskFor:
		"No hab�a respuesta.";

	!! Ask: @see Answer

	!! AskFor: @see Answer

	Attack:
		if (x1 == player) {
			print "No ";
			if (IsPluralNoun(player)) print "se hubiesen autolesionado";
			else print "se hubiese autolesionado";
			" a prop�sito.";
		}
		print "No hubiese servido de nada tratar de ";
		LanguageVerb(verb_word);
		" ", (the) x1, ".";

	Blow:
		if (IsPluralNoun(player)) print "Su";
		else print "Su";
		" soplido no produjo ning�n efecto.";

	Burn:
		print "Aquella era una idea peligrosa con la que no ";
		if (IsPluralNoun(player)) print "hubiesen logrado";
		else print "hubiese logrado";
		" nada en cualquier caso.";

	Buy:
		if (x1 == 0) "No hab�a nada en venta.";
		else {
			print "No ";
			if (IsPluralNoun(player)) print "pod�an";
			else print "pod�a";
			" comprar ", (the) x1, ".";
		}

	Climb:
		print "No era algo a lo que ";
		if (IsPluralNoun(player)) print "pudiesen";
		else print "pudiese";
		print " ";
		LanguageVerb(verb_word);
		".";

	Close:
		!!	1:	Error. El objeto no es *openable*.
		!!	2:	Error. El objeto est� cerrado.
		!!	3:	Mensaje cuando se cierra el objeto.
		switch (n) {
			1:
				"No era algo que se pudiese cerrar.";
			2:
				"Ya estaba", (n) x1, " cerrad", (o) x1, ".";
			3:
				if (IsPluralNoun(player)) print "Cerraron";
				else print "Cerr�";
				" ", (the) x1, ".";
		}

	CommandsOff:
		switch (n) { ![6/11]
			1:
				"[Grabaci�n de �rdenes finalizada.]";
			#Ifdef TARGET_GLULX;
			2:
				"[Grabaci�n de �rdenes ya finalizada.]";
			#Endif; ! TARGET_
		}

	CommandsOn:
		switch (n) { ![6/11]
			1:
				"[Grabaci�n de �rdenes activada.]";
			#Ifdef TARGET_GLULX;
			2:
				"[�rdenes relanzadas.]";
			3:
				"[Grabaci�n de �rdenes ya activada.]";
			4:
				"[Fallo en la grabaci�n de �rdenes.]";
			#Endif; ! TARGET_
		}

	CommandsRead:
		switch (n) { ![6/11]
			1:
				"[Reejecutando �rdenes...]";
			#Ifdef TARGET_GLULX;
			2:
				"[Las �rdenes ya est�n siendo relanzadas.]";
			3:
				"[Fallo en la reejecuci�n de �rdenes: grabaci�n en curso.]";
			4:
				"[Fallo en la reejecuci�n de �rdenes.]";
			5:
				"[Reejecuci�n de �rdenes: fin del proceso.]";
			#Endif; ! TARGET_
		}

	Consult:
		print "No ";
		if (IsPluralNoun(player)) print "descubrieron";
		else print "descubri�";
		" nada interesante en ", (the) x1, " sobre aquel tema.";

	Cut:
		print "Cort�ndo", (lo) x1, " no ";
		if (IsPluralNoun(player)) print "hubiesen logrado";
		else print "hubiese logrado";
		" gran cosa.";

	Dig:
		print "No hubiese servido de nada que ";
		if (IsPluralNoun(player)) print "se pusiesen";
		else print "se pusiese";
		print " a ";
		LanguageVerb(verb_word);
		" all�.";

	Disrobe:
		!!	1:	Error. El protagonista no lleva el objeto puesto.
		!!	2:	Mensaje cuando el protagonista se quita el objeto.
		switch (n) {
			1:
				print "No ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "llevaban";
				else print "llevaba";
				" puest", (o) x1, ".";
			2:
				if (IsPluralNoun(player)) print "Se quitaron";
				else print "Se quit�";
				" ", (the) x1, ".";
		}

	Drink:
		"Aquello no parec�a potable.";

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
			1:
				print "Para poder dejar ", (the) x1, " ";
				if (IsPluralNoun(player)) print "hubiesen debido";
				else print "hubiese debido";
				" tener", (lo) x1, ".";
			2:
				print "No ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" ", (contigo) player, ".";
			3:
				print "(Primero ";
				if (IsPluralNoun(player)) print "se quitaron";
				else print "se quit�";
				" ", (the) x1, ".)";
			4:
				"Dejad", (o) x1, ".";
		}

	Eat:
		!!	1:	Error, el objeto no tiene el atributo "comestible".
		!!	2:	�xito. [NOTA: la librer�a permite por defecto comerse
		!!		cualquier cosa que tenga el atributo "comestible", pero la
		!!		�nica acci�n que provoca esto es que el objeto en cuesti�n
		!!		desaparece del juego al ser comido.]
		switch (n) {
			1:
				"Aquello no parec�a comestible.";
			2:
				if (IsPluralNoun(player)) print "Se comieron";
				else print "Se comi�";
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
			1:
 				"", (The) x1, " no pod�a", (n) x1, " tener cosas dentro.";
			2:
				print "No ";
 				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" hacerlo porque ", (the) x1, " estaba", (n) x1,
				" cerrad", (o) x1, ".";
			3:
				"", (The) x1, " ya estaba", (n) x1, " vac�", (o) x1, ".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
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
		!! contiene el verbo usado por el usuario (convertido en forma
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
		!!		al usuario en el objeto desde el cual pueda acceder al que el
		!!		usuario le ha indicado.
		switch (n) {
			1:
				print "Ya ";
				if (IsPluralNoun(player)) print "estaban";
				else print "estaba";
				print " ";
				if (x1 has supporter) print "sobre";
				else print "en";
				" ", (the) x1, ".";
			2:
				print "No ";
				if (IsPluralNoun(x1)) print "eran";
				else print "era";
				print " algo donde ";
				if (IsPluralNoun(player)) print "pudiesen";
				else print "pudiese";
				print " ";
				LanguageVerb(verb_word);
				".";
			3:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				print " ";
				LanguageVerb(verb_word);
				print " en ", (the) x1, " porque estaba", (n) x1,
				" cerrad", (o) x1, ".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "iban a poder";
				else print "iba a poder";
				print " ";
				LanguageVerb(verb_word);
				print " ah� mientras no ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "soltasen";
				else print "soltase";
				" primero.";
			5:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "Subieron";
					else print "Subi�";
					print " ", (al) x1;
				} else {
					if (IsPluralNoun(player)) print "Entraron";
					else print "Entr�";
					print " en ", (the) x1;
				}
				".";
			6:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "(Se bajaron";
					else print "(Se baj�";
				} else {
					if (IsPluralNoun(player)) print "(Salieron";
					else print "(Sali�";
				}
				" ", (del) x1, ").";
			7:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "(Se subieron";
					else print "(Se subi�";
					" ", (al) x1, ").^";
				} else if (x1 has container) {
					if (IsPluralNoun(player)) print "(Se metieron";
					else print "(Se meti�";
					" en ", (the) x1, ").^";
				} else {
					if (IsPluralNoun(player)) print "(Entraron";
					else print "(Entr�";
					" en ", (the) x1, ").^";
				}
		}

	Examine:
		!!	1:	Error, el usuario intenta examinar un objeto, pero est� a
		!!		oscuras.
		!!	2:	�xito, pero el objeto examinado no tiene descripcion
		!!	3:	�xito, pero el objeto examinado no tiene descripcion, aunque
		!!		tiene el atributo conmutable, por lo que la librer�a genera
		!!		este mensaje para indicar si est� apagado o encendido.
		switch (n) {
			1:
				print "Estaba demasiado oscuro. No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" ver nada.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "observaron";
				else print "observ�";
				"  nada especial en ", (the) x1, ".";
			3:
				print (The) x1, " estaba", (n) x1;
				if (x1 has on) print " encendid", (o) x1;
				else print " apagad", (o) x1;
				".";
		}

	Exit:
		!!	1:	Error, el usuario no est� subido/sentado/metido en ning�n
		!!		objeto. [Nota, si la localidad tiene la propiedad "afuera",
		!!		entonces la acci�n Salir lo sacar� de la localidad. En caso
		!!		contrario es cuando se genera este error.]
		!!	2:	Error, el usuario est� dentro de un recipiente cerrado.
		!!	3:	�xito, el usuario sale/baja del objeto
		!!	4:	Error, m�s espec�fico. [6/11]
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "estaban";
				else print "estaba";
 				print " en ning�n sitio del que ";
				if (IsPluralNoun(player)) print "debiesen";
				else print "debiese";
				print " ";
				LanguageVerb(verb_word);
				".";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" salir ", (del) x1, " porque estaba", (n) x1,
				" cerrad", (o) x1, ".";
			3:
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "Bajaron";
					else print "Baj�";
				} else {
					if (IsPluralNoun(player)) print "Salieron";
					else print "Sali�";
				}
				" ", (del) x1, ".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				print ". No ";
				if (IsPluralNoun(player)) print "estaban";
				else print "estaba";
				print " ";
				if (x1 has supporter) print "encima";
				else print "dentro";
				" ", (del) x1, ".";
		}

	Fill:
		print "No ";
		if (IsPluralNoun(player)) print "pod�an";
		else print "pod�a";
		" llenar", (lo) x1, ".";

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
			1:
				if (deadflag) print "La puntuaci�n se desglos� ";
				else          print "La puntuaci�n se desglosa ";
				"de la siguiente manera:^";
			2:
				"por encontrar objetos importantes";
			3:
				"por visitar lugares importantes";
			4:
				print "total (de ", MAX_SCORE ; ")";
		}

	GetOff:
		!! Esta acci�n se genera ante la frase SAL DEL ARMARIO o similares.
		!! Ante SAL a secas la acci�n es Salir. Si el usuario no est� en el
		!! objeto indicado, se genera el siguiente mensaje de error. Si est�,
		!! la librer�a generar� una acci�n Salir, por lo que el mensaje de
		!! �xito ser� el de Salir.
		print "No ";
		if (IsPluralNoun(player)) print "pod�an";
		else print "pod�a";
		print ". No ";
		if (IsPluralNoun(player)) print "estaban";
		else print "estaba";
		" en ", (the) x1, ".";

	Give:
		!!	1:	Error, el usuario intenta dar un objeto que no tiene.
		!!	2:	Error, el usuario se da el objeto a s� mismo.
		!!	3:	Aviso, se ha enviado la acci�n Dar al PNJ, pero este no ha
		!!		respondido. En este caso x1 apunta al PNJ y no al objeto
		!!		que le hemos dado.
		!!
		!! [Observar que por defecto el objeto sigue en poder del
		!! usuario. Si queremos que el PNJ lo acepte, hay que programarlo
		!! como parte de su rutina Vida.]
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" ", (the) x1, ".";
			2:
				if (IsPluralNoun(player)) print "Manosearon";
				else print "Manose�";
				" ", (the) x1, " durante unos momentos, sin conseguir nada.";
			3:
				"", (The) x1, " no parec�a", (n) x1, " interesad", (o) x1, ".";
		}

	Go:
		!!	1:	Error, el usuario est� dentro/subido en un objeto del que
		!!		tiene que salir antes.
		!!	2:	Error, la localidad no tiene salida en esa direcci�n (y tampoco
		!!		tiene la propiedad "cant_go", ya que en este caso se habr�a
		!!		impreso el valor de esa propiedad.
		!!	3:	Error, el usuario ha intentado ir hacia arriba, pero all� hay
		!!		una puerta cerrada.
		!!	4:	Error, el usuario ha intentado ir hacia abajo, pero all� hay
		!!		una puerta cerrada.
		!!	5:	Error, en la direcci�n que ha dicho el usuario hay una
		!!		puerta cerrada.
		!!	6:	Error, en la direcci�n que ha dicho el usuario hay una puerta,
		!!		pero �sta no tiene una propiedad "door_to" (probablemente un
		!!		error de programaci�n del juego).
		switch (n) {
			1:
				PronounNotice(x1);
				if (IsPluralNoun(player)) print "Ten�an";
				else print "Ten�a";
				print " que ";
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "bajarse";
					else print "bajarse";
				}
				else print "salir";
				" ", (del) x1, " antes.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" ir por ah�.";
			3:
				PronounNotice(x1);
				if (IsPluralNoun(player)) print "Eran incapaces";
				else print "Era incapaz";
				" de trepar por ", (the) x1, ".";
			4:
				PronounNotice(x1);
				if (IsPluralNoun(player)) print "Eran incapaces";
				else print "Era incapaz";
				" de bajar por ", (the) x1, ".";
			5:
				PronounNotice(x1);
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" pasar a trav�s ", (del) x1, ".";
			6:
				PronounNotice(x1);
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" ir porque ", (the) x1, " no llevaba", (n) x1,
				" a ning�n sitio.";
		}

	Insert:
		!!	1:	Error, el objeto no est� en poder del usuario. [Nota, conviene
		!!		mirar en este caso si el objeto es animado o no, para generar
		!!		un mensaje m�s adecuado].
		!!	2:	Error, el usuario intenta meter el objeto en otro que no tiene
		!!		el atributo "container".
		!!	3:	Error, el usuario intenta meter el objeto en un recipiente
		!!		cerrado.
		!!	4:	Error, el objeto es una prenda que el usuario lleva puesta.
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
			1:
				if (x1 has animate) {
					if (IsPluralNoun(player))
						"Antes ten�an que ", (coge)"r", (lo) x1,
						" y no sab�an si se hubiese", (n) x1, " dejado.";
					else
						"Antes ten�a que ", (coge)"r", (lo) x1,
						" y no sab�a si se hubiese", (n) x1, " dejado.";
				} else {
					if (IsPluralNoun(player)) print "Necesitaban";
					else print "Necesitaba";
					" tener ", (the) x1, " para poder meter", (lo) x1,
					" donde fuese.";
				}
			2:
				"No se pod�an meter cosas dentro ", (del) x1, ".";
			3:
				"", (The) x1, " estaba", (n) x1, " cerrad", (o) x1, ".";
			4:
				if (IsPluralNoun(player)) print "Ten�an que quit�rse";
				else print "Ten�a que quit�rse";
				"", (lo) x1, " antes.";
			5:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" poner un objeto dentro de s� mismo.";
			6:
				print "(Primero ";
				if (IsPluralNoun(player)) print "se ", (lo) x1, " quitaron";
				else print "se ", (lo) x1, " quit�";
				").^";
			7:
				"No quedaba sitio en ", (the) x1, ".";
			8:
				"Hecho.";
			9:
				if (IsPluralNoun(player)) print "Metieron";
				else print "Meti�";
				" ", (the) x1, " dentro ", (del) second, ".";
		}

	Inv:
		!!	1:	Mensaje si el inventario est� vac�o
		!!	2:	Encabezado del inventario, antes de la lista de objetos
		!!		generada por la librer�a
		!!	3 y 4: [6/11]
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "llevaban";
				else print "llevaba";
				" nada.";
			2:
				if (IsPluralNoun(player)) print "Llevaban";
				else print "Llevaba";
			3:
				print ":^";
			4:
				print ".^";
		}

	Jump:
		if (IsPluralNoun(player)) print "Saltaron";
		else print "Salt�";
		" en el sitio, sin ning�n resultado.";

	JumpOver, Tie:
		print "No ";
		if (IsPluralNoun(player)) print "hubiesen conseguido";
		else print "hubiese conseguido";
		" nada as�.";

	Kiss:
		!! TODO - modificar
		print "No ";
		if (IsPluralNoun(player)) print "se les hubiese ocurrido";
		else print "se le hubiese ocurrido";
		" hacer algo as� en aquel momento.";

	Listen:
		print "No ";
		if (IsPluralNoun(player)) print "escucharon";
		else print "escuch�";
		" nada fuera de lo com�n.";

	ListMiscellany:
		!! Los siguientes mensajes se muestran como aclaraciones cuando se est�
		!! listando el inventario del usuario, o los objetos que hay en una
		!! localidad. Junto a cada mensaje se comenta qu� condiciones deben
		!! darse en ese objeto para que se muestre ese mensaje aclaratorio.
		switch (n) {
			1:	!! El objeto tiene 'light' y la localidad no
				print " (alumbrando)";
			2:	!! El objeto tiene 'container' pero no 'open'
				print " (que estaba", (n) x1, " cerrad", (o) x1, ")";
			3:	!! Casos 2 y 1 juntos
				print " (cerrad", (o) x1, " y alumbrando)";
			4:	!! El objeto es un recipiente abierto (o transparente) y no
				!! tiene nada en su interior
				print " (que estaba", (n) x1, " vac�", (o) x1, ")";
			5:	!! Casos 1 y 4 juntos
				print " (vac�", (o) x1, " y alumbrando)";
			6:	!! El objeto tiene 'container', no 'open', pero
				!! s� 'transparent'
				print " (que estaba", (n) x1, " cerrad", (o) x1,
				" y vac�", (o) x1, ")";
			7:	!! Casos 1 y 6 juntos
				print " (cerrad", (o) x1, ", vac�", (o) x1, " y
				alumbrando)";

			!! Los casos siguientes son similares, pero se muestran cuando se
			!! solicita a la rutina EscribirListaDesde la opci�n INFOTOTAL. La
			!! librer�a puede combinar varios de estos mensajes, por eso no
			!! deben llevar el cerrado de par�ntesis al final, que lo a�ade la
			!! propia librer�a. *** NO SE ACONSEJA CAMBIAR ESTOS ***

			8:	!! El objeto tiene 'light' y 'worn'
				print " (alumbrando y que ";
				if (IsPluralNoun(player)) print "llevaban";
				else print "llevaba";
				print " puest", (o) x1;
			9:	!! El objeto tiene 'light' pero no 'worn'
				print " (alumbrando";
			10:	!! El objeto no tiene 'light' pero s� 'worn'
				print " (que ";
				if (IsPluralNoun(player)) print "llevaban";
				else print "llevaba";
				print " puest", (o) x1;
			11:	!! Mensaje introductorio para decir "que est�
				!! abierto / cerrado / vacio"...
				print " (que estaba", (n) x1, " ";
			12:	!! Objeto tiene 'container', 'openable' y 'open'
				!! (y cosas dentro)
				print "abiert", (o) x1;
			13:	!! Objeto tiene 'container', 'openable' y 'open'
 				!! (pero vacio)
				print "abiert", (o) x1, ", pero vac�", (o) x1;
			14:	!! Objeto tiene 'container', 'openable' y no 'open'
				print "cerrad", (o) x1;
			15:	!! Objeto tiene 'container', 'openable' y 'locked' o 'lockable'
				print "cerrad", (o) x1, " con llave";
			16:	!! Objeto tiene 'container', no 'openable' y 'transparent'
				print " vac�", (o) x1;
			17:	!! Como el caso anterior, pero mensaje m�s "largo" (se activa
				!! si 'WriteListFrom' es llamada sin el modo PARTINV_BIT)
				!! TODO - Comprobar que se trata realmente del modo PARTINV_BIT
				print " (que estaba", (n) x1, " vac�", (o) x1, ")";
			18:	!! encabezado a la lista de lo que hay dentro del objeto
				print " que conten�a", (n) x1, " ";
			19:	!! Si el objeto tiene 'supporter', la librer�a va a listar sus
				!! contenidos. Este es el encabezado de la lista
 				print " (sobre ", (el_) x1;
			20:	!! Como e l9, pero en otra modalidad (que se activa si
				!! 'WriteListFrom' es llamada sin el modo PARTINV_BIT)
				print ", encima ", (del_) x1;
			21:	!! Si el contenido tiene 'container' y puede verse su interior
				!! y hay cosas, la librer�a va a mostrar sus contenidos. Este
				!! es el encabezado de la lista
				print " (en ", (el_) x1;
			22:	!! Como el 21, pero en otra modalidad (que se activa si
				!! 'WriteListFrom' es llamada sin el modo PARTINV_BIT)
				!! TODO - Comprobar que se trata realmente del modo PARTINV_BIT
				print ", dentro ", (del_) x1;
		}

 	LMode1:
	    !! La acci�n LMode1 se genera ante el comando BREVE (o NORMAL). La
	    !! librer�a imprime la constante Historia y a continuaci�n este
	    !! mensaje.
		"[", (string) Story, " est� ahora en su modo normal @<<breve@>>, que da
		s�lo descripciones largas de las localidades la primera vez que son
		visitadas, y descripciones cortas en otro caso].";

	LMode2:
    	!! La acci�n LMode2 se genera ante el comando LARGO. La librer�a
		!! imprime la constante Historia y a continuaci�n este mensaje.
		"[", (string) Story, " est� ahora en su modo @<<largo@>>, que siempre
		da descripciones largas de las localidades (incluso si ya hab�as
		estado antes)].";

	LMode3:
    	!! La acci�n LMode3 se genera ante el comando SUPERBREVE. La librer�a
		!! imprime la constante Historia y a continuaci�n este mensaje.
		"[", (string) Story, " est� ahora en su modo @<<superbreve@>>, que
		siempre da descripciones cortas de las localidades (incluso si nunca
		hab�as estado antes)].";

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
			1:
				"No parec�a", (n) x1, " tener ning�n tipo de cerrojo.";
			2:
				if (x1 provides with_key) {
					"", (The) x1, " ya estaba", (n) x1, " cerrad", (o) x1,
					" con llave.";
				}
				else {
					"", (The) x1, " ya ten�a", (n) x1, " echado el cerrojo.";
				}
			3:
				print "Primero ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
 				" que cerrar ", (the) x1, ".";
			4:
				if (second) {
					"No parec�a", (n) x1, " encajar en la cerradura.";
				} else {
					if (IsPluralNoun(player)) print "Necesitaban";
					else print "Necesitaba";
					" alg�n tipo de llave.";
				}
			5:
				if (second) {
					if (IsPluralNoun(player)) print "Cerraron";
					else print "Cerr�";
					" ", (the) x1, " con ", (the) second, ".";
				} else {
					if (IsPluralNoun(player)) print "Echaron";
					else print "Ech�";
					" el cerrojo ", (al) x1, ".";
				}
		}

	Look:
		!! La acci�n Look se genera cuando el usuario pone MIRAR, pero tambi�n
		!! de forma autom�tica al entrar en una localidad nueva, o cuando el
		!! usuario sale/se baja de un objeto en el que estaba.
		!!
		!! Algunos de los mensajes que se definen aqu� aparecen en el "t�tulo"
		!! de la localidad (lo que aparece en negrita antes de la descripci�n
		!! de la localidad).
		!!
		!!	1:	Aclaraci�n a a�adir tras el t�tulo si el usuario est� subido
		!!		en un objeto.
		!!	2:	Aclaraci�n a a�adir tras el t�tulo si el usuario est� dentro
		!!		de un objeto.
		!!	3:	Aclaraci�n a a�adir tras el t�tulo si el usuario ha sido
		!!		transformado en otro personaje mediante una llamada a
		!!		ChangePlayer(nuevo, 1); (sin el 1, la librer�a no intentar�
		!!		mostrar este mensaje).
		!!	4:	Una vez que la librer�a ha mostrado la descripci�n de la
		!!		localidad, si el usuario estaba encima de un supporter, la
		!!		librer�a generar� este mensaje 4 para mostrar qu� m�s cosas
		!!		hay sobre el supporter.
		!!	Restante: 5,6 [6/11] antes 'default'
		!!		Son usados por la librer�a para listar los objetos "simples"
		!!		que hay en la localidad. Son objetos "simples" los que no
		!!		dan su propia auto-descrcipcion a trav�s de la propiedad
		!!		"describe" o "initial".
		!!	7:	Respuesta estandar para MirarHacia [6/11]
		switch (n) {
			1:
				print ", ";
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
			2:
				print ", ";
				!! XXX: Ver comportamiento de Look con n == 1
				if ( x1 provides clarification ) {
					if (x1.clarification ofclass string)
						print (string) x1.clarification;
					else if (x1.clarification ofclass routine)
						indirect( x1.clarification);
				}
				else print ", en ", (the) x1;
			3:
				print " (como ", (object) x1 , ")";
			4:
				print "^Sobre ", (the) x1;
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
				if (x1 ~= location) {
					if (x1 has supporter) print "Sobre ";
					else print "En ";
					print (the) x1, " ";
					if (IsPluralNoun(player)) print "pod�an";
					else print "pod�a";
					print " ver ";
				} else {
					if (IsPluralNoun(player)) print "Pod�an";
					else print "Pod�a";
					print " ver ";
				}
				if (n==5) print "tambi�n ";
				WriteListFrom(child(x1),
					ENGLISH_BIT + WORKFLAG_BIT + RECURSE_BIT
					+ PARTINV_BIT + TERSE_BIT + CONCEAL_BIT);
				".";
			7:
				print "No ";
				if (IsPluralNoun(player)) print "observaron";
				else print "observ�";
				" nada digno de menci�n al mirar hacia ", (the) x1, ".";
			8:
				if (x1 has supporter) print " (sobre "; else print " (en ";
				print (the) x1, ")";
		}

	LookUnder:
		!!	1:	Error, estamos a oscuras.
		!!	2:	�xito, mensaje por defecto.
		switch (n) {
			1:
				"Estaba demasiado oscuro como para poder ver algo.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "vieron";
				else print "vio";
				" nada destacable.";
		}

	Mild:
		!! Respuesta si se usa como primera palabra alg�n insulto suave.
		"Bastante.";

	Miscellany:
		!! Esta es una falsa acci�n, que se usa simplemente para agrupar aqu�
		!! todos los mensajes de error del parser, los mensajes ante algunos
		!! metacommandos, o algnouns mensajes de librer�a no relacionados con
		!! acci�n alguna. La asignaci�n de n�meros a mensajes es bastante
		!! caprichosa.
		switch (n) {
			1:
				!! El usuario ha especificado objetos multiples, pero el parser
				!! tiene una lista que no admite m�s de 16, de modo que los
				!! restantes objetos no ser�n procesados.
				"(S�lo se consideran los diecis�is primeros objetos).";
			2:
				!! El usuario ha usado objetos m�ltiples, pero por alguna raz�n
				!! la lista del parser est� vac�a.
				"[No se pudo determinar a qu� objetos te has referido].";
			3:
				!! Mensaje de fin del relato. Muerte del personaje.
				!! En realidad se trata de un mensaje del parser, pero tiene
				!! su propio formato.
				print " Has perdido ";
			4:
				!! Mensaje de fin del relato. Victoria.
				!! Como el anterior, se trata de un mensaje del parser.
				print " Has ganado ";
			5:
				!! Mensaje a mostrar tras el fin del juego, para pedir al
				!! usuario si quiere reniciar, recuperar, anular, puntuaci�n,
				!! curiosidades o terminar.
				print "^�Quieres REINICIAR, RECUPERAR un juego guardado";
				#IFDEF DEATH_MENTION_UNDO;
					print ", ANULAR tu �ltimo movimiento";
				#ENDIF;
				#IFNDEF NO_PUNTUACION;
					if (TASKS_PROVIDED==0)
						print ", ver la PUNTUACI�N de este juego";
				#ENDIF; ! NO_PUNTUACION
				if (deadflag==2 && AMUSING_PROVIDED==0)
					print ", ver algunas CURIOSIDADES";
				" o TERMINAR?";
			6:
				!! Error si el int�rprete no tiene "undo"
				"[Tu int�rprete no puede @<<DESHACER@>> acciones].";
			7:
				#Ifdef TARGET_ZCODE; ![6/11]
				!! Otro error si el int�rprete no tiene "undo", pero no hab�a
				!! sido detectado correctamente.
				"[@<<DESHACER@>> fall�. (Puede que tu int�rprete no permita
				realizar esa acci�n)].";
				#Ifnot; ! TARGET_GLULX
				"[No puedes @<<DESHACER@>> m�s].";
				#Endif; ! TARGET_
			8:
				!! Si el usuario no responde correctamente a la pregunta del
				!! mensaje [Miscellany,5]
				"[Por favor, introduce una de las respuestas anteriores].";
			9:
				!! TODO - Modificar
				!! Mensaje cuando se detecta, al final del turno, que ya no hay
				!! una fuente de luz en la localidad actual.
				print "^�";
				if (IsPluralNoun(player)) print "Se hab�an";
				else print "Se hab�a";
				" quedado a oscuras!";
			10:
				!! Mensaje cuando el usuario introduce una linea en blanco.
				"[No has introducido ninguna instrucci�n].";
			11:
				!! Si el usuario intenta "undo" al principio del juego
				"[No se puede @<<DESHACER@>> algo que no has hecho].";
			12:
				!! Si el usuario pone "undo" dos veces.
				"[No se puede @<<DESHACER@>> dos veces seguidas].";
			13:
				!! �xito en el "undo".
				"[Retrocediendo al turno anterior].";
			14:
				!! Si el usuario pone EEPA (verbo para corregir), pero el
				!! parser no recordaba ninguna palabra mal. Ejmplo de uso del
				!! comando EEPA:
				!!		> SACA MAZANA VERDE DE LA CESTA
				!!		No vqeo eso por aqu�.
				!!		> EEPA MANZANA
				!!		Sacas la manzana verde de la cesta de mimbre.
				"[Eso no puede corregirse].";
			15:
				!! Se usa EEPA sin especificar la palabra corregida.
				"[Has utilizado @<<EEPA@>> sin especificar qu� palabra deseabas
				corregir].";
			16:
				!! Si el usuario pone EEPA seguido de dos o m�s palabras.
				"[@<<EEPA@>> s�lo puede corregir una palabra].";
			17:
				!! Descripci�n del objeto Oscuridad.
				"Estaba demasiado oscuro como para poder ver algo.";
			18:
				!! Nombre corto del objeto usuario.
				if (IsPluralNoun(player)) print "ell", (o) player;
				else {
					if (IsFemaleNoun(player)) print "ella";
					else print "�l";
				}
				print " mism", (o) player;
			19:
				!! Descripci�n del personaje controlado por el usuario.
				"Tan buen aspecto como siempre.";
			20:
				!! Cuando el usuario pone PNJ, REPITE para que el PNJ haga otra
				!! vez la �ltima acci�n.
				"[Para repetir un comando como @<<PERSONAJE, SALTA@>>, escribe
				@<<REPITE@>>, en lugar de @<<PERSONAJE, REPITE@>>].";
			21:
				!! Cuando el usuario pone REPITE como primer commando del juego.
				"[No hay comando que repetir].";
			22:
				!! El usuario ha comenzado la frase con una coma.
				"[No se puede empezar una frase con una coma].";
			23:
				!! Cuando el usuario pone, por ejemplo; PEPE, COGE HACHA, pero
				!! no hay un objeto que responda al name PEPE.
				"[Parece que has tratado de hablar con alguien, pero no se pudo
				identificar con qui�n].";
			24:
				!! Si el usuario intenta hablar con un objeto que no es
				!! "animate" ni "talkable" ("talkable" debe ponerse a objetos
				!! inanimates con los que se podr�a hablar, como un micr�fono).
				"[No es posible hablar con ", (the) x1, "].";
			25:
				!! Hay palabras no comprendidas entre el nombre de un PNJ y la
				!! coma, ej: PEPE ZAFDSRGG, SALTA.
				"[Para iniciar una conversaci�n, intenta �rdenes del tipo:
				PERSONAJE, HOLA].";
			26:
				!! La gram�tica especifica que una acci�n debe efectuarse sobre
				!! un objeto en poder del usuario (token 'held'), pero el
				!! usuario lo ha intentado sobre un objeto que no tiene, aunque
				!! est� a su alcance. El parser intentar� autom�ticamente coger
				!! ese objeto antes de efectuar la acci�n. En este mensaje se
				!! avisa al usuario de esta intenci�n.
				print "(Primero ";
				if (IsPluralNoun(player)) print "trataron";
				else print "trat�";
				" de ", (coge) "r ", (the) x1, ".)";

			!! ERRORES DE PARSING: Estos errores son generados por la librer�a,
			!! a menos que el programador proporcione su propia funci�n
			!! ParserError para manejo de errores.

			27:
				!! ERROR DE PARSING. El parser se ha atascado. Es el tipo de
				!! error m�s gen�rico. Si el parser puede, se generar� un error
				!! m�s concreto.
				"[No se pudo entender esa instrucci�n.]";

			28:
				!! ERROR DE PARSING. A la instrucci�n le sobraban palabras,
				!! aunque el parser ha entendido gran parte de su significado.
				print "[Intenta de nuevo porque s�lo se pudo entender: @<<";
				PrintCommand();
				print "@>>].^";
				return true;

			29:
				!! ERROR DE PARSING. El parser esperaba un token de tipo
				!! n�mero.
				"[No se pudo comprender ese n�mero].";

			30:
				!! ERROR DE PARSING. El parser no ha comprendido el nombre del
				!! objeto al que se refiere el jugador, o ese objeto no est�
				!! aqu�.
				"[Te has referido a algo con lo que no se puede interactuar en
				este momento].";

			31:
				!! ERROR DE PARSING. Este error parece que no se genera nunca.
				!! Un posible bug de libreria, o restos de versiones arcaicas.
				"[Parece que falta informaci�n en esa instrucci�n].";

			32:
				!! ERROR DE PARSING. El objeto que el usuario intenta usar no
				!! est� en su poder. El parser ha intentado "cogerlo de forma
				!! automatica", pero ha fallado.
				print "No ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" eso.";

			33:
				!! ERROR DE PARSING. El usuario ha intentado usar objetos
				!! m�ltiples (o "TODO") con un verbo que en su gram�tica no lo
				!! admite.
				"[No se pueden especificar objetos m�ltiples con @<<",
				(address) verb_word, "@>>.]";

			34:
				!! ERROR DE PARSING. El usuario ha intentado objetos multiples
				!! para "noun" y para "second", como en METE TODO EN TODO.
				"[S�lo se pueden especificar objetos m�ltiples una vez en cada
				l�nea].";

			35:
				!! ERROR DE PARSING. El usuario ha usado un pronombre, como
				!! COMELO, pero el parser no tiene asignado un valor a ese
				!! pronombre.
				"[No est� claro a qu� te refieres con @<<",
				(address) pronoun_word ,"@>>].";

			36:
				!! ERROR DE PARSING. El usuario ha puesto una lista de objetos
				!! y ha usado la palabra EXCEPTO para exceptuar algo que no
				!! estaba incluido en la lista, por ejemplo: COGE TODAS LAS
				!! MONEDAS EXCEPTO EL SACO.
				"[Has exceptuado algo que no estaba incluido].";

			37:
				!! ERROR DE PARSING. La gram�tica de un verbo obliga a que el
				!! objeto sobre el que se act�e sea animate (tiene un token de
				!! tipo "creature"), pero el usuario lo ha intentado sobre un
				!! objeto que no es animate.
				"[S�lo se puede hacer eso con seres animados].";

			38:
				!! ERROR DE PARSING. La primera palabra usada por el usuario es
				!! desconocida (o la primera palabra tras la coma, si se trata
				!! de una orden a un PNJ).
				print "[La instrucci�n @<<";
				for (i = 0: i < WordLength(1): i++) {
					print (char) WordAddress(1) -> i;
				}
				"@>> no est� definida].";

			39:
				!! ERROR DE PARSING. El usuario intenta actiones sobre las
				!! palabras que est�n en la propiedad "irrelevante" de la
				!! localidad.
				"[No es necesario referirse a eso para terminar la historia].";

			40:
				!! ERROR DE PARSING. El usuario ha usado un pronombre, como
				!! EXAMINALO, pero el pronombre se refiere a un objeto que ya
				!! no est� visible.
				"[Ahora mismo no se puede encontrar lo que representa el
				pronombre @<<", (address) pronoun_word, "@>> (",
				(the) pronoun_obj, ")].";

			41:
				!! ERROR DE PARSING. Este error no se produce nunca.
				!! Probablemente sigue aqu� por razones de compatibilidad, o
				!! por despiste de Graham. �Tal vez ha sido sustituido en
				!! versiones mas recientes por el mensaje n�mero 28?
				"[No se pudo entender la �ltima parte de la instrucci�n].";

			42:
				!! ERROR DE PARSING. El usuario ha solicitado un n�mero de
				!! objetos en una lista de objetos m�ltiples, pero el parser no
				!! es capaz de encontrar tantos. Por ejemplo:
				!! COGE SEIS MONEDAS.
				if (x1==0) "[No hay suficientes].";
		        else if (x1 == 1) {
			    	print "[Aqu� s�lo hay un";
			    	if (multiple_object-->1) print (o) multiple_object-->1;
			    	else print "o";
			    	" disponible].";
			    }
				"[S�lo hay ", (number) lm_o, " disponibles para esa acci�n].";

			43:
				!! ERROR DE PARSING. El usuario ha puesto TODO como objeto
				!! m�ltiple, pero el parser no ha encontrado ning�n objeto. En
				!! realidad este error parece no producirse nunca y el que
				!! acaba gener�ndose siempre es el siguiente
				!! (#44, ASKSCOPE_PE).
				"[No se puede encontrar nada con lo que hacer eso].";

			44:
				!! El usuario ha intentado objetos m�ltiples usando TODO
				!! pero el parser no ha encontrado ninguno. Por ejemplo, COGE
				!! TODO o DEJA TODO si no hay nada cerca o en el inventario.
				!! Modificado en [020621] para dar un mensaje m�s coherente
				!! si el usuario tiene alg�n objeto en su inventario.
				if (action_to_be == ##Drop) {
					print "[No ";
					if (IsPluralNoun(player)) print "ten�an";
					else print "ten�a";
					print " nada que ";
					LanguageVerb(verb_word);
					"].";
				} else {
					print "[No hab�a nada que ";
					LanguageVerb(verb_word);
					"].";
				}
			45:
				!! El usuario ha nombrado un PNJ ambiguo (hay m�s de noun con
				!! el mismo name cerca). El parser le pide aclaraci�n. Este
				!! mensaje es la primera parte de la pregunta, el resto lo pone
				!! el parser (que es la lista de PNJs entre los que duda).
				!! Debemos poner a 1 la variable PreguntaCualExactamente cuando
				!! se generan este tipo de preguntas aclaratorias.
				print "[�Qui�n concretamente: ";
				PreguntaCualExactamente=1;
				ImprimirListaDudosos("o");
			46:
				!! El usuario ha nombrado un objeto ambiguo (hay m�s de objeto
				!! con el mismo nombre cerca). El parser le pide aclaraci�n.
				!! Este mensaje es la primera parte de la pregunta, el resto lo
				!! pone el parser (que es la lista de objetos entre los que
				!! duda). Debemos poner a 1 la variable PreguntaCualExactamente
				!! cuando se generan este tipo de preguntas aclaratorias.
				print "[�Cu�l concretamente: ";
				PreguntaCualExactamente=1;
				ImprimirListaDudosos("o");
			47:
				!! El usuario ha respondido "TODOS" o "AMBOS" a una pregunta
				!! aclaratoria como la anterior, pero el verbo no admite
				!! objetos m�ltiples.
				print "[Desafortunadamente s�lo puedes referirte a un objeto
				en este caso. �Cu�l exactamente?]^";
				PreguntaCualExactamente=1;
			48:
				!! El usuario ha escrito una frase u orden a PSI incompleta,
				!! como BESA (verbo aplicado sobre PSIs normalmente). El parser
				!! le pregunta para que complete la frase.
				PreguntaCualExactamente = 1;
				print "[";
				if (IniciarPregunta() == 0) print "A qui�n";
				if (actor ~= player) print " tiene que ";
				else print " quieres ";
				IdiomaImprimirComando();
				if (actor ~= player) print " ", (the) actor;
				print "?]";
				new_line;
			49:
				!! FIXME - �Qu� quieres comerse?
				!! El usuario ha escrito una frase u orden incompleta, como
				!! COGE (verbo aplicado sobre objetos normalmente). El parser
				!! le pregunta para que complete la frase.
				PreguntaCualExactamente = 1;
				print "[";
				if (IniciarPregunta() == 0) print "Qu�";
				if (actor ~= player) print " tiene que ";
				else print " quieres ";
				IdiomaImprimirComando();
				if (actor ~= player) print " ", (the) actor;
				print "?]";
				new_line;
			!#IFNDEF NO_PUNTUACION;
			50:
				!! El usuario acaba de realizar una acci�n que punt�a (la
				!! librer�a ha detectado que la variable score ha cambiado de
				!! valor). Se informa de ello al player. El par�metro x1
				!! contiene el incremento (o decremento) en la puntuaci�n.
				print "[Tu puntuaci�n ha ";
				if (x1 > 0) print "aumentado";
				else {
					x1 = -x1;
					print "disminuido";
				}
				print " en ", (number) x1, " punto";
				if (x1 > 1) print "s";
			!#ENDIF; ! NO_PUNTUACION
			51:
				!! El usuario ha intentado una acci�n con objeto m�ltiple
				!! (como COGE TODO). Esta acci�n es convertida por el parser en
				!! una serie de actiones COGE OBJETO1, COGE OBJETO2, etc... Si
				!! en la ejecuci�n de alguna de estas actiones encuentra que la
				!! localidad del player ha cambiado, debe abortar el proceso.
				!! Este mensaje informa de ello al usuario.
				"(Se ha producido un evento inesperado que ha obligado a
				recortar la lista de objetos sobre los que actuabas).";
			52:
				!! En los men�s, se espera a que el player escriba un n�mero
				!! para mostrar una entrada del men�. Si pulsa un numero
				!! incorrecto, se saca este mensaje. El par�metro x1 contiene
				!! el n�mero m�s alto v�lido.
				new_line;
				print "[Escribe un n�mero del 1 al ", x1, ", 0 para volver a
				mostrarlo, o pulsa Intro].";
				new_line;
				return true;
			53:
				!! Mensaje que muestra el sistema de men�s cuando espera una
				!! tecla.
				new_line;
				"[Por favor, pulsa ESPACIO].";
			54:
				! TODO - Guardar comentarios sin imprimir mensajes
				"[Comentario guardado].";
			55:
				"[Comentario NO guardado].";
			56:
				print "].^";
			57:
				print "?]^";
		}

	No:
		!! Cuando el usuario pone NO, a secas, se genera esta acci�n. Est�
		!! pensada por si el relato suelta una frase del estilo de "�Pero t�
		!! eres tonto?" y el usuario responde NO. De todas formas, hay un
		!! problema, y es que NO es normalmente la acci�n Ir al noroeste. Si
		!! queremos que NO sea provisionalmente la acci�n No, entonces se debe
		!! poner a 1 la variable PreguntaSiNo antes de escribir el texto
		!! "�Pero t� eres tonto?". En ese caso, el parser interpretar� "NO"
		!! como la acci�n No, pero �nicamente durante el siguiente turno.
		"[S�lo se trataba de una pregunta ret�rica].";

	NotifyOff:
		"[Notificaci�n de puntuaci�n desactivada].";

	Objects:
		! TODO - mensaje del parser
		!! Ante el verbo "OBJETOS" se genera esta acci�n, que muestra una
		!! lista de todos los objetos que el usuario ha manipulado a lo largo
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
			1:
				print "[Objectos que has manejado:]^";
			2:
				"Ninguno.";
			3:
				print "   (puest", (o) x1, ")";
			4:
				print "   (", (contigo) player, ")";
			5:
				print "   (dejad", (o) x1, " con alguien)";
			6:
				print "   (entonces en ", (name) x1, ")";
			7:
				print "   (entonces en ", (the) x1, ")";
			8:
				print "   (entonces dentro ", (del) x1, ")";
			9:
				print "   (entonces en ", (the) x1, ")";
			10:
				print "   (perdid", (o) x1, ")";
		}

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
			1:
				"No era algo que se pudiese abrir.";
			2:
				"Estaba", (n) x1, " cerrad", (o) x1, " con llave.";
			3:
				"Ya estaba", (n) x1, " abiert", (o) x1, ".";
			4:
				if (IsPluralNoun(player)) print "Abrieron";
				else print "Abri�";
				print " ", (the) x1, ", descubriendo ";
				if (WriteListFrom(child(x1),
					ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT) == 0) {
					print "que estaba", (n) x1, " vac�", (o) x1;
				}
				".";
			5:
				if (IsPluralNoun(player)) print "Abrieron";
				else print "Abri�";
				" ", (the) x1, ".";
		}

	Order:
		"", (The) x1, " ten�a", (n) x1, " mejores cosas que hacer.";

	Places:
		!! FIXME - Introducir flexiones
		!! El verbo "LUGARES" muestra un listado de los lugares que el usuario
		!! ha visitado. Aqu� debemos escribir el texto introductorio a esa
		!! lista.
		switch (n) {
			1:  print "[Has visitado: ";
			2:  print "].^";
		}

	Pray:
		"La fe tal vez pudiese resultar �til en una ocasi�n diferente.";

	Prompt:
		!! El prompt aparece justo antes de pedir una nueva l�nea al usuario.
		!! Puede definirse para que sea una frase, o se genere una frase
		!! aleatoria en cada turno, por ejemplo.
		new_line;
		print "> ";

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
			1:
				print "[En este momento, ";
			2:
				print "es ";
			3:
				print "no est� definido";
			4:
				print "el juego no conoce ning�n pronombre].";
				new_line;
				return true;
			5:
				print "].";
				new_line;
				return true;
		}

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
			1:
				"Estaba", (n) x1, " firmemente sujet", (o) x1, ".";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "fueron capaces";
				else print "fue capaz";
				".";
			3:
				"No ocurri� nada, aparentemente.";
			4:
				"Aquello hubiese sido, como poco, maleducado.";
		}

!!	Push:	see Pull.

	PushDir:
		!! La acci�n PushDir se genera ante frases como EMPUJA EL COCHE HACIA
		!! EL NORTE. Hay 3 casos posibles:
		!!	1:	Si el juego no ha previsto la posibilidad de empujar ese
		!!		objeto hacia una direcci�n (o sea, no llama a la rutina
		!!		PermitirEmujarDir). Esta es la respuesta por defecto m�s
		!!		habitual.
		!!	2:	Si el usuario pone tras HACIA algo que no es una direcci�n.
		!!		(respuesta por defecto en este caso).
		!!	3:	Si intenta empujar hacia arriba o hacia abajo.
		switch (n) {
			1:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�an";
				else print "cre�a";
				" que empujar", (lo) x1, " hubiese servido de nada.";
			2:
				"Aquello no era una direcci�n.";
			3:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" empujar", (lo) x1, " en esa direcci�n.";
		}

	PutOn:
		!!	1:	Error, el objeto no est� en poder del usuario. [Nota, conviene
		!!		mirar en este caso si el objeto es animado o no, para generar
		!!		un mensaje m�s adecuado].
		!!	2:	Error, el usuario intenta poner un objeto sobre s� mismo.
		!!	3:	Error, el usuario intenta poner el objeto sobre otro que no
		!!		tiene el atributo "supporter".
		!!	4:	Error, el usuario intenta poner un objeto sobre el propio
		!!		usuario.
		!!	5:	Aviso, el objeto es una prenda puesta. La librer�a va a
		!!		quit�rselo autom�ticamente antes de reintentar la acci�n PutOn.
		!!	6:	Error, se intenta poner el objeto sobre otro en el que ya no
		!!		queda sitio (el n�mero de objetos que caben en el soporte se
		!!		indica en su propiedad "capacity").
		!!	7:	Exito. Mensaje a mostrar para cada objeto puesto cuando se
		!!		ponen muchos (ej: PON TODO SOBRE LA MESA).
		!!	8:	Exito. Mensaje a mostrar cuando se pone un objeto sobre otro.
		switch (n) {
			1:
				if (x1 has animate) {
					if (IsPluralNoun(player))
						"Antes ten�an que ", (coge)"r", (lo) x1,
						" y no sab�an si se hubiese", (n) x1,
						" dejado.";
					else
						"Antes ten�a que ", (coge)"r", (lo) x1,
						" y no sab�a si se hubiese", (n) x1, " dejado.";
				} else {
					if (IsPluralNoun(player)) print "Necesitaban";
					else print "Necesitaba";
					" tener ", (the) x1, " para poder poner", (lo) x1,
					" donde fuese.";
				}
			2:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" poner un objeto sobre s� mismo.";
			3:
				"Poner cosas sobre ", (the) x1, " no hubiese servido de nada.";
			4:
				if (IsPluralNoun(player)) print "Les faltaba";
				else print "Le faltaba";
				" destreza.";
			5:
				print "(Primero ";
				if (IsPluralNoun(player)) print "se ", (lo) x1, " quitaron";
				else print "se ", (lo) x1, " quit�";
				").^";
			6:
				"No quedaba sitio en ", (the) x1, " para poner nada m�s.";
			7:
				"Hecho.";
			8:
				if (IsPluralNoun(player)) print "Colocaron";
				else print "Coloc�";
				" ", (the) x1, " sobre ", (the) second, ".";
		}

	Quit:
		!!	1:	Respuesta al comando FIN.
		!!	2:	Respuesta si el usuario escribe algo distinto de "si" o "no".
		switch (n) {
			1:
				print "[Por favor, responde @<<SI@>> o @<<NO@>>]: ";
			2:
				print "[�Realmente quieres abandonar el relato?] ";
		}
		return true;

	Remove:
		!!	1:	El recipiente que contiene el objeto que el usuario quiere
		!!		sacar, est� cerrado. (x1 apunta al objeto, no al recipiente,
		!!		el cu�l puede obtenerse con parent(x1)).
		!!	2:	El objeto no est� dentro del recipiente que el usuario ha dicho.
		!!	3:	�xito.
		switch (n) {
			1:	!! TODO - modificar
				"Por desgracia ", (the) parent(x1), " estaba", (n) parent(x1),
				" cerrad", (o) parent(x1), ".";
			2:	!! TODO - Modificar
				if (second has animate)
					"�Pero si no ", (lo) x1, " ten�a", (n) second, "!";
				else
					"�Pero si no estaba", (n) x1, " ah� en aquel momento!";
			3:
				if (verb_word == 'quita') "Quitad", (o) x1, ".";
				"Sacad", (o) x1, ".";
		}

	Restart:
		!!	1:	Respuesta al comando REINICIAR.
		!!	2:	Si no se puede reiniciar.
		switch (n) {
			1:
				print "[�Realmente quieres reiniciar el relato?] ";
			2:
				"[Error al reiniciar la partida].";
		}

	Restore:
		!!	1:	Si no se pudo cargar la partida con LOAD.
		!!	2:	�xito (no llega a mostrarse, porque en caso de �xito el estado
		!!		del juego cambia al momento en que se salv�. El "Ok" que se ve
		!!		entonces es el del comando Salvar.
		switch (n) {
			1:
				"[Error. No se pudo recuperar la partida].";
			2:
				print "[Partida cargada].^";
				new_line;
				<<Look>>;
		}

	Rub:
		"Ya estaba", (n) x1, " bastante limpi", (o) x1, ".";

	Save:
		!!	1:	Si no se pudo guardar el juego.
		!!	2:	�xito.
		switch (n) {
			1:
				"[Error. No se pudo guardar la partida].";
			2:
				"[Partida guardada].";
		}

	Score:
		!! TODO - Mensaje del parser
		!! Puntuaci�n del juego. Puede activarse porque el usuario lo pide
		!! (con el verbo "PUNTUACION") o porque el juego ha terminado. En
		!! este ultimo caso, la variable "deadflag" valdr� true.
		switch (n) {
			1:
				if (deadflag)
					print "En esta ficci�n interactiva, tu puntuaci�n ha
					sido ";
				else
					print "Hasta el momento tu puntuaci�n es ";
				print score, " de un total de ", MAX_SCORE,
				", en ", turns, " turno";
				if (turns == 0 || turns >1) print "s";
				return;
			2:
				"[Esta ficci�n interactiva no tiene conteo de puntuaci�n].";
		}

	ScriptOff:
		!!	1:	Error ya estaba desactivada la transcrcipci�n.
		!!	2:	�xito.
		switch (n) {
			1:
				"[La transcripci�n ya estaba desactivada].";
			2:
				new_line;
				"[Fin de la transcripci�n].";
			3:
				"[Error al intentar finalizar la transcripci�n].";
		}

	ScriptOn:
		!!	1:	Error, ya estaba activada la transcrcipci�n.
		!!	2:	�xito (parte inicial del mensaje, la librer�a imprime a
		!!		continuaci�n un 'Banner' con los cr�ditos de la aplicaci�n.
		switch (n) {
			1:
				"[La transcripci�n ya estaba activada].";
			2:
				"[Iniciando transcripci�n...]";
			3:
				"[Error al intentar iniciar la transcripci�n].";
		}

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
			1:
				"Estaba demasiado oscuro como para poder ver algo.";
			2:
				"No hab�a nada sobre ", (the) x1, ".";
			3:
				!! TODO - error de Spanish.h?
				print "Sobre ", (the) x1;
				WriteListFrom(child(x1),
					ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT + ISARE_BIT);
				".";
			4:
				print "No ";
				if (IsPluralNoun(player)) print "encontraron";
				else print "encontr�";
				" nada interesante.";
			5:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an";
				else print "pod�a";
				" ver lo que hab�a dentro ", (del) x1, " porque
				estaba", (n) x1, " cerrad", (o) x1, ".";
			6:
				"", (The) x1, " estaba", (n) x1, " vac�", (o) x1, ".";
			7:
				!! TODO - error de Spanish.h?
				print "En ", (the) x1;
				WriteListFrom(child(x1),
					TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
				".";
		}

	Set:
		!! Set sale ante la frase FIJA OBJETO o AJUSTA OBJETO
		print "No, no ";
		if (IsPluralNoun(player)) print "pod�an";
		else print "pod�a";
 		".";

	SetTo:
		!! SetTo sale ante la frase AJUSTA DIAL A 23 o FIJA CONTROL EN
		!! ACTIVADO, o PON REGULADOR A 30
		"Aquello no pod�a regularse a ning�n valor.";

	Show:
		!!	1:	Error, el usuario intenta mostrar un objeto que no tiene.
		!!	2:	Aviso, se ha enviado la acci�n Show al PNJ, pero este no ha
		!!		respondido. En este caso x1 apunta al PNJ y no al objeto que
		!!		le hemos mostrado.
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" ", (the) x1, ".";
			2:
				"", (The) x1, " no mostraba", (n) x1, " ning�n inter�s.";
		}

	Sing: !! TODO - Modificar
		if (IsPluralNoun(player)) print "Cantaban";
		else print "Cantaba";
		" fatal.";

	Sleep:
		print "No ";
		if (IsPluralNoun(player)) print "estaban";
		else print "estaba";
		" especialmente somnolient", (o) player, ".";

	Smell:
		print "No ";
		if (IsPluralNoun(player)) print "ol�an";
		else print "ol�a";
		" nada extra�o.";

	Sorry:
		!! Esta acci�n se genera si el usuario introduce "LO SIENTO",
		!! "PERDONA" o cosas similares.
		"[No es necesario que te disculpes].";

	Squeeze:
		!!	1:	Tratar de retorcer un ser animado.
		!!	2:	Cualquier otro objeto.
		switch (n) {
			1:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "se les hubiese ocurrido";
				else print "se le hubiese ocurrido";
				" hacer algo as�.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "consiguieron";
				else print "consigui�";
				" nada haciendo eso.";
		}

	Strong:
		!! Respuesta si se usa como primera palabra alg�n taco.
		"[No sirve de nada utilizar ese vocabulario].";

	Swim:
		"No era el momento ni el lugar para ponerse a nadar.";

	Swing:
		print "No parec�a", (n) x1, " el lugar m�s adecuado en el que ";
		if (IsPluralNoun(player)) print "columpiarse";
		else print "columpiarse";
		".";

	SwitchOff:
		!!	1:	Error, el objeto no tiene el atributo "switchable".
		!!	2:	Error, el objeto ya tenia desactivado el atributo "on".
		!!	3:	�xito, el objeto tiene ahora desactivado "on".
		switch (n) {
			1:
				"No era algo que se pudiese apagar.";
			2:
				"Ya estaba", (n) x1, "apagad", (o) x1, ".";
			3:
				if (IsPluralNoun(player)) print "Apagaron";
				else print "Apag�";
				" ", (the) x1, ".";
		}

	SwitchOn:
		!! Generada al intentar ENCIENDE OBJETO si el objeto tiene el
		!! atributo "conmutable". Observar que si no lo tiene, la acci�n
		!! que se genera ser� sin embargo Quemar.
		!!	1:	Error, el objeto no es conmutable (este error no aparecer�
		!!		si el usuario pone ENCIENDE OBJETO, ya que en este caso la
		!!		acci�n generada ser� Quemar objeto, pero puede aparecer si
		!!		pone CONECTA OBJETO).
		!!	2:	Error, el objeto ya ten�a el atributo "on".
		!!	3:	�xito, el objeto tiene ahora activado "on".
		switch (n) {
			1:
				"No era algo que se pudiese encender.";
			2:
				"Ya estaba", (n) x1, " encendid", (o) x1, ".";
			3:
				if (IsPluralNoun(player)) print "Encendieron";
				else print "Encendi�";
				" ", (the) x1, ".";
		}

	Take:
		!! Hay 13 casos diferentes. Se trata de 1 mensaje de �xito y 11
		!! mensajes de error y un aviso:
		!!	1:	�xito.
		!!	2:	Error, el objeto cogido es el propio usuario.
		!!	3:	Error, el objeto cogido es un objeto animado.
		!!	4:	Error, el usuario est� subido o metido en el objeto que intenta
		!!		coger.
		!!	5:	Error, el usuario ya ten�a ese objeto en su inventario.
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
		!!	12:	Error, el usuario lleva demasiados objetos.
		!!	13: Mensaje de aviso, la librer�a ha decidido mover objetos del
		!!		inventario al "objeto saco" para hacer sitio y que el usuario
		!!		pueda coger el objeto. [El objeto saco es uno que puede
		!!		declarar el programador. Si el usuario lo coge y lo lleva
		!!		consigo, la librer�a lo usar� autom�ticamente como mochila
		!!		para descargar al usuario cuando sea necesario].
		switch (n) {
			1:
				if (dialecto_sudamericano) print "Tomad";
				else print "Cogid";
				"", (o) noun, ".";
			2:
				print "Siempre ";
				if (IsPluralNoun(player)) print "se ten�an";
				else print "se ten�a";
 				" a ", (string) YOURSELF__TX, ".";
			3:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�an";
				else print "cre�a";
				" que ", (al) x1, " le", (s) x1, " hubiese gustado.";
			4:
				if (IsPluralNoun(player)) print "Ten�an";
				else print "Ten�a";
				print " que ";
				if (x1 has supporter) {
					if (IsPluralNoun(player)) print "bajarse";
					else print "bajarse";
				}
				else print "salir";
				"", (del) x1, " antes.";
			5:
				print "Ya ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" ", (the) x1, ".";
			6:
				"Parec�a", (n) noun, " pertenecer ", (al) x1, ".";
			7:
				"Parec�a", (n) noun, " formar parte ", (del) x1, ".";
			8:
				"No estaba", (n) x1, " disponible", (s) x1, ".";
			9:
				"", (The) x1, " no estaba", (n) x1, " abiert", (o) x1, ".";
			10:
				print "Dif�cilmente ";
				if (IsPluralNoun(player)) print "hubiesen podido llevarse";
				else print "hubiese podido llevarse";
				" aquello.";
			11:
				"", (The) x1, "estaba", (n) x1, " fij", (o) x1,
				" en el sitio.";
			12:
				print "Ya ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" las manos ocupadas con demasiadas cosas.";
			13:
				print "(Primero ";
				if (IsPluralNoun(player)) print "colocaron";
				else print "coloc�";
				" ", (the) x1, " en ", (the) SACK_OBJECT,
				" para hacer sitio).";
		}

	Taste:
		print "No ";
		if (IsPluralNoun(player)) print "saborearon";
		else print "sabore�";
		" nada inesperado.";

	Tell:
		!!	1:	El usuario habla consigo mismo.
		!!	2:	Hablar con cualquier otro ser animado.
		!! [Nota: Hablar con un objeto inanimado no est� permitido por el
		!! parser, que da un error y no llega a generar la acci�n.]
		!! [Los errores de parser se tratan en la secci�n "Miscel�nea" de
		!! esta rutina, al final.]
		switch (n) {
			1:
				if (IsPluralNoun(player)) print "Hablaron";
				else print "Habl�";
				" sol", (o) player, " durante un rato.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "provocaron";
				else print "provoc�";
				" ninguna reacci�n.";
		}

	Think: !! TODO - Modificar
		print "Si, eso ";
		if (IsPluralNoun(player)) print "intentaban";
		else print "intentaba";
		".";

	ThrowAt:
		!!  1:	Lanzar cosas a objetos inanimados.
		!!	2:	Lanzar cosas a objetos animados.
		switch (n) {
			1:
				"No hubiese servido de nada.";
			2:
				print "En el �ltimo momento ";
				if (IsPluralNoun(player)) print "se echaron";
				else print "se ech�";
				" atr�s.";
		}

!!	Tie: see JumpOver

	Touch:
		!!	1:	Si se intenta tocar a un ser animado.
		!!	2:	Tocar un objeto normal del juego.
		!!	3:	Tocarse a si mismo.
		switch (n) {
			1:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�an";
				else print "cre�a";
				" que ", (al) x1, " le", (s) x1, " hubiese gustado.";
			2:
				print "No ";
				if (IsPluralNoun(player)) print "notaron";
				else print "not�";
				" nada extra�o al tacto.";
			3:
				print "En realidad no ";
				if (IsPluralNoun(player)) print "cre�an";
				else print "cre�a";
				" que algo as� hubiese servido de nada.";
    	}

!!	Turn:	see Pull

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
		!!		especificado, el cual podemos encontrarlo en la variable
		!!		"otro".
		switch (n) {
			1:
				"No parec�a", (n) x1, " tener ning�n tipo de cerrojo.";
			2:
				"", (The) x1, " ya ten�a", (n) x1, " abierto el cerrojo.";
			3:
				if (second) {
					"No parec�a", (n) x1, " encajar en la cerradura.";
				} else {
					if (IsPluralNoun(player)) print "Necesitaban";
					else print "Necesitaba";
					" alg�n tipo de llave.";
				}
			4:
				if (IsPluralNoun(player)) print "Quitaron";
				else print "Quit�";
				print " el cerrojo ", (al) x1;
				if (second) print " con ", (the) second;
				".";
		}

	VagueGo:
		!! El usuario ha dicho IR sin especificar a d�nde
		"[Tienes que especificar en qu� direcci�n ir].";

	Verify:
		!!	1:	�xito.
		!!	2:	Error en la verificaci�n.
		switch (n) {
			1:
				"[Fichero de la partida verificado e intacto].";
			2:
				"[El fichero de la partida no parece intacto. Puede estar
				corrompido (a menos que est�s utilizando un int�rprete muy
				b�sico que no sea capaz de realizar la comprobaci�n)].";
		}

	Wait:
		"Pasaba el tiempo...";

	Wake: !! TODO - Modificar
		"La cruda realidad es que aquello no era un sue�o.";

	WakeOther:
		"No parec�a necesario hacer aquello.";

	Wave:
		!!	1:	Si se intenta agitar un objeto que no est� en el inventario.
		!!	2:	Si se agita un objeto que s� est� en el inventario.
		switch (n) {
			1:
				print "No l", (o) x1, " ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
				" ", (contigo) player, ".";
			2:
				if (IsPluralNoun(player)) print "Se sent�an";
				else print "Se sent�a";
				" rid�cul", (o) player, " agitando ", (the) x1, ".";
		}

	WaveHands:
		!! La acci�n WaveHands se genera ante las frases "gesticula", "agita la
		!! mano", "sacude la mano", "saluda con la mano", etc.
		if (IsPluralNoun(player)) print "Se encontraban";
		else print "Se encontraba";
		" rid�cul", (o) player, " gesticulando as�.";

	Wear:
		!! 1: Error, el objeto no tiene el atributo "clothing".
		!! 2: Error, el usuario no tiene el objeto.
		!! 3: Error, el objeto ya tiene el atributo "worn".
		!! 4: �xito.
		switch (n) {
			1:
				print "No ";
				if (IsPluralNoun(player)) print "pod�an ponerse";
				else print "pod�a ponerse";
				" aquello.";
			2:
				print "No ", (lo) x1, " ";
				if (IsPluralNoun(player)) print "ten�an";
				else print "ten�a";
 				".";
			3:
				print "Ya ", (lo) x1;
				if (IsPluralNoun(player)) print "llevaban";
				else print "llevaba";
				" puest", (o) x1, ".";
			4:
				if (IsPluralNoun(player)) print "Se pusieron";
				else print "Se puso";
				" ", (the) x1, ".";
		}

	Yes:
		"[La instrucci�n @<<S�@>> no tiene sentido en esta situaci�n].";

];
