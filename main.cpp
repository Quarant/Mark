#include <iostream>
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/client/h_client.h"
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/nameManager/h_nameManager.h"
#include "classes/client/h_client.h"
#include <vector>
#include <thread>

static void work(client::client c)
{
    while(true){
    std::cout << c.name << std::endl;
    }
}

int main()
{
    
    // std::vector<cashRegister::cashRegister> vec = std::vector<cashRegister::cashRegister>();
    // // cashRegister::cashRegister kasa = cashRegister::cashRegister("cos ");
    // for(int i=0;i<10;i++)
    // vec.push_back( cashRegister::cashRegister(std::to_string(i)) );

    // auto c = client::client();
    
    // nameManager::nameManager n = nameManager::nameManager("vendors/names/names.txt");
    auto& name = nameManager::nameManager::getInstance();
    name.loadNames("vendors/names/names.txt");
    auto& name2 = nameManager::nameManager::getInstance();
    // name.loadNames("vendors/names/names.txt");
    // c.name = name2.randName();

    auto clients = std::vector<client::client*>();
    int id = 0 ;
    for(int i=0 ;i <10 ; i++)
    {
        client::client* c = new client::client();
        c->name= name2.randName() ;
        c->id=id++;
        clients.push_back(c);
    }
    // delete &id;
    for (auto client:clients)
    {
        // std::thread t = std::thread(work,client);
        // t.name(client.name)
        std::cout << "[starting thread] " << client->name << " " << client->id << std::endl;
        client->do_stuff();
    

        // std::cout << client.name << std::endl;
    }
    auto a = 0;
    std::cin >> a; 
    // std::cout << &name << "\t" << &name2 << "\t" << std::endl;

    // for(int i=0;i<10;i++)
    // {
    //     std::cout << n.randName() << " random name" << std::endl;
    // }
   
    // std::cout <<  << std::endl;
    return 0;
}