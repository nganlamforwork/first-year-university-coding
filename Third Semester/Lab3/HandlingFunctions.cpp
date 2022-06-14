#include "HandlingFunctions.h"
#include "DataGenerator.h"

int findAlgorithm(char* argv)
{
	if (string(argv) == "selection-sort") return 1;
	if (string(argv) == "insertion-sort") return 2;
	if (string(argv) == "bubble-sort")    return 3;
	if (string(argv) == "shaker-sort")    return 4;
	if (string(argv) == "shell-sort")     return 5;
	if (string(argv) == "heap-sort")      return 6;
	if (string(argv) == "merge-sort")     return 7;
	if (string(argv) == "quick-sort")     return 8;
	if (string(argv) == "counting-sort")  return 9;
	if (string(argv) == "radix-sort")     return 10;
	if (string(argv) == "flash-sort")     return 11;
	return 0;
}

int findOutputParam(char* argv)
{
	if (string(argv) == "-time") return 1;
	if (string(argv) == "-comp") return 2;
	if (string(argv) == "-both") return 3;
	return 0;
}

int findInputOrder(string argv)
{
	if (string(argv) == "-rand") return 1;
	if (string(argv) == "-sorted") return 2;
	if (string(argv) == "-rev") return 3;
	if (string(argv) == "-nsorted") return 4;
	return 0;
}

double runningTime(int a[], int n, string algorithm)
{
	double answer;
	if (algorithm == "selection-sort") {
		auto start = high_resolution_clock::now();
		selectionSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "insertion-sort")  {
		auto start = high_resolution_clock::now();
		insertionSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "bubble-sort") {
		auto start = high_resolution_clock::now();
		bubbleSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "shaker-sort") {
		auto start = high_resolution_clock::now();
		shakerSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "shell-sort") {
		auto start = high_resolution_clock::now();
		shellSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "heap-sort") {
		auto start = high_resolution_clock::now();
		heapSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "merge-sort") {
		auto start = high_resolution_clock::now();
		mergeSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "quick-sort") {
		auto start = high_resolution_clock::now();
		quickSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "counting-sort") {
		auto start = high_resolution_clock::now();
		countingSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "radix-sort") {
		auto start = high_resolution_clock::now();
		radixSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}
	if (algorithm == "flash-sort") {
		auto start = high_resolution_clock::now();
		flashSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		answer = duration.count() / 1e3;
	}

	return answer;
}

int comparisions(int a[], int n, string algorithm)
{
	int answer = 0;
		if (algorithm == "insertion-sort")answer = insertionSortWithComparision(a, n);
	else
		if (algorithm == "bubble-sort")   answer = bubbleSortWithComparision(a, n);
	else
		if (algorithm == "shaker-sort")   answer = shakerSortWithComparision(a, n);
	else
		if (algorithm == "shell-sort")    answer = shellSortWithComparision(a, n);
	else
		if (algorithm == "heap-sort")     answer = heapSortWithComparision(a, n);
	else
		if (algorithm == "merge-sort")    answer = mergeSortWithComparision(a, n);
	else
		if (algorithm == "quick-sort")    answer = quickSortWithComparision(a, n);
	else
		if (algorithm == "counting-sort") answer = countingSortWithComparision(a, n);
	else
		if (algorithm == "radix-sort")    answer = radixSortWithComparision(a, n);
	else
		if (algorithm == "flash-sort")    answer = flashSortWithComparision(a, n);

	return answer;
}

void readFile(string inputFile, int a[], int &n)
{
	ifstream in(inputFile);
	in >> n;
	for (int i = 0; i<n; i++)
		in >> a[i];
	in.close();
}

void writeFile(string outputFile, int a[], int n)
{
	ofstream out(outputFile);
	out << n << '\n';
	for (int i = 0; i<n; i++)
		out << a[i] << ' ';
	out.close();
}

void executeAlgorithm(int a[], int n, string algorithm, int outputParam)
{
	cout << "Running time (if required): ";
	if (outputParam == 1 || outputParam == 3)
		cout << runningTime(a, n, algorithm);
	cout << '\n';

	cout << "Comparisions (if required): ";
	if (outputParam == 2 || outputParam == 3)
		cout << comparisions(a, n, algorithm);
	cout << '\n';
}

void executeCompare(int a[], int n, string algorithm1, string algorithm2)
{
	cout << "Running time: ";
	cout << runningTime(a, n, algorithm1);
	cout << " | ";
	cout << runningTime(a, n, algorithm2);
	cout << '\n';

	cout << "Comparisions: ";
	cout << comparisions(a, n, algorithm1);
	cout << " | ";
	cout << comparisions(a, n, algorithm2);
	cout << '\n';
}

void algorithmMode(int argc, char *argv[])
{
	int n, a[MAXN];

	if (argc != 5 && argc != 6) return;

	string algorithm = argv[2];
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: ";
	cout << algorithm << '\n';

	if (argc == 5){
		string givenInput = argv[3];
		int outputParam = findOutputParam(argv[4]);

		//--------------COMMAND 3--------------
		if (givenInput[0] >= '0' && givenInput[0] <= '9'){
			int inputSize = atoi(argv[3]);
			cout << "Input size: " << inputSize << '\n';

			n = inputSize;
			string inputOrder[] = { "-rand", "-nsorted", "-sorted", "-rev" };
			string outputFile[] = { "input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt" };
			for (int i = 0; i<4; i++){
				GenerateData(a, n, findInputOrder(inputOrder[i]) - 1);
				writeFile(outputFile[i], a, n);

				cout << "\nInput order: " << inputOrder[i] << '\n';
				cout << "-----------------------\n";
				executeAlgorithm(a, n, algorithm, outputParam);
			}
		}
		//--------------END COMMAND 3--------------

		cout << "Input file: " << givenInput << '\n';
		readFile(givenInput, a, n);
		cout << "Input size: \n";
		cout << "-----------------------\n";

		executeAlgorithm(a, n, algorithm, outputParam);

		writeFile("output.txt", a, n);
	}

	//--------------COMMAND 2--------------
	if (argc == 6){
		int inputSize = atoi(argv[3]);
		string inputOrder = argv[4];
		int outputParam = findOutputParam(argv[5]);

		cout << "Input size: " << inputSize << '\n';
		cout << "Input order: " << inputOrder << '\n';
		cout << "-----------------------\n";

		n = inputSize;
		GenerateData(a, n, findInputOrder(inputOrder) - 1);
		writeFile("input.txt", a, n);

		executeAlgorithm(a, n, algorithm, outputParam);

		writeFile("output.txt", a, n);
	}
	//--------------END COMMAND 2--------------

}

void comparisionMode(int argc, char *argv[])
{
	int n, a[MAXN];

	if (argc != 5 && argc != 6) return;

	string algorithm1 = argv[2];
	string algorithm2 = argv[3];
	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << '\n';

	if (argc == 5){
		string givenInput = argv[4];

		cout << "Input file: " << givenInput << '\n';
		readFile(givenInput, a, n);
		cout << "Input size: " << n << '\n';
		cout << "-----------------------\n";

		executeCompare(a, n, algorithm1, algorithm2);
	}

	int inputSize = atoi(argv[4]);
	string inputOrder = argv[5];

	cout << "Input size: " << inputSize << '\n';
	cout << "Input order: " << inputOrder << '\n';
	cout << "-----------------------\n";

	n = inputSize;
	GenerateData(a, n, findInputOrder(inputOrder) - 1);
	writeFile("input.txt", a, n);

	executeCompare(a, n, algorithm1, algorithm2);
}

bool handleCmdArguments(int argc, char *argv[])
{
	if (argc > 1){
		if (string(argv[1]) == "-a")
			algorithmMode(argc, argv);
		else if (string(argv[1]) == "-c")
			comparisionMode(argc, argv);
		else return 0;
	}
	return 0;
}
