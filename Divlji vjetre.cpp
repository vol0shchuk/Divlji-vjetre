// Divlji vjetre.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager {
public:
    void createFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Unable to create file");
        }
        cout << "File created successfully.\n";
    }

    void writeFile(const string& filename, const string& content) {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file for writing");
        }
        file << content;
        cout << "Content written to file successfully.\n";
    }

    void readFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file for reading");
        }
        string line;
        cout << "File content:\n";
        while (getline(file, line)) {
            cout << line << '\n';
        }
    }

    void copyFile(const string& source, const string& destination) {
        ifstream srcFile(source);
        if (!srcFile.is_open()) {
            throw runtime_error("Unable to open source file");
        }
        ofstream destFile(destination);
        if (!destFile.is_open()) {
            throw runtime_error("Unable to open destination file");
        }
        destFile << srcFile.rdbuf();
        cout << "File content copied successfully.\n";
    }

    void deleteFile(const string& filename) {
        if (remove(filename.c_str()) != 0) {
            throw runtime_error("Error deleting file");
        }
        cout << "File deleted successfully.\n";
    }

    void renameFile(const string& oldname, const string& newname) {
        if (rename(oldname.c_str(), newname.c_str()) != 0) {
            throw runtime_error("Error renaming file");
        }
        cout << "File renamed successfully.\n";
    }
};

int main() {
    FileManager fileManager;
    string filename, content, source, destination, newname;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create File\n";
        cout << "2. Write to File\n";
        cout << "3. Read File\n";
        cout << "4. Copy File\n";
        cout << "5. Delete File\n";
        cout << "6. Rename File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter filename to create: ";
                    cin >> filename;
                    fileManager.createFile(filename);
                    break;
                case 2:
                    cout << "Enter filename to write to: ";
                    cin >> filename;
                    cout << "Enter content to write: ";
                    cin.ignore();
                    getline(cin, content);
                    fileManager.writeFile(filename, content);
                    break;
                case 3:
                    cout << "Enter filename to read: ";
                    cin >> filename;
                    fileManager.readFile(filename);
                    break;
                case 4:
                    cout << "Enter source filename: ";
                    cin >> source;
                    cout << "Enter destination filename: ";
                    cin >> destination;
                    fileManager.copyFile(source, destination);
                    break;
                case 5:
                    cout << "Enter filename to delete: ";
                    cin >> filename;
                    fileManager.deleteFile(filename);
                    break;
                case 6:
                    cout << "Enter current filename: ";
                    cin >> filename;
                    cout << "Enter new filename: ";
                    cin >> newname;
                    fileManager.renameFile(filename, newname);
                    break;
                case 7:
                    cout << "Exiting program.\n";
                    return 0;
                default:
                    cerr << "Invalid choice! Please try again.\n";
                    break;
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << '\n';
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
