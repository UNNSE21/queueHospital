//
// Created by k17 on 25.02.2023.
//

#include "../../include/server/ServerConnectionManager.h"
#include "../../include/server/ServerConnectionHandler.h"
std::atomic<bool> ServerConnectionManager::serverStop = false;


ServerConnectionManager::ServerConnectionManager() {
    if((address = p_socket_address_new("0.0.0.0", 5552)) == nullptr)
    {
        std::cerr << "Could not take the local IP address...\n";
        throw std::runtime_error("Could not take the local IP address...\n");
    }
    if((_socket = p_socket_new(P_SOCKET_FAMILY_INET, P_SOCKET_TYPE_STREAM, P_SOCKET_PROTOCOL_TCP, nullptr)) == nullptr)
    {
        std::cerr << "Could not create socket...\n";
        p_socket_address_free(address);
        throw std::runtime_error("Could not create socket...\n");
    }
    p_socket_set_blocking(_socket, FALSE);
    if (p_socket_bind (_socket, address, FALSE, nullptr) == FALSE) {
        std::cerr << "Could not bind address to socket...\n";
        p_socket_address_free(address);
        p_socket_free(_socket);
        throw std::runtime_error("Could not bind address to socket...\n");
    }
}

ServerConnectionManager::~ServerConnectionManager() {
    p_socket_address_free(address);
    p_socket_close(_socket, nullptr);
    p_socket_free(_socket);
}

void ServerConnectionManager::Listen() {
    p_socket_listen(_socket, nullptr);
    serverStop = false;
    p_uthread_create(&ServerConnectionManager::ListenThread, _socket, false, nullptr);
    char c;
    std::cin >> c;
    serverStop = true;
    std::cout << "Shutting down" << std::endl;
    p_uthread_sleep(10000);
}
ppointer ServerConnectionManager::ListenThread(ppointer arg) {
    PUThread *threads[MAX_SERVER_THREAD_COUNT];
    size_t workingThreads = 0;
    auto ssocket = static_cast<PSocket *> (arg);
    while (!serverStop)
    {
        auto conSocket = p_socket_accept(ssocket, nullptr);
        if(conSocket != nullptr) {
            if (workingThreads < MAX_SERVER_THREAD_COUNT)
            {
                threads[workingThreads++] = p_uthread_create(ServerConnectionManager::ConnectionThread, conSocket, FALSE,
                                                             nullptr);
            }
        }
    }
    std::cout << "Listener shut down" << std::endl;
    return nullptr;
}
ppointer ServerConnectionManager::ConnectionThread(ppointer arg) {
    auto handler = ServerConnectionHandler(static_cast<PSocket *> (arg));
    handler.handleConnection();
    return nullptr;
}
