///////////////////////////////
//
// Abdel-Hakeem Badran
// 01/24/2018
// File: node.hpp
//
///////////////////////////////
//
// Node class base thanks to:
// Mikhail Nesterenko
//
///////////////////////////////

#ifndef CUSTOM_NODE_
#define CUSTOM_NODE_

template <typename T>
class Node {
public:

    Node() : next_(nullptr) { }
    
    T           getData()                     const     { return data_; }
    Node<T> *   getNext()                     const     { return next_; }
    
    void        setData(const T & data)                 { data_ = data; }
    void        setNext(Node<T> * const next)           { next_ = next; }

private:

    T data_;
    Node<T> * next_;
    
};

#endif