#pragma once
#include "../debug.h"
#include "../client/h_client.h"
namespace List
{
    class node
    {
        public:
        client::client* data;
        node* next;
    };
    class List
    {
        
        public:
        node *head, *tail;
        List();
        int length;
        
        void push_back(client::client* element);
        int size();

        client::client* get(int i);
        node* getNode(int i);
        node* getNode(client::client *i);
        void deleteNode(node* n);
        
        // void push_after(T *element);
        // void push_before(T *element);

        // void pop(T *element);
        // void pop_after(T *element);
        // void pop_before(T *element);

    };

}
