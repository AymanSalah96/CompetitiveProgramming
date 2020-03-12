public class Solution {
    public String convertToTitle(int A) {
        StringBuilder sb = new StringBuilder();
        A--;
        while(A >= 0) {
            int tmp = A % 26;
            sb.append((char) (tmp + 'A'));
            A /= 26;
            A--;
        }
        return sb.reverse().toString();
    }
}
