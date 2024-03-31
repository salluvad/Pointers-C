#include <stdio.h>

typedef struct {
 char type;
 char name[50];
 int age ;
 double avg;
}Student ;

int main() {

 FILE *fp = fopen("record.txt","r");
 if(fp == NULL) {
  printf("Error reading file");
  return 1;
 }
 Student students[100];

 //read count for error checkings

 int read = 0 ;

 int records = 0 ;

 do {
  read = fscanf(fp,
                 "%c, %49[^,],%d,%lf \n",
                 &students[records].type,
                 students[records].name,
                 &students[records].age,
                 &students[records].avg
                 );

   //check if we read 4 values 
  if(read == 4 ) records++;

  if(read !=4 && !feof(fp)){
    printf("File format incorrect");
    return 1;
  }
  if(ferror(fp)){
    printf("Error reading file");
    return 1;

  }
 } while(!feof(fp));
 // close the file as we are done working with it
  fclose(fp);
  
  // print out the number of records read
  printf("\n%d records read.\n\n", records);
  
  // print out each of the records that was read 
  for (int i = 0; i < records; i++)
    printf("%c %s %d %.2f\n", 
           students[i].type, 
           students[i].name,
           students[i].age,
           students[i].avg);
  printf("\n");

  return 0;

}
