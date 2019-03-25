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

const int Max = 64;
int n, k;
string responses[Max];
string names[Max];

string ans[Max];

void genNames(){
    string temp = "abcdef";
    int i = 0;
    do{
        if(i >= Max)return;
        string temp2 = (char)toupper(temp[0]) + temp.substr(1, 5);
        names[i++] = temp2;
    }while(next_permutation(temp.begin(), temp.end()));
}

void solve(){
    int idx = 0;
    REP(i,0,k-2){
        ans[i] = names[idx++];
    }
    REP(i,k-1,n-1){
        if(responses[i-k+1] == "YES"){
            ans[i] = names[idx++];
        }
        else{
            ans[i] = ans[i-k+1];
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

    cin>>n>>k;
    REP(i,0,n-k)cin>>responses[i];

    genNames();
    //REP(i,0,Max-1)cout<<names[i]<<endl;
    solve();
    REP(i,0,n-1)cout<<ans[i]<<" ";
    return 0;
}
