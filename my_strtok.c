#include<stdio.h>
#include<string.h>

char *my_strtok(char* s , const char d){
  //static string to remeber the modifications 
   static char* input = NULL;
   
  //initialize the input . for first time 
  if(s!=NULL) input = s;

  //last token
  if(input == NULL) return NULL;

  char *res = new char[strlen(input)+1];
  int i = 0 ;
  for(;input[i]!='\0';i++){
   
    if(input[i]!=d){
      res[i] = input[i];
    } else {
      res[i] = '\0';
      input = input+i+1;  // move the imput string 
      return res;
    }
   
  }
   res[i] = '\0';
   input = NULL;
   return res;

}

int main() {
 char s[] = "aaaaa bbbbb cccccc ddddd eeee";
 char d = ' ';
 char *res ;

 res = my_strtok(s,d);
 if(res){
   printf("%s\n",res);
   delete res;
 }

 while((res = my_strtok(NULL,d))!=NULL) {
   printf("%s\n",res);
   if(res){
     delete res;
    }
 }



 return 0;
}
