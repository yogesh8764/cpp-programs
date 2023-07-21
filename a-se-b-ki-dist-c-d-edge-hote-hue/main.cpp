/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

vector<int> getDistanceArray(map<int,vector<int>> adj_list, int n, int ref){
    vector<int> currentLevel, nextLevel;
    vector<int> visited(n+1, 0);
    vector<int> dist(n+1, 1e9); //ek distance array jisme ref se har ek node ki dist. hogi
   
    currentLevel.push_back(ref);
    visited[ref]=1;
    dist[ref]=0; //ref node zero dist pe rkhtr h 

    while(currentLevel.size()){
        for(auto itr : currentLevel){
            for(auto ngb : adj_list[itr]){
                if(!visited[ngb]){
                    nextLevel.push_back(ngb);
                    visited[ngb]=1;
                    dist[ngb]=dist[itr]+1;
                }
            }
        }
        swap(currentLevel, nextLevel);
        nextLevel.clear();
    }

    return dist;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    map<int,vector<int>> adj_list;
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
       int a, b, c,d; 
       cin>>a>>b>>c>>d;
    
    vector<int> distC =getDistanceArray(adj_list,n,c);
    vector<int> distD =getDistanceArray(adj_list,n,d);
   cout<<min(
   distC[a]+1+distD[b],
   distD[a]+1+distC[b]
    );
    return 0;
}