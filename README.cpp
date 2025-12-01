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

// double-lined-list 
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
};


class DoublyLL{
public:
    Node*head;

    DoublyLL(){
        head = NULL;
    }

    Node* push_front(int val){
        Node* newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head = newnode;
            
        }
        else{
            newnode->next = head;
            head->prev  =newnode;
            head = newnode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"DLL is empty"<<endl;
        }
        Node*temp = head;
        head= head->next;
        if(head !=NULL){
            head->prev =NULL;
        }
        temp->next = NULL;
        delete(temp);
    }
    
    void push_back(int val){
        Node*temp = head;
        Node * newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head  = newnode;
        }
        else{
            
            while(temp->next!=NULL){
                temp = temp->next;
            }
            newnode->prev = temp;
            temp->next = newnode;
            
        }
        
    }

    void pop_back(){
        Node*temp = head;
        if(head==NULL){
            cout<<"DLL is empty";
            return;
        }
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        if(head->next !=NULL){
            Node* temp2 = temp->next;
            temp->next = NULL;
            temp2->prev = NULL;
            delete(temp2);
        }
        
    }

    void printDLL(){
        Node*temp  = head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLL DLL;

    DLL.push_front(1);
    DLL.push_front(2);
    DLL.push_front(3);
    DLL.push_back(4);
    //DLL.pop_front();
    DLL.pop_back();

    DLL.printDLL();
}

// circular-lined-list

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    
};


class CircularLL{
public:
    Node*head;
    Node*  tail;

    CircularLL(){
        head = tail= NULL;
    }

    Node* push_front(int val){
        Node* newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head =tail = newnode;
            
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
        
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"CLL is empty"<<endl;
        }
        Node*temp = head;
        
        if(head ==tail){
            delete(head);
            head = NULL;
            tail=NULL;
           return;
        }
        head= head->next;
        tail->next = head;
        temp->next = NULL;
        delete(temp);
    }
    
    void push_back(int val){
        Node*temp = head;
        Node * newnode = new Node();
        newnode->data = val;
        if(head==NULL){
            head  =tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
        
    }

    void pop_back(){
        Node*temp = tail;
        if(head==NULL){
            cout<<"CLL is empty";
            return;
        }
        if(head==tail){
            delete(head);
            head=tail= NULL;
            return;
        }
        Node*prev = head;
        while(prev->next!=tail){
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete(temp);
    }

    Node* findAtspecificpos(int x){
        Node*temp = head;
        while(temp->data!=x){
            temp= temp->next;
        }
        cout<< temp;
    }

    void printDLL(){
        Node*temp  = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while(temp !=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }

};

int main(){
   CircularLL CLL;

    CLL.push_front(1);
    CLL.push_front(2);
    CLL.push_front(3);
    CLL.push_back(4);
    //CLL.pop_front();
    //CLL.pop_back();
    CLL.printDLL();
     CLL.findAtspecificpos(2);
}

//stack 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack {
private:
    int top;
    int arr[100];

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;    // last valid index in arr[100]
    }

    void push(int x) {
        if (!isFull())
            arr[++top] = x;
        else
            cout << "Stack Overflow\n";
    }

    int pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int peek() {
        return arr[top];
    }
};

// check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// apply operator to two operands
int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;          // assumes b != 0
        case '^': return (int)pow(a, b);
    }
    return 0;
}

// evaluate postfix expression using stack
int evaluatePostfix(string exp) {
    Stack st;

    for (char c : exp) {
        if (c == ' ')
            continue;

        // operand (single digit)
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int b = st.pop();
            int a = st.pop();
            int result = evaluate(a, b, c);
            st.push(result);
        }
    }
    return st.pop();
}

// evaluate prefix expression using stack
int evaluatePrefix(string exp) {
    Stack st;

    for (int i = (int)exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if (c == ' ')
            continue;

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int a = st.pop();
            int b = st.pop();
            int result = evaluate(a, b, c);
            st.push(result);
        }
    }
    return st.pop();
}

int main() {
    string postfix, prefix;

    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);
    cout << "Postfix Evaluation = " << evaluatePostfix(postfix) << endl;

    cout << "\nEnter Prefix Expression: ";
    getline(cin, prefix);
    cout << "Prefix Evaluation = " << evaluatePrefix(prefix) << endl;

    return 0;
}

// queue

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isempty() {
        return head == nullptr;
    }

    void push(int val) {
        Node* newnode = new Node(val);
        if (isempty()) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {   // queue became empty
            tail = nullptr;
        }
    }

    int front() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return head->data;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while (!q.isempty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

// BST 
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:   
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left= right= NULL;
    }

};

Node* insertBST(Node*root , int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insertBST(root->left,val);
    } else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int val:arr){
        root = insertBST(root,val);
    }
    return root;
}

bool Search(Node* root, int key){
    if(root==NULL){
        return false;
    }

    if(root->data ==key){
        return true;
    } else if(root->data>key){
        return Search(root->left,key);
    } else{
        return Search(root->right,key);
    }

    return false;
}

Node * getInorderSuccesor(Node*root){
    while(root !=NULL && root->left !=NULL){
        root =root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root==NULL){
        return NULL;
    }

    if(key<root->data){
        root->left = deleteNode(root->left,key);
    } else if(key>root->data){
        root->right = deleteNode(root->right,key);
    } else {
        if(root->left==NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        } else if(root->right==NULL){
             Node* temp = root->left;
            delete(root);
            return temp;
        } else{
            Node * IS = getInorderSuccesor(root->right);
            root->data = IS->data;
            root->right= deleteNode(root->right,IS->data);
        }
        
    }
    return root;
}

void inOrder(Node*root){
    if(root==NULL){
        return;
    }
     inOrder(root->left);
     cout<<root->data<<" ";
     inOrder(root->right);
    
}

int main(){
    vector<int> arr = { 3,2,1,5,6,4};
    Node* root = buildBST(arr);
    inOrder(root);
    cout<<endl;
    deleteNode(root,7);
    inOrder(root);
    cout<<endl;
    

   cout<< Search(root,7);
}
// AVL 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node*left;
    Node*right;
    int height;

    Node(int val){
        data = val;
        left=right = NULL;
    }
};

int height(Node* N){
    if(N==NULL){
        return 0;
    }
    return N->height;
}

int updateheight(Node* N){
    if(N==NULL){
        return 0;
    }
    return max(N->left->height,N->right->height) + 1;
}

int balanceFactor(Node *N){
    if(N==NULL){
        return 0;
    }
    return (N->left->height - N->right->height) +1;
}

// left--left case
Node* rightrotation(Node* y){
    Node * x = y->left;
    Node*z = x->right;

    //rotate
    x->right = y;
    y->left = z;
    updateheight(y);
    updateheight(x);
    return x;
}
//right-right
Node* leftrotation(Node* x){
    Node * y = x->right;
    Node*z = y->left;

    //rotate
    y->left = x;
    x->right = z;
    updateheight(x);
    updateheight(y);
    return y;
}

Node* insert(Node* node, int val){
    if(node==NULL){
        return new Node(val);
    }

    if(val<node->data){
        node->left = insert(node->left,val);
    } else{
        node->right = insert(node->right,val);
    }
    return node;

    updateheight(node);
    int fd = balanceFactor(node);

    // left -left case
    if(fd>1 && val<node->left->data){
        return rightrotation(node);
    }
    // right-right case
    if(fd<-1 && val>node->right->data){
        return leftrotation(node);
    }
    //left - right case
    if(fd > 1 && val > node->left->data){
        node->left = leftrotation(node);
        return rightrotation(node);
    }
    // right - left case
     if(fd < -1 && val < node->right->data){
        node->right = rightrotation(node);
        return leftrotation(node);
    }

    return node;


}

void inOrder(Node*root){
    if(root!=NULL){
        inOrder(root->left) ;
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    inOrder(root);
}
