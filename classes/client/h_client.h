#pragma once
#include <thread>
#include "../product/h_product.h"
#include <vector>

namespace client
{
        struct pos {
            int x;
            int y; 
        };



    class client
    {
        public:
        std::vector<product::product*> wants = std::vector<product::product*>();
        std::thread worker;
        void printName();
        int id;
        client();
        client(const client & );
        client(int x,int y);
        
        // client(int i);
        //TELEPORTATION !
        void move(int x, int y);
        void whatIWant();

        char* name;
        pos P;

        void do_stuff();

        

    };

}