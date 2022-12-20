#include <bits/stdc++.h>
using namespace std;

int KthSorted(vector<int>nums,int n,int k)
{
priority_queue<int,vector<int>,greater<int>> pq;  
for(int i=0;i<nums.size();++i){
		pq.push(nums[i]);
		if(pq.size()>k) pq.pop();
	}
	return pq.top(); 
}


int main()
{
  vector<int>arr={5,1,4,2,3,9,7};
  int k;
  cin>>k;
  cout<<KthSorted(arr,arr.size(),k);
}