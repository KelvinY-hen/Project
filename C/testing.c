#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vaccine
{
    char name[20];
    char code[5];
    char prod_country[20];
    int dosage;
    int quantity;
    float population;
};

int readv (struct vaccine *vac, FILE *vfile)
{
    int n=0;
    vfile=fopen("vaccine.txt","r");
    fscanf(vfile, "%d\n", &n);
    fflush(stdin);
    char line[100];
    for (int i=0;i<n;++i)
    {
        fgets(line,100,vfile);
        fflush(stdin);
        
    }
    fclose(vfile);
    return n;
}

int main()
{
    char menu[2]="y";
    do
    {
        system("cls");
        int choice;
        
        printf("==========Vaccine=Inventory=Program==========\n");
        printf("Select Command:\n\t1. Append new vaccine\n\t2. Input Vaccine Quantity\n\t3. Search Vaccine\n\t4. Display Vaccine Data\n\t5. Exit\n");
        printf("choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        
        system("cls");
        if (choice == 1)
            command_1();
        else if (choice==2)
            command_2();
        else if (choice==3)
            command_3();
        else if (choice==4)
            command_4();
        else if (choice==5)
            {
            system("cls");
            return 0;
            }
        else
            printf("Invalid Input");
        fflush(stdin);
        printf("\n\nRestart Program? (y to restart): ");
        scanf("%c", &menu);

    }
    while (strcmp(menu,"y")==0 || strcmp(menu,"Y")==0);
    system("cls");
    return 0;
}
