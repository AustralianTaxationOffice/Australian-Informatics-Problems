#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

void compile_file(std::string fileName, std::string folderName);

int main()
{
    std::string fileName;
    std::string folderName;
    std::ifstream input_file("aiocompiler.txt");
    input_file >> fileName;
    input_file >> folderName;
    if (std::filesystem::exists(folderName + "/" + fileName + ".cpp"))
    {
        compile_file(fileName, folderName);
    }
    else
    {
        std::cout << "file does not exist" << "\n";
        exit(1);
    }
    
}

void compile_file(std::string fileName, std::string folderName)
{
    // Modify this command to your liking:
    std::string command = "g++ " + folderName + "/" + fileName + ".cpp -o " + folderName + "/" + fileName + "";
    
    
    std::cout << command << "\n";
    std::cout << "Run this command? y/n";
    std::string request;
    std::cin >> request;
    if (request == "y")
    {
        system(command.c_str());
        std::cout << "file compiled";
    }
    else
    {
        exit(1);
    }

    
}