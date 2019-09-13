//  File: wl.h
//
//  Description: Assignment #1: C++ Word Locator - CS 564 Fall 2019
//  UW Campus ID: 9075332602
//  email: fakhrulanuar@wisc.edu

#include <string>
using namespace std;

/**
 * A utility function to remove whitespaces from a string.
 *
 * @param str The string to be cleaned.
 * @return A string without whitespaces.
 */
string removeWhitespace(string);

/**
 * A utility function to convert a string to lowercase.
 * Uses toLower().
 *
 * @param str The string to be lowercased.
 * @return A lowercased string (if applicable).
 */
string toLowercase(string);

/**
 * A helper function that returns a "cleaned" command i.e. lowercased and whitespaces-removed.
 *
 * @param command The command to be cleaned.
 * @return A vector of strings containing the cleaned commands.
 */
vector<string> parseCommand(string);

/**
 * Checks if a string is a valid word i.e. consists of only alphabetical characters, apostrophes, and/or numbers.
 * 
 * @param word The string to be checked.
 * @return true if valid word, false otherwise
 */
bool isValidWord(string);

/**
 * Checks if a string is a valid occurance i.e a number that is larger than 0.
 * 
 * @param word The string to be checked.
 * @return true if valid occurance, false otherwise
 */
bool isValidOccurance(string);
