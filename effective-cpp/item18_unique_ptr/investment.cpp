#include "investment.hpp"

#include <iostream>
#include <memory>

void makeLogEntry(Investment* p){
    std::cout << "makeLogEntry()" << std::endl;
}

auto delInvmt = [](Investment* pInv)
                {
                    makeLogEntry(pInv);
                    delete pInv;
                }; // customer deleter

template<typename... Ts>
std::unique_ptr<Investment, decltype(delInvmt)>
makeInvestment(Ts&&... args){
    std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

    if(needBond){
        pInv.reset(new Bond(std::forward<Ts>(args)...));
    }
    else if(needStock){
        pInv.reset(new Stock(std::forward<Ts>(args)...));
    }
    else if(needRealEstate){
        pInv.reset(new RealEstate(std::forward<Ts>(args)...));
    }
    return pInv;
}

int main(){
    auto pInv = makeInvestment();
}

