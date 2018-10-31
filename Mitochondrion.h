#include "Protein.h"
class Mitochondrion 
{
private:
	unsigned int _glocuse_level;
	bool _has_glocuse_receptor;
public:
	bool produceATP(const int glocuse_unit) const;
	void set_glucose(const unsigned int glocuse_units);
	void insert_glucose_receptor(const Protein & protein);
	void init();
};