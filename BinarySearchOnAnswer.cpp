/*
P2249是先前学过的二分查找，现在学习的是其之应用--二分答案：
   一。不是在数组之中找一个数字，而是在一段答案范围之内寻找满足条件的最优答案
       确定答案的最小值和最大值。
   二。二分答案的核心流程
      1.取中间值 mid。
      2.编写 check(mid)，判断这个答案是否可行。
      3.如果可行，尝试更大的答案。
      4.如果不可行，尝试更小的答案。
      5.不断缩小范围，直到找到最优答答案。
   三。
     普通二分查找：在一组有序数据中寻找目标。
     而二分答案解决的是另一类问题：
     答案范围很大时，通过不断缩小答案范围，寻找满足条件的最大值或最小值。
     例如：
-      木头最多能锯多长？
-      一条路最短需要多长时间才能走完？
-      每个人最多能分到多少资源？
-      完成任务所需的最小速度是多少？
       这些问题往往不是让你在数组中找一个数，而是让你寻找一个最优答案。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> a;

bool check(int H){
    long long sum=0;
    for(int i=0;i< n;++i){
        if(a[i]> H){
            sum += max(0,a[i]-H);
        }
        else{
        sum+=0;}
    }
    if(sum>= m){
        return true;
    }
    else
     return false;
}

int MaxH(vector<int>&a){
    int m=a[0];
    for(int i=1; i< n;++i){
        if(a[i]>m){
            m=a[i];
        }
    }
    return m;
}


int main(){
    cin>>n;
    a.resize(n);
    cin>>m;
    for(int &s:a){
        cin>>s;
    }
    
    int left=0,right=MaxH(a);
    while(left<= right){
        int mid = left + (right - left) / 2;//养成好习惯，防止数值溢出
         if(check(mid)){
            left=mid+1;

         }else{
            right=mid-1;
         }

    }
    if(right>=0){cout<<right<<endl;}
    else{return -1;}

}


/*相关的备注：
  数组下标、循环变量	    int
  元素数量 n	           通常 int
  二分边界和 mid	       根据数据范围，通常 int
  大范围求和	           long long
  可能超过 21 亿的乘法结果	long long
  二分求中点	           left + (right-left)/2
  动态调整 vector 长度	   a.resize(n)

int 有范围限制，计算结果超过范围可能溢出。
long long 主要用于大范围整数计算，尤其是求和和乘法。
vector.resize(n) 会真正改变元素数量，可以让你访问 a[0] 到 a[n-1]。
*/

