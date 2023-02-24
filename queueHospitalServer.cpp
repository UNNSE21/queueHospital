// queueHospital.cpp: определяет точку входа для приложения.
//

#include "queueHospitalServer.h"

int main()
{
    p_libsys_init();
    // TODO: Your code here
    auto socket = p_socket_new(P_SOCKET_FAMILY_INET, P_SOCKET_TYPE_STREAM, P_SOCKET_PROTOCOL_TCP, nullptr);

    p_libsys_shutdown();
	return 0;
}
