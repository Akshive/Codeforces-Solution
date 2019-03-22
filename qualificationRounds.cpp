#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
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
#define abs 1e-6
#define char_to_int(c)(int(c)-(int)'0')
#define MP(a, b) \
make_pair(a, b)
#define PB(a) \
push_back(a)
#define PI acos(-1)

int n, m;
map<int, bool> mp;

void init(){
    cin>>n>>m;
    REP(i,1,n){
        int t = 1, tot = 0, p = 1;
        REP(j,1,m){
            cin>>t;
            tot += t*p;
            p *= 2;
        }
        mp[tot] = 1;
    }
}

bool solve(){
    int mask, lim = (1<<m);
    for(auto it = mp.begin(); it != mp.end(); it++){
        mask = it->first;
        //cout<<mask<<": ";
        if(mask == 0)return true;
        for(int i = 1; i < lim; i++){
            //cout<<mask<<"_"<<i<<"_"<<((mask&i)==0)<<" ";
            if((mp.find(i) != mp.end()) && ((mask&i) == 0))return true;
        }//cout<<endl;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    init();
    /*for(auto it = mp.begin(); it != mp.end(); it++){
        int mask = it->first;
        cout<<mask<<endl;
    }*/
    if(solve())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
