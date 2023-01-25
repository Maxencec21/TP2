#pragma once
#include "date.h"

class Reservation {
	public:
		Reservation(Date date_debut, int nombre_nuits, std::string id_hotel, std::string id_chambre, std::string id_client);
		Date date_debut();
		int nombre_nuits();
		std::string id_hotel();
		std::string id_chambre();
		std::string id_client();
		int prix_nuit();
		double montant_total(double prix_nuit);
		void change_date_debut(Date debut);
		void change_nombre_nuits(int nombre);
		void change_id_chambre(std::string id_chambre);
		friend std::ostream& operator<<(std::ostream& os, Reservation r);

	private:
		Date _date_debut;
		int _nombre_nuits;
		std::string _id_hotel;
		std::string _id_chambre;
		std::string _id_client;
		double _montant_total;
		int _prix_nuit;
};