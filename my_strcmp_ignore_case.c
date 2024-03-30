#include<stdio.h>
#include<string.h>

int my_strcmp(char* s1, char*s2) {

int i = 0 ;
for(;s1[i] && s2[i];++i) {
 if(s1[i]==s2[i] || ((s1[i]^32) == s2[i]) ){    // by inverting 6th bit lowe becomes upper anc vmye versa 
   continue;  
 } else break;

 }

 if(s1[i]==s2[i]) return 0 ;

  if( (s1[i]|32) < (s2[i]|32) ) 
     return -1;
  
  return 1;
}

int main(void)
{
    printf("ret: %d\n", my_strcmp("Geeks", "apple"));
    printf("ret: %d\n", my_strcmp("", "ABCD"));
    printf("ret: %d\n", my_strcmp("ABCD", "z"));
    printf("ret: %d\n", my_strcmp("ABCD", "abcdEghe"));
    printf("ret: %d\n", my_strcmp("GeeksForGeeks", "gEEksFORGeEKs"));
    printf("ret: %d\n", my_strcmp("GeeksForGeeks", "geeksForGeeks"));
    return 0;
}
