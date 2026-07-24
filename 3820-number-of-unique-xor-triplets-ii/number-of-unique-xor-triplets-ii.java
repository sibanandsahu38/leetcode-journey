public class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int m=0;
        for (int num : nums)
            m=Math.max(m, num);
        int T = 1;
        while (T <= m)
            T <<= 1;
        boolean[] s1 = new boolean[T];
        boolean[] s2 = new boolean[T];
        for (int i = 0; i < nums.length; i++)
            for (int j = i; j < nums.length; j++)
                s1[nums[i] ^ nums[j]] = true;
        for (int i = 0; i < T; i++)
            if (s1[i]) 
                for (int num : nums) 
                    s2[i ^ num] = true;
        int c= 0;
        for (int i = 0; i < T; i++) 
            if (s2[i]) 
                c++;        
        return c;
    }
}