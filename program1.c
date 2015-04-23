#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age,h,m=0;
    char name[20],gender,married,title[10];

    printf("Please enter your name (type STOP to END): ");
    do
    {
    fflush(stdin);
    scanf("%s",name);
        if(strcmp(name,"stop")==0)
        {
            printf("Goodbye");
            return 0;
        }

    do
    {
    printf("Please enter your age, gender (M/F), and are you married (Y/N): ");
    fflush(stdin);
    scanf("%d %c %c",&age,&gender,&married);
    if(age<0 || age >120 || (gender !='M' && gender !='F') || (married !='Y' && married != 'N'))
    {
        printf("Error!!");
    }
    }
    while (age<0 || age >120 || (gender !='M' && gender !='F') || (married !='Y' && married != 'N'));


        do
         {
            printf("Enter hours (0-23) & minutes(0-59): ");
            scanf("%d %d",&h,&m);
            if(h<0 || h>23 || m<0 || m>59)
            {
                printf("Incorrect hours (0-23) or minutes (0-59), try again.\n");

            }
         }
        while(h<0 || h>23 || m<0 || m>59);

        if(h>=0 && h<=11)
        {
            printf("GoodMorning");
        }
        else if(h>=12 && h<=18)
        {
            printf("GoodAfternoon");
        }
        else
        {
            printf("GoodEvening");
        }

    if(gender=='M' && age>=15)
    {
        strcpy(title,"NAI");
    }
    else if(gender=='M' && age<15)
    {
        strcpy(title,"Dek Chai");
    }
    else if(gender=='F' && age<15)
    {
        strcpy(title,"Dek Ying");
    }
    else if(gender=='F' && age>=15 && married=='Y')
    {
        strcpy(title,"Nang");
    }
    else
    {
        strcpy(title,"Nang Sao");
    }
    printf(" %s %s\n\n\n",title,name);
    printf("Please enter your name type STOP to END): ");
    }
    while(1);
    return 0;
}
