#include "WeakCR.h"

WeakCR::WeakCR(){std::cout<<"WeakCR Default constructor"<<'\n';};
WeakCR::~WeakCR(){std::cout<<"WeakCR Destructor"<<'\n';};
void WeakCR::circular_reference(std::weak_ptr<WeakCR> ptr)
{
    other = ptr;
};