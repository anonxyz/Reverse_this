#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void decrypt(char const password[]);
char xor_gate(char const a, char const b);
char nand(char const a, char const b);
int prin(int x,int select_char);
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
    int win=1;

if(win)
{
    int count;
    int prin_char;
    int select_char;
    for(count=0,select_char=0;count<=13;count++,select_char++)
    {

        prin_char=prin(count,select_char);
        printf("%c",prin_char);
    }

}
    }
    else{printf("WRONG PASSWORD\n");}

}

char xor_gate(char const a, char const b)
{
    return nand(nand(a, nand(a,b)), nand(b,nand(a,b)));
}

char nand(char const a, char const b)
{
    return ~(a & b);
}
int prin(int x,int select_char)
{
    x=65;
    if(select_char==0)
    {
        return x;
    }
    if(select_char==1 || select_char==2)
    {
        return x+=2;
    }
    if(select_char==3)
    {
        return x+=4;
    }
    if(select_char==4 || select_char==5)
    {
        return x+=18;
    }
    if(select_char==6)
    {
        return x-=33;
    }
    if(select_char==7)
    {
        return x+=6;
    }
    if(select_char==8)
    {
        return x+=17;
    }
    if(select_char==10)
    {
        return x+=13;
    }
    if(select_char==11)
    {
        return x+=19;
    }
    if(select_char==12)
    {
        return x+=4;
    }
    if(select_char==13)
    {
        return x+=3;
    }
    else{return x;}
}
