#include <iostream>
#include <filesystem>
#include <cstdio>
#include <cstdlib> // For std::exit()

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <source_file> <destination_file>\n";
        return 1;
    }

    const char *sourceFile = argv[1];
    const char *destinationFile = argv[2];

    // Check if the source file exists
    if (!fs::exists(sourceFile))
    {
        std::cerr << "Error: Source file " << sourceFile << " does not exist.\n";
        return 1;
    }

    // Copy the file
    try
    {
        fs::copy_file(sourceFile, destinationFile, fs::copy_options::overwrite_existing);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error copying file: " << e.what() << "\n";
        return 1;
    }

    // Copy the timestamps
    try
    {
        auto sourceTime = fs::last_write_time(sourceFile);
        fs::last_write_time(destinationFile, sourceTime);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error copying timestamp: " << e.what() << "\n";
        return 1;
    }

    std::cout << "File copied successfully with the same timestamp.\n";
    return 0;
}

