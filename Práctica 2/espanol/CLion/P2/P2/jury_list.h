/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 14 / 04 / 2023
 */

#ifndef JURY_LIST_H
#define JURY_LIST_H

#include "types.h"
#include "participant_list.h"

/* Write your code here... */
#include <stdbool.h>
#define MAX 10
#define  NULLJ -1       //Variable nula

typedef struct tItemJ{
    tJuryName juryName;
    tNumVotes totalVoters;
    tNumVotes validVotes;
    tNumVotes nullVotes;
    tListP participantList;
}tItemJ;                //Datos de un jurado

typedef int tPosJ;

typedef struct tListJ{
    tItemJ data[MAX];
    tPosJ lastPos;
}tListJ;                //Lista de Jurados

void createEmptyListJ(tListJ *L);     //Crea una lista vacía.
void updateItemJ(tItemJ d, tPosJ p, tListJ *L);   //Modifica el contenido del elemento situado en la posición indicada.
bool isEmptyListJ(tListJ L);  //Determina si la lista está vacía.
tItemJ getItemJ(tPosJ p, tListJ L);   //Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
tPosJ firstJ(tListJ L);   //Devuelve la posición del primer elemento de la lista.
tPosJ lastJ(tListJ L);    //Devuelve la posición del último elemento de la lista.
tPosJ previousJ(tPosJ p, tListJ L);   //Devuelve la posición en la lista del elemento anterior al de la posición indicada (o LNULL si la posición no tiene anterior).
tPosJ nextJ(tPosJ p,tListJ L);    //Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).
bool insertItemJ(tItemJ d, tListJ *L);   //Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final. Devuelve un valor true si el elemento fue insertado; false en caso contrario.
void deleteAtPositionJ(tPosJ p,tListJ *L);    //Elimina de la lista el elemento que ocupa la posición indicada.
tPosJ findItemJ(tJuryName d, tListJ L);    //Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda con el indicado (o LNULL si no existe tal elemento).

#endif
