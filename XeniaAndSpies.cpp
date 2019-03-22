#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define IREP(i, a, b) \
for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000
#define char_to_int(c)(int(c)-(int)'0')
#define MP(a, b) \
make_pair(a, b)
#define PB(a) \
push_back(a)
#define PI acos(-1)

const int Max = 1e5 + 100;
int n, m, s, f, l, r, st=0, dir;
map<int, ii> watch;
string ans = "";

bool isBlocked(int idx, int pos){
    if(watch.find(idx) != watch.end()){
        l = watch[idx].first; r = watch[idx].second;
        if(pos >= l && pos <= r)return true;
        return false;
    }
    return false;
}

void init(){
    int idx;
    cin>>n>>m>>s>>f;
    REP(i,1,m){
        cin>>idx>>l>>r;
        watch[idx] = MP(l, r);
        st = max(st, idx);
    }
    if(f > s)dir = 1;
    else dir = -1;
}

void solve(){
    int m = s;
    REP(i,1,st){
        if(m == f)return;
        if(isBlocked(i, m))ans.PB('X');
        else if(isBlocked(i, m+dir))ans.PB('X');
        else if(dir == 1){ans.PB('R'); m += 1;}
        else {ans.PB('L'); m -= 1;}
    }
    while(m != f){
        if(dir == 1){ans.PB('R'); m += 1;}
        else {ans.PB('L'); m -= 1;}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    init();
    solve();
    cout<<ans<<endl;
    return 0;
}
