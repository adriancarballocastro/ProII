/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 14 / 04 / 2023
 */

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include "types.h"

/* Write your code here... */
#define NULLP NULL              //Variable nula

typedef struct tItemP {         //Datos de un participante
    tParticipantName participantName;
    tNumVotes numVotes;
    tEUParticipant EUParticipant;
} tItemP;

typedef struct tNodo* tPosP;

struct tNodo{
    tItemP data;
    tPosP next;
};
typedef tPosP tListP;       //Lista de participantes



tPosP firstP(tListP L);   //Devuelve la posición del primer elemento de la lista.
void createEmptyListP(tListP *L);    //Crea una lista vacía.
bool isEmptyListP(tListP P);     //Determina si la lista está vacía.
bool createNodP(tPosP *pos);     //Crea un nodo
bool insertItemP(tItemP d,tListP *L);     //Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final. Devuelve un valor true si el elemento fue insertado; false en caso contrario.
void updateItemP(tItemP d,tPosP p, tListP *L);    //Modifica el contenido del elemento situado en la posición indicada.
void deleteAtPositionP(tPosP p, tListP *L);   //Elimina de la lista el elemento que ocupa la posición indicada.
tPosP findItemP(tParticipantName d,tListP P);     //Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda con el indicado (o LNULL si no existe tal elemento).
tItemP getItemP(tPosP p, tListP L);   //Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
tPosP lastP(tListP L);    //Devuelve la posición del último elemento de la lista.
tPosP previousP(tPosP p, tListP L);   //Devuelve la posición en la lista del elemento anterior al de la posición indicada (o LNULL si la posición no tiene anterior).
tPosP nextP(tPosP p,tListP L);    //Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).
tPosP findPosition(tItemP d,tListP miL);

#endif
