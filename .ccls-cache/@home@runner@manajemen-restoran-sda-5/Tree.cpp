#include <iostream>
#include "../include/Tree.h"

using namespace std;

Tree::Tree() : root(nullptr) {}

void Tree::addMenuItem(const std::string &name) {
    addMenuItem(root, name);
}

void Tree::addMenuItem(MenuItem *&node, const std::string &name) {
    if (node == nullptr) {
        node = new MenuItem{name, nullptr, nullptr};
    } else if (name < node->name) {
        addMenuItem(node->left, name);
    } else {
        addMenuItem(node->right, name);
    }
}

void Tree::displayMenu() {
    displayMenu(root);
}

void Tree::displayMenu(MenuItem *node) {
    if (node != nullptr) {
        displayMenu(node->left);
        cout << node->name << endl;
        displayMenu(node->right);
    }
}

MenuItem* Tree::findMenuItem(const std::string &name) {
    return findMenuItem(root, name);
}

MenuItem* Tree::findMenuItem(MenuItem *node, const std::string &name) {
    if (node == nullptr || node->name == name) {
        return node;
    }
    if (name < node->name) {
        return findMenuItem(node->left, name);
    }
    return findMenuItem(node->right, name);
}
