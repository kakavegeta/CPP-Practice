#ifndef _INVESTMENT_H_
#define _INVESTMENT_H_


bool needBond = true;
bool needStock = false;
bool needRealEstate = false;


class Investment{
public:
    virtual ~Investment() {} //deconstructor
};

class Bond: public Investment {};
class RealEstate: public Investment {};
class Stock: public Investment {};

#endif