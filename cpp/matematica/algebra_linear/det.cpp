int det(vvi &mat){
	int n = mat.size();
	int ret = 0, m1, m2;
	int i, j;
	for(int b = 0; b < n; b++){
		m1 = 1, m2 = 1;
		for(int k = 0; k < n; k++){
			i = k; j = (b+k)%n;
			m1 *= mat[i][j];
			
			j = (n-(b+k+1)%n)%n;
			m2 *= mat[i][j];
		}
		ret += m1 - m2;
	}
	
	return ret;
}
