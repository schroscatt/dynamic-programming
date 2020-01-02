#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <set>
#include <vector>


using namespace std;
void parseInput(ifstream& inFile,long long int &  N,long long int &  M, vector <long long int> &prices);
int main(int argc, char* argv[]) {


    long long int N,M;
    vector<long long int> prices;

    if (argc != 3) {
        // cerr should be used for errors
        cerr << "Run the code with the following command: ./cmpe250-assignment5[input_file] [output_file]" << endl;
        return 1;
    }


    ifstream inFile(argv[1]);
    if (!inFile) { // checking if there was a failure
        cerr << "There was a problem opening \"" << argv[1] << "\" as input file" << endl;
        return 1;
    }
    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "There was a problem opening \"" << argv[2] << "\" as output file" << endl;
        return 1;
    }

    vector<long long int> total; //keeps the total prices
    total.push_back(0);
    parseInput(inFile,N,M,prices);
    sort(prices.begin(),prices.end(), less<long long int>());

    for(long long int k=1; k<=N;k++) {
        long long int element = prices[k-1]; //takes the smallest element

        if(k-1>=M) {
            {
                long long int value = total[k - M] - total[k - M - 1]+ total[k - 1] + element;;
                total.push_back(value);
                outFile << value << " ";
            }
        }
        else {
            long long int value = total[k-1]+element;
            total.push_back(value);
            outFile<<value<< " ";
        }
    }


    outFile.close();

    return 0;
}
void parseInput(ifstream& inFile,long long int &  N,long long int &  M,vector <long long int>&prices) //reads input
{
    string line, tmp;
    getline(inFile, line);
    istringstream linestream(line);

    getline(linestream, tmp, ' ');
    N = stoi(tmp);
    getline(linestream, tmp, ' ');
    M = stoi(tmp);

    getline(inFile, line);
    istringstream linestream2(line);

    for(long long int i=0;i<N;i++) {
        string price;
        getline(linestream2,price,' ');
        long long int K = stoi(price);
        prices.push_back(K);
    }
    inFile.close();

}
