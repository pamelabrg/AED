int confere (int n, int* v) {
    for(int a = 0; a < n-2; a++) {
        if(v[a] > v[a+1]) return 0;
    }
    return 1;
}
