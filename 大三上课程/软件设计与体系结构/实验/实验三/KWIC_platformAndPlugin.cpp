#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <chrono> // 用于时间测量

// 插件接口定义
class IKWICPlugin {
public:
    virtual ~IKWICPlugin() = default;
    virtual void process(std::vector<std::string>& lines) = 0;
};

// 插件管理器定义
class PluginManager {
public:
    void addPlugin(std::shared_ptr<IKWICPlugin> plugin) {
        plugins_.push_back(plugin);
    }

    void executePlugins(std::vector<std::string>& lines) {
        for (const auto& plugin : plugins_) {
            plugin->process(lines);
        }
    }

private:
    std::vector<std::shared_ptr<IKWICPlugin>> plugins_;
};

// 输入插件实现
class InputPlugin : public IKWICPlugin {
public:
    void process(std::vector<std::string>& lines) override {
        std::string line;
        std::cout << "平台/插件风格实现:" << std::endl;
        /*std::cout << "请输入多行文本（输入END结束）：" << std::endl;
        while (std::getline(std::cin, line) && line != "END") {
            lines.push_back(line);
        }*/
        lines = {
        "hello world",
        "that is ok",
        "the only limit is doubts"
        };
    }
};

// 循环移位插件实现
class CircularShiftPlugin : public IKWICPlugin {
public:
    void process(std::vector<std::string>& lines) override {
        std::vector<std::string> shifted_lines;
        for (const auto& line : lines) {
            std::vector<std::string> words = split(line);
            for (size_t i = 0; i < words.size(); ++i) {
                std::rotate(words.begin(), words.begin() + 1, words.end());
                shifted_lines.push_back(join(words));
            }
        }
        lines = shifted_lines;
    }

private:
    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> words;
        std::string word;
        for (char ch : str) {
            if (std::isspace(ch)) {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
            else {
                word += ch;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }

    std::string join(const std::vector<std::string>& words) {
        std::string result;
        for (const auto& word : words) {
            if (!result.empty()) {
                result += ' ';
            }
            result += word;
        }
        return result;
    }
};

// 排序插件实现
class AlphabetizerPlugin : public IKWICPlugin {
public:
    void process(std::vector<std::string>& lines) override {
        std::sort(lines.begin(), lines.end());
    }
};

// 输出插件实现
class OutputPlugin : public IKWICPlugin {
public:
    void process(std::vector<std::string>& lines) override {
        std::cout << "排序后的循环移位结果：" << std::endl;
        for (const auto& line : lines) {
            std::cout << line << std::endl;
        }
    }
};

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // 获取开始时间点

    PluginManager manager;

    // 创建插件实例
    auto inputPlugin = std::make_shared<InputPlugin>();
    auto circularShiftPlugin = std::make_shared<CircularShiftPlugin>();
    auto alphabetizerPlugin = std::make_shared<AlphabetizerPlugin>();
    auto outputPlugin = std::make_shared<OutputPlugin>();

    // 添加插件到管理器
    manager.addPlugin(inputPlugin);
    manager.addPlugin(circularShiftPlugin);
    manager.addPlugin(alphabetizerPlugin);
    manager.addPlugin(outputPlugin);

    // 执行插件链
    std::vector<std::string> lines;
    manager.executePlugins(lines);


    auto end = std::chrono::high_resolution_clock::now(); // 获取结束时间点
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
