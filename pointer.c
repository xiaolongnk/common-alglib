#include <stdio.h>
#include <stdlib.h>

typedef int (* funcType) (int); /*定义一个函数指针的类型*/

int func (int);  /*函数指针*/
int func_test(funcType fp , int); /*用函数指针作为参数*/


int func(int a)
{
    return a+1;
}

int func_test(funcType fp , int a)
{
    return fp(a);
}

int main()
{
    int abc = 100;
    /*定义一个函数指针，指向一个函数。函数名本质上是一个指针常量*/
    funcType hello = func;
    int dd = (*hello)(abc);
    printf("value of variable dd  is %d\n",dd);
    abc = func_test(func , abc);
    printf("%d\n",abc);
    return 0;
}

