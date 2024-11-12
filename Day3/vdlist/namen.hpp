#include<string>

class namen
{
	public: /* gilt für den ganzen Block*/
		std::string nachname;
		std::string vorname;
		int alter;
		namen * prev;
		namen * next;
		namen(); //Konstruktor
		namen(std::string, std::string, int);//muss keine Namen für Var hinterlegen
		void Output();

};
