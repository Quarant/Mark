#include <iostream>
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/client/h_client.h"
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/nameManager/h_nameManager.h"
#include "classes/client/h_client.h"
#include "classes/market/h_market.h"
#include "classes/debug.h"
#include <vector>
#include <string>
#include <thread>

static void work(client::client c)
{
    while(true){
    std::cout << c.name << std::endl;
    }
}

int main()
{
    auto a = 0;
    
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
    // INFO("NAMEMANAGER ADDRESS");
    WARN("NAME MANAGER ADDRESS");
    ERROR(&name);
    // WARN(&name2);

    auto& m = market::market::getInstance();
    auto& m2 = market::market::getInstance();
    // INFO("MARKET ADDRES");
    WARN("MARKET ADDRESS");
    ERROR(&m);

    // auto clients = std::vector<client::client*>();
    // int id = 0 ;
    // for(int i=0 ;i <10 ; i++)
    // {
    //     client::client* c = new client::client( std::rand()%100,std::rand()%100);
    //     c->name= name2.randName() ;
    //     c->id=id++;
    //     clients.push_back(c);
    // }
    // WARN("MARKET ADRESS "+&m2);
    // m.space[0][0] = clients[0];
    // m.space[0][0].printName()
    // auto c = clients[0];

    for(int i =0 ; i <10 ; i ++)
    {
        m.spawnClient();
    }
    while(m.haveClients())
    {
        std::cout << m.haveClients() << std::endl;
        ERROR(m.haveClients());
        if(m.haveClients()){
            m.moveClients();
            std::cin >> a;
            m.deleteClient(1);
        }
    }
    // while(true){
    //     for(int i=0 ; i< clients.size();i++)
    //     {
    //         clients[i]->move(std::rand()%100,std::rand()%100);
    //     }
    //     std::cin >> a;
    // }
    // {
    //     c->move(std::rand(),std::rand());
    //     std::cin >> a;
    // }

    // delete &id;
    // for (auto client:clients)
    // {
    //     // std::thread t = std::thread(work,client);
    //     // t.name(client.name)
    //     std::cout << "[starting thread] " << client->name << " " << client->id << std::endl;
    //     client->do_stuff();
    

    //     // std::cout << client.name << std::endl;
    // }

    
    std::cin >> a; 
    // std::cout << &name << "\t" << &name2 << "\t" << std::endl;

    // for(int i=0;i<10;i++)
    // {
    //     std::cout << n.randName() << " random name" << std::endl;
    // }
   
    std::cout << "koniec" << std::endl;
    return 0;
}