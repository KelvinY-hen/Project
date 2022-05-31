#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Mark
{
    char id[10];
    char name[20];
    int test;
    int assignment;
    int final;
};

void analyze()
{
    struct Mark mark[30];
    FILE *student;
    int i=0, counter;

    student=fopen("marks.txt","r");
        
    fscanf(student,"%d\n",&i);
    for (int n=0;n<i;++n)
    {
        fgets(mark[n].id,10,student);
        fflush(stdin);
        mark[n].id[strlen(mark[n].id)-1]=0;   
        fgets(mark[n].name,20,student);
        fflush(stdin);
        mark[n].name[strlen(mark[n].name)-1]=0;
        fscanf(student,"%d",&mark[n].test);
        fflush(stdin);
        fscanf(student,"%d",&mark[n].assignment);
        fflush(stdin);
        fscanf(student,"%d\n",&mark[n].final);
        fflush(stdin);
    }
    fclose(student);

    int pass=0,accumulation=0,total=0;
    float avg;

    for (int n=0 ; n<i;++n)
    {
        total=mark[n].test + mark[n].assignment + mark[n].final;
        printf("\nid: %-12s  score: %d", mark[n].id,total);
        if (total>55)
        {
            pass++;
        }
        accumulation += total;
    }

    avg=accumulation/i;
    printf("\n\nAvg Total Mark: %.2f", avg);
    printf("\nTotal Student Who Pass: %d, Fail: %d", pass, i-pass);


}

int main()
{
    char menu[5];
    do
    {   system("cls");
        struct Mark mark[30];
        FILE *student;
        int choice;
        
        printf("Select Action: ");
        printf("\n\t1. Input Marks");
        printf("\n\t2. Analyze Student Marks");
        printf("\nInput Choice: ");
        scanf("%d", &choice);
        system("cls");
        if (choice==1)
        {
            int i=0;
            fflush(stdin);
            student=fopen("marks.txt","r"); 
            fscanf(student,"%d\n",&i);
            for (int n=0;n<i;n++)
            {
                fgets(mark[n].id,10,student);
                fflush(stdin);
                mark[n].id[strlen(mark[n].id)-1]=0;   
                fgets(mark[n].name,20,student);
                fflush(stdin);
                mark[n].name[strlen(mark[n].name)-1]=0;
                fscanf(student,"%d",&mark[n].test);
                fflush(stdin);
                fscanf(student,"%d",&mark[n].assignment);
                fflush(stdin);
                fscanf(student,"%d\nr",&mark[n].final);
                fflush(stdin);
            }
            fclose(student);

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
            
            i++;

            student=fopen("marks.txt","w");
            fprintf(student,"%d\n", i);
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
        printf("\n\ny to retry: ");
        scanf("%c", &menu);

    }
    while (strcmp(menu,"y")==0 || strcmp(menu,"Y")==0);
    return 0;
}