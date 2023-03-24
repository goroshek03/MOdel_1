#include <iostream>
using namespace std;




using namespace std;
float determinant(float matrix[100][100], int n) {
	float det = 0; // свой дет передать
	float submatrix[100][100];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}

int main()
{

	int stolb;
	int stroka;


	setlocale(LC_ALL, "Russian");
	cout << "Вариант задание 1 \n";
	cout << endl;
	cout << "Условие: y = a0 + a1/x1 + a2/x2 + ... + am/xn;  \n";
	cout << endl;
	cout << "Введите число эксперементов  (столбцов): "; cin >> stolb;
	cout << "\n";
	cout << "Введите число входных воздейтсвий  (строк): "; cin >> stroka;
	cout << "\n";
	cout << "Заполните таблицу входными данными\n";
	cout << endl;
	float arr_1[100][100] = { 0 }; //массив входных данных

	// Ввод значений уравнений 
	for (int i = 0; i < stolb; i++) {

		int b = i + 1;
		cout << "Введите данные " << b << " эксперемента\n";
		for (int j = 0; j < stroka; j++) {

			int a = j + 1;
			if (j == (stroka - 1)) {

				cout << "y:"; cin >> arr_1[j][i];
				 //запись y элемента
				
				 //* (-1)); // запись y элемента с отрицательным знаком 
			}
			else
			{

				cout << "x" << a << ":"; cin >> arr_1[j][i];

				arr_1[j][i] = (1 / arr_1[j][i]); // линеризация 

			}
		}
	}

	// умножить y на -1

	for (int i = 0; i < stolb; i++) {

		for(int j = 0; j < stroka; j++){

			if(j == (stolb - 1)) arr_1[j][i] = ((-1) * arr_1[j][i]);

		}
	}








	for (int i = 0; i < 10; i++) {

		cout << "----";
	}
	cout << "\n";


	// вывод результата ввиде таблицы 
	int a = 1;
	for (int i = 0; i < stroka; i++) {

		bool flag = true;
		if (i == (stroka - 1)) flag = false;
		if (i == (stroka - 1)) {

			cout << "|y ";
		}
		else cout << "|x" << a;
		for (int j = 0; j < stolb; j++) {

			if (flag) {

				cout << " | " << arr_1[i][j] << "   |";

			}
			else {

				cout << " | " << arr_1[i][j] << "  |";
				
			}
		}
		cout << endl;
		a = a + 1;
	}

	for (int i = 0; i < 10; i++) { // раздел частей 

		cout << "----";
	}



	//вычисление производных
	float arr_2[100][100] = { 0 }; 

	


	//столбец = уравненю
   //число уравнений число столбцов

	cout << endl;
	// алгоритм вычисления производных 
	
	
	
	
	
	float arr_3[100][100] = { 0 };
	int h = 0; // смещение индекса
	
	float arr_4[100][100] = { 0 };
	cout << endl;
	int skobka = 0; // переменная для проверки введен ли 0

	float vector_stolb[100][100] = { 0 };

	float arr_5[100][100] = { 0 };
	float matrix[100][100] = { 1 };



	cout << "Функция ошибок равна: " << endl;

	for (int i = 0; i < stolb; i++) {
		cout << "[a0 + ";
		int o = 1;
		for (int j = 0; j < stroka; j++) {
			
			
			if (j < (stroka - 1)) {

				cout << "(" << arr_1[j][i] << ")a" << o ;
			}
			else {

				cout << "(" << arr_1[j][i] << ")"; // 
			}
			if (j < (stroka - 1)  ){

				cout << " + ";// знак

			}
			o = o + 1;
			
		}
		o = 0;
		
		cout << "]^2 ";

		if (i < (stolb - 1)) cout << "+ ";
	}
	
	cout << endl<< endl;

	cout << "Найдем частные произвоные по каждому элементу: " << endl;


	for (int g = 0; g < stroka; g++) { // сколько раз вызвать функцию 


		if (g > 1) {

			h = h + 1;
		}
		for (int i = 0; i < stolb; i++) {
			int cot = 1;

			for (int j = 0; j < stroka; j++) {

				if (g == 0 && j == 0) { //берем частную производную по а0
					cout << "2*[(a0";
					arr_4[j][i] = 2; 
					skobka = skobka + 1;


				}
				else {

					if (arr_1[j + h][i] != 0 && j == 0) {

						if (arr_1[j + h][i] != 0) {

							cout << 2 * arr_1[j + h][i] << "*" << "[(a0";
							skobka = skobka + 1;
						}
						//

						arr_4[j][i] = 2 * arr_1[j + h][i]; // запоминаем на что умножим скобку было -[j +g]
					}

					

				}




				if (j == (stroka - 1) && j != 0) {

					if (skobka && arr_1[j][i] != 0) {
						// изменяд -1 тут 
						
						cout << " + (" << arr_1[j][i] << ")";
					}
				}
				else  if (skobka && arr_1[j][i] != 0) cout << " + (" << arr_1[j][i] << ")a" << cot << "";


				cot++;

				if (j == (stroka - 1) && j != 0 && skobka) cout << "]";
			}

			if (i != (stolb - 1) && skobka) cout << " + ";

			skobka = 0;
		}
		




		cout << " = [";

		for (int i = 0; i < stolb; i++) { // занести значение а0

			int a = 0;

			if (i == 1) a = a + 1;
			arr_2[0][i] = arr_4[0][i]; // былло = {1} i-a поменял на 0
			
		}

	

		// вторая часть уравнения умножение одой строчки и занесение ее в массив 
	
		



		for (int i = 0; i < stolb; i++) {

			int a = 0;
			for (int j = 0; j < stroka; j++) {
				int a = 0;
				if (i == 1) a = a + 1;

				arr_2[j + 1][i] = arr_4[0][i] * arr_1[j][i]; //arr_2 [j+1][i]
				a = 0;




			}
		}


		for (int i = 0; i < stolb; i++) { // сброс значений массива по итогу массива 4 должен быть весь в нулях

			for (int j = 0; j < stroka; j++) {

				arr_4[j][i] = 0;
			}
		}





		int b = 1; // нужно сдвивагать столб с ростом уравнений 
		// сложение строки после умножения


		for (int i = 0; i < stolb ; i++) { // был stolb -1 

			int a = 0;
			for (int j = 0; j < (stroka + 1); j++) {
				if (i == 0) {

					arr_3[j][0]  = arr_2[j][0];

				} else arr_3[j][0] += arr_2[j][i];

				//arr_3[j][i + g] = arr_2[j][i] + arr_2[j][i + 1]; 



			}
		}


		for (int i = 0; i < stolb; i++) {

			for (int j = 0; j < (stroka + 1); j++) {

				arr_5[j][g] = arr_3[j][0];
			}
		}



		// придумать условие сдвига столбца массива arr_3


		for (int i = 0; i < stolb; i++) { // сброс значений массива по итогу массива 2 должен быть весь в нулях

			for (int j = 0; j < (stroka + 1); j++) {

				arr_2[j][i] = 0;
			}
		}


		// печать



		int s = 1;
		int cot = 0;
		for (int j = 0; j < (stroka + 1); j++) {




			// вывод y элемента
			if (j == stroka) { cout << "(" << arr_5[j][g] << ")"; }
			else {

				cout << "(" << arr_5[j][g] << ")" << "a" << cot;
				cot = cot + 1;
			}



			if (j == stroka) {

				cout << " ] ";
			}
			else
			{
				cout << " + ";
			}

		}

		if (g > 0) s = s + 1;







		cout << endl;


	}



	// перезаписать массив для удобства вычисления крамером


	for (int i = 0; i < (stroka); i++) {

		for (int j = 0; j < (stolb + 1); j++) {

			matrix[j][i] = arr_5[i][j]; // перепишем в привычную линейную матрицу 
			
		}
	}



	// записать отдельно ввиде вектор-столбец значения y


	for (int i = 0; i < (stolb + 1); i++) {

		for (int j = 0; j < stroka; j++) {

			if (j == (stroka - 1)) vector_stolb[(j - j) + i][0] = ((-1) * arr_5[j + 1][i]); // сделаем вектор-столбец 

		}
	}


	float matrix_2[100][100] = { 0 };
	//дубляж матрицы
	for (int i = 0; i < stroka; i++) {

		for (int j = 0; j < stroka; j++) {

			matrix_2[i][j] = matrix[i][j];
		}
	}

	// определитель 
	float det;
	float detN;

	float znachenie[100] = { 0 };
	det = determinant(matrix, stroka); // определитель в знаменателе

	for (int i = 0; i < stroka; i++ ) { 
		// количество раз вызова функции determinant
		// внутриу цикла будет заменятся столбец 

		for (int j = 0; j < stroka; j++) {

			

			matrix[j][i] = vector_stolb[j][0];//замена столбца для счета следующего опеределителя

			
		}

		detN = determinant(matrix, stroka);
		znachenie[i] =  detN / det; // запись полученных значений ( an )


		// вернуть матрицу в исходное состояние 
		for (int i = 0; i < stroka; i++) {

			for (int j = 0; j < stroka; j++) {

				matrix[i][j] = matrix_2[i][j];
			}
		}


		

	}
	cout << endl;
	cout << "Полученные коэффициенты: " <<endl;
	for (int i = 0; i < stroka; i++) {

		cout<< "a" << i << " = " << znachenie[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < stroka; i++) {

		if (i == 0) {

			cout << "y = " << znachenie[0];
		}
		else cout <<"(" << znachenie[i] << ") / x" << i;
		if (i < (stroka - 1)) cout << " + ";

		

	}

	cout << endl;


}


