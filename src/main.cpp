#include "main.h"
#include <iostream>
#include <conncpp.hpp>

int main() {
    std::cout << "Hellos" << std::endl;
    try {
      // Instantiate Driver
      sql::Driver* driver = sql::mariadb::get_driver_instance();
      
      // Configure Connection
      // The URL or TCP connection string format is
      // ``jdbc:mariadb://host:port/database``.
      //omen-home.iptime.org
      //203.251.63.137
      sql::SQLString url("tcp://203.251.63.137:8001");

      // Use a properties map for the user name and password
      sql::Properties properties({
            {"user", "guest"},
            {"password", "1234"}
         });

      // Establish Connection
      // Use a smart pointer for extra safety
      std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
/*
      // Created a PreparedStatement
      // Use a smart pointer for extra safety
      std::shared_ptr<sql::PreparedStatement> stmnt(
            conn->prepareStatement(
               "INSERT INTO test.contacts(first_name, last_name, email) VALUES (?, ?, ?)"
            )
         );
      // Close Connection
      */
     
      conn->close();
   }
   catch (sql::SQLException& e) {
      std::cerr << "Error Connecting to the database: " << e.what() << std::endl;
      return 1;
   }

    return 0;
}