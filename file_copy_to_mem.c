#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MORE_LINES 1024
#define MORE_CHARS 1024

int main() {
FILE* file = fopen("file.txt","r");

if(file == NULL) {
  printf("Error opening file \n");
  return 1;
}

//create a 2d array of chars 
char **lines = (char**) malloc(sizeof(char*) * MORE_LINES);

size_t  total_lines = 0;
size_t total_chars = 0 ;

char c;

do {
 c = fgetc(file);
 if(ferror(file)){
   printf("Error reading file ");
   return 1;
 }
 if(feof(file)){
  //just realloc the last line 
   if(total_chars !=0){
    lines[total_lines] = realloc(lines[total_lines],total_chars+1);
    lines[total_lines][total_chars] = '\0';
    total_lines++;
   }
    break;
 }
 //allocate memory for each line 
 if(total_chars == 0) {
   lines[total_lines] = malloc(MORE_CHARS);
 }
 //store the char
 lines[total_lines][total_chars] = c;
 total_chars++;
 
 //if reached end of current line 
 if(c == '\n') {
  lines[total_lines] = realloc(lines[total_lines],total_chars+1);
  lines[total_lines][total_chars] = '\0' ;
  total_lines++;
  //reset total chars for next line 
  total_chars=0;

  //if need more lines to allocate 
  if(total_lines% MORE_LINES ==0){
    size_t new_size = total_lines+MORE_LINES;
    lines = realloc(lines, sizeof(char*)*new_size);
  } // if more chars are needed
   else if(total_chars%MORE_CHARS == 0){
     size_t new_size = total_chars+MORE_CHARS;
     lines[total_lines] = realloc(lines[total_lines],new_size);
   }
 }



} while(true);

//here we know how many lines are need
  lines = (char**)realloc(lines,total_lines * sizeof(char*));
 
// Output each string/line in the array of strings
  for (size_t i = 0; i < total_lines; i++)
    printf("%s", lines[i]);
  
  // Free the block of memory allocated for each string
  for (size_t i = 0; i < total_lines; i++)
    free(lines[i]);
  
  // Free the block of memory allocated for the array of pointers to chars
  free(lines);
  
  // close the file as we are done working with it
  fclose(file);
}
