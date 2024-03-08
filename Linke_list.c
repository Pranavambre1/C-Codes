#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Structure of a node */
struct node
{
    int data;          // Data
    struct node *next; // Address
} *head;

/*
 * Functions to create and display list
 */
void createList(int n);
void traverseList();
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtMiddle(int data, int position);
void deleteFirstNode();
void deleteLastNode();
void deleteMiddleNode(int position);
int search(int key);

int main()
{
    int n, data, position, index, keyToSearch;
    //  clrscr();
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);

    int choice;
    do
    {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at middle\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at middle\n");
        printf("7. Search for an element\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning of the list: ");
            scanf("%d", &data);
            insertNodeAtBeginning(data);
            traverseList();
            break;

        case 2:
            printf("Enter data to insert at the end of the list: ");
            scanf("%d", &data);
            insertNodeAtEnd(data);
            traverseList();
            break;

        case 3:
            printf("Enter data to insert at middle of the list: ");
            scanf("%d", &data);
            printf("Enter the position to insert a new node: ");
            scanf("%d", &position);
            insertNodeAtMiddle(data, position);
            traverseList();
            break;

        case 4:
            deleteFirstNode();
            traverseList();
            break;

        case 5:
            deleteLastNode();
            traverseList();
            break;

        case 6:
            printf("Enter the node position you want to delete: ");
            scanf("%d", &position);
            deleteMiddleNode(position);
            traverseList();
            break;

        case 7:
            printf("Enter an element to search: ");
            scanf("%d", &keyToSearch);
            index = search(keyToSearch);
            if (index >= 0)
                printf("%d found in the list at position %d\n", keyToSearch, index + 1);
            else
                printf("%d not found in the list.\n", keyToSearch);
            break;

        case 8:
            printf("Data in the list:\n");
            traverseList();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
    getch();
    return 0;
}

// Create a list of n nodes
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }

    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    // Create n - 1 nodes and add to the list
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if (newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure the new node points to NULL

        temp->next = newNode; // Link the previous node with newNode
        temp = temp->next;    // Make the current node the previous node
    }
}

// Display entire list
void traverseList()
{
    struct node *temp;

    // Return if the list is empty
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data); // Print the data of the current node
        temp = temp->next;                 // Move to the next node
    }
}

// Create a new node and insert it at the beginning of the linked list
void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = head; // Link the address part

        head = newNode; // Make newNode the first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

// Create a new node and insert it at the end of the linked list
void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = NULL;

        temp = head;

        // Traverse to the last node
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link the address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

// Create a new node and insert it in the middle of the linked list
void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = NULL;

        temp = head;

        /*
         * Traverse to the (position - 1) node
         */
        for (i = 2; i <= position - 1; i++)
        {
            temp = temp->next;

            if (temp == NULL)
                break;
        }

        if (temp != NULL)
        {
            /* Link the address part of the new node */
            newNode->next = temp->next;

            /* Link the address part of the (position - 1) node */
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}

// Delete the first node from the list
void deleteFirstNode()
{
    struct node *toDelete;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d from position 1\n", toDelete->data);

        /* Clears the memory occupied by the first node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED THE FIRST NODE FROM THE LIST\n");
    }
}

// Delete the last node of the linked list
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;
    int position = 0;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        /* Traverse to the last node of the list */
        while (toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
            position++;
        }

        if (toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect the link of the second last node with the last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("Data deleted = %d from position %d\n", toDelete->data, position + 1);
        printf("SUCCESSFULLY DELETED THE LAST NODE OF THE LIST\n");
    }
}

// Delete the middle node of the linked list
void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;
    int deletedPosition = position;
    position = 0;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for (i = 2; i <= deletedPosition; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if (toDelete == NULL)
                break;
            position++;
        }

        if (toDelete != NULL)
        {
            if (toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            /* Delete the nth node */
            free(toDelete);

            printf("Data deleted = %d from position %d\n", toDelete->data, position + 1);
            printf("SUCCESSFULLY DELETED A NODE FROM THE MIDDLE OF THE LIST\n");
        }
        else
        {
            printf("Invalid position, unable to delete.\n");
        }
    }
}


// Search for an element with the given key in the linked list
int search(int key)
{
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;

    // Iterate until the last element is found or the key is not found
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }

    return (curNode != NULL) ? index : -1;
}
