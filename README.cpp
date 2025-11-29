# ds-practical

// single-linked-list 

#include<iostream>
using namespace  std;

struct Node{
    int data;
    struct Node* next;
  
};

// traversal
void printlist(struct Node* ptr){
    while(ptr!=NULL){
        cout<< ptr->data << endl;
        ptr=ptr->next;
    }
}

//insertion at the front
struct Node* insertAtFront(struct Node* &head, int x){
    Node* newnode = new Node();
    newnode->data=x;
    newnode->next = head;
    head = newnode;
    return head;
}

//insertion at the end
struct Node* insertAtEnd(struct Node* &head, int x){
    Node* newnode = new Node();
    newnode->data=x;
    newnode->next = NULL;
    
    // Case 1: empty list
    if (head == NULL) {
        head = newnode;
        return head;
    }
    // Case 2: non‑empty list
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
// insert after given node
void insertaftergiven(struct Node* prev,int x){
    if(prev==NULL){
        cout<< "previous is null"<<endl;
        return;
    }
    Node* newnode = new Node();
    newnode->data=x;

    newnode->next= prev->next;
    prev->next= newnode;
}

// insert at specific position
struct Node* insertAtSpecific(struct Node* &head, int x, int key){
    Node* newnode = new Node();
    newnode->data=x;
    newnode->next = NULL;
    
    // Case 1: empty list
    if (head == NULL) {
        head = newnode;
        return head;
    }
    // Case 2: non‑empty list
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    newnode->next= temp->next;
    temp->next= newnode;
    return head;
    
}

void pop_front(struct Node* &head) {
    if (head == NULL) {
        cout << "linkedlist is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void pop_back(struct Node* &head) {
    if (head == NULL) {
        cout << "linkedlist is empty" << endl;
        return;
    }
    if (head->next == NULL) {          // only one node
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) { // stop at second-last
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void popatspecificpos(struct Node* &head ,int pos) {
    if (head == NULL) {
        cout << "list is empty" << endl;
        return;
    }
    if (pos == 1) {                    // delete head
        pop_front(head);
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != NULL && i < pos - 2; i++) {
        temp = temp->next;
    }

    // position out of range or no node to delete
    if (temp == NULL || temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

Node* reverseLL(struct Node* &head) {
    if (head == NULL) {
        cout << "cant be reverse.." << endl;
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

    
int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data=6;
    head->next =second;

    second->data=13;
    second->next=third;
    
    third->data=23;
    third->next=NULL;
    
    printlist(head);
   
    insertAtFront(head ,4);
    cout<< "node is inserted"<< endl;
    printlist(head);
    
    insertAtEnd(head ,45);
    printlist(head);
    insertAtSpecific(head,20,13);
    cout<<endl;
    printlist(head);
    
    insertaftergiven(second,11);
    printlist(head);
    
    pop_front(head);
    pop_back(head);
    popatspecificpos(head ,3);
    reverseLL(head);
    printlist(head);
    return 0;

}
