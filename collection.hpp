///////////////////////////////
//
// Abdel-Hakeem Badran
// 01/24/2018
// File: collection.hpp
//
///////////////////////////////

#ifndef CUSTOM_COLLECTION_
#define CUSTOM_COLLECTION_

#include "node.hpp"
#include <iostream>

template <typename T>
class Collection {
public:

    Collection() : size_(0), head_(nullptr), tail_(nullptr) { }
    Collection(const Collection<T> &);
    ~Collection();

    Collection&              operator=(Collection<T>);
    
    void                     addItem(const T &);
    void                     removeItem(const T &);
    
    T                        lastItem();
    void                     printCollection();
    
    void                     swap(Collection<T> &);
    
    template        <typename U>
    friend bool     equal(const Collection<U> &, const Collection<U> &);
    
private:

    Node<T> * head_;
    Node<T> * tail_;
    
    int size_;
    
};

template <typename T>
Collection<T>::Collection(const Collection<T> & rhs) : size_(0), head_(nullptr), tail_(nullptr) {
    
    if ( rhs.size_ == 0 ) return;
    
    Node<T> * pRHSIterator = rhs.head_, * pLHSIterator = nullptr;
    
    head_ = new Node<T>;
    head_->setData( pRHSIterator->getData() );    
    
    pLHSIterator = head_;
    pRHSIterator = pRHSIterator->getNext();
    
    while ( pRHSIterator != nullptr ) {
        
        pLHSIterator->setNext( new Node<T> );
        pLHSIterator = pLHSIterator->getNext();
        pLHSIterator->setData( pRHSIterator->getData() );
        
        pRHSIterator = pRHSIterator->getNext();
        
    }
    
    tail_ = pLHSIterator;
    size_ = rhs.size_;
    
}

template <typename T>
Collection<T>::~Collection() {
    
    Node<T> * pCurrentPos = head_, * pPreviousPos = nullptr;
    while ( pCurrentPos != nullptr ) {
        
        pPreviousPos = pCurrentPos;
        pCurrentPos = pCurrentPos->getNext();
        
        delete pPreviousPos;
        
    }
    
}

template <typename T>
void Collection<T>::swap(Collection<T> & rhs) {
    
    int temp_size = size_;
    Node<T> * temp_head = head_;
    Node<T> * temp_tail = tail_;
    
    size_ = rhs.size_;
    head_ = rhs.head_;
    tail_ = rhs.tail_;
    
    rhs.size_ = temp_size;
    rhs.head_ = temp_head;
    rhs.tail_ = temp_tail;
    
}

template <typename T>
Collection<T>& Collection<T>::operator=(Collection<T> rhs) {
    
    swap(rhs);
    return *this;
    
}


template <typename T>
void Collection<T>::addItem(const T & item) {
    
    ++ size_;
    
    if ( head_ == nullptr ) {
        
        head_ = new Node<T>;
        head_->setData(item);
        
        tail_ = head_;
        
    } else {
        
        Node<T> * newNode = new Node<T>;
        newNode->setData(item);
        
        tail_->setNext(newNode);
        tail_ = newNode;
        
    }
    
}

template <typename T>
void Collection<T>::removeItem(const T & item) {
    
    if ( size_ == 0 ) return;
    Node<T> * currentNode = head_, * previousNode = nullptr, * futureNode = nullptr;
    
    while ( currentNode != nullptr ) {

        if ( currentNode == head_ && head_->getData() == item ) {
            
            futureNode = head_->getNext();
            
            delete head_;
            -- size_;
            
            head_ = futureNode;
            currentNode = head_;
            
        } else if ( currentNode->getData() == item ) {
            
            futureNode = currentNode->getNext();
            previousNode->setNext(futureNode);
                
            // Special case for the tail.
            if ( futureNode == nullptr ) {
                tail_ = previousNode;
            }
                
            delete currentNode;
            -- size_;
            
            currentNode = futureNode;
            
        } else {
            
            previousNode = currentNode;
            currentNode = currentNode->getNext();
            
        }
    
    }

}

template <typename T>
T Collection<T>::lastItem() {
    return tail_->getData();
}

template <typename U> // Friend functions need new template identifier
bool equal(const Collection<U> & lhs, const Collection<U> & rhs) {
    
    if ( lhs.size_ != rhs.size_ ) return false;
    
    Node<U> * lhsIterator = lhs.head_;
    Node<U> * rhsIterator = rhs.head_;
    
    while ( lhsIterator != nullptr && rhsIterator != nullptr ) {
        
        if ( lhsIterator->getData() != rhsIterator->getData() ) {
            
            return false;
            
        } else {
            
            lhsIterator = lhsIterator->getNext();
            rhsIterator = rhsIterator->getNext();
            
        }
        
    }
    
    return true;
}

template <typename T>
void Collection<T>::printCollection() {

    Node<T> * currentNode = head_;
    while ( currentNode != nullptr ) {
        
        std::cout << currentNode->getData() << "\n";
        currentNode = currentNode->getNext();
        
    }

}

#endif