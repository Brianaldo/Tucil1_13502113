#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define CAPACITY 100

typedef struct {
    char content[CAPACITY][CAPACITY];
    int m, n;
} Puzzle;

typedef struct {
    string content[CAPACITY];
    int count;
} WordList;

void file2data(string fileName, Puzzle *P, WordList *WL) {
    ifstream file("./test/" + fileName);
    string str, temp;

    int i = 0;
    while (getline(file, str) && str != "") {
        temp = "";
        for (int j = 0; j < str.length(); ++j) {
            if (str[j] != ' ') {
                temp = temp + str[j];
            }
        }
        strcpy((*P).content[i], temp.c_str());
        ++i;
    }
    (*P).m = i; (*P).n = temp.length();

    i = 0;
    while (getline(file, str)) {
        (*WL).content[i] = str;
        ++i;
    }
    (*WL).count = i;
}

void searchWord(Puzzle P, string W, int *count) {
    int length = W.length();
    char char_W[length];
    strcpy(char_W, W.c_str());

    bool found = false;
    for (int i = 0; i < P.m; ++i) {
        for (int j = 0; j < P.n; ++j) {
            // Check East
            if ((!found) && (j + length <= P.n)) {
                int k = 0;
                while ((k < length) && (P.content[i][j+k] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i) && (m == j + n)) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check Southeast
            if ((!found) && (i + length <= P.m) && (j + length <= P.n)) {
                int k = 0;
                while ((k < length) && (P.content[i+k][j+k] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i + n) && (m == j + n)) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check South
            if ((!found) && (i + length <= P.m)) {
                int k = 0;
                while ((k < length) && (P.content[i+k][j] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i + n) && (m == j)) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check Southwest
            if ((!found) && (i + length <= P.m) && (j - length <= P.n) && (j - length + 1 >= 0)) {
                int k = 0;
                while ((k < length) && (P.content[i+k][j-k] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i + n) && (m == j - n)) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check West
            if ((!found) && (j - length <= P.n) && (j - length + 1 >= 0)) {
                int k = 0;
                while ((k < length) && (P.content[i][j-k] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i) && (m == j + ((n + 1) - k))) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check Northwest
            if ((!found) && (i - length <= P.m) && (i - length + 1 >= 0) && (j - length <= P.n) && (j - length + 1 >= 0)) {
                int k = 0;
                while ((k < length) && (P.content[i-k][j-k] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i + ((n + 1) - k)) && (m == j + ((n + 1) - k))) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check North
            if ((!found) && (i - length <= P.m) && (i - length + 1 >= 0)) {
                int k = 0;
                while ((k < length) && (P.content[i-k][j] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i + ((n + 1) - k)) && (m == j)) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }

            // Check Northeast
            if ((!found) && (i - length <= P.m) && (i - length + 1 >= 0) && (j + length <= P.n)) {
                int k = 0;
                while ((k < length) && (P.content[i-k][j+k] == char_W[k])) {
                    ++(*count);
                    ++k;
                }
                if (k == length) {
                    found = true;
                    int n = 0;
                    for (int l = 0; l < P.m; ++l) {
                        for (int m = 0; m < P.n; ++m) {
                            if ((n < k) && (l == i + ((n + 1) - k)) && (m == j + (k - n - 1))) {
                                ++n;
                                cout << P.content[l][m] << " ";
                            } else {
                                cout << "- ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }
            if (found) break;
        }
        if (found) break;
    }
    if (!found) {
        cout << W << " Not Found!" << "\n";
    }
}

int main() {
    Puzzle P;
    WordList WL;

    // Inisialisasi
    P.m = 0; P.n = 0;
    WL.count = 0;

    // Read File
    string fileName;
    cout << "\nInput your test file name: ";
    cin >> fileName;
    cout << "\n";
    file2data(fileName, &P, &WL);

    // Brute Force
    int count = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < WL.count; ++i) {
        searchWord(P, WL.content[i], &count);
        cout << "\n";
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken       : "<< duration.count() << " microseconds \n";

    cout << "Total comparison : " << count << " letters\n\n";

    return 0;
}