#pragma once
#include "../debug.h"
#include "../shelf/h_shelf.h"
#include <vector>

namespace shelfManager
{
    class shelfManager
    {
        private:
        shelfManager();
        shelfManager(const shelfManager &);
        std::vector<shelf::shelf*> shelfs = std::vector<shelf::shelf*>();
        std::vector<std::string> products = std::vector<std::string>();

        public:

        // shelf
        shelf::shelf& getShelfWithProduct(std::string name);
        void addShelf(shelf::shelf *c);
        void makeShelfs();

        //products
        void loadProducts(std::string loc);
        std::vector<std::string> aviableProducts();
        int sizeOfProducts();


        // static nameManager& getInstance()
        // {
            
        //     static nameManager sing;
        //     return sing;
        // }


        static shelfManager& getInstance()
        {    
            static shelfManager sing;
            return sing;
        }

    };
}