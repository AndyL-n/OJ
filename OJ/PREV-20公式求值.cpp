#include <bits/stdc++.h>
using namespace std;
const long long MOD = 999101;
const int maxn = 1e4 + 6;
typedef long long ll;
ll dp[maxn][maxn];
ll two[maxn];
 
ll mulit(ll a,ll b,ll m) {
    ll ans = 0;
    while(b) {
        if(b & 1)   ans=(ans+a)%m;
        a = (a << 1) % m;
        b >>= 1;
    }
    return ans;
}
 
ll quick_mod(ll a,ll b,ll m) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = mulit(ans,a,m);
        }
        a = mulit(a,a,m);
        b >>= 1;
    }
    return ans;
}
 
ll comp(ll a,ll b,ll m) {
    if(a < b) return 0;
    if(a == b)    return 1;
    if(b > a - b)   b = a - b;
    ll ans = 1,ca = 1,cb = 1;
    for(int i = 0;i < b;i++) {
        ca = ca*(a - i) % m;
        cb = cb*(b - i) % m;
    }
    ans = ca*quick_mod(cb,m - 2,m) % m;
    return ans;
}
 
ll lucas(ll a,ll b,ll m) {
    ll ans = 1;
    while(a && b) {
        ans = (ans*comp(a % m,b % m,m)) % m;
        a /= m;
        b /= m;
    }
    return ans;
}
 
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    memset(dp,0,sizeof dp);
    memset(two,0,sizeof two);
    dp[0][0] = 1;
    two[0] = 1;
    for(int i = 1;i < maxn;i++){
        two[i] = (2*two[i - 1]) % MOD;
    }
    for(int i = 1;i < maxn;i++)
        dp[i][i] = (dp[i][i] + (n - i + 1)*dp[i - 1][i - 1] % MOD) % MOD;
    for(int j = 0;j < maxn;j++)
        for(int i = j + 1;i < maxn;i++)
            dp[i][j] = (dp[i][j] + (j*dp[i - 1][j]) % MOD) % MOD;
    for(int i = 1;i < maxn;i++)
        for(int j = 1;i + j < maxn;j++)
            dp[i + j][j] =  (dp[i + j][j] + ((n - j + 1)*dp[i + j - 1][j - 1]) % MOD) % MOD;
//    for(int i = 0;i < 4;i++){
//        for(int j = 0;j <= i;j++){
//            cout<< " " << dp[i][j];
//        }
//        cout<<endl;
//    }
 
    ll sum = 0;
    for(int i = 0;i <= k;i++){
        sum = (sum + ((ll)(dp[k][i] % MOD)*(two[n - i] % MOD))) % MOD;
    }
    sum = (sum*lucas(n,m,MOD)) % MOD;
    cout<< sum <<endl;
 
 
    return 0;
}
