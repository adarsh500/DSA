//https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1/?track=DSASP-BitMagic&batchId=154#


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int largestPowerOf2inrange(int n){
            int x = 0;
            while((1 << x) <= n){
                x++;
            }
            return x-1;
    }
        
    int countSetBits(int n)
    {
        if(n == 0){
            return 0;
        }
        int x = largestPowerOf2inrange(n);
        return ((pow(2,x-1) * x) + (n - pow(2,x) + 1) + countSetBits(n - pow(2,x)));
    }
};
