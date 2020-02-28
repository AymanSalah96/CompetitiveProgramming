public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> spiralOrder(final List<ArrayList<Integer>> A) {
        int n = A.size();
        int m = A.get(0).size();
        int startRow = 0, startCol = 0;
        int endRow = n, endCol = m;
        int curRow = 0, curCol = 0;
        int dir = 0;
        ArrayList<Integer> spiralList = new ArrayList<Integer>();
        while(startRow != endRow && startCol != endCol) {
            if(dir == 0) { // from left to right
                while(curCol < endCol) {
                    spiralList.add(A.get(curRow).get(curCol));
                    curCol++;
                }
                curCol--;
                curRow++;
                startRow++;
                dir = 1;
            } else if(dir == 1) { // from up to down
                while(curRow < endRow) {
                    spiralList.add(A.get(curRow).get(curCol));
                    curRow++;
                }
                curRow--;
                curCol--;
                endCol--;
                dir = 2;
            } else if(dir == 2) { // from right to left
                while(curCol >= startCol) {
                    spiralList.add(A.get(curRow).get(curCol));
                    curCol--;
                }
                curCol++;
                curRow--;
                endRow--;
                dir = 3;
            } else if(dir == 3) { // from down to up
                while(curRow >= startRow) {
                    spiralList.add(A.get(curRow).get(curCol));
                    curRow--;
                }
                curRow++;
                curCol++;
                startCol++;
                dir = 0;
            }
        }
        return spiralList;
    }
}
