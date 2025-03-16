//we use var_args

int my_printf(const char *format , ... ) {

  va_list args ;
  va_start(args , format);
  while (*format ) {
    if(*format = '%') {
       format++;
       //type of data 
      if (*format == 'd') {  // Integer format specifier
        int num = va_arg(args, int);
        printf("%d", num);  // Print integer.   /// >>> you can write your own print int fucntion or use vprintf
        
      } else if (*format == 's') {  // String format specifier
        char *str = va_arg(args, char*);
        printf("%s", str);  // Print string
      } else {
        // If we encounter an unsupported format specifier, print the '%'
        putchar('%');
        putchar(*format);
      }
      
     } else {
      putchar(*format); 
    }
     format ++;
  }
   va_end(args);
}




int main() {
    int age = 25;
    char name[] = "Alice";

    // Test the custom printf function
    my_printf("Hello, my name is %s and I am %d years old.\n", name, age);
    my_printf("Here is another number: %d\n", 42);
    
    return 0;
}
