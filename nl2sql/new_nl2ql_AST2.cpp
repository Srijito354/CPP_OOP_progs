#include <bits/stdc++.h>
using namespace std;

// AST Node structures.

struct Condition {
    string column;
    string op;
    string value;
};

struct SelectQuery {
    vector<string> columns;
    string table;
    vector<Condition> whereClauses;
};

// Functions to print AST.

void printAST(const SelectQuery &q) {
    cout << "AST: SELECT\n";
    cout << " Columns: ";
    if (q.columns.empty()) cout << "*";
    else {
        for (int i = 0; i< q.columns.size(); i++)
        {
            cout << q.columns[i];
            if (i<q.columns.size()-1) cout << ", ";
        }
    }
    cout << endl;
    cout << "Table: " << q.table << endl;
    if (!q.whereClauses.empty()) {
        cout << " WHERE:\n";
        for (auto &cond : q.whereClauses) {
            cout << " " << cond.column << " " << cond.op << " " << cond.value << endl;
        }
    }
}

SelectQuery parseNL(string input) {
    SelectQuery q;

    for (auto &c:input) c = tolower(c);
    if (input.find("customer") != string::npos) q.table = "customers";
    else if (input.find("order") != string::npos) q.table = "orders";
    else q.table = "unknown";

    if (input.find("name") != string::npos) q.columns.push_back("name");
    if (input.find("age") != string::npos) q.columns.push_back("age");
    if (input.find("email") != string::npos) q.columns.push_back("email");

    if (q.columns.empty()) q.columns.push_back("*");

    string num_str = "";
    for (char& ch : input)
    {
        if (isdigit(ch)) {
            num_str+=ch;
        }
    }

    if (input.find("age > "+num_str) != string::npos) {
        Condition cond;
        cond.column = "age";
        cond.op = ">";
        cond.value = num_str;
        q.whereClauses.push_back(cond);
    }
    else if (input.find("age is greater than "+num_str) != string::npos) {
        Condition cond;
        cond.column = "age";
        cond.op = ">";
        cond.value = num_str;
        q.whereClauses.push_back(cond);
    }

    return q;
}

int main() {
    string input;
    cout << "Enter NL query: ";
    getline(cin, input);

    SelectQuery q = parseNL(input);

    printAST(q);

    return 0;
}