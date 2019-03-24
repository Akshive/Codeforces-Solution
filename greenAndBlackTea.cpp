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

int n, k;
int cnt[2] = {0};
string ans = "";
bool is = 1;

char fn2(int x){
    if(x == 0)return 'G';
    return 'B';
}

void fn(int prev, int prev_cnt){
    if(ans.size() == n)return;
    if(prev_cnt == k){
        if(cnt[1-prev] == 0){
            is = 0;
            return;
        }
        ans.PB(fn2(1-prev));
        cnt[1-prev] -= 1;
        fn(1-prev, 1);
    }
    else{
        if(cnt[prev] > cnt[1-prev]){
            ans.PB(fn2(prev));
            cnt[prev] -= 1;
            fn(prev, prev_cnt+1);
        }
        else{
            ans.PB(fn2(1-prev));
            cnt[1-prev] -= 1;
            fn(1-prev, 1);
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

    cin>>n>>k>>cnt[0]>>cnt[1];

    if(cnt[0] > cnt[1]){
        cnt[0] -= 1;
        ans.PB('G');
        fn(0, 1);
    }
    else{
        cnt[1] -= 1;
        ans.PB('B');
        fn(1, 1);
    }

    if(is)cout<<ans<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
