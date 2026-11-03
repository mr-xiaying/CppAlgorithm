    /*
1.递归：（1）一个函数在执行的过程之中，调用它自己。
        （2）递归= 递归出口+ 递归调用。
        （3）递归= 深入+ 回溯
             深入；一层一层向下调用函数，问题被不断拆小、
             回溯：最深的问题结束以后，逐层返回上一层，继续执行剩下的代码
        */


/*
DFS深度优先搜索：
  （1）核心思想：沿着一条路径尽可能向深处探索，走不下去时返回上一个状态，尝试其他的路径
   （2）dfs tool:vis[],作为一个数组记录数字是否已经使用
*/

/*例题一：
#include <iostream>
using namespace std;

 void dfs(int n){
    if(n== 0){return;}
    cout<<n<<" ";
    dfs(n-1);
}

int main(){
    dfs(5);
    return 0;

}*/

/*例题二：
#include <iostream>
using namespace std;

void dfs(int n){
    if(n== 0){
        return;}

    cout<<n<<" ";
    dfs(n-1);
    cout<<n*2<<" ";
}
int main(){
    dfs(4);
    return 0;

}*/

/*
dfs的五个步骤：
从第一个位置开始，
遍历数字1到n，
如果数字已经使用->跳过，
如果没有使用->标记vis[i]= true并且继续递归，
递归返回以后就撤销选择*/

/*
例题三：
void dfs(int step){
    if(step== n+1){
        for(int i=1;i<= n; ++i){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    for(int j=1; j<=n; ++j){
        if(vis[j]== false){
            path[step]= j;
            vis[j]= true;
            dfs(step+1);
            vis[j]= false;

        }//for循环的根本目的是为了往path数组里面塞东西，而不是为了确定path数组的下标
    }
}*/
/*郑重声明一个东西：
  path[i]:第i个位置放了那个数字
  vis[j]:数字j有没有被使用过*/


/*
例题四；
#include <iostream>
using namespace std;

int n;
int path[20];

void dfs(int step) {
    // 递归出口
    if (step == n + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << path[i];
        }
        cout << endl;
        return;
    }


    // 当前的位置尝试 0 和 1
    for (int k = 0; k <= 1; ++k) {
        path[step] = k;

        // 进入下一层
        dfs(step + 1);
    }//for循环的根本目的是通过遍历往里面塞东西，而不是确定path数组的下标
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}//甚至可以按照字典顺序输出 */


//网格dfs经典的数水洼的问题
#include <iostream>
using namespace std;

   int n,m;
    int ans=0;
  char a[105][105];
    
void dfs(int x, int y){
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    if(x>= n|| y>=m||x< 0||y< 0){
        return ;
    }
    if(a[x][y]!='W'){
        return ;
     }
    a[x][y]='.';
    for(int k=0;k< 8;++k){
    int nx= x+dx[k];
    int ny= y+dy[k];
        dfs(nx,ny);
    }
    
}

int main(){
    cin>>n>>m;
    for(int i=0;i< n;++i){
        for(int j=0;j< m; ++j){
            cin>> a[i][j];
        }
    }
 
    for(int i=0;i< n;++i){
        for(int j=0;j< m; ++j){
         if(a[i][j]== 'W'){
            ans++;
             dfs(i,j);}
        }
        
    }
    cout<<ans<<" ";
    return 0;
    
}