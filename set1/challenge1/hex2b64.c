#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex2b64.h"
int main(int argc, char** argv){
    static const char *input = "\x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20 \
        \x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20 \
        \x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d";
    char* result = encode_hex(input);
    printf("The encoded message is: %s\n", result);
}

char* encode_hex(const char* input){
    size_t i = 0;

    char* b64_string = (char *) malloc(((strlen(input)/3) * 4 + 1) * sizeof(char));

    b64_string[((strlen(input)/3)*4)] = 0;

    for(i = 0; i < strlen(input)/3; ++i){
        int numBytes = 0;
        numBytes += input[i*3] << 16;
        numBytes += input[i*3+1] << 8;
        numBytes += input[i*3+2];
        b64_string[i*4] = int_2_b64char(numBytes >> 18);
        b64_string[i*4+1] = int_2_b64char(numBytes >> 12 & 0x3f);
        b64_string[i*4+2] = int_2_b64char(numBytes >> 6 & 0x3f);
        b64_string[i*4+3] = int_2_b64char(numBytes & 0x3f);
    }

    return b64_string;
}

char int_2_b64char(int group){
    char b64char;
    if(0 <= group && group <= 25)
       b64char = (char)(group + 65);
    else if(26 <= group && group <= 51)
        b64char = (char)(group + 71);
    else if(52 <= group && group <= 61)
        b64char = (char)(group - 4);
    else if(group == 62)
        b64char = '+';
    else if(group == 63)
        b64char = '/';
    else 
        b64char = 0;

    return b64char;
}
