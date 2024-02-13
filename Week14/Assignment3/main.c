#include <stdio.h>
#include "functions.h"

typedef enum { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } rank_t;
typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } suit_t;

typedef struct {
    rank_t rank;
    suit_t suit;
} card_t;

/// Builds a deck of 52 playing cards.
/// @param deck The array to fill with cards.
void build_deck(card_t deck[static 52])
{
    int cardCount = 0;

    for (suit_t s = HEARTS; s <= SPADES; s++)
    {
        for (rank_t r = TWO; r <= ACE; r++)
        {
            deck[cardCount].rank = r;
            deck[cardCount].suit = s;
            cardCount++;
        }
    }

    shuffle(deck, 52, sizeof(card_t));
}

/// Prints a playing card to the console.
/// @param card The card to print.
/// @param isFirstCard Changes the wording used in output.
void print_card(const card_t *card, bool isFirstCard)
{
    const char *rank_names[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const char *suit_names[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    if (isFirstCard)
    {
        printf("The first card is the %s of %s.\n", rank_names[card->rank], suit_names[card->suit]);
    }
    else
    {
        printf("The next card is the %s of %s.\n", rank_names[card->rank], suit_names[card->suit]);
    }
}

int main(void)
{
    card_t deck[52];
    int cardCount = 1;

    build_deck(deck);
    print_card(&deck[0], 10);

    while (1)
    {
        char choice;
        printf("Will the next card be higher (h) or lower (l)? ");
        scanf(" %c", &choice);

        print_card(&deck[cardCount], 0);

        if ((choice == 'h' && deck[cardCount].rank > deck[cardCount - 1].rank) ||
            (choice == 'l' && deck[cardCount].rank < deck[cardCount - 1].rank))
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect! Game over after %d cards.\n", cardCount);
            break;
        }

        cardCount++;
    }

    return 0;
}
