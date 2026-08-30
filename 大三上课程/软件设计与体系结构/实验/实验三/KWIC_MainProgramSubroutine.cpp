#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>
#include <chrono> // 用于时间测量

// 函数声明
std::vector<std::string> readInput();
std::vector<std::string> generateShifts(const std::vector<std::string>& lines);
void alphabetize(std::vector<std::string>& shifts);
void writeOutput(const std::vector<std::string>& shifts);

// 忽略大小写的比较函数
bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
    std::string lowerA = a;
    std::string lowerB = b;
    std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
    std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
    return lowerA > lowerB;
}

// 新增过滤函数：保留以指定前缀开头的字符串
void filterByPrefix(std::vector<std::string>& shifts, char prefix) {
    shifts.erase(std::remove_if(shifts.begin(), shifts.end(),
        [prefix](const std::string& str) {
            return std::tolower(str[0]) != std::tolower(prefix);
        }),
        shifts.end());
}

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // 获取开始时间点

    std::vector<std::string> lines = readInput();
    std::vector<std::string> shifts = generateShifts(lines);
    alphabetize(shifts);
    writeOutput(shifts);

    auto end = std::chrono::high_resolution_clock::now(); // 获取结束时间点
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}

std::vector<std::string> readInput() {
    std::vector<std::string> lines;
    std::string line;
    // std::cout << "主程序子程序风格实现:" << std::endl;
    std::cout << "主程序子程序风格实现:" << std::endl;
    /*std::cout << "请输入行（输入 'END' 结束）：\n";
    while (std::getline(std::cin, line) && line != "END") {
        lines.push_back(line);
    }*/
    lines = {
        "hello world",
        "that is ok",
        "the only limit is doubts"
    };
    return lines;
}

std::vector<std::string> generateShifts(const std::vector<std::string>& lines) {
    std::vector<std::string> shifts;
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
            std::istream_iterator<std::string>());
        for (size_t i = 0; i < words.size(); ++i) {
            std::string shift;
            for (size_t j = 0; j < words.size(); ++j) {
                shift += words[(i + j) % words.size()] + " ";
            }
            shifts.push_back(shift.substr(0, shift.size() - 1)); // 去除末尾空格
        }
    }
    return shifts;
}

void alphabetize(std::vector<std::string>& shifts) {
    std::sort(shifts.begin(), shifts.end(), caseInsensitiveCompare);
}

void writeOutput(const std::vector<std::string>& shifts) {
    std::cout << "\n排序后的循环移位结果：\n";
    for (const auto& shift : shifts) {
        std::cout << shift << std::endl;
    }
}
