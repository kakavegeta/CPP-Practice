## Smart pointers are designed to help manage the lifetimes of dynamicallly allocted objects, i.e., to avoid resource leaks by ensuring that such objects are destroyed in the appropriate manner at the appropriate time.  

### use `std::unique_ptr` for exclusive-ownership resource namagement
1. used commonly in factory.  
