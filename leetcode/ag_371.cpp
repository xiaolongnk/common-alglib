#include <iostream>

using namespace std;


class Solution {
public:

    int getSum1(int a, int b)
    {
        return b == 0 ? a :this->getSum1(a^b, (a&b)<<1);
    }

    int getSum(int a, int b) {
        while (b!=0){
            int carry = a & b; 
            a = a^b;          
            b = carry << 1;
        }
        return a;
    }
};


int main()
{
	Solution *s = new Solution();
    cout<<s->getSum1(-1,201)<<endl;
    return 0;
}
