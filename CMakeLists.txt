# CMakeList.txt: проект CMake для queueHospital; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project ("queueHospital")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queueHospitalServer "queueHospitalServer.cpp" "queueHospitalServer.h")
add_executable (queueHospitalClient "queueHospitalClient.cpp" "queueHospitalClient.h")


# TODO: Добавьте тесты и целевые объекты, если это необходимо.
