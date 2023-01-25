#pragma once
#include <string>
#include <ostream>

class Chambre {
	public:
		Chambre(std::string num_chambre, std::string type_chambre, int prix_chambre);
		std::string num_chambre();
		std::string type_chambre();
		int prix_chambre();
		void set_prix_chambre(double prix);
		std::string affiche_chambre();
		friend std::ostream& operator<<(std::ostream& os, Chambre c);

	private:
		std::string _num_chambre;
		std::string _type_chambre;
		int _prix_chambre;

};