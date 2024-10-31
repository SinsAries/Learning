#include<bits/stdc++.h>

using namespace std;

// type
using ll = long long;
using ld = long double;
using db = double;
using str = string;

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

// vector
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define sor(x) sort(all(x))
#define rsz resize
#define rtn return

// binary search
#define lb lower_bound
#define ub upper_bound
template<class T> ll lwb(vector<T>& a, const T& b) { rtn lb(all(a), b) - a.begin(); }
template<class T> ll upb(vector<T>& a, const T& b) { rtn ub(all(a), b) - a.begin(); }

// pairs
#define mp make_pair
#define f first
#define s second

// loops
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
#define cont continue
#define bre break

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s) {
    setIn(s+".in"); setOut(s+".out");
}
const int MOD = 1e9 + 7;
const int MX = 3e5+5;
const ll INF = 1e18 + 7;
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// modulo, exponentiation, inverse
ll pow_mod(ll a, ll b, ll m) { ll res = 1; while(b){ res = res * (b & 1 ? a : 1) % m; a = a * a % m; b >>= 1; } rtn res; }
ll inv(ll a, ll m) { rtn pow_mod(a, m - 2, m); }

ll nxt(){
	ll x;
	cin >> x;
	rtn x;
}

string IS_PARENT = "Parent Event";
string IS_CHILD = "IEEE Event";

struct EVENT {
	string eventID;
	string eventTittle;
	string acronyms;
	string projectCode;
	string threeDigitsProjectCode;
	string recordType;
	vl parents;
	void init(string informations) {
		// cout << informations << '\n';
		int i = 0;
		// get eventID
		while(i < sz(informations) && informations[i] != ',')
			eventID.pb(informations[i++]);
		i++;

		// get eventTittle
		i++;
		while(i < sz(informations) && informations[i] != '"')
			eventTittle.pb(informations[i++]);
		i++;

		// get acronyms
		i+= 2;
		while(i < sz(informations) && informations[i] != '"')
			acronyms.pb(informations[i++]);
		i++;

		// get projectCode
		i++;
		while(i < sz(informations) && informations[i] != ',')
			projectCode.pb(informations[i++]);
		i++;
		
		// get threeDigitsProjectCode
		while(i < sz(informations) && informations[i] != ',')
			threeDigitsProjectCode.pb(informations[i++]);
		i++;
		
		// get recordType
		i++;
		while(i < sz(informations) && informations[i] != '"')
			recordType.pb(informations[i++]);
	}
	void print(void) {
		// cout << eventID << "," << '"' << eventTittle << '"' << "," << acronyms << ',' << projectCode << ',' << threeDigitsProjectCode << ',' << recordType;
		cout << eventID << ',';
		cout << '"' << eventTittle << '"' << ',';
		cout << '"' << acronyms << '"' << ',';
		cout << projectCode << ',';
		cout << threeDigitsProjectCode << ',';
		cout << '"' << recordType << '"';;
	}
};

vector<EVENT> events;

void init() {
	string informations;
	while(getline(cin, informations)) {
		EVENT event;
		event.init(informations);
		events.pb(event);
	}
}

bool alive[361];

void solve() {
	each(event, events)
		cout << event.eventID << ';' << event.eventTittle << ';' << event.acronyms << ';' << event.projectCode << ';' << event.threeDigitsProjectCode << ';' << event.recordType << '\n';
	ll N = sz(events);
	F0R(i, N)
		alive[i] = true;

	map<str, bool> isKilled;

	// Any child event without a parent should be eliminated from the output.
	F0R(i, N) if(events[i].recordType == IS_CHILD) {
		F0R(j, N) if(events[j].recordType == IS_PARENT && events[i].acronyms == events[j].acronyms) 
			events[i].parents.pb(j);

		if(sz(events[i].parents) == 0) 
			alive[i] = false;

		// All serialized sets that don't have a unique parent event should be eliminated from the output.
		if(sz(events[i].parents) > 1) {
			alive[i] = false;
			each(p, events[i].parents)
				alive[p] = 0;
			isKilled[events[i].acronyms] = 1;
		}
	}
	
	// Any parent event without children should be exclude from the output.
	F0R(i, N) if(events[i].recordType == IS_PARENT) {
		bool ok = 0;
		F0R(j, N) if(events[j].recordType == IS_CHILD && events[i].acronyms == events[j].acronyms)
			ok = 1;
		if(!ok)
			alive[i] = 0;
	}

	F0R(i, N) if(events[i].recordType == IS_CHILD) {
		each(p, events[i].parents)
			if(events[p].threeDigitsProjectCode == "")
				events[p].threeDigitsProjectCode = events[i].threeDigitsProjectCode;
			else if(events[p].threeDigitsProjectCode != events[i].threeDigitsProjectCode) 
				events[p].threeDigitsProjectCode = "???";
	}

	// Any record with no acronym is eliminated from the output.
	F0R(i, N)
		if(events[i].acronyms == "" || isKilled[events[i].acronyms])
			alive[i] = false;
	
	vector<EVENT> newEvents;
	F0R(i, N)
		if(alive[i])
			newEvents.pb(events[i]);
	sort(all(newEvents), [](EVENT a, EVENT b) {
		if(a.acronyms != b.acronyms)
			return a.acronyms < b.acronyms;
		else {
			if(a.recordType == IS_PARENT)
				return true;
			if(b.recordType == IS_PARENT)
				return false;
			if(a.eventTittle != b.eventTittle)
				return a.eventTittle < b.eventTittle;
			return a.eventID < b.eventID;
		}
	});
	each(event, newEvents) {
		event.print();
		if(event.recordType == IS_CHILD) {
			cout << ',' << events[event.parents[0]].eventID;
		}
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO( "file");
	setIn("file.in");
    
	init();
	solve();

    rtn 0;
}
