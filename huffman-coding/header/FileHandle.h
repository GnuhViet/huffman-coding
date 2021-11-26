#pragma once
#include <fstream>
#include <string>

class FileHandle {
public:
	static std::string FileReader(const std::string& fileName);
	static void FileWriter(const std::string& fileName, const std::string& data);
};

