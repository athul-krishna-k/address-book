/*
Name : Athul Krishna K
Date : 07/12/2025
Description : Addressbook Project
*/

#include <stdio.h>
#include "contact.h"

#define red     "\033[1;31m"
#define green   "\033[1;32m"
#define blue    "\033[1;34m"
#define reset   "\033[0m"

int main()
{
    int option;
    AddressBook addressbook;

    addressbook.contact_count = 0;

    init_intitalization(&addressbook);

    while (1)
    {
        printf(blue "┌───────────────────────────────────┐\n" reset);
        printf(blue "│" reset       "         ADDRESS BOOK MENU         " reset blue "│\n" reset);
        printf(blue "├───────────────────────────────────┤\n" reset);
        printf(blue "│" reset " 1. Add contact                    " blue "│\n" reset);
        printf(blue "│" reset " 2. Search contact                 " blue "│\n" reset);
        printf(blue "│" reset " 3. Edit contact                   " blue "│\n" reset);
        printf(blue "│" reset " 4. Delete contact                 " blue "│\n" reset);
        printf(blue "│" reset " 5. Display contacts               " blue "│\n" reset);
        printf(blue "│" reset " 6. Save contacts                  " blue "│\n" reset);
        printf(blue "│" reset " 7. Exit                           " blue "│\n" reset);
        printf(blue "└───────────────────────────────────┘\n" reset);

        printf("Enter your option: ");
        scanf("%d", &option);
        getchar();

        switch (option) 
        {
        case 1:
        
            create_contact(&addressbook);
            break;
        
        case 2:
        
            
            search_contacts(&addressbook);
            break;
        
        case 3:

            edit_contact(&addressbook);
            break;

        case 4:
            delete_contact(&addressbook);
            break;

        case 5: 
            list_contacts(&addressbook);
            break;
        
        case 6:
            printf(green"Saving contacts.....\nContacts Saved!\n"reset);
            save_contacts(&addressbook);
            break;

        case 7:
            printf("INFO : Save and Exit...\n");
            return 0;

        default:
            printf("Invalid option \n");
            break;
        }
    }
    return 0;
}
