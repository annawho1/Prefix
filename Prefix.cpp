

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> strs {};
    int n = 0; cout << "Number of words?"; cin >> n;
    string word{};
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        strs.push_back(word);
    }
    word = "";
    bool equal = true;
    auto smin = *std::min_element(strs.begin(), strs.end(),
        [](const std::string& s1, const std::string& s2) {return s1.length() < s2.length(); }
    );
    for (int i = 0; i < smin.length(); i++)
    {
        for (int j = 0; j < strs.size() - 1; j++)
            if (strs[j][i] != strs[j + 1][i])
            {
                equal = false;
                cout << "Longest common prefix: " << word;
                return 0;
            }
        if (equal == true)
            word += strs[0][i];
    }
    cout << "Longest common prefix: " << word;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
