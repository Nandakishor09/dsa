#include <bits/stdc++.h>
using namespace std;

void matrixMethod(int n, int m){
    
    int adj[n + 1][m + 1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

vector<vector<int>> vectorMethod(int n, int m) {
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

vector<int> bfs(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    vector<int> BFS;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        BFS.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return BFS;
}

void dfsHelper(int node, vector<vector<int>> adj, int vis[], vector<int> &DFS){
    vis[node] = 1;
    
    DFS.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfsHelper(it, adj, vis, DFS);
        }
    }
}
vector<int> dfs(int n, vector<vector<int>> adj){
    int vis[n] = {0};
    int start = 0;
    vector<int> DFS;

    dfsHelper(start, adj, vis, DFS);
    
    return DFS;
}

int main() {
    int n, m;

    cout << "Enter no nodes: ";
    cin >> n;

    cout << "Enter no edges: ";
    cin >> m;

    vector<vector<int>> adj = vectorMethod(n, m);

    vector<int> BFS = bfs(n, adj);

    for (int i = 0; i < BFS.size(); i++) {
        cout << BFS[i] << " ";
    }
    cout<<endl;

    vector<int> DFS = dfs(n, adj);

    for(int i = 0; i < DFS.size(); i++){
        cout<< DFS[i] << " ";
    }

    return 0;
}