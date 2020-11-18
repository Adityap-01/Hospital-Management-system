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
void bill()
{
    FILE *fptr;
    fptr = fopen ("hospital.txt", "r+");
    if (fptr == NULL)
    {
        printf("\nError openning file\n");
        exit (1);
    }
    char id[15];
    char t[5];
    printf("\nPatient Id :");
    scanf("%s",&id);
    for(int i=0;i<count;i++)
    {   fread((ptr+i),sizeof(struct patient),1,fptr);
        if(strcmp(id,(ptr+i)->pid)==0)
        {
            printf("Enter Yes or No for test: ");
            scanf("%s",t);
            if(stricmp(t,"yes")==0)
                (ptr+i)->b.bill=testres((ptr+i)->b.bill,(ptr+i)->b.test);
            printf("Total bill amount is %d",((ptr+i)->b).bill);
        }
    }
    fclose(fptr);
}
int testres(int amt,char *test)
{
    char res[25];
    if(strcmp(test,"Electrocardiogram")==0)
    {
        amt+=400;
        printf("\nEnter result of test: ");
        scanf("%s",res);
        if(stricmp(res,"positive")==0)
            amt+=500;
    }
    if(strcmp(test,"MRI")==0)
    {
        amt+=300;
        printf("\nEnter result of test: ");
        scanf("%s",res);
        if(stricmp(res,"positive")==0)
            amt+=300;
    }
    if(strcmp(test,"Blood test")==0)
    {
        amt+=50;
        printf("\nEnter result of test: ");
        scanf("%s",res);
        if(stricmp(res,"positive")==0)
            amt+=200;
    }
    if(strcmp(test,"Prick test")==0)
    {
        amt+=250;
        printf("\nEnter result of test: ");
        scanf("%s",res);
        if(stricmp(res,"positive")==0)
            amt+=600;
    }
    if(strcmp(test,"X-Ray")==0)
    {
        amt+=200;
        printf("\nEnter result of test: ");
        scanf("%s",res);
        if(stricmp(res,"positive")==0)
            amt+=400;
    }
    return amt;
}
void display(char *id)
{
    FILE *fptr;
    fptr = fopen("hospital.txt", "r");
    if (fptr == NULL)
    {
        printf("\nError openning file\n");
        exit (1);
    }
    struct patient *sptr;
    sptr=(struct patient*)calloc(15,sizeof(struct patient));
    int i;
    int f=0;
    for(i=0;i<count;i++)
    {   fread((sptr+i),sizeof(struct patient),1,fptr);
        if(strcmp(id,(ptr+i)->pid)==0)
        {
            printf("\nPatient Id: %s",(sptr+i)->pid);
            printf("\nName: %s",(sptr+i)->name);
            printf("\nAge: %s",(sptr+i)->age);
            printf("\nPhone Number: %s",(sptr+i)->phn);
            printf("\nAddress: %s",(sptr+i)->addrs);
            printf("\nDoctor Treating: %s",(sptr+i)->doc);
            printf("\nDepartment: %s",(sptr+i)->department);
            f=1;
        }
    }
    fclose(fptr);
    if(f==0)
    {
        printf("Id not found");
    }
}
void edit(char *id)
{
    FILE *temp;
    FILE *fptr;
    temp=fopen("temp.txt","w");      // Creating temporary File
    fptr=fopen("hospital.txt","r");
    if(fptr==NULL)
    {
        printf("\nCan't open file");
        exit(0);
    }
    int i,k;
    for(i=0;i<count;i++)
    {   fread((ptr+i),sizeof (struct patient),1,fptr);
        if(strcmp(id,(ptr+i)->pid)==0)
        {
            printf("Choose the Detail to be Changed");
            printf("\n1.Name\n2.Age\n3.Address\n4.Department\n5.Phone number\n");
            printf("\nEnter your Choice: ");
            scanf("%d",&k);
            switch(k)
            {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s",(ptr+i)->name);
                    break;

                case 2:
                    printf("Enter new Age: ");
                    scanf("%s",&(ptr+i)->age);
                    break;

                case 3:
                    printf("Enter new Address: ");
                    scanf("%s",(ptr+i)->addrs);
                    break;

                case 4:
                    printf("Enter new Department: ");
                    scanf("%s",(ptr+i)->department);
                    if(stricmp((ptr+i)->department,"Cardiology")==0)
                    {
                        strcpy((ptr+i)->doc,"Dr.Raj Gupta");
                        strcpy((ptr+i)->b.test,"Electrocardiogram");
                    }

                    if(stricmp((ptr+i)->department,"Neurology")==0)
                    {
                        strcpy((ptr+i)->doc,"Dr.Tarun Dutt");
                        strcpy((ptr+i)->b.test,"MRI");
                    }
                    if(stricmp((ptr+i)->department,"Physician")==0)
                    {
                        strcpy((ptr+i)->doc,"Dr.Vijay Kumar");
                        strcpy((ptr+i)->b.test,"Blood test");
                    }
                    if(stricmp((ptr+i)->department,"Dermatology")==0)
                    {
                        strcpy((ptr+i)->b.test,"Prick test");
                        strcpy((ptr+i)->doc,"Dr.Sarthak Arora");
                    }
                    if(stricmp((ptr+i)->department,"Osteology")==0)
                    {
                        strcpy((ptr+i)->b.test,"X-Ray");
                        strcpy((ptr+i)->doc,"Dr.Anjali Gupta");
                    }
                    break;

                case 5:
                    printf("Enter new Phone number: ");
                    scanf("%s",&(ptr+i)->phn);
                    break;

                default:
                    printf("Wrong Option");
                    break;
            }
            fwrite((ptr),sizeof(struct patient),count,temp);
            printf("Changes Made Successfully");
        }
    }
    fclose(fptr);
    fclose(temp);
    remove("hospital.txt");             // Deleting Original File
    rename("temp.txt","hospital.txt");  // Rename new File
}
