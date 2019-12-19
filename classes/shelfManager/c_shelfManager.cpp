#pragma once
#include "../debug.h"
#include "h_shelfManager.h"
#include "../shelf/h_shelf.h"
#include <fstream>
#include <string>

shelf::shelf& shelfManager::shelfManager::getShelfWithProduct(std::string name)
{
    for( auto& s :this->shelfs )
    {
        if(s->product->name == name)
            return *s;
    }
    
    std::string msg = "ITEM DO NOT EXIST --> " + name +" <--"; 
    CRITICAL(msg);
    exit(PRODUCT_NOT_EXIST);
    // return NULL;
    
}


void  shelfManager::shelfManager::addShelf(shelf::shelf *c)
{
    this->shelfs.push_back(c);
}

std::vector<std::string> shelfManager::shelfManager::aviableProducts()
{
    return this->products;
}

int shelfManager::shelfManager::sizeOfProducts()
{
    return this->products.size();
}

void shelfManager::shelfManager::makeShelfs()
{
    //     char* name = new char();
    //     // sprintf(name,"mango %d",i);
    //     auto product = new product::product();
    //     product->name=productName;
    //     auto shelf = new shelf::shelf();
    //     shelf->product = product;
    //     sM.addShelf(shelf);
    //     INFO("shelf added");

    for(auto s : this->products)
    {
        auto product = new product::product();
        product->name = s;
        auto shelf = new shelf::shelf();
        shelf->product = product;
        shelf->P = {std::rand()%100,std::rand()%100};
        this->addShelf(shelf);
    }
}

void shelfManager::shelfManager::loadProducts(std::string loc)
{
    std::ifstream input = std::ifstream(loc);
    std::string tmp;
    while(getline(input,tmp))
    {
        this->products.push_back(tmp);
    }
    INFO("SHELF MANAGER PRODUCTS LOADED");
    for(auto i : this->products)
    INFO(i);
}

shelfManager::shelfManager::shelfManager()
{

}