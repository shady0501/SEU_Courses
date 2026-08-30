#include <iostream>
#include <string>
#include <Windows.h>
#include<fstream>
#include<cstring>
#include <unordered_map>
#include <stack>
#include <tuple>
#include <Windows.h>

using namespace std;

unordered_map<int, unordered_map<string, string>> action_table = {
    {0,  {{"if", "S2"}, {"else", "na"}, {"while", "S3"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {1,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "Succ"}}},
    {2,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "S6"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {3,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "S7"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {4,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "S9"}, {"*", "S10"}, {"i", "na"}, {";", "S8"}, {"$", "na"}}},
    {5,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "r6"}, {"*", "r6"}, {"i", "na"}, {";", "r6"}, {"$", "na"}}},
    {6,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S12"}, {";", "na"}, {"$", "na"}}},
    {7,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S12"}, {";", "na"}, {"$", "na"}}},
    {8,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "r3"}}},
    {9,  {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {10, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {11, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "S16"}, {"+", "S17"}, {"*", "S18"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {12, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "r6"}, {"+", "r6"}, {"*", "r6"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {13, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "S19"}, {"+", "S17"}, {"*", "S18"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {14, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "r4"}, {"*", "S10"}, {"i", "na"}, {";", "r4"}, {"$", "na"}}},
    {15, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "r5"}, {"*", "r5"}, {"i", "na"}, {";", "r5"}, {"$", "na"}}},
    {16, {{"if", "S21"}, {"else", "na"}, {"while", "S22"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {17, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S12"}, {";", "na"}, {"$", "na"}}},
    {18, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S12"}, {";", "na"}, {"$", "na"}}},
    {19, {{"if", "S2"}, {"else", "na"}, {"while", "S3"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {20, {{"if", "na"}, {"else", "S27"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {21, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "S28"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {22, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "S29"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {23, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "S9"}, {"*", "S10"}, {"i", "na"}, {";", "S30"}, {"$", "na"}}},
    {24, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "r4"}, {"+", "r4"}, {"*", "S18"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {25, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "r5"}, {"+", "r5"}, {"*", "r5"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {26, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "r2"}}},
    {27, {{"if", "S2"}, {"else", "na"}, {"while", "S3"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {28, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S12"}, {";", "na"}, {"$", "na"}}},
    {29, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S12"}, {";", "na"}, {"$", "na"}}},
    {30, {{"if", "na"}, {"else", "r3"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {31, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "r1"}}},
    {32, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "S34"}, {"+", "S17"}, {"*", "S18"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {33, {{"if", "na"}, {"else", "na"}, {"while", "na"}, {"(", "na"}, {")", "S35"}, {"+", "S17"}, {"*", "S18"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {34, {{"if", "S21"}, {"else", "na"}, {"while", "S22"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {35, {{"if", "S21"}, {"else", "na"}, {"while", "S22"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {36, {{"if", "na"}, {"else", "S38"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {37, {{"if", "na"}, {"else", "r2"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}},
    {38, {{"if", "S21"}, {"else", "na"}, {"while", "S22"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "S5"}, {";", "na"}, {"$", "na"}}},
    {39, {{"if", "na"}, {"else", "r1"}, {"while", "na"}, {"(", "na"}, {")", "na"}, {"+", "na"}, {"*", "na"}, {"i", "na"}, {";", "na"}, {"$", "na"}}}
};

unordered_map<int, unordered_map<char, int>> goto_table = {
    {0, {{'S', 1}, {'E', 4}}},
    {1, {{'S', -1}, {'E', -1}}},
    {2, {{'S', -1}, {'E', -1}}},
    {3, {{'S', -1}, {'E', -1}}},
    {4, {{'S', -1}, {'E', -1}}},
    {5, {{'S', -1}, {'E', -1}}},
    {6, {{'S', -1}, {'E', 11}}},
    {7, {{'S', -1}, {'E', 13}}},
    {8, {{'S', -1}, {'E', -1}}},
    {9, {{'S', -1}, {'E', 14}}},
    {10, {{'S', -1}, {'E', 15}}},
    {11, {{'S', -1}, {'E', -1}}},
    {12, {{'S', -1}, {'E', -1}}},
    {13, {{'S', -1}, {'E', -1}}},
    {14, {{'S', -1}, {'E', -1}}},
    {15, {{'S', -1}, {'E', -1}}},
    {16, {{'S', 20}, {'E', 23}}},
    {17, {{'S', -1}, {'E', 24}}},
    {18, {{'S', -1}, {'E', 25}}},
    {19, {{'S', 26}, {'E', 4}}},
    {20, {{'S', -1}, {'E', -1}}},
    {21, {{'S', -1}, {'E', -1}}},
    {22, {{'S', -1}, {'E', -1}}},
    {23, {{'S', -1}, {'E', -1}}},
    {24, {{'S', -1}, {'E', -1}}},
    {25, {{'S', -1}, {'E', -1}}},
    {26, {{'S', -1}, {'E', -1}}},
    {27, {{'S', 31}, {'E', 4}}},
    {28, {{'S', -1}, {'E', 32}}},
    {29, {{'S', -1}, {'E', 33}}},
    {30, {{'S', -1}, {'E', -1}}},
    {31, {{'S', -1}, {'E', -1}}},
    {32, {{'S', -1}, {'E', -1}}},
    {33, {{'S', -1}, {'E', -1}}},
    {34, {{'S', 36}, {'E', 23}}},
    {35, {{'S', 37}, {'E', 23}}},
    {36, {{'S', -1}, {'E', -1}}},
    {37, {{'S', -1}, {'E', -1}}},
    {38, {{'S', 39}, {'E', 23}}},
    {39, {{'S', -1}, {'E', -1}}}
};

//规则编号，产生式左侧，产生式右侧，产生式右侧符号个数
tuple<int, char, string, int> grammar[6] = {
    {1, 'S',"if (E) S else S" ,7},
    {2, 'S',"while (E) S" ,5},
    {3, 'S',"E;", 2},
    {4, 'E',"E + E", 3},
    {5, 'E',"E * E", 3},
    {6, 'E',"i", 1}
};

//符号栈和状态栈
struct StackElement {
    char character;
    int state;

    StackElement(char ch, int st) : character(ch), state(st) {}
};
stack<StackElement> myStack;

const int ERROR_STATE = -1;
const int ACCEPT_STATE = -2;

void syntaxAnalysis(const string& filePath) {
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    char currentChar;
    string currentString;
    int currentState = 0; // 初始状态
    myStack.push(StackElement('$', 0)); // 将初始状态压入状态栈
    inFile.seekg(0, ios::beg);
    string token; // 用于存储识别的单词或词法单元
    bool Flag = true;
    while (1) {
        if (Flag) {
            inFile.get(currentChar);
            if (!inFile.eof()) {

                // 根据当前状态和读入的字符执行相应的动作
                if (currentChar == ' ' || currentChar == '\n') {
                    continue; // 忽略空格和换行符
                }
                else if (currentChar == 'i') {
                    char nextChar;
                    if (inFile.get(nextChar)) {
                        if (nextChar == 'f') {
                            currentString = "if";
                        }
                        else {
                            inFile.putback(nextChar);
                            currentString = 'i';
                        }
                    } 
                    else {
                        currentString = "i"; // 读取失败，设置为单字符
                    }
                }
                else if (currentChar == 'e') {    // 可能是 else
                    char nextChar1, nextChar2, nextChar3;
                    if (inFile.get(nextChar1) && inFile.get(nextChar2) && inFile.get(nextChar3)) {
                        if (nextChar1 == 'l' && nextChar2 == 's' && nextChar3 == 'e') {
                            currentString = "else"; // 匹配 else
                        }
                        else {
                            // 回退字符
                            inFile.putback(nextChar3);
                            inFile.putback(nextChar2);
                            inFile.putback(nextChar1);
                            currentString = "e"; // 单字符 e
                        }
                    }
                    else {
                        currentString = "e"; // 读取失败，设置为单字符
                    }
                }
                else if (currentChar == 'w') {   // 可能是 while
                    char nextChar1, nextChar2, nextChar3, nextChar4;
                    if (inFile.get(nextChar1) && inFile.get(nextChar2) && inFile.get(nextChar3) && inFile.get(nextChar4)) {
                        if (nextChar1 == 'h' && nextChar2 == 'i' && nextChar3 == 'l' && nextChar4 == 'e') {
                            currentString = "while"; // 匹配 while
                        }
                        else {
                            // 回退字符
                            inFile.putback(nextChar4);
                            inFile.putback(nextChar3);
                            inFile.putback(nextChar2);
                            inFile.putback(nextChar1);
                            currentString = "w"; // 单字符 w
                        }
                    }
                    else {
                        currentString = "w"; // 读取失败，设置为单字符
                    }
                }
                else if (currentChar == '(' || currentChar == ')' || currentChar == '+' || currentChar == '*' || currentChar == ';') {
                    currentString = currentChar;
                }
                else if (currentChar == '$') {
                    currentChar = '$'; // 设置当前字符为结束符号
                    currentString = '$';
                }
            }
            else {
                currentChar = '$';
                currentString = '$';
            }
        }
        
        // 根据读入字符和当前状态查找LR(1)分析表
        string action;

        // 小写字符，从ACTION表中查找操作
        action = action_table[currentState][currentString];
        Flag = true;
        if (action == "Succ") {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout << "Success.";
            return; // 接受状态，停止分析
        }
        else if (action[0] == 'S') {
            // 移进操作
            int nextState = stoi(action.substr(1)); // 下一个状态
            myStack.push(StackElement(currentChar, nextState)); // 将当前字符和下一个状态压入栈
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	//字体恢复原来的颜色
            cout << "ACTION: " << currentString << " to state " << nextState << endl;
            currentState = nextState;

        }
        else if (action[0] == 'r') {
            // 规约操作
            int ruleIndex = stoi(action.substr(1)); // 规则编号
            int ruleNum = get<0>(grammar[ruleIndex - 1]); // 规则编号
            char left = get<1>(grammar[ruleIndex - 1]); // 规约左部符号
            string right = get<2>(grammar[ruleIndex - 1]); // 规约右部符号
            int ruleLen = get<3>(grammar[ruleIndex - 1]);//规约右部符号个数
            // 进行规约操作，弹出规约的字符和状态
            for (size_t i = 0; i < ruleLen; ++i) {
                myStack.pop();
            }
            // 获取当前状态并查找规约后的状态
            currentState = myStack.top().state;
            char leftSymbol = left;
            int nextState = goto_table[currentState][leftSymbol];
            myStack.push(StackElement(leftSymbol, nextState)); // 将左部符号和规约后的状态压入栈
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);	//绿色
            cout << "Reduce using " << ruleNum << ": " << right << " -> " << left << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	//蓝色
            cout << "GOTO: " << leftSymbol << " to state " << nextState << endl;
            currentState = nextState;
            Flag = false;
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);	//红色
            cout << "Error: Invalid action." << endl;
            cout << "Maybe near the \"" << currentString << "\" is wrong" << endl;
            return; // 遇到错误，停止分析
        }

    }

    inFile.close(); // 关闭文件
}

int main() {
    string filename;
    cout << "Please enter the file path name：";
    cin >> filename;
    syntaxAnalysis(filename);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	//字体恢复原来的颜色
    return 0;
}