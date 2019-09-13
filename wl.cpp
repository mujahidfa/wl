//  File: wl.cpp
//
//  Description: Assignment #1: C++ Word Locator - CS 564 Fall 2019
//  UW Campus ID: 9075332602
//  email: fakhrulanuar@wisc.edu

#include <iostream>
#include <string>
#include <regex>
#include <fstream> // std::ifstream
#include <unordered_map>
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
 * A helper function that returns a "cleaned" command i.e. lowercased and whitespaces-removed.
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
 * Checks if a string is a valid word i.e. consists of only alphabetical characters, apostrophes, and/or numbers.
 * 
 * @param word The string to be checked.
 * @return true if valid word, false otherwise
 */
bool isValidWord(string word)
{
    regex validWordRegex("[a-zA-Z'0-9]+");

    return regex_match(word, validWordRegex);
}

/**
 * Checks if a string is a valid number and larger than 0.
 * 
 * @param word The string to be checked.
 * @return true if valid number, false otherwise
 */
bool isValidNumber(string word)
{
    regex validNumberRegex("[0-9]+");

    return regex_match(word, validNumberRegex) && (stoi(word) > 0);
}

int main()
{
    string command; // used as placeholder by getline to read commands
    bool isLoaded = false;
    unordered_multimap<string, int> wordList; // used to store all words and their position in the loaded file

    do
    {
        cout << ">";
        getline(cin, command);

        // properly parse the command, checking for whitespaces and uppercases
        vector<string> commands = parseCommand(command);

        // debugging purposes //
        // for (int i = 0; i < commands.size(); i++)
        // {
        //     cout << "Command " << i << ": |" << commands[i] << "|" << endl;
        // }
        // cout << commands[0] << endl;
        // cout << commands.size() << endl;
        // end debugging purposes //

        string firstCommand = commands[0];

        // The “load” command scans the document, & parse and store
        // the words in a data structure i.e. wordList (unordered_multimap).
        // It can only take 1 argument.
        if (firstCommand.compare("load") == 0 && commands.size() == 2)
        {
            std::ifstream inputFile(commands[1], ifstream::in);

            if (!inputFile)
            {
                cout << "ERROR: Invalid command" << endl;
            }
            else
            {
                // reset wordList everytime a valid load command is run
                wordList.clear();
                isLoaded = false;

                string currLine;
                int wordCount = 1;

                while (getline(inputFile, currLine))
                {
                    // cout << currLine << endl; // for debugging purposes

                    // if line is empty, skip
                    if (currLine.empty())
                        continue;

                    regex notValidWordRegex("[^a-zA-Z0-9']+");
                    sregex_token_iterator itr(currLine.begin(), currLine.end(), notValidWordRegex, -1);
                    sregex_token_iterator end;

                    while (itr != end)
                    {
                        // add current lowercased word with the current word count as its value
                        wordList.insert(make_pair(toLowercase(itr->str()), wordCount));

                        *itr++;
                        wordCount++;
                    }
                }

                isLoaded = true;
                inputFile.close();
            }

            // print line, for debugging purposes
            // for (unordered_multimap<string, int>::iterator itr = wordList.begin(); itr != wordList.end(); itr++)
            // {
            //     cout << itr->first << '\t';
            //     cout << itr->second << endl;
            // }
        }

        // The "locate" command, given a word, returns the position of the
        // nth occurrence of the word in the document you load.
        // It can only take 2 arguments.
        else if (firstCommand.compare("locate") == 0 && commands.size() == 3)
        {
            // check if the 2nd argument and 3rd argument are not valid
            if (isValidWord(commands[1]) == false)
            {
                cout << "ERROR: Invalid command" << endl;
            }
            else if (isValidNumber(commands[2]) == false)
            {
                cout << "ERROR: Invalid command" << endl;
            }
            // if the 2nd argument and 3rd argument are valid,
            else
            {
                // check if a file was loaded
                if (isLoaded == false)
                {
                    cout << "No matching entry" << endl;
                }
                // if a file was loaded, then we can do our search
                else
                {
                    int occurance = stoi(commands[2]);
                    int count = 1;

                    unordered_multimap<string, int>::iterator itr = wordList.find(commands[1]);
                    if (itr != wordList.end())
                    {
                        while (itr != wordList.end())
                        {
                            // if not found matching occurance
                            if (count > wordList.count(commands[1]))
                            {
                                cout << "No matching entry" << endl;
                                break;
                            }

                            // if found matching occurance
                            if (count == occurance)
                            {
                                // cout << itr->first << " "; // for debugging purposes
                                cout << itr->second << endl;
                                break;
                            }
                            count++;
                            itr++;
                        }
                    }
                    else
                    {
                        cout << "No matching entry" << endl;
                    }
                }
            }
        }

        // The "new" command resets the word list to original (empty) state.
        // It should NOT take any arguments.
        else if (firstCommand.compare("new") == 0 && commands.size() == 1)
        {
            wordList.clear();
            isLoaded = false;
        }

        // The "end" command resets the word list to its original (empty) state.
        // It should NOT take any argument
        else if (firstCommand.compare("end") == 0 && commands.size() == 1)
        {
            command = firstCommand;
        }

        // Captures empty commands so that it doesn't end up in the invalid commands.
        else if (firstCommand.compare("") == 0)
        {
        }

        // Handles invalid/bad commands.
        else
        {
            cout << "ERROR: Invalid command" << endl;
        }

        command = firstCommand; // enables while loop to check for the "end" command
    } while (command.compare("end") != 0);

    // cout << "Out of while loop" << endl; // for debugging purposes
    return 0;
}
