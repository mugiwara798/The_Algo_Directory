  /*
  Bellman ford is an algorithm used to find the shortest path but edges can have negative weights
  suppose an array dist that stores the shortest path of some node
  if u-v is an edge connects u and v we update v if it will make the shortest path of v better
  but we do that for each edge we have.
  It can be proved that if we run this for n times such that n is the number of nodes that we will have the best answer for each node
  */ 
  #include<bits/stdc++.h>
  #define int long long
  using namespace std;
  vector < pair < int, pair < int, int >>> edges;
  int dist[5000];
  bool is = false;
  void relax() {
    for (int i = 0; i < edges.size(); i++) {
      if (dist[edges[i].second.first] > dist[edges[i].first] + edges[i].second.second) {
        is = true;
        dist[edges[i].second.first] = dist[edges[i].first] + edges[i].second.second;
      }
    }
  }

  int32_t main() {
    int n;
    cin >> n;
    bool del[n];
    vector < int > todel;
    int edge[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        edge[i][j] = 1e9;
    }
    int tmp[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> tmp[i][j];
        edge[i][j] = tmp[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      todel.push_back(x);
    }
    vector < int > ans;

    bool vis[n];
    for (int i = 0; i < n; i++)
      vis[i] = false;
    for (int id = n - 1; id >= 0; id--) {
      int i = todel[id];
      vis[i] = true;
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < n; l++) {
          edge[j][l] = min(edge[j][l], edge[j][i] + edge[i][l]);
        }
      }
      int sum = 0;
      for (int j = id; j < n; j++) {
        for (int l = id; l < n; l++) {
          if (edge[todel[j]][todel[l]] < (int) 1e9)
            sum += edge[todel[j]][todel[l]];
        }
      }
      ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (int i: ans)
      cout << i << " ";
  }
//codeforces problem: https://codeforces.com/contest/295/problem/B