#include <bits/stdc++.h>
using namespace std;

int Sum_(int i,int arr[])
{
  if(i<0)
  return 0;

  return arr[i]+Sum_(i-1,arr);
}


int main()
{
  int arr[]={5,1,4,2,3,9,7};
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<Sum_(size-1,arr);
}