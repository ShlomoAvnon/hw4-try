//
// Created by teich on 23/05/2022.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
#include "Node.h"
#include <cassert>
template <class T>
class Queue
{
public:
    /*
     * C'tor of Queue class
     *
     * @param
     * @return
     *      A new instance of Queue
    */
    Queue():
            m_first(nullptr),
            m_last(nullptr),
            m_counter(0)
    {}

    ~Queue()
    {
        while(!isEmpty())
            popFront();
    }

    /*
     * copy C'tor of Queue class
     *
     * @param queue- to be copied
     * @return
     *      A copy instance of queue
    */
    Queue(const Queue<T>& queue):
    m_first(NULL),
    m_last(NULL),
    m_counter(0)
    {
        try {
            for (const T &element: queue) {
                this->pushBack(element);
            }
        }
        catch (...){
            while(!isEmpty())
                popFront();
            throw;
        }
    }

    /*
    * Operator =
    *
    * @param queue- the queue to be copied
    * @return
    *      reference to a new Queue
    */
    Queue& operator=(const Queue<T>& queue)
    {
        if (this == &queue){
            return *this;
        }
        Queue<T> queue1;

        for (const T &element: queue) {
            queue1.pushBack(element);
        }

        while (!isEmpty())
        {
            this->popFront();
        }
        this->m_first = queue1.m_first;
        this->m_counter = queue1.m_counter;
        this->m_last = queue1.m_last;
        queue1.m_counter=0;
        return *this;
    }

    /*
    * pushes a new element to the queue
    *
    * @param element- the element to be pushed
    * @return
    *      void
    */
    void pushBack(T element)
    {
        Node<T>* tmp = new Node<T>();
        tmp->setData(element);
        tmp->setNext(nullptr);

        if (isEmpty()) {
            m_first = m_last = tmp;
        }
        else {
            m_last->setNext(tmp);
            m_last = tmp;
        }
        m_counter++;
    }

    /*
    * return the first element in the queue by referene
    *
    * @param
    * @return
    *      reference to the first element in the queue
    */
    T& front() const
    {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        return m_first->getData();
    }

    /*
    * delete the first element in the queue
    *
    * @param
    * @return
    *     void
    */
    void popFront()
    {
        if ( isEmpty() ){
            throw EmptyQueue();
        }
        if (m_first == nullptr){
            return;
        }
        Node<T>* tmp = m_first;
        m_first = m_first->getNext();
        m_counter--;
        delete tmp;
    }

    /*
    * return the number of elements in the queue
    *
    * @param
    * @return
    *      the size of the queue
    */
    int size() const
    {
        return m_counter;
    }

    /*
    * return if the queue has at least 1 element
    *
    * @param
    * @return
    *      type bool if the queue has at least 1 element
    */
    bool isEmpty() const
    {
        return m_counter == 0;
    }

    /*
    * return a new queue that contains only the elements that was filtred
     * in the condition method
    *
    * @param queue- the queue to be filtred
     * @param condition - the method that filters the elements
    * @return
    *      new filtered Queue object
    */
    template<class P, class Condition>
    friend Queue<P> filter(Queue<P> queue,Condition condition);

    /*
   * changes the elements of queue by sending it to operation
   *
   * @param queue- the queue to be changed
    * @param operation - the method that changes the elements
   * @return
   *      void
   */
    template<class P, class Operation>
    friend void transform(Queue<P> &queue, Operation operation);



    class Iterator;
    class ConstIterator;

    /*
  * returns an iterator object the points to the begin of the queue
  *
  * @param
  * @return
  *      Iterator to begining of the queue
  */
    Iterator begin()
    {
        return Iterator(this, this->m_first);
    }

    /*
  * returns an iterator object that points to one after the end of the queue
  *
  * @param
  * @return
  *      Iterator to one after the end of the queue
  */
    Iterator end()
    {
        return Iterator(this, NULL);
    }

    /*
  * returns a const iterator object that points to the begin of the queue
  *
  * @param
  * @return
  *      constIterator to begining of the queue
  */
    ConstIterator begin() const
    {
        return ConstIterator(this, this->m_first);
    }

    /*
  * returns a const iterator object that points to one after the end of the queue
  *
  * @param
  * @return
  *      constIterator to one after the end of the queue
  */
    ConstIterator end() const
    {
        return ConstIterator(this, NULL);
    }

    class EmptyQueue {};

private:
    Node<T>* m_first;
    Node<T>* m_last;
    int m_counter;
};

template <class P, class Condition>
Queue<P> filter(Queue<P> queue ,Condition condition) {
        Queue<P> result;
        for (const P& element: queue) {
            if ( condition(element) ){
                result.pushBack(element);
            }
        }
        return result;
}

template<class P, class Operation>
void transform(Queue<P> &queue ,Operation operation)
{
    for (typename Queue<P>::Iterator i = queue.begin(); i != queue.end(); ++i) {
        operation(*i);
    }
}

template<class T>
class Queue<T>::Iterator{
public:
    /*
     * the default Copy C'tor of the Iterator
     *
     * @param
     * @return
     *      new Iterator that equal to the other one
    */
    Iterator(const Iterator&) = default;

    /*
     * the default Assigment operator of the Iterator
     *
     * @param
     * @return
     *      reference to this Iterator
    */
    Iterator& operator=(const Iterator&) = default;

    /*
     * the default D'tor of the Iterator
     *
     * @param
     * @return
     *
    */
    ~Iterator() = default;

    class InvalidOperation {};

    /*
     * operator*
     *
     * @param
     * @return
     *      reference to the data of the current Node in the queue
    */
    T& operator*() const
    {
        if(!(m_queue->isEmpty()) && (&m_current))
        {
            return m_current->getData();
        }
        throw InvalidOperation();
    }

    /*
     * operator++()
     *
     * @param
     * @return
     *      reference to this Iterator (before add one)
    */
    Iterator& operator++()
    {
        if (!(m_current)){
            throw InvalidOperation();
        }
        m_current = m_current->getNext();
        return *this;
    }

    /*
     * operator++(int)
     *
     * @param
     * @return
     *      new Iterator (after add one to this)
    */
    Iterator operator++(int)
    {
        if (!m_current){
            throw InvalidOperation();
        }
        Iterator result = *this;
        ++*this;
        return result;
    }

    /*
     * operator==
     *
     * @param reference to Iterator
     * @return
     *      false - if they are not the same
     *      true - if they are the same
    */
    bool operator==(const Iterator& iterator) const
    {
        if(!(m_queue == iterator.m_queue))
        {
            throw InvalidOperation();
        };
        return m_current == iterator.m_current;
    }

    /*
     * operator!=
     *
     * @param reference to Iterator
     * @return
     *      true - if they are not the same
     *      false - if they are the same
    */
    bool operator!=(const Iterator& iterator) const
    {
        return !(*this == iterator);
    }


private:
    const Queue<T>* m_queue;
    Node<T> *m_current;
    Iterator(const Queue<T> *queue, Node<T> *current):
            m_queue(queue),
            m_current(current)
    {};
    friend class Queue<T>;

};


template<class T>
class Queue<T>::ConstIterator{
public:

    /*
     * the default Copy C'tor of the ConstIterator
     *
     * @param
     * @return
     *      new ConstIterator that equal to the other one
    */
    ConstIterator(const ConstIterator&) = default;

    /*
     * the default Assigment operator of the ConstIterator
     *
     * @param
     * @return
     *      reference to this ConstIterator
    */
    ConstIterator& operator=(const ConstIterator&) = default;

    /*
     * the default D'tor of the ConstIterator
     *
     * @param
     * @return
     *
    */
    ~ConstIterator() = default;


    class InvalidOperation {};

    /*
     * operator*
     *
     * @param
     * @return
     *      const reference to the data of the current Node in the queue
    */
    const T& operator*() const
    {
        if(!(m_queue->isEmpty()) && m_current);
        return m_current->getData();
    }

    /*
     * operator++()
     *
     * @param
     * @return
     *      reference to this ConstIterator (before add one)
    */
    ConstIterator& operator++()
    {
        if (!(m_current)){
            throw InvalidOperation();
        }
        m_current = m_current->getNext();
        return *this;
    }

    /*
     * operator++(int)
     *
     * @param
     * @return
     *      new ConstIterator (after add one to this)
    */
    ConstIterator operator++(int)
    {
        if (!m_current){
            throw InvalidOperation();
        }
        ConstIterator result = *this;
        ++*this;
        return result;
    }

    /*
     * operator==
     *
     * @param reference to ConstIterator
     * @return
     *      false - if they are not the same
     *      true - if they are the same
    */
    bool operator==(const ConstIterator& constIterator) const
    {
        if(!(m_queue == constIterator.m_queue))
        {
            throw InvalidOperation();
        };
        return m_current == constIterator.m_current;
    }

    /*
     * operator!=
     *
     * @param reference to ConstIterator
     * @return
     *      true - if they are not the same
     *      false - if they are the same
    */
    bool operator!=(const ConstIterator& constIterator) const
    {
        return !(*this == constIterator);
    }


private:
    const Queue<T>* m_queue;
    Node<T> *m_current;
    ConstIterator(const Queue<T>* queue, Node<T>* current):
            m_queue(queue),
            m_current(current)
    {};
    friend class Queue<T>;

};


#endif //EX3_QUEUE_H
