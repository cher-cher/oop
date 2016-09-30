#include "stdafx.h"
#include "Operation.h"

using namespace std;

int main()
{
	vector<shared_ptr<IShape>> shapes;
	cout << "Input shapes name and properties. In the end, enter \"end\"!" << endl;

	COperations handle(cin, cout, shapes);
	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!handle.HandleCommand())
		{
			cout << "Unknown shape!" << endl;
		}
	}
	return 0;
}

