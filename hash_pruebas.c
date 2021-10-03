#include "hash.h"
#include <stdio.h>
#include "pa2mm.h"

void dadoUnHashInexistente_SiIntentoInsertarUnPar_NoPuedoHacerlo(){
  hash_t* hash= NULL;
  pa2m_afirmar(!hash, "EL hash no existe.");
  pa2m_afirmar(hash_insertar(hash, (char*)1, (void*)3)==-1, "Dado un hash inexistente no puedo insertar elementos.");

  hash= hash_crear(NULL, 3);
  pa2m_afirmar(hash!=NULL, "El hash se ha creado con exito.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"AC123BD", (void*)0) ==0, "Dado un hash puedo insertar un elemento NULL.");

  hash_destruir(hash);
}
void dadoUnHash_SiQuieroInsertarUnPar_PuedoHacerlo(){
    hash_t * hash= hash_crear(NULL, 6);
    pa2m_afirmar(hash!=NULL, "El hash se ha creado con exito.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"AC123BD", (void*)"auto mariano") ==0, "Dado un hash puedo insertar un elemento con su clave.");
    pa2m_afirmar(hash_cantidad(hash)==1, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_obtener(hash, (char*)"AC123BD")==(void*)"auto mariano","La clave ingresada contiene el elemento correcto.");
    pa2m_afirmar(hash_insertar(hash, NULL, (void*)0) ==-1, "No puedo insertar un elemento con clave nula.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"OPQ976", (void*)"auto lucas") ==0, "Dado un hash puedo insertar 2 elementos con sus claves.");
    pa2m_afirmar(hash_cantidad(hash)==2, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_obtener(hash, (char*)"OPQ976")==(void*)"auto lucas","La clave ingresada contiene el elemento correcto.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"A421ACB", (void*)"moto manu") ==0, "Dado un hash puedo insertar 3 elementos con sus claves.");
    pa2m_afirmar(hash_cantidad(hash)==3, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_obtener(hash, (char*)"A421ACB")==(void*)"moto manu","La clave ingresada contiene el elemento correcto.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"AA442CD", (void*)"auto guido") ==0, "Dado un hash puedo insertar 4 elementos con sus claves.");
    pa2m_afirmar(hash_cantidad(hash)==4, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_obtener(hash, (char*)"AA442CD")==(void*)"auto guido","La clave ingresada contiene el elemento correcto.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"AC152AD", (void*)"auto agustina") ==0, "Dado un hash puedo insertar 5 elementos con sus claves.");
    pa2m_afirmar(hash_cantidad(hash)==5, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_obtener(hash, (char*)"AC152AD")==(void*)"auto agustina","La clave ingresada contiene el elemento correcto.");

    pa2m_afirmar(hash_insertar(hash, ( char*)"AC152AD", (void*)"auto agus") ==0, "Ingreso un nuevo elemento con la misma clave que el anterior.");
    pa2m_afirmar(hash_cantidad(hash)==5, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_obtener(hash, (char*)"AC152AD")==(void*)"auto agus","La clave ingresada actualiza el elemento que contiene correctamente."); 
    pa2m_afirmar(hash_insertar(hash, ( char*)"OPQ976", (void*)"auto ") ==0, "Ingreso un nuevo elemento con la misma clave que uno ya insertado.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"AC152AD¡¡", (void*)"auto agustina") ==0, "Dado un hash puedo insertar 6 elementos con sus claves.");
    pa2m_afirmar(hash_cantidad(hash)==6, "La cantidad de elementos es la correcta.");
    pa2m_afirmar(hash_insertar(hash, ( char*)"AC", (void*)"autoss") ==0, "La tabla se rehasea correctamente.");
    pa2m_afirmar(hash_cantidad(hash)==7, "La cantidad de elementos es la correcta.");
   
    hash_destruir(hash);
}
void dadoUnHashInexistente_SiQuieroBorrarUnPar_NoPuedoHAcerlo(){
  hash_t* hash=NULL;
  pa2m_afirmar(hash_quitar(hash,(char*)"hola")==-1, "Dado un hash inexistente no puedo eleminar elementos.");
}
void dadoUnHash_SiQuieroBorrarUnPar_SiHayParesInsertadosPuedoHacerlo(){
  hash_t* hash= hash_crear(NULL,5);
  pa2m_afirmar(hash_quitar(hash, (char*)"hola")==-1, "Dado un hash existente no puedo borrar un elemento ya que esta vacio.");
 
  pa2m_afirmar(hash_insertar(hash, ( char*)"1", (void*)'A') ==0, "Inserto un elemento.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"1", (void*)'A') ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_quitar(hash, (char*)"1")==0, "Dado un hash existente puedo borrar un elemento entre varios elementos .");
  pa2m_afirmar(hash_quitar(hash, (char*)"1")==-1, "No puedo elimanar un elemento que ya habia eliminado .");
  pa2m_afirmar(hash_obtener(hash, (char*)"1")==NULL, "No puedo encontrar el elemento buscado porque lo elimine.");
  pa2m_afirmar(hash_cantidad(hash)==0, "AL borrar todos los elementos tengo un hash vacio.");
  
  hash_destruir(hash);

  hash= hash_crear(NULL,5);
  pa2m_afirmar(hash_insertar(hash, ( char*)"hola", (void*)3) ==0, "Inserto un elemento.");
  pa2m_afirmar(hash_quitar(hash, (char*)"hola")==0, "Dado un hash existente puedo borrar un elemento .");
  pa2m_afirmar(hash_quitar(hash, (char*)"hola")==-1, "Si quiero borrarlo nuevamente no puedo .");
  pa2m_afirmar(hash_cantidad(hash)==0, "Al borrar un elemento tengo nuevamente un hash vacio.");
  pa2m_afirmar(hash_obtener(hash, (char*)"hola")==NULL, "No puedo encontrar el elemento insertado porque lo elimine.");
  
  hash_destruir(hash);
}
void dadaoUnHashInexistente_SiQuieroBuscarUnPar_NoPuedoHacerlo(){
  hash_t * hash= NULL;
  pa2m_afirmar(hash_obtener(hash, (char*)"hola")==NULL, "Dado un hash inexistente no puedo encontrar elementos.");
}
void dadaoUnHash_SiQuieroBuscarUnPar_SiSeEncuentraEnElHashPuedoHacerlo(){
  hash_t * hash= hash_crear(NULL, 6);
  pa2m_afirmar(hash_obtener(hash, (char*)"hola")==NULL, "No puedo encontrar el elemento insertado porque el hash esta vacio.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"hola", (void*)3) ==0, "Inserto un elemento.");
  pa2m_afirmar(hash_obtener(hash, (char*)"hola")==(void*)3, "Puedo encontrar el elemento insertado.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"como", (void*)1) ==0, "Dado un hash existente puedo insertar un elemento.");
  pa2m_afirmar(hash_obtener(hash, (char*)"como")==(void*)1, "Puedo encontrar el elemento insertado.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"s", (void*)1) ==0, "Dado un hash existente puedo insertar otro elemento.");
  pa2m_afirmar(hash_obtener(hash, (char*)"s")==(void*)1, "Puedo encontrar el elemento insertado. ");
  pa2m_afirmar(hash_insertar(hash, ( char*)"s", (void*)2) ==0, "Inserto con la misma clave otro elemento.");
  pa2m_afirmar(hash_obtener(hash, (char*)"s")==(void*)2, "Puedo encontrar el elemento insertado. ");
  pa2m_afirmar(hash_obtener(hash, (char*)"co")==NULL, "No puedo encontrar el elemento insertado porque no se encuentra en el hash.");
  
  hash_destruir(hash);
}
void dadoUnHashInexistente_SiBuscoUnElemento_NoLoEncuentro(){
  hash_t * hash= NULL;
  pa2m_afirmar(!hash_contiene(hash, (char*)"hola"), "Dado un hash inexsitente no se contienen elementos almacenados.");
}
void dadoUnHash_SiBuscoUnElementoYLoEncuentro_MeDevuelveTrue(){
  hash_t * hash= hash_crear(NULL, 4);
  pa2m_afirmar(!hash_contiene(hash, (char*)"hola"), "No contiene un elemento almacenado con la clave solicitada por estar vacio el hash.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"hola", (void*)2) ==0, "Inserto un elemento.");
  pa2m_afirmar(hash_contiene(hash, (char*)"hola"), "El hash contiene el elemento insertado.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"como", (void*)2) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_contiene(hash, (char*)"como"), "El hash contiene el elemento insertado.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"s", (void*)3) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_contiene(hash, (char*)"s"), "El hash contiene el elemento insertado.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"no", (void*)3) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_contiene(hash, (char*)"no"), "El hash contiene el elemento insertado.");
  pa2m_afirmar(hash_quitar(hash, ( char*)"como") ==0, "Elimino uno de los elementos.");
  pa2m_afirmar(!hash_contiene(hash, (char*)"como"), "El hash no contiene el elemento porque ha sido eliminado.");
  pa2m_afirmar(!hash_contiene(hash, (char*)"bien"), "El hash no contiene el elemento porque nunca fue insertado.");

  hash_destruir(hash);
}
void dadoUnHashInexistente_SiQuieroSaberCuantosELementosHay_NopuedoHacerlo(){
  hash_t * hash= NULL;
  pa2m_afirmar(hash_cantidad(hash)==0, "Dado un hash inexistente la cantidad de elementos es nula. ");
}
void dadoUnHash_SiQuieroSaberCuantosELementosHay_PuedoHacerlo(){
  hash_t * hash= hash_crear(NULL, 6);
  pa2m_afirmar(hash_cantidad(hash)==0, "Dado un hash vacio la cantidad de elementos es 0. ");
  pa2m_afirmar(hash_insertar(hash, ( char*)"hola", (void*)2) ==0, "Inserto un elemento.");
  pa2m_afirmar(hash_cantidad(hash)==1, "Dado un hash con 1 elemento la cantidad es 1. ");
  pa2m_afirmar(hash_insertar(hash, ( char*)"como", (void*)2) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_cantidad(hash)==2, "Dado un hash con 2 elementos la cantidad es 2. ");
  pa2m_afirmar(hash_insertar(hash, ( char*)"estas", (void*)2) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_cantidad(hash)==3, "Dado un hash con 3 elementos la cantidad es 3. ");
  pa2m_afirmar(hash_insertar(hash, ( char*)"bien", (void*)2) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_cantidad(hash)==4, "Dado un hash con 4 elementos la cantidad es 4. ");

  pa2m_afirmar(hash_quitar(hash, ( char*)"bien") ==0, "Elimino uno de los elementos.");
  pa2m_afirmar(hash_cantidad(hash)==3, "La cantidad de elementos es 3. ");
  pa2m_afirmar(hash_quitar(hash, ( char*)"como") ==0, "Elimino otro de los elementos.");
  pa2m_afirmar(hash_cantidad(hash)==2, "La cantidad de elementos es 2. ");
  pa2m_afirmar(hash_insertar(hash, ( char*)"bienes", (void*)1) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_cantidad(hash)==3, "Dado un hash con 3 elementos la cantidad es 3. ");

  hash_destruir(hash);
}

bool funcion_de_prueba(hash_t* hash ,const char* clave,void* aux){  
	if(!clave){
    return true;
  }
  aux=aux;
  hash=hash;
  return false;
}
void dadoUnHash_AlCrearUnIteradorInterno_SeCreaUnIteradorInterno(){
  hash_t* hash= NULL;
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , 0)==0,"Si el hash es NULL no se puede iterar." );  
  pa2m_afirmar(hash_con_cada_clave(hash,NULL , 0)==0, "Si la funcion pasada es NULL no se puede iterar." );
  
  hash= hash_crear(NULL, 5);
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==0, "Dado un hash vacio itero sobre 0 elementos." );
  pa2m_afirmar(hash_insertar(hash, ( char*)"AC152AD", (void*)2) ==0, "Inserto un elemento.");
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==1, "Itero sobre 1 elemento." );
  pa2m_afirmar(hash_cantidad(hash)==1, "La cantidad de elementos es la esperada.");
  pa2m_afirmar(hash_insertar(hash, ( char*)"como", (void*)3) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==2, "Itero sobre 2 elementos." );
  pa2m_afirmar(hash_insertar(hash, ( char*)"estasss", (void*)3) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==3, "Itero sobre 3 elementos." );
  pa2m_afirmar(hash_insertar(hash, ( char*)"e", (void*)3) ==0, "Inserto otro elemento.");
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==4, "Itero sobre 4 elementos." );
  pa2m_afirmar(hash_obtener(hash, (char*)"AC152AD")== (void*)2, "Puedo obtener uno de los elementos insertados.");
  pa2m_afirmar(hash_cantidad(hash)==4, "La cantidad de elementos es la esperada.");
  hash_quitar(hash, (char*)"como");
  pa2m_afirmar(hash_cantidad(hash)==3, "Borre un elemento y la cantidad de elementos es la esperada.");
  hash_quitar(hash, (char*)"estasss");
  pa2m_afirmar(hash_cantidad(hash)==2, "Borre otro elemento y la cantidad de elementos es la esperada.");
  hash_quitar(hash, (char*)"e");
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==1, "Itero sobre 1 elementos." );
  pa2m_afirmar(hash_insertar(hash, ( char*)"chau", (void*)1) ==0, "Inserto un elemento .");
  pa2m_afirmar(hash_con_cada_clave(hash,funcion_de_prueba , NULL)==2, "Itero sobre 2 elementos." );
  pa2m_afirmar(hash_cantidad(hash)==2, "La cantidad de elementos es la esperada.");

  
  hash_destruir(hash);
}

int main(){
  pa2m_nuevo_grupo("Pruebas de insertar");
  dadoUnHashInexistente_SiIntentoInsertarUnPar_NoPuedoHacerlo();
  dadoUnHash_SiQuieroInsertarUnPar_PuedoHacerlo();

  pa2m_nuevo_grupo("Pruebas de quitar");
  dadoUnHashInexistente_SiQuieroBorrarUnPar_NoPuedoHAcerlo();
  dadoUnHash_SiQuieroBorrarUnPar_SiHayParesInsertadosPuedoHacerlo();

  pa2m_nuevo_grupo("Pruebas de obtener");
  dadaoUnHashInexistente_SiQuieroBuscarUnPar_NoPuedoHacerlo();
  dadaoUnHash_SiQuieroBuscarUnPar_SiSeEncuentraEnElHashPuedoHacerlo();

  pa2m_nuevo_grupo("Pruebas de contiene");
  dadoUnHashInexistente_SiBuscoUnElemento_NoLoEncuentro();
  dadoUnHash_SiBuscoUnElementoYLoEncuentro_MeDevuelveTrue();

  pa2m_nuevo_grupo("Pruebas de cantidad");
  dadoUnHashInexistente_SiQuieroSaberCuantosELementosHay_NopuedoHacerlo();
  dadoUnHash_SiQuieroSaberCuantosELementosHay_PuedoHacerlo();
  
  pa2m_nuevo_grupo("Pruebas de con cada clave");
  dadoUnHash_AlCrearUnIteradorInterno_SeCreaUnIteradorInterno();


  return pa2m_mostrar_reporte();
}
