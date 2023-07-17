#pragma once
#include <iostream>
#include <memory>

// Circular Reference Test Class
class ShareCR
{
public:
    ShareCR();
    ~ShareCR();
    std::shared_ptr<ShareCR> other;

    // member function for checking Circular Reference
    void circular_reference(std::shared_ptr<ShareCR> ptr);
};
