#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &);
	~Brain();

	Brain &operator = (const Brain &);

	void setIdea(unsigned int index, const std::string &idea);
	const std::string &getIdea(unsigned int index) const;

private:
	std::string ideas[100];
};

#endif
