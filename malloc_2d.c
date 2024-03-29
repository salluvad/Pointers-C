#include<stdio.h>
#include <stdlib.h>
int main () {
int r= 3;
int c = 3;

int** matrix;

matrix = (int**) malloc(r*sizeof(int*));

int i,j ;
for(i=0;i<3;i++)
   matrix[i] = (int*)malloc(3*sizeof(int));

for(i=0;i<3;i++)
   for(j=0;i<3;i++)
    matrix[i][i] = i+j;

for(i=0;i<3;i++) {
   for(j=0;j<3;j++  ) {
    printf("%d  ", matrix[i][i]);
    }
    printf("\n");
}
for(i=0;i<3;i++)
   free(matrix[i]);

free(matrix);

return 0;
}
