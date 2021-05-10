// *******************************
// Singly Linked List
// *******************************


#include <bits/stdc++.h>
using namespace std;

//  Link list node
class Node
{
public:
    int data;
    Node *next;
};

// Counts no. of nodes in linked list
int getCount(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// inserts a new node on the front of the list.
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// insert at the end
void back_push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    //  If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
    {
        //  Else traverse till the last node
        while (last->next != NULL)
            last = last->next;
    }

    //  Change the next of last node
    last->next = new_node;
    return;
}

// Delete from front
void delete_front(Node **head_ref)
{
    if ((*head_ref) != NULL)
    {
        Node *tmp = (*head_ref)->next;
        delete (*head_ref);
        (*head_ref) = tmp;
    }
    else
        return NULL;
}

// Delete from back
void delete_back(Node **head_ref)
{
    if ((*head_ref) != NULL)
    {
        Node *end = (*head_ref);
        Node *prev_end;

        while (end->next != NULL)
        {
            prev_end = end;
            end = end->next;
        }

        prev_end->next = NULL;
        if (end != NULL)
            delete end;
    }
}

// Display the elements of the list
void display(Node **head_ref)
{

    Node *ptr = *head_ref;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Driver
int main()
{
    Node *head = NULL;
    int ch, n, i;

    while (1)
    {
        // Menu
        cout << "\n........Menu.........." << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Delete at end" << endl;
        cout << "5. Insert at begin" << endl;
        cout << "6. Delete at begin" << endl;
        cout << "7. Count" << endl;
        cout << "8. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            push(&head, 3);
            push(&head, 1);
            push(&head, 2);
            push(&head, 1);

            cout << "Created Linked List" << endl;
            break;

        case 2:
            display(&head);
            break;

        case 3:
            back_push(&head, 1);
            break;

        case 4:
            delete_back(&head);
            break;

        case 5:
            push(&head, 1);
            break;

        case 6:
            delete_front(&head);
            break;

        case 7:
            cout << "count of nodes is " << getCount(head);
            break;

        case 8:
            exit(0);

        default:
            cout << "\nInvalid choice!!!!" << endl;
        }
    }
}