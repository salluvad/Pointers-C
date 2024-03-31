#ifndef __cplusplus 

typedef enum BoolenTag 
{ 
false, 
true
} bool; 

#endif 

#define CRASH() do { \ 
	((void(*)())0)(); \ 
} while(false) 

int main() 
{ 
CRASH(); 
return 0; 
} 


/*

0;                      /* literal zero */
(0); ( ()0 );                /* 0 being casted to some type */
( (*) 0 );              /* 0 casted some pointer type */
( (*)() 0 );            /* 0 casted as pointer to some function */
( void (*)(void) 0 );   /* Interpret 0 as address of function 
 taking nothing and returning nothing */
( void (*)(void) 0 )(); /* Invoke the function */


*/
