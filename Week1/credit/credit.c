#include <stdio.h>
#include <cs50.h>

int main(void) {

    long number = get_long("Number: ");
    long number2 = number;
    string provider = "";
    int temp;
    int length = 0;
    int mNum;
    int sum = 0;
    int isValid = 0;

    while (number) {
        length++;
        temp = number % 10;
        number = (number - temp) / 10;

        if (!(length % 2)) {
            mNum = temp*2;

            while (mNum >= 10) {
                temp = mNum % 10;
                sum += temp;
                mNum = (mNum - temp) / 10;
            }
            sum += mNum;
        }
    }

    number = number2;
    
    for (int i = 1; i <= length; i++) {

        temp = number % 10;
        number = (number - temp) / 10;

        if(i % 2) {
            sum += temp;
        }

        if (i == length-2) {
            if ((number >= 51 && number <=55) && (length == 16)) {
                isValid = 1;
                provider = "MASTERCARD";
            }else if ((number == 34 || number == 37) && (length == 15)) {
                isValid = 1;
                provider = "AMEX";
            }
        }

        if (i == length-1) {
            if ((number == 4) && (length == 13 || length == 16)) {
                isValid = 1;
                provider = "VISA";
            }
        }
    }

    if (!(sum % 10) && isValid) {
        printf("%s\n", provider);
    }else{
        printf("INVALID\n");
    }
}
