//
//  File: wl.cpp
//
//  Description: Add stuff here ...
//  Student Name: Add stuff here ..
//  UW Campus ID: Add stuff here ..
//  email: Add stuff here ..

#include <iostream>
#include <string>
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

int main()
{
    string command;
    while (removeWhitespace(command).compare("end") != 0)
    {
        cout << ">";
        getline(cin, command); // enable Enter key capture
        cout << "The command you entered is: " << command << endl;
    }
    cout << "Out of while loop" << endl;
    return 0;
}
