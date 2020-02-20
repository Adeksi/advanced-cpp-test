#include "app.hpp"


void App::run(std::istream& input) {
    std::string command_name;
    
    while (true) {
        input >> command_name;
        if (command_name == "/rm") {
            RowNumber row_index;
            FieldIndex field_index;
            input >> row_index >> field_index;
            m_db->delete_field(row_index, field_index);
            m_writer->write_row(m_db->get_row(row_index));
            continue;
        }

        if (command_name == "/add") {
            RowNumber row_index;
            FieldIndex field_index;
            std::string value;
            input >> row_index >> field_index >> value;
            m_db->add_field(row_index, field_index, value);
            m_writer->write_row(m_db->get_row(row_index));
            continue;
        }

        if (command_name == "/edit") {
            RowNumber row_index;
            FieldIndex field_index;
            std::string value;
            input >> row_index >> field_index >> value;
            m_db->edit_field(row_index, field_index, value);
            m_writer->write_row(m_db->get_row(row_index));
            continue;
        }

        if (command_name[0] != '/') {
            Row row;
            row[0] = command_name;

            FieldIndex index = 0;

            std::string line;
            std::getline(input, line);

            std::istringstream iss(line);
            std::string token;

            while(std::getline(iss, token, '\t')) {
                if (token == "") {
                    continue;
                }
                index++;
                row[index] = token;
            }

            m_db->add_row(row);
            m_writer->write_row(row);
        }
    }
}
