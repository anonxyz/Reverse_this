#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LEVELXOR.h"
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("USAGE:LEVELXOR.exe enter_Pass_here\n");
        exit(1);
    }

    decrypt(argv[1]);

    return 0;
}

void decrypt(char const password[])
{
    char coder[] = {(char) 0x8A,(char) 0xC8,(char) 0xCA,
                    (char) 0x8C,(char) 0x8E,(char) 0xCC,
                    (char) 0xCE,(char) 0x98,(char) 0x00};

    
    char key[SIZE];
    unmix_string_nibbles((char*)coder, key, SIZE, SIZE); // get key
    char enc[]="C]\\@GYXL"; // get data
    int i;
    for (i=0;enc[i] != '\0';i++)
    {
        enc[i]=xor_gate(enc[i], key[i]); 
    }
    if(strcmp(password,enc)==0)
    {
        printf("ACCESS GRANTED\n");
    }
    else{printf("WRONG PASSWORD\n");}

}

char xor_gate(char const a, char const b)
{
    return nand(nand(a, nand(a,b)), nand(b,nand(a,b)));
}

char nand(char const a, char const b)
{
    return nor(and_gate(a,b),and_gate(a,b));
}

char nor(char const a, char const b)
{
    return ~or_gate(a,b);
}

char and_gate(char const a, char const b)
{
    return nor(nor(a,a), nor(b,b));
}

char or_gate(char const a, char const b)
{
    return ~(~(a & a) & ~(b & b));
}

char unmix_bits_val(char const byte)
{
    unsigned char result = 0;
    union BYTE decoded = {0};

    decoded.bits.b6 = (byte & (1<<0)) ? 1: 0;
    decoded.bits.b0 = (byte & (1<<1)) ? 1: 0;
    decoded.bits.b2 = (byte & (1<<2)) ? 1: 0;
    decoded.bits.b5 = (byte & (1<<3)) ? 1: 0;
    decoded.bits.b3 = (byte & (1<<4)) ? 1: 0;
    decoded.bits.b7 = (byte & (1<<5)) ? 1: 0;
    decoded.bits.b1 = (byte & (1<<6)) ? 1: 0;
    decoded.bits.b4 = (byte & (1<<7)) ? 1: 0;

    return decoded.data;

}

void unmix_string_nibbles(char * const input, char *output,
                           size_t const input_len, size_t const output_len )
{
    if(!input || !output)
    {
        fprintf(stderr, "unmix_string_nibbles: Invalid input");
        return;
    }

    if(input_len > output_len)
    {
        fprintf(stderr,"unmix_string_nibbles: Output buffer too small for input size!");
        return;
    }

    size_t ctr1, ctr2;

    for(ctr1 = 0; ctr1 < input_len; ctr1++)
    {
        output[ctr1] = unmix_bits_val(input[ctr1]);
    }
    return;
}