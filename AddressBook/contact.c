#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    for(int i= 0; i<addressBook->contactCount;i++){
    printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

static int check_phone(char *phone, AddressBook *addressbook){
    for(int i=0; i<addressbook->contactCount;i++){
        if (strcmp(phone, addressbook->contacts[i].phone) == 0){
            return 1;
        }       
    }
    return 0;
}

static int valid_phone(char *phone){
    if (strlen(phone)!=10){
        return 0;
    }
    for(int i=0;i<10;i++){
        if (isdigit(phone[i]) == 0){
            return 0;
        }
    }
    return 1;
}

static int check_email(char *email, AddressBook *addressbook){
    for(int i=0; i<addressbook->contactCount;i++){
        if (strcmp(email, addressbook->contacts[i].email) == 0){
            return 1;
        }     
    }
    return 0;
}

static int valid_email(char *email){
    if (strchr(email,'@')== NULL){
        return 0;
    }
    if (strstr(email, ".com")== NULL){
        return 0;
    }

    char *at = strchr(email,'@');
    char *dotcom = strstr(email, ".com");
    if (dotcom <at){
        return 0;
    }
    return 1;

}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[20], phone[20], email[20];
    int res, valid;
    printf("Enter the name : ");
    scanf(" %19[^\n]", name);

    do{
        printf("Enter the phone number : ");
        scanf(" %19[^\n]", phone);
        valid = valid_phone(phone);
        if (valid){
            res = check_phone(phone, addressBook);
            if(res==1){
                printf("The phone number is already present\n");
            }  
        }
        else{
            printf("Phone number is not vaild\n");
        }

    }while(valid == 0 || res == 1);

    do{
        printf("Enter the email id : ");
        scanf(" %19[^\n]", email);
        valid = valid_email(email);
        if (valid){
            int res = check_email(email, addressBook);
            if(res==1){
                printf("The email id is already present\n");
            }
        }
        else{
            printf("Email id is not valid\n");
        }

        
    }while(valid==0 || res == 1);

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    (addressBook->contactCount)++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int option, flag = 0;;
    char name[20];
    char ph_no[15];
    char email_id[20];
    printf("1. Search by name\n 2.Search by phn no\n 3.Search by email id\n");
    printf("Enter the option : ");
    scanf("%d", &option);

    switch(option)
    {
        case 1: 
                printf("Enter the name : ");
                scanf(" %19[^\n]", name);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(name, addressBook -> contacts[i].name) == 0){
                        printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }
                    
                }
                if(flag == 0){
                    printf("name is not found\n");
                }  
                break;
        case 2: 
                printf("Enter the ph no : ");
                scanf(" %14[^\n]", ph_no);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(name, addressBook -> contacts[i].phone) == 0){
                        printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }
                    
                    if(flag == 0){
                        printf("Phone number is not found\n");
                    }  
                }
                break;
        case 3: 
                printf("Enter the email id : ");
                scanf(" %19[^\n]", email_id);
        
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(name, addressBook -> contacts[i].email) == 0){
                        printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }
                    
                    if(flag == 0){
                        printf("Email id is not found\n");
                    }                  
                }
                break;
    }

}
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int option, choice, index = -1;
    int flag = 0;
    char name[20];
    char ph_no[15];
    char email_id[20];

    printf("1. select by name\n 2.select by phn no\n 3.select by email id\n");
    printf("Enter the option : ");
    scanf("%d",&option);

    switch (option)
    {       
        case 1:
                printf("Enter the name to edit: ");
                scanf(" %[^\n]", name);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(name, addressBook -> contacts[i].name) == 0){
                        printf("%d %s %s %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }       
                }
                if(flag){
                    printf("Enter the index: ");
                    scanf("%d", &index);
                    if(index!= -1){
                        printf("1. Edit by name\n 2.Edit by phn no\n 3.Edit by email id\n 4.Edit all detail\n");       
                        printf("Enter the choice : ");
                        scanf("%d", &choice);   
                        
                        switch (choice)
                        {
                            case 1:
                                printf("Enter the new name: ");
                                scanf(" %[^\n]", name);
                                strcpy(addressBook->contacts[index].name, name);
                                break;
                            
                            case 2:
                                printf("Enter the new ph no: ");
                                scanf(" %[^\n]", ph_no);
                                strcpy(addressBook->contacts[index].phone, ph_no);
                                break;

                            case 3:
                                printf("Enter the new email id: ");
                                scanf(" %[^\n]", email_id);
                                strcpy(addressBook->contacts[index].email, email_id);
                                break;
                            case 4:
                                printf("Enter the new name: ");
                                scanf(" %[^\n]", name);
                                strcpy(addressBook->contacts[index].name, name);

                                printf("Enter the new ph no: ");
                                scanf(" %[^\n]", ph_no);
                                strcpy(addressBook->contacts[index].phone, ph_no);

                                printf("Enter the new email id: ");
                                scanf(" %[^\n]", email_id);
                                strcpy(addressBook->contacts[index].email, email_id);
                                break;
                            default:
                            break;
                        }
                    }
                 
                }
                else{
                    printf("Entered name is wrong\n");
                }
                break;
        case 2:
                printf("Enter the phone no: to edit: ");
                scanf(" %[^\n]", ph_no);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(ph_no, addressBook -> contacts[i].phone) == 0){
                        index =i;
                    }       
                }
                if(index!= -1){
                    printf("1. Edit by name\n 2.Edit by phn no\n 3.Edit by email id\n 4.Edit all detail\n");       
                    printf("Enter the choice : ");
                    scanf("%d", &choice);   
      
                    switch (choice)
                    {
                        case 1:
                            printf("Enter the new name: ");
                            scanf(" %[^\n]", name);
                            strcpy(addressBook->contacts[index].name, name);
                            break;
                        
                        case 2:
                            printf("Enter the new ph no: ");
                            scanf(" %[^\n]", ph_no);
                            strcpy(addressBook->contacts[index].phone, ph_no);
                            break;

                        case 3:
                            printf("Enter the new email id: ");
                            scanf(" %[^\n]", email_id);
                            strcpy(addressBook->contacts[index].email, email_id);
                            break;
                        
                        case 4:
                            printf("Enter the new name: ");
                            scanf(" %[^\n]", name);
                            strcpy(addressBook->contacts[index].name, name);

                            printf("Enter the new ph no: ");
                            scanf(" %[^\n]", ph_no);
                            strcpy(addressBook->contacts[index].phone, ph_no);
                            
                            printf("Enter the new email id: \n");
                            scanf(" %[^\n]", email_id);
                            strcpy(addressBook->contacts[index].email, email_id);
                            break;
                        default:
                        break;
                    }
                }
                break;
                
        case 3:
                printf("Enter the email id: to edit: ");
                scanf(" %[^\n]", email_id);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(email_id, addressBook -> contacts[i].email) == 0){
                        index =i;
                    }       
                }
                if(index!= -1){
                    printf("1. Edit by name\n 2.Edit by phn no\n 3.Edit by email id\n 4.Edit all detail\n");       
                    printf("Enter the choice : ");
                    scanf("%d", &choice);   
      
                    switch (choice)
                    {
                    case 1:
                        printf("Enter the new name: ");
                        scanf(" %[^\n]", name);
                        strcpy(addressBook->contacts[index].name, name);
                        break;
                    
                    case 2:
                        printf("Enter the new ph no: ");
                        scanf(" %[^\n]", ph_no);
                        strcpy(addressBook->contacts[index].phone, ph_no);
                        break;

                    case 3:
                        printf("Enter the new email id: ");
                        scanf(" %[^\n]", email_id);
                        strcpy(addressBook->contacts[index].email, email_id);
                        break;
                    
                    case 4:
                        printf("Enter the new name: ");
                        scanf(" %[^\n]", name);
                        strcpy(addressBook->contacts[index].name, name);

                        printf("Enter the new ph no: ");
                        scanf(" %[^\n]", ph_no);
                        strcpy(addressBook->contacts[index].phone, ph_no);
                        
                        printf("Enter the new email id: ");
                        scanf(" %[^\n]", email_id);
                        strcpy(addressBook->contacts[index].email, email_id);
                        break;
                    default:
                       break;
                    }
                }
                break; 
        default:
            break;           
    }
    if(index == -1){
        printf("Contact not found\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int option, choice, index = -1;
    int flag=0;
    char name[20];
    char ph_no[15];
    char email_id[20];

    printf("1. select by name\n 2.select by phn no\n 3.select by email id\n");
    printf("Enter the option : ");
    scanf("%d",&option);

    switch (option)
    {       
        case 1:
                printf("Enter the name to delete: ");
                scanf(" %[^\n]", name);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(name, addressBook -> contacts[i].name) == 0){
                        printf("%d %s %s %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }       
                }
                if(flag==1){
                    printf("Enter the index: ");
                    scanf("%d", &index);
                    if(index!= -1){
                        for(int i=index;i<addressBook->contactCount;i++){
                            addressBook->contacts[i]= addressBook->contacts[i+1];

                        }
                        (addressBook->contactCount)--;

                    }   
                }
                else{
                    printf("wrong name\n");
                }
                
                break;
        case 2:
                printf("Enter the phone no: to delete: ");
                scanf(" %[^\n]", ph_no);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(ph_no, addressBook -> contacts[i].phone) == 0){
                        printf("%d %s %s %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }       
                }
                if(flag ==1){
                    printf("Enter the index: ");
                    scanf("%d", &index);
                    if(index!= -1){
                        for(int i=index;i<addressBook->contactCount;i++){
                            addressBook->contacts[i]= addressBook->contacts[i+1];

                        }
                        (addressBook->contactCount)--;

                    }  
                }
                else{
                    printf("Wrong Phone number\n");
                } 
                break;
        case 3:
                printf("Enter the email id to delete: ");
                scanf(" %[^\n]", email_id);
                for(int i = 0; i<addressBook->contactCount;i++){
                    if (strcmp(email_id, addressBook -> contacts[i].email) == 0){
                        printf("%d %s %s %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        flag = 1;
                    }       
                }
                if (flag == 1){
                    printf("Enter the index: ");
                    scanf("%d", &index);
                    if(index!= -1){
                        for(int i=index;i<addressBook->contactCount;i++){
                            addressBook->contacts[i]= addressBook->contacts[i+1];

                        }
                        (addressBook->contactCount)--;

                    }  
                }
                else{
                    printf("Wrong email id\n");
                } 
                break;
        default:
            printf("Invalid option!\n");
            return;

    }
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }
}