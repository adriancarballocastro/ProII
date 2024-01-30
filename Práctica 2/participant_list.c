/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 14 / 04 / 2023
 */

#include "participant_list.h"
#include <string.h>
#include <stdlib.h>

/* Write your code here... */

void createEmptyListP(tListP *L){
    *L = NULLP;
    //Objetivo: Crea una lista vacía y la inicializa
    //Salida: Una lista vacía
    //Poscondición: La lista sin datos
}


bool isEmptyListP(tListP P){
    return(P==NULLP);
    //-Objetivo: Determinar si la lista está vacía
    //-Entrada: List: Lista a comprobar
    //-Salida: Verdadero si la lista está vacía, falso en caso contrario
}

bool createNodP(tPosP *q){
    *q =malloc(sizeof(struct tNodo));
    return (*q != NULL);
    //-Objetivo: Crear un nodo
    //-Entrada: Nodo a crear
    //-Precondición: Lista inicializada
    //-Salida: Un nodo creado
}

bool insertItemP(tItemP item,tListP *P){
    tPosP p,q;
    if(!createNodP(&q)) return false;
    else{
        q->data=item;
        q->next = NULLP;
        if(isEmptyListP(*P)){
            *P=q;
        }
        else if(strcmp(item.participantName,(*P)->data.participantName)<0){
            q->next =(*P);
            *P=q;
        }
        else{
            p=findPosition(item,*P);
            q->next=p -> next;
            p -> next = q;
        }
        return true;
    }

    //-Objetivo: Inserta un elemento en la lista según el campo participantName
    //-Entrada: ItemP: Contenido del elemento a insertar
    //List: Lista donde vamos a insertar
    //-Salida: List: Lista con el elemento ItemL insertado en la posición correspondiente segín su contenido y verdadero si se ha podido insertar, falso en caso contrario
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado
}

tPosP findPosition(tItemP item,tListP miL){
    tPosP pos;
    pos= miL;
    while((pos->next != NULLP)&&
    (strcmp(pos->next->data.participantName,item.participantName)<0))
        pos = pos -> next;
    return pos;
}

void updateItemP(tItemP d,tPosP p, tListP *L){
    p -> data = d;
    //-Objetivo: Modifica el contenido de un elemento de la lista
    //-Entrada: ItemP: Nuevo contenido a asignar al elemento en Position
    //PosP: Posición del elemento que queremos modificar
    //List: Lista a modificar
    //-Salida: List: Lista con el contenido del elemento modificado
    //-Precondición: PosP es una posición válida de la lista
}



tPosP findItemP(tParticipantName d,tListP lista){
    tPosP p;
    for(p=lista;(p!=NULL) &&(strcmp(p -> data.participantName,d)!=0);p=p->next);
    return p;
    //-Objetivo: Busca el primer elemento con cierto contenido en la lista
    //-Entrada: ItemP: Contenido del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: PosP: Posición del elemento encontrado o nulo si no se encuentra
}

tItemP getItemP(tPosP p, tListP L){
    return p->data;
    //-Objetivo: Recupera el contenido de un elemento de la lista
    //-Entrada: PosP: Posición del elemento buscado
    //List: Lista donde realizar la búsqueda
    //-Salida: ItemP: Contenido del elemento que está en PosL
    //-Precondición: Position es una posición válida en la lista
}


tPosP lastP(tListP L){
    tPosP p;
    for(p=L;p->next != NULL;p=p->next);
    return p;
    //-Objetivo: Devuelve la posición del último elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosP: Posición del último elemento
    //-Precondición: La lista no está vacía
}

tPosP previousP(tPosP p, tListP L){
    tPosP q;
    if(p== firstP(L)){
        return NULL;
    }else{
        for(q= firstP(L);q->next != p;q = nextP(q,L));
        return q;
    }
    //-Objetivo:Devuelve la posición del elemento anterior al actual
    //-Entrada: PosP: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: Posición del elemento anterior o nulo si es el primero
    //-Precondición: PosP es una posición válida de la lista
}

tPosP nextP(tPosP p,tListP L){
    return p-> next;
    //-Objetivo: Devuelve la posición del elemento siguiente al actual
    //-Entrada: PosP: Posición del elemento actual
    //List: Lista a manipular
    //-Salida: PosP: Posición del elemento siguiente o nulo si es el último
    //-Precondición: PosL es una posición válida de la lista
}


tPosP firstP(tListP L){
    return L;
    //-Objetivo: Devuelve la posición del primer elemento de la lista
    //-Entrada: List: Lista a manipular
    //-Salida: PosP: Posición del primer elemento
    //-Precondición: La lista no está vacía
}


void deleteAtPositionP(tPosP p ,tListP *L){
    tPosP q;
    if(p == firstP(*L)){    //Se elimina en la primera posición
        *L = (*L) -> next;
    }
    else{
        if(p->next == NULL) {     //Se elimina en la última posición
            for (q = *L; q->next != p; q = q->next);
            q->next = NULL;
        }
        else{  //Se elimina en una posición intermedia
            q=p->next;
            p -> data = q -> data;
            p -> next = q -> next;
            p=q;
        }
    }
    free(p);
    //-Objetivo: Elimina de la lista un elemento con cierta posición
    //-Entrada: PosP: Posición del elemento a eliminar
    //List: Lista a modificar
    //-Salida: List: Lista sin el elemento correspondiente a PosL
    //-Precondición: PosP es una posición válida de la lista
    //-Postcondición: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado
}
