#pragma once
#include "h_cashRegister.h"
#include <string>
namespace cashRegister
{
    cashRegister::cashRegister(){
        
    }
    cashRegister::cashRegister(std::string name)
    {
        this->name = name;
    }
    std::string cashRegister::getName()
    {
        return this->name;
    };
}