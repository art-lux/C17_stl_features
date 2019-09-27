#include <string>
#include <iostream>

/*
1.  Класс process_monitor должен содержать статический член 
	и быть доступным глобально сам по себе, 
	что приведет(при включении его в несколько единиц трансляции) к появлению символов,
	определенных дважды :
*/

// foo_lib.hpp
/*
class process_monitor {
public:
	static const std::string standard_string
	{ "some static globally available string" };
};
process_monitor global_process_monitor;
*/


/*
2.  Теперь при попытке включить данный код в несколько файлов 
	с расширением.cpp, а затем скомпилировать и связать их произойдет сбой 
	на этапе связывания.Чтобы это исправить, добавим ключевое слово inline:
*/
// foo_lib.hpp
class process_monitor {
public:
	static const inline std::string standard_string
	{ "some static globally available string" };
};
inline process_monitor global_process_monitor;

void header_libs_with_inline()
{
	std::cout << std::endl;
	std::cout << global_process_monitor.standard_string << std::endl << std::endl;
}