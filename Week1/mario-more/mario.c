#include <stdio.h>
#include <cs50.h>

int main(void) {
    int n;

    do {
        n = get_int("Height: ");
    }while(n < 1 || 8 < n);

    for (int i = n; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            printf(" ");
        }

        for (int j = n; j >= i; j--) {
            printf("#");
        }
        printf("  ");

        for (int j = n; j >= i; j--) {
            printf("#");
        }
        printf("\n");
    }
}
