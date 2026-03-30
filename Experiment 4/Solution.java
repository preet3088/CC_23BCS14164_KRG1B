class Solution {
    public int sumBitDifferences(int[] arr) {
        long res=0;
        int n=arr.length;
        for(int i=0;i<32;i++){
            int one=0;
            for(int x:arr){
                if((x&(1<<i))!=0){
                    one++;
                }
            }
            int zero=n-one;
            res+=2L*one*zero;
        }
        return (int)res;
    }
}
