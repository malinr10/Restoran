#ifndef TREE_H
#define TREE_H

#include <string>

struct MenuItem {
  std::string name;
  MenuItem *left;
  MenuItem *right;
};

class Tree {
public:
  Tree();
  void addMenuItem(const std::string &name);
  void displayMenu();
  MenuItem *findMenuItem(const std::string &name);

private:
  MenuItem *root;
  void addMenuItem(MenuItem *&node, const std::string &name);
  void displayMenu(MenuItem *node);
  MenuItem *findMenuItem(MenuItem *node, const std::string &name);
};

#endif
