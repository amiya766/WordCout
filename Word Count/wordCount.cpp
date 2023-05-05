#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int count_chars(string filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Cannot open file " << filename << endl;
        exit(1);
    }
    ifs >> noskipws; // 不忽略空格
    int count = count_if(istream_iterator<char>(ifs), istream_iterator<char>(), [](char c) {
        return c != '\n' && c != '\t' && c != ' ';
        });
    return count;
}

int count_words(string filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Cannot open file " << filename << endl;
        exit(1);
    }
    int count = 0;
    string line, word;
    while (getline(ifs, line)) {
        stringstream ss(line);
        while (ss >> word) {
            count++;
        }
    }
    return count;
}

int main(int argc, char const* argv[]) {
    if (argc < 2 || argc > 3) {
        cerr << "Usage: " << argv[0] << " -c/-w [input_file_name]" << endl;
        exit(1);
    }
    string filename;
    if (argc == 2) {
        filename = "input.txt";
    }
    else {
        filename = argv[2];
    }
    if (string(argv[1]) == "-c") {
        cout << "字符数：" << count_chars(filename) << endl;
    }
    else if (string(argv[1]) == "-w") {
        cout << "单词数：" << count_words(filename) << endl;
    }
    else {
        cerr << "Invalid parameter " << argv[1] << endl;
        exit(1);
    }
    return 0;
}
