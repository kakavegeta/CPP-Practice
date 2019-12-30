See "C++ type deduction and why you care", by Scott Meyers  

**Type Deduction**  
```
template<typename T>
void f(ParamType param);

f(expr)
```
We have three dedection scenarios to examine. 
1. ParamType is a reference or pointer, but not universal reference:  
a. if `expr` is a reference, ignore that;  
b. Pattern-match `expr`'s type against `ParamType` to determin `T`  

2. ParamType is an universal Reference:
```
template<typename T>
void f(T&& param);
f(expr)
```  
- if `expr` is lvalue with deduced type `E`, `T` deduced as `E&`  
- if `expr` is an rvalue, case 1 applies.

3. By-value parameters:  
- if `expr`'s type is reference, ignore that;  
- if `expr` is `const` or `volatile`, ignore that;
- `T` is the result 
`expr`'s reference or const qualifier always dropped in deducing `T` 

