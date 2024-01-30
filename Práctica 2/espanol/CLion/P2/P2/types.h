/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 14 / 04 / 2023
 */

#ifndef PRO2_2023_P2_TYPES_H
#define PRO2_2023_P2_TYPES_H

#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

typedef char tJuryName[NAME_LENGTH_LIMIT];              //Nombre del jurado

typedef char tParticipantName[NAME_LENGTH_LIMIT];       //Nombre de un participante

typedef int tNumVotes;                                  //Numero de votos

typedef bool tEUParticipant;                            //Bool para guardar la pertenecia a la UE


#endif //PRO2_2023_P2_TYPES_H
