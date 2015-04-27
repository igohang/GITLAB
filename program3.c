#include <stdio.h>
#include <string.h>
int main ()
{
    char exit = 'Y';
    int nCourse = 0;
    int i = 0;
    int j = 0;
    int credit[50] ;
    char course[50][50] ;
    char grade[50] ;
    float GPA = 0.00;
    int end = 0;
    int round = 0;
    float sCredit = 0;
    float sScore = 0;

    while (exit == 'Y')
    {
        exit = 'x' ;
        printf ("How many courses ? : ");
        scanf ("%d",&nCourse);
        i=0;

        sScore = 0;
        sCredit = 0;
        GPA = 0.00;

        while (i < nCourse && end ==0)
        {
            printf ("Enter course name , credits, and grade for course #%d : ", i+1);
            scanf ("%s %d %c",&course[i],&credit[i],&grade[i]);
            while (grade[i] != 'A' && grade[i] != 'B' && grade[i] != 'C' && grade[i] != 'D'&& grade[i] != 'F'&& grade[i] != 'S')
            {
                printf ("Invalid Grade E. Allowed values are A, B, C, D, F, S. Try Again.\n");
                printf ("Enter course name , credits, and grade for course #%d : ", i+1);
                fflush(stdin);
                scanf ("%s %d %c",&course[i],&credit[i],&grade[i]);
            }
            round = nCourse ;
            if (strcmp (course[i],"END")== 0)
            {
                end = 1;
                round = i ;
            }

            i++;
        }

    printf ("\n\nYour Transcript for this semester:\n");
    printf ("----------------------------------\n");
    printf ("   #  COURSE    CREDITS   GRADE\n");

    for (j = 0;j<round;j++)
    {
        printf ("%4d %7s %10d %7c\n",j+1 ,course[j],credit[j],grade[j]);
        sCredit += credit[j];
        if (grade[j] == 'A')
        {
            sScore += (4.0*credit[j]);
        }
        else if (grade[j] == 'B')
        {
            sScore += (3.0*credit[j]);
        }
        else if (grade[j] == 'C')
        {
            sScore += (2.0*credit[j]);
        }
        else if (grade[j] == 'D')
        {
            sScore += (1.0*credit[j]);
        }
        else if (grade[j] == 'F')
        {
            sScore += (0.0*credit[j]);
        }
    }
    printf ("----------------------------------\n");
    printf ("SEMESTER GPA: %.2f\n",sScore/sCredit);
    printf ("----------------------------------\n\n");

    while (exit != 'Y' && exit != 'N')
    {
        end = 0;
        printf ("Do you wish to countinue (Y/N) : ");
        scanf (" %c",&exit);
        if (exit != 'Y' && exit != 'N')
        {
            printf ("Invalid answer P. Enter only Y ro N .\n");
        }
    }
    }

    printf ("\nBYE ! ");

return 0;
}
