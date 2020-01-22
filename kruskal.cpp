// Print numbers from 1 to n in lexicographical order
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<pthread.h>
#define f first
#define s second
using namespace std;
typedef long long ll;

#define pb push_back
#define MAX ll(1e9+1)
#define N int(1e5+1)

struct Edge {
public:
	int src, dest, weight;
};

class Graph {
public:
	int V, E;
	Edge* edge;
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
		this->edge = new Edge[E];
	}
};

bool cmp(Edge a, Edge b) {
	return a.weight <= b.weight;
}

int findParent(vector<int> parent, int u) {
	if(parent[u] != u)
		return parent[u] = findParent(parent, parent[u]);
	return u;
}

void Union(vector<int>& parent, vector<int>& rank, int u, int v) {
	int x = findParent(parent, u), y = findParent(parent, v);
	if(rank[x] < rank[y]) {
		parent[x] = y;
		rank[y] += rank[x];
		rank[x] = 0;
	}
	else {
		parent[y] = x;
		rank[x] += rank[y];
		rank[y] = 0;
	}
	return;
}

void MST(Graph* graph) {
	sort(graph->edge, graph->edge+graph->E, cmp);
	int cnt = 0;
	vector<int> rank(graph->V,1), parent(graph->V);
	for(int i = 0 ; i < parent.size() ; i++)
		parent[i] = i;
	for(int i = 0 ; i < graph->E && cnt <= graph->V - 1 ; i++) {
		int u = findParent(parent, graph->edge[i].src), v = findParent(parent, graph->edge[i].dest);
		if(u != v) {
			cout << graph->edge[i].src << ' ' << graph->edge[i].dest << '\n';
			Union(parent, rank, u, v);
			cnt++;
		}
	}
	return;
}

int main() {
	Graph* graph = new Graph(4,5);
	// add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;
    MST(graph);
    return 0;
}
