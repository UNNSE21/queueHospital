# CMakeList.txt: проект CMake для queueHospital; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project ("queueHospital")

add_subdirectory(modules/plibsys plibsys)

add_library(queueAppCommonLib common.h Patient.cpp Patient.h VipPatient.cpp VipPatient.h ConnectionHandler.h DataConverter.cpp DataConverter.h)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queueHospitalServer
        "common.h"
        "queueHospitalServer.cpp" "queueHospitalServer.h"
        "queue.h"
        ServerConnectionManager.cpp ServerConnectionManager.h
        PatientRepository.cpp PatientRepository.h
        )
add_executable (queueHospitalClient
        "common.h"
        "queueHospitalClient.cpp" "queueHospitalClient.h"
        )

target_link_libraries(queueHospitalServer plibsys)
target_link_libraries(queueHospitalServer queueAppCommonLib)
target_link_libraries(queueHospitalClient plibsys)
target_link_libraries(queueHospitalClient queueAppCommonLib)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
