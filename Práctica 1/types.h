/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 10 / 03 / 2023
 */

#ifndef PRO2_2023_P1_TYPES_H
#define PRO2_2023_P1_TYPES_H


#define NAME_LENGTH_LIMIT 25    //Longitud máxima de un nombre
#include <stdbool.h>

typedef char tParticipantName[NAME_LENGTH_LIMIT];   //Nombre del participante
typedef int tNumVotes;  //Número de votos recibidos
typedef bool tEUParticipant;  //Pertenencia a la Unión Europea


typedef struct tItemL { //Datos de un participante
    tParticipantName participantName;
    tNumVotes numVotes;
    tEUParticipant EUParticipant;
} tItemL;

#endif //PRO2_2023_P1_TYPES_H
