/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 10 / 03 / 2023
 */

#include <stdio.h>
#include "dynamic_list.h"
#include <stdlib.h>
#include <string.h>
/* Write your code here... */

void createEmptyList(tList *L){
    *L = LNULL;
    //Objetivo: Crea una lista vacía y la inicializa
    //Salida: Una lista vacía
    //Poscondición: La lista sin datos
}


bool isEmptyList(tList *L){
    return(L==LNULL);
    //-Objetivo: Determinar si la lista está vacía
    //-Entrada: List: Lista a comprobar
    //-Salida: Verdadero si la lista está vacía, falso en caso contrario
}

bool createNod(tPosL *q){
    *q =malloc(sizeof(struct tNodo));
    return (*q != LNULL);
    //-Objetivo: Crear un nodo
    //-Entrada: Nodo a crear
    //-Precondición: Lista inicializada
    //-Salida: Un nodo creado
}

bool insertItem(tItemL d,tPosL p,tList *L){
    tPosL q,r;
    if(!createNod(&q)){
        return false;
    }
    else {
        q->data = d;
        q -> next = LNULL;
        //Si la lista se encuentra vacía, se añade el elemento a la primera posición y el puntero List apunta al primer nodo
        if (*L==LNULL) {
            *L = q;
        }else{
            if(p == LNULL) {    //Si la posición recibida es nula, se añade como último elemento
                r=*L;
                while( r->next != LNULL)
                    r = r -> next;
                r->next = q;
            }else{
                if(p == *L) {   //Si se recibe un posición identica al puntero List, hay que añadir el elemento a la primera posición
                    q->next = *L;
                    *L = q;
                }else {    //Si no se cumple ninguna condición, se inserta en una posición intermedia
                    q->data = p->data;
                    p->data = d;
                    q->next = p->next;
                    p->next = q;
                }
            }
        }
        return true;
    }
    //-Objetivo: Inserta un elemento en la lista según el criterio de ordenación sobre el campo ItemL
    //-Entrada: ItemL: Contenido del elemento a insertar
    //List: Lista donde vamos a insertar
    //-Salida: List: Lista con el elemento ItemL insertado en la posición correspondiente segín su contenido y verdadero si se ha podido insertar, falso en caso contrario
    //-Precondición: La lista está inicializada
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado
}


void updateItem(tItemL d,tPosL p, tList *L){
    p -> data = d;
    //-Objetivo: Modifica el contenido de un elemento de la lista
    //-Entrada: ItemL: Nuevo contenido a asignar al elemento en Position
    //PosL: Posición del elemento que queremos modificar
    //List: Lista a modificar
    //-Salida: List: Lista con el contenido del elemento modificado
    //-Precondición: PosL es una posición válida de la lista
}



tPosL findItem(tParticipantName d,tList L){
    tPosL p;
    for(p=L;(p!=LNULL)&&(strcmp(p -> data.participantName,d)!=0);p=p->next);
    return p;
    //-Objetivo: Busca el primer elemento con cierto contenido en la lista
    //-Entrada: ItemL: Contenido del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: PosL: Posición del elemento encontrado o nulo si no se encuentra
}

tItemL getItem(tPosL p, tList L){
    return p->data;
    //-Objetivo: Recupera el contenido de un elemento de la lista
    //-Entrada: PosL: Posición del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: ItemL: Contenido del elemento que está en PosL
    //-Precondición: Position es una posición válida en la lista
}


tPosL last(tList L){
    tPosL p;
    for(p=L;p->next != NULL;p=p->next);
    return p;
    //-Objetivo: Devuelve la posición del último elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosL: Posición del último elemento
    //-Precondición: La lista no está vacía
}

tPosL previous(tPosL p, tList L){
    tPosL q;
    if(p== first(L)){
        return NULL;
    }else{
        for(q= first(L);q->next != p;q = next(q,L));
        return q;
    }
    //-Objetivo:  Devuelve la posición del elemento anterior al actual
    //-Entrada: PosL: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: Posición del elemento anterior o nulo si es el primero
    //-Precondición: PosL es una posición válida de la lista
}

tPosL next(tPosL p,tList L){
    return p-> next;
    //-Objetivo:  Devuelve la posición del elemento siguiente al actual
    //-Entrada: PosL: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: PosL: Posición del elemento siguiente o nulo si es el último
    //-Precondición: PosL es una posición válida de la lista
}


tPosL first(tList L){
    return L;
    //-Objetivo: Devuelve la posición del primer elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosL: Posición del primer elemento
    //-Precondición: La lista no está vacía
}


void deleteAtPosition(tPosL p ,tList *L){
    tPosL q;
    if(p == first(*L)){    //Se elimina en la primera posición
        *L = (*L) -> next;
    }
    else{
        if(p->next == LNULL) {     //Se elimina en la última posición
            for (q = *L; q->next != p; q = q->next);
            q->next = NULL;
        }
        else{  //Se elmina en una posición intermedia
        q=p->next;
        p -> data = q -> data;
        p -> next = q -> next;
        p=q;
        }
    }
    free(p);
    //-Objetivo: Elimina de la lista un elemento con cierta posición
    //-Entrada: PosL: Posición del elemento a eliminar
    //List: Lista a modificar
    //-Salida: List: Lista sin el elemento correspondiente a PosL
    //-Precondición: PosL es una posición válida de la lista
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado
}
