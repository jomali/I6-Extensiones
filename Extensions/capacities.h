

!!==============================================================================
!!
!!	CAPACITIES
!!	Extensi�n a las reglas de capacidad para contenedores y soportes
!!
!!==============================================================================
!!
!!	Archivo:		capacities.h
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!					Peer Schaefer
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		1.0
!!	Fecha:			2018/03/08
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
!!	1.0: 2018/03/08	Versi�n inicial de la extensi�n.
!!
!!------------------------------------------------------------------------------
!!
!!	INTRODUCCI�N
!!
!!	La extensi�n 'capacities.h' implementa un conjunto de rutinas que extienden
!!	el comportamiento por defecto de la librer�a para tratar las reglas de
!!	capacidad de contenedores y soportes. En concreto, adem�s del l�mite de la
!!	librer�a que establece el n�mero m�ximo de objetos que pueden ser
!!	contenidos por un contenedor/soporte, se a�ade l�gica para tratar l�mites
!!	de peso, volumen y tama�o. Est� basada en la extensi�n 'recept.h' de Peer
!!	Schaefer <peer@wolldingwacht.de>.
!!
!!	Para utilizar la extensi�n hay que a�adir la siguiente l�nea en el fichero
!!	principal de la obra, despu�s de la l�nea 'Include "Parser";':
!!
!!		Include "capacities";
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef CAPACITIES;
Constant CAPACITIES;
Message "Incluyendo 'capacities' v1.0";

Constant CAPACITIES_INFINITE	-1;
Constant CAPACITIES_NUMBER		0;
Constant CAPACITIES_SIZE		1;
Constant CAPACITIES_VOLUME		2;
Constant CAPACITIES_WEIGHT		3;

!! Clase falsa para definir las 6 nuevas propiedades utilizadas por la
!! extensi�n sin consumir memoria adicional:

Class	capacities_dummy
 with	capacity_size 0,
		capacity_volume 0,
		capacity_weight 0,
		size 0,
		volume 0,
		weight 0;

!!------------------------------------------------------------------------------
!! Calcula el n�mero de objetos contenidos por �l, el tama�o, volumen o el peso
!! de un objeto dado. La medida concreta que se calcula depende del c�digo
!! pasado como par�metro.
!!
!!	@param {integer} measure_code - C�digo que identifica la medida concreta
!!		que se quiere calcular. Sus posibles valores son:
!!		0.	N�mero de objetos contenidos directamente por 'obj'
!!		1.	Tama�o de 'obj'
!!		2.	Volumen de 'obj'
!!		3.	Peso total de 'obj' (incluye el peso de los objetos contenidos)
!!	@param {Object} obj - Objeto del que se desea calcular una medida
!!	@returns {integer} N�mero de objetos contenidos por 'obj', su tama�o,
!!		volumen o su peso total, en funci�n del c�digo 'measure_code'
!!------------------------------------------------------------------------------
[ GetMeasure measure_code obj
	i result;
	result = 0;
	switch (measure_code) {
		CAPACITIES_NUMBER:
			objectloop(i in obj) result++;
		CAPACITIES_SIZE:
			if (obj provides size) {
				if (metaclass(obj.size) == Routine) {
					return indirect(obj.size);
				}
				result = obj.size;
			}
		CAPACITIES_VOLUME:
			if (obj provides volume) {
				if (metaclass(obj.volume) == Routine) {
					return indirect(obj.volume);
				}
				result = obj.volume;
			}
		CAPACITIES_WEIGHT:
			if (obj provides weight) {
				if (metaclass(obj.weight) == Routine) {
					return indirect(obj.weight);
				}
				result = obj.weight;
			}
			if ((obj has container) || (obj has supporter)) {
				!! Llamada recursiva para agregar el peso de sus contenidos
				objectloop(i in obj)
					result = result + GetMeasure(CAPACITIES_WEIGHT, i);
			}
	}
	return result;
];

!!------------------------------------------------------------------------------
!! Calcula la capacidad de n�mero de objetos, tama�o, volumen o peso de un
!! objeto dado. La medida de capacidad concreta que se calcula depende del
!! c�digo pasado como par�metro.
!!
!!	@param {integer} measure_code - C�digo que identifica la capacidad concreta
!!		que se quiere calcular. Sus posibles valores son:
!!		0.	N�mero de objetos total que puede contener 'obj'
!!		1.	Tama�o m�ximo de los objetos que puede contener 'obj'
!!		2.	Volumen m�ximo total que puede contener 'obj'
!!		3.	Peso m�ximo total que puede contener 'obj'
!!	@param {Object} obj - Objeto del que se quiere conocer un l�m. de capacidad
!!	@returns {integer} Capacidad de 'obj' en n�mero de objetos, tama�o, volumen
!!		o peso, en funci�n del c�digo 'measure_code'
!!------------------------------------------------------------------------------
[ GetCapacity measure_code obj
	result;
	result = CAPACITIES_INFINITE;
	switch (measure_code) {
		CAPACITIES_NUMBER:
			if (obj provides capacity) {
				if (metaclass(obj.capacity) == Routine) {
					return indirect(obj.capacity);
				}
				result = obj.capacity;
			}
		CAPACITIES_SIZE:
			if (obj provides capacity_size) {
				if (metaclass(obj.capacity_size) == Routine) {
					return indirect(obj.capacity_size);
				}
				result = obj.capacity_size;
			}
		CAPACITIES_VOLUME:
			if (obj provides capacity_volume) {
				if (metaclass(obj.capacity_volume) == Routine) {
					return indirect(obj.capacity_volume);
				}
				result = obj.capacity_volume;
			}
		CAPACITIES_WEIGHT:
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
!! Comprueba si un objeto tiene capacidad suficiente para albergar a otro,
!! pasados ambos como par�metro. El resultado es un c�digo num�rico positivo
!! si tiene capacidad suficiente, o negativo en caso contrario.
!!
!!	@param {Object} receiver - Objeto del que se comprueba si tiene capacidad
!!		suficiente para albergar a 'obj'
!!	@param {Object} obj - Objeto con posibles propiedades de tama�o, volumen y
!!		peso que se compara con los l�mites de capacidad de 'receiver'
!!	@returns {integer} C�digo num�rico con el resultado de la comprobaci�n:
!!		 1)	'receiver' puede albergar al objeto 'obj'
!!		-1)	se supera la cantidad m�xima de objetos que puede tener 'receiver'
!!		-2) 'obj' supera el tama�o m�ximo admitido por 'receiver'
!!		-3) 'obj' supera el volumen m�ximo admitido por 'receiver'
!!		-4) el volumen agregado supera el volumen total admitido por 'receiver'
!!		-5)	'obj' supera el peso m�ximo admitido por 'receiver'
!!		-6) el peso agregado supera el peso total admitido por 'receiver'
!!------------------------------------------------------------------------------
[ CheckIfObjectFits receiver obj
	receiver_capacity measure i;
	!! 0) Se comprueba la cantidad m�xima de objetos admitida:
	receiver_capacity = GetCapacity(CAPACITIES_NUMBER, receiver);
	measure = 1;
	objectloop(i in receiver) measure++;
	if (measure > receiver_capacity) return -1;
	!! 1) Se comprueba el l�mite de tama�o:
	receiver_capacity = GetCapacity(CAPACITIES_SIZE, receiver);
	if (receiver_capacity ~= CAPACITIES_INFINITE) {
		if (GetMeasure(CAPACITIES_SIZE, obj) > receiver_capacity) return -2;
	}
	!! 2) Se comprueba el l�mite de volumen:
	receiver_capacity = GetCapacity(CAPACITIES_VOLUME, receiver);
	if (receiver_capacity ~= CAPACITIES_INFINITE) {
		measure = GetMeasure(CAPACITIES_VOLUME, obj);
		if (measure > receiver_capacity) return -3;
		else {
			objectloop(i in receiver) {
				measure = measure + GetMeasure(CAPACITIES_VOLUME, i);
			}
			if (measure > receiver_capacity) return -4;
		}
	}
	!! 3) Se comprueba el l�mite de peso:
	receiver_capacity = GetCapacity(CAPACITIES_WEIGHT, receiver);
	if (receiver_capacity ~= CAPACITIES_INFINITE) {
		measure = GetMeasure(CAPACITIES_WEIGHT, obj);
		if (measure > receiver_capacity) return -5;
		else {
			objectloop(i in receiver) {
				measure = measure + GetMeasure(CAPACITIES_WEIGHT, i);
			}
			if (measure > receiver_capacity) return -6;
		}
	}
	return 1;
];

!!------------------------------------------------------------------------------

#Ifdef DEBUG;
Verb meta	'dimensiones' 'measure'	* noun -> DebugMeasure;
Verb meta	'capacidad' 'capacity'	* noun -> DebugCapacity;

[ DebugMeasureSub;
	print (The) noun, ":^";
	spaces(6); print "Tama�o: ", GetMeasure(CAPACITIES_SIZE, noun), " ud(s)^";
	spaces(6); print "Volumen: ", GetMeasure(CAPACITIES_VOLUME, noun)," ud(s)^";
	spaces(6); print "Peso: ", GetMeasure(CAPACITIES_WEIGHT, noun), " ud(s)^";
	return true;
];

[ DebugCapacitySub
	i;
	print (The) noun, ":^";
	i = GetCapacity(CAPACITIES_NUMBER);
	spaces(6); print "Capacidad (n�mero de objetos): ";
	if (i == CAPACITIES_INFINITE) print "infinita^";
	else print i, "^";
	i = GetCapacity(CAPACITIES_SIZE);
	spaces(6); print "Capacidad (tama�o): ";
	if (i == CAPACITIES_INFINITE) print "infinita^";
	else print i, "^";
	i = GetCapacity(CAPACITIES_VOLUME);
	spaces(6); print "Capacidad (volumen): ";
	if (i == CAPACITIES_INFINITE) print "infinita^";
	else print i, "^";
	i = GetCapacity(CAPACITIES_WEIGHT);
	spaces(6); print "Capacidad (peso): ";
	if (i == CAPACITIES_INFINITE) print "infinita^";
	else print i, "^";
];
#Endif; ! DEBUG;

#Endif; ! CAPACITIES;
