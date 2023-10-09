#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
//#include <typeinfo>
using namespace std;

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](string& w1, string& w2){return w1.size()<w2.size();});
    unordered_map<string, int> dp;
    int ans = 0;
    for (string w:words)
    {
        dp[w] = 1;
        for (int i=0; i<w.size();i++)
        {
            string wpre = w.substr(0, i) + w.substr(i+1, w.size()-i-1);
            auto found = dp.find(wpre);
            //cout<<typeid(found).name()<<endl;
            if (found != dp.end())
            {
                dp[w] = max(dp[w], found->second + 1);
            }
        }
        ans = max(ans, dp[w]);
    }
    return ans;
}

int main(){
    vector<string> mywords{"a", "ca", "ab", "aaa"};
    cout<<longestStrChain(mywords)<<endl;
}