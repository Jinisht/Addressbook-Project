#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = {                  // array of structure//static global variable and available only to this file. 
                                                    //static variable is available till the termination of the program// internal linkage
    {"John Doe", "1234567890", "john@example.com"},  
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Alice Smith", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};

void populateAddressBook(AddressBook* addressBook)
/*
{
    int numDummyContacts = sizeof(dummyContacts) / sizeof(dummyContacts[0]);
    for (int i = 0; i < numDummyContacts && addressBook->contactCount < MAX_CONTACTS; ++i) {
        addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
    }
}
    */
{
 int size =  sizeof(dummyContacts)/sizeof(dummyContacts[0]);

 for (int i=0;i<size;i++)
 {
    addressBook->contacts[i] = dummyContacts[i];
    (addressBook ->contactCount)++;
 }
}