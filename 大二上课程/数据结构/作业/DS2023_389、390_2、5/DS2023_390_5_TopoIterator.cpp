#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

class TopoIterator {
public:
    TopoIterator(const std::unordered_map<char, std::vector<char>>& graph)
        : graph_(graph) {
        topologicalSort();
    }

    bool hasNext() const {
        return !topoOrder_.empty();
    }

    char next() {
        if (!hasNext()) {
            throw std::out_of_range("No more elements in topological order.");
        }

        char vertex = topoOrder_.top();
        topoOrder_.pop();
        return vertex;
    }

private:
    std::unordered_map<char, std::vector<char>> graph_;
    std::unordered_set<char> visited_;
    std::stack<char> topoOrder_;

    void topologicalSortUtil(char vertex) {
        visited_.insert(vertex);

        for (const char& neighbor : graph_[vertex]) {
            if (visited_.find(neighbor) == visited_.end()) {
                topologicalSortUtil(neighbor);
            }
        }

        topoOrder_.push(vertex);
    }

    void topologicalSort() {
        for (const auto& entry : graph_) {
            char vertex = entry.first;
            if (visited_.find(vertex) == visited_.end()) {
                topologicalSortUtil(vertex);
            }
        }
    }
};

int main() {
    std::unordered_map<char, std::vector<char>> exampleGraph = {
        {'A', {'B', 'C'}},
        {'B', {'D'}},
        {'C', {'D'}},
        {'D', {'E'}},
        {'E', {}}
    };

    TopoIterator topoIterator(exampleGraph);

    std::cout << "Topological Order:" << std::endl;
    while (topoIterator.hasNext()) {
        std::cout << topoIterator.next() << " ";
    }

    return 0;
}
