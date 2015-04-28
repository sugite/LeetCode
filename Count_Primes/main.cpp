class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        bool *t = new bool[n];
        t[0] = t[1] = false;
        for(int i = 2 ; i < n ; ++i)
            t[i] = true;
        int count = 0 , sqr = sqrt(n);
        for(int i = 2 ; i <= sqr ; ++i){
            if(t[i]){
                for(int j = i*i ; j < n ; j+=i)
                    t[j] = false;
            }
        }
        for(int i = 2 ; i < n  ; ++i){
            if(t[i]) ++count;
        }
        delete[] t;
        return count;
    }
};

//https://primes.utm.edu/howmany.html#1