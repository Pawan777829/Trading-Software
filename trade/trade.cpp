#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TradingApp {
private:
    double balance;
    double profitLoss;
    double bitcoins;
    double dogecoins; 
    double totalBitcoinsPurchased;
    double totalDogecoinsPurchased;
    double totalBitcoinsSold;
    double totalDogecoinsSold;
    double bitcoinRate; 
    double dogecoinRate;

    vector<string> transactions;

public:
    TradingApp() : balance(0), profitLoss(0), bitcoins(0), dogecoins(0),totalBitcoinsPurchased(0), totalDogecoinsPurchased(0), totalBitcoinsSold(0), totalDogecoinsSold(0),bitcoinRate(100), dogecoinRate(0.2)  {}

    void getAccountInfo() {
        cout << "Balance: " << balance << endl;
        cout << "Profit/Loss: " << profitLoss << endl;
        cout << "Bitcoins: " << bitcoins << endl;
        cout << "Dogecoins: " << dogecoins << endl;
    }

    void depositMoney(double amount) {
        balance += amount;
        transactions.push_back("Deposit: $" + to_string(amount));
        cout << "....Money deposited successfully. Balance updated....\n";

    }

    bool withdrawMoney(double amount) {
        if (amount > balance) {
            cout << ".....Insufficient balance in your account....." << endl;
            return false;
        }
        balance -= amount;
        transactions.push_back("Withdraw: $" + to_string(amount));
        return true;
    }

    void buyShares(string type, double amount) {
        if (type == "Bitcoin") {
    double bitcoinPrice = 100; // Assuming 1 Bitcoin = $10
    double totalPrice = amount * bitcoinPrice;
    if (totalPrice >= balance) {
        cout << "....Insufficient balance to buy.. " << amount << " Bitcoins." << endl;
        return;
    }
    bitcoins += amount;
    balance -= totalPrice;
    totalBitcoinsPurchased += amount;
    transactions.push_back("Bought " + to_string(amount) + " Bitcoins");
    cout << ".....Bitcoin bought successfully....." << endl;
}
        else if (type == "Dogecoin") {
            double totalPrice = amount * 0.2;
            if (totalPrice >= balance) {
                cout << "Insufficient balance to buy " << amount << " Dogecoins." << endl;
                return;
            }
            dogecoins += amount;
            balance -= totalPrice;
            totalDogecoinsPurchased += amount;
            transactions.push_back("Bought " + to_string(amount) + " Dogecoins");
            cout << ".....Dogecoin bought successfully....." << endl;
        } else {
            cout << "Invalid cryptocurrency type." << std::endl;
        }
    }

    void sellShares(string type, double amount) {
        // Implementation for selling cryptocurrency
        if (type == "Bitcoin") {
            if (bitcoins >= amount) {
                bitcoins -= amount;
                balance += amount * 5000; // Assuming 1 Bitcoin = 5000
                transactions.push_back("Sold " + to_string(amount) + " Bitcoins");
                cout << ".....bitcoin sold successfully....." << endl;
            } else {
                cout << "Insufficient Bitcoins." << endl;
            }
        } else if (type == "Dogecoin") {
            if (dogecoins >= amount) {
                dogecoins -= amount;
                balance += amount * 0.2; // Assuming 1 Dogecoin = 0.2
                transactions.push_back("Sold " + to_string(amount) + " Dogecoins");
                cout << ".....Dogecoin sold successfully......" << endl;
            } else {
                cout << "Insufficient Dogecoins." << endl;
            }
        }
    }

    void checkTransactions() {
        // Implementation for checking transactions
         for (const auto& transaction : transactions) {
            cout << transaction << endl;
        }
    }

    void checkSharePrices() {
        // Implementation for checking share prices
        cout << "Share price for Company X: $100\n";
        cout << "Share price for Company Y: $200\n";
    }

    void checkAccountBalance() {
        // Implementation for checking account balance
        cout << "Account balance: $" << balance << endl;
    }

    void getPurchaseSummary() {
        cout << "Total Bitcoins Purchased: $" << totalBitcoinsPurchased << endl;
        cout << "Total Dogecoins Purchased: $" << totalDogecoinsPurchased << endl;
    }

    void getSaleSummary() {
        cout << "Total Bitcoins Sold: $" << totalBitcoinsSold << endl;
        cout << "Total Dogecoins Sold: $" << totalDogecoinsSold << endl;
    }
};

int main() {
    // Implementation for main function
     string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Simulate login check
    if (username == "user" && password == "pass") {
        cout << "\n-------Login successful.--------\n";
        TradingApp app;
        int choice;
        double amount;
        string cryptoType;

        while (true) {
            cout << "\n --------TRADING SOFTWARE---------\n";
            cout << "\nTrading Application Menu:\n";
            cout << "1. Get Account Info\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "5. Sell Shares\n";
            cout << "6. Check Transactions\n";
            cout << "7. Check Share Prices\n";
            cout << "8. Check Account Balance\n";
            cout << "8. total purchased\n";
            cout << "8. total sold\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    app.getAccountInfo();
                    break;
                case 2:
                    cout << "Enter amount to deposit: $";
                    cin >> amount;
                    app.depositMoney(amount);
                    
                    break;
                case 3:
                    cout << "Enter amount to withdraw: $ ";
                    cin >> amount;
                    app.withdrawMoney(amount);
                    break;
                case 4:
                    cout << "Enter type of cryptocurrency (Bitcoin/Dogecoin): ";
                    cin >> cryptoType;
                    cout << "Enter amount to buy: $ ";
                    cin >> amount;
                    app.buyShares(cryptoType,amount);
                    break;
                case 5:
                    cout << "Enter type of cryptocurrency (Bitcoin/Dogecoin): ";
                    cin >> cryptoType;
                    cout << "Enter amount to sell: $ ";
                    cin >> amount;
                    app.sellShares(cryptoType, amount);
                    break;
                case 6:
                    app.checkTransactions();
                    break;
                case 7:
                    app.checkSharePrices();
                    break;
                case 8:
                    app.checkAccountBalance();
                    break;
                case 9:
                    app.getPurchaseSummary();
                    break;
                case 10:
                    app.getSaleSummary();
                    break;
                case 11:
                    cout << "Exiting the application.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    } else {
        cout << "Login failed.\n";
    }

    return 0;
}
