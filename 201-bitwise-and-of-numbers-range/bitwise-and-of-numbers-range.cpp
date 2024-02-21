class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int u = 0;
        int lastSetBitPos = 0;
        int c = right;
        
        // Finding the position of the last set bit in 'right'
        while (c > 0) {
            if (c & 1) 
                lastSetBitPos = u;
            c >>= 1;
            u++;
        }
        
        // Finding the common prefix of 'left' and 'right'
        while (left < right) {
            right &= (right - 1);
        }
        
        return right;
    }
};
