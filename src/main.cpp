#include "db.hpp"
#include "app.hpp"
#include "row_writer.hpp"
#include <iostream>


int main(void) {
    std:: cout << "Input fields splited with tabs. \nAvailable commands: \n /rm <field num> - remove field \n /add <row num> <field num> <value> - create field \n /edit <row num> <field num> <value> - edit field\n";
    MemoryDB db;
    ConsoleWriter writer;
    App app(&db, &writer);
    app.run(std::cin);
}
