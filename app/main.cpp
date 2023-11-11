#include "list.cpp"
#include "polynomial.cpp"
#include "summand.cpp"
#include <iostream>

template<class C>
void transformation(LinkedList<summand<C>>& list, const Polynomial<C>& pol) {
	summand<C> tmp;
	for (int i = 0; i <= pol.get_degree(); i++) {
		tmp.coeff = pol[i];
		if (tmp.coeff == 0) continue; // if coeff = 0, dont push to list
		tmp.degree = i;

		list.push_head(tmp);
	}
}

using namespace std;

int main(){
	
	LinkedList<int> list1;

	//--------1---------//

	list1.push_head(10);
	list1.push_head(15);
	list1.push_head(20);
	cout << "1: \t";
	cout << list1 << endl;

	//--------2---------//

	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	cout << "2: \t";

	cout << list1 << endl;

	//--------3---------//

	list1.pop_head();
	cout << "3: \t";
	cout << list1 << endl;

	//--------4---------//

	list1.pop_tail();
	cout << "4: \t";
	cout << list1 << endl;

	//--------5---------//

	list1.delete_node(20);
	list1.delete_node(10);
	cout << "5: \t";
	cout << list1 << endl;

	//--------6---------//

	LinkedList<int> list2(list1);
	cout << "6: \t";
	cout << list2 << endl;

	//--------7--------//

	cout << "7: \t";
	cout << list1 + list2 << endl;
	
	//--------8--------//

	list1 += list2;
	cout << "8: \t";
	cout << list1 << endl;

	//--------9--------//

	cout << "9: \t";
	cout << list1[0] << endl;

	//--------10--------//
	//-----------------//

	Polynomial<double> pol(2);
	pol.set(10, 0);
	pol.set(0, 1);
	pol.set(6, 2);
	cout << endl << "polynomial:\t" << pol << endl;
	LinkedList<summand<double>> pol_list;
	transformation(pol_list, pol);
	std::cout << "pol_list: \t" << pol_list << std::endl;
	std::cout << "x = 2: \t" << LinkedList<summand<double>>::calculate_list(pol_list, 2) << endl;

	return 0;
}