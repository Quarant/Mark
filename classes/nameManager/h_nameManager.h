#pragma once
#include <vector>
#include <string>

namespace nameManager
{
    class nameManager
    {
        private:
        nameManager();
        nameManager(const nameManager & );

        public:
        // static nameManager* instance;
        std::vector<std::string> names;
        void loadNames(std::string fileLoc);

        
        static nameManager& getInstance(){
            
            static nameManager sing;
            return sing;
        }

        char* randName();        

    };
    
}