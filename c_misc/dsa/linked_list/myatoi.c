#include<stdio.h>
int myatoi(const char *string);
int main(int argc, char* argv[])
{
 printf("\n%d\n", myatoi("1998"));
 return(0);
}
int myatoi(const char *string)
{
 int i;
 i=0;
 while(*string)
 {
 i=(i<<3) + (i<<1) + (*string - '0');
 string++;
 // Dont increment i!
 }
 return(i);
} 
