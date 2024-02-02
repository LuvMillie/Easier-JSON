#ifndef QUERY_WRITER_H
#define QUERY_WRITER_H
#include <string>
#include <vector>
#include <atomic>
#include <fstream>
#include <stdlib.h>
#include <stdint.h>
#include <cstdbool>
#include <typedef.h>
#include <fmt/core.h>
#include <MyQuery.h>
namespace utils
{
	class QueryResult {
	private:
		MyQuery m_query;
	public:
		MyQuery get_query();
	public:
		QueryResult(MyQuery&);
		QueryResult(const std::string&);
		QueryResult() = default;
		~QueryResult() { m_query.clear(); }
	public:
		void write(const std::string&, const std::atomic_bool&);
		void write(const std::string&, const std::boolean&);
		void write(const std::string&, const std::string&);
		void write(const std::string&, const std::string_view&);
		void write(const std::string&, const std::u8string&);

		void write(const std::string&, const uint8_t&);
		void write(const std::string&, const uint16_t&);
		void write(const std::string&, const uint32_t&);
		void write(const std::string&, const uint64_t&);

		void write(const std::string&, const int8_t&);
		void write(const std::string&, const int16_t&);
		void write(const std::string&, const int32_t&);
		void write(const std::string&, const int64_t&);

		void read(const std::string&, std::atomic_bool&);
		void read(const std::string&, std::boolean&);
		void read(const std::string&, std::string&);
		void read(const std::string&, std::string_view&);
		void read(const std::string&, std::u8string&);

		void read(const std::string&, uint8_t&);
		void read(const std::string&, uint16_t&);
		void read(const std::string&, uint32_t&);
		void read(const std::string&, uint64_t&);

		void read(const std::string&, int8_t&);
		void read(const std::string&, int16_t&);
		void read(const std::string&, int32_t&);
		void read(const std::string&, int64_t&);
	public:
		template <typename Args>
		void write_array(const std::string& name, const Args& val) {
			m_query[name] = val;
		}
		template <typename Args>
		void read_array(const std::string& name, Args& val) {
			if (m_query.find(name) != m_query.end())
				val = m_query[name].get<Args>();
		}
		void dump(const std::string& name, const int& indent) {
			std::ofstream file(name);
			if (file.fail()) {
				fmt::print("Failed to dump {}.\n", name);
				return;
			} file << get_query().dump(indent) << std::endl;
			file.close();
		}
	};
}
#endif // !QUERY_WRITER_H
