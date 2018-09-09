//Write a function to generate the generalized abbreviations of a word.
//
//Example:
//
//Given word = "word", return the following list(order does not matter) :
//
//    ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

#include <iostream>
#include <vector>
#include <string>

void backtrack(std::vector<std::string>& result, std::string& word, int pos, int cnt, std::string path)
{
    if (pos == word.size())
    {
        if (cnt > 0)
            path += std::to_string(cnt);

        result.push_back(path);
        return;
    }

    backtrack(result, word, pos + 1, cnt + 1, path);
    backtrack(result, word, pos + 1, 0, path + (cnt > 0 ? std::to_string(cnt) : "") + word[pos]);
}

std::vector<std::string> generateAbbreviations(std::string word)
{
    std::vector<std::string> result;
    std::string path;
    backtrack(result, word, 0, 0, path);

    return result;
}

void backtrack2(std::vector<std::string>& result, std::string& word, int pos)
{
    for (int i = pos; i < word.size(); ++i)
    {
        for (int j = 1; i + j <= word.size(); ++j)
        {
            std::string temp = word.substr(0, i);
            temp += std::to_string(j) + word.substr(i + j);
            result.push_back(temp);
            backtrack2(result, temp, i + 1 + std::to_string(j).size());
        }
    }
}

std::vector<std::string> generateAbbreviations2(std::string word)
{
    std::vector<std::string> result;
    std::string path;
    backtrack2(result, word, 0);

    return result;
}

int main()
{
    std::string input = "word";
    std::vector<std::string> result = generateAbbreviations2(input);

    for (auto s : result)
        std::cout << s << std::endl;

    system("pause");
    return 0;
}