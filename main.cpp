#include "database.h"
#include "table.h"

int main() {
	Database db;
	// create a table with columns
	db.create_table("users", {{"id", "int"}, {"name", "string"}});

	// Insert rows
	Table *users_table = db.get_table("users");
	users_table->insert({{"id", 1}, {"name", "Alice"}});
	users_table->print_rows();
}
