#ifndef _ORDERQUEUE_H
#define _ORDERQUEUE_H

#include "Order.h"

struct NodeType
{
    Order data;
    NodeType* next;
};

class OrderQueue
{
public:
    OrderQueue()
    {
        qFront = NULL;
        qRear = NULL;
    }


    ~OrderQueue()
    {
        Order tmp;
        while (!IsEmpty()) {
            Dequeue(tmp);
        }
    }

    bool IsEmpty() const {
        return (qFront == NULL);
    }

    // Adds newItem to the rear of the queue.
    // Pre: Queue has been initialized.
    // Post: newItem is at rear of queue.
    void Enqueue(Order neworder) {
        NodeType* ptr;
        ptr = new NodeType;
        ptr->data = neworder;
        ptr->next = NULL;
        if (qRear == NULL)
            qFront = ptr;
        else
            qRear->next = ptr;
        qRear = ptr;
    }

    /**
    *   @brief   Order Queue�� front�� ��ġ�ϴ� �޴��� ���� �� �Է��Ķ������ menu�� ����
    *   @pre   Queue has been initialized. ť�� ������� �ʾƾ� ��
    *   @post   ���� front�� �޴��� ���� �� front�� �޴��� ��ȭ
    */
    void Dequeue(Order& neworder) {
        NodeType* tempPtr;
        tempPtr = qFront;
        neworder = qFront->data;
        qFront = qFront->next;
        if (qFront == NULL)
            qRear = NULL;
        delete tempPtr;
    }

    /**
    *   @brief   Order Queue���� �޴����� print
    *   @pre   Queue has been initialized.
    *   @post   none.
    */
    void PrintOrderQueue() {
        cout << endl;
        cout << "[Order Oueue]" << endl;
        NodeType* tempPtr;
        tempPtr = qFront;
        while (tempPtr != NULL) {
            tempPtr->data.PrintOrder(); // order ��ü print �Լ�
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }

private:
    NodeType* qFront;
    NodeType* qRear;
};


#endif