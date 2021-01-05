#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <typeinfo>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    int visit;
};

void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node* del_duplicate(Node* n){
    Node* temp = n;
    while (temp != NULL)
    {
        Node* current = temp;
        while (current->next != NULL)
        {
            if (current->next->data == temp->data)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        temp = temp->next;
    }
    return n;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;
    Node* seventh = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();
    seventh = new Node();

    head->data = 3;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;
    fourth->visit = 0;

    fifth->data = 10;
    fifth->next = sixth;
    fifth->visit = 0;

    sixth->data = 8;
    sixth->next = seventh;
    sixth->visit = 0;

    seventh->data = 1;
    seventh->next = NULL;
    seventh->visit = 0;

    Node* rev1 = del_duplicate(head);
    cout << "The list after deleting duplicates is " << endl;
    printList(rev1);

    return 0;
}