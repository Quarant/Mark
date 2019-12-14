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
    //     // this->P = P;
    // };

    client::client::client(const client &o  )
    {
        this->name = o.name;
    };
    void client::client::printName()
    {
        std::cout << this->name << " " << this->id <<   std::endl;
        usleep(std::rand() % 60);
        std::cout << "finished";
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
    client::client::client(client::pos pos)
    {
        this->P = client::pos();
        this->P.x = p.pos
        this->P.y = p.pos
    };
    // client::client::client(int i)
    // {
    //     this->id = i;
    // };
}