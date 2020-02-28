public class Solution {
    public ArrayList<Integer> plusOne(ArrayList<Integer> A) {
        int start = 0;
        while(start < A.size() && A.get(start) == 0)
            start++;
        int lastIdx = A.size() - 1, carry = 1;
        while(lastIdx >= start) {
            int curDigit = A.get(lastIdx);
            curDigit += carry;
            if(curDigit == 10)
                curDigit = 0;
            else
                carry = 0;
            A.set(lastIdx, curDigit);
            lastIdx--;
        }
        ArrayList<Integer> result = new ArrayList<Integer>();
        if(carry != 0)
            result.add(carry);
        for(int i = start; i < A.size(); i++)
            result.add(A.get(i));
        return result;
    }
}
