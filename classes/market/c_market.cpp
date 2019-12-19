#pragma once
#include "h_market.h"
#include "../debug.h"
#include "../client/h_client.h"
#include "../nameManager/h_nameManager.h"
#include <vector>
#include <mutex>
namespace market
{
    market::market()
    {
    //     for(int i=0;i<100;i++)
    //         for(int j=0;j<100;j++)
    //             // this->space[i][j] = std::vector<vector>();
    //pushing null customer to not fully deleting list 
    this->haveC = true;
    auto c = new client::client();
    clients->push_back(c);
    }
    void market::market::spawnClient()
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        try
        {
        auto c = new client::client();
        auto& nameManager = nameManager::nameManager::getInstance();
        c->name = nameManager.randName();
        auto* Clients = this->clients;
        this->haveC = true;
        Clients->push_back(c);
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }
    void market::market::moveClients()
    {
        // int size = this->clientSize();
        for(int i =0; i < this->clientSize(); i++)
        {
            // (*(clients))[i]->move(std::rand()%100,std::rand()%100);
            // (*(clients))[i]->printName();
            this->moveClient(i,std::rand()%100,std::rand()%100);
        }
    }
    void market::market::moveClient(int i,int x,int y)
    {
        if(i==0) return ;
        std::lock_guard<std::mutex> lock(this->m_mutex);
        try
        {
        // auto* c = clients->get(i);
        clients->get(i)->move(x,y);
        // c->move(x,y);
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        

        
    }

    // void market::market::deleteClient(client::client* c)
    // {
    //     this->clients->deleteNode(c);
    // }

    void market::market::deleteClient(int i)
    {
        if(clients->length == 1) return;
        if(this->haveC)
        {
        auto c  = clients->getNode(i);
            this->clients->deleteNode(c);
        }else
        {
            this->haveC = false;
            // free(clients);
        }

    }
    int market::market::clientSize()
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return this->clients->size();
    }

    bool market::market::haveClients()
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        return this->clients->size()-1;
    }

}
