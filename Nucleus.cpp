#include "Nucleus.h"
/*
initalize the gene and sets the fields to the parmaters
Input:const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand
Ouput:none
*/
void Gene::init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand) 
{
	//sets fiels to parmas
	this->_start = start;
	this->_end = end;
	this->_on_complementary_dna_strand = on_complementary_dna_strand;
}
/*
get the complementary dna strand
Input: none
Ouput:true/false
*/
bool Gene::is_on_complementary_dna_strand() const 
{
	return this->_on_complementary_dna_strand;
}
/*
get the _start field of the class
Input:none
Ouptut:the field (unsigned int)
*/
unsigned int Gene::get_start() const
{
	return this->_start;
}
/*
get the _end field of the class
Input:none
Ouptut:the field (unsigned int)
*/
unsigned int Gene::get_end() const
{
	return this->_end;
}

/*
The function initalize the object and builds the complement DNA 
Input:string data_sequnce
Output:none
*/
void Nucleus::init(const std::string dna_sequence)
{
	/*
	G=C
	C=G
	T=A
	A=T
	*/
	unsigned int i = 0;
	this->_DNA_strand= dna_sequence;
	
	for (i = 0; i < dna_sequence.length(); i++)
	{
		//builds the complement string 
		switch (dna_sequence[i]) 
		{
			case 'A':
				this->_complementary_DNA_strand += 'T';
				break;
			case 'T':
				this->_complementary_DNA_strand += 'A';
				break;
			case 'G':
				this->_complementary_DNA_strand += 'C';
				break;
			case 'C':
				this->_complementary_DNA_strand += 'G';
				break;
			default:
				std::cerr << "Error!Illegal letters!";//print error
				_exit(1);//an error occurod so we ending the program
				break;
		}
					
	}
}

/*The function builds the RNA transcript and replace the T character with the U
Input:const Gene&gene 
Output:return the reuslt RNA 
*/
std::string Nucleus::get_RNA_transcript(const Gene& gene) const
{
	
	std::string result ="";
	std::string strand;
	//check which of the strings we need to use
	if (gene.is_on_complementary_dna_strand()) 
	{
		strand = this->_complementary_DNA_strand;
	}
	else
	{
		strand = this->_DNA_strand;
	}
	unsigned int i = 0;
	//scan the string to replace T with U
	for (i = gene.get_start(); i < gene.get_end(); i++)
	{
		if (strand[i] == 'T') 
		{
			result+= 'U';
		}
		else 
		{
			result += strand[i];
		}
	}
	//return the result
	return result;
}


/*
get the dna in revered order 
Inpuut:none
Ouput:dna in revered order (from end to start )
*/
std::string Nucleus::get_reversed_DNA_strand()const  
{
	//scan the string from the end 
	unsigned int i = 0;
	std::string result = "";
	for ( i = this->_DNA_strand.length(); i >=0 ; i++)
	{
		result += this->_DNA_strand[i];
	}
	return result;
}
/*
get the number of a occurrences of a sub string 
Input:const std::string& codon
Ou tput:reutrn the result 
*/
unsigned int Nucleus::get_num_of_codon_appearances(const std::string& codon) const 
{
	//declare vars 
	int occurrences = 0;
	std::string::size_type pos = 0;
	//scan the string 
	while ((pos = this->_DNA_strand.find(codon, pos)) != std::string::npos) {
		++occurrences;
		pos += codon.length();
	}
	return occurrences;
}


