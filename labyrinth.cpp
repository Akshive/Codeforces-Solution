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
#define EPS 1e-6
#define char_to_int(c)((int)c-(int)'A')
#define PB(a)\
push_back(a)
#define MP(a, b)\
make_pair(a, b)

char mat[2048][2048];
int dist[2048][2048];
int n, m, r, c, x, y;

void bfs(){
    dist[r][c] = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(MP(0, MP(r, c)));
    while(!pq.empty()){
        int w = pq.top().first, u = pq.top().second.first, v = pq.top().second.second;
        pq.pop();
        if(w > dist[u][v])continue;
        if(v > 1 && mat[u][v-1] != '*' && dist[u][v-1] > dist[u][v] + 1){
            dist[u][v-1] = dist[u][v] + 1;
            pq.push(MP(dist[u][v-1], MP(u, v-1)));
        }
        if(v < m && mat[u][v+1] != '*' && dist[u][v+1] > dist[u][v]){
            dist[u][v+1] = dist[u][v];
            pq.push(MP(dist[u][v+1], MP(u, v+1)));
        }
        if(u > 1 && mat[u-1][v] != '*' && dist[u-1][v] > dist[u][v]){
            dist[u-1][v] = dist[u][v];
            pq.push(MP(dist[u-1][v], MP(u-1, v)));
        }
        if(u < n && mat[u+1][v] != '*' && dist[u+1][v] > dist[u][v]){
            dist[u+1][v] = dist[u][v];
            pq.push(MP(dist[u+1][v], MP(u+1, v)));
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

    cin>>n>>m>>r>>c>>x>>y;
    REP(i,1,2047)REP(j,1,2047)dist[i][j] = INF;
    REP(i,1,n)REP(j,1,m)cin>>mat[i][j];
    bfs();
    int cnt = 0;
    REP(i,1,n){
        REP(j,1,m){
            if(mat[i][j] != '*'){
                int l_d = dist[i][j], r_d = l_d+j-c;
                if(l_d <= x && r_d <= y)cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
