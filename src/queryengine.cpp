#include "queryengine.h"
#include <iostream>

QueryEngine::QueryEngine(Database &db) : database(db) {}

void QueryEngine::execute(const std::string &query) {
	std::string query_start{query.substr(0, query.find(" "))};
	if (query_start == "CREATE") {
		handle_create_table(query);
		return;
	}
	if (query_start == "INSERT") {
		handle_insert(query);
		return;
	}

	if (query_start == "SELECT") {
		handle_select(query);
		return;
	}
	std::cout << "Invalid query!\n";
}

void QueryEngine::handle_create_table(const std::string &query) {
	std::string table_name{"users"};
	std::vector<std::pair<std::string, std::string>> columns = {{"id", "INT"},
	                                                            {"Name", "STRING"}};

	database.create_table(table_name, columns);
	std::cout << "Table " << table_name << " created.\n";
}
void QueryEngine::handle_insert(const std::string &query) {
	std::string table_name{"users"};
	Table *table{database.get_table(table_name)};

	Table::Row row = {{"id", 1}, {"name", "Alice"}};
	table->insert(row);
	std::cout << "Row inserted into " << table_name << ".\n";
}
void QueryEngine::handle_select(const std::string &query) {
	std::string table_name{"users"};
	Table *table{database.get_table(table_name)};

	for (const auto &row : table->query_all()) {
		for (const auto &[column, value] : row) {
			std::visit([](auto &&val) { std::cout << val << " "; }, value);
		}
		std::cout << "\n";
	}
}
