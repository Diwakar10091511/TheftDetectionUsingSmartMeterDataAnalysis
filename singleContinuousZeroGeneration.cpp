#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i = a-1; i>=b; i--)
#define ll long long
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
int nxt() {
	int x;
	cin>>x;
	return x;
}
void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void changeIt(vector<vector<double>> &v, int first, int duration) {
	
	int start = first;
	int end = first + duration;

	for(int i = start; i<end; i++) {
		for(int j = 0; j<50; j++)
			v[i][j] = 0;
	}

	return;
}


int main()
{
    setIO("");
    freopen("MeterDataForChangingForContinousZero.txt","r",stdin);
    freopen("singleContinuousZeroGeneration.txt","w",stdout);


	int n;
    cin>>n;
    set<int> meters;
    for(int i = 0; i<n; i++) {
    	int val; cin>>val;
    	meters.insert(val);
    }


    map<int, double[171][50] > mp;
    // cout<<"Meters we changed "<<meters.size()<<endl;
    // for(auto &i: meters)
    // 	cout<<i<<endl;

    // cout<<" Data will be from now on : times , then range "<<endl;


    while(true) {
        int id,day,reading;
        cin>>id>>day>>reading;
        double consumption;
        cin>>consumption;

        if(meters.count(id))
        	mp[id][day-195][reading-1] = consumption;

        if(id == 1998 && day == 365 && reading == 50)
            break;
    }


    for(auto &meter: mp) {
    	int id = meter.first;

    	// we have 171 readings;
    	int times = (rand() % 10) + 1;
    	map<int,int> duration;
    	// cout<<times<<endl;
    	while(times--) {
    		int day =  (rand() % 171);
    		int range = min(7,171 - day);
    		range = (rand()%range) + 1;
    		duration[day] = range;
    		// cout<<day<<" "<<range<<endl;
    	}

    	vector<vector<double>> temp(171, vector<double>(50));

    	for(int i = 0; i<171; i++) {
    		for(int j = 0; j<50; j++) {
    			temp[i][j] = meter.second[i][j];
    		}
    	}


    	for(auto &i: duration) {
    		changeIt(temp,i.first,i.second);
    	}



    	for(int i = 0; i<171; i++) {
    		for(int j = 0; j<50; j++) {
    			cout<<id<<" "<<195+i<<" "<<j+1<<" "<<temp[i][j]<<endl;
    		}
    	}

    }



    

    return 0;
}