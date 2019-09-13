//
//  File: wl.cpp
//
//  Description: Assignment 1 - CS 564 Fall 2019
//  Student Name: Mujahid Fakhrul Anuar
//  UW Campus ID: 9075332602
//  email: mujahid.f.anuar@wisc.edu

#include <iostream>
#include <string>
#include <regex>
using namespace std;

/**
 * A utility function to remove whitespaces from a string.
 *
 * @param str The string to be cleaned.
 * @return A string without whitespaces.
 */
string removeWhitespace(string str)
{
    const string whitespaceRegex = "\r\v\n\t\f ";
    str.erase(str.find_last_not_of(whitespaceRegex) + 1); // right trim
    str.erase(0, str.find_first_not_of(whitespaceRegex)); // left trim

    return str;
}

/**
 * A utility function to convert a string to lowercase.
 * Uses toLower().
 *
 * @param str The string to be lowercased.
 * @return A lowercased string (if applicable).
 */
string toLowercase(string str)
{
    int i = 0;
    char c;
    while (str[i])
    {
        c = str[i];
        str[i] = tolower(c);
        i++;
    }
    return str;
}

/**
 * A helper function that returns a cleaned command.
 *
 * @param command The command to be cleaned.
 * @return A vector of strings containing the cleaned commands.
 */
vector<string> parseCommand(string command)
{
    vector<string> commands;
    command = removeWhitespace(command);

    // regex whitespaceRegex("[\r\v\n\t\f ]+");
    regex whitespaceRegex("\\s+");
    sregex_token_iterator itr(command.begin(), command.end(), whitespaceRegex, -1);
    sregex_token_iterator end;
    while (itr != end)
    {
        commands.push_back(toLowercase(itr->str()));
        *itr++;
    }

    return commands;
}

/**
 * A helper function that parses a file.
 *
 * @param command The file name that is to be parsed.
 * @return A vector of strings containing the parsed text.
 */
vector<string> parseText(string command)
{
    vector<string> text;

    return text;
}

int main()
{
    string command; // used by cin to read commands
    bool isLoaded = false;

    do
    {
        cout << ">";
        getline(cin, command); // enable Enter key capture

        vector<string> commands = parseCommand(command);

        // debugging purposes //
        int i = 0;
        for (i = 0; i < commands.size(); i++)
        {
            cout << "Command " << i << ": |" << commands[i] << "|" << endl;
        }
        cout << commands[0] << endl;
        cout << commands.size() << endl;
        // end debugging purposes //

        string firstCommand = commands[0];

        if (firstCommand.compare("load") == 0 && commands.size() == 2)
        {
        }
        else if (firstCommand.compare("locate") == 0 && commands.size() == 3)
        {
        }
        else if (firstCommand.compare("new") == 0 && commands.size() == 1)
        {
            isLoaded = false;
        }
        else if (firstCommand.compare("end") == 0 && commands.size() == 1)
        {
            command = firstCommand;
        }
        else if (firstCommand.compare("") == 0) // capture empty command
        {
        }
        else // bad command
        {
            cout << "ERROR: Invalid command”" << endl;
        }

    } while (command.compare("end") != 0);

    cout << "Out of while loop" << endl;
    return 0;
}
