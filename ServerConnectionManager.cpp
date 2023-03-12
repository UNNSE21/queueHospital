//
// Created by k17 on 25.02.2023.
//

#include "ServerConnectionManager.h"
#include "ServerConnectionHandler.h"

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
    //p_socket_set_blocking(socket, FALSE);
    if (p_socket_bind (_socket, address, FALSE, nullptr) == FALSE) {
        std::cerr << "Could not bind address to socket...\n";
        p_socket_address_free(address);
        p_socket_free(_socket);
        throw std::runtime_error("Could not bind address to socket...\n");
    }
}

ServerConnectionManager::~ServerConnectionManager() {
    p_socket_address_free(address);
    p_socket_free(_socket);
}

void ServerConnectionManager::Listen() {
    p_socket_listen(_socket, nullptr);
    while (_socket != nullptr)
    {
        auto conSocket = p_socket_accept(_socket, nullptr);
        p_uthread_create(&ServerConnectionManager::ConnectionThread, conSocket, FALSE, "serverThread");
    }
}

ppointer ServerConnectionManager::ConnectionThread(ppointer arg) {
    auto handler = ServerConnectionHandler(static_cast<PSocket *> (arg));
    handler.handleConnection();
}
