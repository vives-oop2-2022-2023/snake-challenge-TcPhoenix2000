//#################################
//# Node
//#################################
//# - _next: Node*
//# - _data: int
//#################################
//# + Node(data: int)
//# + Next():Node*
//# + Next(node: Node*)
//# + data():int
//# + data(data: int)
//#################################
#pragma once 
namespace Linked_List{
    template <typename T>
    class Node{
        
        private:
            Node * _next = nullptr;
            T _data;
        public:
            Node(T data){
                this->data(data);
            }
        public:
            Node* Next(){
                return _next;
            }
            void Next(Node* node){
                _next = node;
            }
            void data(T data){
                _data = data;
            }
            int data(void){
                return _data;
            }
    };
}
