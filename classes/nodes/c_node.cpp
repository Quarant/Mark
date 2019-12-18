#pragma once
#include "../debug.h"
#include "h_node.h"
#include <cassert>

namespace List
{

    List::List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }

    void List::List::push_back(client::client *element)
    {
        this->length++;
        auto *tmp = new node();
        tmp->data = element;
        tmp->next = NULL;

        if (this->head == NULL)
        {
            this->head = tmp;
            this->tail = tmp;
        }
        else
        {
            this->tail->next = tmp;
            this->tail = tail->next;
        }
    }
    int List::List::size()
    {
        return this->length;
    }

    // https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
    client::client *List::List::get(int i)
    {
        node *current = this->head;
        int count = 0;
        while (current != NULL)
        {
            if (count == i)
                return (current->data);
            count++;
            current = current->next;
        }
        // in case of error
        assert(0);
    }

    node* List::List::getNode(int i)
    {
        if(this->length < i)
            CRITICAL("INDEX OUT OF RANGE ");
        node *current = this->head;
        int count = 0;
        while (current != NULL)
        {
            // if (current->data == i)
            if(count == i)
                return (current);
            count++;
            current = current->next;
        }
        // in case of error
        assert(0);
    }
    node* List::List::getNode(client::client *i)
    {
        node *current = this->head;
        int count = 0;
        while (current != NULL)
        {
            if (current->data == i)
                return (current);
            count++;
            current = current->next;
        }
        // in case of error
        assert(0);
    }

    // https://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/
    void List::List::deleteNode(node *n)
    {
        // When node to be deleted is head node
        if (this->head == n)
        {
            if (this->head->next == NULL)
            {
                std::cout << "There is only one node."
                        << " The list can't be made empty ";
                return;
            }

            /* Copy the data of next node to head */
            this->head->data = this->head->next->data;

            // store address of next node
            n = this->head->next;

            // Remove the link of next node
            this->head->next = this->head->next->next;

            // free memory
            free(n);

            return;
        }

        // When not first node, follow
        // the normal deletion process

        // find the previous node
        node *prev = head;
        while (prev->next != NULL && prev->next != n)
            prev = prev->next;

        // Check if node really exists in Linked List
        if (prev->next == NULL)
        {
            std::cout << "\nGiven node is not present in Linked List";
            return;
        }

        // Remove node from Linked List
        prev->next = prev->next->next;

        // Free memory
        free(n);
        this->length--;
        return;
    }

} // namespace List