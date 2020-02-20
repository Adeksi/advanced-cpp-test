#include "row_writer.hpp"
#include <iostream>

void ConsoleWriter::write_row(const Row& row) {
    for (auto field : row) {
        std::cout << "(" << field.first << ")" <<field.second << " ";
    }
    std::cout << std::endl;
}
