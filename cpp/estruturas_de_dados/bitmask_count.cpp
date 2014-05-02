int numOfOnes(int i){
i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int numOfOnes(unsigned long long int i) {
    i = i - ((i >> 1) & 0x5555555555555555ULL);
    i = (i & 0x3333333333333333ULL) + ((i >> 2) & 0x3333333333333333ULL);
    return (int)((((i + (i >> 4ULL)) & 0xF0F0F0F0F0F0F0FULL) * 0x101010101010101ULL) >> 56);
}