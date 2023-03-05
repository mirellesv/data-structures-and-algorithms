#include <iostream>

using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d){
        key = k;
        data = d;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList(){
    public:
        Node* head;

    DoublyLinkedList(){
        head = NULL;
    }

    DoublyLinkedList(Node *new_node){
        head = new_node;
    }

    // 1. Operation that checks if a node with key k
    // already exists in the list. If so, it returns its
    // address. If not, it returns NULL.
    Node* checkIfNodeExists(int k){
        Node* temp = NULL; // temp is gonna store the address of the node with
                           // key k, if exists. If not, it will just be NULL.
        Node* aux = head; // aux is gonna be in charge of storing the address
                          // of the node that is being examined

        while(aux != NULL){
            if(aux->key == k){
                temp = aux;
            }
            aux = aux->next; // aux needs to be updated as it goes through the list
        }

        return temp;
    }

    // 2. Append a node to the list
    void append(Node *new_node){
        Node* temp;

        temp = checkIfNodeExists(new_node->key);

        if(temp != NULL){

        } else{
            cout << "Node with key " << new_node->key << " already exists!" << endl;
        }
    }
};

int main(){

    return 0;
}
