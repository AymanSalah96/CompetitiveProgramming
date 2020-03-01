public class Solution {
    public int titleToNumber(String A) {
        int result = 0;
        for(int i = A.length() - 1, j = 0; i >= 0; i--) {
            result += (A.charAt(i) - 'A' + 1) * (int)Math.pow(26, j++);
        }
        return result;
    }
}
