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

int n, m;
string ans = "";
bool is = 1;
void fn(int prev1, int prev2){
    if(n == 0 && m == 0)return;
    if(prev2 == 0){
        if(m == 0){is = 0; return;}
        ans.PB('1');
        m -= 1;
        prev1 = prev2; prev2 = 1;
        fn(prev1, prev2);
    }
    else{
        if(prev1 == 1){
            if(n == 0){is = 0; return;}
            ans.PB('0');
            n -= 1;
            prev1 = prev2; prev2 = 0;
            fn(prev1, prev2);
        }
        else{
            if(m > n){
                ans.PB('1');
                m -= 1;
                prev1 = prev2; prev2 = 1;
                fn(prev1, prev2);
            }
            else{
                ans.PB('0');
                n -= 1;
                prev1 = prev2; prev2 = 0;
                fn(prev1, prev2);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;
    if(m > n){ans.PB('1'); m -= 1; fn(-1, 1);}
    else{ans.PB('0'); n -= 1; fn(-1, 0);}
    if(is)cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
