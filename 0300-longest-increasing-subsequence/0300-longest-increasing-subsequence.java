class Solution {
    public int lengthOfLIS(int[] arr) {
        int memoTable[][] = new int[arr.length + 1][arr.length];
        for (int[] l : memoTable) {
            Arrays.fill(l, -1);
        }
        return LISLength(arr, -1, 0, memoTable);
    }
    public int LISLength(int[] arr, int prev, int current, int[][] memoTable) {
        if (current == arr.length) {
            return 0;
        }
        if (memoTable[prev + 1][current] >= 0) {
            return memoTable[prev + 1][current];
        }
        int include = 0;
        if (prev < 0 || arr[current] > arr[prev]) {
            include = 1 + LISLength(arr, current, current + 1, memoTable);
        }

        int exclude = LISLength(arr, prev, current + 1, memoTable);
        memoTable[prev + 1][current] = Math.max(include, exclude);
        return memoTable[prev + 1][current];
    }
}