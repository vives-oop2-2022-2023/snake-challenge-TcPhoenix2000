#pragma once

//#include <exception>
#include <stdexcept>
#include <string>


namespace Linked_List::Exception{
    class IndexOutOfBoundException: public std::runtime_error{
    private:
        /* data */
    public:
        IndexOutOfBoundException(std::string message="index was out of bound")
        :runtime_error(message){
            
        }
        
    };
};