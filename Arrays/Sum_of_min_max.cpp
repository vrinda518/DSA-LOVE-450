#include<bits/stdc++.h>
using namespace std;

int sumOfMaxMin(vector<int> &arr){
	// Write your code here.

    int min_ele = INT_MAX, max_ele = INT_MIN;

    for (int ele : arr)
    {
        if (ele<min_ele)
            min_ele = ele;
        if (ele>max_ele)
            max_ele = ele;
    }

    return  min_ele+max_ele;
}

int main()
{
  std::vector<int> v = {2,3,4,5,6,7,10}; // sample test case
  int ans = sumOfMaxMin(v);
  cout<<ans;
  return 0;
}
