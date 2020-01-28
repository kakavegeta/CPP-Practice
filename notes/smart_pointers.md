Smart pointers are designed to help manage the lifetimes of dynamicallly allocted objects, i.e., to avoid resource leaks by ensuring that such objects are destroyed in the appropriate manner at the appropriate time.  

### use `std::unique_ptr` for exclusive-ownership resource management
1. used commonly in factory. 
2. almost similar as raw pointer.  
3. copy a `std::unique_ptr` is not allowed; `std::unique_ptr` is a move-only type.  

#### example:  
```
class Investment {...};

class Stock:
    public Investment {...};

class Bond:
    public Investment {...};

class RealEstate:
    public Investment {...};
```

```
template<typename... Ts>
std::unique_ptr<Investment> makeInvestment(Ts&&... params); // declare factory function
```
Callers could use the returned `std::unique_ptr` in a single scope as follows:  
```
{
    ...
    auto pInvestment = makeInvestment(args);
    ...
} // *pInvestment is destroyed.
```
