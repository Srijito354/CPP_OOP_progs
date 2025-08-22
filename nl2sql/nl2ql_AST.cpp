#include <iostream>  
#include <string>  
#include <vector>  
#include <memory>  
  
// Base class for all AST nodes  
class AstNode {  
public:  
    virtual ~AstNode() = default;  
    virtual void print() const = 0;  
};  
  
// SELECT statement node  
class SelectNode : public AstNode {  
public:  
    std::string select_list;  
    std::unique_ptr<FromNode> from;  
    std::unique_ptr<WhereNode> where;  
  
    SelectNode(const std::string& select,   
               std::unique_ptr<FromNode> from,  
               std::unique_ptr<WhereNode> where)  
        : select_list(select), from(std::move(from)), where(std::move(where)) {}  
  
    void print() const override {  
        std::cout << "SELECT " << select_list << "\n";  
        if (from) from->print();  
        if (where) where->print();  
    }  
};  
  
// FROM clause node  
class FromNode : public AstNode {  
public:  
    std::string table_name;  
  
    FromNode(const std::string& table) : table_name(table) {}  
  
    void print() const override {  
        std::cout << "FROM " << table_name << "\n";  
    }  
};  
  
// WHERE clause node  
class WhereNode : public AstNode {  
public:  
    std::string condition;  
  
    WhereNode(const std::string& cond) : condition(cond) {}  
  
    void print() const override {  
        std::cout << "WHERE " << condition << "\n";  
    }  
};

int main() {  
    // Create nodes  
    auto where = std::make_unique<WhereNode>("age > 30");  
    auto from = std::make_unique<FromNode>("users");  
    auto select = std::make_unique<SelectNode>("name", std::move(from), std::move(where));  
  
    // Print the AST  
    select->print();  
  
    return 0;  
}