#include "list.cpp"
#include "polynomial.cpp"
#include "summand.cpp"
#include <iostream>

template<class U>
void transformation(LinkedList<summand<U>>& list, const Polynomial<U>& pol) {
	summand<U> tmp;
	for (int i = 0; i <= pol.get_degree(); i++) {
		tmp.coeff = pol[i];
		if (tmp.coeff == 0) continue;
		tmp.degree = i;

		list.push_head(tmp);
	}
}

int main(){
	
	Polynomial<double> pol(2);
	pol.set(10, 0);
	pol.set(0, 1);
	pol.set(6, 2);
	std::cout << pol << std::endl;

	LinkedList<summand<double>> pol_list;
	transformation(pol_list, pol);
	std::cout << pol_list << std::endl;
	std::cout << calculate_list(pol_list, 2);

	return 0;
}