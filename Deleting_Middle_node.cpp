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

Node* delete_element(Node* n, int pos){
    Node* prev = new Node();
    Node* temp = n;

    if (pos == 1){
        n = n->next;
    }
    else
    {
        while(pos - 1 > 0){
            prev = n;
            n = n->next;
            pos = pos - 1;
        }
    }
    prev->next = n->next;
    return n;
}

void del_middle(Node* n){
    float count = list_count(n);
    float middle;
    middle = ceil(count/2);
    delete_element(n, static_cast<int>(middle));
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

    del_middle(head);
    cout << "List after deleting middle element is " << endl;
    printList(head);

    return 0;
}