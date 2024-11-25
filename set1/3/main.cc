#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main(int argumentQuantity, char* fileNames[])
{
    if (argumentQuantity != 3)
    {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return 1;
    }
    std::string toCopy = fileNames[1];
    std::string result = fileNames[2];

    fs::path pathToCopy(std::move(toCopy));
    fs::path pathResult(std::move(result));
    fs::copy(pathToCopy, pathResult, fs::copy_options::overwrite_existing);
    last_write_time(pathResult, last_write_time(pathToCopy));
}
