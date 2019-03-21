///*
// * https_server.cpp
// *
// *  Created on: 12.03.2019
// *      Author: labor
// */
//
//#include "https_server.h"
//// Includes for the server
//#include "../libraries/esp32_https_server/HTTPRequest.hpp"
//#include "../libraries/esp32_https_server/HTTPResponse.hpp"
//#include "../libraries/esp32_https_server/HTTPServer.hpp"
//
//#undef send
//
//// The HTTPS Server comes in a separate namespace. For easier use, include it here.
//using namespace httpsserver;
//
//// Additionally, we create an HTTPServer for unencrypted traffic
//HTTPServer insecureServer = HTTPServer();
//
//// Declare some handler functions for the various URLs on the server
//void handleRoot(HTTPRequest * req, HTTPResponse * res);
//void handle404(HTTPRequest * req, HTTPResponse * res);
//
//
//// The hanlder functions are the same as in the Static-Page example.
//// The only difference is the check for isSecure in the root handler
//
//void handleRoot(HTTPRequest * req, HTTPResponse * res)
//{
//    res->setHeader("Content-Type", "text/html");
//
//    res->println("<!DOCTYPE html>");
//    res->println("<html>");
//    res->println("<head><title>Hello World!</title></head>");
//    res->println("<body>");
//    res->println("<h1>Hello World!</h1>");
//
//    res->print("<p>Your server is running for ");
//    res->print((int) (millis() / 1000), DEC);
//    res->println(" seconds.</p>");
//
//    // You can check if you are connected over a secure connection, eg. if you
//    // want to use authentication and redirect the user to a secure connection
//    // for that
//    if (req->isSecure())
//    {
//        res->println("<p>You are connected via <strong>HTTPS</strong>.</p>");
//    }
//    else
//    {
//        res->println("<p>You are connected via <strong>HTTP</strong>.</p>");
//    }
//
//    res->println("</body>");
//    res->println("</html>");
//}
//
//void handle404(HTTPRequest * req, HTTPResponse * res)
//{
//    req->discardRequestBody();
//    res->setStatusCode(404);
//    res->setStatusText("Not Found");
//    res->setHeader("Content-Type", "text/html");
//    res->println("<!DOCTYPE html>");
//    res->println("<html>");
//    res->println("<head><title>Not Found</title></head>");
//    res->println(
//            "<body><h1>404 Not Found</h1><p>The requested resource was not found on this server.</p></body>");
//    res->println("</html>");
//}
//
//void serverTask(void *params)
//{
//    // For every resource available on the server, we need to create a ResourceNode
//    // The ResourceNode links URL and HTTP method to a handler function
//    ResourceNode * nodeRoot = new ResourceNode("/", "GET", &handleRoot);
//    ResourceNode * node404 = new ResourceNode("", "GET", &handle404);
//
//    // We do the same for the default Node
//    insecureServer.setDefaultNode(node404);
//
//    Serial.println("Starting HTTP server...");
//    insecureServer.start();
//    if (insecureServer.isRunning())
//    {
//        Serial.println("Servers ready.");
//    }
//    while (1)
//    {
//        insecureServer.loop();
//        delay(1);
//    }
//
//}
