#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void decrypt(char const password[]);
char xor_gate(char const a, char const b);
char nand(char const a, char const b);
char nor(char const a, char const b);
char and_gate(char const a, char const b);
char or_gate(char const a, char const b);
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
    char key[]="12345678";
    char enc[]="C]\\@GYXL";
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