#include <string>

using namespace std;
class Solution {
private:
    void replaceString(const string& target, const string& rep, string& text) {
        auto i = 0;
        while ((i = text.find(target, i)) != string::npos) {
            text.replace(i, target.size(), rep);
            i += rep.size();
        }
    }

public:
    string entityParser(string text) {
        replaceString("&quot;", "\"", text);
        replaceString("&apos;", "\'", text);
        replaceString("&gt;", ">", text);
        replaceString("&lt;", "<", text);
        replaceString("&frasl;", "/", text);
        replaceString("&amp;", "&", text);

        return text;
    }
};

void testEntityParser() {
    Solution soluiton;

    assert(soluiton.entityParser("&amp; is an HTML entity but &ambassador; is not.") == "& is an HTML entity but &ambassador; is not.");
    assert(soluiton.entityParser("and I quote: &quot;...&quot;") == "and I quote: \"...\"");
    assert(soluiton.entityParser("Stay home! Practice on Leetcode :)") == "Stay home! Practice on Leetcode :)");
    assert(soluiton.entityParser("x &gt; y &amp;&amp; x &lt; y is always false") == "x > y && x < y is always false");
    assert(soluiton.entityParser("leetcode.com&frasl;problemset&frasl;all") == "leetcode.com/problemset/all");
}

int main() {
    testEntityParser();

    return 0;
}