#include <iostream>
using namespace std;

// déclaration des constantes

// LIMITES DE POIDS POUR CHAQUE LETTRE (en g)
const int limitePoids1 = 27;
const int limitePoids2 = 81;
const int limitePoids3 = 120;

// PRIX POUR CHAQUE LETTRE (en $)
const double prix1 = 0.45;
const double prix2 = 0.90;
const double prix3 = 1.10;
const double prix4 = 1.50;

// VALEURS/COUT DES TAXES
const double taxeTPS = 0.05; 
const double taxeTVQ = 0.09975;

// AUTRES
const double rabaisGrosEnvois = 0.10; // 10% de rabais
const int montantPlafondPourRabais = 20;




// FONCTION PRINCIPALE
void main() {

	// déclaration des variables
	double poidsLettre;
	double coutLettre = 0;
	double sousTotal = 0;
	double montantTaxes = 0;
	double reduction = 0;
	double grandTotal = 0;
	bool saisieCorrecte = false;


	// saisie des données + traitement pour chaque saisie
	do {
		cout << "Saisir le poids de la lettre ? ";
		cin >> poidsLettre;

		// cas de traitement d'erreur de saisie (pas un nombre)
		if (cin.fail() || cin.peek() != '\n'){
			coutLettre = 0;
			cout << "Vous avez fait une erreur de saisie, merci de recommencer " << endl;
			cin.clear(); // réinitialise le "cin"
			cin.ignore(512, '\n'); // vide le tampon clavier jusqu'a un retour a la ligne
		}
		else{
			saisieCorrecte = true;
			coutLettre = 0;
		}


		// cas de traitement d'erreur de saisie (nombre invalide)
		if (poidsLettre < 0){
			cout << "Le poids saisi est négatif, recommencez " << endl;
			coutLettre = 0;
		}

		// cas de traitement pour : Saisie = 0
		else if (poidsLettre == 0){
			coutLettre = 0;
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
			coutLettre = prix4;
		}

		// incrément du cout d'envoi
		sousTotal += coutLettre;
	} while
		(poidsLettre != 0);

	// 1) affichage sous-total
	cout << "Le cout de l envoi HT, avant reduction est de : " << sousTotal << endl;


	// TRAITEMENT GLOBAL DU COUT APRES SAISIES
	if (sousTotal > montantPlafondPourRabais){
		reduction = sousTotal * rabaisGrosEnvois;
		// 2) affichage reduction (seulement si necessaire)
		cout << "Le montant de la reduction pour cet envois consequent est de " << reduction << endl;
	}
	// MAJ du sous-total "dans tous les cas"
	sousTotal -= reduction;


	// TRAITEMENT DES TAXES
	montantTaxes += sousTotal * taxeTPS;
	montantTaxes += sousTotal * taxeTVQ;
	// 3) affichage taxes
	cout << "Le montant des taxes est de " << montantTaxes << endl;


	// TRAITEMENT FINAL
	grandTotal = sousTotal + montantTaxes - reduction;
	// 4) affichage grand-total
	cout << "Le cout de l envoi total est de : " << grandTotal << endl;
}