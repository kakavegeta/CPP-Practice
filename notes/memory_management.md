1. What is dangling pointer? 
Pointers that do not point to a valid object of the appropriate type.  
e.g.:  
```
int* get_ptr_five(){
    int x = 5;
    return &x;
}

int main(){
    int *p = get_ptr_five();
    cout << *p << endl; // here x goes out of scope, so p is a dangling pointer.
}
```

2. `new` operator: allocate memory to ensure it remains allocated.    
3. `delete` operator: when done, de-allocate the memory.  
4. Tips for `new` and `delete`:  
    a. if not use `delete` to de-allocate memory, there will be waste memory/memory leak;  
    b. do not use memory after deletion;  
    c. do not delete memory twice;  
    d. only `delete` if memory was allocated by `new`;  
5. When allocating arrays on stack, e.g., `int arr[size]`, `size` must be constant;  
6. When allocating arrays on heap, e.g., `new int[size]`, `size` can be a variable;  
7. De-allocate arrays with `delete[]`
8. 

