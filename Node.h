//
// Created by shlom on 23/05/2022.
//

#ifndef EX3_NODE_H
#define EX3_NODE_H
#include <cstddef>
template <class T>
class Node
{
private:
    T m_data;
    Node* m_next;
public:

    /*
     * C'tor of Node class
     *
     * @param
     * @return
     *      A new instance of Node
     *      m_next = 0;
    */
    Node():
    m_next(NULL)
    {}
    /*
     * the default Copy C'tor of Node class
     *
     * @param
     * @return
     *      A new instance of Node, equal to the other one
    */
    Node(const Node&) = default;

    /*
     * the default assigment operator of Node class
     *
     * @param
     * @return
     *      reference
    */
    Node& operator=(const Node&) = default;

    /*
     * the default D'tor of Node class
     *
     * @param
     * @return
     *
    */
    ~Node() = default;

    /*
     * setData - set the data of the Node by the elements it gets
     *
     * @param hp - T element
     * @return
     *      void
    */
    void setData(T element)
    {
        if(this!= nullptr)
        {
            m_data = element;
        }
    }

    /*
     * setNext - set the address of the next Node by pointer to the next element
     *
     * @param Node<T>* - pointer to T
     * @return
     *      void
    */
    void setNext(Node<T>* element)
    {
        if(this!= nullptr) {
            m_next = element;
        }
    }

    /*
     * getData
     *
     * @param
     * @return
     *      the data of the Node
    */
    T& getData()
    {
        return m_data;
    }

    /*
     * getNext
     *
     * @param
     * @return
     *      return the pointer to the next Node
    */
    Node* getNext()
    {
        return m_next;
    }
};
#endif //EX3_NODE_H
