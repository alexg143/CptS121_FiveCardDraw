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

#include "header.h"

int main(void)
{
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	int deck[4][13] = { 0 }, redraw_nums[5] = { 0 }, ai_redraw_num = 0, choice = 0, index = 0;

	Card player_hand[5] = { { 0, 0, 0 } }, dealer_hand[5] = { { 0, 0, 0 } };

	srand((unsigned)time(NULL));

	game_menu();

	shuffle(deck);
	deal(deck, face, suit, player_hand, 5, 1, 0);
	deal(deck, face, suit, dealer_hand, 5, 6, 0);

	printf("The deck has been shuffled and the cards have been dealt!\n\n");
	printf("Your hand:\n");
	display_hand(player_hand, suit, face);

	// Player redraw sequence --------------------------
	choice = redraw_choice();
	if (choice == 1)
	{
		get_redraw_indices(redraw_nums);
		for (index = 0; index < 5; ++index)
		{
			if (redraw_nums[index] != 20)
			{
				deal(deck, face, suit, player_hand, 1, 12 + index, redraw_nums[index]);
			}
		}
	}
	// AI redraw sequence--------------------------------
	ai_redraw_num = redraw_num(dealer_hand);
	if (redraw_num != 0)
	{
		deal(deck, face, suit, dealer_hand, ai_redraw_num, 17, 0);
	}
	printf("\nThe dealer has decided to redraw %d card(s).\n", ai_redraw_num);
	// -------------------------------------------------
	system("pause");
	system("cls");
	printf("Time for everyone to show their hands:\n\n");
	printf("Player:\n");
	display_hand(player_hand, suit, face);
	printf("\nDealer:\n");
	display_hand(dealer_hand, suit, face);
	has_won(player_hand, dealer_hand);

	return 0;
}