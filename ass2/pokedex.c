// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by ZHOU ZIYU (z5212919)
// on 30-04-2019
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
#include<time.h>

// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.
#define random(x) (rand()%x)


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.




struct pokedex {
    struct pokenode *head;
    struct pokenode *current_pokenode;

    int size;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

typedef struct pokenode {
    struct pokenode *next;
    struct pokenode *evolve_next;
    Pokemon         pokemon;
    int find; 
    //1 can find ;0 can't find
}*Pokenode;

// Add any other structs you define here.


// Add prototypes for any extra functions you create here.

int contain_without_case(const char *content, const char *key);
Pokenode new_pokenode(void); 
Pokenode findByID(Pokedex pokedex, int id);

// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof(struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;
    new_pokedex->current_pokenode = NULL;
    new_pokedex->size = 0;

    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    Pokenode node = new_pokenode();

    node->pokemon = pokemon;


    pokedex->size++;

    Pokenode p = pokedex->head;
    if (p == NULL){
        pokedex->head = node;
        pokedex->current_pokenode = node;
        return;
    }
    //if the pokemon exists
    while (p->next != NULL){
        if (pokemon_id(p->pokemon) == pokemon_id(pokemon)){
            fprintf(stderr, "pokemon_id already exists");
            exit(1);
        }

        p = p->next;
    }
    p->next = node;


}

void detail_pokemon(Pokedex pokedex) {

    //if it is empty
    Pokenode p = pokedex->current_pokenode;
    if (p == NULL){
        printf("exiting because pokenode is empty");
        return;
    }

    Pokemon pn = p->pokemon;
    if (pn == NULL){
        printf("exiting because pokemon is empty");
        return;
    }
    printf("Id: %03d\n", pokemon_id(pn));
    //found
    if (p->find == 1){
        printf("Name: %s\n", pokemon_name(pn));
        printf("Height: %.1fm\n", pokemon_height(pn));
        printf("Weight: %.1fkg\n", pokemon_weight(pn));

        if (pokemon_second_type(pn) <= NONE_TYPE){//does not have second type
            printf("Type: %s\n", pokemon_type_to_string(pokemon_first_type(pn)));
        }
        else{
            printf("Type: %s %s\n", pokemon_type_to_string(pokemon_first_type(pn)),
                pokemon_type_to_string(pokemon_second_type(pn)));
        }

    }
    //not found
    else{
        printf("Name: ");
        char* name = pokemon_name(pn);
        for (int i = 0; i<name[i] != '\0'; i++){
            printf("*");
        }
        printf("\n");
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    }

}

Pokemon get_current_pokemon(Pokedex pokedex) {

    if (pokedex == NULL){
        fprintf(stderr, "exiting because pokedex is empty\n");
        exit(1);
    }
    return pokedex->current_pokenode->pokemon;
}

void find_current_pokemon(Pokedex pokedex) {
    if (pokedex == NULL || pokedex->current_pokenode == NULL){

        return;
    }
    pokedex->current_pokenode->find = 1;//can be found

}

void print_pokemon(Pokedex pokedex) {
    
    Pokenode p = pokedex->head;
    if (p == NULL){
        
        return;
    }
    Pokenode cur = pokedex->current_pokenode;
    // select the current pokemon
    while (p != NULL){
        Pokemon pn = p->pokemon;
        if (pn == NULL){
            
            return;
        }
        if (p == cur)
            printf("--> ");
        else
            printf("    ");


        printf("#%03d: ", pokemon_id(pn));
        //the pokemon has been found
        if (p->find == 1){
            printf("%s\n", pokemon_name(pn));
        }
        else{
        //pokemon hasn't been found    
            char* name = pokemon_name(pn);
            for (int i = 0; i<name[i] != '\0'; i++){
                printf("*");
            }
            printf("\n");
        }
        p = p->next;
    }


}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {

    //select the next pokemon
    Pokenode p = pokedex->current_pokenode;
    if (p == NULL)
        return;
    if (p->next != NULL){
        pokedex->current_pokenode = p->next;
    }


}

void prev_pokemon(Pokedex pokedex) {
    // the previous pokemon
    Pokenode head = pokedex->head;
    Pokenode cur = pokedex->current_pokenode;
    if (head == cur){
        return;
    }
    else{
        while (head->next != cur){
            head = head->next;
        }
        pokedex->current_pokenode = head;
    }


}

void change_current_pokemon(Pokedex pokedex, int id) {

    if (pokedex == NULL)
        return;

    Pokenode p = pokedex->head;
    while (p != NULL){
        Pokemon pn = p->pokemon;
        //if there is no pokemon
        if (pn == NULL){
            printf("exiting because pokemon is empty");
            return;
        }

        if (pokemon_id(pn) == id){
            pokedex->current_pokenode = p;


            return;
        }

        p = p->next;
    }
}

void remove_pokemon(Pokedex pokedex) {
    if (pokedex == NULL || pokedex->size == 0){
        return;
    }


    Pokenode p = pokedex->head;

    if (pokedex->size == 1){
        //only one pokemon in head

        pokedex->current_pokenode = NULL;

        pokedex->head = NULL;
    }
    else {
        Pokenode cur = pokedex->current_pokenode;
        if (cur == p){
        //cur==head
            pokedex->head = p->next;
            pokedex->current_pokenode = pokedex->head;
        }
        else{
            while (p->next != cur) p = p->next;

            p->next = cur->next;

            if (cur->next != NULL)
                pokedex->current_pokenode = cur->next;
            else
                pokedex->current_pokenode = p;
            p = cur;
        }
    }
    //free Pokenode
    if (p->pokemon != NULL)
        destroy_pokemon(p->pokemon);
    p->pokemon = NULL;


    if (p)
        free(p);

    //pokemon removed, size decreases
    pokedex->size--;
    
}

void destroy_pokedex(Pokedex pokedex) {

    if (pokedex == NULL) return;

    Pokenode p1 = pokedex->head;

    while (p1 != NULL){
        Pokenode p = p1;
        p1 = p1->next;

        //free Pokenode
        if (p->pokemon)
            destroy_pokemon(p->pokemon);
        free(p);
    }

    pokedex->current_pokenode = NULL;
    pokedex->size = 0;
    free(pokedex);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    
    //if pokdex empty
    if (pokedex == NULL){

        exit(1);
    }
    if (how_many >= factor){

        return;
    }
    Pokenode p0 = findByID(pokedex, how_many);
    if (p0 == NULL){
        return;

    }

    srand(seed);
    //explore radomly
    while (1){
        int id = random(factor);
        Pokenode p1 = findByID(pokedex, id);
        if (p1 == NULL)
            continue;
        p1->find = 1;

        if (p1 == p0){
            return;
        }
    }

}

int count_found_pokemon(Pokedex pokedex) {

    if (pokedex == NULL) return 0;

    Pokenode p = pokedex->head;
    int count = 0;
    //count the amount of pokemons found
    while (p != NULL){
        if (p->find == 1)
            count++;

        p = p->next;
    }
    return count;
}

int count_total_pokemon(Pokedex pokedex) {
    return pokedex->size;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {

    if (from_id == to_id){
    // the evolution is itself
        fprintf(stderr, "exiting because from_id = to_id\n");
        exit(1);
    }
    //pokdex empty
    if (pokedex == NULL) return;

    Pokenode p = pokedex->head;
    Pokenode p1 = NULL;
    Pokenode p2 = NULL;
    while (p != NULL){
        Pokemon pn = p->pokemon;
        if (pokemon_id(pn) == from_id){
            p1 = p;
        }
        if (pokemon_id(pn) == to_id){
            p2 = p;
        }

        p = p->next;
    }
    //either id not found
    if (p1 == NULL || p2 == NULL){
        fprintf(stderr, "exiting because not find from_id or to_id\n");
        exit(1);
    }
    p1->evolve_next = p2;
}

void show_evolutions(Pokedex pokedex) {

    Pokenode cur = pokedex->current_pokenode;
    int isFirst = 1;
    while (cur != NULL){
        Pokemon pn = cur->pokemon;
        if (isFirst == 1) {
            isFirst = 0;
        }    
        else {
            printf(" --> ");
        }
        printf("#%03d ", pokemon_id(pn));
        //when it is found
        if (cur->find == 1){
            printf("%s ", pokemon_name(pn));
            if (pokemon_second_type(pn) <= NONE_TYPE){
            //does not have second type
                printf("[%s]", pokemon_type_to_string(pokemon_first_type(pn)));
            }
            else{
            //have the second type
                printf("[%s, %s]", pokemon_type_to_string(pokemon_first_type(pn)),
                    pokemon_type_to_string(pokemon_second_type(pn)));
            }
        }
        //while not found
        else{
            printf("???? [????]");
        }
        
        cur = cur->evolve_next;
    }
    printf("\n");

}

int get_next_evolution(Pokedex pokedex) {
    
    if (pokedex == NULL){
        fprintf(stderr, "exiting because pokedex is empty\n");
        exit(1);
    }

    Pokenode cur = pokedex->current_pokenode;
    if (cur == NULL || cur->evolve_next == NULL){
        return DOES_NOT_EVOLVE;
    }
    else{
        return pokemon_id(cur->evolve_next->pokemon);
    }

}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    
    //if type is wrong
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE){
        fprintf(stderr, "exiting because type is wrong\n");
        exit(1);
    }
    //if nothing in pokedex
    if (pokedex == NULL){
        fprintf(stderr, "exiting because pokedex is empty\n");
        exit(1);
    }
    Pokedex newPokedex = new_pokedex();
    Pokenode p = pokedex->head;
    //clone pokemon
    while (p != NULL){
        Pokemon pn = p->pokemon;
        if (p->find == 1 && (type == pokemon_first_type(pn) || type == pokemon_second_type(pn))){
            Pokemon newPn = clone_pokemon(pn);
            add_pokemon(newPokedex, newPn);
        }

        p = p->next;
    }

    //create new pokedex
    p = newPokedex->head;
    while (p != NULL){
        p->find = 1;
        p = p->next;
    }
    return newPokedex;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    
    if (pokedex == NULL){
        fprintf(stderr, "exiting because pokedex is empty\n");
        exit(1);
    }
    Pokedex newPokedex = new_pokedex();
    Pokenode p = pokedex->head;
    
    while (p != NULL) {
        Pokemon pn = p->pokemon;
        if (p->find == 1){
            Pokemon newPn = clone_pokemon(pn);
            add_pokemon(newPokedex, newPn);
        }

        p = p->next;
    }

    //sort by id
    Pokenode p1 = newPokedex->head;
    while (p1 != NULL) {
        Pokenode p2 = p1->next;
        while (p2 != NULL){
            if (pokemon_id(p1->pokemon) > pokemon_id(p2->pokemon)){
                //exchange pokemon
                Pokemon temp = p1->pokemon;
                p1->pokemon = p2->pokemon;
                p2->pokemon = temp;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    //set cur and set find
    p1 = newPokedex->head;
    
    while (p1 != NULL)	{
        p1->find = 1;

        p1 = p1->next;
    }

    return newPokedex;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    
    Pokedex newPokedex = new_pokedex();
    Pokenode p = pokedex->head;

    while (p != NULL) {
        Pokemon pn = p->pokemon;
        if (p->find == 1 && contain_without_case(pokemon_name(pn), text) == 1){
            Pokemon newPn = clone_pokemon(pn);
            add_pokemon(newPokedex, newPn);
        }

        p = p->next;
    }
    //set cur and set find
    Pokenode p1 = newPokedex->head;
    while (p1 != NULL)	{
        p1->find = 1;
        p1 = p1->next;
    }

    return newPokedex;
}

// Add definitions for your own functions below.
int contain_without_case(const char *content, const char *key)
{
    int i = 0;
    while (content[i] != '\0'){
        int j = 0;
        while (key[j] != '\0'){
            char k = key[j] < 'a' ? key[j] - 'A' + 'a' : key[j];
            char c = content[i + j];
            if (c == '\0'){
                break;
            }
            char c1 = c < 'a' ? c - 'A' + 'a' : c;

            if (c1 != k)
                break;

            j++;
        }
        if (key[j] == '\0'){
            return 1;
        }

        i++;
    }

    return 0;

}

Pokenode new_pokenode(void) {
    Pokenode new_pokenode = (Pokenode)malloc(sizeof(struct pokenode));
    assert(new_pokenode != NULL);
    // init
    new_pokenode->next = NULL;
    new_pokenode->evolve_next = NULL;
    new_pokenode->pokemon = NULL;


    new_pokenode->find = 0;
    return new_pokenode;
}


Pokenode findByID(Pokedex pokedex, int id){
    Pokenode p = pokedex->head;
    while (p != NULL){

        if (pokemon_id(p->pokemon) == id)
            return p;

        p = p->next;
    }
    return NULL;
}
// Make them static to limit their scope to this file.
