#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Graph.h"

using namespace std;

template<class T>
class Node
{
    public:
        T* Data;
        Node *Next;
        Node(T *data){
            Data = data;
            Next = NULL;
        }
};

template<class T>
class Linked_list
{
    public:
        Node<T>* Head, *Current;
        Linked_list(){
            Head = NULL;
        }
        void Add(T *data){
            if(Head == NULL){
                Head = new Node<T>(data);
            }
            else{
                Node<T>* tmp = Head;
                while(tmp->Next)
                    tmp = tmp->Next;
                tmp->Next = new Node<T>(data);
            }
        }

        T* Begin(){
            Current = Head;
            return (Current != NULL ? Current->Data : NULL);
        }

        T* GetNext(){
            Current = Current->Next;
            return (Current != NULL ? Current->Data : NULL);
        }

        friend ostream& operator<<(ostream& out, Linked_list<T>& lst){
            Node<T>* cur = lst.Head;
            while (cur != NULL){
                out << *cur->Data << " ";
                cur = cur->Next;
            }
            return out;
        }
};

#endif // LINKED_LIST_H
