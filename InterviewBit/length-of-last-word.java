public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int lengthOfLastWord(final String A) {
        boolean space = false;
        int res = 0;
        for(int i = A.length() - 1; i >= 0; i--) {
            if(A.charAt(i) == ' ' && space)
                break;
            if(Character.isLetter(A.charAt(i))) {
                space = true;
                res++;
            }
        }
        return res;
    }
}
