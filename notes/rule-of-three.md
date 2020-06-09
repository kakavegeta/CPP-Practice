### Destructor

The implicit destruction of a member of built-in pointer type does not `delete` the object to which that pointer points.

Unlike ordinary pointers, the smart pointers (§ 12.1.1, p. 452) are class types and have destructors. As a result, unlike ordinary pointers, members that are smart pointers are automatically destroyed during the destruction phase.

It is important to realize that the destructor body does not directly destroy the members themselves. Members are destroyed as part of the implicit destruction phase that follows the destructor body. A destructor body executes in addition to the memberwise destruction that takes place as part of destroying an object.

If a class needs destructor, it almost surely also needs copy constructor and copy assignment operator.  Reason: if define destructor but not copy constructor and copy assignment operator, the default ones implement shallow copy, copyee and copyer point to same memory. 