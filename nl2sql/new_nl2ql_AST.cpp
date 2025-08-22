#include <bits/stdc++.h> // includes all the header shit we gotta need.
using namespace std;

int main() {
    string input;
    cout << "Enter natural language query: ";
    getline(cin, input);

    // make lowercase
    for (auto &c : input) c = tolower(c);

    string sql = "SELECT * FROM ";

    // find table
    if (input.find("customer") != string::npos) {
        sql += "customers";
    } else if (input.find("order") != string::npos) {
        sql += "orders";
    } else if (input.find("product") != string::npos) {
        sql += "products";
    } else {
        sql += "unknown_table";
    }

    // select specific columns
    if (input.find("name") != string::npos) {
        sql = "SELECT name FROM " + sql.substr(14); // hacky
    }
    if (input.find("email") != string::npos) {
        sql = "SELECT name, email FROM " + sql.substr(14);
    }
    if (input.find("count") != string::npos) {
        sql = "SELECT COUNT(*) FROM " + sql.substr(14);
    }
    if (input.find("average") != string::npos || input.find("avg") != string::npos) {
        sql = "SELECT AVG(price) FROM " + sql.substr(14);
    }
    if (input.find("maximum") !=string::npos || input.find("max") != string::npos) {
        sql = "SELECT MAX(price) FROM" + sql.substr(14);
    }

    // where clause
    if (input.find("age") != string::npos) {
        size_t pos = input.find("age");
        string cond = input.substr(pos);
        if (cond.find("greater") != string::npos || cond.find(">") != string::npos) {
            sql += " WHERE age > 30"; // hardcoded
        } else if (cond.find("less") != string::npos || cond.find("<") != string::npos) {
            sql += " WHERE age < 30";
        } else if (cond.find("=") != string::npos || cond.find("equal") != string::npos) {
            sql += " WHERE age = 30";
        }
    }

    // order by
    if (input.find("order by") != string::npos || input.find("sort by") != string::npos) {
        if (input.find("age") != string::npos) {
            sql += " ORDER BY age";
            if (input.find("desc") != string::npos)
                sql += " DESC";
        }
    }

    // limit
    if (input.find("top 10") != string::npos || input.find("limit 10") != string::npos) {
        sql += " LIMIT 10";
    }

    cout << "Generated SQL:\n" << sql << endl;

    return 0;
}
