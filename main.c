#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Function/func.h"

int main()
{
    int choice;
    ptr=(struct patient*)calloc(15,sizeof(struct patient));
    printf("                                |***********  CMC VELLORE  ***********|");
    printf("\n******|   Menu   |******");
    printf("\n1.New Registration\n2.Deletion of Records\n3.Editing Records\n4.Displaying of Record\n5.Bill Details\n6.Exit\n");
    while(1)
    {
        printf("\n\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nRegistration - ");
                reg();
                break;

            case 2:
                printf("\nDeletion of record - ");
                char id[15];
                printf("\nPatient Id :");
                scanf("%s",id);
                del(id);
                break;

            case 3:
                printf("\nEditing of record - ");
                char ip[15];
                printf("\nPatient Id :");
                scanf("%s",ip);
                edit(ip);
                break;

            case 4:
                printf("\nDisplaying record - ");
                char im[15];
                printf("\nPatient Id :");
                scanf("%s",im);
                display(im);
                break;

            case 5:
                printf("\nBill");
                bill();
                break;

            case 6:
                printf("\nExiting");
                exit(0);
        }
    }
    return 0;
}