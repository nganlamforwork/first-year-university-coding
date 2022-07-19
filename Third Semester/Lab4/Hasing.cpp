#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(string file_name)
{
    ifstream in(file_name);
    string company, name, profit_tax, address;
    getline(in, company, '\n');

    vector<Company> data;
    data.clear();

    while (!in.eof()) {
        getline(in, name, '|');
        getline(in, profit_tax, '|');
        getline(in, address, '\n');

        data.push_back({ name, profit_tax, address });
    }

    in.close();

    return data;
}
long long Pow(int a, int b)
{
    if (b == 0) return 0;
    if (b == 1) return 1;
    long long ans = 1;
    long long m = 1e9 + 9;
    if (b % 2 == 1)
        return (((Pow(a, b / 2) * Pow(a, b / 2)) % m) * a) % m;
    return (Pow(a, b / 2) * Pow(a, b / 2)) % m;
}
long long HashString(string company_name)
{
    long long ans = 0;
    long long m = (long long) 1e9 + 9;
    long long p = 31;
    string s;

    if (company_name.size() < 20) s = company_name;
    else s = company_name.substr(company_name.size() - 20, 20);

    for (int i = 0; i < (int)s.size(); i++)
        ans = (ans + (s[i] * Pow(p, i)) % m) % m;
    return ans;
}
Company* CreateHashTable(vector<Company> list_company)
{
    int capacity = 2000;
    Company* table = new Company[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = { "","","" };

    int size = 0;
    for (int i = 0; i < (int)list_company.size(); i++) {
        long long hashIndex = HashString(list_company[i].name) % capacity;

        while (table[hashIndex].name != "") {
            hashIndex++;
            hashIndex %= capacity;
        }
        table[hashIndex] = list_company[i];
    }
    return table;
}
void Insert(Company* hash_table, Company company)
{
    int capacity = 2000;
    long long hashIndex = HashString(company.name) % capacity;

    while (hash_table[hashIndex].name != "") {
        hashIndex++;
        hashIndex %= capacity;
    }

    hash_table[hashIndex] = company;
}
Company* Search(Company* hash_table, string company_name)
{
    int capacity = 2000;
    int hashIndex = HashString(company_name) % capacity;
    while (hash_table[hashIndex].name != company_name) {
        if (hash_table[hashIndex].name == "")
            return NULL;
        hashIndex = (hashIndex + 1) % capacity;
    }
    return &hash_table[hashIndex];
}
int main()
{
    vector<Company> ans = ReadCompanyList("MST.txt");
    CreateHashTable(ans);
	return 0;
}