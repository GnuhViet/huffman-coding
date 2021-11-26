#pragma once

#include "DeCoding.cpp"
#include "EnCoding.cpp"
#include "FileHandle.cpp"

#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>


using namespace std;

class Menu {
private:
    static void choice1();
    static void choice2();
    static void pause();
    static string getPath();
public:
    static void primary();
};

void Menu::primary() {
    int choice;
    do {
        system("cls");
        cout << "-------------Menu---------------" << endl;
        cout << "1. Nen file" << endl;
        cout << "2. Giai nen file" << endl;
        cout << "3. exit" << endl;
        cout << "--------------------------------" << endl;
        cout << "Nhap lua chon: "; cin >> choice;
        cout << "--------------------------------" << endl;
        switch (choice) {
            case 1:
                choice1();
                pause();
                break;
            case 2:
                choice2();
                pause();
                break;
            case 3:
                break;
            default:
                cout << "vui long nhap so tu 1 den 3" << endl;
        }
    } while (choice != 3);
}

void Menu::choice1() {
    string filePath;
    string treePath;
    cout << "nhap duong dan file:"; filePath = getPath();
    cout << "nhap duong dan luu file tree.dat:"; treePath = getPath();

    cout << "-duong dan:" + filePath << endl;

    try {
        const string msg = FileHandle::StringReader(filePath);
        EnCoding obj(msg);
        FileHandle::StringWriter(filePath, obj.getCodedString());
        FileHandle::TreeWriter(treePath, obj.getRoot());
        cout << "nen file thanh cong";
    } catch (const char* &emsg) {
        cerr << emsg << endl;
    }

}

void Menu::choice2() {
    //system("cls");
    string filePath;
    string treePath;

    cout << "nhap duong dan file: "; filePath = getPath();
    cout << "nhap duong dan file tree.dat: "; treePath = getPath();

    cout << "-Duong dan file:" << filePath << "\n-Duong dan tree:" << treePath << endl;

    try {
        const string codedMsg = FileHandle::StringReader(filePath);
        TreeNode *root = FileHandle::TreeReader(treePath);

        DeCoding obj(codedMsg, root);

        FileHandle::StringWriter(filePath, obj.getDeCodedString());
        cout << "giai nen thanh cong";
    } catch (const char* &emsg) {
        cerr << emsg << endl;
    }
}

void Menu::pause() {
    cout << "\n Bam phim bat ky de quay lai menu chinh...";
    getch();
}

string Menu::getPath() {
    string path;
    rewind(stdin);
    getline(cin, path);
    fflush(stdin);
    return path;
}
