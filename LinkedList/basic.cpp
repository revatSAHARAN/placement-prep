#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this->data;
    // Memory Free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data"<< value << endl;
    }

};

void deleteNode(int position, Node* &head){

    if(position == 1){
        Node* temp = head;
        head = head->next;

        temp->next == NULL;
        delete temp;
    }
    else{
        Node* cur = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt < position){
            prev= cur;
            cur=cur->next;
            cnt++;
        }

        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }

}

void insertAtHead(Node* &head, int d) {

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
    
}

void insertInMid(Node* &tail, Node* &head, int data, int pos){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = new Node(data);
    Node* cur = head;
    for(int i=0;i<pos-2;i++){
        cur = cur->next;
    }
    if(cur->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    temp->next = cur->next;
    cur->next = temp;
}

void print (Node* &head){
    Node* cur = head;
    while(cur != NULL){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 15);
    insertAtHead(head, 20);
    insertAtHead(head, 25);

    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertInMid(tail, head,17,3);

    insertInMid(tail, head, 99, 1);
    print(head);
    // deleteNode(3,head);
    print(head);
    // cout<< node1->data <<endl;
    // cout<< node1->next <<endl;    
}