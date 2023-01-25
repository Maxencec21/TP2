#include "reservation.h"

Reservation::Reservation(Date date_debut, int nombre_nuits, std::string id_hotel, std::string id_chambre, 
	std::string id_client) : _date_debut(date_debut), _nombre_nuits(nombre_nuits), 
	_id_hotel(id_hotel), _id_chambre(id_chambre), _id_client(id_client){
}

Date Reservation::date_debut() {
	return _date_debut;
}

int Reservation::nombre_nuits() {
	return _nombre_nuits;
}

std::string Reservation::id_hotel() {
	return _id_hotel;
}

std::string Reservation::id_chambre() {
	return _id_chambre;
}

std::string Reservation::id_client() {
	return _id_client;
}

double Reservation::montant_total(double prix_nuit) {
	_montant_total = _nombre_nuits * prix_nuit;
	std::cout << "le montant total est : " << _montant_total << "\n \n \n";
	return _montant_total;
}


void Reservation::change_date_debut(Date debut) {
	_date_debut = debut;
	std::cout << "La nouvelle date est : \n" << toString(debut);
}

void Reservation::change_nombre_nuits(int nombre) {
	_nombre_nuits = nombre;
	std::cout << "le nouveau nombre de nuits est : \n" << nombre;
}

void Reservation::change_id_chambre(std::string id_chambre) {
	_id_chambre = id_chambre;
	std::cout << "le nouvel id chambre est : \n" << id_chambre;
}

std::ostream& operator<<(std::ostream& os, Reservation r){
	os << "date debut : " << toString(r.date_debut()) << " ---- nombre nuit(s) : " << r.nombre_nuits() << " ---- id hotel : " << r.id_hotel() << " ---- id chambre : " << r.id_chambre() << " ---- id client : " << r.id_client() << "\n \n";
	return os;
}