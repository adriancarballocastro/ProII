/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 14 / 04 / 2023
 */

#include "jury_list.h"
#include "participant_list.h"
#include <string.h>

/* Write your code here... */

void createEmptyListJ(tListJ *L){
    L -> lastPos = NULLJ;
    //Objetivo: Crea una lista vacía y la inicializa
    //Salida: Una lista vacía
    //Poscondición: La lista sin datos
}



bool isEmptyListJ(tListJ L){
    return (L.lastPos == NULLJ);
    //-Objetivo: Determinar si la lista está vacía
    //-Entrada: List: Lista a comprobar
    //-Salida: Verdadero si la lista está vacía, falso en caso contrario
}


tPosJ firstJ(tListJ L){
    return 0;
    //-Objetivo: Devuelve la posición del primer elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosJ: Posición del primer elemento
    //-Precondición: La lista no está vacía
}

tPosJ lastJ(tListJ L){
    return L.lastPos;
    //-Objetivo: Devuelve la posición del último elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosJ: Posición del último elemento
    //-Precondición: La lista no está vacía
}

tPosJ previousJ(tPosJ p, tListJ L){
    return --p;
    //-Objetivo:Devuelve la posición del elemento anterior al actual
    //-Entrada: PosJ: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: Posición del elemento anterior o nulo si es el primero
    //-Precondición: PosJ es una posición válida de la lista
}

tPosJ nextJ(tPosJ p,tListJ L){
    if(p==lastJ(L)){
        return NULLJ;
    }
    else return ++p;
    //-Objetivo:Devuelve la posición del elemento siguiente al actual
    //-Entrada: PosJ: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: PosJ: Posición del elemento siguiente o nulo si es el último
    //-Precondición: PosJ es una posición válida de la lista
}


void deleteAtPositionJ(tPosJ p,tListJ *L){
    tPosJ i;
    L -> lastPos--;
    for(i=p;i<=L -> lastPos;i++){
        L->data[i] = L -> data[i+1];
    }
    //-Objetivo: Elimina de la lista un elemento con cierta posición
    //-Entrada: PosL: Posición del elemento a eliminar
    //List: Lista a modificar
    //-Salida: List: Lista sin el elemento correspondiente a PosL
    //-Precondición: PosJ es una posición válida de la lista
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado
}

tPosJ findItemJ(tParticipantName d, tListJ L){
    tPosJ p;
    if(isEmptyListJ(L)) {
        return NULLJ;
    } else {
        for(p = 0; (p < L.lastPos) && (strcmp(L.data[p].juryName,d)!=0); p++);
        if(strcmp(L.data[p].juryName,d)==0) {
            return p;
        } else {
            return NULLJ;
        }
    }
    //-Objetivo: Busca el primer elemento con cierto contenido en la lista
    //-Entrada: ItemJ: Contenido del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: PosJ: Posición del elemento encontrado o nulo si no se encuentra
}


tItemJ getItemJ(tPosJ p, tListJ L){

    return L.data[p];

    //-Objetivo: Recupera el contenido de un elemento de la lista
    //-Entrada: PosJ: Posición del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: ItemJ: Contenido del elemento que está en PosL
    //-Precondición: Position es una posición válida en la lista
}

void updateItemJ(tItemJ d, tPosJ p, tListJ *L){
    L -> data[p]=d;
    //-Objetivo: Modifica el contenido de un elemento de la lista
    //-Entrada: ItemL: Nuevo contenido a asignar al elemento en Position
    //PosL: Posición del elemento que queremos modificar
    //List: Lista a modificar
    //-Salida: List: Lista con el contenido del elemento modificado
    //-Precondición: PosL es una posición válida de la lista
}

bool insertItemJ(tItemJ d, tListJ *L){
    tPosJ i;
    if(L ->lastPos == MAX-1){
        return false;
    }
    else{
        if(isEmptyListJ(*L)){
            L-> lastPos++;
            L-> data[L->lastPos] = d;
            return true;
        }else{
            L-> lastPos++;

            for (i=L->lastPos;(i>0)&&(strcmp(d.juryName,L->data[i-1].juryName)<0);i--) {
                L->data[i]= L->data[i-1];
            }
            L -> data[i]=d;
            return true;
        }
    }
    //-Objetivo: Inserta un elemento en la lista según juryName
    //-Entrada: ItemJ: Contenido del elemento a insertar
    //List: Lista donde vamos a insertar
    //-Salida: List: Lista con el elemento ItemL insertado en la posición correspondiente segín su contenido y verdadero si se ha podido insertar, falso en caso contrario
    //-Precondición: La lista está inicializada
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado
}