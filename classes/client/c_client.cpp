#pragma once

#include "h_client.h"
#include "../debug.h"
#include <thread>
#include <unistd.h>
#include "../product/h_product.h"
#include "../shelfManager/h_shelfManager.h"


// #if debug(DEBUG_INFO)

// #include <iostream>
// #endif

namespace client
{

    // client::client( client::pos& P )
    // {
    //     // this->P = P;a
    // };

    client::client::client(const client &o  )
    {
        this->name = o.name;
    };
    void client::client::printName()
    {
        std::cout << this->name << " " <<   std::endl;
        usleep(std::rand() % 2000);
        // std::cin >> a;
    };
    void client::client::do_stuff()
    {
        this->worker = std::thread(&client::client::printName , this);
        this->worker.detach();
        
    };
    client::client::client()
    {
        this->P = {0,0};
        auto& shelfManager =  shelfManager::shelfManager::getInstance();
        for(int i =0 ; i < std::rand()%10;i++)
        {
            auto product = new product::product();
            product->name = shelfManager.aviableProducts()[std::rand()%shelfManager.sizeOfProducts()];
            this->wants.push_back(product);
        }
    };
    client::client::client(int x,int y)
    {
        this->P.x = x;
        this->P.y = y;
    };
    void client::client::move(int x , int y)
    {
        try
        {
        char* a = new char();
        sprintf(a,"%s moved from x:%d y:%d to x:%d y:%d",this->name,this->P.x,this->P.y,x,y);
        INFO(a);
        delete a;
        this->P.x = x;
        this->P.y = y;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        // std::string a = (std::string)(this->name) + (std::string)" moved from " (this->P.x + " " + this->P.y);
        // std::stringstream a = std::stringstream("");
        // a << this->name << " moved from : " << this->P.x << " " << this->P.y << " to :" << x << " " << y;
    }
    // client::client::client(int i)
    // {
    //     this->id = i;
    // };

    void client::client::whatIWant()
    {
        std::string items = "";
        for(auto item : this->wants)
        {
            items += item->name + " ";
        }
        std::string tmp = std::string(this->name);
        items = tmp + " " + items;
        INFO(items);
    }
}