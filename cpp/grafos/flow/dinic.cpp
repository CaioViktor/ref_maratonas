struct edge {
	int x, y, c, c0, r;
};

vector<edge> E;
VVI G;

int flow(int s, int t) {
	for (int f = 0;;) {
		VI prev(G.size(), -1);
		queue<int> q;

		q.push(s); prev[s] = 0;
		while (!q.empty() && prev[t] < 0) {
			int x = q.front(); q.pop();
			for (int i = 0; i < (int)G[x].size(); i++) {
				int e = G[x][i], y = E[e].y;
				if (E[e].c == 0 || prev[y] >= 0) continue;
				prev[y] = e;
				q.push(y);
			}
		}

		if (prev[t] < 0)
			return f;

		int c = INF;
		for (int x = t; x != s; x = E[prev[x]].x)
			c = min(c,E[prev[x]].c);

		for (int x = t; x != s; x = E[prev[x]].x) {
			E[prev[x]].c -= c;
			E[E[prev[x]].r].c += c;
		}
		f += c;
	}
}

void add(int x, int y, int c) {
	struct edge e;
	e.x = x; e.y = y; e.c = e.c0 = c;
	e.r = E.size()+1;
	G[x].push_back(E.size());
	E.push_back(e);
	swap(e.x, e.y);
	e.r = E.size()-1;
	e.c = e.c0 = 0;
	G[y].push_back(E.size());
	E.push_back(e);
}


// USO
G = VVI(N, VI());
E.clear();

for(edges){
  add(u,v,cap);
}

int mf = flow(s,t);
