class Solution {
    TreeSet<Integer> starts = new TreeSet<>();  // boundary positions + sentinel n
    TreeMap<Integer, Integer> lens = new TreeMap<>();  // multiset of gap lengths
    char[] s;

    public int[] longestRepeating(String S, String queryCharacters, int[] queryIndices) {
        s = S.toCharArray();
        int n = s.length;
        for (int i = 0, j = 0; i < n; i = j) {  // groupby(s)
            while (j < n && s[j] == s[i]) j++;
            starts.add(i);
            addLen(j - i);
        }
        starts.add(n);

        int[] res = new int[queryIndices.length];
        for (int q = 0; q < res.length; q++) {
            int i = queryIndices[q];
            char c = queryCharacters.charAt(q), old = s[i];
            if (c != old) {
                for (int[] pn : new int[][]{{i, i - 1}, {i + 1, i + 1}}) {
                    int p = pn[0], nb = pn[1];
                    if (0 <= nb && nb < n) {
                        if (s[nb] == old) addBreak(p);
                        else if (s[nb] == c) removeBreak(p);
                    }
                }
                s[i] = c;
            }
            res[q] = lens.lastKey();
        }
        return res;
    }

    void addBreak(int p) {
        int l = starts.lower(p), r = starts.higher(p);
        starts.add(p);
        removeLen(r - l);
        addLen(p - l);
        addLen(r - p);
    }

    void removeBreak(int p) {
        int l = starts.lower(p), r = starts.higher(p);
        starts.remove(p);
        removeLen(p - l);
        removeLen(r - p);
        addLen(r - l);
    }

    void addLen(int x)    { lens.merge(x, 1, Integer::sum); }
    void removeLen(int x) { lens.compute(x, (len, cnt) -> cnt == 1 ? null : cnt - 1); }
}