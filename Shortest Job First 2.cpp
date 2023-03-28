#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int tq, at[N], bt[N], ct[N], tat[N], wt[N], p[N], n;

int32_t main () {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> bt[i];
  
  vector<vector<int> >v;
  for (int i = 0; i < n; i++) {
    v.push_back({bt[i], p[i]});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    bt[i] = v[i][0];
    p[i] = v[i][1];
  }
  
  cout << "P\t\tbt\ttat\twt\t" << endl; 
  int tot_tat = 0, tot_wt = 0;

  for (int i = 0; i < n; i++) {
    wt[i] = 0;
    tat[i] = 0;
    for (int j = 0; j < i; j++) {
      wt[i] += bt[j];
    }
    tat[i] = wt[i] + bt[i];
    tot_wt += wt[i];
    tot_tat += tat[i];
    
    cout << "p[" << p[i] << "] \t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl; 
  }

  float av_wt = (tot_tat * 1.0)/n, av_tat = (tot_wt * 1.0) / n;

  cout << "average tat = " << av_tat << endl;
  cout << "average wt = " << av_wt << endl;
  
}