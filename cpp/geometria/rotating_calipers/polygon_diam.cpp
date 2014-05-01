ll rotatingCalipers(){
	int ans = 0;
	
	int i = 0, j = dn.size()-1; 
	
	while(i < (int)up.size() - 1 || j > 0){
		// Entrou aqui: up[i] e dn[j] eh um antipodal pair
		ans = max(ans, dist2(up[i],dn[j]));
		
		if(i == (int)up.size()-1) j--;
		else if(j == 0) i++;
		else{
			// Verifica qual o menor angulo a ser rotacionado p utilizar na rotacao
			if((up[i+1].second - up[i].second) * (dn[j].first - dn[j-1].first)
				> (dn[j].second - dn[j-1].second) * (up[i+1].first - up[i].first ))
				i++;
			else
				j--;
		}
	}
	return ans;
}
