#include <vector>
#include <queue>
#include <cstdint>
#include <string>
#include <map>

class HaffmanTree {
private:

    class Node {
    public:
        int byteValue;
        size_t priority;
        Node* left;
        Node* right;

        Node(
            int byteValue,
            size_t priority,
            Node* left,
            Node* right
        );

        Node(
            int byteValue,
            size_t priority
        );

    };

    /* nodes comparator for priority_queue */
    class NodesComparator {
    public:
        bool operator () (Node*& a, Node*& b) {
            return a->priority > b->priority;
        }
    };

public:

    /* constructor */
    HaffmanTree();

    /* Build Haffman tree */
    void buildTree(std::vector<size_t>& statistic);

    /* Build dictionary from tree */
    std::map<unsigned char, std::string> getDict();

private:

    /* Build dictionary from tree */
    void getDict(Node* now, std::string code, std::map<unsigned char, std::string>& dictionary);

    Node* root;
};
