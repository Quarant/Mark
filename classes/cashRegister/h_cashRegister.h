#pragma once
#include <string>
namespace cashRegister
{
    class cashRegister
    {
        public:
        cashRegister();
        std::string name;
        cashRegister(std::string name);
        
            std::string getName();

    };



}