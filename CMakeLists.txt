# CMakeList.txt: проект CMake для queueHospital; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project ("queueHospital")

add_subdirectory(modules/plibsys plibsys)

add_library(queueAppCommonLib include/common/common.h source/common/Patient.cpp include/common/Patient.h source/common/VipPatient.cpp include/common/VipPatient.h include/common/ConnectionHandler.h source/common/DataConverter.cpp include/common/DataConverter.h source/common/PatientDataConverter.cpp include/common/PatientDataConverter.h)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queueHospitalServer
        "include/common/common.h"
        "source/server/queueHospitalServer.cpp" "include/server/queueHospitalServer.h"
        "include/server/queue.h"
        source/server/ServerConnectionManager.cpp include/server/ServerConnectionManager.h
        source/server/PatientRepository.cpp include/server/PatientRepository.h
        source/server/ServerConnectionHandler.cpp include/server/ServerConnectionHandler.h
        source/server/PatientAuthorization.cpp include/server/PatientAuthorization.h source/server/DoctorAuthorization.cpp include/server/DoctorAuthorization.h source/server/Authorization.cpp include/server/Authorization.h)
add_executable (queueHospitalClient
        "include/common/common.h"
        "source/client/queueHospitalClient.cpp" "include/client/queueHospitalClient.h"
        source/client/ClientConnectionHandler.cpp include/client/ClientConnectionHandler.h
        source/client/commands/doctor/ReceivingPatient.cpp include/client/commands/doctor/ReceivingPatient.h source/client/commands/common/Authorization.cpp include/client/commands/common/Authorization.h source/client/commands/doctor/DoctorCommandHandler.cpp include/client/commands/doctor/DoctorCommandHandler.h include/client/commands/common/CommandHandler.h source/client/commands/patient/PatientCommandHandler.cpp include/client/commands/patient/PatientCommandHandler.h)

target_link_libraries(queueHospitalServer plibsys)
target_link_libraries(queueHospitalServer queueAppCommonLib)
target_link_libraries(queueHospitalClient plibsys)
target_link_libraries(queueHospitalClient queueAppCommonLib)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
