#pragma once
#include <string>
#include <iostream>
#include <vector>

class Client {
	public:
		Client(std::string id_client, std::string nom, std::string prenom);
		std::string id_client();
		std::string nom();
		std::string prenom();
		friend std::ostream& operator<<(std::ostream& os, Client c);
		
	private:
		std::string _id_client;
		std::string _nom;
		std::string _prenom;
};