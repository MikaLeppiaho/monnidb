
#include "table.h"
#include <iostream>
#include <vector>

Table::Table(const std::vector<std::pair<std::string, std::string>> &columns) {
	for (const auto &[name, type] : columns) {
		column_names.push_back(name);
		column_types[name] = type;
	}
}

void Table::insert(const Row &row) {
	rows.push_back(row);
}

const std::vector<Table::Row> &Table::query_all() const {
	return rows;
}

void Table::print_rows() const {
	for (const auto &row : rows) {
		for (const auto &[column, value] : row) {
			std::visit([](auto &&val) { std::cout << val << " "; }, value);
		}
	}
}
