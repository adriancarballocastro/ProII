/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 03 / 03 / 2023
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

/* Write your code here... */
#include <stdbool.h>
#define MAX 25
#define LNULL -1
typedef int tPosL;
typedef struct tList{
    tItemL data[MAX];
    tPosL lastPos;
}tList;

void createEmptyList(tList *L);     //Crea una lista vacía.
void updateItem(tItemL d, tPosL p, tList *L);   //Modifica el contenido del elemento situado en la posición indicada.
bool isEmptyList(tList L);  //Determina si la lista está vacía.
tItemL getItem(tPosL p, tList L);   //Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
tPosL first(tList L);   //Devuelve la posición del primer elemento de la lista.
tPosL last(tList L);    //Devuelve la posición del último elemento de la lista.
tPosL previous(tPosL p, tList L);   //Devuelve la posición en la lista del elemento anterior al de la posición indicada (o LNULL si la posición no tiene anterior).
tPosL next(tPosL p,tList L);    //Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).
bool insertItem(tItemL d, tPosL p, tList *L);   //Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final. Devuelve un valor true si el elemento fue insertado; false en caso contrario.
void deleteAtPosition(tPosL p,tList *L);    //Elimina de la lista el elemento que ocupa la posición indicada.
tPosL findItem(tParticipantName d, tList L);    //Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda con el indicado (o LNULL si no existe tal elemento).

#endif //STATIC_LIST_H
