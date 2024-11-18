#include "table.h"

int main() {
	Table users({{"id", "INT"}, {"name", "STRING"}});
	users.insert({{"id", 1}, {"name", "Alice"}});
	users.insert({{"id", 2}, {"name", "Mark"}});
	users.print_rows();
}
