#include <stdio.h>
#include "contact.h"
#include<string.h>
#define red   "\033[1;31m"
#define green  "\033[1;32m"  
#define blue  "\033[1;34m"
#define reset   "\033[0m"


/* Function definitions */
void load_contacts_file(AddressBook *addressbook);
void save_contacts_file(AddressBook *addressbook);
void init_intitalization(AddressBook *addressbook)
{
    load_contacts_file(addressbook);
}
int name_validation(char*name);
int mobile_validation(char*mob,AddressBook *addressbook);
int email_validation(char*email,AddressBook *addressbook);
int k=0;
int create_contact(AddressBook *addressbook)
{
    int i=1;
    while(i)
    {
        int res=1;
        char name[20];
        while(res)
        {
        printf("Enter the Name: ");
        scanf(" %[^\n]",name);
        res = name_validation(name);
        }
        strcpy(addressbook->contact_details[addressbook->contact_count].Name,name); 
        
        res=1;
        char mob[11]; 
        while(res)
        { 
         printf("Enter the Mobile Number: ");
         scanf(" %[^\n]",mob);
         res = mobile_validation(mob,addressbook);
        }
        strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mob);
        
        res=1;
        char email[50];
        while(res)
        {
            printf("Enter the Mail ID: ");
            scanf(" %[^\n]",email);
            res=email_validation(email,addressbook);
        }
        strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,email);

       
        (addressbook->contact_count)++;
    
        printf("DO YOU WANT TO ADD ANOTHER CONTACT(YES[1]/NO[0]):");
        scanf(" %d",&i);
    }       
    return 0;
}

//To display contact lists.
void list_contacts(AddressBook *addressbook)
{
    printf("\n\t\t\t\tCONTACT LISTS\n");

    printf(blue "+-------------------------------------------------------------------------------+\n" reset);

    printf(blue "|" reset " %-4s %-22s %-18s %-30s " blue "|\n" reset,
           "SNO", "NAME", "MOBILE NUMBER", "MAIL ID");

    printf(blue "+-------------------------------------------------------------------------------+\n" reset);

    for (int i = 0; i < addressbook->contact_count; i++)
    {
        printf(blue "|" reset " %-4d %-22s %-18s %-30s " blue "|\n" reset,
               i + 1,
               addressbook->contact_details[i].Name,
               addressbook->contact_details[i].Mobile_number,
               addressbook->contact_details[i].Mail_ID);
    }

    printf(blue "+-------------------------------------------------------------------------------+\n" reset);
}

//Function to search contacts using mail id
int search_email(AddressBook*addressbook)
{
    char email[20];
    printf("Enter the Mail ID: ");
    scanf(" %[^\n]",email);
    int flag=0;
   // int k=0;
    for(int i=0;i<addressbook->contact_count;i++)
    {
        int res=strcmp(email,addressbook->contact_details[i].Mail_ID);
        if(res==0)
        {
            flag=1;
            k=i;
            break;
        }
    }
    if(flag==1)
    {
        printf(green"Contact found\n"reset);
        printf("Name: %s\n",addressbook->contact_details[k].Name);
        printf("Mob No: %s\n",addressbook->contact_details[k].Mobile_number);
        printf("Mail Id: %s\n",addressbook->contact_details[k].Mail_ID); 
        return 0;   
    }
    else
    {
        printf(red"Contact not found!\n"reset);
        return 1;
    }

}

//Function to search contacts using mob no.
int search_phone(AddressBook*addressbook)
{
    char phone[20];
    printf("Enter the Mobile Number: ");
    scanf(" %[^\n]",phone);
    int flag=0;
    // int k=0;
    for(int i=0;i<addressbook->contact_count;i++)
    {
        int res=strcmp(phone,addressbook->contact_details[i].Mobile_number);
        if(res==0)
        {
            flag=1;
            k=i;
            break;
        }
    }
    if(flag==1)
    {
        printf(green"Contact found!\n"reset);
        printf("Name: %s\n",addressbook->contact_details[k].Name);
        printf("Mob No.: %s\n",addressbook->contact_details[k].Mobile_number);
        printf("Mail Id: %s\n",addressbook->contact_details[k].Mail_ID);  
        return 0;  
    }
    else
    {
        printf(red"Contact not found!\n"reset);
        return 1;
    }

}

//Function to search contacts using name
int search_name(AddressBook*addressbook)
{
    int arr[10],count=0;
    char name[20];
    printf("Enter the Name: ");
    scanf(" %[^\n]",name);
    int flag=0;
    //int k=0;
    for(int i=0;i<addressbook->contact_count;i++)
    {
        int res=strcmp(name,addressbook->contact_details[i].Name);
        if(res==0)
        {
            flag=1;
            arr[count]=i;
            k=i;
            count++;
        }
    }
    if(flag==0)
    {
        printf(red"Contact not found !\n"reset);
        return 1;
    }

    if (count > 1)
    {
        printf(red "Duplicate Name found!\n" reset);

        printf(blue "+-------------------------------------------------------------------------------+\n" reset);
        printf(blue "|" reset " %-4s %-22s %-18s %-30s " blue "|\n" reset,
            "SNO", "NAME", "MOBILE NUMBER", "MAIL ID");
        printf(blue "+-------------------------------------------------------------------------------+\n" reset);

        for (int i = 0; i < count; i++)
        {
            printf(blue "|" reset " %-4d %-22s %-18s %-30s " blue "|\n" reset,
                i + 1,
                addressbook->contact_details[arr[i]].Name,
                addressbook->contact_details[arr[i]].Mobile_number,
                addressbook->contact_details[arr[i]].Mail_ID);
        }

        printf(blue "+-------------------------------------------------------------------------------+\n" reset);


        printf("Do you want to search by Mobile Number[1]/Mail ID[0]:");
        int search;
        scanf("%d",&search);
        if(search)
        {
            char mob[11];
            printf("Enter the Mobile Number: ");
            scanf(" %[^\n]",mob);
            for(int i=0;i<count;i++)
            {
                if(strcmp(addressbook->contact_details[arr[i]].Mobile_number,mob)==0)
                {
                    printf(green"Contact Found!!\n"reset);
                    printf("Name: %s\n",addressbook->contact_details[arr[i]].Name);
                    printf("Mobile No.: %s\n",addressbook->contact_details[arr[i]].Mobile_number);
                    printf("Mail Id: %s\n",addressbook->contact_details[arr[i]].Mail_ID);
                    k=arr[i];
                    return 0;
                }
            }
            
            printf(red"Contact not found!!\n"reset);
            return 1;
            
        }
        else
        {
            char email[50];
            printf("Enter the Mail Id: ");
            scanf(" %[^\n]",email);
            for(int i=0;i<count;i++)
            {
                if(strcmp(addressbook->contact_details[arr[i]].Mail_ID,email)==0)
                {
                    printf(green"Contact Found!\n"reset);
                    printf("Name: %s\n",addressbook->contact_details[arr[i]].Name);
                    printf("Mobile No.: %s\n",addressbook->contact_details[arr[i]].Mobile_number);
                    printf("Mail Id: %s\n",addressbook->contact_details[arr[i]].Mail_ID);
                    k=arr[i];
                    return 0;
                }
            }
                
            printf(red"Contact not found!!\n"reset);
            return 1;
            
        }
    }

    else
    {
        printf(green"Contact Found!\n"reset);
        printf("Name: %s\n",addressbook->contact_details[k].Name);
        printf("Mobile No.:%s\n",addressbook->contact_details[k].Mobile_number);
        printf("Mail Id: %s\n",addressbook->contact_details[k].Mail_ID);
        return 0;
    }
    
}

//Function to search contacts
int search_contacts(AddressBook *addressbook)
{  
    int flag = 1; 
    while(flag){
    printf("DO YOU WANT TO SEARCH BY \n1.Name\n2.Mobile Number\n3.Mail ID\n4.Exit\n");
    int opt;
    printf("Select the option: ");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        search_name(addressbook);
        break;
        case 2:
        search_phone(addressbook);
        break;
        case 3:
        search_email(addressbook);
        break;
        case 4:
        return 0;
        default:
        printf(red"Invalid input\n"reset);

    }
    printf("DO YOU WANT TO CONTINUE YES[1]/N0[0]:");
    scanf("%d",&flag);

}
  return 0;
}

//Function to edit a contact
int edit_contact(AddressBook *addressbook)
{
    int flag = 1;
    while (flag)
    {
        // search_contacts(addressbook);

        printf("DO YOU WANT SEARCH BY\n1.Name\n2.Mob No.\n3.Mail Id\n4.Exit\n");
        char opt;
        scanf(" %c", &opt);
        char name[20];
        char phone[20];
        char email[20];
        switch (opt)
        {
        case '1':
            int res = 1;
            while (res)
            {
                res = search_name(addressbook);
            }
            
            edit : res = 1;
            while (res)
            {
                printf("DO YOU WANT TO EDIT BY\n1.Name\n2.Mobile Number\n3.Mail Id\n4.Edit all\n");
                int opt;
                printf("Select the option: ");
                scanf(" %d", &opt);
    

                switch (opt)
                {
                case 1:
                    res = 1;
                    while (res)
                    {
                        printf("ENTER THE NEW NAME: ");
                        scanf(" %[^\n]", name);
                        res = name_validation(name);
                    }
                    strcpy(addressbook->contact_details[k].Name, name);
                    printf(green "EDITED SUCCESSFULLY!!\n" reset);
                    printf("Name: %s\n", addressbook->contact_details[k].Name);
                    printf("Mobile number: %s\n", addressbook->contact_details[k].Mobile_number);
                    printf("Mail ID: %s\n", addressbook->contact_details[k].Mail_ID);
                    break;

                case 2:
                    res = 1;
                    while (res)
                    {
                        printf("ENTER THE NEW MOBILE NUMBER: ");
                        scanf(" %[^\n]", phone);
                        res = mobile_validation(phone, addressbook);
                    }
                    strcpy(addressbook->contact_details[k].Mobile_number, phone);
                    printf(green "EDITED SUCCESSFULLY\n" reset);
                    printf("Name: %s\n", addressbook->contact_details[k].Name);
                    printf("Mobile Number: %s\n", addressbook->contact_details[k].Mobile_number);
                    printf("Mail ID: %s\n", addressbook->contact_details[k].Mail_ID);
                    break;

                case 3:
                    res = 1;
                    while (res)
                    {
                        printf("ENTER THE NEW MAIL ID:");
                        scanf(" %[^\n]", email);
                        res =  email_validation(email, addressbook);
                    }    
                    strcpy(addressbook->contact_details[k].Mail_ID, email);
                    printf(green "EDITED SUCCESSFULLY!!\n" reset);
                    printf("Name: %s\n", addressbook->contact_details[k].Name);
                    printf("Moble Number: %s\n", addressbook->contact_details[k].Mobile_number);
                    printf("Mail ID: %s\n", addressbook->contact_details[k].Mail_ID);
                    break;


                case 4:
                    res = 1;
                    while (res)
                    {
                        printf("ENTER THE NEW NAME: ");
                        scanf(" %[^\n]", name);
                        res = name_validation(name);
                    }
                    strcpy(addressbook->contact_details[k].Name, name);

                    res = 1;
                    while (res)
                    {
                        printf("ENTER THE NEW NUMBER: ");
                        scanf(" %[^\n]", phone);
                        res = mobile_validation(phone, addressbook);
                    }
                    strcpy(addressbook->contact_details[k].Mobile_number, phone);

                    res = 1;
                    while (res)
                    {
                        printf("ENTER THE MAIL ID: ");
                        scanf(" %[^\n]", email);
                        res =  email_validation(email, addressbook);
                    }    
                    strcpy(addressbook->contact_details[k].Mail_ID, email);

                    printf(green "EDITED SUCCESSFULLY\n" reset);
                    printf("Name: %s\n", addressbook->contact_details[k].Name);
                    printf("Mob No.: %s\n", addressbook->contact_details[k].Mobile_number);
                    printf("Mail Id: %s\n", addressbook->contact_details[k].Mail_ID);
                    break;

                default:
                    printf(red "Invalid Input!\n" reset);
                    
                }
            }
            break;
            

        case '2':
            res = 1;
            while (res)
            {
                res = search_phone(addressbook);
            }
            goto edit;
            break;

        case '3':
            res = 1;
            while (res)
            {
                res = search_email(addressbook);
            }
            goto edit; 
            break;

        case '4':
            return 0;
        default:
            printf(red "Invalid Input!" reset);

            k = -1;
            break;
        }
        printf("DO YOU WANT TO CONTINUE  YES[1]/NO[0]:");
        scanf("%d", &flag);
    }

    return 0;
}

//Function to delete a contact from the list 
int delete_contact(AddressBook *addressbook)
{
    int opt1;
    printf("DO YOU WANT TO SEARCH BY:\n1.Name\n2.Mobile Number\n3.Mail ID\n4.Exit\n");
    scanf(" %d", &opt1);
    switch (opt1)
    {
    case 1:
        search_name(addressbook);
        break;
    case 2:
        search_phone(addressbook);
        break;
    case 3:
        search_email(addressbook);
        break;
    case 4:
        return 0;
    default:
        printf(red "Invalid Input!!\n" reset);
        break;
    }
    printf("DO YOU WANT TO DELETE THIS CONTACT YES[1]/NO[0]:");
    int opt;
    scanf("%d", &opt);
    if (opt == 1)
    {
        for (int i = k; i < addressbook->contact_count - 1; i++)
        {
            addressbook->contact_details[i] = addressbook->contact_details[i + 1];
        }
        printf(green "CONTACT SUCCESSFULLY DELETED!\n" reset);
        (addressbook->contact_count)--;
    }
    else
    {
        printf(red "DELETION CANCELLED!\n" reset);
        return 0;
    }

    return 0;
}

//Function to save contacts to the file
int save_contacts(AddressBook *addressbook)
{
    save_contacts_file(addressbook);

    return 0;
}