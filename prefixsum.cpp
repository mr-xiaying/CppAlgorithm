/*前缀和的核心思想是 提前算好从开头到每个位置的累计和，以后查询区间时，就不必重新遍历区间
前缀和数组：sum[i]= a[0] */
#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n+1];
  int sum[n+1]={0};

  for(int i= 1;i<= n ;++i){
    cin>>a[i];
    sum[i]= sum[i-1]+ a[i]; 
  }

  int p;
  cin>>p;

  for(int j= 1;j= p;++j){
    int l;
    int r;
    cin>>l>>r;
    cout<<sum[r]- sum[l-1]<<"\n";

  }
 return 0;}