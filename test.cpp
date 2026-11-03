//判断和是不是质数的排列组合问题
#include <iostream>
using namespace std;
int n,r;
int path[25];
int sum=0;
void dfs(int step,int start){
    if(step>r){
        for(int i=1;i <=r; i++){
            sum += path[i];
            
        }if()
        cout<<sum<<endl;
    }
    for(int i= start; i <= n;++i){
        path[step]= i;
        dfs(step+1,i+1);
    }
}

int main(){
    cin>>n>>r;
    dfs(1,1);
    return 0;
}