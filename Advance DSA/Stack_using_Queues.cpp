#include<bits/stdc++.h>
using namespace std;


class Stack {
public:
	queue<int> que;
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	void pop() {
		que.pop();
	}

	int top() {
		return que.front();
	}

	bool empty() {
		return que.empty();
	}

    
};

void printStack(Stack st)
    {
       while(!st.empty())
       {
        cout<<st.top()<<endl;
        st.pop();
       }
    } 

int main()
{
    Stack st;
    st.push(1);
    st.push(4);
    st.push(5);
    printStack(st);
    cout<<"Top_Ele:"<<st.top()<<endl;
    st.pop();
    printStack(st);
    cout<<"Top_Ele:"<<st.top()<<endl;

}