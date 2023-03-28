#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int tq, at[N], bt[N], ct[N], tat[N], wt[N], p[N], n;

int32_t main () {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> at[i];
  for (int i = 0; i < n; i++) cin >> bt[i];
  
  vector<vector<int> >v;
  for (int i = 0; i < n; i++) {
    v.push_back({bt[i], at[i], p[i]});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    bt[i] = v[i][0];
    at[i] = v[i][1];
    p[i] = v[i][2];
  }

  int mn = at[0], id;
  
  for (int i = 0; i < n; i++) {
    if(mn > at[i]) {
      mn = at[i];
      id = i;
    }
  }

  
  ct[id] = mn + bt[id];
  int tt = ct[id];

  for (int i = 0; i < n; i++) {
    if(at[i] != mn) {
      ct[i] = bt[i] + tt;
      tt = ct[i];
    }
  }
  
  cout << "P\t\tat\tbt\ttat\twt\t" << endl; 
  int tot_tat = 0, tot_wt = 0;
  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    tot_tat += tat[i];
    wt[i] = tat[i] - bt[i];
    tot_wt += wt[i];
    cout << "p[" << p[i] << "] \t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl; 
  }

  float av_wt = (tot_tat * 1.0)/n, av_tat = (tot_wt * 1.0) / n;

  cout << "average tat = " << av_tat << endl;
  cout << "average wt = " << av_wt << endl;
  
}