#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int finder(string input, string whatToFind)
{
    int stringLocation;
    bool substringFound = false;
    vector<char> stringAsChars;
    for (int i = 0; i < input.size(); i++)
    { // puts the string into a vector of chars
        stringAsChars.push_back(input.at(i));
    }

    for (int k = 0; k < stringAsChars.size(); k++)
    {
        if (substringFound == true)
        {
            break;
        }
        if (stringAsChars.at(k) == whatToFind.at(0))
        {
            for (int j = 0; j < whatToFind.size(); j++)
            {
                if (k + j == stringAsChars.size())
                {
                    stringLocation = -1;
                    break;
                }
                if (stringAsChars.at(k + j) == whatToFind.at(j))
                {
                    stringLocation = k;
                    if (j == whatToFind.size() - 1)
                    {
                        substringFound = true;
                    }
                }
                else
                {
                    stringLocation = -1;
                    break;
                }
            }
        }
    }

    return stringLocation;
}

int finder(string input, char whatToFind)
{
    int charLocation;
    bool charLocationFound = false;
    for (int i = 0; i < input.size(); i++)
    {
        if (charLocationFound == true)
        {
            break;
        }
        if (input.at(i) == whatToFind)
        {
            charLocation = i;
            charLocationFound = true;
            break;
        }
        if (i == input.size() - 1 && charLocationFound == false)
        {
            charLocation = -1;
        }
    }
    return charLocation;
}

int main()
{
    string stringToBeExamined;
    assert(finder("Hello", "e") == 1);
    assert(finder("OiHello", "Hello") == 2);
    assert(finder("OiHel", "Hello") == -1);
    assert(finder("HelHello", "Hello") == 3);
    assert(finder("HelloHello", "Hello") == 0);
    assert(finder("Hello", 'e') == 1);
    assert(finder("OiHello", 'H') == 2);
    assert(finder("OiHel", 'p') == -1);
    assert(finder("HHH", 'H') == 0);

    cout << "This worked" << endl;

    return 0;
}