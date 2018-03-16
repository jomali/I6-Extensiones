

!!==============================================================================
!!
!!	RECEPTACLES
!!	Contenedores con l�mites de capacidad
!!
!!==============================================================================
!!
!!	Archivo:		receptacles.h
!!	Autor(es):		Peer Schaefer <peer@wolldingwacht.de> (lib. recept.h)
!!					J. Francisco Mart�n <jfm.lisaso@gmail.com> (traducci�n)
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Platforma:		M�quina-Z / GLULX
!!	Versi�n:		2.X FIXME
!!	Fecha:			2018/03/08
!!	Notes:			Las funciones pueden no comportarse como se espera si se
!!					utiliza una versi�n del compilador Inform igual o anterior
!!					a la 6.15.
!!
!!------------------------------------------------------------------------------
!!
!!	Copyright (c) 2002, 2006, Peer Schaefer
!!	Copyright (c) 2012, 2014, J. Francisco Mart�n
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
!!	X.X: 2018/03/08 Refactorizaci�n de la extensi�n.
!!					Actualizaci�n de la documentaci�n.
!!	2.1: 2014/02/06	Traducci�n completa de la documentaci�n.
!!	2.0: 2012/05/03	Correcciones y creaci�n de la propiedad error_messages
!!					sobre la clase Receptacle para separar la l�gica y los
!!					mensajes.
!!	1.0				Traducci�n de la librer�a original recept.h v1.0 de Peer
!!					Schaefer, para implementar contenedores con capacidades
!!					definidas.
!!
!!------------------------------------------------------------------------------
!!
!!	INTRODUCCI�N
!!
!!	La extensi�n 'receptacles.h' implementa una nueva clase de objeto llamada
!!	'Receptacle', que permite definir contenedores o soportes en el mundo de
!!	juego con un comportamiento m�s complejo que el contemplado por defecto por
!!	la librer�a Inform. Los contenedores/soportes 'Receptacle' incluyen l�mites
!!	de capacidad de peso, volumen y tama�o, adem�s del l�mite de n�mero de
!!	objetos definido ya por la librer�a, de forma que cada vez que se intenta
!!	colocar un objeto dentro de un 'Receptacle' se comprueba antes si tiene
!!	capacidad suficiente para el nuevo objeto y muestra un mensaje de error
!!	adecuado si no es as�.
!!
!!	'receptacles.h' se basa en la extensi�n 'recept.h' de Peer Schaefer.
!!
!!
!!	INSTALACI�N
!!
!!	Para utilizar la extensi�n hay que a�adir la siguiente l�nea en el fichero
!!	principal de la obra, entre las l�neas 'Include "Parser";' y
!!	'Include "VerbLib";':
!!
!!		Include "receptacles";
!!
!!
!!	NUEVAS PROPIEDADES USADAS POR LA EXTENSI�N
!!
!!	Peso, volumen y tama�o
!!
!!	Para que los nuevos l�mites de capacidad de peso, volumen y tama�o de los
!!	contenedores 'Receptacle' tengan sentido, se hace necesario definir objetos
!!	con nuevas propiedades de peso, volumen y tama�o. A continuaci�n es hace
!!	una relaci�n de estas nuevas propiedades utilizadas por la extensi�n (se
!!	tratan de propiedades OPCIONALES; el autor es libre de implementarlas o
!!	no):
!!
!!	<>	'weight': Peso del objeto. (Cuando se intenta introducir un objeto con
!!		peso en un contenedor con l�mite de peso, se comprueba si el peso
!!		agregado de todos los elementos ya contenidos en el 'Receptacle' m�s el
!!		peso del nuevo objeto superan el l�mite).
!!	<>	'volume': Volumen del objeto. (Cuando se intenta introducir un objeto
!!		con volumen en un contenedor con l�mite de volumen, igual que ocurre
!!		con el peso, se comprueba si el volumen agregado de todos los elementos
!!		m�s el volumen del nuevo objeto superan el l�mite del contenedor).
!!	<>	'size': Longitud m�xima del objeto en cualquiera de sus ejes. Por
!!		ejemplo, la longitud de una flecha o de un bast�n. (Cuando se intenta
!!		introducir un objeto con tama�o definido en un contenedor con l�mite de
!!		tama�o, se comprueba si el l�mite es suficiente como para aceptar el
!!		tama�o del objeto.)
!!
!!	Cada una de estas tres propiedades puede ser un valor num�rico o una rutina
!!	que retorne un valor num�rico. Si el autor no define alguna de estas
!!	propiedades o tiene el valor cero, la extensi�n interpreta que esa
!!	caracter�stica del objeto es 0 ---se entiende as� que el objeto carece de
!!	peso, volumen o tama�o, o que se trata de una medida despreciables---.
!!
!!	Las tres nuevas propiedades 'weight', 'volume' y 'size', se miden en
!!	unidades abstractas. Si la unidad se refiere, por ejemplo, a un gramo, una
!!	libra, una tonelada, o la masa del sol, es decisi�n libre del programador.
!!
!!	L�mites de capacidad:
!!
!!	Para crear un contenedor que compruebe autom�ticamente si tiene capacidad
!!	de peso, volumen o tama�o suficientes para los objetos que se intenta
!!	introducir en �l, se definen otras tres nuevas propiedades opcionales:
!!
!!	<>	'capacity_weight': Peso total que puede soportar el contenedor.
!!	<>	'capcity_volume': Volumen total que puede almacenar.
!!	<>	'capacity_size': Tama�o m�ximo del contenedor. Cualquier objeto con un
!!		tama�o superior simplemente no cabr�a.
!!
!!	Cada una de estas tres propiedades, de nuevo, puede ser un valor num�rico o
!!	una rutina que retorne un valor num�rico. Si alguna de estas propiedades no
!!	est� definida o tiene el valor 'INFINITE_CAPACITY' (una constante
!!	predefinida por la extensi�n), la capacidad respectiva para esa medida del
!!	recept�culo se considerar� infinita.
!!
!!	Desde luego, los contenedores/soportes 'Receptacle' pueden tener tambi�n
!!	definidas propiedades de peso, volumen y tama�o, ya que no se tratan s�lo
!!	de contenedores si no tambi�n de objetos que pueden ser colocados a su vez
!!	dentro de otros contenedores.
!!
!!	Resumen sobre las nuevas propiedades:
!!
!!	<>	Pueden almacenarse m�ltiples objetos con peso en un 'Receptacle',
!!		siempre que el peso total ('weight' agregado de todos ellos) no exceda
!!		el l�mite 'capacity_weight' del contenedor. Es decir, 'capacity_weight'
!!		se va "agotando" conforme se a�ade peso al contenedor.
!!	<>	Pueden almacenarse m�ltiples objetos con volumen en un 'Receptacle',
!!		siempre que el volumen total ('volume' agregado de todos ellos) no
!!		exceda el l�mite 'capacity_volume' del contenedor. Es decir,
!!		'capacity_volume' se va "agotando" conforme se a�ade volumen al
!!		contenedor.
!!	<>	Pueden almacenarse m�ltiples objetos con tama�o en un 'Receptacle',
!!		siempre que sean m�s peque�os que el l�mite 'capacity_size' del
!!		contenedor (size < capacity_size). Es decir, la capacidad del
!!		contenedor no se va "agotando" conforme se a�aden objetos.
!!
!!	Adem�s, como habitualmente, los contenedores/soportes 'Receptacle' pueden
!!	definir tambi�n la propiedad 'capacity' contemplada por defecto por la
!!	librer�a Inform. Esta propiedad indica cu�ntos objetos (como m�ximo) se
!!	pueden almacenar dentro del contenedor.
!!
!!
!!	DETALLES T�CNICOS
!!
!!	A continuaci�n se ofrecen algunas apreciaciones que deben tenerse en cuenta
!!	a la hora de utilizar la extensi�n:
!!
!!	<>	Calcular el peso de un contenedor/soporte 'Receptacle' es un proceso
!!		recursivo; los pesos de todos los objetos contenidos inmediatamente en
!!		�l se a�aden al peso del propio contenedor/soporte. Si �ste se
!!		encuentra a su vez en otro contenedor/soporte, su peso total se a�ade
!!		al de �ste, junto con el resto de objetos tambi�n contenidos (y as�
!!		sucesivamente).
!!	<>	Si el peso de un objeto viene dado por una rutina, esta rutina debe
!!		devolver EL PESO TOTAL del objeto, incluyendo los pesos de todos los
!!		objetos que alberga directa e indirectamente en �l. En este caso, los
!!		pesos de los objetos contenidos en el contenedor NO se calculan
!!		autom�ticamente. Esto a�ade flexibilidad a la hora de crear
!!		contenedores especiales (como por ejemplo una bolsa m�gica cuyo peso
!!		sea menor al de los pesos de los objetos que contenga en su interior).
!!	<>	El volumen y los tama�os de los objetos que alberga un
!!		contendor/soporte 'Receptacle' NO se a�aden al volumen o tama�o del
!!		'Receptacle' (se asume que un contenedor est�ndar no es flexible y que
!!		tiene unas proporciones fijas y predeterminadas). Para reescribir este
!!		comportamiento se pueden definir nuevas propiedades VOLUME y SIZE, de
!!		forma que calculen el volumen y tama�o del recept�culo en tiempo de
!!		ejecuci�n.
!!	<>	Es perfectamente posible crear un contenedor/soporte cuya capacidad sea
!!		superior a sus propias medidas (un comportamiento altamente improbable
!!		en un objeto, pero que permite la creaci�n de cajas m�gicas, agujeros
!!		negros y otros objetos extra�os).
!!
!!
!!	VERBOS DE DEPURACI�N
!!
!!	Al compilar en modo depuraci�n (con la constante DEBUG), la librer�a define
!!	tres meta-acciones nuevas:
!!
!!	 *	xpeso OBJETO			imprime el peso del objeto
!!	 *	xdimensiones OBJETO		imprime todas las dimensiones del objeto
!!	 *	xcapacidad OBJETO		imprime todas las capacidades del objeto
!!
!!------------------------------------------------------------------------------
!!
!!	EJEMPLO #1
!!
!!	Creaci�n de una caja con un volumen de '10' y una capacidad de volumen de
!!	'9', y una piedra con un volumen de 2. El jugador puede poner hasta 4 piedras en
!!	la caja (cuyo volumen total ser�a 2*4 = 8). Una quinta piedra no podr�a ser
!!	introducida en la caja, puesto que su capacidad es 9 y el volumen total de
!!	5 piedras ser�a de 10:
!!
!!		Receptacle -> box "caja"
!!		 with	name 'caja',
!!				volume 10,			! el volumen de la propia caja
!!				capacity_volume 9,	! la capacidad de la caja
!!		 has	container;
!!
!!		Object -> stone "piedra"
!!		 with	name 'piedra',
!!				volume 2;			! el volumen de la piedra
!!
!!------------------------------------------------------------------------------
!!
!!	# EJEMPLO 2
!!
!!	El siguiente ejemplo crea una caja de madera y una caja de acero:
!!
!!		Receptacle -> wooden_box "caja de madera"
!!		 with	name 'caja' 'madera',
!!				volume 10,			! volumen del objeto
!!				capacity_volume 9,	! capacidad de volumen del objeto
!!		 has	container;
!!
!!		Receptacle -> stell_box "caja de acero"
!!		 with	name 'caja' 'acero',
!!				volume 8,			! volumen del objeto
!!				capacity_volume 7,	! capacidad de volumen del objeto
!!		 has	container;
!!
!!	El jugador puede introducir la caja de acero (volumen 8) dentro de la caja
!!	de madera (capacidad 9), pero la caja de madera (volumen 10) no se puede
!!	introducir en la caja de acero (capacidad 7). Si se introduce un objeto de
!!	volumen igual o mayor a 2 dentro de la caja de madera (como la piedra del
!!	EJEMPLO 1), ya no se podr�a introducir la caja de acero en su interior,
!!	porque �sta requiere un espacio libre de 8 o m�s.
!!
!!------------------------------------------------------------------------------
!!
!!	# EJEMPLO 3
!!
!!	El volumen y tama�o de los objetos contenidos en un recept�culo NO se
!!	a�aden a su volumen y tama�o total (se asume que los recept�culos no son
!!	flexibles y tienen proporciones fijas). Si se desea crear una bolsa
!!	flexible cuyo volumen aumente conforme se introducen objetos en su
!!	interior, se debe implementar la rutina apropiada en su propiedad volume:
!!
!!		Receptacle -> bag "bolsa flexible"
!!		 with	name 'bolsa' 'flexible',
!!				capacity_volume 20,
!!				capacity_size 5,
!!				volume [ result i;
!!					!! Volumen m�nimo de la bolsa (cuando est� vac�a):
!!					result = 1;
!!					!! Se suman los vol�menes de los objetos que contiene:
!!					objectloop (i in self)
!!						result = result + VolumeOf(i);
!!					!! Retorna el volumen total acumulado:
!!					return result;
!!				],
!!				size [ result i;
!!					!! Tama�o m�nimo de la bolsa (cuando est� vac�a):
!!					result = 1;
!!					!! Se obtiene el objeto contenido de mayor tama�o:
!!					objectloop(i in self)
!!						if (SizeOf(i) > result) result = SizeOf(i);
!!					!! El tama�o del mayor objeto contenido en ella determina
!!					!! el tama�o actual de la bolsa:
!!					return result;
!!				],
!!		 has	container;
!!
!!------------------------------------------------------------------------------
!!
!!	# EJEMPLO 4
!!
!!	Los pesos de los objetos contenidos en �l se a�aden autom�ticamente al peso
!!	total del recept�culo. Se puede sobreescribir este comportamiento
!!	definiendo la propiedad weight como una rutina. El siguiente ejemplo crea
!!	una bolsa m�gica cuyo peso total es s�lo la mitad del peso de los objetos
!!	contenidos en su interior:
!!
!!		Receptacle -> magic_bag "bolsa m�gica"
!!		 with	name 'bolsa' 'magica' 'maravillosa',
!!				capcity_volume 100,
!!				weight [ result i;
!!					!! Peso base de la bolsa (cuando est� vac�a):
!!					result = 1;
!!					!! Se suman los pesos de los objetos que contiene:
!!					objectloop(i in self)
!!						result = result + WeightOf(i);
!!					!! Retorna el 50% del peso total:
!!					return (result/2);
!!				],
!!		 has	container;
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef RECEPTACLES;
Constant RECEPTACLES;

Constant RECEPTACLE_NUMBER	0;
Constant RECEPTACLE_SIZE	1;
Constant RECEPTACLE_VOLUME	2;
Constant RECEPTACLE_WEIGHT	3;

Constant RECEPTACLE_INFINITE_CAPACITY -1;

!! Se definen las 6 nuevas propiedades utilizadas por la extensi�n sin utilizar
!! espacio del programa ni memoria en tiempo de ejecuci�n:

Class	receptacle_properties
 with	capacity_size 0,
		capacity_volume 0,
		capacity_weight 0,
		size 0,
		volume 0,
		weight 0,
;

!!------------------------------------------------------------------------------
!! Calcula el peso, volumen o el tama�o de un objeto dado.
!!
!!	@param{integer} measure - C�digo num�rico que indica la medida que se
!!		quiere calcular: 1) peso, 2) volumen o 3) tama�o
!!	@param{Object} obj - Objeto del que se quiere conocer una medida
!!	@returns{integer} Valor de peso, volumen o tama�o (en funci�n del c�digo
!!		'measure') del objeto 'obj'
!!------------------------------------------------------------------------------
[ GetMeasure measure obj
	result temp;
	result = 0;
	switch (measure) {
		RECEPTACLE_SIZE:
			if (obj provides size) {
				if (metaclass(obj.size) == Routine) {
					return indirect(obj.size);
				}
				result = obj.size;
			}
		RECEPTACLE_VOLUME:
			if (obj provides volume) {
				if (metaclass(obj.volume) == Routine) {
					return indirect(obj.volume);
				}
				result = obj.volume;
			}
		RECEPTACLE_WEIGHT:
			if (obj provides weight) {
				if (metaclass(obj.weight) == Routine) {
					return indirect(obj.weight);
				}
				result = obj.weight;
			}
			if ((obj has container) || (obj has supporter)) {
				!! Llamada recursiva para agregar el peso de sus contenidos
				objectloop(temp in obj)
					result = result + GetMeasure(RECEPTACLE_WEIGHT, temp);
			}
	}
	return result;
];

!!------------------------------------------------------------------------------
!! Calcula la capacidad en n�mero de objetos, peso, volumen o tama�o de un
!! objeto dado.
!!
!!	@param{integer} measure - C�digo num�rico que indica la capacidad que se
!!		quiere calcular: 0) n�mero de objetos 1) peso, 2) volumen o 3) tama�o
!!	@param{Object} obj - Objeto del que se quiere conocer su capacidad
!!	@returns{integer}  Valor de capacidad en n�mero de objetos, peso, volumen
!!		o tama�o del objeto 'obj'
!!------------------------------------------------------------------------------
[ GetCapacity measure obj
	result;
	result = RECEPTACLE_INFINITE_CAPACITY;
	switch (measure) {
		RECEPTACLE_NUMBER:
			if (obj provides capacity) {
				if (metaclass(obj.capacity) == Routine) {
					return indirect(obj.capacity);
				}
				result = obj.capacity;
			}
		RECEPTACLE_SIZE:
			if (obj provides capacity_size) {
				if (metaclass(obj.capacity_size) == Routine) {
					return indirect(obj.capacity_size);
				}
				result = obj.capacity_size;
			}
		RECEPTACLE_VOLUME:
			if (obj provides capacity_volume) {
				if (metaclass(obj.capacity_volume) == Routine) {
					return indirect(obj.capacity_volume);
				}
				result = obj.capacity_volume;
			}
		RECEPTACLE_WEIGHT:
			if (obj provides capacity_weight) {
				if (metaclass(obj.capacity_weight) == Routine) {
					return indirect(obj.capacity_weight);
				}
				result = obj.capacity_weight;
			}
	}
	return result;
];

!!------------------------------------------------------------------------------
!! -1: se supera la cantidad m�xima de objetos
!! -2: se supera el tama�o m�ximo
!! -3: el objeto es demasiado voluminoso
!! -4: se supera el l�mite de volumen total
!! -5: el objeto es demasiado pesado
!! -6: se supera el l�mite de peso total
!!------------------------------------------------------------------------------
[ CheckIfObjectFits receiver obj
	receiver_capacity measure i;
	!! 1) Se comprueba el l�mite de tama�o:
	receiver_capacity = GetCapacity(RECEPTACLE_SIZE, receiver);
	if (receiver_capacity ~= RECEPTACLE_INFINITE_CAPACITY) {
		if (GetMeasure(RECEPTACLE_SIZE, obj) > receiver_capacity) return -2;
	}
	!! 2) Se comprueba el l�mite de volumen:
	receiver_capacity = GetCapacity(RECEPTACLE_VOLUME, receiver);
	if (receiver_capacity ~= RECEPTACLE_INFINITE_CAPACITY) {
		measure = GetMeasure(RECEPTACLE_VOLUME, obj);
		if (measure > receiver_capacity) return -3;
		else {
			objectloop(i in receiver) {
				measure = measure + GetMeasure(RECEPTACLE_VOLUME, i);
			}
			if (measure > receiver_capacity) return -4;
		}
	}
	!! 3) Se comprueba el l�mite de peso:
	receiver_capacity = GetCapacity(RECEPTACLE_WEIGHT, receiver);
	if (receiver_capacity ~= RECEPTACLE_INFINITE_CAPACITY) {
		measure = GetMeasure(RECEPTACLE_WEIGHT, obj);
		if (measure > receiver_capacity) return -5;
		else {
			objectloop(i in receiver) {
				measure = measure + GetMeasure(RECEPTACLE_WEIGHT, i);
			}
			if (measure > receiver_capacity) return -6;
		}
	}

	return 1;
];




!!==============================================================================
!! Definici�n de la nueva clase Receptacle
!!------------------------------------------------------------------------------

Class	Receptacle
 with	before [ s i;
			Receive:
				!! Se comprueba el peso (si su capacidad no es infinita):
				if ( CapacityWeightOf( self ) ~= INFINITE_CAPACITY ) {
					if ( GetMeasure(RECEPTACLE_WEIGHT, noun) > CapacityWeightOf( self ))
						return self.error_messages(1, noun);
					!! Se calcula el peso de todo el contenido
					s = 0; objectloop (i in self) s = s + GetMeasure(RECEPTACLE_WEIGHT, i);
					if ( (s + GetMeasure(RECEPTACLE_WEIGHT, noun)) > CapacityWeightOf (self) )
						return self.error_messages(2);
				}

				!! Se comprueba el volumen (si su capacidad no es infinita):
				if ( CapacityVolumeOf (self) ~= INFINITE_CAPACITY ) {
					if ( VolumeOf(noun) > CapacityVolumeOf( self ))
						return self.error_messages(3, noun);
					!! Se calcula el volumen de todo el contenido
					s = 0; objectloop (i in self) s = s + VolumeOf(i);
					if ( (s + VolumeOf(noun)) > CapacityVolumeOf( self ))
						return self.error_messages(4);
				}

				!! Se comprueba el tama�o (si su capacidad no es infinita):
				if ( GetCapacity(RECEPTACLE_SIZE, self) ~= INFINITE_CAPACITY ) {
					if ( SizeOf(noun) > GetCapacity(RECEPTACLE_SIZE, self ))
						return self.error_messages(5, noun);
				}

				!! Se comprueba el n�mero (si su capacidad no es infinita):
				if ( CapacityNumberOf (self) ~= INFINITE_CAPACITY ) {
					s = 0; objectloop (i in self) s++;
					if ( (s+1) > CapacityNumberOf( self ))
						return self.error_messages(6);
				}

				return false;
		],
		!! Mensajes de error. Se producen al intentar meter en el recept�culo
		!! un objeto que viola alguno de los l�mites de capacidad definidos
		error_messages [ id obj;
			switch (id) {
				1:
					!! Intentar meter en el bolsillo un objeto cuyo peso supera
					!! el l�mite permitido
					print_ret (The) obj, " ", (es) obj, " demasiado pesad",
					(o) obj ," para ", (the) obj ,".";
				2:
					!! Intentar meter en el bolsillo un objeto cuyo peso, unido
					!! al del resto de objetos que hay ya en el bolsillo,
					!! superan el l�mite permitido
					print_ret (The) self ," ha", (n) self ," alcanzado su
					capacidad m�xima.";
				3:
					!! Intentar meter en el bolsillo un objeto cuyo volumen
					!! supera el l�mite permitido
					print_ret (The) obj ," no encaja", (n) obj ," dentro de ",
					(the) self ,".";
				4:
					!! Intentar meter en el bolsillo un objeto cuyo volumen,
					!! unido al del resto de objetos que hay ya en el bolsillo,
					!! superan el l�mite permitido
					print_ret (The) self ," ha", (n) self ," alcanzado su
					capacidad m�xima.";
				5:
					!! Intentar meter en el bolsillo un objeto cuyo tama�o
					!! supera el l�mite permitido
					print_ret (The) obj ," ", (es) obj ," demasiado grande",
					(s) obj ," para ", (the) self ,".";
				6:
					!! Intentar meter en el bolsillo un objeto despu�s de haber
					!! alcanzado el l�mite de objetos introducidos permitido
					"En ", (the) self ," no entran ya m�s cosas.";
			}
		];

!!==============================================================================
!! Verbos de depuraci�n
!!------------------------------------------------------------------------------

#Ifdef DEBUG;

Verb meta 'xpeso' 'xweight'			* noun	-> MetaWeight;
Verb meta 'xdimensiones' 'xmeasure'	* noun	-> MetaMeasure;
Verb meta 'xcapacidad' 'xcapacity'	* noun	-> MetaCapacity;

[ MetaWeightSub;
	print (The) noun, " pesa", (n) noun ," ",
	GetMeasure (RECEPTACLE_WEIGHT, noun), " unidad(es)";
	new_line;
	return true;
];

[ MetaMeasureSub;
	print (The) noun, ":^";
	spaces(6);	print "Peso: ",		GetMeasure(RECEPTACLE_WEIGHT, noun),	" unidades^";
	spaces(6);	print "Tama�o: ",	SizeOf(noun),	" unidades^";
	spaces(6);	print "Volumen: ",	VolumeOf(noun),	" unidades^";
	return true;
];

[ MetaCapacitySub;
	print (The) noun, ":^";

	spaces(6); print "Capacidad (peso): ";
	if (GetCapacity(RECEPTACLE_WEIGHT, noun) == INFINITE_CAPACITY) print "infinita^";
	else print GetCapacity(RECEPTACLE_WEIGHT, noun), " unidad(es)^";

	spaces(6); print "Capacidad (tama�o): ";
	if (GetCapacity(RECEPTACLE_SIZE, noun) == INFINITE_CAPACITY) print "infinita^";
	else print GetCapacity(RECEPTACLE_SIZE, noun), " unidad(es)^";

	spaces(6); print "Capacidad (volumen): ";
	if (GetCapacity(RECEPTACLE_VOLUME, noun) == INFINITE_CAPACITY) print "infinita^";
	else print GetCapacity(RECEPTACLE_VOLUME, noun), " unidad(es)^";

	spaces(6); print "Capacidad (n�mero de objetos): ";
	if (CapacityNumberOf(noun) == INFINITE_CAPACITY) print "infinita^";
	else print CapacityNumberOf(noun), "^";

	return true;
];

#Endif; ! DEBUG;


#Endif; ! RECEPTACLES;
