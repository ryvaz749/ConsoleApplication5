// ConsoleApplication5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
int main()
{
	/*el programa recibe un string con las palabras juntas y con la primera letra de cada palabra en mayuscula y las separa, dejandolas todas en minusculas*/
		/*s sera la variable donde almacenaremos el string*/
	string s;
	cout << "string"<<endl;
	/*aqui guardamos el string que el usuario ingreso en la variable s*/
	getline(cin, s);
	/*la primer letra siempre estara en mayuscula, por lo que automaticamente la ago minuscula*/
	s[0] = tolower(s[0]);
	/*recorro todo el string letra por letra*/
	for (int a = 0; a < s.length(); a++) {
		/*si una letra es mayuscula la hare minuscula y pondre un espacio entre esta y la anterior*/
		if (isupper(s[a])) {
			s[a] = tolower(s[a]);
			s.insert(a, " ");
		}
	}
	cout << s<<endl;
	/*regreso el string*/
	


	//Van Eck sequence
	// en el input se pone el largo que quieres que sea la serie
	int largo;
	cout << "vector" << endl;
	cout << "largo" << endl;
	cin >> largo;
	//sequence es el vector que tendra la sequencia que inicia con 0,0
	vector<int> sequence;
	sequence.push_back(0);
	sequence.push_back(0);
	cout << "0 0 ";
	int i;
	//en este for se va calculando de uno por uno los valores de la serie
	for (int a = 2; a < largo; a++) {
		i = 0;
		//se recorre la serie hacia atras para encontrar cuando fue la ultima ves que aparecio,sino a aparecido es sero
		for (int e = a-2; e >- 1; e--) {
			
			if (sequence[e] == sequence[a - 1]) {
				i = a - e - 1;
				break;
			}
		}
		cout << i << " ";
		sequence.push_back(i);
	}
	cout << endl;




	//se ordena un conjuto de numeros positivos de menor a mayor, pero hay unas que no se pueden mover, marcadas con -1
	list<int> li,lis;
	cout << "list" << endl;
	cout << "largo" << endl;
	int cuantos;
	cin >> cuantos;
	int input;
	cout << "ints" << endl;
	//se obtiene la lista input por input de el largo que se inputio arriba
	for (int a = 0; a < cuantos; a++) {
		cin >> input;
		li.push_back(input);
	}
	//se separan los ints que no son -1 y se ponen en una lista aparte
	for (list<int>::iterator i = li.begin(); i != li.end(); ++i) {
		if (*i != -1) {
			lis.push_back(*i);
		}
	}
	// se ordena la lista de los que se separaron
	lis.sort();
	//se reinsertan a la lista original en los lugares en los que no hay -1
	list<int>::iterator it = lis.begin();
	for(list<int>::iterator i = li.begin(); i != li.end(); ++i) {
		if (*i != -1) {
			*i = *it;
			it++;
			
		}
		cout << *i<<" ";
	}
	cout << endl;





	//de dos lsitas de numeros enteros te regresa una lista con los valores que estan en ambas listas
	set<int> se1, se2;
	cout << "lista1" << endl;
	cout << "largo" << endl;
	cin >> cuantos;
	cout << "ints" << endl;
	//en los imputs se ponen los dos sets
	for (int a = 0; a < cuantos; a++) {
		cin >> input;
		se1.insert(input);
	}
	cout << "lista2" << endl;
	cout << "largo" << endl;
	cin >> cuantos;
	cout << "ints" << endl;
	for (int a = 0; a < cuantos; a++) {
		cin >> input;
		se2.insert(input);
	}
	//va buscando de uno por uno los elementos de un set en el otro, y como son sets no volvera a buscar el mismo
	for (set<int>::iterator i = se1.begin(); i != se1.end(); ++i) {
		if (se2.find(*i) != se2.end()) {
			cout << *se2.find(*i) << " ";
		}
	}
	cout << endl;



	//este es un indice indice por personaje, en el que se pone el personaje y en que pagina sale 
	cout << "map" << endl;
	map<string, vector<int>> indice;
	string st;
	int in, cuantasd;
	st = "x";
	bool v;
	//se pone cuantos pondras y vas poniendo en que pagina esta
	cout << "cuantos" << endl;
	cin >> cuantasd;
	cout << "personaje" << endl;
	cin >> st;
	cout << "pagina" << endl;
	cin >> in;
	vector<int> ve;
	ve.push_back(in);
	indice.insert(pair<string, vector<int>>(st, ve));
	for (int a = 0; a < cuantasd; a++) {
		cout << "personaje" << endl;
		cin >> st;
		cout << "pagina" << endl;
		cin >> in;
		if (indice.find(st) == indice.end()) {
			ve.pop_back();
			ve.push_back(in);
			//si es la primera ves que sale el personaje crea un par para almacenar el personaje y la pagina
			indice.insert(pair<string, vector<int>>(st, ve));
		}
		else {
			//si ya se a usado el personaje se va al vector del personaje y agrega la pagina
			indice[st].push_back(in);
		}
	}
	int len;
	map<string, vector<int>>::iterator ite = indice.begin();
	// aqui se va de personaje en personaje y regresa todos los ints de este
	while (ite != indice.end()) {
		cout << ite->first << " ";
		len = indice[ite->first].size();
		for (int a = 0; a < len; a++) {
			cout << indice[ite->first][a] << " ";
		}
		ite++;
		cout << endl;
	}
	cout << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
