/***
 * solve hannio problems.
 * fibbnico problesm
 * 斐波那契数列（Fibonacci sequence），又称黄金分割数列、因数学家列昂纳多·斐波那契（Leonardoda Fibonacci）以兔子繁殖为例子而引入，故又称为“兔子数列”，指的是这样一个数列：1、1、2、3、5、8、13、21、34、……在数学上，斐波纳契数列以如下被以递归的方法定义：F(0)=0，F(1)=1, F(n)=F(n-1)+F(n-2)（n>=2，n∈N*）在现代物理、准晶体结构、化学等领域，斐波纳契数列都有直接的应用，为此，美国数学会从1963起出版了以《斐波纳契数列季刊》为名的一份数学杂志，用于专门刊载这方面的研究成果。*
 * recursive exercise.
 * 汉诺塔：汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
 *
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void fib_value(int n)
{
    if( n <= 2) return 1;
    return fib_value(n-1) + fib_value(n - 1);
}

void hanio(char a,char b, char c,int n)
{
    if( n==1 )  cout<<a<<" => "<<c<<endl;
    else{
        hanio(a,c,b,n-1);
        cout<<a<<" => "<<c<<endl;
        hanio(b,a,c,n-1);
    }
}

int main()
{
    cout<<"Please input your n:"<<endl;
    int plate_num;
    scanf("%d",&nn);
    hanio('A','B','C',nn);
    return 0;
}

