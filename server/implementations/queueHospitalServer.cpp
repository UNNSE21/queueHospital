// queueHospital.cpp: определяет точку входа для приложения.
//

#include "../queueHospitalServer.h"
#include "../ServerConnectionManager.h"

pchar buffer[MESSAGE_MAX_SIZE];

int main()
{
    p_libsys_init();
    // При любом выводе в поток делать на конце std::endl. Либо использовать std::cout.flush() чтобы обновить консоль.
    // Иначе она может фризить и по факту выведенное сообщение не появится на экране. Видимо побочный эффект работы
    // с сокетами
    /*PSocketAddress *addr;
    PSocket   *sock;
    p_libsys_init();

    if((addr = p_socket_address_new("127.0.0.1", 5552)) == nullptr)
    {
        std::cerr << "Could not take the local IP address...\n";
        p_libsys_shutdown();
        return 1;
    }
    if((sock = p_socket_new(P_SOCKET_FAMILY_INET, P_SOCKET_TYPE_STREAM, P_SOCKET_PROTOCOL_TCP, nullptr)) == nullptr)
    {
        std::cerr << "Could not create socket...\n";
        p_socket_address_free(addr);
        p_libsys_shutdown();
        return 2;
    }
    if (p_socket_bind (sock, addr, FALSE, nullptr) == FALSE) {
        std::cerr << "Could not bind address to socket...\n";
        p_socket_address_free(addr);
        p_socket_free(sock);
        p_libsys_shutdown();
        return 3;
    }*/
    //std::cout << "bound address\n";
    /*if(p_socket_listen(sock, nullptr) == FALSE)
    {
        std::cerr << "Could not start listening on socket...\n";
        p_socket_address_free(addr);
        p_socket_free(sock);
        p_libsys_shutdown();
        return 4;
    }
    std::cout << "started listening on socket" << std::endl;
    auto nSock = p_socket_accept(sock, nullptr);
    std::cout << "accepted connection" << std::endl;

*/
    auto server = new ServerConnectionManager();
    server->Listen();
    delete server;
    p_libsys_shutdown();
	return 0;
}
