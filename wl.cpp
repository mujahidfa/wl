//
//  File: wl.cpp
//
//  Description: Add stuff here ...
//  Student Name: Add stuff here ..
//  UW Campus ID: Add stuff here ..
//  email: Add stuff here ..

#include <iostream>
#include <string>
#include <regex>
using namespace std;

/**
 * A string utility function to remove whitespaces from a command.
 *
 * @param &str The command to be cleaned.
 */
string &removeWhitespace(string &str)
{
    const string whitespaceRegex = "\r\v\n\t\f ";
    str.erase(str.find_last_not_of(whitespaceRegex) + 1); // right trim
    str.erase(0, str.find_first_not_of(whitespaceRegex)); // left trim

    return str;
}

string &lowercase(string &str)
{
    return str;
}

vector<string> tokenize(const string stringToTokenize)
{
    // vector<string> tokens;
    // string token;
    // stringstream tokenStream(s);
    // while (getline(tokenStream, token, delimiter))
    // {
    //     tokens.push_back(token);
    // }
    // return tokens;

    vector<string> tokens;

    regex whitespaceRegex("[\r\v\n\t\f ]+");
    sregex_token_iterator iterator(stringToTokenize.begin(), stringToTokenize.end(), whitespaceRegex, -1);
    sregex_token_iterator regex_end;
    while (iterator != regex_end)
    {
        tokens.push_back(iterator->str());
    }

    return tokens;
}

int main()
{
    string command;
    while (removeWhitespace(command).compare("end") != 0)
    {
        cout << ">";
        getline(cin, command); // enable Enter key capture

        // Returns first token
        vector<string> tokenizedCommandLine = tokenize(command);
        string firstCommand = tokenizedCommandLine[0];

        if (firstCommand.compare("load") == 0)
        {
        }
        else if (firstCommand.compare("locate") == 0)
        {
        }
        else if (firstCommand.compare("new") == 0)
        {
        }
        else if (firstCommand.compare("end") == 0)
        {
            // do nothing
        }
        else if (firstCommand.compare("") == 0) // capture empty command
        {
            /* code */
        }
        else // bad command
        {
            cout << "ERROR: Invalid command”" << endl;
        }

        // cout << "The command you entered is: " << command << endl;
    }
    cout << "Out of while loop" << endl;
    return 0;
}
