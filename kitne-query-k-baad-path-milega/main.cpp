/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

bool path_milega(vector<vector<int>> &given, int n,int m){
    if(given[n][m]==1 and given[1][1]=1) return false
    
    vector<vector<int>> visited(n+1,vector<int>(m+1,0));
    vector<pair<int,int>> current,next;
    current.push_back({1,1});
    visited[1][1]=1;
    while(visited.size()){
        for(auto itr:current){
        int x=itr.first;
        int y=itr.second;
        if(x+1<=n and visited[x+1][y]==0 and given[x+1][y]!=1){
            next.push_back({x+1,y});
            visited[x+1][y]=1;
        }
        if(y+1<=n and visited[x][y+1]==0 and given[x][y+1]!=1){
            next.push_back({x,y+1});
            visited[x][y+1]=1;
        }
         if(x-1>=1 and visited[x-1][y]==0 and given[x-1][y]!=1){
            next.push_back({x-1,y});
            visited[x-1][y]=1;
        }
         if(y-1>=1 and visited[x][y-1]==0 and given[x][y-1]!=1){
            next.push_back({x,y-1});
            visited[x][y-1]=1;
        }
    }
    swap(current,next);
    next.clear();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

     int q;
    cin>>q;
    vector<pair(int,int)> query(q+1,0);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        query[i]={x,y};
        cout<<endl;
    }
    
    int lo=1;
    int hi=q;
    int ans=-1;
    vector<vector<int>> given(n+1,vector<int>(m+1,1))
    
    while(lo<=hi){
        int mid=(lo+hi)/2;
         for(int i=0;i<mid;i++){
            given[queries[i].first][queries[i].second]=0;
        }
        if(path_milega(given,n,m)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}