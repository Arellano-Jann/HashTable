#include <iostream>
#include <string>
#include "../headers/Dictionary.h"
#include "../headers/Entry.h"

int main(){
    // Dictionary<std::string, int> dict;
    // Dictionary<int, std::string> dict;
    Dictionary<std::string, std::string> dict;
    // Dictionary<int, int> dict;

    std::cout << std::boolalpha << dict.add("John", "775-555-1234") << std::endl;
    std::cout << std::boolalpha << dict.add("Jane", "775-555-1235") << std::endl;
    std::cout << std::boolalpha << dict.add("Joe", "775-555-1236") << std::endl;
    std::cout << std::boolalpha << dict.add("Jill", "775-555-1237") << std::endl;
    std::cout << std::boolalpha << dict.contains("Jill") << std::endl;
    std::cout << std::boolalpha << dict.getValue("Jill") << std::endl;

    std::cout << std::boolalpha << dict.add("Jack", "775-555-1238") << std::endl;
    std::cout << std::boolalpha << dict.add("Jill", "775-555-1239") << std::endl; // update
    std::cout << std::boolalpha << dict.contains("Jill") << std::endl;
    std::cout << std::boolalpha << dict.getValue("Jill") << std::endl;
    std::cout << std::boolalpha << dict.remove("Jill") << std::endl;
    std::cout << std::boolalpha << dict.contains("Jill") << std::endl;
    // dict // prints out the dictionary
    return 0;
}