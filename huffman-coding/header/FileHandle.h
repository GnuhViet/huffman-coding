#pragma once
#include <fstream>
#include <string>

class FileHandle {
public:
	static std::string FileReader(std::string fileName);
	static void FileWriter(std::string fileName, std::string data);
};

