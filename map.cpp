/*map:这是cpp当中的一种有序关联容器，存储键值对（key,value）,map会按照键的顺序组织元素
#include <map>
using namespace std;
map<long long,int> cnt;
cnt[5]++
cnt[5]++
cnt[3]++
key=3,value=1;
key=5,value=2;
cnt[3]=10;cnt[5]=7;
cout<<cnt[3]<<"\n"
notice: cnt[5]不存在时，map会插入这个键，并且将int类型的值初始化为0;
method：cnt[x]为访问或者插入相应的值。
cnt.find(x)为查找键x,返回迭代器。
  eg:auto it=cnt.find(3);
     if key=3存在，it就指向这个键值对，如果不存在，那么就返回cnt.end();
cnt.count(x)为判断x是否存在，map的值分别为0或者1；
遍历整个map:for(const &auto item:cnt){
  cout<<cnt.first<<cnt.second<<“\n}cnt.first是键，second是值*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n;
    long long c;
    cin>>n>>c;
    vector<long long> a(n);
    long long  num= 0;

    for(int i=0; i< n; i++){
        cin>>a[i];
    }

    map<long long,int> cnt;

    for(int x: a){
        cnt[x]++ ;
    }

    for(int j= 0;j< n; j++){
       long long p =a[j]- c;
       auto it = cnt.find(p);
       if(it ==cnt.end()){
        continue;
       }
       else{
        num += it->second;

       }


    }

    cout<<num<<"\n";
    return 0;




}