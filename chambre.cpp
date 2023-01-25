#include "chambre.h"

Chambre::Chambre(std::string num_chambre, std::string type_chambre, int prix_chambre) : _num_chambre(num_chambre), _type_chambre(type_chambre), _prix_chambre(prix_chambre) {
}

std::string Chambre::num_chambre() {
	return _num_chambre;
}

std::string Chambre::type_chambre() {
	return _type_chambre;
}

int Chambre::prix_chambre() {
	return _prix_chambre;
}

void Chambre::set_prix_chambre(double prix) {
	_prix_chambre = prix;
}

std::string toString_prix(double prix) {
	return std::to_string(prix);
}

std::string Chambre::affiche_chambre() {
	return "Numero de la chambre : " + num_chambre() + "\n" + "Type de la chambre : " + type_chambre() + "\n" + "Prix de la chambre : " + toString_prix(prix_chambre()) + " euros \n \n \n";
}

std::ostream& operator<<(std::ostream& os, Chambre c) {
	os << c.num_chambre() << " - " << c.type_chambre() << " - " << c.prix_chambre();
	return os;
}