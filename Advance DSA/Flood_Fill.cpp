#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int y,vector<vector<int>>&image,int &color,vector<vector<int>>&visited)
    {
        
        visited[x][y]=1;
        if(y-1>=0 and visited[x][y-1]!=1 and image[x][y-1]==image[x][y])
        dfs(x,y-1,image,color,visited);
        
        if(y+1<image[0].size() and visited[x][y+1]!=1 and image[x][y+1]==image[x][y])
        dfs(x,y+1,image,color,visited);
        
        if(x+1<image.size() and visited[x+1][y]!=1 and image[x+1][y]==image[x][y])
        dfs(x+1,y,image,color,visited);
        
        if(x-1>=0 and visited[x-1][y]!=1 and image[x-1][y]==image[x][y])
        dfs(x-1,y,image,color,visited);
        
        image[x][y]=color;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        dfs(sr,sc,image,color,visited);
        return image;
    }


int main()
{
    vector<vector<int>>image={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1;
    int sc=1;
    int color=2;
    vector<vector<int>>ans=floodFill(image,sr,sc,color);

    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}