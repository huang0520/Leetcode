#include <iostream>
#include <string>

#define cond(i) ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
#define capital(i) (i >= 'A' && i <= 'Z')

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto lp = s.begin();
        auto rp = s.end() - 1;

        while (lp < rp){
            if (capital(*lp)) *lp += 32;
            if (capital(*rp)) *rp += 32;

            if (!empty(*lp)) lp++;
            else if (!empty(*rp)) rp--;
            else if (*lp != *rp) return false;
            else{
                lp++;
                rp--;
            }
        }
        return true;
    }
};

int main(void){
    string s = "A man, a plan, a canal: Panama";

    Solution sol;

    cout << sol.isPalindrome(s) << "\n";
}