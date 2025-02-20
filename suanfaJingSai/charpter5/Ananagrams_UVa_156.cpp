//反片语
//输入一些单词，求满足下列条件的单词，此单词不能通过字母重排，得到输入文本中的另外一个单词，字母不分大小写，但输出时应保留输入中的大小写，按字典排序输出
//map的应用
//把每个单词标准化，即全部转化为小写字母后进行排序，再放到map中进行统计
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> cnt;
vector<string> words;

string repr(const string &s) //将s进行标准化
{
    string ans = s;
    for (int i = 0; i < ans.length(); i++)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 0;
    string s;
    while (cin >> s)
    {
        if (s[0] == '#')
        {
            break;
        }
        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r))
        {
            cnt[r] = 0;
        }
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        if (cnt[repr(words[i])] == 1)
        {
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}