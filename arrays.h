

!!==============================================================================
!!
!!	ARRAYS
!!	Rutinas de utilidad para manipular arrays de caracteres
!!
!!==============================================================================
!!
!!	Archivo:		arrays.h
!!	Autor(es):		J. Francisco Mart�n <jfm.lisaso@gmail.com>
!!	Idioma:			ES (Espa�ol)
!!	Sistema:		Inform-INFSP 6
!!	Plataforma:		M�quina-Z/Glulx
!!	Versi�n:		1.0
!!	Fecha:			2018/06/19
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
!!	1.0: 2018/06/19	Versi�n inicial de la extensi�n.
!!
!!------------------------------------------------------------------------------
System_file;

#Ifndef ARRAYS;
Constant ARRAYS;

Array temp_array -> INPUT_BUFFER_LEN; ! hasta 160 caracteres

!!------------------------------------------------------------------------------
!! Dado un array de caracteres, capitaliza la primera letra de cada palabra de
!! �ste ---�til por ejemplo si el array almacena el nombre de una persona
!! (Paul O'Brian, Jean-Paul Sartre,...) o de una localidad (Weston-Super-Mare,
!! Los Angeles,...)---.
!!
!!	@param {Array} character_array - El array de caracteres sobre el que se
!!		realizar� la capitalizaci�n
!!	@returns {boolean} Verdadero
!!	@version 1.0
!!------------------------------------------------------------------------------
[ CapitaliseCharacterArray character_array
	i c flg;
	for (i = 0, flg = true : i < character_array-->0 : i++) {
		c = character_array->(i+WORDSIZE);
		if (c >= 'a' && c <= 'z') {
			if (flg) character_array->(i+WORDSIZE) = UpperCase(c);
			flg = false;
 		} else flg = true;
	}
	return true;
];

!!------------------------------------------------------------------------------
!! Dados dos arrays de caracteres: 'array_a' y 'array_b', modifica el primero
!! de forma que se convierte en la concatenaci�n de los dos. Puede
!! especificarse adem�s un caracter extra opcional que ser� introducido como
!! delimitador entre los dos arrays (si no se especifica este caracter extra,
!! el segundo array se a�ade inmediatamente a continuaci�n del primero).
!!
!!	@param {Array} array_a - Primer array de caracteres; sobre el que queda el
!!		resultado de la concatenaci�n
!!	@param {Array} array_b - Segundo array de caracteres; el que se concatena
!!		a continuaci�n de 'array_a'
!!	@param {char} [c=false] - Caracter opcional que puede introducirse como
!!		delimitador de los dos arrays
!!	@returns {boolean} Verdadero
!!	@version 1.0
!!------------------------------------------------------------------------------
[ ConcatenateArrays array_a array_b c
	len i;
	len = array_a-->0;
	if (c ~= 0 || metaclass(c) ~= nothing) {
		array_a->(WORDSIZE+len) = c;
		(array_a->(WORDSIZE-1))++;
		len = array_a-->0;
	}
	for (i = 0 : i < array_b->(WORDSIZE-1) : i++) {
		array_a->(WORDSIZE+len+i) = array_b->(WORDSIZE+i);
		(array_a->(WORDSIZE-1))++;
	}
	return true;
];

!!------------------------------------------------------------------------------
!! Imprime en pantalla un array de caracteres, caracter a caracter.
!!
!!	@param {array} character_array - Array de caracteres a imprimir
!!	@returns {boolean} Verdadero
!!	@version 1.0
!!------------------------------------------------------------------------------
[ PrintCharacterArray character_array
	i;
	for (i = 0 : i < character_array->(WORDSIZE-1) : i++) {
		print (char) character_array->(WORDSIZE+i);
	}
	return true;
];

#Endif; ! ARRAYS;
