#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000
#define PB(a)\
push_back(a)

const int Max = 128;
ll a[Max][32] = {0};
ll mat[128][128];
int n;

void solve(){
    REP(i,0,n-2){
        REP(j,i+1,n-1){
            ll num = mat[i][j];
            //cout<<num<<endl;
            for(int k = 0; k < 32; k++){
                if(num&(1<<k)){
                    a[i][k] = a[j][k] = 1;
                }
            }
        }
    }

    REP(i,0,n-1){
        ll temp = 0;
        REP(j,0,31){
            temp += ((1<<j)*a[i][j]);
        }
        cout<<temp<<" ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    REP(i,0,n-1){
        REP(j,0,n-1)cin>>mat[i][j];
    }
    solve();
    return 0;
}
