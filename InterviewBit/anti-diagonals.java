public class Solution {
    public ArrayList<ArrayList<Integer>> diagonal(ArrayList<ArrayList<Integer>> A) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        int n = A.size();
        int m = A.get(0).size();
        for(int i = 0; i < m; i++) {
            int curCol = i;
            int curRow = 0;
            result.add(new ArrayList<Integer>());
            while(curRow < n && curCol >= 0) {
                result.get(result.size() - 1).add(A.get(curRow).get(curCol));
                curRow++;
                curCol--;
            }
        }
        for(int i = 1; i < n; i++) {
            int curRow = i;
            int curCol = m - 1;
            result.add(new ArrayList<Integer>());
            while(curRow < n && curCol >= 0) {
                result.get(result.size() - 1).add(A.get(curRow).get(curCol));
                curRow++;
                curCol--;
            }
        }
        return result;
    }
}
