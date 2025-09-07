#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// ----------- Hierarchical Directory Structure ------------
struct Directory {
    string name;
    vector<string> files;
    vector<Directory> subdirs;
};

void display(Directory d, string indent = "") {
    cout << indent << d.name << "/\n";
    for (auto &f : d.files) cout << indent << "  " << f << endl;
    for (auto &sd : d.subdirs) display(sd, indent + "  ");
}

int main() {
    // ------------------ Single Level Directory ------------------
    cout << "\n--- Single Level Directory ---\n";
    int n;
    cout << "Enter number of files: ";
    cin >> n;
    vector<string> files;
    for (int i = 0; i < n; i++) {
        string fname;
        cout << "Enter file name: ";
        cin >> fname;
        files.push_back(fname);
    }
    cout << "\nFiles in Directory:\n";
    for (auto &f : files) cout << f << endl;

    // ------------------ Two Level Directory ------------------
    cout << "\n--- Two Level Directory ---\n";
    int users;
    cout << "Enter number of users: ";
    cin >> users;
    map<string, vector<string>> dir;
    for (int i = 0; i < users; i++) {
        string uname;
        cout << "Enter user namefor user "<<i+1<<": ";
        cin >> uname;
        int fcount;
        cout << "Enter number of files for " << uname << ": ";
        cin >> fcount;
        vector<string> ufiles;
        for (int j = 0; j < fcount; j++) {
            string fname;
            cout << "Enter file name: ";
            cin >> fname;
            ufiles.push_back(fname);
        }
        dir[uname] = ufiles;
    }
    cout << "\nTwo Level Directory:\n";
    for (auto &u : dir) {
        cout << u.first << ":\n";
        for (auto &f : u.second) cout << "  " << f << endl;
    }

    // ------------------ Hierarchical Directory ------------------
    cout << "\n--- Hierarchical Directory ---\n";
    Directory root;
    root.name = "root";
    root.files = {"file1", "file2"};

    Directory sub1;
    sub1.name = "subdir1";
    sub1.files = {"a.txt"};

    Directory sub2;
    sub2.name = "subdir2";
    sub2.files = {"b.txt"};

    root.subdirs.push_back(sub1);
    root.subdirs.push_back(sub2);

    cout << "Hierarchical Directory Structure:\n";
    display(root);

    return 0;
}
