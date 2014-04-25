int ans = N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) );

// Outra forma
int xorUpToK(int k) {
	switch (k % 4) {
		case 0: return k;
		case 1: return 1;
		case 2: return k + 1;
		case 3: return 0;
	}
}
