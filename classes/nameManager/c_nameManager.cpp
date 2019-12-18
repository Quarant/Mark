#include "../debug.h"
#include "h_nameManager.h"
#include <fstream>
#include <vector>
#include <ctime>




namespace nameManager{
    // static nameManager & getInstance()
    // {
    //     static nameManager sig;
    //     return sig;
    // }
    
    

    void nameManager::loadNames(std::string nameLoc)
    {
        

        std::srand(std::time(NULL));
        std::ifstream input = std::ifstream(nameLoc);
        // #if debug(DEBUG_WARN)
        // if(input.good())
        //     std::cout<< "[WARN] FILE " << nameLoc << " exist" << std::endl;
        // else
        //     std::cout<< "[WARN] FILE " << nameLoc << " not exist" << std::endl;
        
        // #endif
        if(input.good())
        {
            INFO("FILE EXIST");
        }
        else
        {
            CRITICAL("FILE NOT EXIST");
            exit(CODE_FILE_NOT_EXIST);
        }
    
        std::string line;
        while(getline(input,line))
        {
            this->names.push_back( line);
        }


    };
    nameManager::nameManager()
    {
        
    };

    char* nameManager::randName()
    {
        std::vector<std::string>::iterator it = this->names.begin();
        // std::srand(std::time(NULL));
        //can be problematic soooo let's hope it wont :D ¯\_(ツ)_/¯
        std::advance(it,std::rand() % this->names.size());
        // #if debug(DEBUG_INFO)
        // std::cout << "[INFO] ITERATOR OUTPUT "  << it->c_str() << std::endl;
        // #endif
        return const_cast<char*> (it->c_str());
    };
}