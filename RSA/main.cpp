#include <iostream>

using namespace std;

vector <int> primary_numbers;
map <int, bool> used;

pair <int, int> public_key;
pair <int, int> private_key;


void PrimeFiller() {
    bool primes[10000];

    for(int i = 2; i < 10000; i++){
        for(int j = i*2; j < 10000; j += i){
            primes[j] = true;
        }
    }

    for(int i = 1; i < 10000; i++){
        if(!primes[i]){
            primary_numbers.push_back(i);
            used[i] = false;
        }
    }
}


pair <int, int> PickPrimeNumbers() {
    int range;
    cout << "Choose the range to choose the numbers on:" << endl;
    cin >> range;

    for(auto& prime : primary_numbers){
        if(prime > range) break;
        cout << prime << " ";
    }
    cout << endl;

    cout << "Choose two different numbers from the set:" << endl;
    int first_number, second_number;

    while(true){
        cin >> first_number >> second_number;

        if(first_number == second_number){
            cout << "Choose different numbers!!" << endl;
            continue;
        }

        if(find(primary_numbers.begin(), primary_numbers.end(), first_number) == primary_numbers.end()
        || find(primary_numbers.begin(), primary_numbers.end(), second_number) == primary_numbers.end()){
            cout << "Choose the numbers from the set!!" << endl;
            continue;
        }
        break;
    }

    used[first_number] = true;
    used[second_number] = true;
    return {first_number, second_number};
}


void PublicKeyGenerator(pair <int, int>& numbers) {
    int& p = numbers.first;
    int& q = numbers.second;
    int n = p * q;
    int phi = (p-1) * (q-1);

    int e;
    cout << "Choose the integer from the set:" << endl;
    for(auto& prime : primary_numbers){
        if(prime == 1) continue;
        if(prime > phi) break;
        if(!used[prime]) cout << prime << " ";
    }
    cout << endl;

    while(true){
        cin >> e;
        if(find(primary_numbers.begin(), primary_numbers.end(), e) == primary_numbers.end()
        || used[e] == true){
            cout << "Choose the number from the set!!";
            continue;
        }
        break;
    }

    public_key.first = n;
    public_key.second = e;
}

void PrivateKeyGenerator(pair <int, int>& numbers) {
    int& p = numbers.first;
    int& q = numbers.second;
    int n = p * q;
    int phi = (p-1) * (q-1);


}

void Encrypt() {
    PrimeFiller();
    pair <int, int> choice = PickPrimeNumbers(range);
    PublicKeyGenerator(choice);
}

int main()
{
    int option;
    cout << "Choose the option:\n"
            "(1) Encrypt message\n"
            "(2) Decrypt message\n";
    cin >> option;
    switch(option){
        case 1:{
            Encrypt();
        }
        case 2:{
            ;
        }
    };
    return 0;
}
