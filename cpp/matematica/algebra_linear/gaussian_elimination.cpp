
struct AugmentedMatrix{ double mat[MAX_N][MAX_N+1]; };
struct ColumnVector{ double vec[MAX_N]; };

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug){

	int i, j, k, l; double t; ColumnVector X;
	
	for(j = 0; j < N - 1; j++){
		l = j;
		for(i = j + 1; i < N; i++)
			if(fabs(Aug.mat[i][j]) > fabs(Aug.mat[l][j]))
				l = i;
		for(k = j; k <= N; k++){
			t = Aug.mat[j][k];
			Aug.mat[j][k] = Aug.mat[l][k];
			Aug.mat[l][k] = t;
		}
		for(i = j + 1; i < N; i++)
			for(k = N; k >= j; k--)
				Aug.mat[i][k] -= Aug.mat[j][k] * Aug.mat[i][j] / Aug.mat[j][j];
	}
	
	for(j = N - 1; j >= 0; j--){
		for(t = 0.0, k = j + 1; k < N; k++)
			t += Aug.mat[j][k] * X.vec[k];
		X.vec[j] = (Aug.mat[j][N] - t) / Aug.mat[j][j];
	}
	return X;
}
