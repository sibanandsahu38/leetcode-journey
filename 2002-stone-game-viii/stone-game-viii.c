#define MAX(a, b) ((a) > (b) ? (a) : (b))

int stoneGameVIII(int* stones, int stonesSize) {
    int s=0;
    for(int i=0;i<stonesSize;i++) s+= stones[i];
    int a=s;
    for(int i=stonesSize-1;i>1;i--) {
        s-=stones[i];
        a=MAX(a, s - a);
    }
    return a;
}