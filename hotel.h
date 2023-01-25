#pragma once
#include <string>
#include <vector>
#include "chambre.h"
#include <iostream>
#include "client.h"
#include "reservation.h"

class Hotel {
	public:
		Hotel(std::string id_hotel, std::string nom_hotel, std::string ville_hotel, std::vector<Chambre> nombre_chambre);
		std::string id_hotel();
		std::string nom_hotel();
		std::string ville_hotel();
		std::vector<Chambre> nombre_chambre();
		void add_chambre(Chambre c);
		void display(std::vector<Chambre> &v);
		void display(std::vector<Client>& v);
		void display(std::vector<Reservation>& v);
		friend std::ostream& operator<<(std::ostream& os, Hotel h);
		void display_numresa(Reservation r);
		void display_resanumclient(std::string num);

	private:
		std::string _id_hotel;
		std::string _nom_hotel;
		std::string _ville_hotel;
		std::vector<Chambre> _nombre_chambre;
};