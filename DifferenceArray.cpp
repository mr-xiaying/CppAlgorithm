//差分数组
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a{0,4,7,2,9,5,3};
    vector<int> b(8,0);
    vector<int> sum(7,0);

    for(int i=1; i<=6; ++i){
        b[i]= a[i]- a[i-1];
    }

    int p;
    cin>>p;

    for(int j=1;j<=p;++j){
        int l,r,num;
        cin>>l>>r>>num;
        b[l] += num;
        b[r+1] -=num;
    }

    for(int k=1;k<=6;k++){
        sum[k]= sum[k-1] +b[k];
        cout<<sum[k]<<"\n";
    }

    return 0;

    




}