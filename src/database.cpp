#include "database.h"
#include <stdexcept>
#include <string>
#include <vector>

void Database::create_table(
    const std::string &name,
    const std::vector<std::pair<std::string, std::string>> &columns) {
	if (tables.find(name) != tables.end()) {
		throw std::runtime_error("Table already exists!");
	}
	tables[name] = std::make_unique<Table>(columns);
}

Table *Database::get_table(const std::string &name) const {
	// Check if table exists
	auto it = tables.find(name);
	if (it == tables.end()) {
		throw std::runtime_error("Table not found!");
	}
	return it->second.get();
}
