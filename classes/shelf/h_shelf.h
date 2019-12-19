#pragma once
#include "../debug.h"
#include "../product/h_product.h"

namespace shelf
{
    struct pos
    {
        int x;
        int y;
    };
    class shelf
    {
        public:
        shelf();
        pos P;
        product::product* product;
    };
    
}