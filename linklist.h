#ifndef LINKLIST_H
#define LINKLIST_H

template<typename T>
class Node{
private:
    T data;
    Node<T> * next;
    Node<T> * previous;
public:
    Node();
    Node(const Node<T> & other);
    void setData(T data);
    void setNext(Node<T> * next);
    void setPrevious(Node<T> * previous);
    T & getData();
    Node<T>* getNext();
    Node<T>* getPrevious();
};

//-----------------------------------------------------

template<typename T>
class LinkList
{
private:
    Node<T> * head;
    Node<T> * tail;
    int size;
public:
    LinkList();
    LinkList(const LinkList<T> & that);
    void pushBack (T data);
    int getSize();
    void clear();
    Node<T>* getHead();
    void operator << (T data);
    ~LinkList();
};

//-----------------------------------------------------

template<typename T>
Node<T>::Node() {
    next = nullptr;
    previous = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& other) {
    data = other.data;
    next = nullptr;
    previous = nullptr;
    if (other.next != nullptr) {
        next = new Node<T>(*other.next);
        next->setPrevious(this);
    }
    if (other.previous != nullptr) {
        previous = new Node<T>(*other.previous);
        previous->setNext(this);
    }
}

template<typename T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<typename T>
void Node<T>::setNext(Node<T> * next) {
    this->next = next;
}

template<typename T>
void Node<T>::setPrevious(Node<T> * previous) {
    this->previous = previous;
}

template<typename T>
T& Node<T>::getData() {
    return this->data;
}

template<typename T>
Node<T> * Node<T>::getNext() {
    return this->next;
}

template<typename T>
Node<T> * Node<T>::getPrevious() {
    return this->previous;
}


//--------------------------------------------------------------------------------


template<typename T>
LinkList<T>::LinkList() {
    size = 0;
    head = nullptr;
    tail= nullptr;
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T>& that){
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node<T>* current = that.head;
    while (current != nullptr) {
        pushBack(current->getData());
        current = current->getNext();
    }
}

template<typename T>
Node<T>* LinkList<T>::getHead() {
    return head;
}

template<typename T>
int LinkList<T>::getSize() {
    return size;
}

template<typename T>
void LinkList<T>::pushBack (T data){
    Node<T> * tmp = new Node<T>;
    tmp->setData(data);
    if(head == nullptr){
        head = tail = tmp;
    }
    else{
        tmp->setPrevious(tail);
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}

template<typename T>
void LinkList<T>::clear() {
    Node<T> *tmp = head;

    while (tmp != nullptr) {
        Node<T> * tmp2 = tmp;
        tmp = tmp->getNext();
        delete tmp2;
    }

    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
LinkList<T>::~LinkList() {
    clear();
}

template<typename T>
void LinkList<T>::operator<<(T data){
    this->pushBack(data);
}

#endif // LINKLIST_H
