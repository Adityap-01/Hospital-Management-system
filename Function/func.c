#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../Structure/struct.h"
int token=0;
int count=0;

void reg()
{
    FILE * fptr;
    fptr = fopen ("hospital.txt", "w");
    char buffer[15];
    if (fptr == NULL)
    {
        printf("\nError openning file\n");
        exit (1);
    }
        printf("\nName :");
        scanf("%s",(ptr+count)->name);
        strcpy((ptr+count)->pid,"CMC");
        itoa(token+100,buffer,10);
        strcat((ptr+count)->pid,buffer);
        printf("Age :");
        scanf("%s",&(ptr+count)->age);
        printf("Address :");
        scanf("%s",(ptr+count)->addrs);
        printf("Departments Options- \nCardiology,Neurology,General Physician,Dermatology,Osteology");
        printf("\nDepartment to Consult :");
        scanf("%s",(ptr+count)->department);
        printf("Phone number :");
        scanf("%s",&(ptr+count)->phn);
        if(stricmp((ptr+count)->department,"Cardiology")==0)
        {
            strcpy((ptr+count)->doc,"Dr.Raj Gupta");
            strcpy((ptr+count)->b.test,"Electrocardiogram");
        }
        if(stricmp((ptr+count)->department,"Neurology")==0)
        {
            strcpy((ptr+count)->doc,"Dr.Tarun Dutt");
            strcpy((ptr+count)->b.test,"MRI");
        }
        if(stricmp((ptr+count)->department,"General Physician")==0)
        {
            strcpy((ptr+count)->doc,"Dr.Vijay Kumar");
            strcpy((ptr+count)->b.test,"Blood test");
        }
        if(stricmp((ptr+count)->department,"Dermatology")==0)
        {
            strcpy((ptr+count)->doc,"Dr.Sarthak Arora");
            strcpy((ptr+count)->b.test,"Prick test");
        }
        if(stricmp((ptr+count)->department,"Osteology")==0)
        {
            strcpy((ptr+count)->doc,"Dr.Anjali Gupta");
            strcpy((ptr+count)->b.test,"X-Ray");
        }
        (ptr+count)->b.bill=200;
        printf("Patient ID = %s\n",(ptr+count)->pid);
        token++;
        count++;
        fwrite ((ptr),sizeof(struct patient),count,fptr);
        fclose (fptr);
        printf("Contents to file written successfully !\n");
}
void del(char *id)
{
    int i,j;int f=0;
    FILE *temp;
    FILE * fptr;
    temp=fopen("temp.txt","w");
    fptr=fopen("hospital.txt","r");

    if(fptr==NULL)
    {
        printf("\nCan't open file");
        exit(0);
    }

    for(i=0;i<count;i++)
    {   fread((ptr+i),sizeof(struct patient),1,fptr);
        if(strcmp(id,(ptr+i)->pid)== 0)
        {
            for(j=i;j<count-1;j++)
            {
                strcpy((ptr+j)->pid,(ptr+j+1)->pid);
                strcpy((ptr+j)->name,(ptr+j+1)->name);
                strcpy((ptr+j)->age,(ptr+j+1)->age);
                strcpy((ptr+j)->addrs,(ptr+j+1)->addrs);
                strcpy((ptr+j)->doc,(ptr+j+1)->doc);
                strcpy((ptr+j)->department,(ptr+j+1)->department);
                strcpy((ptr+j)->phn,(ptr+j+1)->phn);
                strcpy(((ptr+j)->b).test,((ptr+j+1)->b).test);
                (ptr+j)->b.bill=(ptr+j+1)->b.bill;

            }
            f=1;
            count--;
            printf("Deletion Successful");
            fwrite((ptr),sizeof(struct patient),count,temp);
        }

    }
    if(f==0)
    {
        printf("Id not found");
        fclose(fptr);
        fclose(temp);
        return;

    }
    fclose(fptr);
    fclose(temp);
    remove("hospital.txt");
    rename("temp.txt","hospital.txt");
}