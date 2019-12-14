#pragma once
#include "../debug.h"

namespace market
{
    class market
    {
        private:
        market();
        market(const market &);
        public:
        
        static market& getInstance()
        {
            static market mark;
            return mark;
        };


        //static nameManager& getInstance(){
            
        //     static nameManager sing;
        //     return sing;
        // }

        void* space[100][100]; 
    };

}