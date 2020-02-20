#ifndef APP_H
#define APP_H

#include "db.hpp"
#include "app.hpp"
#include "row_writer.hpp"

#include <sstream>

class App {
  public:
    App(DBGateway* db, RowWriter* writer): m_db(db), m_writer(writer) {}
    void run(std::istream& input);

  private:
    DBGateway* m_db;
    RowWriter* m_writer;
};

#endif