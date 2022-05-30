#include <typeindex>
#include <typeinfo>
#include <memory>



#define MAKEPTR std::make_shared

template<class T>
using PTR = std::shared_ptr<T>;