#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

std::string getHint(std::string secret, std::string guess)
{
    assert(secret.size() == guess.size());

    std::string result;
    int bull = 0;
    int cow = 0;

    std::vector<int> vsecret(256, 0);
    std::vector<int> vguess(256, 0);

    for (int i = 0; i < secret.size(); ++i)
    {
        if (secret[i] == guess[i])
            ++bull;

        ++vsecret[secret[i]];
        ++vguess[guess[i]];
    }

    for (int i = 0; i < 256; ++i)
    {
        if (vsecret[i] != 0 && vguess[i] != 0)
            cow += std::min(vsecret[i], vguess[i]);
    }

    cow -= bull;
    result = std::to_string(bull) + 'A' + std::to_string(cow) + 'B';

    return result;
}

int main()
{
    std::string secret1 = "1123", guess1 = "0111";
    std::string secret2 = "1807", guess2 = "7810";
    std::cout << getHint(secret2, guess2) << std::endl;
    system("pause");
    return 0;
}