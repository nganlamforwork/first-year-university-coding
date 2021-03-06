#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>

#include "SortingAlgorithms.h"
#include "SortingAlgorithmsCmp.h"

using namespace std;
using namespace std::chrono;

void printArray(int a[], int n);

string outputAlgorithm(string argv);
string outputInputOrder(string argv);
int findOutputParam(char* argv);
int findInputOrder(char* argv);

void readFile(string inputFile, int*& a, int &n);
void writeFile(string outputFile, int a[], int n);

double runningTime(int a[], int n, string algorithm);
long long comparisions(int a[], int n, string algorithm);

bool algorithmMode(int argc, char *argv[]);
bool comparisionMode(int argc, char *argv[]);

bool handleCmdArguments(int argc, char *argv[]);
