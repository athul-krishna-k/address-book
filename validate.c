#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"contact.h"

#define red     "\033[1;31m"
#define green   "\033[1;32m"
#define blue    "\033[1;34m"
#define reset   "\033[0m"

// Validate name: only alphabets and spaces allowed
int name_validation(char*name)
{
    int i=0;
    while(name[i]!='\0')
    {
        if((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) || (name[i]==' '))
        {
            i++;
        }
        else
        {
            printf(red"NAME SHOULD ONLY BE ALPHABETS...TRY AGAIN\n"reset); // Invalid character
            return 1;
        }
    }
    return 0;
}

// Validate mobile number: 10 digits, starts 6-9, digits only, must be unique
int mobile_validation(char*mob, AddressBook *addressbook)
{
    int i=0;
    int len=strlen(mob);

    if(len!=10) // Must be exactly 10 digits
    {
        printf(red"NUMBER SHOULD CONTAIN EXACTLY 10 DIGITS...TRY AGAIN\n"reset);
        return 1;
    }

    if(mob[0]<'6') // First digit check
    {
        printf(red"NUMBER SHOULD START WITH 6-9...TRY AGAIN\n"reset);
        return 1;
    }

    while(mob[i]!='\0') // Ensure all characters are digits
    {
        if(isdigit(mob[i]))
        {
            i++;
        }
        else
        {
            printf(red"NUMBER SHOULD CONTAIN ONLY DIGITS...TRY AGAIN\n"reset);
            return 1;
        }
    }

    // Check uniqueness in existing contacts
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(mob,addressbook->contact_details[i].Mobile_number)==0)
        {
            printf(red"CONTACT SHOULD BE UNIQUE...TRY AGAIN\n"reset);
            return 1;
        }
    }
    return 0;
}

// Validate email: proper format, lowercase, uniqueness
int email_validation(char*email, AddressBook *addressbook)
{
    if(!isalpha(email[0])) // Must start with an alphabet
    {
        printf(red"EMAIL SHOULD START WITH ALPHABETS ONLY...TRY AGAIN\n"reset);
        return 1;
    }

    int count=0;
    for(int i=0;email[i]!='\0';i++)
    {
         if(email[i]=='@') count++; // Count '@'
    }

    if(count==0 || count>1) // Must have exactly 1 '@'
    {
        printf(red"EMAIL SHOULD CONTAIN 1 @....TRY AGAIN\n"reset);
        return 1;
    }

    if(strstr(email,".com")==0) // Must contain '.com'
    {
        printf(red"EMAIL SHOULD CONTAIN '.com'...TRY AGAIN\n"reset);
        return 1;
    }

    char*atrate=strstr(email,"@");
    char*dotcom=strstr(email,".com");
    int diff= dotcom - atrate;

    if(diff<=1) // Ensure domain name exists between '@' and '.com'
    {
        printf(red"EMAIL SHOULD CONTAIN DOMAIN NAME...TRY AGAIN\n"reset);
        return 1;
    }

    if((atrate-email)<3) // Minimum 4 chars before '@'
    {
        printf(red"EMAIL ID SHOULD CONTAIN ATLEAST 4 CHARACTER...TRY AGAIN\n"reset);
        return 1;
    }

    int i=0;
    while(email[i]!='\0') // No uppercase allowed
    {
        if(isupper(email[i]))
        {
            printf(red"EMAIL SHOULD NOT CONTAIN UPPERCASE...TRY AGAIN\n"reset);
            return 1;
        }
        else i++;
    }

    // Check uniqueness in existing contacts
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(email,addressbook->contact_details[i].Mail_ID)==0)
        {
            printf(red"CONTACT SHOULD BE UNIQUE...TRY AGAIN\n"reset);
            return 1;
        }
    }
    return 0;
}
