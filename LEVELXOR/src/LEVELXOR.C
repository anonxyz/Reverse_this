#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void decrypt(char password[])
{
    char key[]="12345678";
    char enc[]="C]\\@GYXL";
    int i;
    for (i=0;enc[i] != '\0';i++)
    {
        enc[i]=enc[i] ^ key[i]; 
    }
    if(strcmp(password,enc)==0)
    {
        printf("ACCESS GRANTED");
    }
    else{printf("WRONG PASSWORD");}

}
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("USAGE:LEVELXOR.exe enter_Pass_here");
        exit(1);
    }

    decrypt(argv[1]);

    return 0;
}

