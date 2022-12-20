
#include<bits/stdc++.h>
using namespace std;


void DFS(vector<int>graph[],vector<int>&visited,int source,int V, int E)
{
   visited[source]=1;
   cout<<source<<"->";
   for(int i=0;i<graph[source].size();i++)
   {
    if(!visited[graph[source][i]])
    {
        DFS(graph,visited,graph[source][i],V,E);
    }
   }
}

int main()
{
    int V;
    cout<<"Enter the number of Vertices: ";
    cin>>V;
    int E;
    cout<<"Enter the number of Edges: ";
    cin>>E;
    vector<int>graph[V+1];


    for(int i=0;i<E;i++)
    {
        int u;
        int v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int source;
    cout<<"Enter the source vertex :";
    cin>>source;

    vector<int>visited(V+1,0);

    //BFS(graph,visited,source);
    //DFS(graph,visited,source);

    //Dikstras Algorithm

    DFS(graph,visited,source,V,E);
    

}