public class Solution {
    public int solve(ArrayList<Integer> A) {
        Collections.sort(A);
        for(int i = 0; i < A.size(); i++) {
            while(i + 1 < A.size() && A.get(i) == A.get(i + 1))
				i++;
            int rem = A.size() - i - 1;
            if(rem == A.get(i))
                return 1;
        }
        return -1;
    }
}
