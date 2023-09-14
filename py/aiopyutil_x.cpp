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
        std::cout << "Error! Exactly three arguments must be used. Usage: aioutil [pyfilename] [ioname and foldername]\n";
        exit(-1);
    }
    std::string folderName = argv[2];
    fs::create_directory(folderName);

    std::cout << "python File Name: " << argv[1] << '\n';
    if (argc == 3)
        std::cout << "io File Name: " << argv[2] << '\n';

    if
    (
        fs::exists(std::string(folderName + "/" + argv[1] + ".py")) ||
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
            std::string pyFilePath;
            pyFilePath = argv[1];
            pyFilePath += "/";
            pyFilePath += argv[1];
            pyFilePath += ".py";
            if (system(std::string("code -r \"" + pyFilePath + "\"").c_str()) != 0)
                std::cout << "Warn! Visual Studio Code CLI did not exit with code 0. (Opening " << argv[1] << ".py.\n";
        };

        std::ofstream outpy(folderName + "/" + argv[1] + ".py");

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
    catch (const std::ofstream::failure& ex)
    {
        std::cerr << "Error! " << ex.what() << '\n';
        exit(-1);
    }
}