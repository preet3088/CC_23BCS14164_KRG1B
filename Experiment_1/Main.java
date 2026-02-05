class Solution {
    public int nthMagicalNumber(int n, int a, int b) {

        long lcm=(a/gcd(a,b))*b;
        int mod=(int)1e9+7;

        long l=1;
        long r=(long)n*Math.min(a,b);
        long ans=-1;

        while(l<=r){
            long mid=l+(r-l)/2;
            if(valid(a,b,lcm,mid,n)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return (int)(ans%mod);
    }
    public long gcd(long a,long b){
        return b==0?a:gcd(b,a%b);
    }
    public boolean valid(long a,long b,long lcm,long mid,long n){
        long count=(mid/a)+(mid/b)-(mid/lcm);
        return count>=n;
    }
}
