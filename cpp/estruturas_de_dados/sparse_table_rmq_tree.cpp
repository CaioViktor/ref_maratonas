// PLL: pair de long long
pll t[MAX_N][MLOGN];
void precomputa(){
	for(int u = 0; u < n; u++){
		for(int j = 0; j < (int)child[u].size(); j++){
			pll v = child[u][j];
			t[v.first][0].first = u;
			t[v.first][0].second = v.second;
		}
	}
	
	int i, j, aux;
	for(j = 1; (1<<j) <= n; j++){
		for(i = 0; i < n; i++){
			aux = t[i][j-1].first;
			t[i][j].first = t[aux][j-1].first;
			t[i][j].second = min(t[i][j-1].second,t[aux][j-1].second);
		}
	}	
}

// Computa a menor aresta entre a e b, contando que um deles seja o pai
// do outro
int menor_aresta(int a, int b){
	if(L[H[a]] < L[H[b]]) swap(a,b); // b eh pai de a (L eh profundida-
									 // de do no, se usar LCA do CP3)
	
	//~ cout << a << "!=" << b << ',' << L[H[a]] << '-' << L[H[b]] << endl;
	ll ans = 1e9;
	for(int i = MLOGN-1; i >= 0 && a != b; i--){
		if(L[H[b]] <= L[H[a]] - (1 << i)){
			ans = min(ans, t[a][i].second);
			a = t[a][i].first;
		}
	}
	return ans;
}
