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

int readv (struct vaccine *vac, FILE *vfile)
{
    int n=0;
    vfile=fopen("vaccine.txt","r");
    fscanf(vfile, "%d\n", &n);
    fflush(stdin);
    for (int i=0;i<n;++i)
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
    return n;
}

int writev (struct vaccine *vac, FILE *vfile, int count)
{
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
    return 0;
}

int readd (struct distribution *dist, FILE *dfile)
{
    int n=0;
    dfile=fopen("dist.txt","r");
    if (dfile==NULL)
        return -1;
    fscanf(dfile, "%d\n", &n);
    fflush(stdin);
    for (int i=0;i<n;++i)
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
    return n;
}

int command_1()
{
    int count=0;
    struct vaccine vac[100];
    FILE *vfile;
    int i;
    char confirmation[3];

    printf("===========\n");
    printf("New Vaccine");
    printf("\n===========\n");

        
            
        count=readv(vac, vfile);
        
        
        printf("Name Code: ");fflush(stdin); gets(vac[count].code);
        for (i=0; vac[count].code[i]!=0; i++)
            {
                if (vac[count].code[i]>='a' && vac[count].code[i]<='z')
                    vac[count].code[i]=vac[count].code[i]-32;
            }
        for (i=0; i<count;i++)
        {
            if (strcmp(vac[i].code,vac[count].code)==0)
            {
                printf("Code is taken!");
                return 0;
            }
        }

        printf("\nName: "); fflush(stdin); gets(vac[count].name);
        printf("Producing country: ");fflush(stdin);  gets(vac[count].prod_country);
        printf("Dosage Required: ");fflush(stdin);scanf("%d", &vac[count].dosage);
        printf("Quantity Available: ");fflush(stdin);scanf("%d", &vac[count].quantity);
        printf("Population: ");fflush(stdin); scanf("%f", &vac[count].population);
        fflush(stdin);


        
        printf("\nAdd data to vaccine record? (y to proceed): ");
        scanf("%c",&confirmation);

        if (strcmp(confirmation,"y")==0||strcmp(confirmation,"Y")==0)
            {
                

                ++count;
                    
                writev(vac, vfile, count);
                
                printf("Recording Successful");
            }
        else
            return 0;
    return 0;

}

int command_2()
{
        int choice_2, new_quantity, choice_3;

        int count=0;
        struct vaccine vac[100];
        FILE *vfile;

        int dist_count=0;
        struct distribution dist[100];
        FILE *dfile;
        
        count=readv(vac, vfile);


        printf("Select a Vaccine\n");
        if (count < 0)
            puts("Data not Available");
        printf(" \t\t\t\t *****  Vaccine List *****\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("S.N.|    NAME     |  Code  |  Producing Country | Dosage Required |  Available Quantity  | Population Covered (%%) |\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        for (int i=0;i<count;++i)
        { 
            printf("%d     %-13s %-8s %-20s %-17d %-22d %-24.2f\n",i+1,vac[i].name,vac[i].code,vac[i].prod_country,vac[i].dosage,vac[i].quantity,vac[i].population);
        }
        printf("\nChoice: "); scanf("%d", &choice_2);

        if (choice_2>count)
        {
            printf("Number out of Range");
            return 0;
        }
        
        
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

            vac[choice_2-1].quantity=vac[choice_2-1].quantity+new_quantity;
    
            writev(vac, vfile, count);

            printf("Quantity Succesfully Added");
            break;
        case 2:
            
            dist_count=readd(dist, dfile);

            printf("\nHow many?: ");fflush(stdin);scanf("%d", &new_quantity);
            
            vac[choice_2-1].quantity = vac[choice_2-1].quantity-new_quantity;
            if (vac[choice_2-1].quantity<0)
            {
                printf("Out of Range");
                break;
            }

            printf("Where?: ");fflush(stdin);gets(dist[dist_count].hospital);
            dist[dist_count].quantity=new_quantity;
            strcpy(dist[dist_count].code,vac[choice_2-1].code);
            
            writev(vac, vfile, count);
            
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
            printf("Quantity Succesfully Distributed");
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
    struct vaccine vac[100];
    FILE *vfile;
    char search_code[5];

    int n=0;
    n=readv(vac, vfile);

    printf("==============\n");
    printf("Search Vaccine");
    printf("\n==============\n");

    printf("Input Vaccine Code: "); fflush(stdin); gets(search_code);

    for (int i=0; search_code[i]!=0; i++)
    {
        if (search_code[i]>='a' && search_code[i]<='z')
            search_code[i]=search_code[i]-32;
    }

    int available_counter=0;

    printf("\nProduct with same code: ");
    for (int i=0; i<n;++i)
    {
        if (strcmp(vac[i].code,search_code)==0)
        {
            available_counter+=1;
            printf("\nVaccine Name      : %s \nVaccine Code      : %s\nProduction Country: %s\nDosage Required   : %d\nAvailable Quantity: %d\nPopulation Covered: %.2f%%",vac[i].name,vac[i].code,vac[i].prod_country,vac[i].dosage,vac[i].quantity,vac[i].population);
        }
    }
    if (available_counter==0)
        printf("Vaccine not found");

    return 0;
}

int command_4()
{
    int count=0;
    int dist_count=0;
    struct vaccine vac[100];
    struct distribution dist[100];
    struct sorting sort[100];
    FILE *vfile;
    FILE *dfile;
    
    
    count=readv(vac, vfile);

    dist_count=readd(dist, dfile);

    for (int i=0; i<count;++i)
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

    struct vaccine temp;

    int choice=0;
    printf("Select sorting mode:\n\t1. available quantity descending\n\t2. distributed quantity descending\ninput choice: ");
    scanf("%d",&choice);

    if (choice==1)
    {
        
        struct vaccine temp;
        for (int i=0; i<count; i++)
        {
            for (int j=0; j<count-i-1; j++)
            {
                if (vac[j].quantity < vac[j+1].quantity)
                {
                    temp=vac[j];
                    vac[j]=vac[j+1];
                    vac[j+1]=temp;
                    
                }
            }
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("S.N.|    NAME     |  Code  |  Producing Country | Dosage Required |  Available Quantities  | Distributed Quantities | Population Covered (%%) |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int i=0;i<count;++i)
        { 
            for (int j=0; j<count;++j)
            {
                if (strcmp(vac[i].code,sort[j].code)==0)
                printf("%d     %-13s %-8s %-20s %-17d %-24d %-24d %-24.2f\n",i+1,vac[i].name,vac[i].code,vac[i].prod_country,vac[i].dosage,vac[i].quantity,sort[j].accumulation,vac[i].population);
            }
                        
        }
    }
    else if (choice==2)
    {
        struct sorting temp;    
        for (int i=0; i<count; i++)
        {
            for (int j=0; j<count-i-1; j++)
            {
                if (sort[j].accumulation < sort[j+1].accumulation)
                {
                    temp=sort[j];
                    sort[j]=sort[j+1];
                    sort[j+1]=temp;
                    
                }
            }
        }
        printf(" \t\t\t\t\t\t\t   *****  Vaccine List *****\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("S.N.|    NAME     |  Code  |  Producing Country | Dosage Required |  Available Quantities  | Distributed Quantities | Population Covered (%%) |\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------ ----\n");
        for (int i=0;i<count;++i)
        { 
            for (int j=0; j<count;++j)
            {
             if (strcmp(vac[i].code,sort[j].code)==0)
                 printf("%d     %-13s %-8s %-20s %-17d %-24d %-24d %-24.2f\n",i+1,vac[j].name,vac[j].code,vac[j].prod_country,vac[j].dosage,vac[j].quantity,sort[i].accumulation,vac[j].population);
            }
                        
        }
    }
    else
        printf("Invalid Input");
    return 0;
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
