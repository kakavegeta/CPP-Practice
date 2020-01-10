1. copy constructor  
cloning using pointers is efficient in c++, which avoids slicing:  
```
Object* originalObj = new Object;
Object* copy = nullptr;

copy = new Object(*OrigianlObj)
```

2. move constructor
3. A constructor that supplies default arguments for all its parameters also defines the default constructor.  
4. the order of member initialization matters if one member is initialized in terms of another.  
