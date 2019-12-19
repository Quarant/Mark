#include <iostream>
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/client/h_client.h"
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/nameManager/h_nameManager.h"
#include "classes/client/h_client.h"
#include "classes/market/h_market.h"
#include "classes/debug.h"
#include "classes/shelfManager/h_shelfManager.h"
#include "classes/shelf/h_shelf.h"
#include "classes/product/h_product.h"
#include <vector>
#include <string>
#include <thread>
#include <fstream>
#include <ctime>

static void work(client::client c)
{
    while(true){
    std::cout << c.name << std::endl;
    }
}

int main()
{
    auto a = 0;
    char* main_msg = new char();
    std::srand(std::time(NULL));
    INFO("INFO");
    WARN("WARN");
    ERROR("ERROR");
    CRITICAL("CRITICAL");
    
    INFO("TESTING SHELF MANAGER");
    auto& sM = shelfManager::shelfManager::getInstance();
    // std::ifstream input = std::ifstream();
    sM.loadProducts("vendors/products/product.txt");
    sM.makeShelfs();
    // std::ifstream input = std::ifstream(nameLoc);
    // std::string productName;
    // while(getline(input,productName))
    // {
        
    //     char* name = new char();
    //     // sprintf(name,"mango %d",i);
    //     auto product = new product::product();
    //     product->name=productName;
    //     auto shelf = new shelf::shelf();
    //     shelf->product = product;
    //     sM.addShelf(shelf);
    //     INFO("shelf added");

    // }
    auto c = sM.getShelfWithProduct("fish");
    INFO(c.product->name);
    INFO(c.P.x);
    INFO(c.P.y);
    // std::vector<cashRegister::cashRegister> vec = std::vector<cashRegister::cashRegister>();
    // // cashRegister::cashRegister kasa = cashRegister::cashRegister("cos ");
    // for(int i=0;i<10;i++)
    // vec.push_back( cashRegister::cashRegister(std::to_string(i)) );

    // auto c = client::client();
    
    // nameManager::nameManager n = nameManager::nameManager("vendors/names/names.txt");
    auto& name = nameManager::nameManager::getInstance();
    name.loadNames("vendors/names/names.txt");
    // auto& name2 = nameManager::nameManager::getInstance();
    // name.loadNames("vendors/names/names.txt");
    // c.name = name2.randName();
    // INFO("NAMEMANAGER ADDRESS");
    // sprintf(main_msg,"NAME MANAGER ADDRESS -> 0x%d \n",&name);

    // INFO(main_msg);
    // ERROR(&name);
    // WARN(&name2);

    auto& m = market::market::getInstance();
    // auto& m2 = market::market::getInstance();
    // // INFO("MARKET ADDRES");
    // sprintf(main_msg,"MARKET ADDRESS -> 0x%d\n",&m);
    // INFO(main_msg);




    std::cin >> a; 
    INFO("TEST OF NAME MANAGER");
    // sprintf(main_msg,"NAME MANAGER ADDRES -> 0x%d\n",&name);
    for(int i=0;i<10;i++)
    {
        std::cout << name.randName() << " random name" << std::endl;
    }

    // ERROR(&m);

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
    INFO("SPAWINING CLIENTS");
    for(int i =0 ; i <10 ; i ++)
    {
        m.spawnClient();
    }
    INFO("END OF SPAWINING CLIENTS");
    INFO("WHAT CLIENTS WANT");
    for(int i=1 ; i < m.clients->size();i++)
    {
        m.clients->getNode(i)->data->whatIWant();
    }
    INFO("MOVING CLIENTS");
    while(m.haveClients())
    {
        ERROR(m.haveClients());
        ERROR(m.clientSize());
        if(m.haveClients()){
            m.moveClients();
            // std::cin >> a;
            sprintf(main_msg,"REMOVING CLIENT -> %d",a);
            INFO(main_msg);
            m.deleteClient(1);
        }
    }
    INFO("END OF CLIENT TEST");

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

    

    // delete main_msg;

    INFO("END OF PROGRAM");
    return 0;
}