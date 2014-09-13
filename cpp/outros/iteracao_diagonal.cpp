for (int slice=0; slice < (L+C-1); ++slice) {
    int z1 = slice < C ? 0 : slice - C + 1;
    int z2 = slice < L ? 0 : slice - L + 1;
    for (int j = slice - z2; j >= z1; --j) {
        // ...
    }
}