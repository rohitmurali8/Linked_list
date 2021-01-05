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

Node* partition(Node* n, int elem){
    Node* left = new Node();
    Node* left_temp = left;
    Node* right = new Node();
    Node* right_temp = right;

    while (n != NULL){
        if(n->data >= elem){
            right_temp->next = new Node();
            right_temp->next->data = n->data;
            right_temp = right_temp->next;
        }
        if(n->data < elem){
            left_temp->next = new Node();
            left_temp->next->data = n->data;
            left_temp = left_temp->next;
        }
        n = n->next;        
    }
    left_temp->next = right->next;
    return left->next;
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

    printList(head);

    Node* part = partition(head, 5);
    cout << "This is the list after partition " << endl;
    printList(part);

    return 0;
}