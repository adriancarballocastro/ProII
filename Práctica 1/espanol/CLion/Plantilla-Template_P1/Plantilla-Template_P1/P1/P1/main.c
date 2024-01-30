/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Carballo Castro,Adrián LOGIN 1: adrian.carballo
 * AUTHOR 2: Rodríguez Rodríguez,Eladio LOGIN 2: eladio.rodriguez
 * GROUP: 4.1
 * DATE: 15 / 03 / 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif




int new(char *commandNumber, char command, char *param1, char *param2,tList *L){
    /*Se añade al final de la lista el nuevo participante asigando sus votos a cero y se guarda si pertenece a la UE o no*/

    tItemL item;

    strcpy(item.participantName, param1);
    if(strcmp(param2,"eu")==0){
        item.EUParticipant=true;
    }
    else{
        item.EUParticipant=false;
    }
    item.numVotes=0;
    if(findItem(param1,*L)== LNULL){
        insertItem(item, LNULL, L);
        printf("* New: participant %s location %s\n",param1,param2);
        return 1;
    }
    else return 0;
}

int vote(char *commandNumber, char command, char *param1, char *param2,tList *L,int *votosnulos,int *votosvalidos){
    /*Busca el participante y le añade un voto, si no lo encuentra ese voto pasa a contarse como nulo*/
        if(findItem(param1,*L)==LNULL){
            (*votosnulos)++;
            return 0;
        }
        else{
            tItemL item;
            tPosL pos;
            pos = findItem(param1, *L);
            item = getItem(pos, *L);
            item.numVotes++;
            updateItem(item,pos,L);
            char participantLocation[8];
            if(item.EUParticipant==true){
                strcpy(participantLocation, "eu");
            }
            else{
                strcpy(participantLocation ,"non-eu");
            }
            printf("* Vote: participant %s location %s numvotes %d\n",param1,participantLocation,item.numVotes);
            (*votosvalidos)++;
            return 1;
        }
}

int disqualify(char *commandNumber, char command,char *param1,char *param2,tList *L,int *votosnulos,int *votosvalidos){
    /*Busca al participante, pasa sus votos a nulos y lo borra de la lista, si no esta ese participante en la lista imprime un error*/
    tItemL item;
    tPosL pos = findItem(param1,*L);
    if((pos==LNULL)){
        return 0;
    }
    else{
        tItemL item;
        tPosL pos;
        pos = findItem(param1, *L);
        item = getItem(pos, *L);
        *votosnulos+=item.numVotes;
        if(*votosvalidos!=0){
            (*votosvalidos)--;
        }
        deleteAtPosition(pos,L);

        char participantLocation[8];
        if(item.EUParticipant==true){
            strcpy(participantLocation, "eu");
        }
        else{
            strcpy(participantLocation ,"non-eu");
        }
        printf("* Disqualify: participant %s location %s\n",param1,participantLocation);
        return 1;
    }
}

void stats(char *commandNumber, char command,char *param1,char *param2,tList *L,int votosnulos,int votosvalidos){
    /*Muestra la lista completa de participantes con su nombre, número de votos, localización y porcentaje de votos*/
    tPosL pos;
    tItemL item;


    int porcentajedevotos;
    for(pos= first(*L);pos != LNULL ;pos=next(pos,*L)){
        item = getItem(pos,*L);
        if(votosvalidos == 0){
            porcentajedevotos=0;
        }
        else{
            porcentajedevotos = (item.numVotes / votosvalidos);
        }


        char participantLocation[8];
        if(item.EUParticipant==true){
            strcpy(participantLocation, "eu");
        }
        else{
            strcpy(participantLocation ,"non-eu");
        }


        printf("Participant %s location %s numvotes %d (%.2f%%)\n",item.participantName,participantLocation,item.numVotes,(float)porcentajedevotos*100);
    }
    /*Muestra el número de votos nulos*/
    printf("Null votes %d\n",votosnulos);
    /*Calculamos la cantidad de votos totales y el porcentaje de miembros del jurado que ya han ejercido su derecho a voto*/
    int votostotales;
    votostotales=votosnulos+votosvalidos;
    float votantestotales=((float)votostotales/atof(param1));
    printf("Participation: %d votes from %s voters (%.2f%)\n",votostotales,param1,votantestotales*100);
}



void processCommand(char *commandNumber, char command, char *param1, char *param2,tList *L,int *votosnulos,int *votosvalidos){
                                                            /*En función de la instrucción indicada en el archivo txt seleccion
                                                             *el subprograma y si falla se imprime el mensaje de erro*/
        switch (command) {

        case 'N':
            printf("********************\n");
            printf("%s %c: participant %s location %s\n",commandNumber,command,param1,param2);
            if(!new( commandNumber,  command,  param1,  param2, L)){
                printf("+ Error: New not possible\n");
            }

            break;
        case 'V':
            printf("********************\n");
            printf("%s %c: participant %s\n",commandNumber,command,param1);
            if(vote(commandNumber,  command,  param1,  param2, L,votosnulos,votosvalidos)==0){
                printf("+ Error: Vote not possible. Participant %s not found. NULLVOTE\n",param1);
                }
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: participant %s\n",commandNumber,command,param1);
            if(disqualify( commandNumber,  command,  param1,  param2, L,votosnulos,votosvalidos)==0){
                printf("+ Error: Disqualify not possible\n");
            }

            break;
        case 'S':
            printf("********************\n");
            printf("%s %c: totalvoters %s\n",commandNumber,command,param1);
            if(isEmptyList(*L)){
                printf("+ Error: Stats not possible\n");
            }
            else stats( commandNumber,  command,  param1,  param2, L,*votosnulos,*votosvalidos);
            break;
        default:
            printf("********************\n");
            printf("Error\n");
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    //Creamos la lista
    tList L;
    createEmptyList(&L);
    int votosnulos =0;                                                                        //Creamos una variable para guardar los votos nulos
    int votosvalidos = 0;                                                                     //Creamos una variable para contar los votos validos


    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2,&L,&votosnulos,&votosvalidos);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    char *file_name = "test1.txt";

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
