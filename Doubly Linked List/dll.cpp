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
    void appendNode(Node *n){
        if(checkIfNodeExists(n->key) == nullptr){
            if(!(head == nullptr)){ // If our list is not empty
                Node *temp;

                temp = head;

                while(temp != nullptr){ // Getting to the last node
                    temp = temp->next;
                }
                temp->next = n; // The pointer "next" of the last node is now pointing to node n
                n->previous = temp; // The pointer "previous" of the last node is now pointing to the one that
                                    // used to be the last
            }else{ // If the list is empty
                head = n;
            }
            cout << "Node of key " << n->key << " has been appended." << endl;
        }else{ // If there already is a node with key of the node we wanted to add
            cout << "Node with key " << n->key << " already exists in the list." << endl;
        }
    }

    // 3. Prepend a node
    void prepend(Node *n){
        if(checkIfNodeExists(n->key) == nullptr){
            if(head != nullptr){
                head->previous = n;
                n->next = head;
                head = n;
            }else{
                head = n;
            }
            cout << "Node of key " << n->key << " has been prepended." << endl;
        }else{
            cout << "Node with key " << n->key << " already exists in the list." << endl;
        }
    }

    // 4. Insert a node after
    void insertNodeAfter(int k, Node *n){
        Node *ptr;

        ptr = checkIfNodeExists(k);

        if(ptr != nullptr){ // If the node we want to insert after exists in the list
            if(checkIfNodeExists(n->key) == nullptr){ // If there is no node with the key of the node we want to insert
                 Node *next_ptr;

                 next_ptr = ptr->next; // Pointer next_ptr is gonna store the address of the node that comes next to the
                                       // node we want to insert a node after

                 if(next_ptr->next != null){ // If the node we want to insert a node after is in between nodes
                    next_ptr->previous = n;
                    n->next = next_ptr;
                    ptr->next = n;
                    n->previous = ptr;
                 }else{ // If the node we want to insert a node after is at the end of the list
                    n->previous = ptr;
                    ptr->next = n;
                 }
                 cout << "Node has been inserted after node of key " << k << "." << endl;
            }else{
                cout << "There already is a node with key " << n->key << " in the list." << endl;
            }
        }else{
            cout << "There is no node with key " << k << " to insert a node after." << endl;
        }
    }

    // 5. Delete node by key
    void deleteByKey(int k){
        if(head != nullptr){ // If the list is no empty, we proceed with the deletion
            Node *ptr;

            ptr = checkIfNodeExists(k);

            if(ptr != nullptr){ // If there is a node with the key k
                if(ptr != head){
                    Node *next_ptr;
                    Node *prev_ptr;

                    next_ptr = ptr->next;
                    prev_ptr = ptr->previous;

                    if(next_ptr->next != nullptr){ // If the node is in between two other nodes
                        prev_ptr->next = next_ptr;
                        next_ptr->prev = prev_ptr;
                    }else{ // If the node we want to delete is at the end of the list
                        prev_ptr->next = nullptr;
                    }
                }else{ // If the node we want to delete happens to be the head
                    head = ptr->next;
                }
            }else{
                cout << "There is no node with key " << k << "." << endl;
            }
        }else{
            cout << "The list is empty!" << endl;
        }
    }
};

int main(){

    return 0;
}
