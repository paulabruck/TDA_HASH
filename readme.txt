
*Un Readme.txt donde se explique la definición de tabla de hash. Enumere los distintos tipos de tablas que
conoce y explique cómo se diferencian.

La tabla de hash es una estructura que contiene valores y a su vez claves(no necesariamente tienen que ser numericas) para poder 
hallar a estos. Lo que hace es acomodar los pares clave-valor y accede a ellos mediante una funcion de hash. La funcion de hash
lo que hace es ubicar en la tabla el valor, al transformar las claves en numeros asociados que son las posiciones en la tabla de hash
que estamos usando. Cuando tenemos dos claves distintas que dan el mismo valor en hash (misma posicion) entonces ahi se produce una colision.
Cuando esto ocurre existen dos formas de direccionar el elemento que esta colisionando dentro del hash. Estas son direccionamiento 
cerrado y direccionamiento abierto. Segun el tipo de direccionamiento que tengamos el tipo de hash que tenemos. Cuando hay 
direccionamiento cerrado hablamos de un hash abierto y cuando hay direccionamiento abierto el hash es cerrado. En los hash abiertos 
se dice que hay un encadenamiento cerrado porque el elemento termina en el indice que le correspondia en esa tabla de hash y no se 
mueve del indice. Al momento de implementarlo se usa una tecnica llamada encadenamiento que como podemos tener muchos mas claves
que posiciones en la tabla cuando ocurre esto en dicha posicion se crea un puntero a una lista y todos las claves que dan la misma 
posicion de hash se van insertanado en esa posicion en la lista. La complejidad algoritmica en estos tipos de hash es de o(1), se 
espera que una buena funcion de hash divida claves en las posiciones del hash lo mas equitativo posible, en el caso de tener un hash
degenerado en lista la funcion de hash esta mal y la complejidad seria o(n). En los hash cerrados el direccionamiento es abierto y
todos los valores se guardan dentro de la misma tabla no se hace uso de otra estructura para guardar los valores. En estos casos 
el tamańio de la tabla tiene que ser mayor o igual al numero de claves y si se produce una colision, se puede resolver 
haciendo probing lineal que lo que hace es recorrer el array hasta encontrar un espacio que este libre, por esto se dice q es
direccionamiento abierto ya que una clave nos puede quedar en otra posicion de memoria que la que dio la funcion de hash .
A su vez existe el llamado factor de carga que indica el grado de ocupacion de la tabla y por lo tanto que tan probable es que 
haya una colision. Este se calcula mediante la formula α=n/m, siendo n el numero de claves almacenadas actualmente  y m la capacidad
de la tabla de hash. Cuando el resultado de esta cuenta es  α>= 0,75 se dice que hay que rehashear osea aumentar la capacidad de la 
tabla y volver a insertar reordenados a los elementos . Las operaciones en un hash son crear, insertar, obtener, cantidad,destruir,
quitar, contiene.


*El Readme.txt deberá contener también una explicación de la solución implementada. Este archivo le sirve a
su corrector para saber si entendió o no el tema. Explique la implementación como si se lo estuviese explicando
a alguien que no sabe del tema. Explique las decisiones que tomó al implementar las primitivas (esto incluye
estrategia de resolución de colisiones, criterio de redimensionamiento, etc). Si hizo extra alguna suposición para
resolver el TP (ya sea por enunciado poco claro o cualquier otro motivo) también explı́quela.

Bueno , para este tda hash lo primero que hice fue responder la pregunta teorica sobre la tabla de hash para asi poder tener bien claro que era lo que iba a 
hacer y para empezar a ver como lo iba a hacer. Despues lo que hice fue hacer un par de dibujitos sobre las primitivas principales como la de insertar , quitar 
y obtener y ver que era lo que tenia que tener en cuenta para que funcione como correspondia. Luego de eso pase a ver que estructura iba a usar porque  era el 
primer tda donde nosostros elegiamos que estructura usar . Termine decidiendome por hacer la tabla del hash como un vector de punteros a pares que contenian una clave y un valor que 
lo llame elemento , a su vez tambien le agregue un campo booleano para ver si ya se habia ocupado ese espacio y que funciona como flag al momento de obtener un elemento .
Una vez definida mi estructura pase a crear el hash ,la tabla donde iba a insertar los pares y arme tambien una funcion para crear los pares antes de insertarlos 
en la tabla. Despues de eso pase a hacer pruebas de creacion y pruebas de insercion pensando en que casos tenia que contemplar para que mi insertar funcionara. 
Despues de varias vueltas termine haciendo una funcion para insertar los pares en la tabla primero y despues esa funcion la use en insertar teniendo en cuenta que
si en vez de insertar una nueva clave solo tenia que reemplazar el elemento no se sumara la cantidad de elementos que habia en la tabla y para resolver el 
tema de las colisiones hice que si la clave a insertar no se encontraba en la tabla y la posicion que le tocaba a ese elemento por la funcion de hash
estaba ocupada entonces que se insertara en la proxima posicion libre. Tambien para el insertar tuve que armar una funcion de hash que me transforme la clave
recibida por un valor numerico y que a su vez este se encuentre dentro de la capacidad de la tabla. Una vez que por fin funcionaba mi insertar agregue la funcion 
de rehash para que si se llegaba a superar el valor de factoreo se  duplicara el tamaño. En este proceso arme una funcion booleana
que se fijara que en el insertar que si el factor de cargar superaba el valor esperado entonces ahi se rehasee. Para el rehaseo termine haciendo una tabla con el
doble de capacidad de la tabla original y a medida que recorria el hash con la tabla original si el par tenia un elemento ahi insertaba ese elemento con su 
clave en la tabla mas grande . Despues de pasar todos los elementos destruia la tabla vieja y  reasignaba la tabla a la nueva. Para destruir la tabla me cree una 
funcion auxiliar que despues me sirvio para simplificar el hash destruir. En el medio de insertar hice las funciones de cantidad, de contiene y de obtener para poder
usarlas en las pruebas y ver si se insertaba todo como tenia que ser y si se actualizaba el elemento si la clave a insertar era la misma.Para la funcion de obtenenr 
lo que hice fue en base a la clave que se recibia ver la posicion de hash que le correspondia si esta contenia la clave entonces devolvia el elemento y si la posicion que le 
corresondia estaba vacia y siempre habia estado asi entonces devolvia null porque significaba que el elemento no estaba en la tabla . Ahora si en el lugar habia habido un 
elemento se fijaba en la proxima posicion hasta o encontrar la clave y devolver el elemento o hasta encontar una poscion vacia que nunca habia tenido un elemento. Una vez que funciono el 
insertar en su totalidad pase a las funcion de quitar y una vez que esta funciono fui a  hacer el iterador interno. Mas alla de las pruebas que iba haciendo me 
sirvio muchisimo ir probando en el minidemo . Porque podia ir viendo bien que era lo que pasaba con mi codigo y probar los distintos casos y ver que si fallaban 
por alguna razon era y en base a eso ver que tenia que corregir.
 