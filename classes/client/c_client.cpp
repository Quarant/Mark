#pragma once

#include "h_client.h"
#include "../debug.h"
#include <thread>
#include <unistd.h>


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
}