#pragma once
#include "../debug.h"
#include "../client/h_client.h"
#include "../nodes/h_node.h"
#include <vector>
#include <mutex>


namespace market
{
    class market
    {
        private:
        market();
        market(const market &);
        mutable std::mutex m_mutex;
        public:
        // std::vector<client::client*>* clients = new std::vector<client::client*>();
        List::List* clients = new List::List();
        bool haveC ;
        
        static market& getInstance()
        {
            static market mark;
            return mark;
        };

        int clientSize();

        void spawnClient();
        void moveClients();
        void moveClient(int i,int x,int y);
        void deleteClient(client::client* c);
        void deleteClient(int i);
        bool haveClients();
        
        //static nameManager& getInstance(){
            
        //     static nameManager sing;
        //     return sing;
        // }

        void* space[100][100]; 
    };

}