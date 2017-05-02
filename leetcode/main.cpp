#include "data_structure.h"

using namespace std;
using namespace commonlib;

int main()
{
    vector< int > p = {1,2,3,4,5,6,8};
    for(const auto &x : p){
        cout<<x<<endl;
    }
    CommonMethod::randomShuffle(p);
    for(const auto &x : p){
        cout<<x<<endl;
    }
    return 0;
}

