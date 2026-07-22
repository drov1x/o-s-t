#include "god.h"
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> s;
        for (int i = 0; i < operations.size(); i ++){
            if (operations[i][0] <= '9' && operations[i][0] >= '0'){
                int x = 0;
                for (int j = 0; j < operations[i].size(); j ++){
                    x *= 10;
                    x += operations[i][j] - '0';
                }
                s.push_back(x);
            }else if (operations[i][0] == '-'){
                int x = 0;
                for (int j = 1; j < operations[i].size(); j ++){
                    x *= 10;
                    x += operations[i][j] - '0';
                }
                s.push_back(x * -1);
            }else if (operations[i] == "+"){
                s.push_back(s[s.size() - 1] + s[s.size() - 2]);
            }else if (operations[i] == "C"){
                s.pop_back();
            }else if (operations[i] == "D"){
                s.push_back(s.back() * 2);
            }
        }
        int cnt = 0;
        for (int i = 0; i < s.size(); i ++){
            cnt += s[i];
        }
        return cnt;
    }
};

int main() {
    vector<string> operations={"1","C","-62","-45","-68"};
    Solution outputs;
    int result = outputs.calPoints(operations);
    cout << result;
    return 0;
}