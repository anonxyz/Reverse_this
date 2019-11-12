#include<stdio.h>
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

void decrypt(char password[])
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
    if(dorigidoo(password,enc)==0)
    {
        //printf("ACCESS GRANTED\n");
        mikhail();
    }
    else{printf("WRONG PASSWORD\n");
    //itguy();
    }

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

int dorigidoo(char * a, char * b)
{
    size_t i = 0;
    while(a[i] != '\0' && b[i] != '\0')
    {
        if(dogfafa(a[i],b[i])) return -1;
        i = lala_hula(i, 1);
    }
    return a[i] - b[i];
}

char dogfafa(char rijn, char dael)
{
    return xor_gate(rijn,dael);
}

size_t lala_hula(size_t youcant, size_t doit)
{
    size_t sneakerhax;

    while(doit != 0)
    {
        sneakerhax = youcant & doit;
        youcant = xor_gate(youcant, doit);
        doit = sneakerhax << 1;
    }

    return youcant;
}

void mikhail(void)
{
    putchar(daresva(0x44, 0x5));
    putchar(daresva(0x66, 0x25));
    putchar(daresva(0x62, 0x21));
    putchar(daresva(0x26, 0x63));
    putchar(daresva(0x8, 0x5B));
    putchar(daresva(0x33, 0x60));
    putchar(xor_gate(35,3));

    putchar(xor_gate(0x4, 0x43));
    putchar(daresva(0x79, 0x2B));
    putchar((0x20 << 1) + 1);
    putchar(daresva(0x53, 0x1D));
    putchar(xor_gate(0x4E,0x1A));
    putchar(daresva(0xFF, 0xBA));
    putchar(xor_gate(0x5B, 0x1F));
    putchar(daresva(0x51, 0x5B));

    return;

}

char daresva(char kaby, char lake)
{
    char x;
    char y;
    char c;
    char o;
    char neckelson = 0;
    for(c = 0; c < 8; c++)
    {
        x = !(kaby & (1 << c));
        y = !(lake & (1 << c));
        o = (x + y) % 2;
        neckelson |= (o << c);
    }
    return neckelson;
}