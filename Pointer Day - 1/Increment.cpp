#include <bits/stdc++.h>
using namespace std;

void Increment(int* ptr)
{
 
  *ptr=*ptr+1;
  cout<< *ptr<<endl;

  
}


int main()
{
  int n;
  cin>>n;

  int *ptr=&n;
  Increment(ptr);
  cout<<n<<endl;
  cout<<*ptr<<endl;
}