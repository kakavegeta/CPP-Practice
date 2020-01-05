1. uniform initialization: a single initialization syntax that can, at least in concept, be used anywhere and express everything.  
2. braced initialization is called "uniform" because braces can be used everywhere.  
3. braced initialization prohibits implicit narrowing conversions.  
```
double x, y, z;
int sum1{x + y + z}; // error! sum of doubles may not be expressible as int!
int sum2(x + y + z); // ok, value truncated to int
int sum3 = x + y + z; // ok, value truncated to int
```
4. braced initialization is immune to c++'s most vexing parse.  
```
// no confusion with following:
Widget w1(); // most vexing parse, declare a function;
Widget w1{}; // declare an object, call Widget ctor with no args
```
5. when using braced initialization, be cautious with `auto`.  
6. constructor with `std::initializer_list`.  
7. It is challenging to choose between `{}` and `()` for object creation inside template(do mess up...).  

