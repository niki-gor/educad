#include <typeindex>
#include <typeinfo>
#include <memory>
#include <vector>



#define MAKEPTR std::make_shared

template<class T>
using PTR = std::shared_ptr<T>;

template<class T>
using algorithm = std::vector<std::pair<std::string, std::vector<PTR<T>>>>;