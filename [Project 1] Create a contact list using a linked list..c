/*
    Project 1:
    -----------

    Create a contact list using a linked list. Each node contains the name, occupation and cell phone number.
    Contact list will have several subgroups like- School friend, College friend, University friend, Paternal relatives, Maternal relatives.

    A person may have more than one contact. The menu option will be i) Add a contact,
                                                                    ii) Edit a contact,
                                                                   iii) Search a contact,
                                                                    iv) Delete a contact (Remove a person with all contacts or remove a contact of a person having more than one),
                                                                     v) Display all contact in a group,
                                                                    vi) Delete all contact in a group,
                                                                   vii) Exit.
    On the exit, each time the system will save all the data to a file, and a contact list with all the data from the file will be created when you launch a new session.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact                                      /// Structure Define
{
    char name[50];
    char occupation[50];
    long long int phone;
    struct contact *next;
};

struct group
{
    char name[50];
    struct contact *head;
};

struct group *createGroup(char name[])
{
    struct group *newGroup = (struct group*)malloc(sizeof(struct group));
    strcpy(newGroup->name, name);
    newGroup->head = NULL;
    return newGroup;
}

void addContact(struct group *group)                                        /// Contact add
{
    struct contact *newContact = (struct contact*)malloc(sizeof(struct contact));
    printf("-> Enter name: ");
    scanf("%s", newContact->name);
    printf("-> Enter occupation: ");
    scanf("%s", newContact->occupation);
    printf("-> Enter phone: ");
    scanf("%lld", &newContact->phone);
    newContact->next = NULL;

    if(group->head == NULL){
        group->head = newContact;
    }

    else{
        struct contact *temp = group->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newContact;
    }

    printf("\n\t\t>> Contact added successfully! <<\n");
}

void displayContacts(struct group *group)                                       /// Contact Show
{
    if(group->head == NULL)
        printf("\n\t\t>> No contacts found in this group! <<\n");

    else
    {
        int con_num=0;
        printf("\n--> Contacts in %s group:\n\n", group->name);
        struct contact *temp = group->head;
        while(temp != NULL)
        {
            con_num++;
            printf("------ Contact %d -------------\n", con_num);
            printf("-> Name: %s\n", temp->name);
            printf("-> Occupation: %s\n", temp->occupation);
            printf("-> Phone: %lld\n", temp->phone);
            printf("------------------------------\n\n");
            temp = temp->next;

        }
    }
}

void searchContact(struct group *group)                                        /// Contact Search
{
    if(group->head == NULL)
        printf("\n\t\t>> No contacts found in this group! <<\n");

    else
    {
        char name[50];
        printf("-> Enter name of contact to search: ");
        scanf("%s", name);
        struct contact *temp = group->head;
        int found = 0;
        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("\n\t\t>> Contact found! <<\n\n");
                printf("--------------------\n");
                printf("-> Name: %s.\n", temp->name);
                printf("-> Occupation: %s.\n", temp->occupation);
                printf("-> Phone: %lld.\n", temp->phone);
                printf("--------------------\n");
                found = 1;
            }
            temp = temp->next;
        }

        if(!found)
        printf("\n\t\t>> Contact not found! <<\n");
    }
}

void editContact(struct group *group)                                      /// Contact Edit
{
    if(group->head == NULL)
        printf("\n\t\t>> No contacts found in this group! <<\n");

    else
    {
        char name[50];
        printf("-> Enter name of contact to edit: ");
        scanf("%s", name);
        struct contact *temp = group->head;
        int found = 0;
        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("\n-> Enter new name: ");
                scanf("%s", temp->name);
                printf("-> Enter new occupation: ");
                scanf("%s", temp->occupation);
                printf("-> Enter new phone: ");
                scanf("%lld", &temp->phone);
                printf("\n\t\t>> Contact updated successfully! <<\n");
                found = 1;
            }
            temp = temp->next;
        }

        if(!found)
            printf("\n\t\t>> Contact not found! <<\n");
    }
}

void deleteContact(struct group *group)                                        /// Single Contact Delete
{
    if(group->head == NULL)
        printf("\n\t\t>> No contacts found in this group! <<\n");

    else
    {
        char name[50];
        printf("-> Enter name of contact to search: ");
        scanf("%s", name);
        struct contact *temp = group->head;
        struct contact *prev = NULL;
        int found = 0;
        while(temp != NULL){
            if(strcmp(temp->name, name) == 0){
                found = 1;
                if(prev == NULL){
                    group->head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                free(temp);
                printf("\n\t\t>> Contact deleted successfully! <<\n");
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(!found){
            printf("\n\t\t>> Contact not found!<<\n");
        }
    }
}

void deleteAllContacts(struct group *group){                                            /// Full Contact Delete
    if(group->head == NULL){
        printf("\n\t\t>> No contacts found in this group! <<\n");
    }
    else{
        struct contact *temp = group->head;
        while(temp != NULL){
            group->head = temp->next;
            free(temp);
            temp = group->head;
        }
        printf("\n\t\t>> All contacts deleted successfully! <<\n");
    }
}

void saveToFile(struct group *group, FILE *fptr){
    if(group->head == NULL){
        return;
    }
    struct contact *temp = group->head;
    while(temp != NULL){
        fprintf(fptr, "%s %s %lld %s\n", temp->name, temp->occupation, temp->phone, group->name);
        temp = temp->next;
    }
}

void saveAllToFile(struct group *groups[], int numGroups){                                       /// File Save On Exit
    FILE *fptr;
    fptr = fopen("contacts.txt", "w");
    if(fptr == NULL){
        printf("Error opening file!");
        exit(1);
    }
    for(int i=0; i<numGroups; i++){
        saveToFile(groups[i], fptr);
    }
    fclose(fptr);
    printf("\n\t\t>> Contacts saved to file successfully! <<\n");
}

void readFromFile(struct group *groups[], int numGroups){                                       /// Load File On Startup
    FILE *fptr;
    fptr = fopen("contacts.txt", "r");
    if(fptr == NULL){
        printf("--> File does not exist or could not be opened!\n");
        fptr = fopen("contacts.txt", "a");
        printf("--> New file created successfully!\n\n");
        return;
    }
    char name[50], occupation[50], groupName[50];
    long long int phone;
    while(fscanf(fptr, "%s %s %lld %s", name, occupation, &phone, groupName) != EOF){
        for(int i=0; i<numGroups; i++){
            if(strcmp(groups[i]->name, groupName) == 0){
                struct contact *newContact = (struct contact*)malloc(sizeof(struct contact));
                strcpy(newContact->name, name);
                strcpy(newContact->occupation, occupation);
                newContact->phone = phone;
                newContact->next = NULL;
                if(groups[i]->head == NULL){
                    groups[i]->head = newContact;
                }
                else{
                    struct contact *temp = groups[i]->head;
                    while(temp->next != NULL){
                        temp = temp->next;
                    }
                    temp->next = newContact;
                }
            }
        }
    }
    fclose(fptr);
    printf("--> Contacts loaded from file successfully!\n\n");
}

int main(){
    int numGroups = 5, count;
    struct group *groups[numGroups];
    groups[0] = createGroup("School-Friend");
    groups[1] = createGroup("College-Friend");
    groups[2] = createGroup("University-Friend");
    groups[3] = createGroup("Paternal-Relatives");
    groups[4] = createGroup("Maternal-Relatives");
    readFromFile(groups, numGroups);
    int choice;
    char groupName[50], name[50];
    while(1){
        printf("\n   MENU:\n");
        printf("-----------\n");
        printf("1. Add a contact.\n");
        printf("2. Edit a contact.\n");
        printf("3. Search a contact.\n");
        printf("4. Delete a contact.\n");
        printf("5. Display all contact.\n");
        printf("6. Delete all contact.\n");
        printf("7. Exit.\n");
        printf("=}} Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("-> Enter group name_(School-Friend, College-Friend, University-Friend, Paternal-Relatives, Maternal-Relatives):\n\t ");
                scanf("%s", groupName);
                for(int i=0; i<numGroups; i++){
                    if(strcmp(groups[i]->name, groupName) == 0){
                        addContact(groups[i]);
                        break;
                    }else{
                        count++;
                    }
                }
                if(count == 5)
                    printf("\nGroup doesn't exist!\n");
                break;
            case 2:
                printf("-> Enter group name_(School-Friend, College-Friend, University-Friend, Paternal-Relatives, Maternal-Relatives):\n\t ");
                scanf("%s", groupName);
                for(int i=0; i<numGroups; i++){
                    if(strcmp(groups[i]->name, groupName) == 0){
                        editContact(groups[i]);
                        break;
                    }else{
                        count++;
                    }
                }
                if(count == 5)
                    printf("\nGroup doesn't exist!\n");
                break;
            case 3:
                printf("-> Enter group name_(School-Friend, College-Friend, University-Friend, Paternal-Relatives, Maternal-Relatives):\n\t ");
                scanf("%s", groupName);
                for(int i=0; i<numGroups; i++){
                    if(strcmp(groups[i]->name, groupName) == 0){
                        searchContact(groups[i]);
                        break;
                    }else{
                        count++;
                    }
                }
                if(count == 5)
                    printf("\nGroup doesn't exist!\n");
                break;
            case 4:
                printf("-> Enter group name_(School-Friend, College-Friend, University-Friend, Paternal-Relatives, Maternal-Relatives):\n\t ");
                scanf("%s", groupName);
                for(int i=0; i<numGroups; i++){
                    if(strcmp(groups[i]->name, groupName) == 0){
                        deleteContact(groups[i]);
                        break;
                    }else{
                        count++;
                    }
                }
                if(count == 5)
                    printf("\nGroup doesn't exist!\n");
                break;
            case 5:
                printf("-> Enter group name_(School-Friend, College-Friend, University-Friend, Paternal-Relatives, Maternal-Relatives):\n\t ");
                scanf("%s", groupName);
                for(int i=0; i<numGroups; i++){
                    if(strcmp(groups[i]->name, groupName) == 0){
                        displayContacts(groups[i]);
                        break;
                    }else{
                        count++;
                    }
                }
                if(count == 5)
                    printf("\nGroup doesn't exist!\n");
                break;
            case 6:
                printf("-> Enter group name_(School-Friend, College-Friend, University-Friend, Paternal-Relatives, Maternal-Relatives):\n\t ");
                scanf("%s", groupName);
                for(int i=0; i<numGroups; i++){
                    if(strcmp(groups[i]->name, groupName) == 0){
                        deleteAllContacts(groups[i]);
                        break;
                    }else{
                        count++;
                    }
                }
                if(count == 5)
                    printf("\nGroup doesn't exist!\n");
                break;
            case 7:
                saveAllToFile(groups, numGroups);
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
