void precomputa(){
	for(int u = 0; u < n; u++){
		for(int j = 0; j < (int)AdjList[u].size(); j++){
			ii v = AdjList[u][j];
			t[v.first][0].pai = i;
			t[v.first][0].val = v.second;
		}
	}
	
	int i, j, aux;
	for(j = 1; (1<<j) < n; j++){
		for(i = 0; i < n; i++){
			aux = t[i][j-1].pai;
			t[i][j].pai = t[aux][j-1].pai;
			t[i][j].val = min(t[i][j-1].val,t[aux][j-1].val);
		}
	}
}

// Computa a menor aresta entre a e b, contando que um deles seja o pai
// do outro
int menor_aresta(int a, int b){
	if(L[H[a]] < L[H[b]]) swap(a,b); // b eh pai de a (L eh profundida-
									 // de do no, se usar LCA do CP3)
	
	int logH, ans = INF;
	while(a != b){
		logH = floor(log(L[H[a]]-L[H[b]]),log(2.0));
		ans = min(ans, t[a][logH].val);
		a = t[a][logH].pai;
	}
	return ans;
}
