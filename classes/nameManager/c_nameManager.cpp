#include "../debug.h"
#include "h_nameManager.h"
#include <fstream>
#include <vector>
#include <ctime>


#if debug(DEBUG_INFO) || debug(DEBUG_WARN)
#include <iostream>
#endif
namespace nameManager{
    static nameManager* nameManager::getInstance()
    {
        if(instance == 0)
            static nameManager instance = new nameManager::nameManager();

        return instance;

    };

    void nameManager::loadNames(std::string nameLoc)
    {
        

        std::srand(std::time(NULL));
        std::ifstream input = std::ifstream(nameLoc);
        #if debug(DEBUG_WARN)
        if(input.good())
            std::cout<< "[WARN] FILE " << nameLoc << " exist" << std::endl;
        else
            std::cout<< "[WARN] FILE " << nameLoc << " not exist" << std::endl;
        
        #endif
        std::string line;
        while(getline(input,line))
        {
            this->names.push_back( line);
        }


    }
    nameManager::nameManager()
    {
        
    }

    char* nameManager::randName()
    {
        std::vector<std::string>::iterator it = this->names.begin();
        // std::srand(std::time(NULL));
        //can be problematic soooo let's hope it wont :D ¯\_(ツ)_/¯
        std::advance(it,std::rand() % this->names.size());
        #if debug(DEBUG_INFO)
        std::cout << "[INFO] ITERATOR OUTPUT "  << it->c_str() << std::endl;
        #endif
        return const_cast<char*> (it->c_str());
    }
}