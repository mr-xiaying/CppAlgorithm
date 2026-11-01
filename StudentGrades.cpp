#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    long id;
    int grades;
};

bool cmp(student a,student b){
   if(a.grades!= b.grades){return a.grades>b.grades;}
   return a.id< b.id;

}

int main(){
    student s[4]= {
        {1003,90},
        {1001,95},
        {1002,90},
        {1004,95},
    };

    sort(s,s+4,cmp);

    for(int i=0; i!= 4;++i){
        cout<<s[i].id<<" "<<s[i].grades<<"\n"<<endl;
    }

    return 0;
}