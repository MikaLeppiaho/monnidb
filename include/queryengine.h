#ifndef QUERYENGINE_H
#define QUERYENGINE_H
#include "database.h"

class QueryEngine {
  public:
	explicit QueryEngine(Database &db);

	/**
	 * Execute databasequery
	 * @param query String query with .
	 * @return void
	 */
	void execute(const std::string &query);

  private:
	Database &database;

	/**
	 * Function to handle table creation.
	 * Example query:
	 * CREATE TABLE table_name (column_name1 TYPE, columne_name2 TYPE)
	 * @param query String query
	 * @return void
	 */
	void handle_create_table(const std::string &query);

	/**
	 * Function to handle the creation of a new row.
	 * Example query:
	 * INSERT INTO table_name (column1, column2) VALUES (value1, value2)
	 * @param query String
	 * @return void
	 */
	void handle_insert(const std::string &query);
	/**
	 * Function to handle fetching of rows
	 * Example query:
	 * SELECT * FROM table_name
	 * Prints the result to the user
	 * @param query String
	 * @return void
	 */
	void handle_select(const std::string &query);
};

#endif
