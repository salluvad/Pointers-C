#include<stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

int x = 0x12345678;

char buffer[100];

memcpy(buffer ,&x , sizeof(x));
int i ;
for(i = 0 ; i< sizeof(int);i++){
   printf("%02hhX ",buffer[i]);
}
//intel uses little endian , Network has Big endian 

printf("\n");
int y = htonl(x);
memcpy(buffer ,&y , sizeof(y));
for(i = 0 ; i< sizeof(int);i++){
   printf("%02hhX ",buffer[i]);
}

printf("\n");
}
