#include<stdio.h>
#include "contact.h"

// Save all contacts to file
void save_contacts_file(AddressBook *addressbook)
{
    FILE* fptr=fopen("data.txt","w"); // Open file for writing 
    if(fptr==NULL)
    {
        printf("file not found");
    }
    fprintf(fptr,"#%d\n",addressbook->contact_count);

    // Write each contact in CSV format: Name,Mobile,Email
    for(int i=0;i<addressbook->contact_count;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }
    fclose(fptr);//close the file
}

// Load contacts from file
void load_contacts_file(AddressBook *addressbook)
{
    FILE*fptr=fopen("data.txt","r"); // Open file for reading
    if(fptr==NULL)
    {
        printf("file not found");
    }
    fscanf(fptr,"#%d\n",&addressbook->contact_count);
    printf("%d\n",addressbook->contact_count);
    
    // Read each contact into the address book
    for(int i=0;i<addressbook->contact_count;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }
    fclose(fptr);
}