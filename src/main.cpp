#include "queryengine.h"

int main() {
	Database db;
	QueryEngine engine(db);

	// Example queries
	engine.execute("CREATE TABLE users (id INT, name STRING)");
	engine.execute("INSERT INTO users (id, name) VALUES (1, 'Alice')");
	engine.execute("INSERT INTO users (id, name) VALUES (2, 'Bob')");
	engine.execute("SELECT * FROM users");

	return 0;
}
