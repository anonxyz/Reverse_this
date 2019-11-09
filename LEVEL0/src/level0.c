#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*A program that matches string and lets the user pass if he supplies the correct password  */
int main(int argc,char *argv[])
{
    char password[]="rootroot";  /*anyone can see this */

    if(argc!=2)
    {
        printf("Usage:level0.exe enter_the_password_here\n");
        exit(1);
    }
    if(strcmp(password,argv[1])==0)
    {
        printf("Correct credentials %s\n",argv[1]);
    }
    else{
        printf("WRONG PASSWORD\n");
        exit(1);
    }
return 0;
}
