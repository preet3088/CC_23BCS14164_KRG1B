class q1 {
    public int singleNumber(int[] nums) {
        int x=0;
        for(int e:nums){
            x^=e;
        }
        return x;
    }
}