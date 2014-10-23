// Pra cada regra sozinha, inciializa table[i][1][regra] = true
// Inicializa o resto como false

for (int i=2; i<=C; i++) //Tamanho da string
    for (int j=0; j<C-i+1; j++) //Início da string
	for (int k=1; k<=i-1; k++) //Tamanho da primeira partição
	    for (int r=0; r<rules.size(); r++) // AB->C
		table[j][i][rule.c] |= (table[j][k][rule.b] && table[j+k][i-k][rule.a]);
