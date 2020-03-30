#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <chrono>
void view_directory(const std::experimental::filesystem::path& path)
{
	if (std::experimental::filesystem::exists(path) && std::experimental::filesystem::is_directory(path))
	{
		for (const auto& entry : std::experimental::filesystem::directory_iterator(path))
		{
			auto file_name = entry.path().filename().string();
			std::cout << file_name << std::endl;
		}
	}
	auto ftime = std::experimental::filesystem::last_write_time(path); // не знаю откуда взять путь последнего измененного файла 
	auto file_name2 = path.filename().string();
	std::cout << file_name2 << std::endl;
	auto file_type = std::experimental::filesystem::file_type();// как файл тайп вызвать и как вывести 
	//std::cout << file_type << std::endl;
	std::time_t cftime = decltype (ftime) ::clock::to_time_t(ftime);
#pragma warning(suppress : 4996)
	std::cout << "Time of changes " << std::asctime(std::localtime(&cftime)) << ' \ n ';

}
int main(int argc, char** argv)
{

	view_directory(std::experimental::filesystem::current_path());

	system("pause");

	return EXIT_SUCCESS;
}