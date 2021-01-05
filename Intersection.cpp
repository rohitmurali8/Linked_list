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

Node* sub_list(Node* n, int k){
    if (k == 1)
    {
        n = n->next;
    }
    else
    {
        while (k - 1 > 0){
            n = n->next;
            k = k - 1;
        }
    }
    return n;
}

int list_count(Node* n){
    int count = 0;
    while (n != NULL)
    {
        count = count + 1;
        n = n->next;
    }
    
    return count;
}

int list_intersect(Node* n1, Node* n2){
    int intersect;
    if(list_count(n1) > list_count(n2)){
        Node* temp2 = sub_list(n1, list_count(n1) - list_count(n2));
        while(temp2 != NULL || n2 != NULL){
            if(temp2 == n2 && temp2->data == n2->data){
                intersect = n2->data;
                break;
            }
            n2 = n2->next;
            temp2 = temp2->next;
        }
    }

    if(list_count(n2) > list_count(n1)){
        Node* temp2 = sub_list(n2, list_count(n2) - list_count(n1));
        while(n1 != NULL || temp2 != NULL){
            if(n1 == temp2 && n1->data == temp2->data){
                intersect = temp2->data;
                break;
            }
            temp2 = temp2->next;
            n1 = n1->next;
        }
    }
    return intersect;
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
    fifth->next = NULL;
    fifth->visit = 0;

    sixth->data = 8;
    sixth->next = seventh;
    sixth->visit = 0;

    seventh->data = 1;
    seventh->next = fourth;
    seventh->visit = 0;

    printList(head);

    cout << "The intersection of the 2 lists is " << list_intersect(head, sixth) << endl;

    return 0;
}