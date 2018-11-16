#include "monitoingtarget.h"



MonitoingTarget::MonitoingTarget(int _id)
    :mId(_id)
{
    std::cout << "Constructing Target : " << mId << std::endl;
}

MonitoingTarget::~MonitoingTarget()
{
    std::cout << "Destroying Target: " << mId << std::endl;
}
