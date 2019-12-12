#pragma once
#include <vector>
#include <string>

namespace nameManager
{
    class nameManager
    {
        private:
        static nameManager* instance;
        nameManager();

        public:
        std::vector<std::string> names;
        void loadNames(std::string fileLoc);
        static nameManager* getInstance();

        char* randName();        

    };
    
}