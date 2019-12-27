1. An lvalue is an expression that identifies a non-temporary object  
2. An rvalue is an expression that identifies a temporary object or is a alue not associated with any object  
3. If the functiona call computes an expression whose value does not exist prior to the call and does not exist onece the call is finished 
    unless it is copied somewhere, it is likely to be an rvalue  
4. lvalue reference is declared by placing an `&` after some type  
5. rvalue reference is delcared by placing an `&&` after some type  
6. reference variables are often used to avoid copying objects  

