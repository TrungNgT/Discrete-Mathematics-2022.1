#include <bits/stdc++.h>
using namespace std;

int V, E;
int u[1001], v[1001], w[1001];
vector <int> adj[1001];
bool visited[1001];

void input() {
   cin >> V >> E;
   for(int i=0; i<E; i++) {
      cin >> u[i] >> v[i] >> w[i];
      adj[u[i]].push_back(v[i]);
      adj[v[i]].push_back(u[i]);
   }
}

void dfs(int x) {
   visited[x] = true;
   cout << x << " ";
   for(int y : adj[x]) {
      if(!visited[y]) dfs(y);
   }
}

void ConnectedComponent() {
   int ans = 0;
   memset(visited, false, sizeof(visited));
   for(int i=1; i<=V; i++) {
      if(!visited[i]) {
         ans++; 
         cout << endl;
         dfs(i);
      }
   }
}

int main() {
   input();
   ConnectedComponent();
   return 0;
}