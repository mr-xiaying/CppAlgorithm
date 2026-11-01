/*cpp允许用户自行定义数据结构
int (*ap)[10] =&arr;//定义一个指针指向这个数组
int (&bp)[10] =arr;//定义一个引用，或者说给原来的数组起一个别名
cpp严格来说并没有多维数组，所谓的多维数组其实是数组的数组
sort(),排序函数
int a[5]= {2,4,3,9,7}
sort(a,a+5)//其为左闭右开区间*/
#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    string name;
    int score;
}

bool Gcmp(student a,student b){
    return a.score> b.score;
}

bool cmp(int a,int b){
    return a>b;

}//这是自己定义的函数，也是后面sort()排序的规则

int main(){
    int a[5]= {2,4,3,9,7};
    sort(a,a+5,cmp);
    for(int i=0;i!=5;++i){
        cout<<a[i]<<endl;
    }
    return 0;
}