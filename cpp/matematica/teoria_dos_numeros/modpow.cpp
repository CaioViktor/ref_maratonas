ll pot(int a, int b) {
	ll x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
		}
		y = (y*y);
		b /= 2;
	}
	return x;
}
