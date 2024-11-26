// Solution 1
class Solution {
    public int findChampion(int n, int[][] edges) {
        /**
        return the node that has no incoming edges
        */

        int[] in_edges = new int[n];
        for (int[] e : edges) {
            in_edges[e[1]]++;
        }

        List<Integer> no_in = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            if (in_edges[i] == 0)
                no_in.add(i);
        }

        return no_in.size() == 1 ? no_in.get(0) : -1;
    }
}
