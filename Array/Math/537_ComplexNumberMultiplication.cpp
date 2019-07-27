#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string complexNumberMultiply(string a, string b)
{
    int ra, ia, rb, ib;
    char buff;
    stringstream aa(a), bb(b), res;
    aa >> ra >> buff >> ia ;
    bb >> rb >> buff >> ib ;

    res << ra * rb - ia * ib << "+" << ra * ib + rb * ia << "i";
    return res.str();
 }

string complexNumberMultiply2(string a, string b)
{
    int pos1 = a.find('+');
    string a1 = a.substr(0, pos1);
    string a2 = a.substr(pos1 + 1);

    int ia1 = stoi(a1);
    int ia2 = stoi(a2);

    int pos2 = b.find('+');
    string b1 = b.substr(0, pos2);
    string b2 = b.substr(pos2 + 1);

    int ib1 = stoi(b1);
    int ib2 = stoi(b2);

    string res1 = to_string(ia1 * ib1 - ia2 * ib2);
    string res2 = to_string(ia1 * ib2 + ia2 * ib1);

    return res1 + '+' + res2 + 'i';
}

void testComplexNumberMultiply()
{
    string a1 = "1+1i";
    string b1 = "1+1i";
    cout << complexNumberMultiply(a1, b1) << endl;

    string a2 = "1+-1i";
    string b2 = "1+-1i";
    cout << complexNumberMultiply(a2, b2) << endl;
}

int main()
{
    testComplexNumberMultiply();

    getchar();
    return 0;
}