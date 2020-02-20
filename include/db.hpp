#ifndef DB_H
#define DB_H

#include "types.hpp"
#include <vector>

class DBGateway {
  public:
    virtual void add_field(RowNumber row_index, FieldIndex index, std::string value) = 0;
    virtual void delete_field(RowNumber row_index, FieldIndex index) = 0;
    virtual void edit_field(RowNumber row_index, FieldIndex field_index, std::string value) = 0;
    virtual const Row& get_row(RowNumber row_index) const = 0;
    virtual RowNumber add_row(const Row& row) = 0;
};

class MemoryDB : public DBGateway {
  public:
    void add_field(RowNumber row_index, FieldIndex index, std::string value);
    void delete_field(RowNumber row_index, FieldIndex index);
    void edit_field(RowNumber row_index, FieldIndex field_index, std::string value);
    const Row& get_row(RowNumber row_index) const;
    RowNumber add_row(const Row& row);

  private:
    std::vector<Row> db;
};

#endif