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

int n, a, b, k;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    cin>>n>>a>>b>>k;
    cin>>s;
    int cnt = 0;
    int cont = 0;
    vi temp;
    REP(i,0,n-1){
        if(s[i] == '0')cnt++;
        else cnt = 0;
        if(cnt == b){cnt = 0; cont++; temp.PB(i);}
    }
    //cout<<cont<<endl;
    int ans = cont - (a - 1);
    cout<<ans<<endl;
    REP(i,0,ans-1){
        cout<<temp[i]+1<<" ";
    }
    return 0;
}
