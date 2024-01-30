/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 10 / 03 / 2023
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"

/* Write your code here... */
#define LNULL NULL

typedef struct tNodo* tPosL;
struct tNodo{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

tPosL first(tList L);   //Devuelve la posición del primer elemento de la lista.
void createEmptyList(tList *L);    //Crea una lista vacía.
bool isEmptyList(tList *L);     //Determina si la lista está vacía.
bool createNod(tPosL *pos);     //Crea un nodo
bool insertItem(tItemL d,tPosL p,tList *L);     //Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final. Devuelve un valor true si el elemento fue insertado; false en caso contrario.
void updateItem(tItemL d,tPosL p, tList *L);    //Modifica el contenido del elemento situado en la posición indicada.
void deleteAtPosition(tPosL p, tList *L);   //Elimina de la lista el elemento que ocupa la posición indicada.
tPosL findItem(tParticipantName d,tList L);     //Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda con el indicado (o LNULL si no existe tal elemento).
tItemL getItem(tPosL p, tList L);   //Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
tPosL last(tList L);    //Devuelve la posición del último elemento de la lista.
tPosL previous(tPosL p, tList L);   //Devuelve la posición en la lista del elemento anterior al de la posición indicada (o LNULL si la posición no tiene anterior).
tPosL next(tPosL p,tList L);    //Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).

#endif //DYNAMIC_LIST_H
