#include "hotel.h"

Hotel::Hotel(std::string id_hotel, std::string nom_hotel, std::string ville_hotel, 
std::vector<Chambre> nombre_chambre) : _id_hotel(id_hotel), _nom_hotel(nom_hotel),
_nombre_chambre(nombre_chambre) {
}

std::string Hotel::id_hotel() {
	return _id_hotel;
}

std::string Hotel::nom_hotel() {
	return _nom_hotel;
}

std::string Hotel::ville_hotel() {
    return _ville_hotel;
}

void Hotel::display(std::vector<Chambre> &v)
{
    for (int i=0; i < v.size(); i++)
    {
       std::cout << v[i].affiche_chambre() << " ";
    }
    std::cout << "\n" << std::endl;
}

void Hotel::display(std::vector<Client>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
    std::cout << "\n" << std::endl;
}

void Hotel::display(std::vector<Reservation>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
    std::cout << "\n" << std::endl;
}

void Hotel::add_chambre(Chambre c) {
    _nombre_chambre.push_back(c);
}

std::ostream& operator<<(std::ostream& os, Hotel h) {
    os << h.id_hotel() << " - " << h.nom_hotel() << " - " << h.ville_hotel();
    return os;
}

void Hotel::display_numresa(Reservation r) {
    std::cout << r;
}



