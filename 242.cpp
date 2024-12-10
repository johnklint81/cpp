<include iostream>

int main() {
    // declare and assign a = 10
    int a = 10;
    // declare reference b to point to a. changing b changes a
    int &b = a;
    // declare int pointer c to point at address of reference b, which references
    // the variable a
    int* c = &b;
    // declare d as a constant int pointer that points at address of ref b.
    // the value at address &b cannot be changed by modifying d. d itself
    // can be made to point to a different address however.
    const int* d = &b;
    // same as above, declare e as a constant int poiter to the address of
    // ref b, i.e. a.
    int const * e = &b;
    // declare f as a constant int pointer to the address of a. a can be changed
    // by modifying f but f cannot be changed to point elsewhere
    int * const f = &a;
    // declare g as a constant pointer to a constant int. neither the value nor
    // what value g points at can be changed through interaction with g
    const int * const g = &a;
    // this is the same as above, g is a constant pointer to a constant int
    int const * const h = &a;
    // declare i as a constant int reference to a, a cannot be changed through
    // interaction with the constant reference i
    int const & i = a;
    // this gives the same result as above, j is a constant int reference to 
    // the alias/reference b which references a. neither can be changed through
    // interaction with b
    const int & j = b;
    // declare k as a function pointer to a function that takes a pointer to an
    // int as input and returns a pointer to an int 
    int*(*k)(int*);
    // declare l as an array of pointers to functions that take no input
    // and returns no output (i.e. return type is void)
    void(*l[4])(void);
}
