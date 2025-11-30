# programs 

// 1 single LL
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

Node* traverse(int n) {
    if (n <= 0) return nullptr;
    
    Node* temp = head;
    for (int i = 1; i < n && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}

void insertInBetween(int value, int i) {
    if (i <= 0) {
        cout << "Invalid input" << endl;
        return;
    }
    
    if (i == 1) {
        insertAtHead(value);
        return;
    }
    
    Node* temp = traverse(i - 1);
    if (temp == nullptr) {
        cout << "Position out of bound" << endl;
        return;
    }
    
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteHead() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteInBetween(int i) {
    if (i <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    
    if (i == 1) {
        deleteHead();
        return;
    }
    
    Node* prev = traverse(i - 1);
    if (prev == nullptr || prev->next == nullptr) {
        cout << "Position " << i << " does not exist" << endl;
        return;
    }
    
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void defaultList() {
    head = nullptr;
    insertAtHead(5);
    insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);
    
    cout << "Default Singly linked list: " << endl;
    display();
}

Node* search(int n) {
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data == n) {
            cout << "Pointer Of '" << n << "' is " << temp << endl;
            return temp;
        }
        temp = temp->next;
    }
    
    cout << "No Match Found" << endl;
    return nullptr;
}

void reverse() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    cout << "List reversed successfully" << endl;
}

void choice() {
    int n;
    cout << "\nChoose one of the Following Options" << endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at ith position" << endl;
    cout << "3. Delete at Head" << endl;
    cout << "4. Delete at ith position" << endl;
    cout << "5. Search for an element" << endl;
    cout << "6. Reverse the Linked List" << endl;
    cin >> n;
    
    if (n == 1) {
        int x;
        cout << "Enter the element to insert at Head: ";
        cin >> x;
        insertAtHead(x);
    }
    else if (n == 2) {
        int x, i;
        cout << "Enter the element to insert: ";
        cin >> x;
        cout << "Enter the Position: ";
        cin >> i;
        insertInBetween(x, i);
    }
    else if (n == 3) {
        deleteHead();
        cout << "Element at head deleted" << endl;
    }
    else if (n == 4) {
        int i;
        cout << "Enter the Position to delete: ";
        cin >> i;
        deleteInBetween(i);
    }
    else if (n == 5) {
        int x;
        cout << "Enter the element to search: ";
        cin >> x;
        search(x);
    }
    else if (n == 6) {
        reverse();
    }
    else {
        cout << "Invalid Option" << endl;
    }
}

int main() {
    cout << "**********************************************************************************" << endl;
    defaultList();
    cout << "**********************************************************************************" << endl;
    
    choice();
    
    cout << "Singly linked list: ";
    display();
    cout << endl;
    
    return 0;
}

//2 Doublly LL
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

Node* traverse(int n) {
    Node* temp = head;
    for (int i = 1; i < n && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}

void insertInBetween(int value, int i) {
    Node* temp = traverse(i-1);
    if (i <= 0) {
        cout << "Invalid Position" << endl;
    } else if (temp == nullptr) {
        cout << "Position out of bound" << endl;
    } else if (i == 1) {
        insertAtHead(value);
    } else {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void deleteHead() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteEnd() {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void deleteInBetween(int i) {
    if (i < 1) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (i == 1) {
        deleteHead();
        return;
    }
    Node* temp = traverse(i-1);
    Node* temp2 = traverse(i);
    if (temp == nullptr || temp2 == nullptr) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (temp2->next == nullptr) {
        temp->next = nullptr;
    } else {
        temp->next = temp2->next;
        temp2->next->prev = temp;
    }
    delete temp2;
}

Node* search(int n){
  Node* temp = head;

  while( temp != nullptr){
    if(temp->data == n){
      cout << "Pointer Of '" << n << "' is " << temp <<endl;
      return temp;
    }
    else{
    temp = temp->next;
    }
  }
}

void reverse(){
  Node *temp = nullptr;
  Node* current = head;

  while(current != nullptr){
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if(temp !=nullptr){
    head = temp->prev;
  }
}

void defaultList(){
  head = NULL;
  insertAtHead(5);
  insertAtHead(4);
  insertAtHead(3);
  insertAtHead(2);
  insertAtHead(1);
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void choice(){
  int n;
    cout<< "Chose on of the Following Option" << endl;
    cout<< "1. Insert at Head" << endl;
    cout<< "2. Insert at ith position" <<endl;
    cout<< "3. Delete at Head" << endl;
    cout<< "4. Delete at ith position" <<endl;
    cout<< "5. Search for an element x in the singly linked list and return its pointer" << endl;
    cout<< "6. Reverse the Linked List" <<endl;
    cin>> n;

    if (n == 1){
      int x;
      cout << "Enter the element you want to insert at Head"<< endl;
      cin >> x;
      insertAtHead(x);
    }
    if (n == 2){
      int x, i;
      cout << "Enter the element you want to insert"<< endl;
      cin >> x;
      cout << "Enter the Position"<< endl;
      cin >> i;
      insertInBetween(x,i);
    }
    if (n == 3){
      deleteHead();
      cout << "Element at head deleted"<< endl;
    }
    if (n == 4){
      int i;
      cout << "Enter the Position you want to delete"<< endl;
      cin >> i;

      deleteInBetween(i);
    }
    if (n == 5){
      int x;
      cout << "Enter the element you want to search"<< endl;
      cin >> x;

      search(x);

    }

    if (n == 6){
      reverse();
    }

    else if(n>6 || n<1){
      cout << "Invalid Option" << endl;
    }
}


int main(){
  cout << "**********************************************************************************" << endl;
  defaultList();
  cout << "**********************************************************************************" << endl;

  choice();
  cout<< "Doubly linked list:  ";
  display();
  cout << endl;

  return 0;
}

// 3 circular LL
#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int value){
      data = value;
      next = nullptr;
    }
};

class CircularLinkedList{
  public:
    Node* head;

    CircularLinkedList(){
      head = nullptr;
    }

    void insertAtHead(int value){
      Node* newNode = new Node(value);
      if(head == nullptr){
        head = newNode;
        newNode->next = head;
      }
      else{
        Node* temp = head;
        while(temp->next != head){
          temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
      head = newNode;
    }
    }

    Node* traverse(int pos){
      Node* temp = head;
  
      for(int i = 1 ; i < pos && temp != nullptr && temp->next != head; i++){
        temp = temp->next;
      }
      return temp;
    }

    void insertInBetween(int v, int p){
      if(p == 0  ){
        cout<< "Invalid Position. Try 1 or greater!" <<endl;
        return;
      }

      if(p==1){
        insertAtHead(v);
        return;
      }

      Node* temp = traverse(p-1);

      Node *newNode = new Node(v);
      newNode->data = v;
      newNode->next = temp->next;
      temp->next = newNode;
    }

    void deleteAtHead(){
      if(head == nullptr){
        cout << "List is empty" << endl;
        return;
      }
      if(head->next == head){
        delete head;
        head = nullptr;
        return;
      }
      Node* temp = head;
      Node* last = head;
      while(last->next != head){
        last = last->next;
      }

      head = head->next;
      last->next = head;
      delete temp;

    }

    void deleteAtPos(int p){
      if(p <= 0){
        cout << "Invalid Position. Try 1 or greater!" << endl;
        return;
      }

      if(p == 1){
        deleteAtHead();
        return;
      }

      Node* prev = head; 
      Node* curr = head->next;

      for (int i = 2; i < p; i++) { 
        prev = curr; 
        curr = curr->next; 
        if (curr == head) { 
          cout << "Invalid Position. Try a smaller number" << endl; 
          return; 
        } 
      }

      if (curr == nullptr || curr == head) { 
        cout << "Invalid Position. Try a smaller number" << endl; 
        return; 
        } 
        prev->next = curr->next; 
        delete curr;

    }

    void display(){
      if(head == nullptr){
        cout << "List is empty" << endl;
        return;
      }
      Node *temp = head;
      do{
        cout << temp->data << " -> ";
        temp = temp->next;
      }while(temp != head);
      cout << "(head)" <<endl;
    }

    Node* search(int n){
      if(head == nullptr){
        cout << "List is empty" << endl;
        return nullptr;
      }

      Node* temp = head;
      do{
        if (temp -> data == n){
          cout << "Pointer of "<< n << " is: " << temp << endl;
          return temp;
        }
        temp = temp->next;
      } while (temp != head);

      cout << "No match found" << endl;
      return nullptr;
}

    void reverse(){
      if(head == nullptr || head->next == nullptr){
        return;
      }

      Node* prev = nullptr;
      Node *current = head;
      Node *next = nullptr;
      Node* last = head;

      while(last->next != head){
        last = last->next;
      }

      do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      } while (current != head);

      head->next = prev;
      head = prev;
    }

    void defaultList(){
      insertAtHead(5);
      insertAtHead(4);
      insertAtHead(3);
      insertAtHead(2);
      insertAtHead(1);

      cout<<"Default Circular List: ";
      display();
    }

    void choice(){
      int n;
      cout<< "Chose on of the Following Option" << endl;
      cout<< "1. Insert at Head" << endl;
      cout<< "2. Insert at ith position" <<endl;
      cout<< "3. Delete at Head" << endl;
      cout<< "4. Delete at ith position" <<endl;
      cout<< "5. Search for an element x in the singly linked list and return its pointer" << endl;
      cout<< "6. Reverse the Linked List" <<endl;
      cin>> n;

      if (n == 1){
        int x;
        cout << "Enter the element you want to insert at Head"<< endl;
        cin >> x;
        insertAtHead(x);
      }
      if (n == 2){
        int x, i;
        cout << "Enter the element you want to insert"<< endl;
        cin >> x;
        cout << "Enter the Position"<< endl;
        cin >> i;
        insertInBetween(x,i);
      }
      if (n == 3){
        deleteAtHead();
        cout << "Element at head deleted"<< endl;
      }
      if (n == 4){
        int i;
        cout << "Enter the Position you want to delete"<< endl;
        cin >> i;

        deleteAtPos(i);
      }
      if (n == 5){
        int x;
        cout << "Enter the element you want to search"<< endl;
        cin >> x;

        search(x);

      }

      if (n == 6){
        reverse();
      }

      else if(n>6 || n<1){
        cout << "Invalid Option" << endl;
      }
    }
};

int main(){
  CircularLinkedList list;
  cout << "**********************************************************************************" << endl;
  list.defaultList();
  cout << "**********************************************************************************" << endl;
  
  list.choice();

  cout<< "Circular linked list:  ";
  list.display();
  cout << endl;
  return 0;
}

//4 stack 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
public:
    Node* head = nullptr;

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return head->data;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int evaluatePostfix(const string& expression) {
    Stack stack;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}

int evaluatePrefix(const string& expression) {
    Stack stack;
    istringstream iss(expression);
    vector<string> tokens;
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
    reverse(tokens.begin(), tokens.end());

    for (const auto& tok : tokens) {
        if (isdigit(tok[0])) {
            stack.push(stoi(tok));
        } else {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();

            switch (tok[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}

int main() {
    string postfix = "5 6 + 4 *";
    string prefix = "* + 5 6 4";

    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}

// 5 Queue 

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void Enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void Dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void Front() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    void Display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Display();

    queue.Dequeue();
    queue.Display();

    queue.Front();

    return 0;
}

// 6 BST 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;

    bst.deleteNode(20);
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    return 0;
}

// 7 AVL 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1; 
    }
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int value) {
        if (!node) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return search(node->left, value);
        }
        
        return search(node->right, value);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void inorderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void display() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "Inorder traversal of the constructed AVL tree is: ";
    avl.display();

    cout << "Searching for 30: " << (avl.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 60: " << (avl.search(60) ? "Found" : "Not Found") << endl;

    return 0;
}


