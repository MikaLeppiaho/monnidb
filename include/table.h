#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

class Table {
  public:
	using Value = std::variant<int, std::string>;
	using Row = std::unordered_map<std::string, Value>;
	Table(const std::vector<std::pair<std::string, std::string>> &columns);

	void insert(const Row &row);
	const std::vector<Row> &query_all() const;

	void print_rows() const;

  private:
	std::vector<std::string> column_names;
	std::unordered_map<std::string, std::string> column_types;
	std::vector<Row> rows;
};
#endif // !TABLE_H
