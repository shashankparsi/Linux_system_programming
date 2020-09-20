#include<stdio.h>
#include<stdlib.h>

int factorial(unsigned int loop)
{
if(loop==1){
return 1;}
return (loop)*factorial(loop-1);
}
int main(int argc,char **argv)
{
unsigned int loop=50;
if(argc==2)
{
loop=atoi(argv[1]);
}
while(loop--)
{
//factorial(loop);
printf("factorial of %d is %u\n",loop,factorial(loop));
}
return 0;
}
