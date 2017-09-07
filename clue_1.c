// -*- compile-command: "gcc -std=c99 -o clue_1 clue_1.c -Wall -lm" -*-
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cypher(const char *input, char *output, int shift)
{
    for (int i=0 ; i<=strlen(input) ; i++)
        if ('A' <= input[i] && input[i] <= 'Z') //Capitals
            output[i]=(input[i]-'A'+shift)%26+'A';
        else if ('a' <= input[i] && input[i] <= 'z') //Lowers
            output[i]=(input[i]-'a'+shift)%26+'a';
        else
            output[i]=input[i];
}

int main(int argc, char *argv[])
{
    const char *messageA="vwduwljudeehghyhubwklqjlfrxogilqgsohdvhuhwxuqdqbeoxhsulqwviruydxowdqgdodupghvljqedvhgrqzklfkedqnbrxghflghrqldpvhwwlqjxsvdihkrxvhfr";

    const char *messageB="gluhflishjrvbadvyyplkaohavbyjpwolypzavvdlhrvuuleatlzzhnlzdpajoavcpnlulyljpwolyrlfdvykpzaolopkkluzftivsvmklhaoputfmhcvypalovsilpuluk";

    for (int i=1 ; i<=26; i++)
    {
        char outputA[strlen(messageA)];
        cypher(messageA, outputA, i);
        printf("1/2, Offset: %d\n%s\n\n", i, outputA);

        char outputB[strlen(messageB)];
        cypher(messageB, outputB, i);
        printf("2/2, Offset: %d\n%s\n\n", i, outputB);
    }

    return 0;
}
