/*
Griffin Morgan
CSC 102 Spring 2021
Lab: Shuffling Cards
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


void shuffle_arr(string* deck, int size, int numShuffles)
{
    srand(time(0));
    for (int i = 0; i < numShuffles; i++)
    {
        int index1 = rand() % size;
        int index2 = rand() % size;

        string temp = deck[index1];
        deck[index1] = deck[index2];
        deck[index2] = temp;
    }
}

void display(string* deck, int size)
{
    cout << "(" << deck[0];

    for (int i = 1; i < size; i++)
    {
        cout << "," << deck[i];
    }

    cout << ")\n";
}


int main()
{
    int numShuffle = 0;
    string deck[12] = {"2", "3", "4", "5", "6", "7", "8", "9", "Jack", "Queen", "King", "Ace"};

    cout << "The deck before shuffling ";

    display(deck, 12);

    cout << "How many times will you shuffle? ";

    cin >> numShuffle;

    shuffle_arr(deck, 12, numShuffle);

    cout << "Your deck after shuffling ";

    display(deck, 12);

    cout << endl;

    return 0;
}

