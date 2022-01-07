#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    int n = arr.size();
    int i = m+1, j = n-1;
    while (i<=j)
    {
        int temp = arr[i];

        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

}

int main()
{
  std::vector<int> v = {1,2,3,4,5,6}; // sample test case
  reverseArray(v,3);
  for (auto ele : v)
    cout<<ele<<" ";
  return 0;
}
