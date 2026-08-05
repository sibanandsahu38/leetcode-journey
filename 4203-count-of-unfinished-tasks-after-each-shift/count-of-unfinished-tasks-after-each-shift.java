class Solution {
    public int[] countTasks(int[] tasks, int[] shifts) {

        int n = tasks.length;
        int m = shifts.length;
        int[] ans = new int[m];
        long[] prefix = new long[n];
        prefix[0] = tasks[0];

        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+tasks[i];
        long totalTime=prefix[n-1];
        long currentCompletedWork=0;

        for(int i=0;i<m;i++) {
            currentCompletedWork+=shifts[i];
            if (currentCompletedWork >= totalTime) {
                ans[i] = 0;
                currentCompletedWork=0;
            } else {

                int low=0;
                int high=n-1;
                while (low<=high){

                    int mid = low+(high-low)/2;

                    if (prefix[mid] <= currentCompletedWork)
                        low=mid+1;
                    else
                        high=mid-1;
                }
                ans[i]=n-low;
            }
        }

        return ans;
    }
}