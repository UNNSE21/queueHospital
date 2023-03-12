#include "queueHospitalClient.h"
#include "ClientConnectionHandler.h"

pchar buffer[MESSAGE_MAX_SIZE];
int main()
{
    // При любом выводе в поток делать на конце std::endl. Либо использовать std::cout.flush() чтобы обновить консоль.
    // Иначе она может фризить и по факту выведенное сообщение не появится на экране. Видимо побочный эффект работы
    // с сокетами

    PSocketAddress *addr;
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

    // Trying to connect until succeed
    while(std::this_thread::sleep_for(500ms),p_socket_connect(sock, addr, nullptr) == FALSE);
    std::cout << "connected" << std::endl;
    ClientConnectionHandler handler(sock);
    handler.handleConnection();
    // Free all resources
    p_socket_free(sock);
    p_socket_address_free(addr); // socket is closed automatically
    p_libsys_shutdown();
	return 0;
}