#include "db.hpp"


void MemoryDB::delete_field(RowNumber row_index, FieldIndex field_index) {
    db[row_index].erase(field_index);
}

void MemoryDB::add_field(RowNumber row_index, FieldIndex field_index, std::string value) {
    db[row_index][field_index] = value;
}

RowNumber MemoryDB::add_row(const Row& row) {
    db.push_back(row);
    return db.size() - 1;
}

void MemoryDB::edit_field(RowNumber row_index, FieldIndex field_index, std::string value) {
    db[row_index][field_index] = value;
}

const Row& MemoryDB::get_row(RowNumber row_index) const {
    return db[row_index];
}
