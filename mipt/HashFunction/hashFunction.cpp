#include "hashFunction.h"

long long int hashFunction(std::string s){
    const int p = 2, q = 101;
    long long int h = 0;
    std::vector<long long int> p_pow (s.length());
    p_pow[0] = 1;
    for(int i = s.length() - 1; i > p_pow.size(); i--){
        p_pow[i] = p_pow[i-1] * p;
    }
    for(int i = 0; i < s.length(); i++){
        h += (()s[i] - 'a' + 1) * p_pow[i]) % q;
    }
    return h;
}
