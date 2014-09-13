inline int at(int idx) { return curr[idx-1]-'0'; }
ll f(int digit, ll sum, bool lo) {
	if (digit == curr.size()+1)
		return (condicao == true);

	int end = lo ? 9 : at(digit);

	ll res = 0;
	for (int i=0; i<=end; i++) {
		// ...
		bool n_lo = (lo || (i < at(digit)));
		res += f(digit+1, n_sum, n_lo);
	}
	return res;
}