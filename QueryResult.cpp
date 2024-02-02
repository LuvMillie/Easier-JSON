#include <database/QueryResult.h>
namespace KHPS
{
	MyQuery QueryResult::get_query()
	{
		return m_query;
	}
	QueryResult::QueryResult(MyQuery& query)
	{
		m_query = query;
	}
	QueryResult::QueryResult(const std::string& name)
	{
		if (std::filesystem::exists(name)) {
			std::ifstream file(name, std::ifstream::binary);
			MyQuery buffer;
			file >> m_query;
			file.close();
		}
	}
	void QueryResult::write(const std::string& name, const std::string& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const std::string_view& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const std::u8string& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const uint8_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const uint16_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const uint32_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const uint64_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const int8_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const int16_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const int32_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const int64_t& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const std::boolean& val)
	{
		m_query[name] = val;
	}
	void QueryResult::write(const std::string& name, const std::atomic_bool& val)
	{
		bool value = (val.load() ? true : false);
		m_query[name] = value;
	}
	void QueryResult::read(const std::string& name, std::atomic_bool& val)
	{
		std::boolean value = false;
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::boolean>();
		val.store(value);
	}
	void QueryResult::read(const std::string& name, std::boolean& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::boolean>();
	}
	void QueryResult::read(const std::string& name, std::string& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::string>();
	}
	void QueryResult::read(const std::string& name, std::string_view& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::string_view>();
	}
	void QueryResult::read(const std::string& name, std::u8string& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::u8string>();
	}
	void QueryResult::read(const std::string& name, uint8_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::uint8_t>();
	}
	void QueryResult::read(const std::string& name, uint16_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::uint16_t>();
	}
	void QueryResult::read(const std::string& name, uint32_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::uint32_t>();
	}
	void QueryResult::read(const std::string& name, uint64_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::uint64_t>();
	}
	void QueryResult::read(const std::string& name, int8_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::int8_t>();
	}
	void QueryResult::read(const std::string& name, int16_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::int16_t>();
	}
	void QueryResult::read(const std::string& name, int32_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::int32_t>();
	}
	void QueryResult::read(const std::string& name, int64_t& value)
	{
		if (m_query.find(name) != m_query.end())
			value = m_query[name].get<std::int64_t>();
	}
}