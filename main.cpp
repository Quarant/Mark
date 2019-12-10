#include <iostream>
#include "classes/cashRegister/h_cashRegister.h"
#include <vector>


int main()
{
    std::vector<cashRegister::cashRegister> vec = std::vector<cashRegister::cashRegister>();
    // cashRegister::cashRegister kasa = cashRegister::cashRegister("cos ");
    for(int i=0;i<10;i++)
    vec.push_back( cashRegister::cashRegister(std::to_string(i)) );

    for(auto a :vec)
    std::cout << a.getName() << std::endl;
    
    // std::cout <<  << std::endl;

    return 0;
}