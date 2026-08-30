#include <iostream>
#include <string>
#include <Windows.h>
#include<fstream>
#include<cstring>

using namespace std;

/* 单词编码 */
char keyword[][20] = { "if","then", "read","write","case","continue","else","for","switch","while","return","void","int","double","cin","cout","endl" };	//17个关键字
char delimiter[][10] = { "(",")","[","]","{","}",":",",",";","'","#",'"', };//12个界符
char operation[][10] = { "+","-","*","/","=",">","<","==",">=","<=","!=","&&","||","!","++","--","<<",">>" };//18个运算符
int numKey = 17;
int numDel = 12;
int numOpe = 18;
string stack = "";//工作栈		
int row = 1;
#define Maxline  1024

enum TokenCode
{
	// 关键字
	IF,
	THEN,
	READ,
	WRITE,
	CASE,
	CONTINUE,
	ELSE,
	FOR,
	SWITCH,
	WHILE,
	RETURN,
	K_VOID,
	K_INT,
	K_DOUBLE,
	K_CIN,
	K_COUT,
	K_ENDL,
	//运算符
	PLUS,
	MINUS,
	MUTIPLE,
	DIVIDE,
	EQUAL,
	BIGGER,
	SMALLER,
	E_COMPARE,
	BIGGER_EQUAL,
	SMALLER_EQUAL,
	NOT_EQUAL,
	AND,
	OR,
	NOT,
	SELF_PLUS,
	SELF_MINUS,
	LEFT_SHIFT,
	RIGHT_SHIFT,
	// 分隔符
	LEFT_YKH,
	RIGHT_YKH,
	LEFT_FKH,
	RIGHT_FKH,
	LEFT_DKH,
	RIGHT_DKH,
	COMMA,
	SEMOCOLOM,
	COLON,
	QUOTATION2,
	QUOTATION1,
	ZS,
	//标识符
	ID,
	// 数字
	T_INT,
	T_DOUBLE,
	//无法识别
	UNDEFINE
};

bool isLetter(char letter);	    //判断是否是整数
bool isDigit(char digit);		//判断是否是字母
int  Is_keyword(string s);		//判断字符串是否是关键字,是则返回下标，否则返回-1
int  Is_delimiter(string s);     //判断字符是否是分隔符，是返回下标，否则返回-1
int  Is_calculation(string s);	//判断字符串是否是运算符，是返回下标，否则返回-1

bool isLetter(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return true;
	return false;

}
bool isDigit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return true;
	return false;
}
int Is_keyword(string s) {
	for (int i = 0; i < numKey; ++i) {
		if (s == keyword[i]) {
			return i;
		}
	}
	return -1;
}
int Is_delimiter(string s) {
	for (int i = 0; i < numDel; ++i) {
		if (s == delimiter[i]) {
			return i;
		}
	}
	return -1;
}
int Is_calculation(string s) {
	for (int i = 0; i < numOpe; ++i) {
		if (s == operation[i]) {
			return i;
		}
	}
	return -1;
}
bool isInteger(const string& str) {
	if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
		return false;

	char* p;
	strtol(str.c_str(), &p, 10);

	return (*p == 0);
}

const char* getTokenCodeName(TokenCode code) {
	switch (code) {
	case IF: return "IF";
	case THEN: return "THEN";
	case READ: return "READ";
	case WRITE: return "WRITE";
	case CASE: return "CASE";
	case CONTINUE: return "CONTINUE";
	case ELSE: return "ELSE";
	case FOR: return "FOR";
	case SWITCH: return "SWITCH";
	case WHILE: return "WHILE";
	case RETURN: return "RETURN";
	case K_VOID: return "VOID";
	case K_INT: return "INT";
	case K_DOUBLE: return "DOUBLE";
	case K_CIN: return "CIN";
	case K_COUT:return "COUT";
	case K_ENDL: return "ENDL";
	case PLUS: return "PLUS";
	case MINUS: return "MINUS";
	case MUTIPLE: return "MUTIPLE";
	case DIVIDE: return "DIVIDE";
	case EQUAL: return "EQUAL";
	case BIGGER: return "BIGGER";
	case SMALLER: return "SMALLER";
	case E_COMPARE: return "E_COMPARE";
	case BIGGER_EQUAL: return "BIGGER_EQUAL";
	case SMALLER_EQUAL: return "SMALLER_EQUAL";
	case NOT_EQUAL: return "NOT_EQUAL";
	case AND: return "AND";
	case OR: return "OR";
	case NOT: return "NOT";
	case SELF_PLUS: return "SELF_PLUS";
	case SELF_MINUS: return "SELF_MINUS";
	case LEFT_SHIFT: return "LEFT_SHIFT";
	case RIGHT_SHIFT: return "RIGHT_SHIFT";
	case LEFT_YKH: return "LEFT_YKH";
	case RIGHT_YKH: return "RIGHT_YKH";
	case LEFT_FKH: return "LEFT_FKH";
	case RIGHT_FKH: return "RIGHT_FKH";
	case LEFT_DKH: return "LEFT_DKH";
	case RIGHT_DKH: return "RIGHT_DKH";
	case COMMA: return "COMMA";
	case SEMOCOLOM: return "SEMOCOLOM";
	case COLON: return "COLON";
	case QUOTATION2: return "QUOTATION2";
	case QUOTATION1: return "QUOTATION1";
	case ZS: return "ZS";
	case ID: return "ID";
	case T_INT: return "T_INT";
	case T_DOUBLE: return "T_DOUBLE";
	case UNDEFINE: return "UNDEFINE";
	default: return "UNKNOWN";
	}
}
void print(TokenCode code, const string& stack) {
	const char* codeName = getTokenCodeName(code);
	cout << '(' << codeName << ',' << stack << ")" << endl;
}
void lexicalAnalysis(const string& filePath) {
	ifstream inFile(filePath);
	if (!inFile) {
		cerr << "Unable to open file: " << filePath << endl;
		return;
	}
	string currentToken;
	TokenCode currentTokenType;

	char currentChar;
	while (inFile.get(currentChar)) {
		if (isLetter(currentChar)) {//判断是否是ID类
			string currentToken;
			currentToken += currentChar;
			char nextChar;
			while (inFile.get(nextChar) && (isLetter(nextChar) || isDigit(nextChar))) {
				currentToken += nextChar;
			}
			inFile.putback(nextChar);
			int keywordIndex = Is_keyword(currentToken);
			if (keywordIndex != -1) {
				print(static_cast<TokenCode>(keywordIndex), currentToken);
			}
			else {
				print(ID, currentToken);
			}
		}
		else if (isDigit(currentChar)) {//判断是否是数字类
			string currentToken;
			currentToken += currentChar;
			char nextChar;
			bool isFloat = false; //浮点数标记
			while (inFile.get(nextChar) && (isDigit(nextChar) || (nextChar == '.'))) {
				if (nextChar == '.' && isFloat) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					cout << "Floating point type error:" << currentToken + nextChar << endl;
					return;
				}
				if (nextChar == '.') {
					isFloat = true;
					char n_char;
					inFile.get(n_char);
					if (!isDigit(n_char)) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						cout << "Floating point type error:" << currentToken + nextChar + n_char << endl;
						return;
					}
					inFile.putback(n_char);
				}
				currentToken += nextChar;




			}
			inFile.putback(nextChar);
			//判断是浮点数还是整数
			if (isFloat) {
				print(T_DOUBLE, currentToken);
			}
			else {
				print(T_INT, currentToken);
			}
		}
		else if (Is_delimiter(string(1, currentChar)) != -1 || Is_calculation(string(1, currentChar)) != -1) {//分隔符和操作符判断
			string currentToken;
			currentToken += currentChar;

			char nextChar;
			while (inFile.get(nextChar)) {
				string combinedToken = currentToken + nextChar;
				if (Is_delimiter(combinedToken) != -1 || Is_calculation(combinedToken) != -1) {
					currentToken = combinedToken;
				}
				else {
					inFile.putback(nextChar);
					break;
				}
			}
			int delimiterIndex = Is_delimiter(currentToken);
			int operatorIndex = Is_calculation(currentToken);
			if (delimiterIndex != -1) {
				print(static_cast<TokenCode>(numKey + numOpe + delimiterIndex), currentToken);
			}
			else if (operatorIndex != -1) {
				print(static_cast<TokenCode>(numKey + operatorIndex), currentToken);
			}

		}
		else if (currentChar == ' ' || currentChar == '\n')
		{
			continue;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "Unrecognizable symbols:" << currentChar << endl;
			return;
		}
	}
	inFile.close();
}

int main() {
	string filename;
	cout << "Please enter the file path name：";
	cin >> filename;
	lexicalAnalysis(filename);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	//字体恢复原来的颜色
	return 0;
}
