#ifndef INVENTORY_H
#define INVENTORY_H

#include <list>
#include <string>

struct Item {
  std::string name;
  std::string type;
  int quantity;
};

class Inventory {
public:
  Inventory();
  void loadInventory();
  void displayInventory();
  void editItemQuantity(const std::string &name, int quantity);
  bool itemExists(const std::string &name) const;  
  int getItemQuantity(const std::string &name) const; 

private:
  std::list<Item> items;
  void saveInventory();
};

#endif
