#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) {
    string texts = get_string("Text: ");
    float cnt_char = 0.0;
    float cnt_tense = 0.0;
    float cnt_word = 0.0;
    int index;
    for (int i = 0, len = strlen(texts); i < len; i++) {
        char c = tolower(texts[i]);
        if (c <= 'z' && c >= 'a') {
            cnt_char++;
        }

        if (c == '.' || c == '?' || c == '!'){
            cnt_tense++;
        }

        if (c == ' ') {
            cnt_word++;
        }
    }
    cnt_word++;
    index = round((0.0588 * ((cnt_char/cnt_word)*100.0)) - (0.296 * ((cnt_tense/cnt_word)*100.0)) - 15.8);
    if (index < 1) {
        printf("Before Grade 1");
    }else if (index > 16) {
        printf("Grade 16+");
    }else {
        printf("Grade %i", index);
    }
    printf("\n");
}
