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

string &ltrim(string &str)
{
    const string chars = "\t\n\v\f\r ";
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string &rtrim(string &str)
{
    const string chars = "\t\n\v\f\r ";
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string &trim(string &str)
{
    return ltrim(rtrim(str));
}

int main()
{
    string command;
    while (trim(command).compare("end") != 0)
    {
        cout << ">";
        getline(cin, command); // enable Enter key capture
        cout << "The command you entered is: " << command << endl;
    }
    cout << "Out of while loop";
    return 0;
}
