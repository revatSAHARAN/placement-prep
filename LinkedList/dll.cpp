#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getlength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data ;
        temp =  temp->next ;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head  = node1;
    Node* tail = node1;

    cout<<getlength(head)<<endl;
    print(head);
}