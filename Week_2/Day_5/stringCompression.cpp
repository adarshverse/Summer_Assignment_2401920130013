// String Compression

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 1;
        int count = 1;
        while (j < n) {
        if (chars[j] == chars[j - 1]) count++;
        else {
            chars[i] = chars[j - 1];
                i++;
                if (count >= 2) {
                    string dig = to_string(count);
                    for (auto x : dig) {
                        chars[i] = x;
                        i++;
                    }
                    count = 1;
                }
            }
            j++;
        }
        chars[i] = chars[n - 1];
        i++;
        if (count >= 2) {
            string dig = to_string(count);
            for (auto x : dig) {
                chars[i] = x;
                i++;
            }
        }
        return i;
    }
};