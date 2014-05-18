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
			if(ccw(point(0,0), toVec(up[i], up[i+1]), toVec(dn[j],dn[j-1])))
				i++;
			else
				j--;
		}
	}
	return ans;
}
