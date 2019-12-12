#include <iostream>
#include "classes/cashRegister/h_cashRegister.h"
#include "classes/nameManager/h_nameManager.h"
#include <vector>


int main()
{
    
    std::vector<cashRegister::cashRegister> vec = std::vector<cashRegister::cashRegister>();
    // cashRegister::cashRegister kasa = cashRegister::cashRegister("cos ");
    for(int i=0;i<10;i++)
    vec.push_back( cashRegister::cashRegister(std::to_string(i)) );


    // nameManager::nameManager n = nameManager::nameManager("vendors/names/names.txt");
    auto n = nameManager::getInstance();

    for(int i=0;i<10;i++)
    {
        std::cout << n.randName() << " random name" << std::endl;
    }
   
    // std::cout <<  << std::endl;

    return 0;
}