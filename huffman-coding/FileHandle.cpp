#include "FileHandle.h"

using namespace std;

string FileHandle::FileReader(string fileName) {
    string data;
    ifstream infile;
    infile.open(fileName, ios::in);
    if (!infile.is_open())
        throw "file khong ton tai";
    infile >> data;
    return data;
}

void FileHandle::FileWriter(string fileName, string data) {
    ofstream outfile;
    outfile.open(fileName, ios::app);
    if (!outfile.is_open())
        throw "file khong ton tai";
    outfile << '\n' + data;
}
