## Example:
```cpp
#include <fmt/core.h>
#include <string>
#include <stdint.h>

using namespace utils;

int main(int argc, char* argv[])
{
	const std::string path("example.json", std::ifstream::binary);

	QueryResult* result = new QueryResult(path);

	std::string name;
	result->read("name", name);

	fmt::print("name: {}\n", name);
	delete result;

	return EXIT_SUCCESS;
}
```
## Credit
[nlohmann-json](https://github.com/nlohmann/json.git)
