#include "DeCoding.h"
#include "EnCoding.h"
#include "FileHandle.h"
#include "Menu.h"


void Menu::primary() {
    int choice;
    do {
        system("cls");
        cout << "-------------Menu---------------" << endl;
        cout << "1. Ma hoa" << endl;
        cout << "2. Giai ma" << endl;
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
                cout << "cam on ban da su dung !!" << endl;
                break;
            default:
                cout << "vui long nhap so tu 1 den 3" << endl;
        }
    } while (choice != 3);
}

void Menu::choice1() {
    string filePath;
    string treePath;
    cout << "nhap duong dan file            -VD: D:\\New folder\\input.txt" << endl;
    cout << "Path: "; filePath = getPath();
    cout << "\nnhap duong dan luu file tree -VD: D:\\New folder\\tree.dat" << endl;
    cout << "Path: "; treePath = getPath();

    try {
        const string msg = FileHandle::StringReader(filePath);
        EnCoding obj(msg);
        FileHandle::StringWriter(filePath, obj.getCodedString());
        FileHandle::TreeWriter(treePath, obj.getRoot());

        cout << "\n---Ma hoa thanh cong---";
    } catch (const char* &emsg) {
        cerr << emsg << endl;
    }
}

void Menu::choice2() {
    string filePath;
    string treePath;

    cout << "nhap duong dan file:        -VD: D:\\New folder\\input.txt" << endl;
    cout << "Path: ";  filePath = getPath();
    cout << "\nnhap duong dan file tree: -VD: D:\\New folder\\tree.dat" << endl;
    cout << "Path: ";  treePath = getPath();

    try {
        const string codedMsg = FileHandle::StringReader(filePath);
        TreeNode *root = FileHandle::TreeReader(treePath);
        DeCoding obj(codedMsg, root);
        FileHandle::StringWriter(filePath, obj.getDeCodedString());

        cout << "\n---Giai ma thanh cong---";
        delete root;
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
