int s = (1 << N) - 1;
while (!(s & 1 << K)) {
	
	/* Faz algo com a mask s */

	int lo = s & ~(s - 1); 
    int lz = (s + lo) & ~s;
    s |= lz;               
    s &= ~(lz - 1);        
    s |= (lz / lo / 2) - 1;
}