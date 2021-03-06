//
// Created by yassine on 23/10/2021.
//
#include <iostream>
#include <cassert>
#include "ConsoleColor.h"

void hanoi(long n, char debut, char fin);

void print(char debut, char fin);

int main()
{
	long n{ 0 };
	std::cout << "Ce programme nous permet de voir les differentes etapes pour resoudre une tour hatoi avec " << red
			  << "n " << white << "etages" << std::endl;
	std::cout << "donner le nombre d\'etage :" << std::endl;
	std::cin >> n;
	assert(n > 0);
	hanoi(n, 'A', 'C');
	return 0;
}

void hanoi(long n, char debut, char fin)
{
	char midleMan = 70 - ((int(debut) - 64) + (int(fin) - 64)); //les valeur ascii de A-B-C sont 65-66-67
	//70 est  64 + 6 et ((int(debut) -64 ) + (int (fin) - 64)) est compri entre 3 et 5
	//midleMan ne peut donc prendre que une des 3 valeur qui corespende au groupe A-B-C

	if (n == 1)        //si il n'y a qu'une tour a deplacer
	{
		print(debut, fin);
	}
	else
	{
		hanoi(n - 1, debut, midleMan);        //deplacer n-1 etagess de debut vers midleMan en utilisant fin
		print(debut, fin);                        //deplacer 1 etage de debut vers fin
		hanoi(n - 1, midleMan, fin);            //deplacer n-1 etagess de midleMan vers fin en utilisant debut
	}
}

void print(char debut, char fin)
{
	static int etape{ 1 };
	std::cout << blue << "etape " << yellow << etape << blue << " : " << red << debut << white << "->" << red << fin
			  << std::endl;
	++etape;
}
