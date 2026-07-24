int uniqueXorTriplets(int* nums, int numsSize) {
    int m= 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > m) 
            m= nums[i];
        
    int t = 1;
    while (t <= m)
        t= t * 2;
    
    bool* s1 = (bool*)calloc(t, sizeof(bool));
    bool* s2 = (bool*)calloc(t, sizeof(bool));
    for (int i = 0; i < numsSize; i++)
        for (int j = i; j < numsSize; j++)
            s1[nums[i] ^ nums[j]] = true;
    
    for (int i = 0; i < t; i++) 
        if (s1[i]) 
            for (int j = 0; j < numsSize; j++) 
                s2[i ^ nums[j]] = true;
         
    int count = 0;
    for (int i = 0; i < t; i++) 
        if (s2[i]) 
            count++;
    free(s1);
    free(s2);
    
    return count;
}