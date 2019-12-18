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