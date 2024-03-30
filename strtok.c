/// need to use string in array form , mutable form , nota pointer to string literal 
 str points to a string literal, which is read-only. When strtok is called, it tries to insert '\0' characters into the string to tokenize it, 
but since the string is read-only, it cannot be modified, and the program may crash.



   #include <stdio.h>
   #include <string.h>
   
   int main() {
   
   char s[] = "aaabbb ccc dddd eeee fff gggg";
   char *tok ;
   
   tok = strtok(s," ");
  
  while(tok!=NULL) {
   printf("%s \n",tok);
   tok = strtok(NULL," ");
 }
  return 0;
}
