/*

We all steal from StackOverflow. But, just because I want to, I'll be citing the sources of what I steal.

*/
#include <iostream>

// Blatantly Stolen From: https://stackoverflow.com/questions/874134/find-out-if-string-ends-with-another-string-in-c
bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}