#include <stdio.h>
#include "functions.h"

void DisplayCoinCount(int coinCount, int coinValue)
{
    if (coinCount > 0)
    {
        if (coinValue == 100 || coinValue == 200)
        {
            printf("You get back %d coin(s) of %d euros.\n", coinCount, coinValue/100);
        }
        else
        {
            printf("You get back %d coin(s) of %d cents.\n", coinCount, coinValue);
        }
    }
}

int CalculateCoinCount(int centsLeft, int coinValue)
{
    int coinCount = centsLeft / coinValue;
    DisplayCoinCount(coinCount, coinValue);
    return centsLeft % coinValue;
}

int main() {
    int static CoinValues[] = {200, 100, 50, 20, 10, 5, 2, 1};

    float moneyGiven = read_float("Please enter the amount of money that you pay: ");
    float price = read_float("Please enter the price of the product: ");

    int centsLeft = (moneyGiven - price) * 100;

    printf("You get back %d cents back!\n", centsLeft);

    for (int i = 0; i < 8; ++i) {
        centsLeft = CalculateCoinCount(centsLeft, CoinValues[i]);
    }

    return 0;
}