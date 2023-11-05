#include <cstddef>

void allocate_not_free()
{
	int *p = new int;
}

int main()
{
	// alustamattomaan osoittimeen viedään arvo
	int *p1;
	*p1 = 20;

	// NULL-osoitteeseen viedään arvo
	int *p2 = NULL;
	*p2 = 20;
	
	// Muistivuoto aliohjelmassa
	allocate_not_free();


	// indexointi taulukon ulkopuolelta stackissa
	int array[10];
	array[29] = 20;

	// indexointi taulukon ulkopuolelta heapissa
	int *array_p = new int[20];
	array_p[30] = 20;
}
