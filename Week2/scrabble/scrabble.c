#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int sum_of_score(string s);

int main(void) {
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = sum_of_score(player1);
    int score2 = sum_of_score(player2);

    printf("score1 is %i\n", score1);
    printf("score2 is %i\n", score2);
    if (score1 > score2){
        printf("Player 1 wins!");
    }else if (score1 < score2) {
        printf("Player 2 wins!");
    }else {
        printf("Tie!");
    }
    printf("\n");
}

int sum_of_score(string s) {
    int sum = 0;
    for (int i = 0, len = strlen(s); i < len; i++) {
        char c = toupper(s[i]);
        if (c >= 'A' && c <= 'Z') {
            if (c == 'Q' || c == 'Z') {
                sum += 10;
            }else if (c == 'J' || c == 'X'){
                sum += 8;
            }else if (c == 'K') {
                sum += 5;
            }else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y') {
                sum += 4;
            }else if (c == 'B' || c == 'C' || c == 'M' || c == 'P') {
                sum += 3;
            }else if (c == 'D' || c == 'G') {
                sum += 2;
            }else {
                sum += 1;
            }
        }
    }
    return sum;
}
