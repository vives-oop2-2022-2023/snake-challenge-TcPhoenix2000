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
            bool _selected = false;  // Add a new field to store the selection status
        public:
            Node(T data) {
                this->data(data);
            }
        public:
            Node* Next() {
                return _next;
            }
            void Next(Node* node) {
                _next = node;
            }
            void data(T data) {
                _data = data;
            }
            T data(void) {
                return _data;
            }
            bool selected() const {  // Add a new method to get the selection status
                return _selected;
            }
            void selected(bool value) {  // Add a new method to set the selection status
                _selected = value;
            }
    };
}
