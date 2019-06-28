#include <stdio.h>  
#include <string.h>

int main (void)
{    
   // Массив с исходной строкой
   char str [11]="0123456789";

   //Определение длины строки и вывод результата на консоль
   printf ("Длина строки %s - %d символов\n", str, strlen (str) );

   return 0;
}