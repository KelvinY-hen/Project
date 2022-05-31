#include <string.h>
#include <stdio.h>

struct Mark
{
    char id[10];
    char name[20];
    int test;
    int assignment;
    int final;
};

int main()
{
    struct Mark mark[30];
    FILE *student;
    int choice;
    
    printf("Select Action: ");
    printf("\n\t1. Input Marks");
    printf("\n\t2. Analyze Student Marks");
    printf("\nInput Choice: ");
    scanf("%d", &choice);

    if (choice==1)
    {
        fflush(stdin);
        int count=0;
        for(int i=0;i<10;i++)
        {
            printf("\nInput student data");
            printf("\nStudent ID: ");fflush(stdin); gets(mark[i].id);
            printf("\nStudent Names: ");fflush(stdin); gets(mark[i].name);
            printf("\nTest Mark (Max=15%%): ");fflush(stdin);scanf("%d",&mark[i].test);
            if (mark[i].test>15)
            {
                printf ("invalid input");
                return 0;
            }
            printf("\nAssignment Mark (Max=35%%): ");fflush(stdin);scanf("%d",&mark[i].assignment);
            if (mark[i].assignment>35)
            {
                printf ("invalid input");
                return 0;
            }
            printf("\nFinal Exam Mark=50%%: ");fflush(stdin);scanf("%d",&mark[i].final);
            if (mark[i].final>50)
            {
                printf ("invalid input");
                return 0;
            }
            count++;
        }
        

        student=fopen("marks.txt","w");
        fprintf(student,"%d\n", count);
        fflush(stdin);
        for (int n = 0; n<i; ++n)
            {
                fputs(mark[n].id,student);
                fprintf(student,"\n");
                fflush(stdin);
                fputs(mark[n].name,student);
                fprintf(student,"\n");
                fflush(stdin);
                fprintf(student,"%d\n", mark[n].test, student);
                fprintf(student,"%d\n",mark[n].assignment, student);
                fprintf(student,"%d\n",mark[n].final, student);
                fflush(stdin);
            }
            fclose(student);
    }
    else if (choice==2)
        analyze();
    else
        printf("Invalid Input");
    return 0;
}