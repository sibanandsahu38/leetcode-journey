int cmp(const void* a, const void* b) { return **(int**)a - **(int**)b; }
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), cmp);
    int a=n*2,l=1,r=1,m= 1;

    for (int i=0;i<reservedSeatsSize; i++) {
        int s = reservedSeats[i][1];
        if(s==2 || s==3) l=0;
        if(s==4 || s==5) l=m =0;
        if(s==6 || s==7) r=m= 0;
        if(s==8 || s==9) r=0;

        if (i==reservedSeatsSize - 1 || reservedSeats[i][0] != reservedSeats[i+1][0]) {
            a-=2-(l && r ? 2 : (l || r || m));
            l=r=m=1;
        }
    }
    return a;
}