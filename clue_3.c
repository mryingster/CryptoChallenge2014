// -*- compile-command: "gcc -std=c99 -o clue_3 clue_3.c -Wall -lm" -*-
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(const char *input, char *output)
{
    char key[5][5]={{'A','F','K','P','U'},
                    {'B','G','L','Q','V'},
                    {'C','H','M','R','W'},
                    {'D','I','N','S','X'},
                    {'E','J','O','T','Y'}};

    for (int i=0 ; i<strlen(input)-2 ; i=i+2)
    {
        //Get coordinates from key grid
        printf("%c",key[input[i]-'1'][input[i+1]-'1']);

        //Save ascii to output
        output[i]=key[input[i]-'1'][input[i+1]-'1'];
    }
}

int main()
{
    const char *message="44541134541123335344541242434244325141212311311353155442544244424344325141534354324234411125513553341342432253431144543453432251343142143251341253341215541534513351444411225144425442444415345123551543213451111311212351425431533321424351445315341434512542531544335154325341443043513544";

    char output[strlen(message)];

    cipher(message, output);

    printf("%s\n", output);

    return 0;
}
