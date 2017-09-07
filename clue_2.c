// -*- compile-command: "gcc -std=c99 -o clue_2 clue_2.c -Wall -lm" -*-
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(const char *key, const char *input, char *output)
{
    int n = 0; // Key index

    for (int i=0 ; i<strlen(input) ; i++)
    {
        int char_enc = input[i] - 'A'; // Get encoded char value
        int char_key = key[n++ % strlen(key)] - 'A'; // get key char value
        int char_dec = (26 + char_enc - char_key) % 26; // Reverse vigenere cipher
        output[i] = char_dec + 'A'; // Store deciphered message
    }
}

int main(int argc, char *argv[])
{
    const char *code="SSKKUULLLL"; // Doubled letters for key is common

    const char *message="KLKBNQLCYTFYSRYUCOCPHGBDIZZFCMJWKUCHZYESWFOGMMETWWOSSDCHRZYLDSBWNYDEDNZWNEFYDTHTDDBOJICEMLUCDYGICCZHOADRZCYLWADSXPILPIECSKOMOLTEJTKMQQYMEHPMMJXYOLWPEEWJCKZNPCCPSVSXAUYODHALMRIOCWPELWBCNIYFXMWJCEMCYRAZDQLSOMDBFLJWNBIJXPDDSYOEHXPCESWTOXWBLEECSAXCNUETZYWFN";

    char output[strlen(message)];

    cipher(code, message, output);

    printf("%s\n", output);

    return 0;
}
