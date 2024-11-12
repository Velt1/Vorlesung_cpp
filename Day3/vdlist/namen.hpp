#include <string>
class namen {
      public:
	std::string nachname;
	std::string vorname;
	int alter;
	namen *prev;
	namen *next;
	namen();
	namen(std::string vorname, std::string nachname, int alter);
	void Output();
};
