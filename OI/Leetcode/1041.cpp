#include "god.h"
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, xx = 0, yy = 1;
        for (int i = 0; i < instructions.size(); i ++){
            if (instructions[i] == 'G')
                x += xx, y += yy;
            else if (instructions[i] == 'L'){
                if (yy != 0){
                    xx -= yy;
                    yy = 0;
                }else{
                    yy += xx;
                    xx = 0;
                }
            }else if (instructions[i] == 'R'){
                if (yy != 0){
                    xx += yy;
                    yy = 0;
                }else{
                    yy -= xx;
                    xx = 0;
                }
            }
        }
        if (x == 0 && y == 0) 
            return true;
        if (yy == 0){
            int xxx = 0, yyy = 0;
            if (x == 1)
                for (int i = 1; i <= 4; i ++){
                    xxx += xx * y - yy * x;
                    yyy += yy * y - xx * x;
                    if (yy != 0){
                    xx -= yy;
                    yy = 0;
                    }else{
                        yy += xx;
                        xx = 0;
                    }
                }
            else for (int i = 1; i <= 4; i ++){
                    xxx += xx * y - yy * x;
                    yyy += yy * y - xx * x;
                    if (yy != 0){
                        xx += yy;
                        yy = 0;
                    }else{
                        yy -= xx;
                        xx = 0;
                    }
                }
            if (xxx == 0 && yyy == 0) return true;
        }else if (yy == -1) return true;
        return false;
    }
};

int main() {
    string instructions="GLGLGGLGL";
    Solution outputs;
    bool result = outputs.isRobotBounded(instructions);
    cout << (result? "True": "False");
    return 0;
}