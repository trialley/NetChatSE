#pragma warning(disable:4996);
//#pragma comment ( lib,"sqlite3.lib" )
//#pragma comment ( lib,"SQLiteCpp.lib" )

#include <iostream>
#include <memory>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <APIServer.h>

// 初始化APIServer静态类成员
mg_serve_http_opts APIServer::s_server_option;
std::string APIServer::s_web_dir = "./web";
std::unordered_map<std::string, ReqHandler> APIServer::s_handler_map;
std::unordered_set<mg_connection*> APIServer::s_websocket_session_set;

int main (int argc, char* argv[]) {
	try {
		SQLite::Database    db ("../www/link.sqlite3");
		SQLite::Statement   query (db, "SELECT * FROM users");
		while (query.executeStep ()) {
			for (int i = 0; i < query.getColumnCount (); i++) {
				auto data = query.getColumn (i);
				std::cout << data << " ";
			}
			std::cout << std::endl;
		}

	} catch (std::exception & e) {
		std::cout << "exception: " << e.what () << std::endl;
	}


	std::string port = "7998";
	auto server = std::shared_ptr<APIServer> (new APIServer);
	server->Init (port);
	server->Start ();

	return 0;
}
