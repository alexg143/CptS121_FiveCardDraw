/*
Programmer: Alexander Glenn
Class: CptS 121; Lab Section 6
Programming Assignment: Programming Assignment 7
Date: April 13, 2018
Description: This program executes a simple version of 
			 a game of five-card-draw. A user plays against
			 the dealer that is AI. The user may redraw cards
			 and the dealer will make its own decisions on how
			 it is redrawing cards. Both hands will be evaluated
			 and a winner will be determined.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct card
{
	int row;
	int col;
	int card_num;
} Card;

// Gameplay
void game_menu(void);
void display_hand(Card hand[], const char **face, const char **suit);
void shuffle(int wDeck[][13]);

// Task 1
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int num_draw, int card_num, int count);
int is_pair(Card hand[]); // 1 if true, 0 if false
int is_2_pair(Card hand[]); // 1 if true, 0 if false
int is_3_of_kind(Card hand[]); // 1 if true, 0 if false
int is_4_of_kind(Card hand[]); // 1 if true, 0 if false
int is_flush(Card hand[]); // 1 if true, 0 if false
int is_straight(Card hand[]); // 1 if true, 0 if false

// Task 2
int eval_hand(Card hand[]); // Returns 0-6 based on how good the hand is
int compare_hands(Card p1_hand[], Card p2_hand[]); // Returns 0 if first hand is better, 1 if second hand is better, 2 if they are equal

// Task 3
int redraw_num(Card hand[]); // Returns number of cards needed to be redrawn by ai

// Task 4
int redraw_choice(void); // Returns 1 if the player wants to redraw, 0 if not
int * get_redraw_indices(int redraw_nums[]); // Returns the indices of the cards the player wants to redraw in an array
void has_won(Card p1_hand[], Card p2_hand[]);