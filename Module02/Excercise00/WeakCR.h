#pragma once
#include <iostream>
#include <memory>

class WeakCR
{
public:
    WeakCR();
    ~WeakCR();
    std::weak_ptr<WeakCR> other;

    // member function for checking Circular Reference
    void circular_reference(std::weak_ptr<WeakCR> ptr);
};