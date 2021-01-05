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
    third->next = NULL;

    fourth->data = 4;
    fourth->next = fifth;
    fourth->visit = 0;

    fifth->data = 10;
    fifth->next = sixth;
    fifth->visit = 0;

    sixth->data = 8;
    sixth->next = NULL;
    sixth->visit = 0;

    int sum, carry = 0;
    Node* add = NULL;
    add = new Node();
    Node* temp = add;
    while(head != NULL || fourth != NULL){
        sum = head->data + fourth->data + carry;
        head = head->next;
        fourth = fourth->next;
        if(sum >= 10){
            carry = sum/10;
            sum = sum % 10;
        }
        else
        {
            carry = 0;
        }
        
        temp->next = new Node();        
        temp->data = sum;
        temp = temp->next;
    }

    printList(add);

    return 0;
}