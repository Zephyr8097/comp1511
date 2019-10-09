// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by ZHOU ZIYU (z5212919)
// on 04-04-2019
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// IF YOU NEED MORE #defines ADD THEM HERE
#define DOUGLAS              42
#define TRUE                  1
#define FALSE                 0


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void best_discards(int*,int*);
void order_handcards(int array[]);
int is_prime(int);
int is_cocomposite(int,int);
int have_prime_card(int,const int*);
int have_non_primer_card(int,const int*);
int have_cocomposite_card(int,int,const int*);
int is_douglas_out(int,const int*);
int max_only_primer(const int*);
int compare(const void*,const void*);
int get_biggest_card(int,const int*);
int get_biggest_card_notice_douglas(int,const int*);
int get_biggest_non_primer_card(int,const int*);
int get_biggest_non_primer_card_notice_douglas(int,const int*);
int get_biggest_primer_card(int, const int*);
int get_biggest_primer_card_smaller_other(int,int,const int*);
int get_biggest_cocomposite_card(int,int,const int*);
int get_biggest_cocomposite_card_notice_douglas(int,int,const int*);


// You should not need to change this main function
int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {
    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME
    printf("Teemo\n");
}

void choose_discards() {
    int i;
    int array_discards[N_CARDS_DISCARDED];
    int cards_initial_hand[N_CARDS_INITIAL_HAND];

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    for (i = 0; i < N_CARDS_INITIAL_HAND; i++)
        scanf("%d", &cards_initial_hand[i]);

    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    best_discards(cards_initial_hand, array_discards);
    printf("%d %d %d\n", array_discards[0], array_discards[1], array_discards[2]);

    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.
}


void choose_card_to_play(void) {
    int i;
    int n_cards_in_hand, n_cards_been_played, table_position;
    int array_cards_in_hand[N_CARDS_INITIAL_HAND] = {0, };
    int array_cards_been_palyed[N_PLAYERS] = {0, };
    int n_cards_previously_played;
    int array_cards_previously_played[N_CARDS] = {0, };

    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    scanf("%d %d %d", &n_cards_in_hand, &n_cards_been_played, &table_position);

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    i = 0;
    while (i < n_cards_in_hand)
        scanf("%d", &array_cards_in_hand[i++]);

    // ADD CODE TO READ THE CARDS PLAYED SO FAR IN THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    i = 0;
    while (i < n_cards_been_played)
        scanf("%d", &array_cards_been_palyed[i++]);

    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED ALL ROUNDS INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    n_cards_previously_played = (N_CARDS_INITIAL_HAND - n_cards_in_hand) * 4;
    i = 0;
    while (i < n_cards_previously_played)
        scanf("%d", &array_cards_previously_played[i++]);

    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    
    if (n_cards_been_played == 0) { 
    // playing the first card in a round
        if (have_prime_card(n_cards_previously_played, array_cards_previously_played)) {
            // Play any card...
            printf("%d\n", is_douglas_out(n_cards_previously_played, array_cards_previously_played) ||
                           is_douglas_out(n_cards_been_played, array_cards_been_palyed) ?
                           get_biggest_card(n_cards_in_hand, array_cards_in_hand) :
                           get_biggest_card_notice_douglas(n_cards_in_hand, array_cards_in_hand));
            return;
        } else {
            if (have_non_primer_card(n_cards_in_hand, array_cards_in_hand)) {
                // Notice if Douglas hasn't been played
                printf("%d\n", is_douglas_out(n_cards_previously_played, array_cards_previously_played) ||
                               is_douglas_out(n_cards_been_played, array_cards_been_palyed) ?
                               get_biggest_non_primer_card(n_cards_in_hand, array_cards_in_hand) :
                               get_biggest_non_primer_card_notice_douglas(n_cards_in_hand, array_cards_in_hand));
                return;
            } else {
                // Play any card...
                printf("%d\n", is_douglas_out(n_cards_previously_played, array_cards_previously_played) ||
                               is_douglas_out(n_cards_been_played, array_cards_been_palyed) ?
                               get_biggest_card(n_cards_in_hand, array_cards_in_hand) :
                               get_biggest_card_notice_douglas(n_cards_in_hand, array_cards_in_hand));
                return;
            }
        }
    } else {  
    // playing non-first in a round
        if (is_prime(array_cards_been_palyed[0])) {
            if (have_prime_card(n_cards_in_hand, array_cards_in_hand)) {
                printf("%d\n", get_biggest_primer_card_smaller_other(max_only_primer(array_cards_been_palyed), n_cards_in_hand, array_cards_in_hand));
                return;
            } else {
                // Play any card...
                printf("%d\n", is_douglas_out(n_cards_previously_played, array_cards_previously_played) ||
                               is_douglas_out(n_cards_been_played, array_cards_been_palyed) ?
                               get_biggest_card(n_cards_in_hand, array_cards_in_hand) :
                               get_biggest_card_notice_douglas(n_cards_in_hand, array_cards_in_hand));
                return;
            }
        } else {
            if (have_cocomposite_card(array_cards_been_palyed[0], n_cards_in_hand, array_cards_in_hand)) {
                // Notice if Douglas hasn't been played
                printf("%d\n", is_douglas_out(n_cards_previously_played, array_cards_previously_played) ||
                               is_douglas_out(n_cards_been_played, array_cards_been_palyed) ?
                               get_biggest_cocomposite_card(array_cards_been_palyed[0], n_cards_in_hand, array_cards_in_hand) :
                               get_biggest_cocomposite_card_notice_douglas(array_cards_been_palyed[0], n_cards_in_hand, array_cards_in_hand));
                return;
            } else {
                // Play any card...
                printf("%d\n", is_douglas_out(n_cards_previously_played, array_cards_previously_played) ||
                               is_douglas_out(n_cards_been_played, array_cards_been_palyed) ?
                               get_biggest_card(n_cards_in_hand, array_cards_in_hand) :
                               get_biggest_card_notice_douglas(n_cards_in_hand, array_cards_in_hand));
                return;
            }
        }
    }
}

// ADD YOUR FUNCTIONS HERE
void best_discards(int array[], int discards[]) {
    int i;
    int has_douglas = 0;

    //Get rid of Douglas first
    for (i = 0; i < N_CARDS_INITIAL_HAND; i++) {
        if (array[i] == DOUGLAS) {
            array[i] = 0; // or array[i] = CARD_MIN
            has_douglas = 1;
            break;
        }
    }

    // Get rid of big number
    order_handcards (array);

    if (has_douglas) {
        discards[0] = DOUGLAS;
        discards[1] = array[N_CARDS_INITIAL_HAND - 1];
        discards[2] = array[N_CARDS_INITIAL_HAND - 2];
    } else {
        discards[0] = array[N_CARDS_INITIAL_HAND - 1];
        discards[1] = array[N_CARDS_INITIAL_HAND - 2];
        discards[2] = array[N_CARDS_INITIAL_HAND - 3];
    }
}

int is_prime(int num) {
    int i;
    
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
        return 0;
    }

    return 1;
}

int is_cocomposite(int num1, int num2) {
    int i, min, max;

    min = num1 < num2 ? num1 : num2;
    max = num1 < num2 ? num2 : num1;

    if (min < CARD_MIN || max > CARD_MAX)
        return 0;

    for (i = 2; i <= min; i++) {
        if (num1 % i == 0 && num2 % i == 0 && i != min)
            return 1;
    }
    return 0;
}

int have_prime_card(int length, const int array[]) {
    int i;

    for (i = 0; i < length; i++) {
        if (is_prime(array[i]))
            return 1;
    }
    return 0;
}

int have_non_primer_card(int length, const int array[]) {
    int i;

    for (i = 0; i < length; i++) {
        if (!is_prime(array[i]))
            return 1;
    }
    return 0;
}

int have_cocomposite_card(int num, int length, const int array[]) {
    int i;

    for (i = 0; i < length; i++) {
        if (is_cocomposite(num, array[i]))
            return 1;
    }
    return 0;
}

int is_douglas_out(int length, const int array[]) {
    int i;

    for (i = 0; i < length; i++) {
        if (array[i] == DOUGLAS)
            return 1;
    }
    return 0;
}

int max_only_primer(const int array[]) {
    int i;
    int temp_array[N_PLAYERS];

    // copy array
    for (i = 0; i < N_PLAYERS; i++) {
        temp_array[i] = is_prime(array[i]) ? array[i] : 0;
    }
    qsort(temp_array, N_PLAYERS, sizeof(int), compare);
    return temp_array[N_PLAYERS - 1];
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int get_biggest_card(int length, const int array[]) {
    return array[length - 1];
}

int get_biggest_card_notice_douglas(int length, const int array[]) {
    int i, max = 0;

    for (i = 0; i < length; i++) {
        if (array[i] > max && array[i] < DOUGLAS)
            max = array[i];
    }
    return max == 0 ? get_biggest_card(length, array) : max;
}

// Suppose the array must have a non-prime card.
int get_biggest_non_primer_card(int length, const int array[]) {
    int i;

    for (i = length - 1; i >= 0; i--) {
        if (!is_prime(array[i]))
            return array[i];
    }
    return -1;
}

// Suppose the array must have a cocomposite card. Notice the Douglas.
int get_biggest_non_primer_card_notice_douglas(int length, const int array[]) {
    int i, max = 0;

    for (i = length - 1; i >= 0; i--) {
        if (!is_prime(array[i]) && array[i] > max && array[i] < DOUGLAS)
            max = array[i];
    }
    return max == 0 ? get_biggest_non_primer_card(length, array) : max;
}

// Suppose the array must have a prime card. Small than other.
int get_biggest_primer_card(int length, const int array[]) {
    int i;

    for (i = length - 1; i >= 0; i--) {
        if (is_prime(array[i]))
            return array[i];
    }
    return -1;
}

// Suppose the array must have a prime card. Small than other.
int get_biggest_primer_card_smaller_other(int num, int length, const int array[]) {
    int i, max = 0;

    for (i = length - 1; i >= 0; i--) {
        if (is_prime(array[i]) && array[i] > max && array[i] < num) {
            max = array[i];
        }
    }
    return max == 0 ? get_biggest_primer_card(length, array) : max;
}

// Suppose the array must have a cocomposite card.
int get_biggest_cocomposite_card(int num, int length, const int array[]) {
    int i;

    for (i = length - 1; i >= 0; i--) {
        if (is_cocomposite(num, array[i]))
            return array[i];
    }
    return -1;
}

// Suppose the array must have a cocomposite card. Notice the Douglas.
int get_biggest_cocomposite_card_notice_douglas(int num, int length, const int array[]) {
    int i, max = 0;
    
    for (i = length - 1; i >= 0; i--) {
        if (is_cocomposite(num, array[i]) && array[i] > max && array[i] < DOUGLAS) {
            max = array[i];
        }
    }
    return max == 0 ? get_biggest_cocomposite_card(num, length, array) : max;
}

// Order my handcars from small to big
void order_handcards (int order[]) {
    int j = 0, k, l = j + 1;
    while (j < N_CARDS_INITIAL_HAND - 1) {
        while (l < N_CARDS_INITIAL_HAND) {
            if (order[j] > order[l]) {
                k = order[j];
                order[j] = order[l];
                order[l] = k;
            }
            l++;				
        }
        j++;
    } 
}
