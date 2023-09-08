#include <bits/stdc++.h>
using namespace std;


#define ff first
#define endl '\n'
#define ss second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define fo(i, a, b) for (int i = a; i < b; i++)
#define foe(i, a, b) for (int i = a; i <= b; i++)

const int MOD1 = 998244353;
const int MOD = 1000000007;
#define INF 1e18
#define PI 3.141592653589793238462

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;


//Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

//Primitive data types
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(double t) {cerr << t;}

//Complex data types
template <class T> void _print(set <T> v);
template <class T> void _print(vector <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<typename F, typename S> ostream& operator <<(ostream& ostream, pair<F, S>& p) { cout << p.first << " " << p.second<<" "; return ostream; }
template<typename T> ostream& operator <<(ostream& ostream, vector<T>& v) { for(auto& element : v) cout << element << " "; return ostream;}
template<typename T> ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v){ for(auto& cell : row) cout << cell << " "; cout << "\n";} return ostream;}
template<typename F, typename S> istream& operator >>(istream& istream, pair<F, S>& p) { cin >> p.first >> p.second; return istream;}
template<typename T> istream& operator >>(istream& istream, vector<T>& v) { for(auto& element : v) cin >> element; return istream; }


void init_code()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
}

bool f=false;
int ans=-123;

void helper(int i,int k,int prev,string s){
    if(i>=s.size())return;
    // debug(prev);
    if(k==0){
        string last=s.substr(i);
        if(stoi(last, nullptr, 2)==prev){
            f=true;
            ans=prev;
        }
        return;
    }
    string temp="";
    for(int j=i;j<s.size();j++){
        temp+=s[j];
        int num=stoi(temp, nullptr, 2);
        debug(num);
        if(num==prev || prev==-1){
            helper(j+1,k-1,num,s);
        }
    }
}

void solve(){
    string s; cin>>s;
    int k; cin>>k;
    helper(0,k-1,-1,s);
    cout<<f<<" "<<ans<<endl;
    return;
    int cnt=0;
    for(char c:s)cnt+=c-'0';
    cnt/=k;
    string ideal="";
    for(int i=s.size()-1;i>=0;i--){
        ideal+=s[i];
        if(s[i]=='1')cnt--;
        if(!cnt)break;
    }
    reverse(all(ideal));
    debug(ideal);
    int j=0;
    while(j<s.size()){
        while(s[j]=='0')j++;
        int i=0;
        while(i<ideal.size() && j<s.size() && s[j]==ideal[i])i++,j++;
        if(i<ideal.size()){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    init_code();

    int t=1;
    // cin>>t;
    while(t--)
    {
     solve(); 
    }

    return 0;
}