#include "namen.hpp"
#include <string>

class vlist
{
	private:
		namen * elemente;


	public:
		vlist() {this -> elemente = NULL;} //Standardkonstruktor
		~vlist(); //Dekonstruktor
		namen * GetFirstElement();
		namen * GetLastElement();
		void AddElement(std::string,std::string,int);
		void InsertElement(std::string,std::string,int);
		void AddElement(namen);
		void InsertElement(namen);
		void Output();
		void OutputAt(int);

};
