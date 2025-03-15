#include <stdio.h>

// Inline function to calculate the square of a number
inline int square(int x) {
    return x * x;
}

int main() {
    int n = 5;
  
    // The compiler will replace square(n) with (n * n)
    int res = square(n);
  
    printf("%d", res);
    return 0;
}


Issues L
1. With out complier optimization you will see compilation  errror 
salluvad@SALLUVAD-M-QRQG ~ % gcc test_inline.c 
Undefined symbols for architecture arm64:
  "_square", referenced from:
      _main in test_inline-a4cb37.o
ld: symbol(s) not found for architecture arm64

2. need to use GCC optimazation flags , -O1 

3. Also use static inline  , this will force internal linkage 

4. can also use forward declaration , like int square () ;
