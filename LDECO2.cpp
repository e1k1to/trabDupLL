#include <iostream>
#include "LDL.h"

using namespace std;

LDL *intercala(LDL *Lista1, LDL *Lista2){
	LDL *lista3 = new LDL();
	No *pAnda = nullptr;
	int chave;
	Elemento dado;
	pAnda = Lista1->getCabeca()->getAnt();
	while(!Lista1->isEmpty()){
		//pAnda = Lista1->getCabeca();
		chave = pAnda->getChave();
		dado = pAnda->getDado();
		pAnda = pAnda->getAnt();
		Lista1->remove(chave);
		//Esvazia a lista 1, colocando seus elementos na lista 3
		lista3->insereOrdemCrescente(chave, dado);
	}
	pAnda = Lista2->getCabeca()->getAnt();
	while(!Lista2->isEmpty()){
		//pAnda = Lista2->getCabeca();
		chave = pAnda->getChave();
		dado = pAnda->getDado();
		//Lista2->remove(chave);
		pAnda = pAnda->getAnt();
		Lista2->remove(chave);
		//Esvazia a lista 2, colocando seus elementos na lista 3
		lista3->insereOrdemCrescente(chave,dado);
	}
	return lista3;
}

// Programa Principal que testa a LDL
int main() {
	LDL *lista1 = new LDL();
	LDL *lista2 = new LDL();
	lista1->insereOrdemCrescente(2, 2); // insere (chave, dado)
	lista1->insereOrdemCrescente(10, 10);
	lista1->insereOrdemCrescente(25, 25);
	lista1->insereOrdemCrescente(12, 12);

	lista2->insereOrdemCrescente(23, 23);
	lista2->insereOrdemCrescente(55, 55);
	lista2->insereOrdemCrescente(22, 22);
	lista2->insereOrdemCrescente(43, 43);
	
	cout << "\nCrescente Lista 1:" << endl;
	lista1->mostraOrdemCrescente();
	cout << "\nCrescente Lista 2:" << endl;
	lista2->mostraOrdemCrescente();
	
	cout << "\nDecrescente Lista 1:" << endl;
	lista1->mostraOrdemDecrescente();
	cout << "\nDecrescente Lista 2:" << endl;
	lista2->mostraOrdemDecrescente();
	
	LDL * lista3 = intercala(lista1,lista2);
	cout << "\nListas juntas:" << endl;
	lista3->mostraOrdemCrescente();
	// Faz uma pausa antes de finalizar o programa
	cout << endl << endl;
	system("pause");
	return 0;
}
