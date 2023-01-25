#include <iostream>
#include "client.h"
#include "date.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"
#include <vector>



int main() {

	
	std::vector<Chambre> toutes_chambres;

	Chambre chambre1("101", "simple", 100);
	Chambre chambre2("202", "simple", 100);
	Chambre chambre3("303", "simple", 100);
	Chambre chambre4("404", "double", 125);
	Chambre chambre5("505", "double", 125);
	Chambre chambre6("606", "double", 125);
	Chambre chambre7("707", "double", 125);
	Chambre chambre8("808", "double", 125);
	Chambre chambre9("909", "suite", 210);
	Chambre chambre10("1010", "suite", 210);

	toutes_chambres.push_back(chambre1);
	toutes_chambres.push_back(chambre2);
	toutes_chambres.push_back(chambre3);
	toutes_chambres.push_back(chambre4);
	toutes_chambres.push_back(chambre5);
	toutes_chambres.push_back(chambre6);
	toutes_chambres.push_back(chambre7);
	toutes_chambres.push_back(chambre8);
	toutes_chambres.push_back(chambre9);
	toutes_chambres.push_back(chambre10);

	Hotel h("1226", "le bellavo", "Dijon", toutes_chambres);

	//std::cout << "voici la liste des chambres \n";
	//h.display(toutes_chambres);

	std::vector<Client> liste_client;

	Client client1("1111", "Contant", "Maxence");
	Client client2("2222", "Donzelot", "Maxime");
	Client client3("3333", "Ginhac", "Dominique");
	Client client4("4444", "Meunier", "Charles");

	liste_client.push_back(client1);
	liste_client.push_back(client2);
	liste_client.push_back(client3);
	liste_client.push_back(client4);

	//std::cout << "voici la liste des clients \n";
	//h.display(liste_client);

	std::vector<Reservation> tableau_resa;
	//std::cout << "voici la liste des reservations \n";
	//h.display(tableau_resa);

	Date d1(10, 02, 2023);
	Date d2(17, 06, 2023);
	Date d3(23, 11, 2023);
	Date d4(1, 06, 2023);

	Reservation r1(d1, 3, h.id_hotel(), chambre3.num_chambre(), client1.id_client());
	Reservation r2(d2, 2, h.id_hotel(), chambre6.num_chambre(), client2.id_client());
	Reservation r3(d3, 1, h.id_hotel(), chambre8.num_chambre(), client3.id_client());
	Reservation r4(d4, 6, h.id_hotel(), chambre10.num_chambre(), client4.id_client());

	tableau_resa.push_back(r1);
	tableau_resa.push_back(r2);
	tableau_resa.push_back(r3);
	tableau_resa.push_back(r4);

	//h.display(tableau_resa);
	
	
	std::cout << "Bonjour, bienvenue au centre des informations de l'hotel Le Bellavo de Dijon ! \n\n\nVous trouverez ci-apres la liste des informations de l'hotel. Que voulez vous faire ? Tapez 1 pour reserver, 2 pour voir toutes les reservations, 3 pour voir une \nreservation en particulier avec le num de reservation, 4 pour voir la reservation avec le num client, 5 pour modifier une reservation, 6 pour en annuler une. \n\n\n";
	
	std::cout << "voici la liste des chambres \n";
	h.display(toutes_chambres);

	std::cout << "voici la liste des clients \n";
	h.display(liste_client);

	std::cout << "voici la liste des reservations \n";
	h.display(tableau_resa);

	int g;
	std::cin >> g;
	
	if (g == 1) {
		std::cout << "Entrez le nom d'un client qui sera recherché ou crée s'il n'existe pas. \n";
		std::string nom;
		std::cin >> nom;

		for (int i = 0; i < liste_client.size(); i++) {
			if (nom == liste_client.at(i).nom()) {
				std::cout << liste_client.at(i);

				bool z = false;
				int a, b, c;
				while (z == false) {
					std::cout << "\nEntrez une date pour la reservation dans cet ordre (jour, mois, annee):";

					std::cin >> a;
					std::cin >> b;
					std::cin >> c;

					if (isDate(b, a) == true)
						z = true;
				}

				Date d(a, b, c);

				std::cout << "la date de la reservation est " << toString(d) << "\n" << "Entrez maintenant le nombre de nuits \n";
				int e;
				std::cin >> e;
				std::cout << "Vous avez reserve le " << toString(d) << " pour une duree totale de " << e << " nuits. \n";

				std::cout << "Quel type de chambre souhaitez vous ? tapez 1 pour une simple, 2 pour une double ou 3 pour une suite. \n";
				int r;
				std::cin >> r;

				if (r == 1) {
					std::cout << "Vous allez vous voir attribuer une chambre simple. \nVoici le recapitulatif de votre reservation :\n";
					std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : simple \nId client : " << liste_client.at(i).id_client();
					Reservation r(d, e, h.id_hotel(), "101", liste_client.at(i).id_client());
					tableau_resa.push_back(r);
					r.montant_total(chambre1.prix_chambre());
					std::cout << "le tableau des reservations est \n";
					h.display(tableau_resa);
					return 0;
				}
				else if (r == 2) {
					std::cout << "Vous allez vous voir attribuer une chambre double. \nVoici le recapitulatif de votre reservation :\n";
					std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : double \nId client : " << liste_client.at(i).id_client();
					Reservation r(d, e, h.id_hotel(), "404", liste_client.at(i).id_client());
					tableau_resa.push_back(r);
					r.montant_total(chambre4.prix_chambre());
					std::cout << "le tableau des reservations est \n";
					h.display(tableau_resa);
					return 0;
				}

				else {
					std::cout << "Vous allez vous voir attribuer une suite. \nVoici le recapitulatif de votre reservation :\n";
					std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : suite \nId client : " << liste_client.at(i).id_client();
					Reservation r(d, e, h.id_hotel(), "909", liste_client.at(i).id_client());
					tableau_resa.push_back(r);
					r.montant_total(chambre9.prix_chambre());
					std::cout << "le tableau des reservations est \n";
					h.display(tableau_resa);
					return 0;
				}

			}
			else {
				std::cout << "client inconnu, entrez un id client " << std::endl;
				std::string id;
				std::cin >> id;

				std::cout << "puis le prenom du client " << std::endl;
				std::string prenom;
				std::cin >> prenom;

				Client newclient(id, nom, prenom);
				std::cout << "voici les caracteristiques du nouveau client : " << newclient << std::endl;
				liste_client.push_back(newclient);
				std::cout << " la liste actualisée est \n";
				h.display(liste_client);

				std::cout << "\nEntrez une date pour la reservation dans cet ordre (jour, mois, annee):";
				bool z = false;
				int a, b, c;
				while (z == false) {
					std::cout << "\nEntrez une date pour la reservation dans cet ordre (jour, mois, annee):";

					std::cin >> a;
					std::cin >> b;
					std::cin >> c;

					if (isDate(b, a) == true)
						z = true;
				}

				Date d(a, b, c);

				std::cout << "la date de la reservation est " << toString(d) << "\n" << "Entrez maintenant le nombre de nuits \n";
				int e;
				std::cin >> e;
				std::cout << "Vous avez reserve le " << toString(d) << " pour une duree totale de " << e << " nuits. \n";

				std::cout << "Quel type de chambre souhaitez vous ? tapez 1 pour une simple, 2 pour une double ou 3 pour une suite. \n";
				int r;
				std::cin >> r;

				if (r == 1) {
					std::cout << "Vous allez vous voir attribuer une chambre simple. \nVoici le recapitulatif de votre reservation :\n";
					std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : simple \nId client : " << id;
					Reservation r(d, e, h.id_hotel(), "101", id);
					tableau_resa.push_back(r);
					r.montant_total(chambre1.prix_chambre());
					std::cout << "le tableau des reservations est \n";
					h.display(tableau_resa);
					return 0;
				}
				else if (r == 2) {
					std::cout << "Vous allez vous voir attribuer une chambre double. \nVoici le recapitulatif de votre reservation :\n";
					std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : double \nId client : " << id;
					Reservation r(d, e, h.id_hotel(), "404", id);
					tableau_resa.push_back(r);
					r.montant_total(chambre4.prix_chambre());
					std::cout << "le tableau des reservations est `n";
					h.display(tableau_resa);
					return 0;
				}

				else {
					std::cout << "Vous allez vous voir attribuer une suite. \nVoici le recapitulatif de votre reservation :\n";
					std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : suite \nId client : " << id;
					Reservation r(d, e, h.id_hotel(), "909", id);
					tableau_resa.push_back(r);
					r.montant_total(chambre9.prix_chambre());
					std::cout << "le tableau des reservations est \n";
					h.display(tableau_resa);
					return 0;
				}
			}
		}
		std::cout << "client inconnu, entrez un id client " << std::endl;
		std::string id;
		std::cin >> id;

		std::cout << "puis le prenom du client " << std::endl;
		std::string prenom;
		std::cin >> prenom;

		Client newclient(id, nom, prenom);
		std::cout << "voici les caracteristiques du nouveau client : " << newclient << std::endl;
		liste_client.push_back(newclient);
		std::cout << " la liste actualisée est \n";
		h.display(liste_client);

		std::cout << "\nEntrez une date pour la reservation dans cet ordre (jour, mois, annee):";
		bool z = false;
		int a, b, c;
		while (z == false) {
			std::cout << "\nEntrez une date pour la reservation dans cet ordre (jour, mois, annee):";

			std::cin >> a;
			std::cin >> b;
			std::cin >> c;

			if (isDate(b, a) == true)
				z = true;
		}

		Date d(a, b, c);

		std::cout << "la date de la reservation est " << toString(d) << "\n" << "Entrez maintenant le nombre de nuits \n";
		int e;
		std::cin >> e;
		std::cout << "Vous avez reserve le " << toString(d) << " pour une duree totale de " << e << " nuits. \n";

		std::cout << "Quel type de chambre souhaitez vous ? tapez 1 pour une simple, 2 pour une double ou 3 pour une suite. \n";
		int r;
		std::cin >> r;

		if (r == 1) {
			std::cout << "Vous allez vous voir attribuer une chambre simple. \nVoici le recapitulatif de votre reservation :\n";
			std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : simple \nId client : " << id;
			Reservation r(d, e, h.id_hotel(), "101", id);
			tableau_resa.push_back(r);
			r.montant_total(chambre1.prix_chambre());
			std::cout << "le tableau des reservations est \n";
			h.display(tableau_resa);
			return 0;
		}
		else if (r == 2) {
			std::cout << "Vous allez vous voir attribuer une chambre double. \nVoici le recapitulatif de votre reservation :\n";
			std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : double \nId client : " << id;
			Reservation r(d, e, h.id_hotel(), "404", id);
			tableau_resa.push_back(r);
			r.montant_total(chambre4.prix_chambre());
			std::cout << "le tableau des reservations est `n";
			h.display(tableau_resa);
			return 0;
		}

		else {
			std::cout << "Vous allez vous voir attribuer une suite. \nVoici le recapitulatif de votre reservation :\n";
			std::cout << "Date de reservation :" << toString(d) << "\nNombre de nuits : " << e << "\nA l'hotel : " << h.nom_hotel() << "\nChambre de type : suite \nId client : " << id;
			Reservation r(d, e, h.id_hotel(), "909", id);
			tableau_resa.push_back(r);
			r.montant_total(chambre9.prix_chambre());
			std::cout << "le tableau des reservations est \n";
			h.display(tableau_resa);
			return 0;
		}

	}
	else if (g == 2) {
		h.display(tableau_resa);
		return 0;
	}

	else if (g == 3) {

		std::cout << "entrez un numero de reservation (exemple r1, r2...)";
		std::string res;
		std::cin >> res;

		if (res == "r1")
			std::cout << r1;
		else if (res == "r2")
			std::cout << r2;
		else if (res == "r3")
			std::cout << r3;
		else
			std::cout << r4;
		return 0;
	}
	else if (g == 4) {
		std::cout << "entrez un id client \n";
		std::string id;
		std::cin >> id;

		for (int i = 0; i < tableau_resa.size(); i++)
		{
			if (tableau_resa.at(i).id_client() == id)
			std::cout << " la reservation correspondante est \n" << tableau_resa.at(i) << "\n";
		}
		return 0;
	}
	else if (g == 5) {
		std::cout << "Quelle reservation souhaitez vous modifier ? Tapez 1 pour r1, 2 pour r2...\n";
		int i;
		std::cin >> i;
		
		if (i == 1) {
			std::cout << "que souhaitez vous modifier ? Tapez 1 pour la date, 2 pour le nombre de nuits, 3 pour le type de chambre\n";
			int j;
			std::cin >> j;
			if (j == 3) {
				std::cout << "pour une chambre simple, tapez &, pour une double 2 et une suite 3 \n";
				int k;
				std::cin >> k;
				if (k == 1)
					r1.change_id_chambre("202");
				else if (k == 2)
					r1.change_id_chambre("606");
				else
					r1.change_id_chambre("1010");
			}

			else if (j == 2) {
				std::cout << "Entrez le nouveau nombre de nuits \n";
				int l;
				std::cin >> l;
				r1.change_nombre_nuits(l);
			}

			else {
				std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";
				bool z = false;
				int a, b, c;
				while (z == false) {
					std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";

					std::cin >> a;
					std::cin >> b;
					std::cin >> c;

					if (isDate(b, a) == true)
						z = true;
				}
				Date df(a, b, c);
				r1.change_date_debut(df);
				tableau_resa.at(0).change_date_debut(df);
			}

		}

		else if (i == 2) {
			std::cout << "que souhaitez vous modifier ? Tapez 1 pour la date, 2 pour le nombre de nuits, 3 pour le type de chambre\n";
			int j;
			std::cin >> j;
			if (j == 3) {
				std::cout << "pour une chambre simple, tapez &, pour une double 2 et une suite 3 \n";
				int k;
				std::cin >> k;
				if (k == 1)
					r2.change_id_chambre("202");
				else if (k == 2)
					r2.change_id_chambre("606");
				else
					r2.change_id_chambre("1010");
			}

			else if (j == 2) {
				std::cout << "Entrez le nouveau nombre de nuits \n";
				int l;
				std::cin >> l;
				r2.change_nombre_nuits(l);
			}

			else {
				std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";
				bool z = false;
				int a, b, c;
				while (z == false) {
					std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";

					std::cin >> a;
					std::cin >> b;
					std::cin >> c;

					if (isDate(b, a) == true)
						z = true;
				}
				Date df(a, b, c);
				r2.change_date_debut(df);
				tableau_resa.at(1).change_date_debut(df);
			}
		}
		else if (i == 3) {
			std::cout << "que souhaitez vous modifier ? Tapez 1 pour la date, 2 pour le nombre de nuits, 3 pour le type de chambre\n";
			int j;
			std::cin >> j;
			if (j == 3) {
				std::cout << "pour une chambre simple, tapez &, pour une double 2 et une suite 3 \n";
				int k;
				std::cin >> k;
				if (k == 1)
					r3.change_id_chambre("202");
				else if (k == 2)
					r3.change_id_chambre("606");
				else
					r3.change_id_chambre("1010");
			}

			else if (j == 2) {
				std::cout << "Entrez le nouveau nombre de nuits \n";
				int l;
				std::cin >> l;
				r3.change_nombre_nuits(l);
			}

			else {
				std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";
				bool z = false;
				int a, b, c;
				while (z == false) {
					std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";

					std::cin >> a;
					std::cin >> b;
					std::cin >> c;

					if (isDate(b, a) == true)
						z = true;
				}
				Date df(a, b, c);
				r3.change_date_debut(df);
				tableau_resa.at(2).change_date_debut(df);
			}
		}

		else {
			std::cout << "que souhaitez vous modifier ? Tapez 1 pour la date, 2 pour le nombre de nuits, 3 pour le type de chambre\n";
			int j;
			std::cin >> j;
			if (j == 3) {
				std::cout << "pour une chambre simple, tapez &, pour une double 2 et une suite 3 \n";
				int k;
				std::cin >> k;
				if (k == 1)
					r4.change_id_chambre("202");
				else if (k == 2)
					r4.change_id_chambre("606");
				else
					r4.change_id_chambre("1010");
			}

			else if (j == 2) {
				std::cout << "Entrez le nouveau nombre de nuits \n";
				int l;
				std::cin >> l;
				r4.change_nombre_nuits(l);
			}

			else {
				std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";
				bool z = false;
				int a, b, c;
				while (z == false) {
					std::cout << "\nEntrez une nouvelle date pour la reservation dans cet ordre (mois, jour, annee):";

					std::cin >> a;
					std::cin >> b;
					std::cin >> c;

					if (isDate(b, a) == true)
						z = true;
				}
				Date df(a, b, c);
				r4.change_date_debut(df);
				tableau_resa.at(3).change_date_debut(df);
			}
		
		}
		h.display(tableau_resa);
		return 0;
	}

	else {
		std::cout << "quelle reservation voulez-vous supprimer ? Entrez un numero de reservation ( exemple 1 pour supprimer r1 ) \n";
		int numr = 0;
		std::cin >> numr;
		if (numr == 1)
			tableau_resa.erase(tableau_resa.begin());
		else if (numr == 2)
			tableau_resa.erase(tableau_resa.begin() + 1);
		else if (numr == 3)
			tableau_resa.erase(tableau_resa.begin() + 2);
		else if (numr == 4)
			tableau_resa.erase(tableau_resa.begin() + 3);
		else {
			std::cout << "impossible d'effacer une reservation inexistante \n";
			return 0;
		}
		std::cout << "voici le tableau mis a jour \n";
		h.display(tableau_resa);
		return 0;
	}
}
