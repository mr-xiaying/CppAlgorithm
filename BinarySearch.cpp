/*二分查找：原理，边界，代码模板
  每次检查中间位置，根据比较结果判断，排除掉不可能包含目标值的一半区间*/
#include <iostream>
using namespace std;

int main(){
  int a[] ={3,7,12,18,25,31,46,59,72,88};
  int target;
  int ans= -1;
  cin>>target;
  int left= 0;
  int right= 9;
  while(left<= right){
    int mid=(left+ right)/2;
    if(a[mid]== target){
      ans= mid;
      break;
    }
    if(a[mid]< target){
      left= mid+1;
    }
    if(a[mid]> target){
      right=mid-1;
    }

  }
  cout<< ans;
  return 0;
}
/*二分查找有两种，第一种是上面的普通的二分查找，
但是他有一个局限性，他只能查找到目标数，但是却并不能保证这个目标数是不是第一个出现的目标数，
所以要是题目出现的是查找最左边（第一个）目标数的时候，应该来采用左边界二分查找法，正如洛谷P2249 */
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int &x:a){
        cin>>x;
    }
    for(int &s:b){
        cin>>s;
        }

    for(int i=0; i< m; ++i){
    int left=0;
    int right=n-1;
    int ans= -1;
    int tg= b[i];

        while(left< right){
            int mid=(left+ right)/2;
            if(a[mid]>= tg){
                right = mid;
            }
            if(a[mid]< tg){
                left =mid+ 1;
            }
         }
        if(a[left] ==tg){ans =left+1;}
        else{ans =-1;}

        cout<<ans<<" ";
    }
    return 0;
  }

  /*P2249《查找》错题复盘

一、题目考查内容

- 二分查找
- 左边界二分（Lower Bound）
- 数组下标与元素值的区别
- 数组越界与边界处理

二、我的错误总结

1. 把 vector 声明成了函数

错误：

vector<int> a();
vector<int> b();

原因：这是函数声明，不是创建 vector 对象。

正确：

vector<int> a(n);
vector<int> b(m);

2. 混淆范围 for 中的元素值和数组下标

错误：

for(int x : a){
    cin >> a[x];
}

原因："x" 是元素值，不是下标。

正确：

for(int &x : a){
    cin >> x;
}

知识点：

- "int x"：复制元素，修改不影响原数组。
- "int &x"：引用元素，修改会影响原数组。
- "const int &x"：引用元素，但不能通过它修改原数组。

3. 没有在每次查询时重置二分边界

错误：把 "left"、"right" 定义在查询循环外部。

原因：上一次查询可能改变边界，影响下一次查询。

正确：每次查询都重新初始化：

for(int i = 0; i < m; ++i){
    int left = 0;
    int right = n - 1;
}

4. 混淆数组下标和元素值

错误：

if(mid > tg)

正确：

if(a[mid] > tg)

原因：

- "mid" 是数组下标。
- "a[mid]" 是数组元素值。
- "tg" 是目标值。

记住：比较目标值时，通常应该比较 "a[mid]" 和 "tg"。

5. 没有考虑重复元素

错误：

if(a[mid] == tg){
    ans = mid;
    break;
}

原因：找到的可能是重复元素中的任意一个，不一定是第一个。

解决方法：使用左边界二分。

while(left < right){
    int mid = left + (right - left) / 2;

    if(a[mid] >= tg){
        right = mid;
    }
    else{
        left = mid + 1;
    }
}

核心思想：

- "a[mid] >= tg"：当前位置可能是答案，继续向左收缩。
- "a[mid] < tg"：答案只能在右边。

6. 混淆赋值和比较

错误：

if(a[left] = tg)

正确：

if(a[left] == tg)

区别：

- "="：赋值。
- "=="：判断是否相等。

7. 数组下标越界

错误：

int tg = b[m];

正确：

int tg = b[i];

原因：长度为 m 的数组，有效下标是 "0 ~ m-1"。

8. 混淆数组下标和题目要求的位置

错误：

ans = left;

正确：

ans = left + 1;

原因：C++ vector 下标从 0 开始，而 P2249 要求输出从 1 开始的位置。

9. 向左扫描的循环条件写反

错误：

for(int p = mid; a[p] != tg; --p)

原因：进入循环时 "a[mid]" 已经等于目标值，循环条件一开始就是 false。

改进：可以用左边界二分，避免额外扫描。

三、最终正确的核心代码

int left = 0;
int right = n - 1;

while(left < right){
    int mid = left + (right - left) / 2;

    if(a[mid] >= tg){
        right = mid;
    }
    else{
        left = mid + 1;
    }
}

if(a[left] == tg){
    ans = left + 1;
}
else{
    ans = -1;
}

四、以后写算法题的自检清单

- [ ] 数组和 vector 是否正确创建？
- [ ] 是否区分下标与元素值？
- [ ] 是否存在数组越界？
- [ ] 多次查询时是否重置变量？
- [ ] 是否考虑重复元素？
- [ ] 是否考虑目标不存在的情况？
- [ ] 是否区分 "=" 和 "=="？
- [ ] 题目要求的下标是从 0 还是从 1 开始？
- [ ] 是否检查最小数据、最大数据和边界数据？

五、本题最重要的收获

算法题不仅要掌握算法思想，还要准确处理边界、下标、数据类型和特殊情况。

这次 P2249 暴露出的主要问题不是二分查找思想，而是 C++ 细节和边界意识。

下一次遇到二分查找，先确认：

1. 普通二分还是左边界/右边界二分？
2. 区间采用什么边界定义？
3. 循环结束后如何验证答案？

        
        


