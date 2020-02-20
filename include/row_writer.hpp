#ifndef ROW_WRITER_H
#define ROW_WRITER_H

#include "types.hpp"

class RowWriter {
  public:
    virtual void write_row(const Row& row) = 0;
};

class ConsoleWriter: public RowWriter {
    public:
      void write_row(const Row& row); 
};

#endif
