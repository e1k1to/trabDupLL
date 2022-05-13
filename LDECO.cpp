#include <iostream>
#include "LDL.h"

using namespace std;

void intercala(LDL *Lista1, LDL *Lista2, LDL *lista3){
	//LDL *lista3 = new LDL();
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
}

int menu(){
	int escolha;
	cout << "\n\nTrabalho LDECO:" << endl;
	cout << "\nEscolha uma das opções do menu:\n1-Mostrar listas em ordem crescente.\n2-Mostrar listas em ordem decrescente.\n3-Remover elemento da lista.\n4-Substituir dado da lista.\n5-Criar lista 3, juntando as listas 1 e 2 (isso apagará as listas 1 e 2).\n0-Fechar o programa." << endl;
	cin >> escolha;
	return escolha;
}

// Programa Principal que testa a LDL
int main() {
	LDL *lista1 = new LDL();
	LDL *lista2 = new LDL();
	LDL *lista3 = new LDL();
	int escolha, escolhaLista, chaveEsc, dadoEsc;
	
	lista1->insereOrdemCrescente(2, 2); // insere (chave, dado)
	lista1->insereOrdemCrescente(10, 10);
	lista1->insereOrdemCrescente(25, 25);
	lista1->insereOrdemCrescente(12, 12);

	lista2->insereOrdemCrescente(23, 23);
	lista2->insereOrdemCrescente(55, 55);
	lista2->insereOrdemCrescente(22, 22);
	lista2->insereOrdemCrescente(43, 43);
	
	while(true){
		escolha = menu();
		switch(escolha){
			case 0:
				return 0;
				break;

			case 1:
				cout << "\nCrescente Lista 1:" << endl;
				lista1->mostraOrdemCrescente();
				cout << "\nCrescente Lista 2:" << endl;
				lista2->mostraOrdemCrescente();
				cout << "\nCrescente Lista 3:" << endl;
				lista3->mostraOrdemCrescente();
				break;
			case 2:
				cout << "\nDecrescente Lista 1:" << endl;
				lista1->mostraOrdemDecrescente();
				cout << "\nDecrescente Lista 2:" << endl;
				lista2->mostraOrdemDecrescente();
				cout << "\nDecrescente Lista 3:" << endl;
				lista3->mostraOrdemDecrescente();
				break;
			case 3:
				cout << "Digite o número da lista da qual deseja excluir um elemento (1,2,3):" << endl;
				cin >> escolhaLista;
				cout << "Digite a chave (não dado) do elemento que deseja excluir:" << endl;
				cin >> chaveEsc;
				switch(escolhaLista){
					case 1:
						lista1->remove(chaveEsc);
						break;
					case 2:
						lista2->remove(chaveEsc);
						break;
					case 3:
						lista3->remove(chaveEsc);
						break;
				}
				break;
			case 4:
				cout << "Digite o número da lista da qual deseja alterar um elemento (1,2,3):" << endl;
				cin >> escolhaLista;
				cout << "Digite a chave (não dado) do elemento que deseja alterar:" << endl;
				cin >> chaveEsc;
				cout << "Digite o novo dado do elemento:" << endl;
				cin >> dadoEsc;
				switch(escolhaLista){
					case 1:
						if(lista1->atualiza(chaveEsc,dadoEsc)) cout << "\nAlterado com sucesso." << endl;
						else cout << "Falha na alteração" << endl;
						break;
					case 2:
						if(lista2->atualiza(chaveEsc,dadoEsc)) cout << "\nAlterado com sucesso." << endl;
						else cout << "Falha na alteração" << endl;
						break;
					case 3:
						if(lista3->atualiza(chaveEsc,dadoEsc)) cout << "\nAlterado com sucesso." << endl;
						else cout << "Falha na alteração" << endl;
						break;
				}
				break;
			case 5:
				intercala(lista1,lista2,lista3);
				//cout << "\nListas juntas:" << endl;
				//lista3->mostraOrdemCrescente();
	// Faz uma pausa antes de finalizar o programa
	system("pause");
		}
	}
}
