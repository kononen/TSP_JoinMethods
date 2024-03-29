#include <iostream>
#include <fstream>

#include "App.h"
#include "Matrix.h"
#include "Globals.h"
#include "BnB.h"
#include "Tabu_search.h"

bool Globals::runInnitialized = false;

int main()
{
	std::setlocale(LC_ALL, "Rus");
	bool next=true;
	while(next)
	{
		//App mainCycle = App();

		//+ 91
		/*Matrix firstMatrix(0, 50, 4);
		firstMatrix.matrix[0][0] = -1; firstMatrix.matrix[0][1] = 20; firstMatrix.matrix[0][2] = 16; firstMatrix.matrix[0][3] = 39;
		firstMatrix.matrix[1][0] = 48; firstMatrix.matrix[1][1] = -1; firstMatrix.matrix[1][2] = 24; firstMatrix.matrix[1][3] = 48;
		firstMatrix.matrix[2][0] = 36; firstMatrix.matrix[2][1] = 41; firstMatrix.matrix[2][2] = -1; firstMatrix.matrix[2][3] = 24;
		firstMatrix.matrix[3][0] = 34; firstMatrix.matrix[3][1] = 3;  firstMatrix.matrix[3][2] = 32; firstMatrix.matrix[3][3] = -1;
		*/

		//---������� 6�6 �������������! F=38 ������ F=34()

		/*Matrix firstMatrix(0, 50, 6);
		firstMatrix.matrix[0][0] = -1;	 firstMatrix.matrix[0][1] = 6;		firstMatrix.matrix[0][2] = 11;	firstMatrix.matrix[0][3] = 16;	 firstMatrix.matrix[0][4] = 3;		 firstMatrix.matrix[0][5] = 8;
		firstMatrix.matrix[1][0] = 1;	 firstMatrix.matrix[1][1] = -1;		firstMatrix.matrix[1][2] = 12;	firstMatrix.matrix[1][3] = 17;	 firstMatrix.matrix[1][4] = 4;		 firstMatrix.matrix[1][5] = 9;
		firstMatrix.matrix[2][0] = 2;	 firstMatrix.matrix[2][1] = 7;		firstMatrix.matrix[2][2] = -1;	firstMatrix.matrix[2][3] = 18;	 firstMatrix.matrix[2][4] = 5;		 firstMatrix.matrix[2][5] = 10;
		firstMatrix.matrix[3][0] = 3;	 firstMatrix.matrix[3][1] = 8;		firstMatrix.matrix[3][2] = 13;	firstMatrix.matrix[3][3] = -1;	 firstMatrix.matrix[3][4] = 6;		 firstMatrix.matrix[3][5] = 11;
		firstMatrix.matrix[4][0] = 4;	 firstMatrix.matrix[4][1] = 9;		firstMatrix.matrix[4][2] = 14;	firstMatrix.matrix[4][3] = 1;	 firstMatrix.matrix[4][4] = -1;		 firstMatrix.matrix[4][5] = 12;
		firstMatrix.matrix[5][0] = 5;	 firstMatrix.matrix[5][1] = 10;		firstMatrix.matrix[5][2] = 15;	firstMatrix.matrix[5][3] = 2;	 firstMatrix.matrix[5][4] = 7;		 firstMatrix.matrix[5][5] = -1;
		*/

		//+ F=133
		/*Matrix firstMatrix(0, 50, 6);
		firstMatrix.matrix[0][0] = -1;	 firstMatrix.matrix[0][1] = 49;		firstMatrix.matrix[0][2] = 45;	firstMatrix.matrix[0][3] = 42;	 firstMatrix.matrix[0][4] = 41;		 firstMatrix.matrix[0][5] = 43;
		firstMatrix.matrix[1][0] = 30;	 firstMatrix.matrix[1][1] = -1;		firstMatrix.matrix[1][2] = 20;	firstMatrix.matrix[1][3] = 33;	 firstMatrix.matrix[1][4] = 40;		 firstMatrix.matrix[1][5] = 35;
		firstMatrix.matrix[2][0] = 24;	 firstMatrix.matrix[2][1] = 26;		firstMatrix.matrix[2][2] = -1;	firstMatrix.matrix[2][3] = 25;	 firstMatrix.matrix[2][4] = 22;		 firstMatrix.matrix[2][5] = 26;
		firstMatrix.matrix[3][0] = 19;	 firstMatrix.matrix[3][1] = 36;		firstMatrix.matrix[3][2] = 25;	firstMatrix.matrix[3][3] = -1;	 firstMatrix.matrix[3][4] = 18;		 firstMatrix.matrix[3][5] = 43;
		firstMatrix.matrix[4][0] = 19;	 firstMatrix.matrix[4][1] = 18;		firstMatrix.matrix[4][2] = 18;	firstMatrix.matrix[4][3] = 12;	 firstMatrix.matrix[4][4] = -1;		 firstMatrix.matrix[4][5] = 25;
		firstMatrix.matrix[5][0] = 16;	 firstMatrix.matrix[5][1] = 47;		firstMatrix.matrix[5][2] = 31;	firstMatrix.matrix[5][3] = 14;	 firstMatrix.matrix[5][4] = 8;		 firstMatrix.matrix[5][5] = -1;
		*/

		// - ������� 6�6 F=13 ������ F=12
		/*Matrix firstMatrix(0, 50, 6);
		firstMatrix.matrix[0][0] = -1;	 firstMatrix.matrix[0][1] = 4;		firstMatrix.matrix[0][2] = 4;	firstMatrix.matrix[0][3] = 5;	 firstMatrix.matrix[0][4] = 4;		 firstMatrix.matrix[0][5] = 3;
		firstMatrix.matrix[1][0] = 2;	 firstMatrix.matrix[1][1] = -1;		firstMatrix.matrix[1][2] = 7;	firstMatrix.matrix[1][3] = 1;	 firstMatrix.matrix[1][4] = 1;		 firstMatrix.matrix[1][5] = 6;
		firstMatrix.matrix[2][0] = 2;	 firstMatrix.matrix[2][1] = 3;		firstMatrix.matrix[2][2] = -1;	firstMatrix.matrix[2][3] = 9;	 firstMatrix.matrix[2][4] = 4;		 firstMatrix.matrix[2][5] = 5;
		firstMatrix.matrix[3][0] = 1;	 firstMatrix.matrix[3][1] = 3;		firstMatrix.matrix[3][2] = 2;	firstMatrix.matrix[3][3] = -1;	 firstMatrix.matrix[3][4] = 3;		 firstMatrix.matrix[3][5] = 1;
		firstMatrix.matrix[4][0] = 7;	 firstMatrix.matrix[4][1] = 4;		firstMatrix.matrix[4][2] = 1;	firstMatrix.matrix[4][3] = 1;	 firstMatrix.matrix[4][4] = -1;		 firstMatrix.matrix[4][5] = 4;
		firstMatrix.matrix[5][0] = 2;	 firstMatrix.matrix[5][1] = 3;		firstMatrix.matrix[5][2] = 4;	firstMatrix.matrix[5][3] = 7;	 firstMatrix.matrix[5][4] = 9;		 firstMatrix.matrix[5][5] = -1;
		*/

		//+ ������� 5�5   F=180
		/*Matrix firstMatrix(0, 50, 5);
		firstMatrix.matrix[0][0] = -1; firstMatrix.matrix[0][1] = 90; firstMatrix.matrix[0][2] = 80; firstMatrix.matrix[0][3] = 40; firstMatrix.matrix[0][4] = 100;
		firstMatrix.matrix[1][0] = 60; firstMatrix.matrix[1][1] = -1; firstMatrix.matrix[1][2] = 40; firstMatrix.matrix[1][3] = 50; firstMatrix.matrix[1][4] = 70;
		firstMatrix.matrix[2][0] = 50; firstMatrix.matrix[2][1] = 30; firstMatrix.matrix[2][2] = -1; firstMatrix.matrix[2][3] = 60; firstMatrix.matrix[2][4] = 20;
		firstMatrix.matrix[3][0] = 10; firstMatrix.matrix[3][1] = 70; firstMatrix.matrix[3][2] = 20; firstMatrix.matrix[3][3] = -1; firstMatrix.matrix[3][4] = 50;
		firstMatrix.matrix[4][0] = 20; firstMatrix.matrix[4][1] = 40; firstMatrix.matrix[4][2] = 50; firstMatrix.matrix[4][3] = 20; firstMatrix.matrix[4][4] = -1;
		*/
		//Matrix firstMatrix(0, 100, 40);



		///*for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		f >> firstMatrix.matrix[i][j];
		//	}
		//}*/

		std::ifstream f;

		std::string filename = "";
		std::cout << " ������� �������� �����\n";
		std::cin >> filename;
		filename +=".txt";
		f.open(filename);

		/*std::string filename = "m6";
		f.open(filename + ".txt");*/

		//+
		//f.open("m6.txt"); 
		//f.open("coord.txt");
		//f.open("coordfirst.txt");
		//f.open("m5_trouble.txt");
		//f.open("m5.txt");
		//f.open("m5_symmetry.txt");

		int n;// = 5;
		f >> n;

		Matrix firstMatrix(0, 50, n);

		//for (int i = 0; i < n; i++) // ��� ������� ��� ������� ��������� (� -1)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		if (i != j)
		//		{
		//			f >> firstMatrix.matrix[i][j];
		//		}//������ �� �����
		//		else
		//		{
		//			//f >> firstMatrix.matrix[i][j];
		//			firstMatrix.matrix[i][j] = -1; 
		//		}
		//	}
		//}

		for (int i = 0; i < n; i++) // ��� ������� � ������� �� ������� ��������� (� �� -1, �� ���-��)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					f >> firstMatrix.matrix[i][j];
				}//������ �� �����
				else
				{
					f >> firstMatrix.matrix[i][j];
					firstMatrix.matrix[i][j] = -1;
				}
			}
		}

		f.close();

		//Matrix firstMatrix(0, 100, 50);
		firstMatrix.printM();

		auto clockS = clock();
		BnB::step1(firstMatrix); // ����� ������ � ������
		std::cout << "time: " << (float)(clock() - clockS) / CLOCKS_PER_SEC << std::endl;


		cout << "---------------------------------- \n";
		cout << "TabuSearch method \n";
		cout << "---------------------------------- \n";
		vector<double> Pmatr;
		int n2 = 0;
		InputList(Pmatr, n2, filename);
		auto clockS2 = clock();
		vector<int> sol2 = TabuSearch(Pmatr, n2);
		cout << "time: " << (float)(clock() - clockS2) / CLOCKS_PER_SEC << endl;
		for (auto val : sol2) { cout << val << "->"; };
		cout << sol2[0] << endl << "Price: " << Price(sol2, Pmatr) << std::endl;

		std::cout << "�������, ���� �Ѩ �� ����������!!!!!\n";

		char YorN = 'f';
		while (YorN!='n' && YorN != 'y')
		{
			std::cout << "������ ����������? y/n\n";
			std::cin >> YorN;
			if (YorN == 'n')
			{
				next = false;
			}
			else if (YorN == 'y')
			{
				next = true;
			}
			else
			{
				std::cout << " �� ����������� ����� �����, ������� ��� ��� \n"; 
			}
		}
	}
}