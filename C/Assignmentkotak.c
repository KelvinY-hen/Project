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

struct distribution
{
    char code[5];
    int quantity;
    char hospital[20];
};

struct sorting
{
    char code[5];
    int accumulation;
};

int command_1()
{
    system("cls");
    int count=0;
    int dist_count=0;
    struct vaccine vac[30];
    struct distribution dist[30];
    FILE *vfile;
    FILE *dfile;

    printf("==========New Vaccine============");

        int n=0;
        int i;
        char confirmation[3];
        vfile=fopen("vaccine.txt","r");
        fscanf(vfile, "%d\n", &n);
        fflush(stdin);
        for (i=0;i<n;++i)
        {
            fgets(vac[i].name,20,vfile);
            fflush(stdin);
            vac[i].name[strlen(vac[i].name)-1]=0;   
            fgets(vac[i].code,5,vfile);
            fflush(stdin);
            vac[i].code[strlen(vac[i].code)-1]=0;
            fgets(vac[i].prod_country,20,vfile);
            fflush(stdin);
            vac[i].prod_country[strlen(vac[i].prod_country)-1]=0;
            fscanf(vfile,"%d",&vac[i].dosage);
            fflush(stdin);
            fscanf(vfile,"%d",&vac[i].quantity);
            fflush(stdin);
            fscanf(vfile,"%f\n",&vac[i].population);
            fflush(stdin);
        }
        fclose(vfile);
            
        count=n;
            
        printf("\nName: "); fflush(stdin); gets(vac[count].name);
        printf("Name Code: ");fflush(stdin); gets(vac[count].code);
        printf("Producing country: ");fflush(stdin);  gets(vac[count].prod_country);
        printf("Dosage Required: ");fflush(stdin);scanf("%d", &vac[count].dosage);
        printf("Quantity Available: ");fflush(stdin);scanf("%d", &vac[count].quantity);
        printf("Population: ");fflush(stdin); scanf("%f", &vac[count].population);
        fflush(stdin);


        
        printf("\nAdd data to vaccine record? (y to proceed): ");
        scanf("%c",&confirmation);

        if (strcmp(confirmation,"y")==0||strcmp(confirmation,"Y")==0)
            {
                for (i=0; vac[count].code[i]!=0; i++)
                        {
                        if (vac[count].code[i]>='a' && vac[count].code[i]<='z')
                            vac[count].code[i]=vac[count].code[i]-32;
                        }

                ++count;
                    
            
                
                vfile=fopen("vaccine.txt","w");
                if (vfile==NULL)
                    return -1;
                fprintf(vfile,"%d\n", count);
                fflush(stdin);
                for (int i = 0; i<count; ++i)
                {
                    fputs(vac[i].name,vfile);
                    fprintf(vfile,"\n");
                    fflush(stdin);
                    fputs(vac[i].code,vfile);
                    fprintf(vfile,"\n");
                    fflush(stdin);
                    fputs(vac[i].prod_country,vfile);
                    fprintf(vfile,"\n");
                    fflush(stdin);
                    fprintf(vfile,"%d\n", vac[i].dosage, vfile);
                    fprintf(vfile,"%d\n", vac[i].quantity, vfile);
                    fprintf(vfile,"%f\n", vac[i].population, vfile);
                    fflush(stdin);
                }
                fclose(vfile);
                
                printf("Recording Successful");
            }
        else
            return 0;
    return 0;

}

int command_2()
{
        system("cls");
        int choice_2, old_quantity, new_quantity, dist_quantity, choice_3;

        int count=0;
        int dist_count=0;
        struct vaccine vac[30];
        struct distribution dist[30];
        FILE *vfile;
        FILE *dfile;
        
        int n=0;
        int i;
        vfile=fopen("vaccine.txt","r");
        fscanf(vfile, "%d\n", &n);
        fflush(stdin);
        for (i=0;i<n;++i)
        {
            fgets(vac[i].name,20,vfile);
            fflush(stdin);
            vac[i].name[strlen(vac[i].name)-1]=0;   
            fgets(vac[i].code,5,vfile);
            fflush(stdin);
            vac[i].code[strlen(vac[i].code)-1]=0;
            fgets(vac[i].prod_country,20,vfile);
            fflush(stdin);
            vac[i].prod_country[strlen(vac[i].prod_country)-1]=0;
            fscanf(vfile,"%d",&vac[i].dosage);
            fflush(stdin);
            fscanf(vfile,"%d",&vac[i].quantity);
            fflush(stdin);
            fscanf(vfile,"%f\n",&vac[i].population);
            fflush(stdin);
        }
        fclose(vfile);
        count=n;


        printf("Select a Vaccine\n");
        if (count < 0)
            puts("Data not Available");
        printf(" \t\t\t\t *****  Vaccine List *****\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("S.N.|    NAME     |  Code  |  Producing Country | Dosage Required |  Available Quantity  | Population Covered (%%) |\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        for (i=0;i<count;++i)
        { 
            printf("%d     %-13s %-8s %-20s %-17d %-22d %-24.2f\n",i+1,vac[i].name,vac[i].code,vac[i].prod_country,vac[i].dosage,vac[i].quantity,vac[i].population);
        }
        printf("\nChoice: "); scanf("%d", &choice_2);

        if (choice_2>count)
        {
            printf("Number out of Range");
            return 0;
        }
        
        old_quantity=vac[choice_2-1].quantity;
        
        printf("Select Action:\n");
        printf("\t1. Add Quantity\n");
        printf("\t2. Distribute Vaccine Quantity\n");
        printf("\t3. Exit\n");
        fflush(stdin);
        printf("Choice: ");
        scanf("%d",&choice_3);

        switch (choice_3)
        {
        case 1:
            printf("\nHow many?: ");fflush(stdin);scanf("%d", &new_quantity);
            new_quantity=new_quantity+old_quantity;
            vac[choice_2-1].quantity=new_quantity;
            

            vfile=fopen("vaccine.txt","w");
            if (vfile==NULL)
                return -1;
            fprintf(vfile,"%d\n", count);
            fflush(stdin);
            for (int i = 0; i<count; ++i)
            {
                fputs(vac[i].name,vfile);
                fprintf(vfile,"\n");
                fflush(stdin);
                fputs(vac[i].code,vfile);
                fprintf(vfile,"\n");
                fflush(stdin);
                fputs(vac[i].prod_country,vfile);
                fprintf(vfile,"\n");
                fflush(stdin);
                fprintf(vfile,"%d\n", vac[i].dosage, vfile);
                fprintf(vfile,"%d\n", vac[i].quantity, vfile);
                fprintf(vfile,"%f\n", vac[i].population, vfile);
                fflush(stdin);
            }
            fclose(vfile);
            break;


        case 2:
            n=0;
            dfile=fopen("dist.txt","r");
            if (dfile==NULL)
                return -1;
            fscanf(dfile, "%d\n", &n);
            fflush(stdin);
            for (i=0;i<n;++i)
            {
                fgets(dist[i].code,5,dfile);
                fflush(stdin);
                dist[i].code[strlen(dist[i].code)-1]=0;
                fscanf(dfile,"%d\n",&dist[i].quantity);
                fflush(stdin);
                fgets(dist[i].hospital,20,dfile);
                dist[i].hospital[strlen(dist[i].hospital)-1]=0;
                fflush(stdin);
            }
            fclose(dfile);
            dist_count=n;
            

            printf("\nHow many?: ");fflush(stdin);scanf("%d", &dist_quantity);
            new_quantity=old_quantity-dist_quantity;
            if (new_quantity<0)
            {
                printf("Out of Range");
                break;
            }
            vac[choice_2-1].quantity=new_quantity;
            dist[dist_count].quantity=dist_quantity;
            strcpy(dist[dist_count].code,vac[choice_2-1].code);
            printf("Where?: ");fflush(stdin);gets(dist[dist_count].hospital);
            vfile=fopen("vaccine.txt","w");
            if (vfile==NULL)
                return -1;
            fprintf(vfile,"%d\n", count);
            fflush(stdin);
            for (int i = 0; i<count; ++i)
            {
                fputs(vac[i].name,vfile);
                fprintf(vfile,"\n");
                fflush(stdin);
                fputs(vac[i].code,vfile);
                fprintf(vfile,"\n");
                fflush(stdin);
                fputs(vac[i].prod_country,vfile);
                fprintf(vfile,"\n");
                fflush(stdin);
                fprintf(vfile,"%d\n", vac[i].dosage, vfile);
                fprintf(vfile,"%d\n", vac[i].quantity, vfile);
                fprintf(vfile,"%f\n", vac[i].population, vfile);
                fflush(stdin);
            }
            fclose(vfile);
            
            dist_count++;
            dfile=fopen("dist.txt","w");
            if (dfile==NULL)
                return -1;
            fprintf(dfile,"%d\n", dist_count);
            fflush(stdin);
            for (int i = 0; i<dist_count; ++i)
            {
                fputs(dist[i].code,dfile);
                fprintf(dfile,"\n");
                fflush(stdin);
                fprintf(dfile,"%d\n", dist[i].quantity, dfile);
                fflush(stdin);
                fputs(dist[i].hospital,dfile);
                fprintf(dfile,"\n");
                fflush(stdin);
            }
            fclose(dfile);
            break;
        case 3:
            return 0;
        default:
            printf("Number out of range");
            break;
            
        }
    return 0;
}

int command_3()
{
    system("cls");
    int count=0;
    int dist_count=0;
    struct vaccine vac[30];
    struct distribution dist[30];
    FILE *vfile;
    FILE *dfile;
    char search_code[5];

    int n=0;
    int i;
    vfile=fopen("vaccine.txt","r");
    fscanf(vfile, "%d\n", &n);
    fflush(stdin);
    for (i=0;i<n;++i)
    {
        fgets(vac[i].name,20,vfile);
        fflush(stdin);
        vac[i].name[strlen(vac[i].name)-1]=0;   
        fgets(vac[i].code,5,vfile);
        fflush(stdin);
        vac[i].code[strlen(vac[i].code)-1]=0;
        fgets(vac[i].prod_country,20,vfile);
        fflush(stdin);
        vac[i].prod_country[strlen(vac[i].prod_country)-1]=0;
        fscanf(vfile,"%d",&vac[i].dosage);
        fflush(stdin);
        fscanf(vfile,"%d",&vac[i].quantity);
        fflush(stdin);
        fscanf(vfile,"%f\n",&vac[i].population);
        fflush(stdin);
    }
    fclose(vfile);

    printf("Input Vaccine Code: "); fflush(stdin); gets(search_code);

    for (i=0; search_code[i]!=0; i++)
    {
        if (search_code[i]>='a' && search_code[i]<='z')
            search_code[i]=search_code[i]-32;
    }

    int available_counter=0;

    printf("\nProduct with same code: ");
    for (i=0; i<n;++i)
    {
        if (strcmp(vac[i].code,search_code)==0)
        {
            available_counter+=1;
            printf("\nVaccine Name      : %s \nVaccine Code      : %s\nProduction Country: %s\nDosage Required   : %d\nAvailable Quantity: %d\nPopulation Covered: %.2f%%",vac[i].name,vac[i].code,vac[i].prod_country,vac[i].dosage,vac[i].quantity,vac[i].population);
        }
    }
    if (available_counter==0)
        printf("Vaccine not found");
}

int command_4()
{
    system("cls");
    int count=0;
    int dist_count=0;
    struct vaccine vac[30];
    struct distribution dist[30];
    struct sorting sort[30];
    FILE *vfile;
    FILE *dfile;
    

    int n=0;
    int i;
    vfile=fopen("vaccine.txt","r");
    fscanf(vfile, "%d\n", &n);
    fflush(stdin);
    for (i=0;i<n;++i)
    {
        fgets(vac[i].name,20,vfile);
        fflush(stdin);
        vac[i].name[strlen(vac[i].name)-1]=0;   
        fgets(vac[i].code,5,vfile);
        fflush(stdin);
        vac[i].code[strlen(vac[i].code)-1]=0;
        fgets(vac[i].prod_country,20,vfile);
        fflush(stdin);
        vac[i].prod_country[strlen(vac[i].prod_country)-1]=0;
        fscanf(vfile,"%d",&vac[i].dosage);
        fflush(stdin);
        fscanf(vfile,"%d",&vac[i].quantity);
        fflush(stdin);
        fscanf(vfile,"%f\n",&vac[i].population);
        fflush(stdin);
    }
    fclose(vfile);
    count=n;

    n=0;
    dfile=fopen("dist.txt","r");
    if (dfile==NULL)
    return -1;
    fscanf(dfile, "%d\n", &n);
    fflush(stdin);
    for (i=0;i<n;++i)
    {
        fgets(dist[i].code,5,vfile);
        fflush(stdin);
        dist[i].code[strlen(dist[i].code)-1]=0;
        fscanf(dfile,"%d\n",&dist[i].quantity);
        fflush(stdin);
        fgets(dist[i].hospital,20,dfile);
        dist[i].hospital[strlen(dist[i].hospital)-1]=0;
        fflush(stdin);
    }
    fclose(dfile);
    dist_count=n;

    for (i=0; i<count;++i)
    {
        strcpy(sort[i].code,vac[i].code);
        sort[i].accumulation=0;
        for (int j=0; j<dist_count;++j)
        {
            if (strcmp(vac[i].code,dist[j].code)==0)
            {
                sort[i].accumulation  += dist[j].quantity;
            }
        }
    }

    int temp_acc;
    char temp_code[5];

    for (i=0; i<count; i++)
    {
        for (int j=0; j<count-i-1; j++)
        {
            if (sort[j].accumulation < sort[j+1].accumulation)
            {
                temp_acc=sort[j].accumulation;
                sort[j].accumulation=sort[j+1].accumulation;
                sort[j+1].accumulation=temp_acc;

                strcpy(temp_code,sort[j].code);
                strcpy(sort[j].code,sort[j+1].code);
                strcpy(sort[j+1].code,temp_code);
            }

            
        }
    }

    printf(" \t\t\t\t *****  Vaccine List *****\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("S.N.|    NAME     |  Code  |  Producing Country | Dosage Required |  Available Quantities  | Distributed Quantities | Total Quantities | Population Covered (%%) |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=0;i<count;++i)
    { 
        for (int j=0; j<count;++j)
        {
        if (strcmp(sort[i].code,vac[j].code)==0)
            printf("%d     %-13s %-8s %-20s %-17d %-24d %-24d %-18d %-24.2f\n",i+1,vac[j].name,vac[j].code,vac[j].prod_country,vac[j].dosage,vac[j].quantity,sort[i].accumulation,vac[j].quantity+sort[i].accumulation,vac[j].population);
        }
        
    }
}


int main()
{
    char menu[2]="y";
    do
    {
        system("cls");
        int count=0;
        int dist_count=0;
        struct vaccine vac[30];
        struct distribution dist[30];
        FILE *vfile;
        FILE *dfile;

        int choice;
        printf("Select Command:\n\t1. Append new vaccine\n\t2. Input Vaccine Quantity\n\t3. Search Vaccine\n\t4. Display Vaccine Data\n\t5. Exit\n");
        printf("choice: ");
        scanf("%d", &choice);
        fflush(stdin);
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
        printf("\n\nRetry Program? (y to retry): ");
        scanf("%c", &menu);

    }
    while (strcmp(menu,"y")==0 || strcmp(menu,"Y")==0);
    system("cls");
    return 0;
}
