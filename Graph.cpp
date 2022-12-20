//adjacency list in a graph.
//Directed Graph

#include<bits/stdc++.h>
using namespace std;


// void BFS(vector<int>graph[],vector<int>&visited,int source)
// {
   
// }

// void DFS(vector<int>graph[],vector<int>&visited,int source)
// {
//    visited[source]=1;
//    cout<<source<<"->";
//    for(int i=0;i<graph[source].size();i++)
//    {
//     if(!visited[graph[source][i]])
//     {
//         DFS(graph,visited,graph[source][i]);
//     }
//    }
// }


void Dikstras(vector<pair<int,int>>graph[],int V,int E,int source,vector<int>dist)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    dist[source]=0;

    //Pq contains distance,vertex name;
    pq.push({0,source});

    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int d=p.first;
        int u=p.second;

        for(auto i=0;i<graph[u].size();i++)
        {
            //vertex v and its weight.
            int v=graph[u][i].first;
            int weight=graph[u][i].second;
            
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }


    printf("Vertex Distance from Source\n");
    for (int i = 0; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    

}


int main()
{
    int V;
    cout<<"Enter the number of Vertices: ";
    cin>>V;
    int E;
    cout<<"Enter the number of Edges: ";
    cin>>E;
    vector<pair<int,int>>graph[V+1];


    for(int i=0;i<E;i++)
    {
        int u;
        int v,w1;
        cin>>u;
        cin>>v>>w1;
        graph[u].push_back({v,w1});
    }
    
    int source;
    cout<<"Enter the source vertex :";
    cin>>source;

    vector<int>dist(V+1,INT_MAX);

    //BFS(graph,visited,source);
    //DFS(graph,visited,source);

    //Dikstras Algorithm

    Dikstras(graph,V,E,source,dist);

    

}