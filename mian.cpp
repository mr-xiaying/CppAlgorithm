//类似于指针类型，迭代器也提供了对对象的间接访问。其之对象是容器当中的元素或者string当中的字符
//如果两个迭代器指向的元素都相同或者是同一个容器的尾后迭代器，则其相等
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s("some string");
    if(s.begin() != s.end()){//确保s非空
        auto it =s.begin();
        *it = toupper(*it);
    }

    for(auto it=s.begin();it != s.end()&& it != isspace(*it);++it){
        *it = toupper(*it);
    }

    //箭头运算符“ ->”,它把解引用和成员访问两个操作结合在一起
    for(auto it= text.cbegin(); it!= text.cend()&& !it->empty(); ++it){
        count<<*it<<endl;
    }
}