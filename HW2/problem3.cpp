// Name: Mitchell Baker
// all the code apart from the reverse function and main was given by Dr.Thompson
#include <iostream>

class Node{
    public:
        int data;    //data
        Node* next;     // pointer to next

};

class List{
    public:
        List(){head = NULL;}    // constructor
        Node* insertNode(int index, int val);   // inserts a node at given index and value
        void displayList(); // displays the list
        Node* reverse();    // reverses the list
    private:
        Node* head;     // holds head of the linked list
};

Node* List::insertNode(int index, int val) {
    if(index < 0) return NULL;  // returns if the given index is less than zero

    int currIndex = 1;      // sets current index to be higher than zero
    Node* currNode = head;  // sets a temp node to hold head so it can be iterated through

    // iterates through list until at at given index
    while(currNode && index > currIndex) {
        currNode = currNode->next;
        currIndex++;
    }

    // if the index doesn't exist, returns
    if (index > 0 && currNode == NULL) return NULL;

    // creates new node
    Node* newNode = new Node;
    newNode->data = val;

    // insert as first element
    // else it inserts after the current node
    if(index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return newNode;
};

void List::displayList(){

    Node* currNode = head;
    while (currNode != NULL) {
        std::cout << currNode->data << std::endl;
        currNode = currNode->next;  
    }
}; 

// takes no paramaters and returns the head of the list
Node* List::reverse() {
    
    Node* currNode = head;      // used to iterate through the list
    Node* prevNode = NULL;      // used to store the node to be have its next switched
    Node* prevPrevNode = NULL;  // used to store the node that prevNode with switch too

    // iterates through the list, stores the previous two nodes then assigns the
    // previous node's pointer to the one before it.
    // prevNode is always one behind currNode (to avoid having a NULL point to a node)
    // and will then point to prevPrevNode.
    while(currNode != NULL){
        prevPrevNode = prevNode;
        prevNode = currNode;
        currNode = currNode->next;
        prevNode->next = prevPrevNode;
    }

    // now assigns head to be prevNode, which is now the old end of the list
    head = prevNode;

    // returns the list fully reversed
    return head;
}

int main(){

    List myLinkedList;

    for(int i = 0; i <= 10; i++) {
        myLinkedList.insertNode(i,i);
    }

    myLinkedList.displayList();

    std::cout << "now reversing the list" << std::endl;

    myLinkedList.reverse();

    myLinkedList.displayList();
    
    return 0;
}