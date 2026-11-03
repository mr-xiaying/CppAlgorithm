/*#include <iostream>
using namespace std;

int n,k;
int path[21];
int a[21];
int cnt=0;

void dfs(int step,int start){
    if(step> k){
        int sum= 0;
        for(int i=1;i<= k;++i){
            sum +=path[i];
       }

        if(sum== 2){
            cnt++;
            
        }else if(sum>2){
        int j;
        for(j=2; j*j<= sum- 1; ++j){
            if(sum% j== 0){
                break;
             }
            }
        if(j*j > sum) {
             cnt++;
             }
        }
    
        return;  
    }
    for(int i= start; i<= n;++i){
        path[step] = a[i];
        dfs(step+1,i+1);
        }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<cnt<<" ";
    return 0;
}*/

#include <iostream>
using namespace std;

int n, k;
int a[21];
int path[21];
int cnt = 0;

// 判断一个数是否为质数
bool isPrime(int x) {
    if(x < 2) return false;

    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            return false;
        }
    }

    return true;
}

// DFS 枚举组合
void dfs(int step, int start) {
    if(step > k) {
        int sum = 0;

        // 计算选出的 k 个数之和
        for(int i = 1; i <= k; ++i) {
            sum += path[i];
        }

        // 判断和是否为质数
        if(isPrime(sum)) {
            cnt++;
        }

        return;
    }

    for(int i = start; i <= n; ++i) {
        path[step] = a[i];
        dfs(step + 1, i + 1);
    }
}

int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dfs(1, 1);

    cout << cnt << endl;

    return 0;
}