#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>
#include <chrono> // 用于时间测量

class Input {
public:
    void readLines() {
        std::string line;
        std::cout << "面向对象风格实现:" << std::endl;
        /*std::cout << "请输入行（输入 'END' 结束）：\n";
        while (std::getline(std::cin, line) && line != "END") {
            lines.push_back(line);
        }*/
        lines = {
        "hello world",
        "that is ok",
        "the only limit is doubts"
        };
    }
    const std::vector<std::string>& getLines() const {
        return lines;
    }
private:
    std::vector<std::string> lines;
};

class CircularShift {
public:
    void generateShifts(const std::vector<std::string>& lines) {
        for (const auto& line : lines) {
            std::istringstream iss(line);
            std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                std::istream_iterator<std::string>());
            for (size_t i = 0; i < words.size(); ++i) {
                std::ostringstream oss;
                for (size_t j = 0; j < words.size(); ++j) {
                    oss << words[(i + j) % words.size()] << " ";
                }
                std::string shift = oss.str();
                shifts.push_back(shift.substr(0, shift.size() - 1)); // 去除末尾空格
            }
        }
    }
    void generateShifts(const std::vector<std::string>& lines, size_t step) {
        for (const auto& line : lines) {
            std::istringstream iss(line);
            std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                std::istream_iterator<std::string>());
            for (size_t i = 0; i < words.size(); i += step) { // 控制移位步长
                std::ostringstream oss;
                for (size_t j = 0; j < words.size(); ++j) {
                    oss << words[(i + j) % words.size()] << " ";
                }
                std::string shift = oss.str();
                shifts.push_back(shift.substr(0, shift.size() - 1)); // 去除末尾空格
            }
        }
    }

    const std::vector<std::string>& getShifts() const {
        return shifts;
    }
private:
    std::vector<std::string> shifts;
};

class Alphabetizer {
public:
    void sortShifts(const std::vector<std::string>& shifts) {
        sortedShifts = shifts;
        std::sort(sortedShifts.begin(), sortedShifts.end(), caseInsensitiveCompare);
    }
    const std::vector<std::string>& getSortedShifts() const {
        return sortedShifts;
    }
private:
    std::vector<std::string> sortedShifts;
    // 忽略大小写的比较函数
    static bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
        std::string lowerA = a;
        std::string lowerB = b;
        std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA > lowerB;
    }
};

class Output {
public:
    void printShifts(const std::vector<std::string>& shifts) {
        std::cout << "\n排序后的循环移位结果：\n";
        for (const auto& shift : shifts) {
            std::cout << shift << std::endl;
        }
    }
};

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // 获取开始时间点

    Input input;
    input.readLines();

    CircularShift shifter;
    shifter.generateShifts(input.getLines());

    Alphabetizer alphabetizer;
    alphabetizer.sortShifts(shifter.getShifts());

    Output output;
    output.printShifts(alphabetizer.getSortedShifts());

    auto end = std::chrono::high_resolution_clock::now(); // 获取结束时间点
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
