//#################################
//# LinkedList
//#################################
//# - head: Node*
//#################################
//# + push_front(data:int)
//# + push_back(data:int)
//# + get(index: size_t):int
//# + length(): size_t

//# + remove(index: size_t):T
//# + insert(index: size_t):data T  // not sure
//# + clear(): 
//# + ~linkedList()
//#################################
#pragma once
#include "node.h"
#include "exceptions.h"

namespace Linked_List{
template <typename T>
class linkedList {
    private:
        Node<T> * head = nullptr;

    public:
        linkedList() {

        }

        void push_front(T data) {
            Node<T> * node = new Node(data);

            node->Next(head);
            head = node;
        }

        void push_back(T data) {
            Node<T> * tempNode = new Node(data);
            Node<T> * tailNode = tail();

            if (tailNode) {
                tailNode->Next(tempNode);
            } else {
                push_front(data);
            }
        }
        Node<T> * getNode(size_t index) const {
            // check for valid index
            if (index >= length()) {
                throw Exception::IndexOutOfBoundException();
            }

            Node<T> * temp = head;

            for(size_t i = 0; i < index; i++) {
                temp = temp->Next();
            }

            return temp;
        }

        T get(size_t index) const {
            Node<T> * node = getNode(index);
            if (!node) {
                throw Exception::NullPointerException();
            }
            return node->data();
        }

        Node<T> * tail() const {
            if (length() == 0) {
                return nullptr;
            }
            return getNode(length() - 1);
        }

        size_t length(void) const {
            Node<T>* temp = head;
            size_t count = 0;

            while(temp) {
                temp = temp->Next();
                count++;
            }
            return count;
        }

        T remove(size_t index) {
            T data = get(index);
            Node<T> *tempNode = nullptr;
            if (index == 0) {
                tempNode = head;
                head = head->Next();
                delete tempNode;
                return data;
            }
            tempNode = getNode(index);
            Node<T> * prevNode = getNode(index - 1);
            prevNode->Next(tempNode->Next());
            delete tempNode;
            return data;
        }

        void insert(size_t index, T data) {
            getNode(index);
            if (index == 0) {
                push_front(data);
            } else {
                Node<T>* tempNode = new Node(data);
                Node<T>* prevNode = getNode(index - 1);
                tempNode->Next(prevNode->Next());
                prevNode->Next(tempNode);
            }
        }

        void clear(){
            while(head){
                remove(0);
            }
        } 
        ~linkedList(){
            clear();
        }
    }; 
}