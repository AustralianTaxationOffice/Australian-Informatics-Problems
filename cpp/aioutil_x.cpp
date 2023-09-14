#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;


int main(int argc, char* argv[])
{
    if 
    (!(
        argc == 3
    ))
    {
        std::cout << "Error! Exactly three arguments must be used. Usage: aioutil [c++filename] [ioname and foldername]\n";
        exit(-1);
    }
    std::string folderName = argv[2];
    fs::create_directory(folderName);

    std::cout << "c++ File Name: " << argv[1] << '\n';
    if (argc == 3)
        std::cout << "io File Name: " << argv[2] << '\n';

    if
    (
        fs::exists(std::string(folderName + "/" + argv[1] + ".cpp")) ||
        [&] {
            if (argc == 3)
                return fs::exists(folderName + "/" + argv[2] + "in.txt") || fs::exists(folderName + "/" + argv[2] + "out.txt");
            else return false;
        } ()
    )
    {
        std::cout << "Warn! One or more of the intended files to create already exists, enter \"y\" to overwrite.\n";

        char confirm;
        std::cin >> confirm;
        switch (confirm)
        {
        case 'y':
            break;
        default:
            std::cout << "Error! Overwrite not confirmed.\n";
            exit(-1);
        }
    }

    try
    {
        auto openCpp = [&]
        {
            std::string cppFilePath;
            cppFilePath = argv[1];
            cppFilePath += "/";
            cppFilePath += argv[1];
            cppFilePath += ".cpp";
            if (system(std::string("code -r \"" + cppFilePath + "\"").c_str()) != 0)
                std::cout << "Warn! Visual Studio Code CLI did not exit with code 0. (Opening " << argv[1] << ".cpp.\n";
        };

        std::ofstream outcpp(folderName + "/" + argv[1] + ".cpp");
        if (argc == 3)
        {
            outcpp.write
(R"(#include <iostream>
#include <cmath>
using namespace std;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define piss(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define int long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
signed main()
{
    piss()", 464);
            outcpp.write(argv[2], strlen(argv[2]));
            outcpp.write
(R"();
})", 4);
            outcpp.close();

            {
                std::ofstream intxt(folderName + "/" + argv[2] + "in.txt");
                std::ofstream outtxt(folderName + "/" + argv[2] + "out.txt");
            }

            openCpp();
            if (system(std::string("code -r \"").append(folderName).append("/").append(argv[2]).append("in.txt\"").c_str()) != 0)
                std::cout << "Warn! Visual Studio Code CLI did not exit with code 0. (Opening " << argv[2] << "in.txt.\n";
            if (system(std::string("code -r \"").append(folderName).append("/").append(argv[2]).append("out.txt\"").c_str()) != 0)
                std::cout << "Warn! Visual Studio Code CLI did not exit with code 0. (Opening " << argv[2] << "out.txt.\n";
        }
        else
        {
            outcpp.write
(R"(#include <iostream>
#include <cmath>
using namespace std;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define piss(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
#define int long long
#define umap std::unordered_map
#define ummap std::unordered_multimap
#define uset std::unordered_set
#define umset std::unordered_multiset
#define mmap std::multimap
#define mset std::multiset
signed main()
{
    speed();
})", 469);
            outcpp.close();
            openCpp();
        }
    }
    catch (const std::ofstream::failure& ex)
    {
        std::cerr << "Error! " << ex.what() << '\n';
        exit(-1);
    }
}