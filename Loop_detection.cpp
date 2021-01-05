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

void check_loop(Node* n){
    while(n != NULL){
        n->visit = 1;
        n = n->next;
        if (n->next->visit == 1){
            cout << "Loop starts at element " << n->next->data << endl;
            break;
        }
    }
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
    head->visit = 0;

    second->data = 4;
    second->next = third;
    second->visit = 0;

    third->data = 8;
    third->next = fourth;
    third->visit = 0;

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
    seventh->next = fifth;
    seventh->visit = 0;

    check_loop(head);

    return 0;
}