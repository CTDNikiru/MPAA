#include "bruteforce.h"
#include "sha256.h"
#include <list>
#include <functional>

using namespace std;

string Pass = "";

void next_comb(long long num, size_t radix, vector<size_t>& idxs) {
    for (int i = idxs.size(); i > 0; --i) {
        idxs[i - 1] = num % radix;
        num /= radix;
    }
}

string gen_n_str(string alf, size_t n, string hashPass) {
    size_t alf_len = alf.size();
    string buf = "";
    long long total = [](size_t bas, size_t exp) { long long pow = 1LL;  while (exp-- > 0) pow *= bas; return pow; }(alf_len, n); 
    vector<size_t> indexes(n);
    for (long long i = 0; i < total; ++i) {

        next_comb(i, alf_len, indexes);

        for (size_t j = 0; j < n; ++j) {
            buf += alf[indexes[j]];
        }

        if (sha256(buf) == hashPass) {
            return buf;
        }
        buf = "";
    }
    return "";
}

string bruteforce(const string& password_hash, const string& alphabet, int max_length) {

    for (int i = 0; i < max_length + 1; i++) {

        Pass = gen_n_str(alphabet, i, password_hash);

        if (Pass != "")
            return Pass;
    }

    return Pass;
}