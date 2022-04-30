#include <iostream>
#include <string>
#include "../headers/Dictionary.h"
#include "../headers/Entry.h"

int main(){
    // Dictionary<std::string, int> dict;
    // Dictionary<int, std::string> dict;
    Dictionary<std::string, std::string> dict;
    // Dictionary<int, int> dict;

    std::cout << dict.add("John", "775-555-1234");
    // std::cout << dict.add("Jane", "775-555-1235");
    // std::cout << dict.add("Joe", "775-555-1236");
    // std::cout << dict.add("Jill", "775-555-1237");
    // std::cout << dict.contains("Jill");
    // std::cout << dict.getValue("Jill");

    // std::cout << dict.add("Jack", "775-555-1238");
    // std::cout << dict.add("Jill", "775-555-1239"); // update
    // std::cout << dict.contains("Jill");
    // std::cout << dict.getValue("Jill");
    // std::cout << dict.remove("Jill");
    // std::cout << dict.contains("Jill");
    // dict // prints out the dictionary
    return 0;
}