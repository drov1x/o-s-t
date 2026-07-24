#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0, rcnt;
        
        for (auto i : s){
            if (i != ' '){
                cnt ++;
            }else{
                rcnt = (cnt?cnt:rcnt);
                cnt = 0;
            }
        }
        return (cnt?cnt:rcnt);
    }
};

int main()
{
    string s = "   fly me   to   the moon  ";
    Solution o;
    int resultd = o.lengthOfLastWord(s);
    cout << resultd << endl;
    return 0;
}