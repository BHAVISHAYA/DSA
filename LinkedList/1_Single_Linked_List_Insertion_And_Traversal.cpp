#include<bits/stdc++.h>
using namespace std;

//* Create a Node class 
class Node {
  public:
    int data; 
    Node* next; 

    Node(int data, Node* next) {
      this -> data = data; 
      this -> next = next; 
    }

    Node(int data) {
      this -> data = data;
      this -> next = NULL;
    }
};

//* 1. Function to print linked list 
void printList(Node* &head) {
  Node* temp = head; 
  while(temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next; 
  }
  cout << "\n";
}

//* 2. Function to insert a node at the head 
Node* insertAtHead(Node* &head, int data) {
  if(head == NULL) {
    return new Node(data);
  }

  Node* nodeToInsert = new Node(data);
  nodeToInsert -> next = head; 
  head = nodeToInsert;

  return head; 
}

//* 3. Function to insert a node at the tail 
Node* insertAtTail(Node* &head, int data) {
  if(head == NULL) {
    return new Node(data);
  }

  Node* nodeToInsert = new Node(data);
  Node* temp = head; 
  while(temp -> next != NULL) {
    temp = temp -> next;
  }

  temp -> next = nodeToInsert;
  return head;
}

//* 4. Function to insert node at Kth position 
// Node* insertAtKthPos(Node* &head, int data, int k) {

// }

int main() {
  Node* head = new Node(1);
  head = insertAtHead(head, 0);
  head = insertAtTail(head, 2);
  head = insertAtTail(head, 3);
  head = insertAtTail(head, 4);
  head = insertAtHead(head, -1);
  head = insertAtHead(head, -2);
  printList(head);

}