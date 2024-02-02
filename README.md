## Example:
-> inside ``example.json``
```cpp
{
	"name": "LuvMillie"
        "telephone": 09919
}
```
-> read objects inside ``example.json``
```cpp
#include <fmt/core.h>
#include <string>
#include <stdint.h>

using namespace utils;

int main(int argc, char* argv[])
{
	const std::string path("example.json", std::ifstream::binary);

	QueryResult result = QueryResult(path);

	std::string name;
        int32_t telephone;

        // reading objects
	result.read("name", name);
        result.read("telephone", telephone);

        // print result
	fmt::print("name: {}\n", name);
        fmt::print("telephone: {}\n", telephone);

	return EXIT_SUCCESS;
}
```
-> OUTPUT:
```cpp
name: LuvMillie
telephone: 09919
```
## Credit
[nlohmann-json](https://github.com/nlohmann/json.git)
