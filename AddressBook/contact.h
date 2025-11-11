// This is a header file contains the prototype of two structures and functions.

#ifndef CONTACT_H  
#define CONTACT_H

#define MAX_CONTACTS 100 // macro

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact; // datatype

typedef struct {   //User defined data  type- used to give aliased name for one data type.
    Contact contacts[MAX_CONTACTS]; // array of structure--<100
    int contactCount; // indicate the no: of contacts present 
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);


#endif
