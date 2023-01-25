#include "client.h"

Client::Client(std::string id_client, std::string nom, std::string prenom) :
	_id_client(id_client),_nom(nom), _prenom(prenom) {
}

std::string Client::id_client() {
	return _id_client;
}

std::string Client::nom(){
	return _nom;
}

std::string Client::prenom() {
	return _prenom;
}

std::ostream& operator<<(std::ostream& os, Client c) {
	os << c.id_client() << " - " << c.nom() << " - " << c.prenom();
	return os;
}



