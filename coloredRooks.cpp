#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define IREP(i, a, b)\
for(int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 1000000000
#define CLR(a) memset(a, 0, sizeof(a))
#define RESET(a) memset(a, -1, sizeof(a))
#define MP(a,b) make_pair((int)a, (int)b)
#define MP2(a,b,c) make_pair((int)a, make_pair((int)b, (int)c))
#define EPS 1e-6
#define char_to_int(c)((int)c-(int)'A')
#define PB(a)\
push_back(a)


int n, m, idx = 1;
vi AdjList[128];
bool mat[2048][128] = {0};
int cnt[128] = {0};

void solve(int u){
    TRvi(AdjList[u], v){
        if(*v > u){
            cnt[u] += 1; cnt[*v] += 1;
            mat[idx][u] = mat[idx][*v] = 1;
            idx++;
        }
    }
    if(!cnt[u]){mat[idx++][u] = 1; cnt[u] += 1;}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;
    int u, v;
    REP(i,1,m){
        cin>>u>>v;
        AdjList[u].PB(v);
        AdjList[v].PB(u);
    }

    REP(i,1,n){
        solve(i);
    }
    REP(j,1,n){
        cout<<cnt[j]<<endl;
        REP(i,1,2047)if(mat[i][j])cout<<i<<" "<<j<<endl;
    }
    return 0;
}
