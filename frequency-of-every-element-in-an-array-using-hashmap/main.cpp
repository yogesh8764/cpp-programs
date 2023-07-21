
#include <bits/stdc++.h>
using namespace std;


void freq(){
   int arr[8]={0};
    for(int i=0;i<8;i++){
        cin>>arr[i];
    }
    
    map<int,int> map1;
     for(int i=0;i<8;i++){
         if(! map1[arr[i]])
         map1[arr[i]]=1;
         else
         map1[arr[i]]++;
     }
     for(auto itr: map1){
         cout<<itr.first<<" occurs "<<itr.second<<" times"<<endl;
     }
}
int main()
{
    
freq();
    return 0;
}

