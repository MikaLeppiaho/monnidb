
#include "table.h"
#include <memory>
#include <string>
#include <vector>

/**
 * @class Database
 * A container class to manage multiple tables, supporting creation and access.
 */
class Database {
  public:
	/**
	 * Creates a new table with the given name and column definitions.
	 * @param name Name of the table.
	 * @param columns Column definitions, where each column is a pair of name and type.
	 * @throws std::runtime_error if a table with the same name already exists.
	 */
	void create_table(
	    const std::string &name,
	    const std::vector<std::pair<std::string, std::string>> &columns);

	/**
	 * Retrieves a pointer to the table with the given name.
	 * @param name Name of the table.
	 * @return A raw pointer to the Table object.
	 * @throws std::runtime_error if no table with the given name exists.
	 */
	Table *get_table(const std::string &name) const;

  private:
	// Mapping of table name to Table object
	std::unordered_map<std::string, std::unique_ptr<Table>> tables;
};
