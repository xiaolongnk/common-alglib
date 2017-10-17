#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int sum = (C - A) * (D - B) + (G - E) * (H - F);
            if (G <= A || C <= E || H <= B || D <= F) return sum;
        }
};

int main()
{
    return 0;
}
