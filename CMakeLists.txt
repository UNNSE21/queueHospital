# CMakeList.txt: проект CMake для queueHospital; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project ("queueHospital")

add_subdirectory(modules/plibsys plibsys)

add_library(queueAppCommonLib common/common.h common/implementations/Patient.cpp common/Patient.h common/implementations/VipPatient.cpp common/VipPatient.h common/ConnectionHandler.h common/implementations/DataConverter.cpp common/DataConverter.h common/implementations/PatientDataConverter.cpp common/PatientDataConverter.h)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queueHospitalServer
        "common/common.h"
        "server/implementations/queueHospitalServer.cpp" "server/queueHospitalServer.h"
        "server/queue.h"
        server/implementations/ServerConnectionManager.cpp server/ServerConnectionManager.h
        server/implementations/PatientRepository.cpp server/PatientRepository.h
        server/implementations/ServerConnectionHandler.cpp server/ServerConnectionHandler.h
        )
add_executable (queueHospitalClient
        "common/common.h"
        "client/implementations/queueHospitalClient.cpp" "client/queueHospitalClient.h"
        client/implementations/ClientConnectionHandler.cpp client/ClientConnectionHandler.h
        )

target_link_libraries(queueHospitalServer plibsys)
target_link_libraries(queueHospitalServer queueAppCommonLib)
target_link_libraries(queueHospitalClient plibsys)
target_link_libraries(queueHospitalClient queueAppCommonLib)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
