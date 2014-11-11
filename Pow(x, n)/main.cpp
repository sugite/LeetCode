class Solution {
public:
    double pow(double x, int n) {
        if(n==1) return x;
        if(n==0) return 1;
        double tmp = x ;
        if(n%2==0) return pow(x*x,n/2);
        else{
            if(n>0) return x*pow(x,n-1);
            else return pow(x,n+1)/x;
        }
    }
};
