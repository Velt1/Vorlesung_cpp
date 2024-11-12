#include "namen.hpp"
#include<iostream>

namen::namen()

{
	this -> nachname = "";
	this -> vorname = "";
	this -> alter = -1;
	this -> prev = NULL;
	this -> next = NULL;	
}

namen::namen(std::string vorname, std::string nachname, int alter)
{
	this -> nachname = nachname;
	this -> vorname = vorname;
	this -> alter = alter;		
}

void namen::Output()
{
	std::cout << " N: " << this -> nachname << ", V: " << this -> vorname;
	std::cout << ", A: " << this -> alter << std::endl;
}
