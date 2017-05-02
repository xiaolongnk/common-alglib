#include "data_structure.h"

_NAMESPACE_COMMONLIB_START

TreeNode * CommonMethod::getSampleTree()
{
    return NULL;
}

vector<int> CommonMethod::getSampleVector()
{
    vector<int> p;
    for(int i = 0 ; i < 10; ++i) {
        p.push_back(i);
    }
    CommonMethod::randomShuffle(p);
    return p;
}

ListNode * CommonMethod::getSampleLinkList()
{
    ListNode * head = null;
    return 0;
}

void CommonMethod::randomShuffle(vector<int> & p)
{
	for(int i=0; i<p.size() -1; i++)
	{
		int temp = rand()%(p.size() - 1);
		swap(p[p.size() -i -1],p[temp]);
	}
}

bool CommonMethod::checkOrder(const vector<int>&p)
{
	for(int i=0; i<p.size() - 1; i++)
		if(p[i]>p[i+1]) return false;
	return true;
}

_NAMESPACE_COMMONLIB_END

