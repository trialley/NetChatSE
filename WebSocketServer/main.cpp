#include <iostream>
#include<string>
#include <memory>
#include <WebSocketServer.h>
#include<CJsonObject/CJsonObject.hpp>
// 初始化HttpServer静态类成员
mg_serve_http_opts WebSocketServer::s_server_option;
std::string WebSocketServer::s_web_dir = "./web";
std::unordered_map<std::string, ReqHandler> WebSocketServer::s_handler_map;
std::unordered_set<mg_connection*> WebSocketServer::s_websocket_session_set;
std::unordered_map<std::string, mg_connection*> WebSocketServer::_id_to_connettion;

int main (int argc, char* argv[]) {
	auto server = std::shared_ptr<WebSocketServer> (new WebSocketServer);
	server->Init ("7999");
	server->Start ();
	return 0;
}
