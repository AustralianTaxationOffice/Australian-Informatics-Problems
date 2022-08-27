#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    if
    (!(
        argc == 3 ||
        [&] {
            if (argc == 2)
            {
                std::cout << "Warn! io file name not provided, input-output files will not be created!\n";
                return true;
            }
            else return false;
        } ()
    ))
    {
        std::cout << "Error! Exactly two or three arguments must be used. Usage: aioutil [cxxname] [opt: ioname]\n";
        exit(-1);
    }

    std::cout << "cxx File Name: " << argv[1] << '\n';
    if (argc == 3)
        std::cout << "io File Name: " << argv[2] << '\n';

    if
    (
        fs::exists(std::string(argv[1]).append(".cpp")) ||
        [&] {
            if (argc == 3)
                return fs::exists(std::string(argv[2]).append("in.txt")) || fs::exists(std::string(argv[2]).append("out.txt"));
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
            if (system(std::string("code -r \"").append(argv[1]).append(".cpp\"").c_str()) != 0)
                std::cout << "Warn! Visual Studio Code CLI did not exit with code 0. (Opening " << argv[1] << ".cpp.\n";
        };

        std::ofstream outcpp(std::string(argv[1]).append(".cpp"));
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
                std::ofstream intxt(std::string(argv[2]).append("in.txt"));
                std::ofstream outtxt(std::string(argv[2]).append("out.txt"));
            }

            openCpp();
            if (system(std::string("code -r \"").append(argv[2]).append("in.txt\"").c_str()) != 0)
                std::cout << "Warn! Visual Studio Code CLI did not exit with code 0. (Opening " << argv[2] << "in.txt.\n";
            if (system(std::string("code -r \"").append(argv[2]).append("out.txt\"").c_str()) != 0)
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