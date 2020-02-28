public class Solution {
    public ArrayList<ArrayList<Integer>> solve(int A) {
        ArrayList<ArrayList<Integer>> pascalTriangle = new ArrayList<ArrayList<Integer>>();
        if(A <= 0)
            return pascalTriangle;
        for(int i = 0; i < A; i++) {
            pascalTriangle.add(new ArrayList<Integer>());
            for(int j = 0; j <= i; j++) {
                if(j == i || j == 0)
                    pascalTriangle.get(i).add(1);
                else
                    pascalTriangle.get(i).add(pascalTriangle.get(i - 1).get(j) + pascalTriangle.get(i - 1).get(j - 1));
            }
        }
        return pascalTriangle;
    }
}
