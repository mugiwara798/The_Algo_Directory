#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int> >& edges, vector<double>& succProb, int start, int end) {
        vector<double> pro(n + 1, 0);
        
        vector<pair<int, double>> adj[n + 1];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pro[start] = 1;
        pq.push({1, start});
        while (!pq.empty()) {
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            for (auto it : adj[node]) {
                if (pro[it.first] < (it.second * pro[node])) {
                    pro[it.first] = (it.second * pro[node]);
                    pq.push({pro[it.first], it.first});
                }
            }
        }
        return pro[end];
    }
};

// Define the main function to read inputs, call the answer function, and print the result
int main() {
    int n, start, end;
    vector<vector<int>> edges;
    vector<double> succProb;

    // Read inputs
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (int i = 0; i < n; i++) {
        double p;
        cin >> p;
        succProb.push_back(p);
    }

    cin >> start >> end;

    // Create an instance of the Solution class
    Solution solution;

    // Call the maxProbability function and print the result
    double result = solution.maxProbability(n, edges, succProb, start, end);
    cout << "Maximum Probability: " << result << endl;

    return 0;
}

// leetcode question : https://leetcode.com/problems/path-with-maximum-probability/description/?envType=list&envId=53js48ke




