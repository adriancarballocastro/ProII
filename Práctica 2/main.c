/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 14 / 04 / 2023
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "jury_list.h"

#define MAX_BUFFER 255

bool new(char *param1,char *param2,char *param3,tListJ *J);
bool create(char *param1,char *param2,tListJ *J);
bool vote(char *param1,char *param2, tListJ *J);
bool stats(tListJ J);
bool disqualify(char *param1,tListJ *J);
bool delete(tListJ *J);
bool winner(tListJ J);
char *participantLocation(tEUParticipant location);

char *participantLocation(tEUParticipant location){
    char* loc;
    if (location) {
        loc = "eu";
    } else {
        loc = "non-eu";
    }
    return loc;

    //-Objetivo: Saber si un participante es de eu o no
    //-Entrada: tEUParticipant: booleano que guarda de donde es el participante
    //-Salida: char: Localización del participante
}

bool create(char *juryName,char *totalVoters,tListJ *J){
    tItemJ item;
    strcpy(item.juryName, juryName);
    item.totalVoters= atoi(totalVoters);
    item.validVotes=0;
    item.nullVotes=0;
    createEmptyListP(&item.participantList);
                                                                            //Creamos un jurado
    if(findItemJ(juryName,*J) == NULLJ){
        if(insertItemJ(item, J)){                                           //Insertamos si no existe si no marca error
            printf("* Create: jury %s totalvoters %s\n",juryName,totalVoters);
            return true;
        }
    }
    return false;
    //-Objetivo: Añadir un jurado con el número de votantes indicado ordenado según el campo juryName
    //-Entrada: tListJ: Lista de jurados
    //List: Lista a modificar
    //-Salida: List: Lista modificada si el jurado no existe
    //-Postcondición: La lista pudo haber sido modificada
}

bool new(char *juryName,char *participantName,char *location,tListJ *J){
    tItemP item;

    strcpy(item.participantName, participantName);
    if(strcmp(location,"eu")==0){
        item.EUParticipant=true;
    }
    else{
        item.EUParticipant=false;
    }
    item.numVotes=0;
                                                    //Creamos el participante

    tPosJ posJury = findItemJ(juryName,*J);           //Comprueba que el jurado donde se quiere insertar el participante existe

    if(posJury != NULLJ){
        tItemJ jury;
        jury = getItemJ(posJury,*J);
        tPosP posPart = findItemP(participantName,jury.participantList);
        if(posPart == NULLP){
                    if(isEmptyListP(jury.participantList))
                        createEmptyListP(&jury.participantList);

                    if(insertItemP(item, &jury.participantList)==true){
                            updateItemJ(jury,posJury,J);                            //Inserta el item del participante
                            printf("* New: jury %s participant %s location %s\n",juryName,item.participantName,participantLocation(item.EUParticipant));
                            return true;
                    }else return false;
            }else return false;
        }else return false;
    //-Objetivo: Añadir un participante al jurado indicando ordenándolo según el campo participantName
    //-Entrada: tListJ: Lista de jurados
    //          char: nombre del jurado y participante
    //List: Lista a modificar
    //-Salida: List: Lista modificada si el jurado existe y el participante no está en esa lista
    //-Postcondición: La lista pudo haber sido modificada
}

bool vote(char *juryName,char *participantName, tListJ *J){

    tPosJ pos1 = findItemJ(juryName,*J);                  //Comprueba que el jurado exista

    if(pos1 != NULLJ){
        tItemJ jury = getItemJ(pos1,*J);

        tPosP pos2 = findItemP(participantName,jury.participantList);            //Comprueba que el participante exista

        if(pos2 != NULLP){
            tItemP participant = getItemP(pos2,jury.participantList);
            (participant.numVotes)++;
            (jury.validVotes)++;                                //Suma los votos a los del participante y a los del jurado



            updateItemP(participant,pos2,&jury.participantList);
            updateItemJ(jury,pos1,J);


            printf("* Vote: jury %s participant %s location %s numvotes %d\n", juryName, participantName,participantLocation(participant.EUParticipant),participant.numVotes);
            return true;

        }else{
            jury.nullVotes++;                   //Si no existe el participante cuenta su voto como nulo en el jurado correspondiente
            updateItemJ(jury,pos1,J);

            printf("+ Error: Vote not possible. Participant %s not found in jury %s. NULLVOTE\n",participantName,juryName);
            return true;
        }
    }else return false;

    //-Objetivo: Sumar un voto al participante de un jurado en concreto
    //-Entrada: tListJ: Lista de jurados
    //          char: nombre del jurado y participante
    //List: Lista a modificar
    //-Salida: List: Lista modificada si el participante existe
    //-Postcondición: La lista pudo haber sido modificada
}

bool stats(tListJ J) {
    if (!isEmptyListJ(J)) {
        tPosJ posJury;
        tItemJ jury;
        for (posJury = firstJ(J); posJury != NULLJ; posJury = nextJ(posJury, J)) {            //Recorre la lista de jurados
            jury = getItemJ(posJury, J);
            printf("Jury %s\n", jury.juryName);
            if (isEmptyListP(jury.participantList)) {               //Comprueba que el jurado tenga algún participante
                printf("No participants\n");
            } else {

                tPosP posPart;
                tItemP part;
                for (posPart = firstP(jury.participantList);posPart != NULLP;posPart = nextP(posPart,jury.participantList)) {       //Recorre la lista de participantes
                    part = getItemP(posPart,jury.participantList);

                    

                    float porcentaje;                   //Calcula el porcentaje de votos
                    if(jury.validVotes == 0){
                        porcentaje = 0;
                    }
                    else porcentaje = (float)part.numVotes / (float)jury.validVotes;

                    printf("Participant %s location %s numvotes %d (%.2f%%)\n",part.participantName,participantLocation(part.EUParticipant),part.numVotes,porcentaje*100);
                }


            }
            printf("Nullvotes %d\n", jury.nullVotes);                   //Votos nulos
            int votostotales = jury.validVotes + jury.nullVotes;
            float porcentaje =((float)(votostotales) )/ (float )jury.totalVoters;           //Calcula la participación

            printf("Participation: %d votes from %d voters (%.2f%%)\n\n", votostotales,jury.totalVoters, porcentaje*100);
        }
        return true;
    } else return false;

    //-Objetivo: Mostrar datos sobre la lista y sus integrantes
    //-Entrada: tListJ: Lista de jurados
    //List: Lista a modificar
}

bool disqualify(char *participantName,tListJ *J){
    if(isEmptyListJ(*J)){
        return false;
    }
    else{
        tPosJ posJury;
        tItemJ jury;
        for (posJury = firstJ(*J); posJury != NULLJ; posJury = nextJ(posJury, *J)) {                //Recorremos la lista de jurados

            jury = getItemJ(posJury, *J);
            printf("Jury %s\n",jury.juryName);
            tPosP posPart = findItemP(participantName,jury.participantList);                                 //Busca al participante
            if(posPart != NULLP){
                tItemP part = getItemP(posPart,jury.participantList);
                jury.nullVotes += part.numVotes;                                                    //Pasa los votos del participante a nulos
                jury.validVotes -= part.numVotes;                                                   //Modifica la cantidad de votos válidos
                deleteAtPositionP(posPart,&jury.participantList);                                   //Borra al participante
                updateItemJ(jury,posJury,J);                                                        //Actualiza la lista
                printf("Participant %s disqualified\n\n",participantName);
            }
        }
        return true;
    }
    //-Objetivo: Eliminar un participante de todas las listas de todos los jurados en el que esté
    //-Entrada: tListJ: Lista de jurados
    //          char: nombre del participante
    //List: Lista a modificar
    //-Salida: List: Lista modificada si existe algún participante en la lista
    //-Postcondición: La lista pudo haber sido modificada
}

bool delete(tListJ *J) {
    if (isEmptyListJ(*J)) {         //Comprueba si la lista está vacía
        return false;
    } else {
        tPosJ posJury;
        tItemJ jury;
        for (posJury = firstJ(*J); posJury != NULLJ; posJury = nextJ(posJury, *J)) {        //Recorre la lista de jurados
            jury = getItemJ(posJury, *J);
            if (jury.validVotes == 0) {                 //Si tiene 0 votos válidos borra el jurado
                deleteAtPositionJ(posJury, J);
                printf("* Remove: jury %s\n", jury.juryName);
                posJury = previousJ(posJury,*J);
            }
        }
        return true;
    }
    //-Objetivo: Eliminar todos los jurados que tienen 0 votos válidos
    //-Entrada: tListJ: Lista de jurados
    //List: Lista a modificar
    //-Salida: List: Lista modificada si hay algún jurado con 0 votos válidos
    //-Postcondición: La lista pudo haber sido modificada
}

bool winner(tListJ J) {
    if (isEmptyListJ(J)) {                 //Comprueba si la lista está vacía
        return false;
    } else {
        tPosJ posJury;
        tItemJ jury;
        for (posJury = firstJ(J); posJury != NULLJ; posJury = nextJ(posJury, J)) {            //Recorre la lista de jurados
            jury = getItemJ(posJury, J);
            printf("Jury %s\n", jury.juryName);

            if (!isEmptyListP(jury.participantList)) {                          //Comprueba que el jurado tenga algún participante
                tPosP posPart;
                tItemP part;
                tNumVotes wEU = -1, wnEU = -1;                                  //Inicializa variables para guardar el número de votos de cada ganador
                tParticipantName weuName, wneuName;                             //Inicializa variables para guardar el nombre de cada ganador
                bool empateEU = false,empateNEU=false;                          //Bool para saber si hay empate
                for (posPart = firstP(jury.participantList);posPart != NULLP; posPart = nextP(posPart, jury.participantList)) {         //Recorre la lista de participantes
                    part = getItemP(posPart, jury.participantList);



                    if (part.EUParticipant == true) {               //Comprueba los valores de cada participante con el mayor registrado según si pertenece a eu o no
                        if (wEU == part.numVotes) {
                            empateEU = true;
                        } else {
                            if (wEU < part.numVotes) {
                                wEU = part.numVotes;
                                strcpy(weuName,part.participantName);
                            }
                        }
                    } else {
                        if (wnEU == part.numVotes) {
                            empateNEU = true;
                        } else {
                            if (wnEU < part.numVotes) {
                                wnEU = part.numVotes;
                                strcpy(wneuName,part.participantName);
                            }
                        }
                    }
                }

                //Aquí se muestran los resultados de cada jurado según el resultado del recuento

                if(empateEU){                                   //Si hay empate de participantes EU
                    printf("Location eu: No winner\n");
                }
                else{
                    if(wEU==-1){                                //Si en la lista no hay países de EU
                        printf("Location eu: No winner\n");
                    }
                    else{                                       //Ganador EU
                        printf("Location eu: Participant %s numvotes %d\n",weuName,wEU);
                    }
                }
                if(empateNEU){                             //Si hay empate de participantes no-EU
                    printf("Location non-eu: No winner\n\n");
                }
                else{
                    if(wnEU==-1){                           //Si en la lista no hay participantes de no-EU
                        printf("Location non-eu: No winner\n\n");
                    }
                    else{                                   //Ganador no-EU
                        printf("Location non-eu: Participant %s numvotes %d\n\n",wneuName,wnEU);
                    }
                }


            } else {                        //Resultados en caso de que un jurado no tenga ningún participante
                printf("Location eu: No winner\n");
                printf("Location non-eu: No winner\n\n");
            }
        }
        return true;
    }
    //-Objetivo: Determinar el participante con más votos begun el campo EUParticipant
    //-Entrada: tListJ: Lista de jurados
    //List: Lista a modificar
}


void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3,tListJ *J) {

    printf("********************\n");

    switch (command) {
        case 'C':
            printf("%s %c: jury %s totalvoters %s\n",commandNumber,command,param1,param2);
            if(!create(param1,param2,J)){
                printf("+ Error: Create not possible\n");
            }
            break;
        case 'N':
            printf("%s %c: jury %s participant %s location %s\n",commandNumber,command,param1,param2,param3);
            if(!new(param1,param2,param3,J)){
                printf("+ Error: New not possible\n");
            }
            break;
        case 'V':
            printf("%s %c: jury %s participant %s\n",commandNumber,command,param1,param2);
            if(!vote(param1,param2,J)){
                printf("+ Error: Vote not possible\n");
            }
            break;
        case 'S':
            printf("%s %c:\n",commandNumber,command);
            if(!stats(*J)){
                printf("+ Error: Stats not possible\n");
            }
            break;
        case 'D':
            printf("%s %c: participant %s\n",commandNumber,command,param1);
            if(!disqualify(param1,J)){
                printf("+ Error: Disqualify not possible\n");
            }
            break;
        case 'R':
            printf("%s %c:\n",commandNumber,command);
            if(!delete(J)){
                printf("+ Error: Remove not possible\n");
            }
            break;
        case 'W':
            printf("%s %c:\n",commandNumber,command);
            if(!winner(*J)){
                printf("+ Error: Winner not possible\n");
            }
            break;
        default:
            printf("+ Error\n");
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    //Creamos lista de jurado
    tListJ J;
    createEmptyListJ(&J);


    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3,&J);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "create.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}
