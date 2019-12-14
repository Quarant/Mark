#pragma once
#include <thread>

namespace client
{
        struct pos {
            int x;
            int y; 
        };



    class client
    {
        public:
        std::thread worker;
        void printName();
        int id;
        client();
        client(const client & );
        // client(int i);
        
        char* name;
        pos P;

        void do_stuff();
        client(pos p);

        

    };

}