#include <iostream>
using namespace std;

// déclaration des constantes

// LIMITES DE POIDS POUR CHAQUE LETTRE (en g)
const int limitePoids1 = 27;
const int limitePoids2 = 81;
const int limitePoids3 = 120;

// PRIX POUR CHAQUE LETTRE (en $)
const float prix1 = 0.45;
const float prix2 = 0.90;
const float prix3 = 1.10;
const float prix4 = 1.50;

// AUTRES
const float rabaisGrosEnvois = 0.10; // 10% de rabais
const int montantPlafondPourRabais = 20;



// FONCTION PRINCIPALE
void main() {

	// déclaration des variables
	double poidsLettre;
	double coutLettre = 0;
	int nbLettres = 0;
	double sousTotal = 0;
	double reduction = 0;
	double grandTotal = 0;


	// saisie des données + traitement pour chaque saisie
	do {
		cout << "Saisir le poids de la lettre ? ";
		cin >> poidsLettre;

		// cas de traitement d'erreur de saisie
		if (poidsLettre < 0){
			cout << "Vous avez fait une erreur de saisie, merci de recommencer " << endl;
		}

		// cas de traitement de saisies standard
		else if (poidsLettre < limitePoids1){
			coutLettre = prix1;
		}
		else if (poidsLettre < limitePoids2){
			coutLettre = prix2;
		}
		else if (poidsLettre < limitePoids3){
			coutLettre = prix3;
		}
		else{
			coutLettre = prix3;
		}

		// incrément du nombre de lettre
		nbLettres++;
		// incrément du cout d'envoi
		sousTotal += coutLettre;

	} while
		(poidsLettre != 0);

	cout << "Le cout de l envoi avant reduction est de : " << sousTotal << endl;

	
	// TRAITEMENT GLOBAL DU COUT APRES SAISIES
	if (sousTotal > montantPlafondPourRabais){
		reduction = sousTotal * rabaisGrosEnvois;
		cout << "Le montant de la reduction pour cet envois consequent est de " << reduction << endl;
	}

	grandTotal = sousTotal - reduction;
	cout << "Le cout de l envoi total est de : " << grandTotal << endl;
}