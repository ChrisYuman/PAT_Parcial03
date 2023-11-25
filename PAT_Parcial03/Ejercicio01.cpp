#include "Ejercicio01.h"
#include <queue>

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* listOfLists)
{
    auto compararnodos = [](const Node<int>* j, const Node<int>* c) {
        return j->value < c->value;
        };

    std::priority_queue<Node<int>*, std::vector<Node<int>*>, decltype(compararnodos)> minHeap(compararnodos);

    Node<Node<int>*>* currentList = listOfLists;
    while (currentList != nullptr) {
        if (currentList->value != nullptr) {
            minHeap.push(currentList->value);
        }
        currentList = currentList->next;
    }

    Node<int>* dummyNode = new Node<int>(0);
    Node<int>* currentNode = dummyNode;

    while (!minHeap.empty()) {
        Node<int>* node = minHeap.top();
        minHeap.pop();

        currentNode->next = new Node<int>(node->value);
        currentNode = currentNode->next;

        if (node->next) {
            minHeap.push(node->next);
        }
    }

    currentNode->next = nullptr;

    return dummyNode->next;
}
