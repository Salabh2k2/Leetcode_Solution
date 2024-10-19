class Solution {
public:
    char rec(int n, int k)
    {
        if(n == 1) return '0';  // Base case: the string at level 1 is "0"
        
        int mid = (1 << (n - 1));  // The middle index for string at level n
        
        if(k == mid) 
            return '1';  // The middle element is always '1'
        else if(k < mid)
            return rec(n - 1, k);  // Search in the first half
        else
            return rec(n - 1, (mid * 2) - k) == '0' ? '1' : '0';  // Mirror case with inversion
    }
    
    char findKthBit(int n, int k) {
        return rec(n, k);
    }
};
