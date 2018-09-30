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

/*
Function: void game_menu(void)
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function prints a start menu
			 for the game and starts once the 
			 player presses enter.
Input parameters: n/a
Returns: n/a
Preconditions: n/a
Postconditions: n/a
*/
void game_menu(void)
{
	char start = '\0';
	do
	{
		printf("Welcome to Five-Card-Draw poker!\n\n");
		printf("Hit enter to start the game!\n");
		start = getchar();
	} while (start != '\n');
	system("cls");
}

/*
Function: void display_hand(Card hand[], const char **face, const char **suit)
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function displays the 
			 player hand.
Input parameters: Card hand[], const char **face, const char **suit
Returns: n/a
Preconditions: hand is initialized
Postconditions: n/a
*/
void display_hand(Card hand[], const char **face, const char **suit)
{
	printf("[1] %s of %s\n", suit[(hand[0].col)], face[(hand[0].row)]);
	printf("[2] %s of %s\n", suit[(hand[1].col)], face[(hand[1].row)]);
	printf("[3] %s of %s\n", suit[(hand[2].col)], face[(hand[2].row)]);
	printf("[4] %s of %s\n", suit[(hand[3].col)], face[(hand[3].row)]);
	printf("[5] %s of %s\n\n", suit[(hand[4].col)], face[(hand[4].row)]);
}

/*
Function: void shuffle(int wDeck[][13])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function shuffles the 
			 deck, it given by the
			 assignment.
Input parameters: int wDeck[][13]
Returns: int wDeck[][13]
Preconditions: deck is initialized
Postconditions: deck is shuffled
*/
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/*
Function: void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int num_draw, int card_num, int count)
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function deals a set amount
			 of cards from the deck into the
			 hand.
Input parameters: int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int num_draw, int card_num, int count
Returns: int wDeck[][13]
Preconditions: parameters initialized
Postconditions: hand is dealt
*/
void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int num_draw, int card_num, int count)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = card_num; card < card_num + num_draw; card++) // need to save cards already dealt, so they aren't dealt again
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					hand[count].row = row;
					hand[count].col = column;
					hand[count].card_num = card;
					++count;
				}
			}
		}
	}
}

/*
Function: int is_pair(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function checks to see
			 if the hand contains a pair.
Input parameters: Card hand[]
Returns: success
Preconditions: hand initialized
Postconditions: success returned
*/
int is_pair(Card hand[])
{
	int index1 = 0, index2 = 0, success = 0, match_count = 0;
	for (; index1 < 5; ++index1)
	{
		for (index2 = 0; index2 < 5; ++index2)
		{
			if (hand[index1].col == hand[index2].col)
			{
				++match_count;
			}
		}
	}
	if (match_count >= 7) // +size +each match is plus 2
	{
		success = 1;
	}
	return success;
}

/*
Function: int is_2_pair(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function checks to see
			 if the hand contains a two pair.
Input parameters: Card hand[]
Returns: success
Preconditions: hand initialized
Postconditions: success returned
*/
int is_2_pair(Card hand[])
{
	int index1 = 0, index2 = 0, success = 0, match_count = 0;
	for (; index1 < 5; ++index1)
	{
		for (index2 = 0; index2 < 5; ++index2)
		{
			if (hand[index1].col == hand[index2].col)
			{
				++match_count;
			}
		}
	}
	if (match_count >= 9) // +size +each match is plus 2
	{
		success = 1;
	}
	return success;
}

/*
Function: int is_3_of_kind(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function checks to see
			 if the hand contains a three
			 of a kind.
Input parameters: Card hand[]
Returns: success
Preconditions: hand initialized
Postconditions: success returned
*/
int is_3_of_kind(Card hand[])
{
	int index1 = 0, index2 = 0, success = 0, match_count = 0;
	for (; index1 < 5; ++index1)
	{
		for (index2 = 0; index2 < 5; ++index2)
		{
			if (hand[index1].col == hand[index2].col)
			{
				++match_count;
			}
		}
	}
	if (match_count >= 11) // +size +each match is plus 2
	{
		success = 1;
	}
	return success;
}

/*
Function: int is_4_of_kind(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function checks to see
			 if the hand contains a four
			 of a kind.
Input parameters: Card hand[]
Returns: success
Preconditions: hand initialized
Postconditions: success returned
*/
int is_4_of_kind(Card hand[])
{
	int index1 = 0, index2 = 0, success = 0, match_count = 0;
	for (; index1 < 5; ++index1)
	{
		for (index2 = 0; index2 < 5; ++index2)
		{
			if (hand[index1].col == hand[index2].col)
			{
				++match_count;
			}
		}
	}
	if (match_count >= 13) // +size +each match is plus 2
	{
		success = 1;
	}
	return success;
}

/*
Function: int is_flush(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function checks to see
			 if the hand contains a flush.
Input parameters: Card hand[]
Returns: success
Preconditions: hand initialized
Postconditions: success returned
*/
int is_flush(Card hand[])
{
	int temp = 0, success = 0;
	
	temp = hand[0].row;

	if ((hand[1].row == temp) && (hand[2].row == temp) && (hand[3].row == temp) && (hand[4].row == temp))
	{
		success = 1;
	}
	return success;
}

/*
Function: int is_straight(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function checks to see
			 if the hand contains a straight.
Input parameters: Card hand[]
Returns: success
Preconditions: hand initialized
Postconditions: success returned
*/
int is_straight(Card hand[])
{
	int index1 = 0, index2 = 1, match_count = 0, success = 0;
	for (; index1 < 5; ++index1, ++index2)
	{
		if (hand[index1].col == (hand[index2].col - 1))
		{
			++match_count;
		}
		else
		{
			break;
		}
	}
	if ((hand[0].col == 9) && (hand[1].col == 10) && (hand[2].col == 11) && (hand[3].col == 12) && (hand[4].col == 0))
	{
		match_count = 4;
	}
	if (match_count == 4)
	{
		success = 1;
	}
	return success;
}

/*
Function: int eval_hand(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function evaluates a
			 hand and gives it a score 
			 between 0 and 6.
Input parameters: Card hand[]
Returns: temp
Preconditions: hand initialized
Postconditions: temp returned
*/
int eval_hand(Card hand[])
{
	int pair = 0, two_pair = 0, three_kind = 0, straight = 0, flush = 0, four_kind = 0, temp = 0;
	pair = is_pair(hand);
	if (pair == 1)
	{
		temp = 1;
	}
	two_pair = is_2_pair(hand);
	if (two_pair == 1)
	{
		temp = 2;
	}
	three_kind = is_3_of_kind(hand);
	if (three_kind == 1)
	{
		temp = 3;
	}
	straight = is_straight(hand);
	if (straight == 1)
	{
		temp = 4;
	}
	flush = is_flush(hand);
	if (flush == 1)
	{
		temp = 5;
	}
	four_kind = is_4_of_kind(hand);
	if (four_kind == 1)
	{
		temp = 6;
	}
	return temp;
}

/*
Function: int eval_hand(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function compares the
			 player hands and determines
			 which one was better.
Input parameters: Card p1_hand[], Card p2_hand[]
Returns: 0, 1, or 2
Preconditions: hands initialized
Postconditions: 0, 1, or 2 returned
*/
int compare_hands(Card p1_hand[], Card p2_hand[])
{
	int p1_temp = 0, p2_temp = 0;

	p1_temp = eval_hand(p1_hand);
	p2_temp = eval_hand(p2_hand);

	if (p1_temp > p2_temp)
	{
		return 0;
	}
	else if (p2_temp > p1_temp)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

/*
Function: int redraw_num(Card hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function determines
			 how many cards the dealer
			 should redraw.
Input parameters: Card hand[]
Returns: num
Preconditions: hands initialized
Postconditions: num returned
*/
int redraw_num(Card hand[])
{
	int redraw_var = 0, num = 0, randint = rand();
	redraw_var = eval_hand(hand);
	if ((redraw_var == 0) || (redraw_var == 1))
	{
		num = (rand() % 3) + 1;
	}

	return num;
}

/*
Function: int redraw_choice(void)
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function asks the
			 user if they want to
			 redraw or not.
Input parameters: n/a
Returns: 0, 1
Preconditions: n/a
Postconditions: 0 or 1 returned
*/
int redraw_choice(void)
{
	int answer = 0;
	do {
		printf("Enter 1 to redraw, or 0 to not redraw: ");
		scanf("%d", &answer);
	} while (answer != 1 && answer != 0);
	if (answer == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
Function: int * get_redraw_indices(int redraw_nums[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function determines
			 which cards the player will
			 redraw.
Input parameters: int redraw_nums[]
Returns: redraw_nums[]
Preconditions: redraw_nums[] initialized
Postconditions: redraw_nums[] returned
*/
int * get_redraw_indices(int redraw_nums[])
{
	int index = 0, index2 = 0;
	char answer = '\0';
	
	printf("You may only redraw up to three cards!\n\n");

	for (index = 1; index < 6; index++)
	{
		printf("Redraw card %d? (y/n): ", index);
		scanf(" %c", &answer);
		if (answer == 'y')
		{
			redraw_nums[index2] = index - 1;
			++index2;
		}
		else
		{
			redraw_nums[index2] = 20;
			++index2;
		}
	}
	return redraw_nums;
}

/*
Function: void has_won(Card p1_hand[], Card p2_hand[])
Date Created: April 12, 2018
Date Last Modified: April 12, 2018
Description: This function determines
			 the winner of the game.
Input parameters: Card p1_hand[], Card p2_hand[]
Returns: n/a
Preconditions: all other functions ran already
Postconditions: statement printed
*/
void has_won(Card p1_hand[], Card p2_hand[])
{
	int winner = 0;
	winner = compare_hands(p1_hand, p2_hand);
	if (winner == 0)
	{
		printf("Player 1 has won!\n");
	}
	else if (winner == 1)
	{
		printf("The dealer has won!\n");
	}
	else
	{
		printf("It is a tie!\n");
	}
}