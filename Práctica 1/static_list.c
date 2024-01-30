/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 03 / 03 / 2023
 */

#include "static_list.h"
#include <string.h>
#include <stdio.h>

/* Write your code here... */


void createEmptyList(tList *L){
    L -> lastPos = LNULL;
    //Objetivo: Crea una lista vacía y la inicializa
    //Salida: Una lista vacía
    //Poscondición: La lista sin datos
}



bool isEmptyList(tList L){
    return (L.lastPos == LNULL);
    //-Objetivo: Determinar si la lista está vacía
    //-Entrada: List: Lista a comprobar
    //-Salida: Verdadero si la lista está vacía, falso en caso contrario
}


tPosL first(tList L){
    return 0;
    //-Objetivo: Devuelve la posición del primer elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosL: Posición del primer elemento
    //-Precondición: La lista no está vacía
}

tPosL last(tList L){
    return L.lastPos;
    //-Objetivo: Devuelve la posición del último elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosL: Posición del último elemento
    //-Precondición: La lista no está vacía
}

tPosL previous(tPosL p, tList L){
    return --p;
    //-Objetivo:  Devuelve la posición del elemento anterior al actual
    //-Entrada: PosL: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: Posición del elemento anterior o nulo si es el primero
    //-Precondición: PosL es una posición válida de la lista
}

tPosL next(tPosL p,tList L){
    if(p==last(L)){
        return LNULL;
    }
    else return ++p;
    //-Objetivo:  Devuelve la posición del elemento siguiente al actual
    //-Entrada: PosL: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: PosL: Posición del elemento siguiente o nulo si es el último
    //-Precondición: PosL es una posición válida de la lista
}


void deleteAtPosition(tPosL p,tList *L){
    tPosL i;
    L -> lastPos--;
    for(i=p;i<=L -> lastPos;i++){
        L->data[i] = L -> data[i+1];
    }
    //-Objetivo: Elimina de la lista un elemento con cierta posición
    //-Entrada: PosL: Posición del elemento a eliminar
    //List: Lista a modificar
    //-Salida: List: Lista sin el elemento correspondiente a PosL
    //-Precondición: PosL es una posición válida de la lista
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado
}

tPosL findItem(tParticipantName d, tList L){
    tPosL p;
    if(L.lastPos==LNULL) {
        return LNULL;
    } else {
        for(p = 0; (p < L.lastPos) && (strcmp(L.data[p].participantName,d)!=0); p++);
        if(strcmp(L.data[p].participantName,d)==0) {
            return p;
        } else {
            return LNULL;
        }
    }
    //-Objetivo: Busca el primer elemento con cierto contenido en la lista
    //-Entrada: ItemL: Contenido del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: PosL: Posición del elemento encontrado o nulo si no se encuentra
}


tItemL getItem(tPosL p, tList L){

    return L.data[p];

    //-Objetivo: Recupera el contenido de un elemento de la lista
    //-Entrada: PosL: Posición del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: ItemL: Contenido del elemento que está en PosL
    //-Precondición: Position es una posición válida en la lista
}

void updateItem(tItemL d, tPosL p, tList *L){
    L -> data[p]=d;
    //-Objetivo: Modifica el contenido de un elemento de la lista
    //-Entrada: ItemL: Nuevo contenido a asignar al elemento en Position
    //PosL: Posición del elemento que queremos modificar
    //List: Lista a modificar
    //-Salida: List: Lista con el contenido del elemento modificado
    //-Precondición: PosL es una posición válida de la lista
}

bool insertItem(tItemL d,tPosL p, tList *L){
    tPosL i;
    if(L ->lastPos == MAX-1){
        return false;
    }
    else{
        L-> lastPos++;
        if(p==LNULL){
            L-> data[L->lastPos] = d;
        }else{
            for(i=L->lastPos; i>=p+1;i--)
                L-> data[i] = L-> data[i-1];
            L -> data[p]=d;
            return true;
        }
    }
    //-Objetivo: Inserta un elemento en la lista según el criterio de ordenación sobre el campo ItemL
    //-Entrada: ItemL: Contenido del elemento a insertar
    //List: Lista donde vamos a insertar
    //-Salida: List: Lista con el elemento ItemL insertado en la posición correspondiente segín su contenido y verdadero si se ha podido insertar, falso en caso contrario
    //-Precondición: La lista está inicializada
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado
}

