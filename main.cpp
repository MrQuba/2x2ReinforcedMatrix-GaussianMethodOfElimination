#include <iostream>

using namespace std;

template < typename T > class TwoElementSquarReinforcedeMatrix
{

  typedef float var;

  typedef unsigned int index;

public:

  TwoElementSquarReinforcedeMatrix (var i0, var i1, var i2, var i3, var r0,
									var r1)
  {

	matrix[0][0] = i0;

	matrix[1][0] = i1;

	matrix[2][0] = r0;



	matrix[0][1] = i2;

	matrix[1][1] = i3;

	matrix[2][1] = r1;

  }

  void gaussianMethodOfElimination ()
  {

	var result;

	displayMatrix ();

	simplifyRow (0);

	displayMatrix ();

	subtractFromRow (1);

	displayMatrix ();

	simplifyRow (1, 1);

	displayMatrix ();



	int x = matrix[2][0] - (matrix[1][1] * matrix[1][0]);

	cout << "X is: " << x << endl << "Y is: " << matrix[1][1];

  }

private:

  void displayMatrix ()
  {

	for (int r = 0; r < 2; r++)
	  {

		for (int c = 0; c < 3; c++)
		  {

			cout << matrix[c][r] << " ";

		  }

		cout << endl;

	  }

	cout << endl;

  }

  void subtractFromRow (index ind)
  {

	int subtract = matrix[0][ind];

	for (int i = 0; i < 3; i++)
	  {

		matrix[i][ind] -= subtract;

	  }

  }

  void simplifyRow (index ind)
  {

	int div = 1;

	if (matrix[0][ind] != 1)
	  {

		div = matrix[0][ind];

		for (int i = 0; i < 3; i++)
		  {

			matrix[i][ind] /= div;

		  }

	  }



  }

  void simplifyRow (index ind, index column)
  {

	int div = 1;

	if (matrix[column][ind] != 1)
	  {

		div = matrix[column][ind];

		for (int i = column; i < 3; i++)
		  {

			matrix[i][ind] /= div;

		  }

	  }



  }

  var matrix[3][2];

};





int
main ()
{

  TwoElementSquarReinforcedeMatrix < float >m (2.f, 4.f, 3.f, 5.f, 6.f, 8.f);

  m.gaussianMethodOfElimination ();

}
