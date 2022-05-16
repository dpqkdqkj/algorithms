#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<char, int> romanTable = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int solution(string roman) 
{
    int res = 0;
    int prev_val = 0;

    for (char symbol : roman) {
        int cur_val = romanTable[symbol];
        res += cur_val;

        if (cur_val > prev_val) {
            res -= prev_val * 2;
        } 

        prev_val = cur_val;
    }

    return res;
}


int main()
{
    cout << solution("MCMM") << endl;
    return 0;
}

