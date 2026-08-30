#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>
#include <chrono> // 用于时间测量

class Blackboard {
public:
    std::vector<std::string> lines;
    std::vector<std::string> shifts;
    std::vector<std::string> sortedShifts;
};

class Input {
public:
    void update(Blackboard& bb) {
        std::string line;
        std::cout << "黑板风格实现:" << std::endl;
        /*std::cout << "请输入行（输入 'END' 结束）：\n";
        while (std::getline(std::cin, line) && line != "END") {
            bb.lines.push_back(line);
        }*/
        bb.lines = {
        "hello world",
        "that is ok",
        "the only limit is doubts"
        };
    }
};

class CircularShift {
public:
    void update(Blackboard& bb) {
        for (const auto& line : bb.lines) {
            std::istringstream iss(line);
            std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                std::istream_iterator<std::string>());
            for (size_t i = 0; i < words.size(); ++i) {
                std::ostringstream oss;
                for (size_t j = 0; j < words.size(); ++j) {
                    oss << words[(i + j) % words.size()] << " ";
                }
                std::string shift = oss.str();
                bb.shifts.push_back(shift.substr(0, shift.size() - 1)); // 去除末尾空格
            }
        }
    }
};

class Alphabetizer {
public:
    void update(Blackboard& bb) {
        bb.sortedShifts = bb.shifts;
        std::sort(bb.sortedShifts.begin(), bb.sortedShifts.end(), caseInsensitiveCompare);
    }
private:
    // 忽略大小写的比较函数
    static bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
        std::string lowerA = a;
        std::string lowerB = b;
        std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    }
};

class Output {
public:
    void update(Blackboard& bb) {
        std::cout << "\n排序后的循环移位结果：\n";
        for (const auto& shift : bb.sortedShifts) {
            std::cout << shift << std::endl;
        }
    }
};

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // 获取开始时间点

    Blackboard bb;
    Input input;
    CircularShift shifter;
    Alphabetizer alphabetizer;
    Output output;

    input.update(bb);
    shifter.update(bb);
    alphabetizer.update(bb);
    output.update(bb);

    auto end = std::chrono::high_resolution_clock::now(); // 获取结束时间点
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
