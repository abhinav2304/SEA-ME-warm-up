#include "ShareCR.h"

ShareCR::ShareCR(){std::cout<<"ShareCR Default constructor"<<'\n';};
ShareCR::~ShareCR(){std::cout<<"ShareCR Destructor"<<'\n';};
void ShareCR::circular_reference(std::shared_ptr<ShareCR> ptr)
{
    other = ptr;
};